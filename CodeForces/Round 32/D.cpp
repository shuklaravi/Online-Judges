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
struct node {
    int radii,up,left;
    node (int a, int b, int c) {
        radii=a; up=b; left=c;
    }
    friend bool operator <(struct node &a, struct node &b) {
    if(a.radii == b.radii)
    {
        if(a.up == b.up)
        {
            return a.left < b.left;
        }
        return a.up < b.up;
    }
    return a.radii < b.radii;
}
};

int main()
{
    char map[305][305];
    MEM(map,0);
    int r,n,m,k,i,j,p,q;
    cin>>n>>m>>k;
//    swap(m,n);
    vector<node> v;
    REP(i,n)
    cin>>map[i];
//        REP(j,m)
            {
//                scanf("%c",&map[i][j]);
            }
    for(r=1;r<=min(n,m)/2;r++)
    {
        for(i=r;i<n-r;i++)
        {
            for(j=r;j<m-r;j++)
            {
                if(!(j+r < m || j-r >= 0 || i+r < n || i-r >=0)) continue;
//                cout<<" checking "<<r<<" "<<i<<" "<<j<<" "<<(char)(map[i][j])<<(char)(map[i][j+r])<<(char)(map[i][j-r])<<(char)(map[i+r][j])<<(char)(map[i-r][j])<<endl;
                if(map[i][j]=='*' && map[i][j+r]=='*' && map[i][j-r]=='*' && map[i+r][j]=='*' && map[i-r][j]=='*')
                v.push_back(node (r,i,j));
//                cout<<r<<" "<<i<<" "<<j<<endl;
//                getchar();
            }
//                            cout<<"...."<<r<<" "<<i<<" "<<j<<endl;
//                getchar();
        }
//                        cout<<"!!!!!!!!!!"<<r<<" "<<i<<" "<<j<<endl;
//                getchar();
    }
    int sz=v.size();
    if(v.size() < k) cout<<"-1";
    else
    {
        cout<<v[k-1].up+1<<" "<<v[k-1].left+1<<endl;
        cout<<v[k-1].up-v[k-1].radii+1<<" "<<v[k-1].left+1<<endl;
        cout<<v[k-1].up+v[k-1].radii+1<<" "<<v[k-1].left+1<<endl;
        cout<<v[k-1].up+1<<" "<<v[k-1].left-v[k-1].radii+1<<endl;
        cout<<v[k-1].up+1<<" "<<v[k-1].left+v[k-1].radii+1<<endl;
    }
//	system("pause"); //Windows Only
	return 0;
}























