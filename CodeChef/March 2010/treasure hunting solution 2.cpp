#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

int neigh[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char a[20][20];
int aa[20][2];
int d[10000][20];
int dd[20][20];
int dis[20][20];
int st[20];
int ed[20];
int zhan[1000][2];

int main()
{
    int i,j,k,l,t,top,bottom,n,m,best,b1,x,y;
    scanf("%d",&t);
    for (l=0;l<t;l++)
    {
        scanf("%d",&n);
        for (i=0;i<n;i++)
            scanf("%s",a[i]);
        m=0;
        for (i=0;i<n;i++)
            for (j=0;j<n;j++)
                if (a[i][j]=='*')
                {
                    aa[m][0]=i;
                    aa[m][1]=j;
                    m++;
                }
        if (m==0)
        {
            memset(dd,-1,sizeof(dd));
            dd[0][0]=0;
            zhan[0][0]=0;
            zhan[0][1]=0;
            top=0;bottom=1;
            while (top<bottom)
            {
                for (k=0;k<4;k++)
                {
                    x=zhan[top][0]+neigh[k][0];
                    y=zhan[top][1]+neigh[k][1];
                    if ((x>=0)&&(x<n)&&(y>=0)&&(y<n)&&(a[x][y]!='#')&&(dd[x][y]==-1))
                    {
                        dd[x][y]=dd[zhan[top][0]][zhan[top][1]]+1;
                        zhan[bottom][0]=x;
                        zhan[bottom][1]=y;
                        bottom++;
                    }
                }
                top++;
            }
            printf("%d\n",dd[n-1][n-1]);
            continue;
        }
        for (i=0;i<m;i++)
        {
            memset(dd,-1,sizeof(dd));
            dd[aa[i][0]][aa[i][1]]=0;
            zhan[0][0]=aa[i][0];
            zhan[0][1]=aa[i][1];
            top=0;bottom=1;
            while (top<bottom)
            {
                for (k=0;k<4;k++)
                {
                    x=zhan[top][0]+neigh[k][0];
                    y=zhan[top][1]+neigh[k][1];
                    if ((x>=0)&&(x<n)&&(y>=0)&&(y<n)&&(a[x][y]!='#')&&(dd[x][y]==-1))
                    {
                        dd[x][y]=dd[zhan[top][0]][zhan[top][1]]+1;
                        zhan[bottom][0]=x;
                        zhan[bottom][1]=y;
                        bottom++;
                    }
                }
                top++;
            }
            for (j=0;j<m;j++)
                dis[i][j]=dd[aa[j][0]][aa[j][1]];
            st[i]=dd[0][0];
            ed[i]=dd[n-1][n-1];
        }
        b1=1;
        for (i=0;i<m;i++)
            for (j=0;j<m;j++)
                if (dis[i][j]==-1) b1=0;
        for (i=0;i<m;i++)
        {
            if (st[i]==-1) b1=0;
            if (ed[i]==-1) b1=0;
        }
        if (b1==0)
        {
            printf("-1\n");
            continue;
        }
        memset(d,-1,sizeof(d));
        for (i=0;i<m;i++)
            if (st[i]!=-1)
                d[1<<i][i]=st[i];
        for (i=0;i<(1<<m);i++)
            for (j=0;j<m;j++)
                if (d[i][j]!=-1)
                {
                    for (k=0;k<m;k++)
                        if (((1<<k)&i)==0)
                            if ((d[i|(1<<k)][k]==-1)||(d[i|(1<<k)][k]>d[i][j]+dis[j][k]))
                                d[i|(1<<k)][k]=d[i][j]+dis[j][k];
                }
        best=2000000000;
        for (i=0;i<m;i++)
            if ((d[(1<<m)-1][i]!=-1)&&(d[(1<<m)-1][i]+ed[i]<best))
                best=d[(1<<m)-1][i]+ed[i];
        printf("%d\n",best);
    }
	return 0;
}
