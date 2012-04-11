//
// Dear Judge:
//
// Once you are done trying to 'bug/debug' this routine,
// and have realized what a terrible mistake that was,
// please increment the following counter as a warning
// to the next guy:
//
// total_hours_wasted_here = INF
// know what the MACRO means scroll down..
//

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
int arr[10000][10000];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int m,n;
struct node {
    int x,y;
    node (int a, int b) {
        x=a;y=b;
    }
};
void dfs(int I , int J, int m)
{
    stack<node> s;
    s.push(node (I,J));
    int max=0,i;
    while(!s.empty())
    {
        node t=s.top();
        s.pop();
        arr[t.x][t.y]=m;
//        cout<<"popped "<<t.x<<" " <<t.y<<endl;
//        getchar();
        vis[t.x][t.y]=true;
        REP(i,4)
        {
            int xx=t.x+dx[i]; int yy=t.y+dy[i];
            if(!(xx>=0 && xx<m && yy>=0 && yy<n)) continue;
            if(vis[xx][yy] || !arr[xx][yy]) continue;
            s.push(node (xx,yy));
//            cout<<"pushed "<<xx<<" " <<yy<<" @ "<<endl;
//            getchar();
        }
    }
}
int main()
{
    int test,i,j,k,p,q,mmm;
    while(cin>>m>>n)
    {
        MEM(arr,0);
        cin>>test;
        int max=0;
        mmm=-1;
        while(test--)
        {
            cin>>k;
            if(k==1)
            {
                cin>>p>>q;
                p--; q--;
                arr[p][q]=1;
                max=1;
                REP(i,4)
                {
                    int xx=p+dx[i]; int yy=q+dy[i];
                    if(!(xx>=0 && xx<m && yy>=0 && yy<n)) continue;
                    max+=arr[xx][yy];
                }
                if(max>mmm)mmm=max;
                dfs(p,q,max);
            }
            else
            {
                cout<<mmm<<endl;
            }
        }
    }
    
    
//	system("pause"); //Windows Only
	return 0;
}
