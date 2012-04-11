//DS includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<bitset>
#include<complex>

//Other Includes
#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

#define oo 				0xBADC0DE
#define s(n)			scanf("%d",&n)
#define sl(n) 			scanf("%lld",&n)
#define sf(n) 			scanf("%lf",&n)
#define fill(a,v) 		memset(a, v, sizeof a)
#define ull 			unsigned long long
#define ll 				long long
#define bitcount 		__builtin_popcount
#define all(x) 			x.begin(), x.end()
#define pb( z ) 		push_back( z )
#define gcd				__gcd
using namespace std;

const int mxn = 10007;
vector<int> adj[mxn], ra[mxn];;
set<int> neigh[mxn];
int vis[mxn], vid;
int val[mxn], outdeg[mxn];

int main(){
	int t;
	s(t);
	while (t--) {
		int n, m;
		s(n); s(m);
		for(int i=1; i <= n; i++)
		{
			adj[i].clear(); neigh[i].clear(); ra[i].clear();
			outdeg[i] = 0;
			val[i] = -1;
		}
		while (m--) {
			int f, t;
			s(f); s(t);
			if (neigh[f].count(t)) continue;
			neigh[f].insert(t);
			adj[f].pb(t);  ra[t].pb(f); outdeg[f]++;
		}
		vid++;
		queue<int> q;
		for(int i=1; i <= n; i++)
		if (adj[i].size()==0) {
			q.push(i);
			val[i] = 1;
			vis[i] = vid;
		}
		bool cycle = false;
		while (q.size() > 0) {
			int z = q.front(); q.pop();

			for(int i=0; i < ra[z].size(); i++) {
				int vi = ra[z][i];
				val[vi] = max( val[vi], 1 + val[z] );
				if (--outdeg[vi] == 0) {
					q.push(vi);
					vis[vi] = vid;
				}
			}
		}
		int ans = 0;
		for(int i=1; i <= n; i++)
		if (vis[i] != vid) cycle = true;
		else ans = max( ans, val[i] );

		if (cycle)
			printf("IMPOSSIBLE\n");
		else
			cout<<ans<<endl;

	}
	return 0;
}
