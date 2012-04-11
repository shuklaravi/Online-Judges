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
    int test,i,k,p,q,j;
    cin>>test;
    while(test--)
    {
        int n,m;
        cin>>n>>m;
        int notes[n];
        REP(i,n)
        cin>>notes[i];
        sort(notes);
        bool avail[m];
        MEM(avail,false);
        avail[0] = true;
        for (i = 0; i < n; i++)
            for (int j = m; j >= notes[i]; j--)
                if (avail[j - notes[i]]) avail[j] = true;
        if(avail[m]) cout<<"Yes\n";
        else cout<<"No\n";
    }
	system("pause"); //Windows Only
	return 0;
}

