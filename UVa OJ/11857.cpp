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
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
//BEGIN_TEMPLATE_BY_PRATYUSH_VERMA

//CONSTANT
#define INF (1<<31)-1
#define PI 3.1428571428571428571428571428571

//FUNC
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
#define V(x) vector < x >

//BITWISE
#define LASTSETBIT(x) x & ~(x-1)
#define TRAILZERO(x) __builtin_ctz(x)
#define LEADZERO(x) __builtin_clz(x)
#define COUNTSETBIT(x) __builtin_popcount(x)

typedef pair<int,int>   PII;
typedef pair<char,int>  PCI;
typedef pair<int,PII>   TRI;
typedef V( int )        VI;
typedef V( PII )        VII;
typedef V( TRI )        VTRI;
typedef V( string )     VS;
typedef long long       LL;
typedef long double     LD;

inline string i2s(int number) { stringstream ss; ss << number; return ss.str(); }
inline void input( int &n ) { n=0; int ch=getchar(); while( ch < '0' || ch > '9' ) ch=getchar(); while( ch >= '0' && ch <= '9' ) n = (n<<3)+(n<<1) + ch-'0', ch=getchar(); }
vector<int> adj[1000000];
bool vis[1000000];
int m,n;
//END_TEMPLATE_BY_PRATYUSH_VERMA
struct node {
    int i;
    node (int a) {i=a;}
	   friend bool operator< (const node &a, const node &b)
	   {
			  return (a.i>b.i);
	   		  }

};
int dfs()
{
    int min=0;
    priority_queue<node> s;
    s.push(node (0));
    int i;
    while(!s.empty())
    {
        node t=s.top();
        s.pop();
        vis[t.i]=true;
        REP(i,n)
        {
            if(vis[i]==true || t.i==i) continue;
            if( adj[t.i][i]==-1) continue;
            if(adj[t.i][i]>min) min=adj[t.i][i];
            s.push(node (i));
        }
    }
    REP(i,n)
    if(!vis[i]) return -1;
    return min;
}
int main()
{
    int i,j,k,p,q;
    while(1)
    {
        input(n);
        input(m);
        if(m==0 && n==0) return 0;
        if(m<n-1)
        {
                printf("IMPOSSIBLE\n");
            continue;
        }
        MEM(vis,0);
        REP(i,n) adj[i].clear();
        REP(i,n)
        REP(j,n) PB(adj[i],-1);
        REP(i,m)
        {
            input(p);
            input(q);
            input(k);
//            cin>>p>>q>>k;
            if(adj[p][q]!=-1) k=min(k,min(adj[p][q],adj[q][p]));
            adj[p][q]=k;
            adj[q][p]=k;
        }
        int flag=dfs();
        if(flag==-1) printf("IMPOSSIBLE\n");
        else
        {
        printf("%d\n",flag);
        }
    }
	return 0;
}






















