// BEGIN CUT HERE

// END CUT HERE
#line 5 "BombMan.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
struct node {
	   int x,y,b,t;
	   node(int a, int bb, int c,int d) {
				x=a;y=bb;b=c;t=d;
	   			}
	   friend bool operator< (const node &a, const node &b)
	   {
			  return (a.t>b.t);
	   		  }
};
class BombMan {
	public:
	int I,J;
	bool grid[55][55];
	bool v[55][55];
	bool is_in(int a, int b)
	{
		 return (a>=0 && a<I && b>=0 && b<J);
 	}
	int djk(int sx,int sy, int dx, int dy, int bob)
	{
		priority_queue <node> p;
		node parent(sx,sy,bob,0);
		p.push(parent);
//		cout<<"......"<<bob<<endl;
		int di[4]={1,-1,0,0};
		int dj[4]={0,0,1,-1};
		while(!p.empty())
		{
						 node t=p.top();
						 p.pop();
//						 cout<<"popped "<<t.x<<" "<<t.y<<" "<<t.b<<" "<<t.t<<endl;
						 v[t.x][t.y]=true;
						 if(t.x==dx && t.y==dy) return t.t;
						 for(int i=0;i<4;i++)
						 {
								 int xx=t.x+di[i]; int yy=t.y+dj[i];
								 if(!is_in(xx,yy)) continue;
								 if(v[xx][yy]) continue;
								 if(grid[xx][yy]) p.push(node (xx,yy,t.b,t.t+1));
								 else if(t.b-1>=0)
									   			  p.push(node (xx,yy,t.b-1,t.t+3));
							  }
				  		 }
	   return -1;
	}
	int shortestPath(vector <string> maze, int bombs) {
		memset(grid, false, sizeof(grid));
		memset(v, false, sizeof(v));
		int i,j,sx=-1,sy=-1,dx=-1,dy=-1;
		I=maze.size();
		J=maze[0].size();
		for(i=0;i<maze.size();i++)
		for(j=0;j<maze[i].length();j++)
		{
									   if(maze[i][j]!='#') grid[i][j]=true;
									   if(maze[i][j]=='B') sx=i,sy=j;
									   if(maze[i][j]=='E') dx=i,dy=j;
		 							   }
//		cout<<sx<<" "<<sy<<" "<<dx<<" "<<dy<<endl;
		return djk(sx,sy,dx,dy,bombs);
	}
};
