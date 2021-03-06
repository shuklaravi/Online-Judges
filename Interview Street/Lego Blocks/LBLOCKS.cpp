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
typedef long long LL;
typedef long double     LD;

template<class T> void print(const vector<T> &v){ostringstream os; for(int i=0; i<v.size(); ++i){if(i)os<<' ';os<<v[i];} cout<<os.str()<<endl;}
template<class T, class U> T cast (U x) { ostringstream os; os<<x; T res; istringstream is(os.str()); is>>res; return res; }
template<class T> vector<T> split(string s, string x=" ") {vector<T> res; for(int i=0;i<s.size();i++){string a; while(i<(int)s.size()&&x.find(s[i])==string::npos)a+=s[i++]; if(!a.empty())res.push_back(cast<T>(a));} return res;}

inline void input( int &n ) { n=0; int ch=getchar(); while( ch < '0' || ch > '9' ) ch=getchar(); while( ch >= '0' && ch <= '9' ) n = (n<<3)+(n<<1) + ch-'0', ch=getchar(); }

//END_TEMPLATE_BY_PRATYUSH_VERMA
#define MOD 1000000007
LL solid[1005], notSolid[1005][1005], wd[1005];
LL pow2(LL num)
{
    return (num * num)%MOD;
}
LL pow_log(LL num, LL x)
{
    if(x == 0) return 1;
    if(x == 1) return num%MOD;
    if(x & 1) return (num * pow_log(num, x-1))%MOD;
    return (pow2( pow_log(num, x/2)))%MOD;
}
LL ipow(LL base, LL exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}
LL Pow(LL x, int power)
{
        if (power == 0)
                return 1;

        if (power == 1)
                return x;

        int c, i, k;
        LL res;
        LL px;
        for (i = 1, px = x, res = 1, k = power; k; k /= 2)
        {
                c = k % 2;
                if (c)
                        res = (res * px)  % MOD;
                px = (px * px) % MOD;
        }
        return res  % MOD;
}
int main()
{
    int i,j,k,p,q;
    int t;
//    cout<<Pow(3LL,2)<<endl;
    cin>>t;

    wd[0] = 1;
    wd[1] = 1;
    wd[2] = 2;
    wd[3] = 4;
    FOR(i,4,1001)
        wd[i] = ((wd[i-1] + wd[i-2]) % MOD + (wd[i-3] + wd[i-4])% MOD)%MOD;
/*
    FOR(i,1,10)
        cout<<wd[i]<<" ";
*/
    FOR(i,1,1001)
    {
        FOR(j,1,1001)
            notSolid[i][j] = Pow(wd[i], j);
    }
/*
    cout<<endl;
    FOR(i,1,10)
    {
            cout<<notSolid[i][5]<<" ";
    }
*/

    while(t--)
    {
        int n,m;
        cin>>n>>m;

//        FOR(i,1,m+1)
  //          cout<<i<<" : "<<notSolid[i]<<endl;
        solid[1] = notSolid[1][m];
    //    cout<<"..................\n";
        FOR(i,2,m+1)
        {
            LL rem = 0;
            FOR(j,1,i)
            {
                rem =  (rem + (solid[j] * notSolid[i-j][n])%MOD)%MOD;
            }
            solid[i] = notSolid[i][n] - rem;
            while(solid[i] < 0)
				solid[i] += MOD;
  //          cout<<i<<" : "<<solid[i]<<" = "<<notSolid[i][n]<<" - "<<rem<<endl;
        }

        cout<<solid[m]<<endl;
    }
//	system("pause");
	return 0;
}





























