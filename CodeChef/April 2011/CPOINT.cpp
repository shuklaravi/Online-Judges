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

typedef pair<long,long>   PII;
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
double dist(double a, double b, double x, double y)
{
    return sqrt( ((a-x)*(a-x))+((b-y)*(b-y)) );
}
int main()
{
    int n,nn;
    double a,b,i,x,y,p_i,p_j;
    vector<PII> v;
    vector<double> vv;
    while(cin>>n)
    {
        if(n==0) break;
        if(n==1)
        {
            cin>>a>>b;
            printf("%0.6lf\n",0);
            continue;
        }
        v.clear();
        vv.clear();
        nn=20;
        REP(i,n)
        {
            cin>>a>>b;
            PB(v,MP(a,b));
            PB(vv,1);
        }
        x=y=0;
        REP(i,n)
        {
            x+=v[i].first;
            y+=v[i].second;
        }
        p_i=x/n; p_j=y/n;
        while(nn--) {
        REP(i,n)
        {
            double temp=dist((double)p_i,(double)p_j,(double)v[i].first,(double)v[i].second);
            vv[i]=temp;
        }
        x=y=0;
        REP(i,n)
        {
            if(vv[i]==0.0) continue;
            x+=v[i].first/vv[i];
            y+=v[i].second/vv[i];
        }
        a=b=0;
        REP(i,n)
        {
            if(vv[i]==0.0) continue;
            a+=(1/vv[i]);
        }
        x/=a; y/=a;
        p_i=x; p_j=y;
        }
        double sum=0,sum1=0;
        REP(i,n)
        {
            sum+=dist(floor(p_i),floor(p_j),(double)v[i].first,(double)v[i].second);
        }
        REP(i,n)
        {
            sum1+=dist(ceil(p_i),floor(p_j),(double)v[i].first,(double)v[i].second);
        }
        sum=min(sum,sum1);
        sum1=0;
        REP(i,n)
        {
            sum1+=dist(ceil(p_i),ceil(p_j),(double)v[i].first,(double)v[i].second);
        }
        sum=min(sum,sum1);
        sum1=0;
        REP(i,n)
        {
            sum1+=dist(floor(p_i),ceil(p_j),(double)v[i].first,(double)v[i].second);
        }
        sum=min(sum,sum1);
        printf("%0.6lf\n",sum);
    }
//	system("pause");
	return 0;
}





























