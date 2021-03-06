// BEGIN CUT HERE

// END CUT HERE
#line 5 "DigitHoles.cpp"

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

class DigitHoles
{
public:
int numHoles(int number)
{
	int res=0;
    while(number>0)
    {
        int t=number%10;
        number/=10;
        if(t==8)res+=2;
        else if(t==4||t==6||t==9||t==0) res++;
    }
	return res;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 42; int Arg1 = 1; verify_case(0, Arg1, numHoles(Arg0)); }
	void test_case_1() { int Arg0 = 669; int Arg1 = 3; verify_case(1, Arg1, numHoles(Arg0)); }
	void test_case_2() { int Arg0 = 688; int Arg1 = 5; verify_case(2, Arg1, numHoles(Arg0)); }
	void test_case_3() { int Arg0 = 123; int Arg1 = 0; verify_case(3, Arg1, numHoles(Arg0)); }
	void test_case_4() { int Arg0 = 456; int Arg1 = 2; verify_case(4, Arg1, numHoles(Arg0)); }
	void test_case_5() { int Arg0 = 789; int Arg1 = 3; verify_case(5, Arg1, numHoles(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
	DigitHoles ___test;
	___test.run_test(-1);

	system("pause"); //Windows Only

	return 0;
}
// END CUT HERE
