
///////////////////////////////////////////////////////////////////////////////
//                  CAN BE IMPLEMENTED USING DP AND DIJKSTRA                 //
///////////////////////////////////////////////////////////////////////////////


// DIJKSTRA SOLUTION

#line 5 "KiloManX.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
struct node {
	   int gun,shot;
	   node (int a, int b) {
            shot=a;
			gun=b;
			}
       friend bool operator<(const node &a, const node &b) {
 	   		return a.shot > b.shot;
// 			return false;
			}
	   };
class KiloManX {
	public:
	bool visited[1<<16];
	int leastShots(vector <string> dc, vector <int> bh) {
		node parent(0,0);
		int i,j,n=1<<bh.size(),nn=bh.size();
		memset(visited,false,sizeof(visited));
//		priority_queue<pair<int,int> > pq;
//	    pq.push(make_pair(0,0));
	    priority_queue<node> pq;
	    pq.push(parent);
	    //cout<<"TARGET "<<(n-1)<<endl;
	    while(!pq.empty())
	    {
						  node temp=pq.top();
						  pq.pop();
	//					  cout<<"poped from stack "<<temp.shot<<" "<<temp.gun<<endl;
						  if(temp.gun==(n-1)) return temp.shot;
						  if(visited[temp.gun]) continue;
						  visited[temp.gun]=true;
						  
						  for(i=0;i<nn;i++)
						  {
								  if(temp.gun>>i & 1) continue;
								  int min_s=bh[i];
								  for(j=0;j<nn;j++)
								  {
												  if(i==j) continue;
												  if(dc[j][i]!='0' && (temp.gun>>j & 1))
												  {
																   int need=bh[i]/(dc[j][i]-'0');
								    							   if (bh[i] % (dc[j][i] - '0') != 0)
																   need++;
								    							   min_s = min(min_s, need);
												   				   }
								   				  }
//								  cout<<"pushing to stack "<<temp.shot+min_s<<" "<<(temp.gun|1<<i)<<endl;
								  pq.push(node (temp.shot+min_s,temp.gun|(1<<i)));
		 				  }
			  }
		return -1;
  }
};
// Powered by FileEdit





////////////////////////////////////////////
//            DP SOLUTION                 //
////////////////////////////////////////////
#line 120 "KiloManX.cpp"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <set>
#include <list>
#include <vector>
using namespace std;

class KiloManX
{
public:
  int A[(1<<15)+10];
  int leastShots(vector <string> dam, vector <int> bo)
  {
    int n = bo.size();
    memset(A, 10, sizeof(A));
    A[0] = 0;
    for (int i = 0; i < (1<<n); i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (!(i&(1<<j)))
        {
          int ma = 1;
          for (int k = 0; k < n; k++)
          {
            if (i&(1<<k))
            {
              ma = max(ma, dam[k][j]-'0');
            }
          }
          A[i|(1<<j)] = min(A[i|(1<<j)], A[i]+(bo[j]+ma-1)/ma);
        }
      }
    }
    return A[(1<<n)-1];
  }


};
