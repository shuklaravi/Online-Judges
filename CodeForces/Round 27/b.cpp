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

int main()
{
    int no;
    cin>>no;
    int arr[no+1],c[no+1];
    MEM(arr,0);
    MEM(c,0);
    int si,sz=(no*(no-1)-1)/2.0,i,j;
    si=no-1;
    while(sz--)
    {
        cin>>i>>j;
        arr[i]++;
        c[i]++; c[j]++;
    }
    int I=-1,J=-1;
    FOR(i,1,no+1)
    {
        if(c[i]==si) continue;
        if(I==-1) I=i;
        else J=i;
    }
    if(arr[I]>arr[J]) cout<<I<<" "<<J;
    else
    cout<<J<<" "<<I;
	return 0;
}

