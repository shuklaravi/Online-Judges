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
struct node
{
    int i;
    friend bool operator+(struct node &a, struct node &b)
    {
        return a.i+b.i;
    }
    friend bool operator*(struct node &a, struct node &b)
    {
        return a.i*b.i;
    }
    friend bool operator< (const node &a, const node &b)
	   {
			  return (a.i>b.i);
	   		  }
    node(int ii)
    {
        i=ii;
    }
};
int main()
{
    priority_queue<node> q;
    int a,b,c,d,i,k,j;
    cin>>a>>b>>c>>d;
    
    q.push(node(a));q.push(node(c));q.push(node(b));q.push(node(d));
    char aa,bb,cc;
    cin>>aa>>bb>>cc;
    int res=1;
    int arr[128];
    MEM(arr,0);
    arr[aa]++;
    arr[bb]++;
    arr[cc]++;
    bool flag=true;
    if((a==0||b==0||c==0||d==0) && (aa=='*'||bb=='*'||cc=='*'))
    {
        cout<<"0";
        return 0;
    }
    if(arr['*']>0)
    {
        flag=0;
        res=q.top().i;
        q.pop();
        res*=q.top().i;
        q.pop();
        q.push(node(res));
        arr['*']--;
//        cout<<"1 "<<res<<endl;
    }
    if(arr['*']>0)
    {
        res=q.top().i;
//        cout<<"popped "<<q.top().i<<endl;
        q.pop();
        res*=q.top().i;
  //      cout<<"popped "<<q.top().i<<endl;
        q.pop();
        q.push(node(res));
        arr['*']--;
    //    cout<<"2 "<<res<<endl;
    }
    if(arr['*']>0)
    {
        res=q.top().i;
        q.pop();
        res*=q.top().i;
        q.pop();
        q.push(node(res));
      //  cout<<"3 "<<res<<endl;
    }
    
    if(arr['+']>0)
    {
        if(flag==1)
        {
            res=q.top().i;
            q.pop();
            res+=q.top().i;
            q.pop();
            q.push(node(res));
        }
        else
        {
            res=q.top().i;
            q.pop();
            res+=q.top().i;
            q.pop();
            q.push(node(res));
        }
        //cout<<"4 "<<res<<endl;
        arr['+']--;
//        cout<<"./................"<<arr['+']<<endl;
    }
    if(arr['+']>0)
    {
        res=q.top().i;
        q.pop();
        res+=q.top().i;
        q.pop();
        q.push(node(res));
  //      cout<<"./................"<<arr['+']<<endl;
        arr['+']--;
    //    cout<<"5 "<<res<<endl;
    }
    if(arr['+']>0)
    {
        res=q.top().i;
        q.pop();
        res+=q.top().i;
        q.pop();
        q.push(node(res));
      //  cout<<"6 "<<res<<endl;
    }
    cout<<q.top().i<<endl;
//	system("pause");
	return 0;
}
