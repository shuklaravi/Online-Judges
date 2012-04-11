// BEGIN CUT HERE

// END CUT HERE
#line 5 "Marketing.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
class Marketing {
	public:
	bool dfs(vector<int> *adj, vector<int> &state, int n, int s)
	{
//		 cout<<"recursed to "<<n<<" whose state is "<<state[n]<<endl;
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
	long long howMany(vector <string> compete) {
		 vector<int> adj[compete.size()];
		 vector<int> state(compete.size(),0);
		 int i,j;
		 for(i=0;i<compete.size();i++)
		 {
									  stringstream ss(compete[i]);
									  while(ss>>j)
									  {
												  adj[i].push_back(j);
												  adj[j].push_back(i);
						   			  }
		 }
		 long long res=0;
		 for(i=0;i<compete.size();i++)
		 {
                                      if(state[i]==0)
		 							  {
  							   				   if(dfs(adj, state, i, 1)==false)
									   				   return -1;
									   				   res++;
													   }
         }
//         cout<<".."<<res<<endl;
         return 1<<res;
 }
};
int main()
{
    Marketing d;
    int N;
    while(cin>>N)
    {
		vector<string> arr;
		string s;
		while(N--)
		{
			cin>>s;
			arr.push_back(s);
		}
		cout<<d.howMany(arr);
	}
	return 0;
}
