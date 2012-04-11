// BEGIN CUT HERE

// END CUT HERE
#line 5 "ImprovingStatistics.cpp"
#include <algorithm>
#include <iostream>
#include <iomanip>
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
class ImprovingStatistics
{
	public:
		int howManyGames(int played, int won)
		{
//            cout.setf(0,ios::floatfield);
  			cout.precision(3);
			double act=(double)won/played;
			if(act==1.00) return -1;
			double rem=act+0.01;
			cout<<rem<<" "<<act;
			int w=1;
			for(won++;;won++,w++)
			{
				double i=(double)won/(played+w);
				cout<<i<<" "<<w<<endl;
				if(i>act) return w;
			}
		}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 8; int Arg2 = 1; verify_case(0, Arg2, howManyGames(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 80; int Arg2 = 6; verify_case(1, Arg2, howManyGames(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 47; int Arg1 = 47; int Arg2 = -1; verify_case(2, Arg2, howManyGames(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 99000; int Arg1 = 0; int Arg2 = 1000; verify_case(3, Arg2, howManyGames(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000000000; int Arg1 = 470000000; int Arg2 = 19230770; verify_case(4, Arg2, howManyGames(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	ImprovingStatistics ___test;
	___test.run_test(-1);
	system("pause");
}
// END CUT HERE
