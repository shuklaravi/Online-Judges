/*
ID: your_id_here
PROG: test
LANG: C++
*/

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
#define FORN(i,xx) for(i=0;i<(xx);i++)
using namespace std;
struct node {
	int x,tl;
	node(int a, int b) {
		x=a;tl=b;
	}
};
int dfs(int ss, int ttl, map<int, vector<int> > m)
{
	set<int> v;
	set<int>::iterator it;
	queue<node> s;
	node parent(ss,ttl);
	s.push(parent);
	int i;
	while(!s.empty())
	{
		node t=s.front();
		s.pop();
		v.insert(t.x);
		FORN(i,m[t.x].size())
		{
			it=v.find(m[t.x][i]);
			if((t.tl-1)>-1 && it==v.end())
			{
				s.push(node (m[t.x][i],t.tl-1));
			}
		}
	}
	return v.size();
}
int main()
{
ios_base::sync_with_stdio(0);
int NC,x,y,i,j,no=0;
while(cin>>NC && NC)
{
 	map<int, vector<int> > dic;
	int adj[35][35];
	string s;

	FORN(i,NC)
	{
		cin>>x>>y;
  		dic[x].push_back(y);
  		dic[y].push_back(x);
	}
	int nodes=dic.size();
	while(cin>>x>>y && (x || y))
	{
		int vv=dfs(x,y,dic);
        cout<<"Case "<<++no<<": "<<nodes-vv<<" nodes not reachable from node "<<x<<" with TTL = "<<y<<".\n";
	}
}
return 0;
}
