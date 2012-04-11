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

inline long long gcd(long long a, long long b) { if(a%b==0) return b; return gcd(b,a%b); }
inline string i2s(int number) { stringstream ss; ss << number; return ss.str(); }
inline void input( int &n ) { n=0; int ch=getchar(); while( ch < '0' || ch > '9' ) ch=getchar(); while( ch >= '0' && ch <= '9' ) n = (n<<3)+(n<<1) + ch-'0', ch=getchar(); }
int c,a,b;

/*
bool vis[40005][40005];
//END_TEMPLATE_BY_PRATYUSH_VERMA

int dfs()
{
    queue<TRI> q;
    q.push(MP(0,MP(0,0)));
    while(!q.empty())
    {
        TRI t=q.front();
        q.pop();
        int x=t.second.first;
        int y=t.second.second;
        int s=t.first;
        if(vis[x][y]==true)
        {
            continue;
        }
        vis[x][y]=true;
        if(x==c || y==c)
        return s;
        if(x!=a)
        {
            q.push( MP (s+1, MP ( a,y )));
        }
        if(y!=b)
        {
            q.push( MP (s+1, MP ( x,b )));
        }
        if(x!=0)
        {
            q.push( MP (s+1, MP ( 0,y )));
        }
        if(y!=0)
        {
            q.push( MP (s+1, MP ( x,0 )));
        }
        {
            if(x <= b-y && (x!=0 || y!=0))
            {
                q.push( MP ( s+1 , MP (0,x+y ) ));
            }
            else if(x > b-y)
            {
                q.push( MP ( s+1, MP (x-(b-y),b ) ));
            }
        }
        {

            if(y <= a-x && (x!=0 || y!=0))
            {
                q.push( MP ( s+1 , MP ( x+y,0 ) ));
            }
            else if(y > a-x)
            {
                q.push( MP ( s+1, MP (a,y-(a-x) ) ));
            }
        }
//        getchar();
    }
    return -1;
}
int main()
{
    int t,i,j,k,p,q;
    input(t);
    while(t--)
    {
        MEM(vis,0);
        input(a);
        input(b);
        input(c);
        printf("%d\n",dfs());
    }
//	system("pause"); //Windows Only
	return 0;
}

*/

int main()
{
    int t,x,y,p,q;
//    fread_unlocked(infile,20000000,1,stdin);
    input(t);
    while(t--)
    {
//        MEM(vis,0);
        x=0;y=0;
        input(a);
        input(b);
        input(c);
        int s1=0,s2=0;
        int g=gcd(a,b);
        if(c%g!=0 || c>max(a,b))
        {
            printf("-1\n");
            continue;
        }
        while(x!=c && y!=c)
        {
            s1++;
            if(x==0) x=a;
            else if(y==b) y=0;
            else
            {
                y=x+y;
                if(y<=b)
                {
                    x=0;
                }
                else
                {
                    x=y-b;
                    y=b;
                }
            }
        }
        {
            x=0;y=0;
            swap(a,b);
            while(x!=c && y!=c)
            {
                s2++;
                if(s2>s1) break;
                if(x==0) x=a;
                else if(y==b) y=0;
                else
                {
                    y=x+y;
                    if(y<=b)
                    {
                        x=0;
                    }
                    else
                    {
                        x=y-b;
                        y=b;
                    }
                }
            }
        }
        printf("%d\n",MIN(s1,s2));
    }
//	system("pause"); //Windows Only
	return 0;
}

