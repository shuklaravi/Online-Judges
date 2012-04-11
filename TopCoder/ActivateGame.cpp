/////////////////////////////////////////////////////////////////////////////
//                             SRM 470 LEVEL 3 EASY                        //
//                                WRONG ANSWER                             //
/////////////////////////////////////////////////////////////////////////////

// BEGIN CUT HERE

// END CUT HERE
#line 5 "ActivateGame.cpp"
#include <string>
#include <queue>
#include <memory>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;
struct node {
	   int ix,iy,fx,fy,score;
	   node (int a, int b, int c, int d, int e) {
			ix=a;iy=b;fx=c;fy=d;score=e;
			}
	   friend bool operator< (const node &a, const node &b)

			  return (a.score<b.score);
	   		  }
};
class ActivateGame {
	public:
//	int grid[51][51];
	int n,m;
	bool v[51][51];
	vector <string> grid;
	bool is_in(int a, int b)
	{
		 if(a<0 || a>=n || b<0 || b>=m) return false;
//		 if(v[a][b]) return false;
		 return true;
	}
	bool all()
	{
		 for(int i=0;i<n;i++)
		 for(int j=0;j<m;j++)
		 if(!v[i][j]) return false;
		 return true;
	}
	int arg(int a, int b, int c, int d)
	{
		int x,y;
		if(isupper(grid[a][b]))
		x=grid[a][b]-'A'+36;
		else if(islower(grid[a][b]))
		x=grid[a][b]-'a'+10;
		else
		x=grid[a][b]-'0';

		if(isupper(grid[c][d]))
		y=grid[a][b]-'A'+36;
		else if(islower(grid[c][d]))
		y=grid[c][d]-'a'+10;
		else
		y=grid[c][d]-'0';
		
		int i=x-y;
		if(i<0) return -i;
		return i;
	}
	bool wrong (node temp)
	{
		 if(v[temp.x][temp.y]) return true;
		 return false;
	}
	int dfs(int ix,int iy)
	{
		priority_queue <node> s;
		node parent(ix,iy,0);
		s.push(parent);
		int dx[4]={0,1,0,-1};
		int dy[4]={1,0,-1,0};
		int score=0;
		for(int i=0;i<n-1;i++)
		{
				for(int j=0;j<n-1;j++)
				{
						for(int k=0;k<2;k++)
						{
								int xx=i+dx[i]; int yy=j+dy[i];
//								if(!is_in(xx,yy)) continue;
								int temp=arg(i,j,xx,yy);
								s.push( node (i,j,xx,yy,(temp)));
						 		}
				 		}
		 		}
		for(int i=0;i<n-1;i++)
		{
				int temp=arg(i,n-1,i+1,n-1);
				s.push( node (i,n-1,i+1,n-1,(temp)));
				int temp=arg(n-1,i,n-1,i+1);
				s.push( node (n-1,i,n-1,i+1,(temp)));
		 		}
		while(all())
		{
					node t=s.top();
					t.pop();
					
		 			}
		{
					node t=s.pop();
					if(v[t.ix][t.iy]==true && v[t.fx][t.fy]==false)
		 			}
		
		while(!s.empty())
		{
						 node t=s.top();
						 s.pop();
						 cout<<"popped\n";
						 if(wrong(t)) continue;
                         score+=t.score;
//                         cout<<"xxxxxxx";
						 if(all()) return score;
//						 cout<<"xxxxxxx";
						 int xx=-1,yy=-1;
						 for(int i=0;i<4;i++)
						 {
								 xx=t.x+dx[i];
								 yy=t.y+dy[i];
                                 cout<<xx<<" "<<yy<<" "<<v[xx][yy]<<endl;
								 if(!is_in(xx,yy)) continue;
								 int temp=arg(t.x,t.y,xx,yy);
						 		 s.push( node (xx,yy,t.score+(temp)));
						 		 cout<<"pushed "<<xx<<" "<<yy<<" "<<t.score+(temp)<<endl;
		 				 }
		 				 v[t.x][t.y]=true;
 					 }
	   return score;
	}
	int findMaxScore(vector <string> g) {
//		memset(grid,0,sizeof(grid));
		grid=g;
		memset(v,0,sizeof(v));
//		n=grid.size();
//		m=grid[0].size();
		n=m=2;
		return dfs(0,0);
	}
};
