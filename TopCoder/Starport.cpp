// #define TRUE FALSE haha now debug this

// BEGIN CUT HERE

// END CUT HERE
#line 7 "Starport.cpp"

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

class Starport
{
public:
double getExpectedTime(int N, int M)
{
	long long double res=0;
	long long double gcd=__gcd(N,M);
	gcd=(N*M)/gcd;
//	gcd*=M;
	cout<<"gcd = "<<gcd<<endl;
    long long double i,j,k=0,p=1,q=1;
    REP(i,gcd)
    {
        long long double w=M*q;
        w/=N;
        w++;
        if(M*q>gcd) break;
        res+=(w*N-M*q);
        cout<<"res inc by  "<<(M*q-w*N)<<endl;
        cout<<" * arrived at "<<M*q<<" & sweep at "<<N*w<<endl;
        q++;
//        if(M*q>N*w) p++;
        k++;
        cout<<"q = "<<q<<" w = "<<w<<" k = "<<k<<endl;
//        getchar();
    }
//    if(res==35723726445.0) cout<<"same\n";
    cout<<"res = "<<res<<endl;
//    cout<<(double) 35723726445.0<<endl;
    cout<<"q = "<<q<<" p = "<<p<<" k = "<<k<<endl;
    //res/=k;
	return res/(double)(k);
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 5; double Arg2 = 1.0; verify_case(0, Arg2, getExpectedTime(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 3; double Arg2 = 2.0; verify_case(1, Arg2, getExpectedTime(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 1; double Arg2 = 2.5; verify_case(2, Arg2, getExpectedTime(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 12345; int Arg1 = 2345; double Arg2 = 6170.0; verify_case(3, Arg2, getExpectedTime(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
	Starport ___test;
	___test.run_test(1);

	system("pause"); //Windows Only

	return 0;
}
// END CUT HERE
