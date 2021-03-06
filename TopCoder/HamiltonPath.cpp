// BEGIN CUT HERE

// END CUT HERE
#line 5 "HamiltonPath.cpp"

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

bool vis[100];
int d[100];
vector <string> road;
int n;

class HamiltonPath
{
    void dfs(int now)
    {
        vis[now]=true;
        for (int i=0;i<n;i++)
            if ((road[now][i]=='Y')&&(!vis[i])) dfs(i);
    }

public:
    int countPaths(vector <string> roads)
    {
        road=roads;
        memset(vis,false,sizeof(vis));
        n=roads.size();
        for (int i=0;i<n;i++)
        {
            int s=0;
            for (int j=0;j<n;j++)
                if (roads[i][j]=='Y') s++;
            if (s>2) return 0;
            d[i]=s;
        }
        int tot1=0,tot2=0;
        for (int i=0;i<n;i++)
            if ((!vis[i])&&(d[i]<2))
            {
                dfs(i);
                if (d[i]==0) tot1++;
                    else tot2++;
            }
        for (int i=0;i<n;i++)
            if (!vis[i]) return 0;
        long long ans=1;
        for (long long i=0;i<tot1+tot2;i++) ans=(ans*(i+1)) % 1000000007;
        for (int i=0;i<tot2;i++)
            ans=(ans*2) % 1000000007;
        return ans;
    }
    


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN",
 "YNN",
 "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, countPaths(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYYY",
 "YNNN",
 "YNNN",
 "YNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, countPaths(Arg0)); }
	void test_case_2() { string Arr0[] = {"NYY",
 "YNY",
 "YYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, countPaths(Arg0)); }
	void test_case_3() { string Arr0[] = {"NNNNNY",
 "NNNNYN",
 "NNNNYN",
 "NNNNNN",
 "NYYNNN",
 "YNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(3, Arg1, countPaths(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
	HamiltonPath ___test;
	___test.run_test(-1);

	system("pause"); //Windows Only

	return 0;
}
// END CUT HERE
