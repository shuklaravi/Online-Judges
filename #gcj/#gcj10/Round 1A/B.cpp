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
		  int D,I,M,N;
		  char pix[105],grid[105][105];
		  while(test--)
		  {
					   cin>>D>>I>>M>>N;
					   bool for_M;
					   for(int i=0;i<N;i++)
					   cin>>pix[i];
					   int opt[3];
					   for(int i=1;i<=N;i++)
					   {
							   for(int j=1;j<=N;j++)
							   {
//									   if(pix[i-1]==pix[j-1])
//									   grid[i][j]=min(min(grid[i][j-1],grid[i-1][j]),grid[i-1][j-1]),continue;
									   int diff=pix[i-1]-pix[j-1]>0?pix[i-1]-pix[j-1]:-pix[i-1]+pix[j-1];
									   if(diff>M)
									   {
                                                              opt[0]=grid[i-1][j]+D;
                                                              opt[1]=grid[i-1][j]+I*(diff/M);
															  opt[2]=diff-M;
															  grid[i][j]=opt[0]
															  for(int k=1;k<3;k++)
															  if(opt[k]<grid[i][j])
															  grid[i][j]=opt[k];
															  }
							   		   }
									   }

		   			   }
return 0;
}
