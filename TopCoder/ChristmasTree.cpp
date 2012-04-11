// BEGIN CUT HERE

// END CUT HERE
#line 5 "ChristmasTree.cpp"

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
#define INF (1<<31)-1
#define REP(i,a) for((i)=0;(i)<(a);(i)++)
#define FOR(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define VAR(V,init) __typeof(init) V=(init)
#define FOREACH(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((int)(x.size()))
#define LENGTH(x) ((int)(x.length()))
#define SZ(x) sizeof(x)
#define MEM(m,i) memset((m),(i),SZ(m))
#define PB(x,y) (x).push_back(y)
#define MP(x,y) make_pair(x,y)
typedef long long ll;
inline string i2s(int number) { stringstream ss; ss << number; return ss.str(); }
//END_TEMPLATE_BY_PRATYUSH_VERMA

class ChristmasTree
{
public:
    long long arr[12];
    long long newton(int n, int k) {
    long long res = 1;

    for ( int i = 1; i <= k; i++ ) {
        res = ( res * (n - i + 1) ) / i;
    }

    return res;
    }
    int func(int N,int r, int g, int b, int l)
    {
        ll res;
        if(r<0 or g<0 or b<0) return 0;
        if(l==N) return 1;
        if(l%3==0)
        {
            res+=func(N,r-l/3,g-l/3,b-l/3,l+1)*newton(l,l/3)*newton(l-l/3,(l-l/3)/2);
        }
        if(l%2==0)
        {
            res+=func(N,r-l/2,g-l/2,b,l+1)*newton(l,l/2);
            res+=func(N,r,g-l/2,b-l/2,l+1)*newton(l,l/2);
            res+=func(N,r-l/2,g,b-l/2,l+1)*newton(l,l/2);
        }
        res+=func(N,r-l,g,b,l+1);
        res+=func(N,r,g-l,b,l+1);
        res+=func(N,r-l,g,b-l,l+1);
        return res;
    }
long long decorationWays(int N, int red, int green, int blue)
{
	return func(N+1,red,green,blue,1);
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; long long Arg4 = 6LL; verify_case(0, Arg4, decorationWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 0; long long Arg4 = 3LL; verify_case(1, Arg4, decorationWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 2; int Arg3 = 1; long long Arg4 = 0LL; verify_case(2, Arg4, decorationWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; long long Arg4 = 36LL; verify_case(3, Arg4, decorationWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 8; int Arg1 = 1; int Arg2 = 15; int Arg3 = 20; long long Arg4 = 197121LL; verify_case(4, Arg4, decorationWays(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
	ChristmasTree ___test;
	___test.run_test(-1);

	system("pause"); //Windows Only

	return 0;
}
// END CUT HERE
