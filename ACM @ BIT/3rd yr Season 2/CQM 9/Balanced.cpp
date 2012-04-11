

// #define TRUE FALSE haha now debug this
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
map<string, int> m;
int arr[105][105];

bool check(string s) {
    stack<char> ss;
    int i;
    ss.push(s[0]);
    FOR(i,1,s.length()) {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') ss.push(s[i]);
        else if(ss.size()!=0 && ss.top()=='(' && s[i]==')') ss.pop();
        else if(ss.size()!=0 && ss.top()=='{' && s[i]=='}') ss.pop();
        else if(ss.size()!=0 &&ss.top()=='[' && s[i]==']') ss.pop();
        else {return false; }
    }
    if(ss.size()==0) return true;
    return false;


}

int mini (string s) {
   // cout<<s<<endl;
   if(m.find(s)!=m.end())
   {
       return m[s];
   }

    if (check(s))
        return 0;
        int cost = 0,mincost =INF;
          //  getchar();
        if (s.length() > 2) {
            int i,j;
            for(i=0,j=2;j<s.length();j+=2)
            {

                string A =s.substr(i,j);
                string B= s.substr(i+j,s.length()-i-j);
                //cout<<A<<" "<<B<<endl;
                cost = mini(A) + mini(B);
                if (cost<mincost) {
                     mincost=cost;
                }
            }
            string A;
            PB(A,s[0]);
            PB(A,s[s.length()-1]);
                        string B = s.substr(1,s.length()-2);
            cost = mini(A) + mini(B);
            if (cost < mincost)
                mincost = cost;
                m[s]=mincost;

            return mincost;
        }
        else  {
            if (check(s))
                return 0;
            else if (s=="}{"||s=="]{"||s=="]["||s==")("||s=="]("||s=="}("||s=="}["||s=="){"||s==")[")
                            return 2;
            else return 1;
    }

}

int main()
{
    string s;
    int i,j,k,p,q;

    while(getline(cin,s,'\n'))
    {
        if(s.length()==0)

        {
            cout<<"0\n";
            continue;
        }
        m.clear();
        if (s.length() %2 ==1)
        cout<<"-1"<<endl;
        else
        cout<< mini(s)<<endl;;

    }
//	system("pause");
	return 0;
}





























