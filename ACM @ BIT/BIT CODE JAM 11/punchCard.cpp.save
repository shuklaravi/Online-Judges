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
int arr[35];
int main()
{
    int i,j,n1,n2;
    arr[0]=1;
    FOR(i,1,33) arr[i]=(i+2)*pow(2.0,i-1);
    int test,b1,b2;
    LL count;
    cin>>test;
//    REP(i,10) cout<<i<<": "<<arr[i]<<"....";
    while(test--)
    {
        cin>>n1>>n2;
        if(n1>n2) swap(n1,n2);
        b1=b2=0;
        count=0;


        while((1<<b1)<=n1) { b1++; }

        while((1<<b2)<=n2) { b2++; }


        if(n2==0) b2=0;
        if(n1==0) b1=0;


          //cout<<b1<<" "<<b2<<endl;
        //cout<<"1: from "<<(1<<(b1-1))<<" "<<n1<<endl;

        FOR(i,b1-1,b2) {
            count=(count+arr[i])%1000007;
        }
        if(b1>=2)
        FOR(i,1<<(b1-1),n1) {
            count-=COUNTSETBIT(i);
        }
      //  cout<<"1: "<<count<<endl;
    //    cout<<"2: from "<<(1<<b2)<<" "<<n2<<endl;
        if(n2-(1<<(b2-1))>(1<<b2 - n2))
        FOR(i,n2+1,(1<<b2)) {
            count-=COUNTSETBIT(i);
        }
  //      cout<<"2: "<<count<<endl;
//        cout<<"3: from "<<(b1)<<" "<<(b2)<<endl;
        cout<<(count%1000007)<<endl;
    }
//	system("pause");
	return 0;
}












#include<iostream>
using namespace std;
long long val(long long N){
long long s=0;
if(N>=0){
int i=0;
while(N>>i!=0){
s=(s+((N&(1<<i))>0)*((N%(1<<i))+1)+((N>>(i+1))*(1<<i)))%1000007 ;
i++;
//cout<<N<<" "<<i<<" "<<s<<endl;
}
return s;
}
else{
N=-1-N;
int i=0;
while(N>>i!=0){
s=(s+((N&(1<<i))>0)*((N%(1<<i))+1)+((N>>(i+1))*(1<<i)))%1000007 ;
i++;//cout<<N<<" "<<i<<" "<<s<<endl;
}
s=(32*(N+1)-s)%1000007;
return s;
}
}

int main(){
long long n1,n2,s1,s2;
int t;
cin>>t;
while(t--){
cin>>n1>>n2;
if(n1>n2){
s1=n1;
n1=n2;
n2=s1;}
cout<<((((n1>0)?(-val(n1-1)):(val(n1)))+ ((n2>=0)?(val(n2)):(-val(n2+1))))%1000007+1000007)%1000007<<endl;
}
return 0;
}


















