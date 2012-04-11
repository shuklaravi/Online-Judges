#include <queue>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define GI ({int _t; scanf("%d", &_t); _t;})
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define REP(i, a) FOR(i, 0, a)
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
#define DBGV(_v) { REP(_i, _v.size()) { cout << _v[_i] << "\t";} cout << endl;}


int main() {
int kase = 0;
while (1) {
int grid[31][31];
REP(i, 31) REP(j, 31) grid[i][j] = 0;
map <int, int> lookup;
int cnt = GI, vcnt = 0;
if (cnt == 0) break;
while (cnt--) {
int v1 = GI, v2 = GI;
if (lookup.find(v1) == lookup.end()) {
lookup[v1] = vcnt;
vcnt++;
}
if (lookup.find(v2) == lookup.end()) {
lookup[v2] = vcnt;
vcnt++;
}
grid[lookup[v1]][lookup[v2]] = grid[lookup[v2]][lookup[v1]] = 1;
}
for (map <int, int>::iterator it = lookup.begin(); it != lookup.end(); it++) {
//cout << it->first << "\t" << it->second << endl;
}
while (1) {
vector <bool> visited(vcnt, false);
vector <int> time (vcnt, 0);
int start = GI, ttl = GI;
int len = ttl;
if (start == 0 && ttl == 0) break;
//Do BFS here
queue <int> q;
q.push(lookup[start]);
time[lookup[start]] = ttl+1;
visited[lookup[start]] = true;
while (!q.empty()) {
int cur = q.front();
//cout << cur << " --> " << time[cur] << endl;
q.pop();
REP(i, vcnt) {
if (grid[cur][i] == 1 && visited[i] == false ) {
q.push(i);
visited[i] = true;
time[i] = time[cur]-1;
}
}
}
int res = 0;
REP(i, vcnt) {
if (time[i] <= 0) res++;
}
//cout << endl;
kase++;
printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", kase, res, start, len);
}
}
return 0;
}
