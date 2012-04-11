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
int main()
{
	int test;
	cin>>test;
	int N,K;
	while(test--)
	{
				 cin>>N>>K;
				 char grid[N+1][N+1];char gridR[N+1][N+1];
				 for(int i=0;i<N;i++)
				 for(int j=0;j<N;j++)
				 cin>>grid[i][j];
				 for(int i=0;i<N;i++)
				 for(int j=0;j<N;j++)
				 gridR[j][i]=grid[i][j];
				 for(int i=0;i<N;i++)
				 for(int j=0;j<N;j++)
				 {
						 if()
				  		 }
				 for(int j=0;j<N;j++)
				 {
						 int count=0;
						 int R=0,B=0;
						 for(int i=0;i<N;i++)
						 {
								 if(grid[i][j]=='.') continue;
								 if(grid[i][j]=='R') R++,B=0;
								 if(grid[i][j]=='B') B++,R=0;
								 if(R==K || B==K) break;
						  		 }
				  		 if(R==K || B==K) break;
						 int RR=0,BB=0;
                         for(int i=0;i<N;i++)
						 {
								 if(grid[i][j]=='.') RR=0,BB=0
								 if(grid[i][j]=='R') R++,B=0;
								 if(grid[i][j]=='B') B++,R=0;
								 if(R==K || B==K) break;
						  		 }
                         if(R==K || B==K) break;
				  		 }
                 if(R==K)	cout<<"Red\n",continue;
				 if (B==K) cout<<"Blue\n",continue;
				 for(int d=1;d<=2*N-1;d++)
				 {
				  		 int height=1+max(0,d-N);
						 int pcount=min(d,N-height+1);
						 for(int j=0 j<=pcount;j++)
						 {
								 int x=min(m,d)-j;
								 int y=height+j;

								 }
								 }
	 			 }
return 0;
}
