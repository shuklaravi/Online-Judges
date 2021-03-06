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
#define MAXX 270000
struct node {
LL q[4];
bool updateX;
bool updateY;
LL lo, hi;
}Seg[MAXX];
void init(LL _min, LL _max, LL idx)
{
    for(int i = 0; i < 4; ++i)
        Seg[idx].q[i] = 0;
    Seg[idx].lo = _min;
    Seg[idx].hi = _max;
    Seg[idx].updateX = 0;
    Seg[idx].updateY = 0;
    if(_min < _max)
    {
        LL _mid = (_min + _max) / 2;
        init(_min, _mid, idx * 2);
        init(_mid + 1, _max, idx * 2 + 1);
    }
}
int is_in(int p, int q)
{
    if(p > 0 && q > 0) return 0;
    if(p < 0 && q > 0) return 1;
    if(p < 0 && q < 0) return 2;
    return 3;
}
void insert(int idx, int k, int quad)
{
    Seg[idx].q[quad]++;
    if(Seg[idx].lo == k && Seg[idx].hi == k)
        return ;
    else{
        int M = (Seg[idx].lo + Seg[idx].hi) / 2;
        if(M >= k) {
            insert(idx * 2, k, quad);
        }
        else {
            insert(idx * 2 + 1, k, quad);
        }
    }
}
void relax(int idx)
{
    if(Seg[idx].updateX)
    {
        if(Seg[idx].hi != Seg[idx].lo)
        {
            Seg[idx * 2].updateX = !Seg[idx * 2].updateX;
            Seg[idx * 2  + 1].updateX = !Seg[idx * 2  + 1].updateX;
        }
        Seg[idx].updateX = 0;
        swap(Seg[idx].q[0], Seg[idx].q[3]);
        swap(Seg[idx].q[1], Seg[idx].q[2]);
    }
    if(Seg[idx].updateY)
    {
        if(Seg[idx].hi != Seg[idx].lo)
        {
            Seg[idx * 2].updateY = !Seg[idx * 2].updateY ;
            Seg[idx * 2  + 1].updateY = !Seg[idx * 2  + 1].updateY;
        }
        Seg[idx].updateY = 0;
        swap(Seg[idx].q[0], Seg[idx].q[1]);
        swap(Seg[idx].q[2], Seg[idx].q[3]);
    }
}
void mirror(int D, int idx, int I, int J)
{
    int i;
    if(Seg[idx].lo == I && Seg[idx].hi == J)
    {
        if(Seg[idx].lo != Seg[idx].hi)
        {
            if(D == 1)
            {
                Seg[idx * 2].updateX = !Seg[idx * 2].updateX;
                Seg[idx * 2 + 1].updateX = !Seg[idx * 2 + 1].updateX;
            }
            else
            {
                Seg[idx * 2].updateY = !Seg[idx * 2].updateY;
                Seg[idx * 2 + 1].updateY = !Seg[idx * 2 + 1].updateY;
            }
        }
        if(D == 1)
        {
            swap(Seg[idx].q[0], Seg[idx].q[3]);
            swap(Seg[idx].q[1], Seg[idx].q[2]);
        }
        else
        {
            swap(Seg[idx].q[0], Seg[idx].q[1]);
            swap(Seg[idx].q[2], Seg[idx].q[3]);
        }
        return ;
    }
    int M = (Seg[idx].lo + Seg[idx].hi) / 2;
    if(M >= J)
        mirror(D, idx * 2, I, J);
    else if(M < I)
        mirror(D, idx * 2 + 1, I, J);
    else
    {
        mirror(D, idx * 2, I, M);
        mirror(D, idx * 2 + 1, M + 1, J);
    }
    relax(idx * 2);
    relax(idx * 2 + 1);
    REP(i,4)
        Seg[idx].q[i] = Seg[idx * 2].q[i] + Seg[idx * 2 + 1].q[i];
    return ;
}
void count(int &Q1, int &Q2, int &Q3, int &Q4, int I, int J, int idx)
{
    int i;

    if(Seg[idx].updateX)
    {
        if(Seg[idx].hi != Seg[idx].lo)
        {
            Seg[idx * 2].updateX = !Seg[idx * 2].updateX;
            Seg[idx * 2  + 1].updateX = !Seg[idx * 2  + 1].updateX;
        }
        Seg[idx].updateX = 0;
        swap(Seg[idx].q[0], Seg[idx].q[3]);
        swap(Seg[idx].q[1], Seg[idx].q[2]);
    }
    if(Seg[idx].updateY)
    {
        if(Seg[idx].hi != Seg[idx].lo)
        {
            Seg[idx * 2].updateY = !Seg[idx * 2].updateY ;
            Seg[idx * 2  + 1].updateY = !Seg[idx * 2  + 1].updateY;
        }
        Seg[idx].updateY = 0;
        swap(Seg[idx].q[0], Seg[idx].q[1]);
        swap(Seg[idx].q[2], Seg[idx].q[3]);
    }
    if(Seg[idx].lo == I && Seg[idx].hi == J)
    {
        Q1 += Seg[idx].q[0];
        Q2 += Seg[idx].q[1];
        Q3 += Seg[idx].q[2];
        Q4 += Seg[idx].q[3];
      return ;
    }
    int M = (Seg[idx].lo + Seg[idx].hi) / 2;
    if(M >= J)
        count(Q1, Q2, Q3, Q4, I, J, idx * 2);
    else if(M < I)
        count(Q1, Q2, Q3, Q4, I, J, idx * 2 + 1);
    else
    {
        count(Q1, Q2, Q3, Q4, I, M, idx * 2);
        count(Q1, Q2, Q3, Q4, M + 1, J, idx * 2 + 1);
    }
  return ;
}
int main()
{
    int N, i, j, k, p ,q;
    int Q;
    char ch;
    cin>>N;
    init(0, N - 1, 1);
    REP(i,N)
    {
        cin>>p>>q;
        insert(1, i,is_in(p,q));
    }
    cin>>Q;
    int Q1, Q2, Q3, Q4;
    REP(i,Q)
    {
        Q1 = Q2 = Q3 = Q4 = 0;
        cin>>ch>>p>>q; p--; q--;
        if(ch == 'X')
            mirror(1, 1, p, q);
        else if(ch == 'Y')
            mirror(0, 1, p, q);
        else
        {
            count(Q1, Q2, Q3, Q4, p, q, 1);
            cout<<Q1<<" "<<Q2<<" "<<Q3<<" "<<Q4<<endl;
        }
    }
	return 0;
}

