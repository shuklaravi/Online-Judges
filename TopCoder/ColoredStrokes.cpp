// #define TRUE FALSE haha now debug this

// BEGIN CUT HERE

// END CUT HERE
#line 7 "ColoredStrokes.cpp"

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
#define REP(i,a) for((i)=0;(i)<(a);(i)++)
#define REP_(i,a) for((i)=0;(i)<=(a);(i)++)
#define FOR(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define MP(x,y) make_pair(x,y)


typedef pair<int,int>   PII;
//END_TEMPLATE_BY_PRATYUSH_VERMA

class ColoredStrokes
{
public:
vector<string> pic;
int H,W;

bool is_in(int a, int b)
{
    if(a<0 || a>=H || b<0 || b>=W) return false;
    return true;
}
void dfs(int I, int J, int x)
{
//    cout<<"in dfs with x="<<x<<" at "<<I<<" "<<J<<endl;
    stack<PII> s;
    s.push(MP(I,J));
    int i;
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
    while(!s.empty())
    {
        PII t=s.top();
        s.pop();
//        cout<<"popped "<<t.first<<" "<<t.second<<endl;
        if(x==0 && pic[t.first][t.second]=='G') pic[t.first][t.second]='R';
        if(x==2 && pic[t.first][t.second]=='G') pic[t.first][t.second]='B';
        if(x==0 && pic[t.first][t.second]=='B') pic[t.first][t.second]='.';
        if(x==2 && pic[t.first][t.second]=='R') pic[t.first][t.second]='.';
        FOR(i,x,x+2)
        {
            int xx=t.first+dx[i]; int yy=t.second+dy[i];
            if(!is_in(xx,yy)) continue;
            if(pic[xx][yy]=='.') continue;
            if(x==0 && pic[xx][yy]=='R') continue;
            if(x==2 && pic[xx][yy]=='B') continue;
            if(x==0 && pic[xx][yy]=='G') pic[xx][yy]='R';
            if(x==2 && pic[xx][yy]=='G') pic[xx][yy]='B';
            if(x==0 && pic[xx][yy]=='B') pic[xx][yy]='.';
            if(x==2 && pic[xx][yy]=='R') pic[xx][yy]='.';
//            cout<<"pushed -- state of "<<xx<<" "<<yy<<" "<<pic[xx][yy]<<" "<<endl;
            s.push(MP(xx,yy));
        }
//        getchar();
    }
}
int getLeast(vector <string> picture)
{
    pic=picture;
	int res=0;
    int i,j,k,p,q;
    H=pic.size();
    W=pic[0].size();
    REP(i,H)
    {
        REP(j,W)
        {
            if(pic[i][j]=='B' || pic[i][j]=='G')
            {
                dfs(i,j,0);
                res++;
            }
            if(pic[i][j]=='R' || pic[i][j]=='G')
            {
                dfs(i,j,2);
                res++;
            }
        }
    }
	return res;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, getLeast(Arg0)); }
	void test_case_1() { string Arr0[] = {"..B.",
 "..B."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getLeast(Arg0)); }
	void test_case_2() { string Arr0[] = {".BB."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, getLeast(Arg0)); }
	void test_case_3() { string Arr0[] = {"...B..",
 ".BRGRR",
 ".B.B.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, getLeast(Arg0)); }
	void test_case_4() { string Arr0[] = {"...B..",
 ".BRBRR",
 ".B.B.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, getLeast(Arg0)); }
	void test_case_5() { string Arr0[] = {"GR",
 "BG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(5, Arg1, getLeast(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
	ColoredStrokes ___test;
	___test.run_test(-1);

	system("pause"); //Windows Only

	return 0;
}
// END CUT HERE
