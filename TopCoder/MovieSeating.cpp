// BEGIN CUT HERE

// END CUT HERE
#line 5 "MovieSeating.cpp"

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

class MovieSeating
{
public:
    ll ff[9];
    int gcd(int a,int b) {
        if (b==0)
            return a;
        else return gcd(b,a%b);
    }
    void fact()
    {
        ff[0]=1;
        ff[1]=1;
        ff[2]=2;
        for(int i=3;i<9;i++)
        ff[i]=i*ff[i-1];
    }
long long getSeatings(int numFriends, vector <string> hall)
{
//    cout<<gcd(30,1)<<endl;
    int i,j,k,p,q;
	long long res=0;
	int n,r;
    ll arr[51][51];
    memset(arr,0,sizeof(arr));
	for (n=1;n<51;n++) {
        for (r=1;r<=n;r++) {
            if (n-r>0)
            if (arr[n][n-r]!=0) {
                arr[n][r]=arr[n][n-r];
                continue;
            }
            //cout<<n<<" "<<r<<endl;
            ll  num=1,deno=1;
            int k=n-r+1;
            int ir=1;
            for (;k<=n&&ir<=r;k++) {

                int g=gcd(k,ir);
                //cout<<k<<" "<<r<<" "<<g<<endl;
                int rum=k/g;
                int dum=ir/g;

                num*=rum;
                deno*=dum;
                if (num%deno==0) {
                    num/=deno;
                    deno=1;
                }
                ir++;
            }
            arr[n][r]=num/deno;
            //cout<<arr[n][r]<<endl;
            //getchar();
        }
    }
    
    MEM(ff,1);
    fact();
//    ll r=0;
    int I=hall[0].length();
    int J=hall.size();
    for(i=0;i<J;i++)
    {
        int c=0;
        for(j=0;j<I;j++)
        {
            if(hall[i][j]=='.') c++;
        }
        if(c>=numFriends) res+=(arr[c][numFriends]*ff[numFriends]);
//        cout<<"c = "<<c<<" numnF = "<<numFriends<<" res = "<<res<<endl;
    }
//    cout<<".......";
     for(i=0;i<I;i++)
    {
        int c=0;
        for(j=0;j<J;j++)
        {
            if(hall[j][i]=='.') c++;
        }
        if(c>=numFriends) res+=(arr[c][numFriends]*ff[numFriends]);
//        cout<<"c = "<<c<<" numnF = "<<numFriends<<" res = "<<res<<endl;
    }
    if(numFriends==1)
    res/=2;
    return res;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arr1[] = { "..",".."};
     vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 34LL; verify_case(0, Arg2, getSeatings(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = { "..#",
  ".##",
  "..." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 16LL; verify_case(1, Arg2, getSeatings(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; string Arr1[] = { "..####..", 
  ".###.##.",
  ".######.",
  "#.#.#.#." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(2, Arg2, getSeatings(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 8; string Arr1[] = { "........" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 40320LL; verify_case(3, Arg2, getSeatings(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
	MovieSeating ___test;
	___test.run_test(-1);

	system("pause"); //Windows Only

	return 0;
}
// END CUT HERE
