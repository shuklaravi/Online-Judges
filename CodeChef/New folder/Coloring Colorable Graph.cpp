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
bool adj[505][505];
bool poss[505][505];
int vis[505];
int n;
void func(int x)
{
    int i,j;
    for(i=0;i<n;i++) {
        if(vis[i]<=x) continue;
		    vis[i]-=x;
		    for(j=0;j<n;j++)
                if(i!=j && adj[i][j] && vis[i]==vis[j]) break;
            if(j!=n) vis[i]+=x;
    }
}
int main()
{
	int i,t,m,j,k,p,q;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(adj,0,sizeof(adj));
		memset(poss,1,sizeof(poss));
		memset(vis,-1,sizeof(vis));
		for(i=0;i<m;i++) {
			scanf("%d%d",&p,&q);p--;q--;
			if(p>q) swap(p,q);
			adj[p][q]=1;
			adj[q][p]=1;
		}
		for(i=0;i<n;i++) {
			if(vis[i]==-1) {
			    vis[i]=1;
			}
			for(j=i+1;j<n;j++) {
                if(adj[i][j]) {
                    poss[j][vis[i]-1]=0;
                    for(k=0;k<n;k++) {
                        if(poss[j][k]) {
                            vis[j]=k+1;
                            break;
                        }
                    }
/*                    if(k==n) {
                        vis[j]=max(vis[j],vis[i]+1);
                    }
  */              }
			}
		}
//		for(i=0;i<n;i++) cout<<vis[i]<<" ";
//		cout<<endl;
		for(i=0;i<n;i++)
            func(i);
		for(i=0;i<n;i++) {
			if(i==0) cout<<vis[i];
			else cout<<" "<<vis[i];
		}
		if(n!=0)
		cout<<endl;
	}
	return 0;
}





























