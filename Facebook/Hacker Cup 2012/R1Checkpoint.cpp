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

//PAIR
#define F first
#define S second


//BITWISE
#define LASTSETBIT(x) x & ~(x-1)
#define TRAILZERO(x) __builtin_ctz(x)
#define LEADZERO(x) __builtin_clz(x)
#define COUNTSETBIT(x) __builtin_popcount(x)
#define GCD(x,y) __gcd(x,y)

typedef long long       LL;
typedef long double     LD;
typedef pair<int,int>   PII;
typedef pair<LL,LL>     PLL;
typedef pair<char,int>  PCI;
typedef pair<int,PII>   TRI;
typedef pair<LL,PLL>    TRL;
typedef V( int )        VI;
typedef V( PII )        VII;
typedef V( TRI )        VTRI;
typedef V( string )     VS;


template<class T> void print(const vector<T> &v){ostringstream os; for(int i=0; i<v.size(); ++i){if(i)os<<' ';os<<v[i];} cout<<os.str()<<endl;}
template<class T, class U> T cast (U x) { ostringstream os; os<<x; T res; istringstream is(os.str()); is>>res; return res; }
template<class T> vector<T> split(string s, string x=" ") {vector<T> res; for(int i=0;i<s.size();i++){string a; while(i<(int)s.size()&&x.find(s[i])==string::npos)a+=s[i++]; if(!a.empty())res.push_back(cast<T>(a));} return res;}

inline void input( int &n ) { n=0; int ch=getchar(); while( ch < '0' || ch > '9' ) ch=getchar(); while( ch >= '0' && ch <= '9' ) n = (n<<3)+(n<<1) + ch-'0', ch=getchar(); }

//END_TEMPLATE_BY_PRATYUSH_VERMA
int dp[2][10000005];
map<int,PII> m;
int main()
{
	int j;
	int ways;
	MEM(dp,0);
	dp[0][1]=1;
	for(int i=1;i<10000005;i++)
	{
		dp[i%2][1]=1;
		for(j=1;j<=(i/2)+1;j++)
		{
//			cout<<"calculating "<<i<<" "<<j<<endl;
			if(dp[(i-1)%2][j-1] == -1) {dp[i%2][j]=-1;break;}
			if(j==(i/2)+1 && i%2==0) dp[i%2][j] = dp[(i-1)%2][j-1] * 2;
			else dp[i%2][j] = dp[(i-1)%2][j-1] + dp[(i-1)%2][j];
			if(dp[i%2][j] > 10000000) {dp[i%2][j]=-1;break;}
			ways = dp[i%2][j];
			if(m.find(ways)!=m.end()) {
				PII p=m[ways];
//				cout<<ways<<" "<<p.F<<" "<<p.S<<", "<<i<<" "<<j<<endl;
				if((m[ways].F + m[ways].S) > (i)) m[ways] = MP(i-j+1,j-1);
//				getchar();
			}
			else m[ways] = MP(i-j+1,j-1);
	//		cout<<ways<<" "<<i-j+1<<" "<<j-1<<endl;
//			getchar();
		}
		//cout<<i<<" : \n";
		//for(j=1;j<=(i/2)+1;j++) cout<<dp[i%2][j]<<" ";
	//	cout<<endl;
//		getchar();
	}
//	cout<<".";
	m[1]=MP(1,0);
	int res = 0, dist, t;
	cin>>t;
	for(int cases = 1; cases <= t; cases++)
	{
		cin>>dist;
		res = INT_MAX;
		for(int part = sqrt(dist); part > 0; part--) {
			if(ceil(dist/(double)part) != floor(dist/(double)part)) continue;
			//cout<<part<<" "<<dist/part<<"......\n";
			if(m.find(part)!=m.end() && m.find(dist/part)!=m.end()) {
				res = MIN(res,m[part].F+m[part].S + m[dist/part].F+m[dist/part].S);
		//		cout<<part<<"  : "<<m[part].F<<" "<<m[part].S<<endl;
	//			cout<<(dist/part)<<"  : "<<m[dist/part].F<<" "<<m[dist/part].S<<endl;
//				cout<<"............\n";
			}
		}
		cout<<"Case #"<<cases<<": "<<res<<endl;
	}
	
//	system("pause");
	return 0;
}
