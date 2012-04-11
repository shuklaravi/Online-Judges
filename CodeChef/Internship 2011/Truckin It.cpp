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
#define LASTSETBIT(x) (x & ~(x-1))
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
void sort(int &a, int &b, int &c)
{
    if(b>c) swap(b,c);
    if(a>b) swap(a,b);
    if(b>c) swap(b,c);
    return ;
}
void sort(LL &a, LL &b, LL &c)
{
    if(b>c) swap(b,c);
    if(a>b) swap(a,b);
    if(b>c) swap(b,c);
    return ;
}
int main()
{
    int test,i;
    cin>>test;
    while(test--)
    {
        int arr[3],res=0;
        int orig[3];
        LL temp[3]={0};
        LL tempp;
        cin>>arr[0]>>arr[1]>>arr[2];
        REP(i,3) orig[i]=arr[i];
        sort(arr[0],arr[1],arr[2]);
        while(1)//arr[0]>0 || arr[1]>0 || arr[2]>0)
        {
            temp[0]=1;temp[1]=1;temp[2]=1;
            while(temp[0]<arr[0]) temp[0]<<=1;
            while(temp[1]<arr[1]) temp[1]<<=1;
            while(temp[2]<arr[2]) temp[2]<<=1;

            if(temp[0] > arr[0]) temp[0]>>=1;
            if(temp[1] > arr[1]) temp[1]>>=1;
            if(temp[2] > arr[2]) temp[2]>>=1;

            sort(temp[0],temp[1],temp[2]);
            cout<<temp[0]<<" "<<temp[1]<<" "<<temp[2]<<endl;
            tempp=temp[0];
            if(tempp==0) tempp=temp[1];
            if(tempp==0) tempp=temp[2];
            cout<<"..........."<<tempp<<endl;
            if(tempp==0) break;







            int x= ( arr[0]/tempp ) ; if(x==0) x++;
            int y= ( arr[1]/tempp ) ; if(y==0) y++;
            int z= ( arr[2]/tempp ) ; if(z==0) z++;

            res+= ( x*y*z );
            arr[0]=( orig[0]%tempp );
            arr[1]=( orig[1]%tempp );
            arr[2]=( orig[2]%tempp );
            cout<<x<<" "<<y<<" "<<z<<endl;
            cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<"..................";
            sort(arr[0],arr[1],arr[2]);
            cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
        }
        cout<<res<<endl;
    }
//	system("pause");
	return 0;
}






























