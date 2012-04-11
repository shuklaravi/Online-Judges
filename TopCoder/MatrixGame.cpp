// #define TRUE FALSE haha now debug this

// BEGIN CUT HERE

// END CUT HERE
#line 7 "MatrixGame.cpp"

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

class MatrixGame
{
public:
vector <string> getMinimal(vector <string> matrix)
{
	vector <string> res;
	int m=matrix.size(),n=matrix[0].size(),i,j,k,p,q;
    string str;
    {
        int arr[m][n];
        vector<string> h,v;
        REP(i,n)
        PB(v,"");
        REP(i,m)
        {
            str=matrix[i];
            PB(h,str);
            REP(j,n)
            {
                    v[j]+=str[j];
            }
        }
        int no=100;
        while(no--)
        {
                sort(ALL(h));
         //      cout<<"sorted h to \n";
           //     print(h);
                REP(i,m)
                {
                    REP(j,n)
                    {
                        arr[i][j]=(h[i][j]-'0');
                    }
                }/*
                REP(i,m)
                {
                    REP(j,n)
                    cout<<arr[i][j];
                    cout<<endl;
                }*/
                v.clear();
                REP(i,n)
                PB(v,"");
                REP(i,m)
                {
                    REP(j,n)
                    {
                        if(arr[i][j]==1)
                        v[j]+="1";
                        else
                        v[j]+="0";
                    }
                }

                sort(ALL(v));
//                cout<<"sorted v to \n";

                REP(i,n)
                {
                    REP(j,m)
                    {
                        arr[j][i]=v[i][j]-'0';
                    }
                }
/*                REP(i,m)
                {
                    REP(j,n)
                    cout<<arr[i][j];
                    cout<<endl;
                }
*/
                h.clear();
                REP(i,m)
                PB(h,"");
                REP(i,m)
                {
                    REP(j,n)
                    {
                        if(arr[i][j]==1)
                        h[i]+="1";
                        else
                        h[i]+="0";
                    }
                }
//                cout<<".......\n";
        }
        REP(i,m)
        {
            PB(res,"");
            REP(j,n)
            {
                if(arr[i][j]==1) res[i]+="1";
                else res[i]+="0";
            }
        }
    }
	return res;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"000",
 "000",
 "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"000", "000", "000" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getMinimal(Arg0)); }
	void test_case_1() { string Arr0[] = {"010",
 "000",
 "110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"000", "001", "011" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getMinimal(Arg0)); }
	void test_case_2() { string Arr0[] = {"111",
 "111",
 "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"111", "111", "111" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getMinimal(Arg0)); }
	void test_case_3() { string Arr0[] = {"01010",
 "10101",
 "01010",
 "10101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00011", "00011", "11100", "11100" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getMinimal(Arg0)); }
	void test_case_4() { string Arr0[] = {"11010100",
 "11110001",
 "00011101",
 "11111111",
 "01110100",
 "10000110",
 "00001001",
 "11010111"};vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00000011", "00001111", "00110100", "01011100", "01111101", "11001100", "11011001", "11111111" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getMinimal(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
	MatrixGame ___test;
	___test.run_test(-1);

	system("pause"); //Windows Only

	return 0;
}
// END CUT HERE
