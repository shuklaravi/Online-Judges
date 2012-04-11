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
LL arr[10000][10000];
bool pos[10000][10000];
LL a[1000000];
int main()
{
    
    LL test;
    scanf("%lld",&test);
    while (test--) {
        LL size;
        scanf("%lld",&size);
      //  MEM(arr,0);
        //MEM(a,0);
        //MEM(pos,false);
        bool put=false;
           LL i,j;
        REP(i,size) {
            bool add=put;
            REP(j,size) {
                pos[i][j]=add;
                add=!add;
            }
            put=!put;
        }
        
     
        REP(i,size*size) {
            scanf("%lld",&a[i]);
        }

            for ( i = 0; i < size; i++)
            for ( j = 0; j < size; j++) {
                cout<<(size*size)*i+j+1<<" ";
             //   arr[i][j] = a[ (size*size)*i + j];
            }
            
            cout<<endl;
            for ( i = 0; i < size; i++) {

            for ( j = 0; j < size; j++)
            cout<<arr[i][j]<<" ";
            cout<<endl;
        }
            LL cases;
            scanf("%lld",&cases);
            while (cases--) {
                LL r1,c1,r2,c2;
                scanf("%lld%lld%lld%lld",&r1,&c1,&r2,&c2);
                LL sumblack=0,sumwhite=0;
                FOR_ ( i,r1,r2) {
                    FOR_ (j,c1,c2){
                        if (pos[i][j]==false) {
                            sumwhite+=arr[i][j];
                        }
                        else sumblack+=arr[i][j];
                    }
                }
                LL ret;
                ret=min(sumwhite,sumblack);
                printf("%lld\n",ret);
            }
    }






	return 0;
}
