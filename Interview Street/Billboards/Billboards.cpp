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

int N,K;
struct node {
	int data, incl, excl, count;
	node(int x, int a, int b) {
		data = x; incl = a; excl = b; count = 0;
	}
};
vector<node> dp;
int func()
{
	int i,j,k,p,q;
	dp[0].incl = dp[0].data;
	dp[0].count = 1;
	/*
	incl excl
1   1   0   1
2   3   1   2
3   4   3   1
1   5   3   2
6
10
	*/
	FOR(i,1,N)
	{
	    //including dp[i].data
		if(dp[i-1].count == K)
		{
		    dp[i].incl = dp[i-1].excl + dp[i].data;
		    dp[i].count = 1;
		}
        else
        {
            dp[i].incl = max(dp[i-1].excl + dp[i].data, dp[i-1].incl + dp[i].data);
            if(dp[i-1].excl == dp[i].incl)
            {
                dp[i].count = 1;
            }
            else
            {
                dp[i].count = dp[i-1].count + 1;
            }
        }
        //excluding dp[i].data
		dp[i].excl = max(dp[i-1].excl, dp[i-1].incl);
	}
	return max(dp[N-1].incl, dp[N-1].excl);
}
int main()
{
	int i;
	int arr[N];
	cin>>N>>K;
	REP(i,N)
	{
		cin>>arr[i];
		PB(dp, node(arr[i], 0, 0));
	}
	cout<<func();
	cout<<".................\n";
	REP(i,N)
	{
	    cout<<i<<" "<<dp[i].data<<"\t"<<dp[i].incl<<"\t"<<dp[i].excl<<"\t"<<dp[i].count<<"\n";
	}
	return 0;
}