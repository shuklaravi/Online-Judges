    ///////////////////////////////////////////////////////////
    //      TEMPLATE FROM ANGRY PROGRAMMER  UVa  11506      ///
    ///////////////////////////////////////////////////////////

/*
ID: vermapr1
PROG: <prog_name>
LANG: C++
*/

// #define TRUE FALSE haha now debug this
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
#define GCD(x,y) __gcd(x,y)

typedef pair<int,int>   PII;
typedef pair<char,int>  PCI;
typedef pair<int,PII>   TRI;
typedef V( int )        VI;
typedef V( PII )        VII;
typedef V( TRI )        VTRI;
typedef V( string )     VS;
typedef long long       LL;
typedef long double     LD;

template<class T> void print(const vector<T> &v){ostringstream os; for(int i=0; i<v.size(); ++i){if(i)os<<' ';os<<v[i];} cout<<os.str()<<endl;}
template<class T, class U> T cast (U x) { ostringstream os; os<<x; T res; istringstream is(os.str()); is>>res; return res; }
template<class T> vector<T> split(string s, string x=" ") {vector<T> res; for(int i=0;i<s.size();i++){string a; while(i<(int)s.size()&&x.find(s[i])==string::npos)a+=s[i++]; if(!a.empty())res.push_back(cast<T>(a));} return res;}

inline void input( int &n ) { n=0; int ch=getchar(); while( ch < '0' || ch > '9' ) ch=getchar(); while( ch >= '0' && ch <= '9' ) n = (n<<3)+(n<<1) + ch-'0', ch=getchar(); }

//END_TEMPLATE_BY_PRATYUSH_VERMA

int M,W;
int adj[220][220];
bool vis[220];
int from[220];
int source, sink;

int in(int i) { return 2*i; }
int out(int i) { return 2*i+1; }




int bfs(int source, int sink)
{
    MEM(from,-1);
    MEM(vis,0);
    queue<int> q;
    q.push(source);
    int i,t,min=-1;
    vis[source]=true;
    bool flag=0;
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(t==sink) break;
        FOR(i,source,sink+1)
        {
            if(vis[i]!=0) continue;
            if(adj[t][i]<=0 ) continue;
            q.push(i);
            vis[i]=t;
            from[i]=t;
        }
    }
//    REP(i,W) cout<<i<<" "<<from[i]<<endl;
    int where = sink, path_cap = INF, prev;
//    cout<<"path  : \n";
    while(from[where]>-1)
    {
//        cout<<where <<"<----";
        prev = from[where];
//        cout<<prev<<"<-----";
        path_cap = MIN (path_cap, adj[prev][where]);
        where=prev;
    }
//    cout<<endl;
    where = sink;
    while(from[where]>-1)
    {
        prev = from [where];
        adj[prev][where] -= path_cap;
        adj[where][prev] += path_cap;
        where = prev;
    }
//    cout<<"path cap = "<<path_cap<<endl;
    if(path_cap == INF ) return 0;
    return path_cap;
}

int maxflow(int source, int sink)
{
    int ret=0;
    while(1)
    {
        int flow=bfs(source, sink);
        if(flow==0) return ret;
        ret+=flow;
//        cout<<"flow inc to "<<ret<<endl;
    }
}



int main()
{
    ///////////////////////////////////////////////////////////
    //      TEMPLATE FROM ANGRY PROGRAMMER  UVa  11506      ///
    ///////////////////////////////////////////////////////////
    int i,j,k,p,q;
    while(cin>>M>>W && ( M || W) )
    {
        MEM(adj,0);
        REP(i,M-2)
        {
            cin>>p>>q; p--;
            adj[in(p)][out(p)]=q;
        }
        REP(i,W)
        {
            cin>>p>>q>>k; p--; q--;
            adj[out(p)][in(q)]=k;
            adj[out(q)][in(p)]=k;
        }

        // DEFINE source AND sink HERE
        source = out(0);
        sink = in(M-1);

        cout<<maxflow(source,sink)<<'\n';
    }
	return 0;
}























