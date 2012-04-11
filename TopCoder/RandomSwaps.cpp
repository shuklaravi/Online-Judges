// BEGIN CUT HERE

// END CUT HERE
#line 5 "RandomSwaps.cpp"
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
class RandomSwaps
{
	public:
		double getProbability(int n, int swapCount, int a, int b)
		{
			int total=n*(n-1)/2;
			double p=0;
			p=(double)1/total;
            cout<<total<<" "<<p<<" "<<(max(a-1,n-a-1));
			if(a!=b && swapCount==1)
			return p;
			if(a==b && swapCount==1)
			return (double)(total-((max(a-1,n-a-1))))/total;
			swapCount--;
			bool corr=false;
			if(a==b)
			p+=(pow((double)(total-((max(a-1,n-a-1))))/total,swapCount));
			cout<<(double)(total-((max(a-1,n-a-1))))/total<<"......\n";
			while(swapCount--)
			{
				if(swapCount==0)
				{
					p+=(double)1/total;
//					cout<<p;
				}
				else
				{
					p+=((double) (max(a-1,n-a-1))/total);
//					cout<<p<<endl;
				}
			}
			return p;
		}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 0; int Arg3 = 0; double Arg4 = 0.6; verify_case(0, Arg4, getProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 0; int Arg3 = 3; double Arg4 = 0.1; verify_case(1, Arg4, getProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 0; int Arg3 = 0; double Arg4 = 0.4; verify_case(2, Arg4, getProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 500; int Arg2 = 3; int Arg3 = 3; double Arg4 = 0.010036635745123007; verify_case(3, Arg4, getProbability(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	RandomSwaps ___test;
	___test.run_test(-1);
	system("pause");
}
// END CUT HERE
