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
set<int> adj[10000];
set<int>::iterator it;
vector<int> state(10000,0);
bool isCycle(int S)
{
	cout<<"visiting "<<S<<endl;
	if(S == n-1) {
		state[S] = 2;
		cout<<"REturning FALSE\n";
		return false;
	}
	state[S] = 1;
	cout<<S<<"city "<<state[S]<<endl;
	int D;
	cout<<"IN STATE "<<S<<endl;
	for(it = adj[S].begin(); it != adj[S].end(); it++)
		cout<<(*it)<<" ";
	cout<<endl;
	for(it = adj[S].begin(); it != adj[S].end(); it++)
//	REP(D,adj[S].size())
	{
		if(state[*it] == 1) 
		{
			cout<<"IN QUEUE "<<(*it)<<" @ "<<S<<endl;
			return true;
		}
		else if(state[*it] == 0)
		{
			cout<<"LOOKING FOR NEIGHBOUR IN "<<S<<" TO "<<(*it)<<endl;
			if(isCycle(*it))
			{
				cout<<"HERE**********\n";
				return true;
			}
			else cout<<"RETURNED FALSE "<<(*it)<<" TO "<<S<<endl;
		}
	}
	cout<<"EXITING "<<S<<endl;
	state[S] = 2;
	return false;
}
int countBFS(int start)
{
	if(start == n-1) return 1;
	int end,c=0;
	for(it = adj[start].begin(); it != adj[start].end(); it++)
//	REP(end,adj[start].size())
	{
		c+=countBFS(*it);
		c%=MOD;
	}
	return c%MOD;
}
int main()
{
	cin>>n>>m;
	int i,j,k,p,q;
	REP(i,m)
	{
		cin>>p>>q;
		p--; q--;
		adj[p].insert(q);
//		PB(adj[p],q);
	}
	if(isCycle(0))
	{
		cout<<"INFINITE PATHS\n";
		return 0;
	}
	cout<<countBFS(0);
	return 0;
}
















