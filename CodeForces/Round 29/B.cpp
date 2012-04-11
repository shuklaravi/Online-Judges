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

int main()
{
    int l,d,g,v,r,p,q,i,j,k;
    cin>>l>>d>>v>>g>>r;
    double t_to_l=(double)d/(double)v;
//    cout<<"t_to_l = "<<t_to_l<<endl;
    double cycle=r+g;
//    cout<<"cycle = "<<cycle<<endl;
    for(;cycle<=t_to_l;cycle=cycle+(r+g));
    cycle-=(r+g);
//    cout<<"cycle = "<<cycle<<endl;
    double rem=t_to_l-cycle;
//    cout<<"rem = "<<rem<<endl;
    if(rem<g || cycle)
    {
        printf("%.8lf",(double)l/(double)v);
        return 0;
    }
    else
    {
        printf("%.8lf",(double)((double)l/(double)v)+(double)(r+g)-(double)rem);
        return 0;
    }
	system("pause"); //Windows Only
	return 0;
}

