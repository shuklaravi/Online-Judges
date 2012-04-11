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
typedef long long       LL;
typedef pair<int,int>   PII;
typedef pair<LL,LL>   PLL;
typedef pair<char,int>  PCI;
typedef pair<int,PII>   TRI;
typedef pair<LL,PLL>   TRL;
typedef pair<double,PLL>   TRDL;
typedef V( int )        VI;
typedef V( PII )        VII;
typedef V( TRI )        VTRI;
typedef V( string )     VS;

typedef long double     LD;

template<class T> void print(const vector<T> &v){ostringstream os; for(int i=0; i<v.size(); ++i){if(i)os<<' ';os<<v[i];} cout<<os.str()<<endl;}
template<class T, class U> T cast (U x) { ostringstream os; os<<x; T res; istringstream is(os.str()); is>>res; return res; }
template<class T> vector<T> split(string s, string x=" ") {vector<T> res; for(int i=0;i<s.size();i++){string a; while(i<(int)s.size()&&x.find(s[i])==string::npos)a+=s[i++]; if(!a.empty())res.push_back(cast<T>(a));} return res;}

inline void input( int &n ) { n=0; int ch=getchar(); while( ch < '0' || ch > '9' ) ch=getchar(); while( ch >= '0' && ch <= '9' ) n = (n<<3)+(n<<1) + ch-'0', ch=getchar(); }

//END_TEMPLATE_BY_PRATYUSH_VERMA
int N;
int main()
{
    cin>>N;
    vector<PLL> a;
    vector<TRDL> A;
    LL i,j,k,p,q;
    double xag=0,yag=0;
    REP(i,N) {
        cin>>p>>q;
        xag+=p;
        yag+=q;
        PB(a,MP(p,q));
    }
    xag/=(double)N;
    yag/=(double)N;
//    cout<<xag<<" "<<yag<<"......\n";
    REP(i,N)
    {
        double dX = fabs(a[i].first - xag);
        double dY = fabs(a[i].second -yag);
        PB(A, MP(max(dX,dY),MP(a[i].first, a[i].second)));
    }
    sort(ALL(A));
    LL dist = 0, res = 0;
    int test = min(1,N);
    FOR(i,0,test)
    {
        dist = 0;
        FOR(j,0,N)
        {
            dist += max(fabs((A[j].second.first - A[i].second.first)) , fabs((A[j].second.second - A[i].second.second)));
        }
        if(i==0) res = dist;
        if(dist < res)
            res = dist;
    }
    cout<<res<<endl;
	return 0;
}

