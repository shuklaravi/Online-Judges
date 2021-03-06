/*
ID: vermapr1
PROG: <prog_name>
LANG: C++
*/

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
int N,X,Y;
char arr[105][105];
int checkP(int x, int y)
{
    if(x+1<N && y-2>=0 && arr[x+1][y-2]=='P') return 1;
    if(x-1>=0 && y-2>=0 && arr[x-1][y-2]=='P') return 1;
    if(x-2>=0 && y-1>=0 && arr[x-2][y-1]=='P') return 1;
    if(x-2>=0 && y+1<N && arr[x-2][y+1]=='P') return 1;
    return 0;
}
int main()
{
    int loop;

    while(cin>>N>>X>>Y)
    {
        if(N<=2) { cout<<"Second\n"; continue; }
        arr[0][0]='P';arr[0][1]='P';arr[1][0]='P';arr[1][1]='P';
        loop=2;
        int x,y;


        int m = N;
        int n = N;
        for (int slice = 0; slice < m + n - 1; ++slice) {
            int z1 = slice < n ? 0 : slice - n + 1;
            int z2 = slice < m ? 0 : slice - m + 1;
            for (int j = slice - z2; j >= z1; j--) {
                    if(checkP(j,slice-j)) arr[j][slice-j]='N';
                    else arr[j][slice-j]='P';

            }
        }
        if(arr[X][Y]=='N') cout<<"First\n";
        else cout<<"Second\n";
    }
//	system("pause");
	return 0;
}



























