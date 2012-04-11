// BEGIN CUT HERE

// END CUT HERE
#line 5 "FactoryCounting.cpp"

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
#include <bitset>
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

//BITWISE
#define LASTSETBIT(x) x & ~(x-1)
#define TRAILZERO(x) __builtin_ctz(x)
#define LEADZERO(x) __builtin_clz(x)
#define COUNTSETBIT(x) __builtin_popcount(x)


class FactoryCounting
{
public:
long long count(int n, int m, vector <string> county)
{
	long long res=0;
    int num=0;
    bitset<30> b(0);
    int c[county.size()];
    REP(i,county.size())
    {
        REP(j,county[0].length())
        {
            if[county[i][j]=='Y') county[i][j]=1;
            else county[i][j]=0;
        }
        bitset<30> temp(county[i]);
        c[i]=temp.to_ulong();
    }

    int mx=0;
    REP(i,county.size())
    {
        mx|=max;
        mx<<=1;
    }
    REP(i,mx+1)
    {
        bitset<30> temp(i);
        REP(j,county.size())
        {
            if(COUNTSETBIT(i)<n+m) continue;
            temp=i&c[i];
            if(COUNTSETBIT(temp)==k)
            {

            }
            if(i&c[j]==i) res++;
        }
    }
    
    
	return res;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; string Arr2[] = {
 "NYY",
 "YNY",
 "YYN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 3LL; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; string Arr2[] = {
 "NYYYYN",
 "YNYYNY",
 "YYNYYY",
 "YYYNYN",
 "YNYYNY",
 "NYYNYN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 32LL; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; string Arr2[] = {
 "NNNNYN",
 "NNNYNN",
 "NNNNYN",
 "NYNNYN",
 "YNYYNN",
 "NNNNNN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 8LL; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {
 "NYYYNYYNYY",
 "YNYYYYYYYN",
 "YYNYYYNYYN",
 "YYYNYYNYNY",
 "NYYYNYYYYY",
 "YYYYYNYYNY",
 "YYNNYYNYYN",
 "NYYYYYYNNY",
 "YYYNYNYNNY",
 "YNNYYYNYYN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 308LL; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 7; int Arg1 = 8; string Arr2[] = {
 "NYYYYYNYYYYYNYYYYYYYYYYNYYYYYY",
 "YNYYYYYYYYYYYYYYYNYYYYYYYYYYYY",
 "YYNYYYYYYYYYYYYNYNYYYNNYYYNYYY",
 "YYYNYYYYYYYYNYYYYYNYYYYYYNYYYY",
 "YYYYNYYYYYYYYYNYYYYYYYYYYYNYYY",
 "YYYYYNYYNYYYYNYYYYYNYYYYYYYNNY",
 "NYYYYYNYYYYYYYYYNYYYYNYYYYYYYY",
 "YYYYYYYNYYYYYYYYYYYYYYYYYYYYYY",
 "YYYYYNYYNYYYYNNYYYYYYYYNYYNNYY",
 "YYYYYYYYYNYYNYYNYNYYNYYYYYYYYY",
 "YYYYYYYYYYNYYNYYYYYYYNYYYYYYYY",
 "YYYYYYYYYYYNYYYYNYYYYYYYYYYYYY",
 "NYYNYYYYYNYYNYYYNYNYYYYYNYYYYY",
 "YYYYYNYYNYNYYNYYYYYYYYYYYNYYNY",
 "YYYYNYYYNYYYYYNNNYYYYYYYYYYYYY",
 "YYNYYYYYYNYYYYNNYNYYYYYNNYYYNY",
 "YYYYYYNYYYYNNYNYNNYYNYYYYYNYNY",
 "YNNYYYYYYNYYYYYNNNYYNYYYYYYYYY",
 "YYYNYYYYYYYYNYYYYYNNYYNYYYYYYY",
 "YYYYYNYYYYYYYYYYYYNNYYYYYYYYYY",
 "YYYYYYYYYNYYYYYYNNYYNYYYYYNYYY",
 "YYNYYYNYYYNYYYYYYYYYYNYYYYYYYY",
 "YYNYYYYYYYYYYYYYYYNYYYNYYYYYYY",
 "NYYYYYYYNYYYYYYNYYYYYYYNYYYYYY",
 "YYYYYYYYYYYYNYYNYYYYYYYYNYYYYY",
 "YYYNYYYYYYYYYNYYYYYYYYYYYNYYYY",
 "YYNYNYYYNYYYYYYYNYYYNYYYYYNYYY",
 "YYYYYNYYNYYYYYYYYYYYYYYYYYYNYY",
 "YYYYYNYYYYYYYNYNNYYYYYYYYYYYNN",
 "YYYYYYYYYYYYYYYYYYYYYYYYYYYYNN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 522891760LL; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 8; int Arg1 = 8; string Arr2[] = {
 "NYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
 "YNYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
 "YYNYYYYYYYYYYYYYYYYYYYYYYYYYYY",
 "YYYNYYYYYYYYYYYYYYYYYYYYYYYYYY",
 "YYYYNYYYYYYYYYYYYYYYYYYYYYYYYY",
 "YYYYYNYYYYYYYYYYYYYYYYYYYYYYYY",
 "YYYYYYNYYYYYYYYYYYYYYYYYYYYYYY",
 "YYYYYYYNYYYYYYYYYYYYYYYYYYYYYY",
 "YYYYYYYYNYYYYYYYYYYYYYYYYYYYYY",
 "YYYYYYYYYNYYYYYYYYYYYYYYYYYYYY",
 "YYYYYYYYYYNYYYYYYYYYYYYYYYYYYY",
 "YYYYYYYYYYYNYYYYYYYYYYYYYYYYYY",
 "YYYYYYYYYYYYNYYYYYYYYYYYYYYYYY",
 "YYYYYYYYYYYYYNYYYYYYYYYYYYYYYY",
 "YYYYYYYYYYYYYYNYYYYYYYYYYYYYYY",
 "YYYYYYYYYYYYYYYNYYYYYYYYYYYYYY",
 "YYYYYYYYYYYYYYYYNYYYYYYYYYYYYY",
 "YYYYYYYYYYYYYYYYYNYYYYYYYYYYYY",
 "YYYYYYYYYYYYYYYYYYNYYYYYYYYYYY",
 "YYYYYYYYYYYYYYYYYYYNYYYYYYYYYY",
 "YYYYYYYYYYYYYYYYYYYYNYYYYYYYYY",
 "YYYYYYYYYYYYYYYYYYYYYNYYYYYYYY",
 "YYYYYYYYYYYYYYYYYYYYYYNYYYYYYY",
 "YYYYYYYYYYYYYYYYYYYYYYYNYYYYYY",
 "YYYYYYYYYYYYYYYYYYYYYYYYNYYYYY",
 "YYYYYYYYYYYYYYYYYYYYYYYYYNYYYY",
 "YYYYYYYYYYYYYYYYYYYYYYYYYYNYYY",
 "YYYYYYYYYYYYYYYYYYYYYYYYYYYNYY",
 "YYYYYYYYYYYYYYYYYYYYYYYYYYYYNY",
 "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 1871589827250LL; verify_case(5, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
	FactoryCounting ___test;
	___test.run_test(-1);

	system("pause"); //Windows Only

	return 0;
}
// END CUT HERE

