// #define TRUE FALSE .. haha now debug this..:D

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

typedef pair<int,int>   PII;
typedef pair<char,int>  PCI;
typedef pair<int,PII>   TRI;
typedef V( int )        VI;
typedef V( PII )        VII;
typedef V( TRI )        VTRI;
typedef V( string )     VS;
typedef long long       LL;
typedef long double     LD;

inline string i2s(int number) { stringstream ss; ss << number; return ss.str(); }
inline void input( int &n ) { n=0; int ch=getchar(); while( ch < '0' || ch > '9' ) ch=getchar(); while( ch >= '0' && ch <= '9' ) n = (n<<3)+(n<<1) + ch-'0', ch=getchar(); }

//END_TEMPLATE_BY_PRATYUSH_VERMA
int I,J;
struct node {
    int x, y,t;
    node (int a, int b, int c) {
        x=a; y=b; t=c;
    }
};
int dx[8]={1,-1,1,-1,2,-2,2,-2};
int dy[8]={2,2,-2,-2,1,1,-1,-1};
int bfs()
{
    set<PII> s;
    queue<node> q;
    int i;
    q.push(node (0,0,0));
    while(!q.empty())
    {
        node t=q.front();
        s.insert( MP (t.x,t.y));
//        cout<<"..."<<t.x<<" "<<t.y<<" "<<I<<" "<<J<<endl;
        if(t.x==I && t.y==J) return t.t;
        q.pop();
        REP(i,8)
        {
            int xx=t.x+dx[i]; int yy=t.y+dy[i];
            if(xx<0 || yy<0) continue;
            if(s.find( MP(xx,yy) )!=s.end() ) continue;
            q.push(node (xx,yy,t.t+1));
        }
    }
    return -1;
}
int main()
{
    string s;
    while(1)
    {
        stringstream ss;
        getline(cin,s);
        if(s[0]=='E') break;
        ss<<s;
        ss>>I; ss>>J;
//        cout<<I<<" ........."<<J<<endl;
        I=I<0?-I:I;
        J=J<0?-J:J;
        cout<<bfs()<<endl;
    }
//	system("pause"); //Windows Only
	return 0;
}





















