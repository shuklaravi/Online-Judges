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
	int T,N;
	cin>>T;
	while(T--)
	{
			  cin>>N;
			  string arr[N];
			  for(int i=0;i<N;i++)
			  {
					  cin>>arr[i];
			   		  }
			  int swaps=0;
			  for(int j=N-1;j>=0;j--)
			  {
					  for(int i=N-1;i>=0;i--)
					  {
							  if(arr[i][j]=='1' && j>i)
							  {
												cout<<"conflict at "<<i<<" "<<j<<endl;
												swaps+=(j-i);
												swap(arr[i],arr[j]);
												cout<<"swaps = "<<swaps<<endl<<endl;
												}
					   		  }
			   		  }
			  cout<<swaps<<endl;
	 		  }
return 0;
}
