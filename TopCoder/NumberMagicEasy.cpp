// BEGIN CUT HERE

// END CUT HERE
#line 5 "NumberMagicEasy.cpp"

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

class NumberMagicEasy
{
public:
int theNumber(string answer)
{
	int i,j;
	vector<int> c[4];
	set<int> res;
	PB(c[0],1);PB(c[0],2);PB(c[0],3);PB(c[0],4);PB(c[0],5);PB(c[0],6);PB(c[0],7);PB(c[0],8);
	PB(c[1],1);PB(c[1],2);PB(c[1],3);PB(c[1],4);PB(c[1],9);PB(c[1],10);PB(c[1],11);PB(c[1],12);
	PB(c[2],1);PB(c[2],2);PB(c[2],5);PB(c[2],6);PB(c[2],9);PB(c[2],10);PB(c[2],13);PB(c[2],14);
	PB(c[3],1);PB(c[3],3);PB(c[3],5);PB(c[3],7);PB(c[3],9);PB(c[3],11);PB(c[3],13);PB(c[3],15);
	set<int>::iterator it;
	REP(i,4)
	{
        if(answer[i]=='Y')
        {
            REP(j,4)
            res.insert(c[i][j]);
            break;
        }
    }
    for ( it=res.begin() ; it != res.end(); it++ )
    cout << " " << *it;
    cout<<endl;
    REP(i,4)
    if(answer[i]=='N')
    {
        REP(j,4)
        res.erase(c[i][j]);
    }
	return *res.begin();
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "YNYY"; int Arg1 = 5; verify_case(0, Arg1, theNumber(Arg0)); }
	void test_case_1() { string Arg0 = "YNNN"; int Arg1 = 8; verify_case(1, Arg1, theNumber(Arg0)); }
	void test_case_2() { string Arg0 = "NNNN"; int Arg1 = 16; verify_case(2, Arg1, theNumber(Arg0)); }
	void test_case_3() { string Arg0 = "YYYY"; int Arg1 = 1; verify_case(3, Arg1, theNumber(Arg0)); }
	void test_case_4() { string Arg0 = "NYNY"; int Arg1 = 11; verify_case(4, Arg1, theNumber(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
	NumberMagicEasy ___test;
	___test.run_test(-1);

	system("pause"); //Windows Only

	return 0;
}
// END CUT HERE
