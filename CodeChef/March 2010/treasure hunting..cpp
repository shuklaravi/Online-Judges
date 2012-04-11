#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#define MAX 13
using namespace std;
const int BIG=0x3f3f3f3f;
struct data{
	int x,y;
};
int mp[MAX+2][MAX+2],dis[MAX+2][MAX+2],X[MAX+2],Y[MAX+2],dp[1<<MAX][MAX];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1},n,e;
char c[15][15];
bool ok(int x,int y)
{
	return x>=0&&x<n&&y>=0&&y<n;
}
void bfs(int x,int y)
{
	int i;
	queue<data> q;
	data now,t;
	memset(mp,0x3f,sizeof(mp));
	mp[x][y]=0;
	now.x=x;now.y=y;
	q.push(now);
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			t.x=now.x+dx[i];
			t.y=now.y+dy[i];
			if(ok(t.x,t.y)&&mp[t.x][t.y]>mp[now.x][now.y]+1&&c[t.x][t.y]!='#')
			{
				mp[t.x][t.y]=mp[now.x][now.y]+1;
				q.push(t);
			}
		}
	}
}
int main()
{
	int i,j,k,ans,cs;
	scanf("%d",&cs);
	while(cs--)
	{
		scanf("%d",&n);
		for(e=i=0;i<n;i++)
		{
			scanf("%s",c[i]);
			for(j=0;j<n;j++)
				if(c[i][j]=='*')
				{
					X[e]=i;
					Y[e++]=j;
				}
		}
		X[e]=Y[e]=0;
		X[e+1]=Y[e+1]=n-1;
		for(i=0;i<e+2;i++)
		{
			bfs(X[i],Y[i]);
			for(j=0;j<e+2;j++)
				dis[i][j]=mp[X[j]][Y[j]];
		}
		for(i=0;i<e+2;i++)
			if(dis[0][i]==BIG)
				break;
		if(i!=e+2)
		{
			puts("-1");
			continue;
		}
		memset(dp,0x3f,sizeof(dp));
		for(i=0;i<e;i++)
			dp[1<<i][i]=dis[e][i];
		for(i=0;i<(1<<e);i++)
			for(j=0;j<e;j++)
				if((1<<j)&i)
					for(k=0;k<e;k++)
						if(((1<<k)&i)==0)
							dp[(1<<k)|i][k]=min(dp[(1<<k)|i][k],dp[i][j]+dis[j][k]);
		for(ans=BIG,i=0;i<e;i++)
			ans=min(ans,dp[(1<<e)-1][i]+dis[i][e+1]);
		printf("%d\n",ans);
	}
}
