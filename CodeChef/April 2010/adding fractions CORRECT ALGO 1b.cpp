/***** Author : Kunal *****/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include <cmath>
#include <cstdio>
#include <queue>
#include <list>
#include <stack>
#include <utility>
#include <numeric>
#include <map>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include <set>

using namespace std;

#define F(a,b) for(int a=0;a<b;a++)
#define REP(a,b) for(int a=0;a<b;a++)
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define FORD(a,b,c) for(int a=b;a>=c;a--)

#define S scanf
#define P printf

#define LEN(x) ((int)x.length())
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(), x.end()
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define INF 1000000000

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<int, PII> PIII;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<string> VS;

//int d[][2]={{-1.0},{1,0},{0,-1},{0,1}};

int A[100001][2];
LL ans[100001][2];
int till[100001];

int main()
{
	int t; S("%d", &t);
	int n;
	int x;
	LL gd;
	while( t-- )
	{
		S("%d", &n );
		REP(i,n) S("%d/%d", &A[i][0], &A[i][1] );

		ans[n-1][0] = A[n-1][0]; ans[n-1][1] = A[n-1][1];
		till[n-1] = n-1;

		FORD(i, n-2, 0 )
		{
			x = i+1;
			ans[i][0] = A[i][0]; ans[i][1] = A[i][1];
			do
			{
				if( ans[i][0]*ans[x][1] <= ans[x][0]*ans[i][1] )
				{
					ans[i][0] += ans[x][0];
					ans[i][1] += ans[x][1];
					x = till[x] + 1;
				}
				else break;
			}while( x < n);
			till[i] = x - 1;
		}
		REP(i,n)
		{
			gd = __gcd(ans[i][0], ans[i][1] );
			P("%lld/%lld\n", ans[i][0]/gd, ans[i][1]/gd );
		}
		puts("");
	}
	return 0;
}
