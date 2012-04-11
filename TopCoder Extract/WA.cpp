// #define TRUE FALSE haha now debug this

// BEGIN CUT HERE

// END CUT HERE
#line 7 "EllysDirectoryListing.cpp"

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

struct node{
	   int aX,aY,bX,bY;
	   int steps;
	   node(int a, int b, int c, int d, int e){
				aX=a;aY=b;bX=c;bY=d;steps=e;
        }
};

class PathFinding {
	public:
	int N, M;
	int Ax, Ay, Bx, By;
	bool vis[20][20][20][20];
	bool is_in(int x, int y) {
        if(x<0 || x>=N || y<0 || y>=M) return false;
            return true;
	}
	int bfs() {
		queue<node> s;
		MEM(vis, false);
		s.push(node (Ax, Ay, Bx, By, 0));
		while(!s.empty())
		{
						 node t=s.front();
						 s.pop();
						 if(t.aX == Bx && t.aY == By && t.bY == Ax && t.bY == Ay) return t.steps;
                         vis[t.aX][t.aY][t.bX][t.bY] = true;
						 for(int p1DelX=-1;p1DelX<2;p1DelX++)
						 for(int p1DelY=-1;p1DelY<2;p1DelY++)
						 for(int p2DelX=-1;p2DelX<2;p2DelX++)
						 for(int p2DelY=-1;p2DelY<2;p2DelY++)
						 {
						     int Axx = p1DelX + t.aX; int Ayy = p1DelY + t.aY; int Bxx = p2DelX + t.bX; int Byy = p2DelY + t.bY;
						     if(!is_in(Axx, Ayy)) continue;
						     if(!is_in(Bxx, Byy)) continue;
						  		 if(vis[Axx][Ayy][Bxx][Byy]) continue;
						  		 if(Axx == t.bX && Ayy == t.bY && Bxx == t.aX && Byy == t.aY) continue;
						  		 s.push(node (Axx, Ayy, Bxx, Byy, t.steps + 1));
		 				 }
        }
		return -1;
	}
	int minTurns(vector <string> board) {
        int i,j,k,p,q;
        N = board.size();
        M = board[0].length();
        REP(i,board.size())
            REP(j,board[0].length())
                if(board[i][j] == 'A')
                    Ax = i, Ay = j;
                else if(board[i][j] == 'B')
                    Bx = i, By = j;
		return bfs();
	}
};
int main()
{
    int r,c,i,j,k;
    PathFinding p;
    while(cin>>r>>c)
    {
        string s;
        vector<string> grid;
        for(i=0;i<r;i++)
        {
            cin>>s;
            grid.push_back(s);
        }
        cout<<p.minTurns(grid)<<endl;
    }
}
