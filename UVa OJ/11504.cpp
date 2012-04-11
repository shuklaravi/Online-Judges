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
#define LASTSETBIT(x) x & ~(x-1)
#define TRAILZERO(x) __builtin_ctz(x)
#define LEADZERO(x) __builtin_clz(x)
#define COUNTSETBIT(x) __builtin_popcount(x)

#define V(x) vector < x >

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
//END_TEMPLATE_BY_PRATYUSH_VERMA

int T,S,m,n;
VII f;
VII s;
VI adj[100001];
VI adj1[100001];
bool vis[100001];
void dfs(VI adj[100001], int I)
{
    int i;
    PB(s,MP(S++,I));
    vis[I]=true;
    REP(i,adj[I].size())
    {
        if(vis[adj[I][i]]==false)
        {
            dfs(adj,adj[I][i]);
        }
    }
    PB(f,MP(T++,I));
}
int main()
{
    int test;
    cin>>test;
    int i,j,k,p,q;
    while(test--)
    {

        cin>>n>>m;
//        MEM(f,-1);
        MEM(vis,false);
        s.erase(ALL(s));
        f.erase(ALL(f));
        REP(i,100001)
        {
//            f[i].erase();
            adj[i].clear();
            adj1[i].clear();
        }
        REP(i,m)
        {
            cin>>p>>q;
            p--; q--;
            PB(adj[p],q);
            PB(adj1[q],p);
        }
        
        REP(i,n)
        {
            if(vis[i]==false)
            {
                cout<<i<<endl;
                T=1;
                S=1;
                dfs(adj,i);
            }
        }
        MEM(vis,false);
        sort(ALL(f));
//        reverse(ALL(f));
        int count=0;
        REP(i,n)
        {
            if(vis[f[i].second]==false)
            {
                dfs(adj1,f[i].second);
                count++;
            }
        }
        cout<<count<<endl;
    }
//	system("pause"); //Windows Only
	return 0;
}






















