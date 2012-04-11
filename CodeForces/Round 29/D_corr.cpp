#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
using namespace std;
#define inf 1000000000
#define MP make_pair
typedef pair<int, int>pii;
struct bb
{
    int a,adj,l;
}p[6010];
int list[610],idx;
void insert(int u,int v,int w)
{
    p[idx].a=v;
    p[idx].l=w;
    p[idx].adj=list[u];
    list[u]=idx++;
}
void dij(int n,int s,int *dis,int *r)
{
    int i,len,u,v;
    for (i=0;i<n;i++) dis[i]=inf;
    priority_queue<pii, vector<pii>,greater<pii> > que;
    while (!que.empty()) que.pop();
    que.push(MP(0,s));
    for (i=0;i<n;i++)
        r[i]=-1;
    dis[s]=0;
    while (!que.empty())
    {
        len=que.top().first;
        u=que.top().second;
        que.pop();
        if (len>dis[u]) continue;
        for (i=list[u];i!=-1;i=p[i].adj)
        {
            v=p[i].a;
            if (dis[v]>dis[u]+p[i].l)
            {
                dis[v]=dis[u]+p[i].l;
                if (r[u]==-1)
                    r[v]=v;
                else
                    r[v]=r[u];
                que.push(MP(dis[v],v));
            }
        }
    }
}
int out[610],dis[610],r[610],cnt,one,n,i,u,v,k,j,du[610],mp[610][610],route[610][610],st;

int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (i=0;i<n;i++)
            for (j=0;j<n;j++)
                mp[i][j]=inf;
        memset(du,0,sizeof(du));
        memset(route,-1,sizeof(route));
        memset(list,-1,sizeof(list));
        idx=0;
        for (i=0;i<n-1;i++)
        {
            scanf("%d%d",&u,&v);
            u--;
            v--;
            insert(u,v,1);
            insert(v,u,1);
            route[u][v]=v;
            route[v][u]=u;
            du[u]++;
            du[v]++;
        }
        one=0;
        for (i=1;i<n;i++)
            if (du[i]==1)
                one++;
        for (i=0;i<n;i++)
        {
            dij(n,i,dis,r);
            for (j=0;j<n;j++)
                route[i][j]=r[j];
        }


        st=0;
        cnt=0;
        for (i=0;i<one;i++)
        {
            scanf("%d",&u);
            u--;
            for (j=st;j!=u;j=route[j][u])
                out[cnt++]=j+1;
            if (cnt>n*2-1) break;
            st=u;
        }
        for(;i<one;i++)
            scanf("%d",&u);
        for (i=st;i!=0;i=route[i][0])
        {
            out[cnt++]=i+1;
            if (cnt>n*2-1) break;
        }
        out[cnt++]=1;
        if (cnt>2*n-1)
            printf("-1\n");
        else
            for (i=0;i<cnt;i++)
                printf("%d ",out[i]);
        printf("\n");
    }
    return 0;
}
