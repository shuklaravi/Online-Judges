// #define TRUE FALSE haha now debug this

// BEGIN CUT HERE

// END CUT HERE
#line 7 "TxMsg.cpp"

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

//CONSTANT
#define INF (1<<31)-1
#define PI 3.1428571428571428571428571428571

//FUNC
#define MAX(i,j) (i)>(j)?(i):(j)
#define MIN(i,j) (i)<(j)?(i):(j)
#define REP(i,a) for((i)=0;(i)<(a);(i)++)
#define REP_(i,a) for((i)=0;(i)<=(a);(i)++)
#define FOR(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define FOR_(i,a,b) for((i)=(a);(i)<=(b);(i)++)
#define VAR(V,init) __typeof(init) V=(init)
#define FOREACH(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((int)(x.size()))
#define LENGTH(x) ((int)(x.length()))
#define SZ(x) sizeof(x)
#define MEM(m,i) memset((m),(i),SZ(m))
#define PB(x,y) (x).push_back(y)
#define MP(x,y) make_pair(x,y)
#define V(x) vector < x >

//BITWISE
#define LASTSETBIT(x) x & ~(x-1)
#define TRAILZERO(x) __builtin_ctz(x)
#define LEADZERO(x) __builtin_clz(x)
#define COUNTSETBIT(x) __builtin_popcount(x)
#define GCD(x,y) __gcd(x,y)

typedef pair<int,int>   PII;
typedef pair<char,int>  PCI;
typedef pair<int,PII>   TRI;
typedef V( int )        VI;
typedef V( PII )        VII;
typedef V( TRI )        VTRI;
typedef V( string )     VS;
typedef long long       LL;
typedef long double     LD;

template<class T> void print(const vector<T> &v){ostringstream os; for(int i=0; i<v.size(); ++i){if(i)os<<' ';os<<v[i];} cout<<os.str()<<endl;}
template<class T, class U> T cast (U x) { ostringstream os; os<<x; T res; istringstream is(os.str()); is>>res; return res; }
template<class T> vector<T> split(string s, string x=" ") {vector<T> res; for(int i=0;i<s.size();i++){string a; while(i<(int)s.size()&&x.find(s[i])==string::npos)a+=s[i++]; if(!a.empty())res.push_back(cast<T>(a));} return res;}

inline void input( int &n ) { n=0; int ch=getchar(); while( ch < '0' || ch > '9' ) ch=getchar(); while( ch >= '0' && ch <= '9' ) n = (n<<3)+(n<<1) + ch-'0', ch=getchar(); }

//END_TEMPLATE_BY_PRATYUSH_VERMA

class TxMsg
{
public:
string getMessage(string o)
{
	string res="",temp;
	int i,j,k,p,q,len=o.length();
	stringstream ss(o);

	while(ss>>temp)
	{
        len=temp.length();
	   for(i=0;i<len;i++)
	   {
            if(!(temp[i]=='a' || temp[i]=='i' || temp[i]=='e' || temp[i]=='o' || temp[i]=='u')) break;
        }
        if(i==len)
        {
            res+=temp;
        }
        else
        {
            for(i=0;i<len;)
            {
                if((temp[i]=='a' || temp[i]=='i' ||  temp[i]=='e' || temp[i]=='o' || temp[i]=='u'))
                {
                    i++;
                }
                else
                {
                    char c=temp[i];
                    res+=c;
                    i++;
                    while(!(temp[i]=='a' ||  temp[i]=='i' || temp[i]=='e' || temp[i]=='o' || temp[i]=='u') && i<len) i++;
                }
            }
        }
        res+=" ";
    }
    cout<<res<<".";
    string ret;
    if(res.length()>1)
    ret=res.substr(0,res.length()-1);
    else ret=res;
    cout<<ret<<"."<<endl;
	return ret;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "fuxcoqiunw dveqozowaa cepemapooxw eypuljifek"; string Arg1 = "tx msg"; verify_case(0, Arg1, getMessage(Arg0)); }
	void test_case_1() { string Arg0 = "ps i love u"; string Arg1 = "p i lv u"; verify_case(1, Arg1, getMessage(Arg0)); }
	void test_case_2() { string Arg0 = "please please me"; string Arg1 = "ps ps m"; verify_case(2, Arg1, getMessage(Arg0)); }
	void test_case_3() { string Arg0 = "back to the ussr"; string Arg1 = "bc t t s"; verify_case(3, Arg1, getMessage(Arg0)); }
	void test_case_4() { string Arg0 = "aeiou bcdfghjklmnpqrstvwxyz"; string Arg1 = "aeiou b"; verify_case(4, Arg1, getMessage(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
	TxMsg ___test;
	___test.run_test(-1);

	system("pause"); //Windows Only

	return 0;
}
// END CUT HERE
