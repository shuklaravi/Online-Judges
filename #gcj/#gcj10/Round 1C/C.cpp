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
string ip(string s)
{
	   int l=s.length();
	   string ret="";
	   for(int i=0;i<l;i++)
	   {
			   if(s[i]=='0') ret+="0000";
			   else if(s[i]=='1') ret+="0001";
			   else if(s[i]=='2') ret+="0010";
			   else if(s[i]=='3') ret+="0011";
			   else if(s[i]=='4') ret+="0100";
			   else if(s[i]=='5') ret+="0101";
			   else if(s[i]=='6') ret+="0110";
			   else if(s[i]=='7') ret+="0111";
			   else if(s[i]=='8') ret+="1000";
			   else if(s[i]=='9') ret+="1001";
			   else if(s[i]=='A') ret+="1010";
			   else if(s[i]=='B') ret+="1011";
			   else if(s[i]=='C') ret+="1100";
			   else if(s[i]=='D') ret+="1101";
			   else if(s[i]=='E') ret+="1110";
			   else if(s[i]=='F') ret+="1111";
	   		   }
	  return ret;
 	   }
int main()
{
	int T,M,N;
	cin>>T;
	while(T--)
	{
			  cin>>M>>N;
			  vector<string> board;
			  vector<vector<int> > coX(M, vector<int> (N) );
			  vector<vector<int> > coY(M, vector<int>(N) );
              string ss;
			  
			  for(int i=0;i<M;i++)
			  {
					  cin>>ss;
					  board.push_back(ip(ss));
					  }
              for(int i=0;i<M;i++)
			  {for(int j=0;j<N;j++)
			  cout<<board[i][j];
			  cout<<endl;
			  }
			  cout<<"....................................\n";
//  					  memset(v,false,sizeof(v));
			  for(int i=0;i<M;i++)
			  {
					  for(int j=0;j<N;j++)
					  {
//							  cout<<i<<" "<<j<<endl;
							  if(j!=0)
							  {
							   		  if(board[i][j]!=board[i][j-1])
							   		  coX[i][j]=coX[i][j-1]+1;
							   		  else coX[i][j]=0;
									  }
							  else coX[i][j]=0;
							  if(i!=0)
							  {
                                      if(board[i][j]!=board[i-1][j])
                                      coY[i][j]=coY[i-1][j]+1;
                                      else coY[i][j]=0;
									  }
							  else coY[i][j]=0;
					   		  }
			   		  }
			  for(int i=0;i<M;i++)
			  {for(int j=0;j<N;j++)
			  cout<<coX[i][j];
			  cout<<endl;
			  }
			  cout<<"......................................\n";
              for(int i=0;i<M;i++)
			  {for(int j=0;j<N;j++)
			  cout<<coY[i][j];
			  cout<<endl;
			  }
			  for(int i=0;i<M;i++)
			  {
					  for(int j=0;j<N;j++)
					  {
							  if(coX[i][j]==0)
							  
					   		  }
							  }
			  }
return 0;
}
