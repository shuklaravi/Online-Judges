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
    //freopen("B_new1.in" , "r" , stdin);
    //freopen("B_new1.txt" , "w" , stdout);
	int C,N,K,B,T;
	cin>>C;
	int no=0;
	while(C--)
	{
			  cin>>N>>K>>B>>T;
			  int X[N],V[N];
			  bool R[N];
			  for(int i=0;i<N;i++)
			  cin>>X[i];
              for(int i=0;i<N;i++)
			  cin>>V[i];
			  int reach=0;
			  int idx[N];
			  int p=0;
			  for(int i=0;i<N;i++)
			  {
					  if(V[i]*T+X[i]>=B)
					  R[i]=1,reach++,idx[p++]=i;
					  else
					  R[i]=0;
			   		  }
/*			  for(int i=0;i<N;i++)
			  cout<<R[i]<<" ";
			  cout<<endl;
*/			  if(reach<K)
			  {
			   			 cout<<"Case #"<<++no<<": "<<"IMPOSSIBLE\n";
						 continue;
						 }
			  int x=N-1;
			  while(R[x--]==1) p--;
              x++;
			  int remain=K-(N-1-x);
//			  cout<<"....."<<remain<<endl;
			  int swaps=0;
			  int j;
			  for(int i=x;i>=0 && remain--;i--)
			  {
					  for(j=i-1;j>=0;j--)
					  if(R[j]==1) break;
					  swaps+=i-j;
			   		  }
			  cout<<"Case #"<<++no<<": "<<swaps<<endl;
			   }
return 0;
}
