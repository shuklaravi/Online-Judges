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
#define INF (1<<31)-1
#define REP(i,a) for((i)=0;(i)<(a);(i)++)
#define FOR(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define VAR(V,init) __typeof(init) V=(init)
#define FOREACH(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((int)(x.size()))
#define LENGTH(x) ((int)(x.length()))
#define SZ(x) sizeof(x)
#define MEM(m,i) memset((m),(i),SZ(m))
#define PB(x,y) (x).push_back(y)
#define MP(x,y) make_pair(x,y)
typedef long long ll;
inline string i2s(int number) { stringstream ss; ss << number; return ss.str(); }
//END_TEMPLATE_BY_PRATYUSH_VERMA
ll arr[1000000];
ll max(ll a, ll b)
{
    if(a>b)
    return a;
    return b;
}
ll func(ll i)
{
    if(i<1000000) return arr[i];
    return max(i,func(i/2)+func(i/3)+func(i/4));
}
int main()
{
    int i,k,j,p,q;
    arr[0]=0;
    arr[1]=1;
    arr[2]=2;
    arr[3]=3;
    arr[4]=4;
    FOR(i,5,1000000)
    arr[i]=max(arr[i/4]+arr[i/2]+arr[i/3],i);
    int no;
    while(scanf("%d",&no)!=EOF)
    {
        if(no<1000000) printf("%lu\n",arr[no]);
        else printf("%lu\n",func(no));
    }
//	system("pause"); //Windows Only
	return 0;
}

