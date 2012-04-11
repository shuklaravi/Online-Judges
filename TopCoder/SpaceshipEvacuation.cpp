// BEGIN CUT HERE

// END CUT HERE
#line 5 "SpaceshipEvacuation.cpp"
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
//END_TEMPLATE_BY_PRATYUSH_VERMA
using namespace std;
class SpaceshipEvacuation
{
	public:
		int additionalCabins(int N, vector <string> tunnelNetwork, int crewSize)
		{
			
		}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"0 1 5 3",
 "2 1 0 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 7; verify_case(0, Arg3, additionalCabins(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; string Arr1[] = {"0 1 0 2",
 "0 2 0 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 4; verify_case(1, Arg3, additionalCabins(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; string Arr1[] = {"0 1 0 6",
 "3 2 3 1",
 "2 1 0 1",
 "3 1 2 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = 6; verify_case(2, Arg3, additionalCabins(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10; string Arr1[] = {"0 1 11 101",
 "1 2 0 100",
 "2 3 20 100",
 "3 4 0 107",
 "4 1 66 0",
 "3 5 104 2",
 "4 6 82 0",
 "5 7 25 25",
 "7 8 14 42",
 "8 9 0 94",
 "9 5 17 92"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 110; int Arg3 = 376; verify_case(3, Arg3, additionalCabins(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 3; string Arr1[] = {"0 1 0 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = -1; verify_case(4, Arg3, additionalCabins(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	SpaceshipEvacuation ___test;
	___test.run_test(-1);
	system("pause");
}
// END CUT HERE
