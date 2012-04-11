
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


int L,M,N;
bool vis[105][105][105];
struct node {
    int i,j,k;
    int s;
    node(int a, int b, int c, int ss) {
        i=a; j=b; k=c; s=ss;
    }
};
bool is_in(int a, int b, int c) {
    if(a<=0 || a>L || b<=0 || b>M || c<=0 || c> N) return false;
    return true;
}
int bfs()
{
    queue<node> q;
    if(vis[1][1][1]==true) return -1;
    q.push(node (1,1,1,1));
    int i;
    int dx[]={1,-1,0,0,0,0};
    int dy[]={0,0,1,-1,0,0};
    int dz[]={0,0,0,0,1,-1};
    while(!q.empty())
    {
        node t=q.front();
        q.pop();
        if(t.i==L && t.j==M && t.k==N) return t.s;
        vis[t.i][t.j][t.k]=true;
        REP(i,6) {
            int xx=t.i+dx[i]; int yy=t.j+dy[i]; int zz=t.k+dz[i];
            if(!is_in(xx,yy,zz)) continue;
            if(vis[xx][yy][zz]) continue;
            vis[xx][yy][zz]=true;
            q.push(node(xx,yy,zz,t.s+1));
        }
    }
    return -1;
}
int main()
{
    int test;
    cin>>test;
    int i,j,k,p,q,r,x,y,z,ii,jj,kk;
    while(test--) {
        MEM(vis,0);
        cin>>L>>M>>N;
//        L--; M--; N--;
        cin>>k;
        REP(i,k) {
            cin>>p>>q>>r>>x>>y>>z;
            FOR_(ii,p+1,p+x) {
                FOR_(jj,q+1,q+y) {
                    FOR_(kk,r+1,r+z) {
                        vis[ii][jj][kk]=true;
                    }
                }
            }
        }
        cout<<bfs()<<endl;
    }
//	system("pause");
	return 0;
}




























