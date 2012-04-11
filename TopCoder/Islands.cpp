// BEGIN CUT HERE

// END CUT HERE
#line 5 "Islands.cpp"
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
struct node{
	int x,y;
	node (int a,int b)
	{
		x=a;
		y=b;
	}
};
class Islands
{
	public:
		int beachLength(vector <string> k)
		{
			int b=0;
			int i,j,p,q;
			int X=k.size();
			int Y=k[0].length();
			FOR(i,0,X-1)
			{
				FOR(j,0,Y+(i%2)-1)
				{
					if(k[i][j]!=k[i][j+1]) {cout<<"1.."<<b<<" "<<i<<" "<<j<<endl;b++;}
					if(!i%2)
					{
						if((i!=0 || j!=0) && k[i][j]!=k[i+1][j-1]) {cout<<"2.."<<b<<" "<<i<<" "<<j<<endl;b++;}
						if(k[i][j]!=k[i+1][j]) {cout<<"3.."<<b<<" "<<i<<" "<<j<<endl;b++;}
					}
					else
					{
						if((i+1!=X || j+1!=Y) && k[i][j]!=k[i+1][j+1]) {cout<<"4.."<<b<<" "<<i<<" "<<j<<endl;b++;}
						if(k[i][j]!=k[i+1][j]) {cout<<"5.."<<b<<" "<<i<<" "<<j<<endl;b++;}
					}
				}
			}
			FOR(j,0,Y+((X-1)%2)-1)
			if(k[i][j]!=k[i][j+1]) b++;
			return b;
		}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".#...#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, beachLength(Arg0)); }
	void test_case_1() { string Arr0[] = {"..#.##", 
 ".##.#.", 
 "#.#..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(1, Arg1, beachLength(Arg0)); }
	void test_case_2() { string Arr0[] = {"#...#.....",
 "##..#...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(2, Arg1, beachLength(Arg0)); }
	void test_case_3() { string Arr0[] = {"....#.",
 ".#....",
 "..#..#",
 "####.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(3, Arg1, beachLength(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	Islands ___test;
	___test.run_test(-1);
	system("pause");
}
// END CUT HERE
