// BEGIN CUT HERE

// END CUT HERE
#line 5 "LockersDivTwo.cpp"

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

class LockersDivTwo
{
public:
int lastOpened(int N)
{
	int res;
	int i,j,k,p,q;
	bool arr[N+1];
	MEM(arr,false);
	int last=-1;
/*	for(i=1;i<N+1;i++)
	{
        for(jk
    }
*/
    int count=0,rem;
	FOR(i,1,N+1)
	{
        for(k=1;k<=N;k++)
        {
            if(!arr[k])
            {
                arr[k]=true;
                last=k;
//                cout<<"opened "<<k<<endl;
//                system("pause");
                count++;
                break;
            }
        }
        if(k==N)
        break;
        rem=i+1;
        for(p=k+1;p<=N;p++)
        {
            if(!arr[p])
            {
                 rem--;
                 if(rem==0)
                 {
                     last=p;
                     arr[p]=true;
//                     cout<<".......opened "<<p<<endl;
//                     system("pause");
                     count++;
                     rem=i+1;
                 }
            }
        }
    }
	return last;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 9; int Arg1 = 6; verify_case(0, Arg1, lastOpened(Arg0)); }
	void test_case_1() { int Arg0 = 42; int Arg1 = 42; verify_case(1, Arg1, lastOpened(Arg0)); }
	void test_case_2() { int Arg0 = 314; int Arg1 = 282; verify_case(2, Arg1, lastOpened(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
	LockersDivTwo ___test;
	___test.run_test(-1);

	system("pause"); //Windows Only

	return 0;
}
// END CUT HERE
