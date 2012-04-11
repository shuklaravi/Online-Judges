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
#define EPS 1e-11
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
typedef long long unsigned     LLU;

template<class T> void print(const vector<T> &v){ostringstream os; for(int i=0; i<v.size(); ++i){if(i)os<<' ';os<<v[i];} cout<<os.str()<<endl;}
template<class T, class U> T cast (U x) { ostringstream os; os<<x; T res; istringstream is(os.str()); is>>res; return res; }
template<class T> vector<T> split(string s, string x=" ") {vector<T> res; for(int i=0;i<s.size();i++){string a; while(i<(int)s.size()&&x.find(s[i])==string::npos)a+=s[i++]; if(!a.empty())res.push_back(cast<T>(a));} return res;}

inline void input( int &n ) { n=0; int ch=getchar(); while( ch < '0' || ch > '9' ) ch=getchar(); while( ch >= '0' && ch <= '9' ) n = (n<<3)+(n<<1) + ch-'0', ch=getchar(); }

#define LMOD 1051962371
#define MAXN 100
LLU bc[10005][10005];
int main(){
   // freopen("hc_r1_a_input.txt","r+",stdin);
   // freopen("hc_r1_a_output.txt","w+",stdout);
    int fact[101],i,j,tcases,n,m,count;


    for(i=0;i<MAXN;i++)bc[i][0]=1;
    for(j=0;j<MAXN;j++)bc[j][j]=1;
    for(i=1;i<MAXN;i++)
    for(j=1;j<i;j++)
    bc[i][j]=bc[i-1][j-1]+bc[i-1][j];
    cin>>tcases;
    LLU temp_n,temp_d;
    while(tcases--){
        cin>>n>>m;
        if(n<10005 && m<10005)
        cout<<bc[n][m]<<endl;
        else
        {
            temp_n=1;
            temp_d=1;
            for(i=min(10005,n),j=min(10005,m);i<=n&&j<=m;i++,j++)
            {
                int temp=GCD(i,j);
                temp_n*=i/temp;
                temp_d*=j/temp;
                temp_n/=GCD(temp_n,temp_d);
                temp_d/=GCD(temp_n,temp_d);
            }
            if(i>n && j<=m)
            {
                j--;
                for(;j<=m;j++)
                {
                    LLU temp=GCD((i-j+1),j);
                    temp_n*=(i-j+1)/temp;
                    temp_d*=j/temp;
                    temp_n/=GCD(temp_n,temp_d);
                    temp_d/=GCD(temp_n,temp_d);
                }
            }
            if(j>m && i<=n)
            {
                i--;
                for(;i<=n;i++)
                {
                    LLU temp=GCD(i,i-j);
                    temp_n*=(i)/temp;
                    temp_d*=(i-j)/temp;
                    temp_n/=GCD(temp_n,temp_d);
                    temp_d/=GCD(temp_n,temp_d);
                }
            }
            LLU temp=GCD(bc[10004][10004],temp_d);
            int num=bc[10004][10004]/temp;
            num*=temp_n;
            temp_d/=temp;
            cout<<num/temp_d<<endl;
        }
    }
    return 0;
}
