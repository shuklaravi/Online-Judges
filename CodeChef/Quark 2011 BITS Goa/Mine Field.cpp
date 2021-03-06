/*
CodeJam ID: vermapratyush
Name: Pratyush Verma
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
#define F first
#define S second
#define FF first.first
#define FS first.second
#define SF second.first
#define SS second.second

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
int R,C;
int arr[1005][1005];
int MOD=1000003;
int dx[]={1,0};
int dy[]={0,1};
int res;
bool is_in(int x, int y)
{
    if(x<0 || x>=R || y<0 || y>=C) return false;
    return true;
}
int dfs()
{
    stack<TRI> s;
    s.push(MP(0,MP(0,0)));
    int ret=0,i;
    while(!s.empty())
    {
        TRI t=s.top();
        s.pop();
        if(t.SF==R-1 && t.SS==C-1)
        {
            if(t.F==1) ret++;
            ret++;
            ret%=MOD;
        }
        REP(i,2)
        {
            int xx=t.SF+dx[i]; int yy=t.SS+dy[i];
            if(!is_in(xx,yy))continue;
            if(arr[xx][yy]==-1) continue;
            if(i==1)
            s.push(MP(0,MP(xx,yy)));
            else
            {
                if(arr[xx][yy+1]!=-1)
                s.push(MP(1,MP(xx,yy+1)));
                else
                s.push(MP(0,MP(xx,yy)));
            }
        }
    }
    return ret;
}
void dfs_rec(int x, int y)
{
    int i;
    if(x==R-1 && y==C-1)
    {
        res++;
        res%=MOD;
        return ;
    }
    REP(i,3)
    {
        int xx=x+dx[i]; int yy=y+dy[i];
        if(!is_in(xx,yy)) continue;
        if(arr[xx][yy]==-1) continue;
        dfs_rec(xx,yy);
    }
    arr[x][y]=1;
}
int main()
{
    int i,j,k,p,q;
    int test;
    input(test);
    while(test--)
    {
        input(R);input(C);input(k);
        MEM(arr,-1);
        while(k--)
        {
            input(p);input(q);
            p--;q--;
            arr[p][q]=0;
        }
        arr[0][0]=1;


        for(i=1;i<C;i++)
            if(arr[0][i]!=0) arr[0][i]=1;
            else break;
        for(i=1;i<R;i++)
            if(arr[i][0]!=0) arr[i][0]=1;
            else break;
        for(j=1;j<C;j++)
        {
            for(i=1;j<R;j++)
            {
                if( arr[i][j]==-1)
                {
                    arr[i][j]+=arr[i-1][j];
                    arr[i][j]+=arr[i-1][j-1];
                    arr[i][j]+=arr[i][j-1];
                }
            }
        }
        REP(i,R)
        {
            REP(j,C)
                cout<<arr[i][j]<<" ";
            cout<<endl;
        }
        cout<<arr[R-1][C-1]<<endl;










//        printf("%d\n",dfs()%MOD);
//
//        cout<<"_____________________________________\n";
//        res=0;
//        dfs_rec(0,0);
//        cout<<res%MOD<<endl;
    }
//	system("pause");
	return 0;
}





























