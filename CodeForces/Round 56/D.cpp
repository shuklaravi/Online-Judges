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

template<class T> void print(const vector<T> &v){ostringstream os; for(int i=0; i<v.size(); ++i){if(i)os<<' ';os<<v[i];} cout<<os.str()<<endl;}
template<class T, class U> T cast (U x) { ostringstream os; os<<x; T res; istringstream is(os.str()); is>>res; return res; }
template<class T> vector<T> split(string s, string x=" ") {vector<T> res; for(int i=0;i<s.size();i++){string a; while(i<(int)s.size()&&x.find(s[i])==string::npos)a+=s[i++]; if(!a.empty())res.push_back(cast<T>(a));} return res;}

inline void input( int &n ) { n=0; int ch=getchar(); while( ch < '0' || ch > '9' ) ch=getchar(); while( ch >= '0' && ch <= '9' ) n = (n<<3)+(n<<1) + ch-'0', ch=getchar(); }

//END_TEMPLATE_BY_PRATYUSH_VERMA
int arr[1005][1005],dir[1005][1005];
int main()
{
    char s1[1005],s2[1005];
    gets(&s1[1]);gets(&s2[1]);
    s1[0]='.';s2[0]='.';
    int i,j;
    REP(i,strlen(s1)+1)
    arr[0][i]=i;
    REP(i,strlen(s2)+1)
    arr[i][0]=i;
    int x,min;
    int l[4];
    REP(i,strlen(s2)+1)
    {
        REP(j,strlen(s1)+1)
        {
            l[1]=arr[i][j-1] +(s1[i]==s2[j]);
            l[2]=arr[i-1][j] +(s1[i]==s2[j]);
            l[3]=arr[i-1][j-1] +(s1[i]==s2[j]);
            min=INF;
            FOR(x,1,4)
            {
                if(l[x]<min)
                {
                    l[x]=min;
                    dir[i][j]=x;
                    cout<<i<<" "<<j<<" "<<x<<" "<<min<<endl;
                }
            }
        }
    }
    
    cout<<arr[strlen(s2)][strlen(s1)]<<endl;
    int I=strlen(s2),J=strlen(s1);
    vector<string> res;
    while(I==0 || J==0)
    {
        if(dir[I][J]==1)
        {
            PB(res,"INSERT ");//+I+s2[J]);
            J--; continue;
        }
        else if(dir[I][J]==2)
        {
            PB(res,"DELETE "+I);
            I--; continue;
        }
        else if(dir[I][J]==3)
        {
            if(s1[I]==s2[J]) continue;
            PB(res,"REPLACE ");
            I--; J--; continue;
        }
    }
    REP(i,strlen(s2)+1)
    {
        REP(j,strlen(s1)+1)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    reverse(ALL(res));
    REP(i,res.size())
    {
        cout<<res[i]<<endl;
    }
    
    
    
	system("pause");
	return 0;
}
