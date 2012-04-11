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
int target;
int a,b,c;
int otot,oret;
bool vis[205][205][205];
struct node {
    int a,b,c;
    int total;
    friend bool operator< (const node &a, const node &b) {
        return a.total>b.total;
    }
    node (int i, int j, int k, int l) {
        a=i; b=j; c=k; total=l;
    }
};
void bfs()
{
    MEM(vis,false);
    priority_queue<node> q;
    q.push(node(0,0,c,0));
    int ta,tb,tc,pour;
    otot=INF; oret=-1;
    while(!q.empty())
    {
        node t=q.top();
        q.pop();
        // to store visited nodes..
        vis[t.a][t.b][t.c]=true;
        // if any of the jar contains.. the target volume
        if(t.a==target ||t.b==target||t.c==target) {
            oret=target;
            otot=t.total;
            return ;
        }
        // in case the jar can not attain d amt of liquid.. oret will store the vol.. and otot will stor the total flow
        if(t.a<target  && ((oret<t.a) || (oret==t.a && otot>t.total))) {
            oret=t.a;
            otot=t.total;
        }
        if(t.b<target  && ((oret<t.b) || (oret==t.b && otot>t.total))) {
            oret=t.b;
            otot=t.total;
        }
        if(t.c<target  && ((oret<t.c) || (oret==t.c && otot>t.total))) {
            oret=t.c;
            otot=t.total;
        }
        // a b c
        // if a is not empty
        if(t.a!=0) {
            // tb= empty space in jar B
            tb=b-t.b;
            // tc= empty space in jar C
            tc=c-t.c;
            pour=min(tb,t.a);
            // pour "pour" vol of liquid from A to B
            if(!vis[t.a-pour] [t.b+pour] [t.c]) q.push(node(t.a-pour,t.b+pour,t.c,t.total+pour));
            if(pour==tb) {
                int temp=min(t.a-pour,tc);
                // pour "temp" vol of liquid from A to C..
                if(!vis[t.a-pour-temp][t.b+pour][t.c+temp]) q.push(node(t.a-pour-temp,t.b+pour,t.c+temp,t.total+pour+temp));
            }
            pour=min(tc,t.a);
            // pour "pour" amt of liquid fomr A to C
            if(!vis[t.a-pour] [t.b] [t.c+pour]) q.push(node(t.a-pour,t.b,t.c+pour,t.total+pour));
            if(pour==tc) {
                int temp=min(t.a-pour,tb);
                // pour "temp" amt of liq form A to B..
                if(!vis[t.a-pour-temp][t.b+temp][t.c+pour]) q.push(node(t.a-pour-temp,t.b+temp,t.c+pour,t.total+pour+temp));
            }
        }

        // same procedure as in A except replace
        // a=>b b=>c c=>a
        if(t.b!=0) {
            tc=c-t.c;
            ta=a-t.a;
            pour=min(tc,t.b);
            if(!vis[t.a] [t.b-pour] [t.c+pour]) q.push(node(t.a,t.b-pour,t.c+pour,t.total+pour));
            if(pour==tc) {
                int temp=min(t.b-pour,ta);
                if(!vis[t.a+temp][t.b-pour-temp][t.c+pour]) q.push(node(t.a+temp,t.b-temp-pour,t.c+pour,t.total+pour+temp));
            }
            pour=min(ta,t.b);
            if(!vis[t.a+pour] [t.b-pour] [t.c]) q.push(node(t.a+pour,t.b-pour,t.c,t.total+pour));
            if(pour==ta) {
                int temp=min(t.b-pour,tc);
                if(!vis[t.a+pour][t.b-temp-pour][t.c+temp]) q.push(node(t.a+pour,t.b-pour-temp,t.c+temp,t.total+pour+temp));
            }
        }

        // this time replace
        // a=>c b=>a c=>b
        if(t.c!=0) {
            ta=a-t.a;
            tb=b-t.b;
            pour=min(ta,t.c);
            if(!vis[t.a+pour] [t.b] [t.c-pour]) q.push(node(t.a+pour,t.b,t.c-pour,t.total+pour));
            if(pour==ta) {
                int temp=min(t.c-pour,tb);
                if(!vis[t.a+pour][t.b+temp][t.c-pour-temp]) q.push(node(t.a+pour,t.b+temp,t.c-pour-temp,t.total+pour+temp));
            }
            pour=min(tb,t.c);
            if(!vis[t.a] [t.b+pour] [t.c-pour]) q.push(node(t.a,t.b+pour,t.c-pour,t.total+pour));
            if(pour==tb) {
                int temp=min(t.c-pour,ta);
                if(!vis[t.a+temp][t.b+pour][t.c-temp-pour]) q.push(node(t.a+temp,t.b+pour,t.c-temp-pour,t.total+pour+temp));
            }
        }
    }
    return ;
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        cin>>a>>b>>c>>target;
        bfs();
        cout<<otot<<" "<<oret<<endl;
    }
//	system("pause");
	return 0;
}






























