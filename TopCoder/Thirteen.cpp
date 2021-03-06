// BEGIN CUT HERE

// END CUT HERE
#line 5 "Thirteen.cpp"
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
using namespace std;
struct node
{
	int x,t;
	node(int a, int b)
	{
		x=a;t=b;
	}
	friend bool operator< (const node &a, const node &b)
	{
		return (a.t>b.t);
	}
};
class Thirteen {
	public:
		int bfs(int final, map<int, vector<int> > m)
		{
			priority_queue<node> q;
			node parent(0,0);
			q.push(parent);
			bool vis[50][13];
			memset(vis, false, sizeof(vis));
			while(!q.empty())
			{
				node t=q.top();
				q.pop();
				vis[t.x][t.t%13]=true;
				if(t.x==final) return t.t;
				for(int i=0;i<m[t.x].size();i++)
				{
					if(m[t.x][i]==-1) continue;
					if((t.t+m[t.x][i])%13==0) continue;
					if(vis[i][(t.t+m[t.x][i])%13]) continue;
					q.push(node (i,t.t+m[t.x][i]));
				}
			}
			return -1;
		}
	int calcTime(vector <string> city) {
		map<int, vector<int> > adj;
		for(int i=0;i<city.size();i++)
		{
			for(int j=0;j<city[0].length();j++)
			{
				if(city[i][j]=='#') adj[i].push_back(-1);
				else if(islower(city[i][j])) adj[i].push_back(city[i][j]-'a'+27);
				else if(isupper(city[i][j])) adj[i].push_back(city[i][j]-'A'+1);
			}
		}
		return bfs(city.size()-1,adj);
	}
};
