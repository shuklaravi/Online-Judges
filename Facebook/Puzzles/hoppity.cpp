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
int main()
{
	int n;
	while(cin>>n)
	{
				 int arr[n];
				 memset(arr,0,sizeof(arr));
				 int x=3;
				 while(x<=n)
				 {
							arr[x]=1;
							x+=3;
				  			}
				 x=5;
                 while(x<=n)
				 {
							if(arr[x]==1) arr[x]=3;
							else arr[x]=2;
							x+=5;
				  			}
				 for(int i=1;i<=n;i++)
				 {
						 if(arr[i]==1) cout<<"Hoppity\n";
						 else if(arr[i]==2) cout<<"Hophop\n";
						 else if(arr[i]==3) cout<<"Hop\n";
				  		 }
	 			 }
return 0;
}
