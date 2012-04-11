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
int arg(int a, int b)
{
    return a-b>0?a-b:b-a;
}
int main()
{
    int i,j,k,p,q,n,nn;
    char ch;
    int test;
    cin>>test;
    string s;
    int currB,currO;
    int res=0;
    int ppp=1;
    while(test--)
    {
        currO=1;currB=1;
        int idxO,idxB;
        idxO=idxB=0;
        cin>>n;
        nn=n;
        vector<int> b,o,ord;
        while(nn--)
        {
            cin>>ch;
            cin>>i;
            PB(ord,!!(ch=='B'));
            if(ch=='B') { PB(b,i); }
            else { PB(o,i); }
        }
//        print(ord);
        res=0;
        //cout<<"sizes : "<<o.size()<<" "<<b.size()<<endl;
        i=0;
        while(idxB!=b.size() && idxO!=o.size())
        {
            if(ord[i]==1) {
      //          cout<<"orig : "<<currO<<" "<<currB<<endl;
              int temp=arg(b[idxB],currB)+1;
              res+=temp;
              currB=b[idxB];
              int temp1=arg(o[idxO],currO);
              if(temp1<=temp) {
                  currO=o[idxO];
              }
              else {
                  if(o[idxO]>currO) currO+=temp;
                  else currO-=temp;
              }
              idxB++;
    //          cout<<"position : "<<currO<<" "<<currB<<" res = "<<res<<" with "<<temp<<" "<<temp1<<endl;
            }
            if(ord[i]==0) {
  //              cout<<"!orig : "<<currO<<" "<<currB<<endl;
              int temp=arg(o[idxO],currO)+1;
              res+=temp;
              currO=o[idxO];
              int temp1=arg(b[idxB],currB);
              if(temp1<=temp) {
                  currB=b[idxB];
              }
              else {
                  if(b[idxB]>currB) currB+=temp;
                  else currB-=temp;
              }
              idxO++;
//              cout<<"position : "<<currO<<" "<<currB<<" res = "<<res<<" with "<<temp<<" "<<temp1<<endl;
            }

            i++;
        }
      //  cout<<"out\n";
    //    cout<<"position : "<<currO<<" "<<currB<<" res = "<<res<<" index : "<<idxO<<" "<<idxB<<endl;
        if(idxB==b.size()) {
  //          cout<<"in O \n";
            res+=(o.size()-idxO);
            while(idxO<o.size()) {
                res+=arg(currO,o[idxO]);
                currO=o[idxO];
                idxO++;
            }
        }
        if(idxO==o.size()) {
//            cout<<"in B\n";
            res+=(b.size()-idxB);
            while(idxB<b.size()) {
                res+=arg(currB,b[idxB]);
                currB=b[idxB];
                idxB++;
            }
        }
        cout<<"Case #"<<ppp++<<": "<<res<<endl;
    }
//	system("pause");
	return 0;
}




























