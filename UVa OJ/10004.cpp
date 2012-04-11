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
#define FORN(i,n) for((i)=0;(i)<(n);(i)++)
using namespace std;
int i;
int dfs(vector<int> *adj,vector<int> adj1,int x, int s)
{
//	cout<<"state "<<x<<" is "<<s<<endl;
	if(adj1[x]!=0) return (adj1[x]!=s);
//	cout<<"1\n";
	adj1[x]=s;
	FORN(i,adj[x].size())
	{
			return dfs(adj,adj1,adj[x][i],3-s);
	 		}
  // cout<<"2\n";
   return false;
}
int main()
{
	int n,l,i,j;
	int x,y;
	while(cin>>n && n!=0)
	{
                 vector<int> adj[n+5];
                 vector<int> adj1(n+5,0);
				 cin>>l;
				 FORN(i,n)
				 {
						 cin>>x>>y;
						 adj[x].push_back(y);
				  		 }
				 FORN(i,n)
				 {
						  					 if(adj1[i]!=0) continue;
											 if(dfs(adj,adj1,i,1)) break;
	 			 }
	 			 if(i!=n) cout<<"NOT BICOLORABLE.\n";
	 			 else cout<<"BICOLORABLE.\n";
				 }
return 0;
}
