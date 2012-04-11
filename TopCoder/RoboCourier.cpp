// BEGIN CUT HERE

// END CUT HERE
#line 5 "RoboCourier.cpp"
#include <string>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
struct node {
	   int X,Y,Z,t,p;
	   node (int a, int b, int c, ind d, int e) {
			X=a;Y=b;Z=c;t=d;p=e;
			}
	   friend bool operator< (const struct &a, const struct &b) {
			  if(a.t!=b.t) return (a.t)>(b.t);
			  if(a.t==b.t) return a.e==2;
			  return false;
	   		  }
	   friend bool operator== (const struct &a, const struct &b) {
			  return (a.X==b.X && a.Y==b.Y);
	   		  }
	   };
class RoboCourier {
	public:
    bool grid[600][600];
    bool visited[600][600][6];
    int bfs(int sx,int sy, int fx, int fy)
    {
        int dir[6]={0,1,2,3,4,5};
        int dx[]={-2,-1,+1,+2,+1,-1};
        int dy[]={0,+1,+1,0,-1,-1};
		priority_queue <node> q;
		node parent(sx,sy,0,0,0);
		node final(fx,fy,0,0,0);
		q.push(parent);
		q.push(node (sx,sy,1,0,0));
		q.push(node (sx,sy,5,0,0));
		if(grid[sx+2][sy]==1)
		q.push(node (sx+2,sy,0,0,1));
		while(!q.empty())
		{
						 node temp=q.front();
						 q.pop();
						 if(temp==final) return temp.t+3;
						 if(visited[temp.X][temp.Y][temp.Z]) continue;
						 q.push(node(temp.X,temp.Y,temp.Z,temp.t+3+(temp.p==1),0));
						 q.push(node(temp.X,temp.Y,temp.Z+1,temp.t+4,1));
	}
	int timeToDeliver(vector <string> path) {
		memset(visited,false,sizeof(visited));
		memset(grid,false,sizeof(grid));
		int i,j,x=300,y=300,d=0;
		grid[x][y]=1;
		for(i=0;i<path.size();i++)
		{
								  for(j=0;j<path[i].length();j++)
								  {
																 if(path[i][j]=='F' && d==0 ) grid[x-2][y]=1,x-=2;
																 else if(path[i][j]=='F' && d==1) grid[x-1][y+1]=1,x--,y++;
																 else if(path[i][j]=='F' && d==2) grid[x+1][y+1]=1,x++,y++;
																 else if(path[i][j]=='F' && d==3) grid[x+2][y]=1,x+=2;
																 else if(path[i][j]=='F' && d==4) grid[x+1][y-1]=1,x++,y--;
																 else if(path[i][j]=='F' && d==5) grid[x-1][y-1]=1,x--,y--;
																 else if(path[i][j]=='R') d=(d+1)%6;
																 else if(path[i][j]=='L') d=(d-1)%6;
								   								 }
		 						  }
		cout<<bfs(300,300,i,j);
	}
};
