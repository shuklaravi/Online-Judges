// #define TRUE FALSE haha now debug this

// BEGIN CUT HERE

// END CUT HERE
#line 7 "SellingProducts.cpp"

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

class SellingProducts
{
public:
int optimalPrice(vector <int> price, vector <int> cost)
{
	int res;
	int i,j,k,p=0,q,max=1;
	vector<PII> v;
	REP(i,price.size())
	{
        PB(v,MP(price[i],cost[i]));
    }
    sort(ALL(v));
    reverse(ALL(v));
    REP(i,price.size())
    cout<<v[i].first<<" "<<v[i].second<<endl;
    REP(i,price.size())
    {
        int temp=0;
        REP(j,price.size())
        {
//            if(i==j) temp+=(-cost[i]);
            if((v[i].first-v[j].second)>0 && v[i].first<=v[j].first)
            {
                temp+=(v[i].first-v[j].second);
            }
        }
        cout<<"for cost "<<v[i].first<<" profit = "<<temp<<endl;
        if(temp>=max)
        {
            max=temp;
            p=v[i].first;
        }
    }
	return p;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {13,22,35}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 22; verify_case(0, Arg2, optimalPrice(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {13,22,35}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,15,30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 13; verify_case(1, Arg2, optimalPrice(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {13,22,35}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {15,30,40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, optimalPrice(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {10,10,20,20,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,5,11,15,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(3, Arg2, optimalPrice(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {13,17,14,30,19,17,55,16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {12,1,5,10,3,2,40,19}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 17; verify_case(4, Arg2, optimalPrice(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
	SellingProducts ___test;
	___test.run_test(-1);

	system("pause"); //Windows Only

	return 0;
}
// END CUT HERE
