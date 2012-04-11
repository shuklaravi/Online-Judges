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
//END_TEMPLATE_BY_PRATYUSH_VERMA

int main()
{
    int n;
    vector<TRI> arr;
    int l[5001];
    int r[5001];
    MEM(l,0);
    MEM(r,0);
    cin>>n;
    int  i,j,k,p,q;
    REP(i,n)
    {
        cin>>p>>q;
        l[i]=p;
        r[i]=q;
        PII t = MP(p,i+1);
        TRI tt=MP(q,t);
        PB(arr,tt);
    }
    sort(ALL(arr));
    set<int> nlec;
    set<int> lec;
    int last=arr[0].first;
    lec.insert(0);
    FOR(i,1,n)
    {
        if(arr[i].second.first>=last) lec.insert(i);
        else
        {
            k=arr[i].second.second;
            nlec.insert(i);
        }
    }
    cout<<lec.size()<<" "<<nlec.size()<<endl;
    if(nlec.size()==0)
    {
        cout<<n<<endl;
        REP(i,n)
        cout<<i+1<<" ";
//        return 0;
    }
    else if(nlec.size()==1)
    {
        cout<<"1\n";
        cout<<k;
    }
    else cout<<"0";
    
//	system("pause"); //Windows Only
	return 0;
}




































