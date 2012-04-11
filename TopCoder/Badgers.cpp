// BEGIN CUT HERE

// END CUT HERE
#line 5 "Badgers.cpp"
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
class Badgers
{
	public:
		int feedMost(vector <int> hunger, vector <int> greed, int totalFood)
		{
			int dp[55][55],len=SIZE(hunger);
			int i,j,k,p,q;
			MEM(dp,0);
			FOR(i,0,len)
			dp[i][0]=hunger[i];
			vector<int> v;
			FOR(i,0,len)
			v.push_back(hunger[i]);
			vector<int> vvv(ALL(v));
			sort(ALL(vvv));
            int a=0,ff=totalFood,count=0,max=0;
			FOR(i,0,len)
			{
				if(ff-vvv[i]>=0)
				{
					ff-=vvv[i];
					max++;
				}
				else break;
			}
			FOR(i,1,len)
			{
				count=0;
				FOR(j,0,len)
				{
					v[j]=v[j]+greed[j];
				}
				ff=totalFood;
				a=i+1;
				vector<int> vv(ALL(v));
				sort(ALL(vv));
				FOR(j,0,len)
				{
					if(!(a--)) break;
					if(ff-vv[j]>=0)
					{
						ff-=vv[j];
						count++;
					}
					else break;
				}
				if(count>max)
				{
					max=count;
				}
			}
			return max;
		}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1();  if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; int Arg3 = 2; verify_case(0, Arg3, feedMost(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {5,2,1,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,2,4,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 19; int Arg3 = 3; verify_case(1, Arg3, feedMost(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000,1000,1000,1000,1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; int Arg3 = 1; verify_case(2, Arg3, feedMost(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,9,8,7,6,5,4,3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = 5; verify_case(3, Arg3, feedMost(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	Badgers ___test;
	___test.run_test(-1);
	system("pause");
}
// END CUT HERE
