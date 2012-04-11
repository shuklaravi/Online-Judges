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
#define EPS 1e-11
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
int r,c;
vector<PII> a[10];
int step[105][105];
string arr[105];
struct node {
    int i,j,s;
    node(int a, int b, int c) {
        i=a;j=b;s=c;
    }
};
node start(0,0,0);
node end(0,0,0);
int min;
bool is_in(int a, int b)
{
    if(a<0 || a>=r || b<0 || b>=c) return false;
    return true;
}
int dfs()
{
    queue<node> s;
    s.push(start);
    int i,j,min=-1;
    int dx[]={1,0,-1,0};
    int dy[]={0,1,0,-1};
    step[start.i][start.j]=0;
    while(!s.empty())
    {
        node temp=s.front();
        s.pop();
//        cout<<" popping "<<temp.i<<" "<<temp.j<<" in steps = "<<temp.s<<endl;
        if(temp.i==end.i && temp.j==end.j && (min>temp.s || min==-1))
        {
            min=temp.s;
            continue;
        }

        if ( step[temp.i][temp.j] < temp.s && step[temp.i][temp.j] != -1 ) continue;
        step[temp.i][temp.j]=temp.s;
        if(arr[temp.i][temp.j]!='0')
        REP(i,a[ arr[temp.i][temp.j]-'0' ].size())
        {
            int xx=a[arr[temp.i][temp.j]-'0'][i].first;
            int yy=a[arr[temp.i][temp.j]-'0'][i].second;
            if(xx==temp.i && yy==temp.j) continue;
            if(arr[xx][yy]=='W') continue;
//            if(step[xx][yy]>temp.s) continue;
            if ( step[xx][yy] <= (temp.s+1) && step[xx][yy] != -1 ) continue;
            step[xx][yy]=temp.s+1;
            s.push(node(xx,yy,temp.s+1));
//            cout<<" teleporting to "<<xx<< " "<<yy<< " "<<temp.s+1<<" via "<<arr[xx][yy]<<endl;
        }
        REP(i,4)
        {
            int xx=temp.i+dx[i]; int yy=temp.j+dy[i];
            if(!is_in(xx,yy)) continue;
            if(arr[xx][yy]=='W') continue;
//            if(step[xx][yy] > temp.s) continue;
            if ( step[xx][yy] <= (temp.s+1) && step[xx][yy] != -1 ) continue;
            step[xx][yy]=temp.s+1;
            s.push(node(xx,yy,temp.s+1));
//            cout<<" .pushed "<<xx<< " "<<yy<< " "<<temp.s+1<<endl;
        }
//        getchar();
    }
    return min;
}

int main()
{
    int n,i,j,k;
    cin>>n;
    while(n--)
    {
        cin>>r>>c;
        MEM(step,-1);
        REP(i,10)
        a[i].clear();
        REP(i,r)
        {
            cin>>arr[i];
            REP(j,c)
            {
                if(arr[i][j]=='S')
                {
                    start.i=i;
                    start.j=j;
                    start.s=0;
                }
                else if(arr[i][j]=='E')
                {
                    end.i=i;
                    end.j=j;
                    end.s=0;
                }
                else if(arr[i][j]!='0')
                {
                    PB(a[arr[i][j]-'0'],MP(i,j));
                }
            }
        }
//        cout<<"start is  : "<<start.i<<" "<<start.j<<endl;
//        cout<<"end is  : "<<end.i<<" "<<end.j<<endl;
        cout<<dfs()<<endl;
    }
//	system("pause");
	return 0;
}

























