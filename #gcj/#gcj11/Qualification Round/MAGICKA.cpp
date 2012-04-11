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
int main()
{
    int test,ppp=1,i,j,k,p,q;
    cin>>test;
    while(test--)
    {
        string str,temp;
        int C,D,N;
        cin>>C;
        map<string,char> comb;
        map<char,char> opp;
        REP(i,C)
        {
            cin>>temp;
            string _temp=temp.substr(0,2);
            comb[_temp]=temp[2];
            swap(_temp[0],_temp[1]);
            comb[_temp]=temp[2];
        }
        //cout<<"conb:"<<comb.size()<<endl;
        cin>>D;
        REP(i,D)
        {
            cin>>temp;
            opp[temp[0]]=temp[1];
            opp[temp[1]]=temp[0];
        //    cout<<"! "<<temp[1]<<" "<<opp[temp[0]]<<endl;
        }
      //  cout<<"opp:"<<opp.size()<<endl;
        cin>>i;
        cin>>str;
        REP(i,str.length())
        {
            if(i==0) continue;
    //        cout<<"erasing "<<str[i]<<" "<<(opp.find(str[i])!=opp.end())<<(str.find(opp.find(str[i])->second)!=string::npos)<<endl;
            if(comb.find(str.substr(i-1,2))!=comb.end()) {
  //              cout<<"combinatoin foind "<<str.substr(i-1,2)<<" -> "<<comb[str.substr(i-1,2)]<<endl;
                string ss="";
                ss+=comb[str.substr(i-1,2)];
                str.replace(i-1,2,ss);//comb[str.substr(i-1,2)]);
                i--;
            }
            if(opp.find(str[i])!=opp.end() && str.find(opp[str[i]])!=string::npos && str.find(opp[str[i]])<i) {
//                cout<<"erasing "<<str[i]<<" "<<str.find(opp[str[i]])<<endl;
                str.erase(0,i+1);
                i=0;
            }
        }
        cout<<"Case #"<<ppp++<<": [";
        REP(i,str.length())
        {
            if(i==0) cout<<str[0];
            else cout<<", "<<str[i];
        }
        cout<<"]\n";
    }
//	system("pause");
	return 0;
}





























