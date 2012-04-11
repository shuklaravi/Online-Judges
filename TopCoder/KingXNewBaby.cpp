// BEGIN CUT HERE

// END CUT HERE
#line 5 "KingXNewBaby.cpp"

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

#define INF (1<<31)-1
#define PI 3.1428571428571428571428571428571

#define MAX(i,j) (i)>(j)?(i):(j)
#define MIN(i,j) (i)<(j)?(i):(j)
#define REP(i,a) for((i)=0;(i)<(a);(i)++)

class KingXNewBaby
{
public:
string isValid(string name)
{
	string res;
    char vowel[]={'a','e','i','o','u'};
    int i,j,k,p,q;
    p=0;
    REP(i,name.length())
    {
        REP(j,5)
        {
            if(name[i]==vowel[j])
            p++;
        }
    }
    if(p!=2) return "NO";
    REP(i,name.length())
    {
        REP(j,5)
        {
            if(name[i]==vowel[j])
            break;
        }
        if(j!=5) break;
    }
    for(j=i+1;j<name.length();j++) if(name[j]==name[i]) break;
    if(j==name.length()) return "NO";
	return "YES";
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "dengklek"; string Arg1 = "YES"; verify_case(0, Arg1, isValid(Arg0)); }
	void test_case_1() { string Arg0 = "gofushar"; string Arg1 = "NO"; verify_case(1, Arg1, isValid(Arg0)); }
	void test_case_2() { string Arg0 = "dolphinigle"; string Arg1 = "NO"; verify_case(2, Arg1, isValid(Arg0)); }
	void test_case_3() { string Arg0 = "mystictc"; string Arg1 = "NO"; verify_case(3, Arg1, isValid(Arg0)); }
	void test_case_4() { string Arg0 = "rngringo"; string Arg1 = "NO"; verify_case(4, Arg1, isValid(Arg0)); }
	void test_case_5() { string Arg0 = "misof"; string Arg1 = "NO"; verify_case(5, Arg1, isValid(Arg0)); }
	void test_case_6() { string Arg0 = "metelsky"; string Arg1 = "YES"; verify_case(6, Arg1, isValid(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
	KingXNewBaby ___test;
	___test.run_test(-1);

	system("pause"); //Windows Only

	return 0;
}
// END CUT HERE
