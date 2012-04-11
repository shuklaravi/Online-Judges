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
using namespace std;
struct node {
	   char *path;
	   node *sub[105];
	   int no_sub;
	   };
int main()
{
	node root;
	root.path="/";
	root.no_sub=-1;
	int test;
	cin>>test;
	int N,M;
	while(test--)
	{
				 cin>>N>>M;
				 char str[105];
				 char * pch;
				 for(int i=0;i<N;i++)
				 {
						 cin>>str;
						 pch = strtok (str,"/");
						 int x=0;
						 node *temp=&root;
  						 while (pch != NULL)
  						 {
							   while(x<=temp->no_sub && strcmp(temp->sub[x++]->path,pch)!=0);
							   cout<<x<<" "<<temp->no_sub+1<<endl;
							   if(x!=temp->no_sub+1)
							   temp=temp->sub[x-1];
							   else
							   break;
						  	   pch = strtok (NULL, "/");
  							   }
						  while(pch!=NULL)
						  {
                                          cout<<++temp->no_sub;
						   				  temp->sub[temp->no_sub]=new node();
										  temp->sub[temp->no_sub]->path=pch;
						   				  temp=temp->sub[temp->no_sub];
                                          pch = strtok (NULL, "/");
                                          cout<<pch<<endl;
          								  }
						  }
						  cout<<root.no_sub<<"\n";
		  		 }
return 0;
}
