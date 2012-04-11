// #define TRUE FALSE .. haha now debug this..:D

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

int main()
{
    int i,j,k,p,q,test,total,count,c;
    bool log[2000];
    scanf("%d",&test);
    while(test--)
    {
        MEM(log,0);
        total=0;
        c=0;
        scanf("%d",&p);
        count=0;
        REP(i,p)
        {
            scanf("%d",&q);
            log[q]=!log[q];
            total=max(total,q);
        }
        if(p==1)
        {
            printf("Alice\n");
            continue;
        }
        for(i=total;i>=2;i--)
        {
            if(log[i]==true)
            {

                for(j=i-1;j>=1;j--)
                {
                    if(log[j]==true)
                    {
                        log[i]=!log[i];
                        log[j]=!log[j];
                        log[i-j]=!log[i-j];
                        if(i-j==1) log[1]=0;
                        count++;
                        REP(k,total+1){
                            cout<<k<<":"<<log[k]<<" , ";
                        }
                        cout<<"\n";
                        break;
                    }
                }
            }
        }
        FOR(i,1,total+1){

            if(log[i])
            {
                count++; //7             55 66 99 88 77 105 11
            }
        }
//        cout<<count<<" "<<c<<"\n";
        if(count%2) printf("Alice\n");
        else printf("Bob\n");
//        if( ((count%2)  && !(c%2)) || (count==0 && p==1) ) printf("Alice\n");
//        else printf("Bob\n");
    }
//	system("pause"); //Windows Only
	return 0;
}





// test
// 5 3 8 11 10 5


















