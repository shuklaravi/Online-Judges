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
#define MOD 1000000000
int n,m;
vector<int> adj[10000];
vector<int> trans[10000];
vector<int> order;

bool vis[10000];
int index1[10000];
int idx;
void isCycle(int S)
{
	int i;
	index1[S] = 0;
	REP(i,adj[S].size())
	{
		if(index1 [adj[S][i]] < 0) 
			isCycle(adj[S][i]);
	}
	index1[S] = idx;
	++idx;
}
bool dfs(int S)
{
	int i;
	vis[S] = 1;
	REP(i,trans[S].size())
	{
		if(vis[trans[S][i]] == 1) continue;
		return false;
	}
	return true;
}
int countBFS(int start)
{
	if(start == n-1) return 1;
	int end,c=0;
	REP(end,adj[start].size())
	{
		c=(c%MOD + countBFS(adj[start][end])%MOD)%MOD;
	}
	return c%MOD;
}
int main()
{
	cin>>n>>m;
	int i,j,k,p,q;
	MEM(vis,0);
	MEM(index1,-1);
	REP(i,m)
	{
		cin>>p>>q;
		p--; q--;
//		REP(j,adj[p].size())
	//		if(adj[p][j] == q)
		//		break;
		//if(j == adj[p].size())
		PB(adj[p],q);
		PB(trans[q],p);
	}
	idx = 1;
	for(int i = 0; i < n; ++i)
	{
	    if(index1[i]==-1)
        {
			isCycle(i);
		}
	}
//	for(int i = 0; i < n; ++i)
	//{
		//cout<<i<< " "<<index1[i]<<"\n";
//	}
	
	vector<PII> v;
	for(int i = 0; i< n ;++i)
	{
		PB(v,MP(index1[i],i));
	}
	sort(ALL(v));
	reverse(ALL(v));
	for( i = 0; i < n && dfs(v[i].second); ++i)
	{
//		cout<<v[i].second<<" PASSED!\n";
	}
	if(i<n)
	//cout<<"FAILED " <<v[i].second<<endl;
	if(i != n)
	{
		cout<<"INFINITE PATHS\n";
		return 0;
	}
	cout<<countBFS(0);
	return 0;
}















