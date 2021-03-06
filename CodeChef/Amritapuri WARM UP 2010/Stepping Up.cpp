//
// Dear Judge:
//
// Once you are done trying to 'bug/debug' this routine,
// and have realized what a terrible mistake that was,
// please increment the following counter as a warning
// to the next guy:
//
// total_hours_wasted_here = INF
// know what the MACRO means scroll down..
//

using namespace std;
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
//BEGIN_TEMPLATE_BY_PRATYUSH_VERMA
#define INF (1<<31)-1
#define MAX(i,j) (i)>(j)?(i):(j)
#define MIN(i,j) (i)<(j)?(i):(j)
#define REP(i,a) for((i)=0;(i)<(a);(i)++)
#define REP_(i,a) for((i)=0;(i)<=(a);(i)++)
#define FOR(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define FOR_(i,a,b) for((i)=(a);(i)<=(b);(i)++)
#define VAR(V,init) __typeof(init) V=(init)
#define FOREACH(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((int)(x.size()))
#define LENGTH(x) ((int)(x.length()))
#define SZ(x) sizeof(x)
#define MEM(m,i) memset((m),(i),SZ(m))
#define PB(x,y) (x).push_back(y)
#define MP(x,y) make_pair(x,y)
#define FASTIO 1
typedef long long ll;
#define V(x) vector < x >

//inline string i2s(int number) { stringstream ss; ss << number; return ss.str(); }
//END_TEMPLATE_BY_PRATYUSH_VERMA
bool adj[10005][10005];
int vis[10005];
int rank[10005];
int m,n,MAX;


typedef pair<int,int>   PI;
typedef pair<int,PI>    TRI;
typedef V( int )        VI;
typedef V( PI  )        VII;
typedef V( string )     VS;
typedef long long       LL;
typedef long double     LD;

/* FastIO, generally required these days ;) */

bool cycle(int i, int r)
{
    int j,k,p,q;
    stack<pair<int, int> > s;
    s.push(MP(i,r));
    while(!s.empty())
    {
        pair<int,int> t=s.top();
        s.pop();
        if(t.second+1>MAX) MAX=t.second+1;
        if(t.second>n)
        {
            return true;
        }
        if(rank[t.first]>t.second) continue;
        if(rank[t.first]<=t.second)
        REP(j,n)
        {
            if(adj[t.first][j]==0) continue;
                s.push(MP(j,t.second+1));
        }

    }
    return false;

}
int main()
{
    int i,j,k,p,test,q;
    bool flag=0;
//    scanf("%d",&test);
    while(test--)
    {
        MAX=-1;
        MEM(vis,-1);
        MEM(rank,-1);
        MEM(adj,0);
        flag=0;
        input(n);
        input(m);
//        scanf("%d%d",&n,&m);
        REP(i,m)
        {
            input(p);
            input(q);
//            scanf("%d%d",&p,&q);
            p--; q--;
            if(adj[p][q] || p==q)
            {
                flag=1;
            }
            else
            {
                adj[p][q]=1;
            }
        }
        if(flag)
        {
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        REP(i,n)
        {
            if(rank[i]==-1)
            {
                if(cycle(i,0))
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag)
        {
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        printf("%d\n",MAX);
    }
	return 0;
}
