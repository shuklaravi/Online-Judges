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
vector<PII> v;
int nails,right;
double n;
int find_left()
{
    int minx=INF,miny=INF,idx=-1;
    int i;
    REP(i,nails)
    {
        if(minx==v[i].first && miny<v[i].second) { minx=v[i].first; miny=v[i].second; idx=i; continue; }
        if(minx>v[i].first) { minx=v[i].first; miny=v[i].second; idx=i; }
    }
    return idx;
}
int find_right()
{
    int minx=INF,miny=INF,idx=-1;
    minx=-minx;
    miny=-miny;
    int i;
    REP(i,nails)
    {
        if(minx==v[i].first && miny>v[i].second) { minx=v[i].first; miny=v[i].second; idx=i; continue; }
        if(minx<v[i].first) { minx=v[i].first; miny=v[i].second; idx=i;  }
    }
    return idx;
}
double angle(int p,int q)
{
    return atan(((double)v[q].second-(double)v[p].second)/((double)v[q].first-v[p].first));
}
double distancee(int a, int b)
{
    return sqrt( pow(v[a].first-v[b].first,2.0) + pow(v[a].second-v[b].second,2.0)  );
}
int main()
{
    int test;
    cin>>test;
    string str;
    int i,j,q,p;
    while(test--)
    {
        vector<bool> vis;
        v.clear();
        double dist=0;
        cin>>n>>nails;
        REP(i,nails)
        {
            cin>>p>>q;
            PB(v, MP(p,q));
            PB(vis,false);
        }
        int left=find_left();
        int right=find_right();
   //     cout<<"right is  "<<right<<endl;
 //ZZ       cout<<"left is "<<left<<endl;
        bool flag=0;
        if(left==right)
        {
            cout<<max(0.0,n)<<endl;
            continue;
        }
        int first=left;
        int next;
  //      cout<<"statrt point is "<<left<<endl;
        do {
            next=-1;
            double slope=-9999999.9;
            REP(i,nails)
            {
                if(left==i) continue;
                if(vis[i]) continue;


                double _slope=angle(i,left);

   //             cout<<"calc from "<<left<<" to "<<i<<" slope = "<<_slope<<endl;

      //          cout<< (_slope > slope )<<" "<<(!flag)<<" "<<(v[left].first<v[i].first)<<endl;
                if( _slope>slope && !flag && v[left].first <= v[i].first)
                {
                    slope=_slope;
                    next=i;
    //                cout<<"updating "<<i<<" from "<<left<<endl;
                }

                if( _slope>slope && flag && v[left].first >= v[i].first)
                {
                    slope=_slope;
                    next=i;
  //                  cout<<"!!! updating "<<i<<" from "<<left<<endl;
                }
            }


            dist+=distancee( next,left);
//            cout<<"chosing point "<<next<<" "<<dist<<endl;
            vis[next]=1;

            if(next==right) { flag=!flag;  }

            left=next;
   //         getchar();
        }while(first!=next);
        printf("%0.5lf\n",n>dist?n:dist);
//        cout<<max(dist,n)<<endl;
    }
//	system("pause");
	return 0;
}




























