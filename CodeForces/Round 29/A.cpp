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
typedef long long ll;
inline string i2s(int number) { stringstream ss; ss << number; return ss.str(); }
//END_TEMPLATE_BY_PRATYUSH_VERMA

struct node{
    int e;
    int s;
    node(int a, int b) {
        e=a; s=b;
    }
};
int main()
{
    vector<node> v;
    int n;
    cin>>n;
    int i,k,j,p,q;
    REP(i,n)
    {
        cin>>p>>q;
        PB(v, node (p,p+q));
    }
    FOREACH(x,v)
    {
        FOREACH(xx,v)
        {
            if(x==xx) continue;
            if((*x).s==(*xx).e && (*xx).s==(*x).e)
            {
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
//	system("pause"); //Windows Only
	return 0;
}
