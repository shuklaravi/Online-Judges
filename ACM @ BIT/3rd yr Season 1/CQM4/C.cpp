
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
    int i,j,k,m,M,ipos,pos,q,bit;
    long long d,D;
    
    int zero,one;
    string str;
    int arr[51];
    while(cin>>str)
    {
        MEM(arr,-1);
        cin>>M>>D;
        zero=0;
        
        one=0;
        m=M; d=D;
        while(m--)
        {
            int t=D%2;
            D=D>>1;
            if(t==1)one++;
            else zero++;
        }
        
        if(str=="North") ipos=1;
        if(str=="East") ipos=0;
        if(str=="South") ipos=3;
        if(str=="West") ipos=2;
        int rel=zero-one;
        
        rel%=4;
        if(rel==-1)
        rel=3;
        else if(rel==-2)
        rel=2;
        else if(rel==-3)
        rel=1;
        pos=ipos+rel;
        pos%=4;
        if(pos==0) cout<<"East\n";
        if(pos==1) cout<<"North\n";
        if(pos==2) cout<<"West\n";
        if(pos==3) cout<<"South\n";
//        cout<<pos<<endl;
    }
//	system("pause"); //Windows Only
	return 0;
}

