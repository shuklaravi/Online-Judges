/*
ID: vermapr1
PROG: <prog_name>
LANG: C++
*/

// #define TRUE FALSE haha now debug this
using namespace std;
#include <iostream>
#include <string>

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

typedef long long       LL;

//END_TEMPLATE_BY_PRATYUSH_VERMA
string arr[20];
void process(int i)
{
    arr[i]="(";
    int j;
    FOR(j,0,i)
    arr[i]+=arr[j];
    arr[i]+=")";
//    cout<<i<<" "<<arr[i].length()<<endl;
//    getchar();
}
int main()
{
    int t,n,i,j,k,l,m;
    cin>>t;
    arr[0]="()";
    FOR(i,1,16)
    process(i);
//    cout<<arr[3];
    while(t--)
    {
        cin>>k>>l>>m;
        if(k>15)
        cout<<arr[15].substr(l-1,m)<<endl;
        else
        cout<<arr[k].substr(l,m)<<endl;
    }
//	system("pause");
	return 0;
}














