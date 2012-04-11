// BEGIN CUT HERE

// END CUT HERE
#line 5 "TeamBuilder.cpp"
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

class TeamBuilder {
	public:
	vector<int> specialLocations(vector <string> paths) {
		   int n=paths.size();
		   vector <int> count(n,0);
		   vector <int> count1(n,0);
		   int arr[55][55]={0};
//		   memset(arr,0,sizeof(arr));
		   for(int k=0;k<n;k++)
		   for(int i=0;i<n;i++)
		   for(int j=0;j<n;j++)
		   arr[i][j]=min(paths[i][j]-'0',paths[i][k]-'0'+paths[k][j]-'0');
		   for(int i=0;i<n;i++)
		   for(int j=0;j<n;j++)
		   {
		   		   if(arr[i][j]!=0)
		   		   count[i]++;
		   		   else if(arr[j][i]!=0)
		   		   count1[i]++;
		   }
		   vector<int> c;
		   c.push_back(0);
		   c.push_back(0);
		   for(int i=0;i<n;i++)
		   {
		   		   if(count[i]==n)
		   		   c[0]++;
		   		   else if(count1[i]==n)
		   		   c[1]++;
		   }
		   return c;
	}
};
