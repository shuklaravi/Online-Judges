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
bool img[32][32];
int idx;
void rec(string s,int ratio, int x, int y)
{
//    cout<<"now @ index "<<idx<<" with ratio "<<ratio<<" and coordinates of  "<<x<<" "<<y<<endl;
//    cout<<"............. "<<s[idx]<<endl;
    int i,j,k,p,q;
    if(s[idx]=='f')
    {
//        idx++;
        int count=0;
//        cout<<"alloting ones "<<" from "<<x<<" to "<<x+ratio<<" and from "<<y<<" to "<<y+ratio<<endl;
        FOR(i,x,x+ratio)
        FOR(j,y,y+ratio)
        {img[i][j]=1;count++;}
//        cout<<"!!!!!!! no of pixels painted "<<count<<endl;
    }
    else if(s[idx]=='p')
    {
        idx++;
//        cout<<"calling "<<idx<<" with ratio "<<ratio/2<<" and co-ordinates of "<<x<<" "<<y<<endl;
        rec(s,ratio/2,x,y);
        idx++;
//        cout<<"calling "<<idx<<" with ratio "<<ratio/2<<" and co-ordinates of "<<x+(ratio/2)<<" "<<y+(ratio/2)<<endl;
        rec(s,ratio/2,x+(ratio/2), y+(ratio/2));
        idx++;
//        cout<<"calling "<<idx<<" with ratio "<<ratio/2<<" and co-ordinates of "<<x<<" "<<y+(ratio/2)<<endl;
        rec(s,ratio/2,x, y+(ratio/2));
        idx++;
//        cout<<"calling "<<idx<<" with ratio "<<ratio/2<<" and co-ordinates of "<<x+(ratio/2)<<" "<<y<<endl;
        rec(s,ratio/2,x+(ratio/2), y);
    }
}
int main()
{
    
    int n,i,j,k,p,q;
    cin>>n;
    while(n--)
    {
        MEM(img,false);
        string s1,s2;
        cin>>s1>>s2;
        int idx1=0,idx2=0;
        int total=0;
        idx=0;
        rec(s1,32,0,0);
//        cout<<"????????????????????????????????????????????????\n";
        idx=0;
        rec(s2,32,0,0);
        REP(i,32)
        REP(j,32)
        if(img[i][j]==true) total++;
        cout<<total<<" black pixels."<<endl;
    }
    
//	system("pause");
	return 0;
}

























