// BEGIN CUT HERE

// END CUT HERE
#line 5 "Circuits.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <sstream>
using namespace std;
struct node{
	   int dist, now;
	   node(int a, int b)
	   {
				dist=a;
				now=b;
	   			}
	   };
class Circuits {
	public:
 	int dfs(vector<int> *adj, vector<int> *cost,int n)
 	{
		stack<node> s;
		node parent(0,n);
		s.push(parent);
		int i,j;
		int max=-1;
		while(!s.empty())
		{
						 node temp=s.top();
						 s.pop();
						 if(max<temp.dist)
						 max=temp.dist;
						 for(i=0;i<adj[temp.now].size();i++)
						 {
						  								  node t(temp.dist+cost[temp.now][i],adj[temp.now][i]);
						  								  s.push(t);
														  }
		 				 }
	   return max;
	}
	int howLong(vector <string> connects, vector <string> costs) {
		vector<int> adj[connects.size()];
		vector<int> cost[costs.size()];
		int i,j;
		int P,Q;
		for(i=0;i<connects.size();i++)
		{
									  stringstream ss(connects[i]);
									  stringstream sss(costs[i]);
									  while(ss>>P)
									  {
												  sss>>Q;
												  adj[i].push_back(P);
												  cost[i].push_back(Q);
						   			  }
	    }
	    vector<int> dist;
	    for(i=0;i<connects.size();i++)
	    {
									  int temp=dfs(adj,cost,i);
									  dist.push_back(temp);
		 							  }
		sort(dist.begin(),dist.end());
		return dist[dist.size()-1];
	}
};
