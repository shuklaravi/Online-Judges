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
bool dfs(map<string, vector<string> > dic, map<string, int> &v, string it, int state)
{

	 if(v[it]!=0) return v[it]==state;
	 v[it]=state;
		 int i,j;
		 for(i=0;i<dic[it].size();i++)
		 {
									 if(dfs(dic, v, dic[it][i],5-state)==false)
									 return false;
		  							 }
		  return true;

}
int main()//int argc, char **argv)
{
// 	freopen(argv[1] , "r" , stdin);
//    freopen("input 1 liarliar.txt" , "r" , stdin);
 	int n,m;
 	cin>>n;
	map<string, vector<string> > dic;
	map<string, vector<string> >::iterator it;
	map<string, int> v;
//	map<string, int>::iterator v;
	string s,ss;
	for(int i=0;i<n;i++)
	{
			cin>>s>>m;
			for(int j=0;j<m;j++)
			{
					cin>>ss;
			 		dic[s].push_back(ss);
			 		dic[ss].push_back(s);
					}
	 		}
	for(it=dic.begin();it!=dic.end();it++)
	{
			v[(*it).first]=0;
			sort((*it).second.begin(),(*it).second.end());
 	        vector<string>::iterator endLocation=unique ((*it).second.begin(), (*it).second.end());
 	        (*it).second.resize( endLocation - (*it).second.begin() );
			pair<string, vector<string> > top=*it;
//			cout<<top.first<<endl;
			for(int j=0;j<top.second.size();j++)
			{
//					cout<<"\t"<<top.second[j]<<endl;
			 		}
			}
	for(it=dic.begin();it!=dic.end();it++)
	{
 	        pair<string, vector<string> > top=*it;
//            string s=*it;
//            cout<<top.first<<endl;
			if(v[(*it).first]==0) cout<<dfs(dic,v,top.first,1)<<endl;
	 		}
   int x=0;
   for(it=dic.begin();it!=dic.end();it++)
   {
   	       
		   if(v[(*it).first]==1) x++;
   		   }
   cout<<max(x,n-x)<<" "<<min(x,n-x)<<endl;
   system("pause");
return 0;
}
