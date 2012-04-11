// BEGIN CUT HERE

// END CUT HERE
#line 5 "Marketing.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
	bool dfs(vector<int> *adj, vector<int> &state, int n, int s)
	{
	//	 cout<<"recursed to "<<n<<" whose state is "<<state[n]<<endl;
		 if(state[n]!=0) return state[n]==s;
		 state[n]=s;
//		 cout<<"in dfs -- on "<<n<<" whose state is "<<s<<endl;
		 int i,j;
		 for(i=0;i<adj[n].size();i++)
		 {
									 if(dfs(adj, state, adj[n][i], 5-s)==false)
									 return false;
		  							 }
		  return true;
 	}
int main()
{
	int n,l,i,j;
	int x,y;
	while(cin>>n && n!=0)
	{
		 vector<int> adj[n+5];
		 vector<int> state(n+5,0);
		 int i,j;
		 cin>>l;
		 for(i=0;i<l;i++)
		 {
									  cin>>x>>y;
									  {
												  adj[x].push_back(y);
												  adj[y].push_back(x);
						   			  }
		 }
		 bool res=1;
  		 if(dfs(adj, state, 0, 1)==false)
		 		 cout<<"NOT BICOLORABLE.\n";
         else cout<<"BICOLORABLE.\n";
		 }
return 0;
}

