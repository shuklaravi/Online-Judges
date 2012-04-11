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
LL toBin(string s)
{
    LL ret = 0;
    int i;

    for(i=s.length()-1;i>=0;i--)
    {
        if(s[i]=='1')
            {
                ret|=1;
            }
        ret<<=1;
    }
    ret >>= 1;
    return ret;

}
int func(int n, int x)
{
    if(n==0) return 0;
    if(x>n) return 0;
    int num = 1;
    int i;
    REP(i,n) num*=(i+1);
    int den = 1;
    REP(i,x) den*=(i+1);
    REP(i,n-x) den*=(i+1);
    return num/den;
}
void print(LL mask)
{
    string s="";
    while(mask)
    {
        s+=mask&1?"1":"0";
        mask>>=1;
    }
    cout<<s<<endl;
}
int countBit(LL num)
{
    int ret = 0;
    while(num)
    {
        if(num&1) ret++;
        num>>=1;
    }
    return ret;
}
int main()
{
    int i,j;
    LL mask[9];
    LL part1 = 15;
    LL part2 = 13510798882111488LL;
    REP(i,9)
    {
        mask[i] = (part1 | part2);
       // print(mask[i]);
        part1<<=4;
        part2>>=2;
    }
    int count = 0,x,n;
    int test;
    cin>>x>>n;
    REP(i,n)
    {
        string s;
        cin>>s;
        REP(j,9)
        {
            LL num = toBin(s);
        //    print(num);
      //      print(mask[j]);
            LL temp = (~num)&mask[j];
    //        print(temp);
            int bits = countBit(temp);
            count += func(bits,x);
  //          cout<<bits<<endl;
//            getchar();
        }
        cout<<count<<endl;
    }
    cout<<count;
//	system("pause");
	return 0;
}






























