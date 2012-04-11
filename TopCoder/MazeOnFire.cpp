// BEGIN CUT HERE

// END CUT HERE
#line 5 "MazeOnFire.cpp"
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
struct node {
	int x,y,t;
	node (int a, int b, int c) {
		x=a;y=b;t=c;
	}
};
class MazeOnFire {
	public:
	bool is_in(int a, int b)
	{
		if(a<0 || a>=n || b<0 || b>=m) return false;
		return true;
	}
	int m,n;
	int maximumTurns(vector <string> maze) {
		n=maze.size();
		m=maze[0].length();
		int sx=0,sy=0;
		int grid[55][55];
		bool v[55][55]={false};
		queue<node> q;
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(maze[i][j]=='F')
			{
				grid[i][j]=0;
				q.push(node (i,j,0));
			}
			else if(maze[i][j]=='$')
			{
				sx=i,sy=j;
				grid[i][j]=-5;
			}
			else if(maze[i][j]=='#')
			{
				grid[i][j]=-1;
				v[i][j]=true;
			}
			else
			grid[i][j]=-5;
		}
		int dx[4]={0,0,1,-1};
		int dy[4]={1,-1,0,0};
		while(!q.empty())
		{
			node t=q.front();
			q.pop();
			if(grid[t.x][t.y]>t.t || grid[t.x][t.y]<0)
			grid[t.x][t.y]=t.t;
			for(int i=0;i<4;i++)
			{
				int xx=t.x+dx[i]; int yy=t.y+dy[i];
				if(!is_in(xx,yy)) continue;
				if(grid[xx][yy]!=-5) continue;
				q.push(node (xx,yy,t.t+1));
			}
		}
		//"....#.", "$##.#.", ".#..#F", ".F#.#.", "..#..."
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			cout<<grid[i][j]<<" ";
			cout<<endl;
		}
		stack<node> s;
		s.push(node (sx,sy,0));
		int max=-1;
		while(!s.empty())
		{
			node t=s.top();
			s.pop();
			v[t.x][t.y]=true;
			if(t.t<grid[t.x][t.y])
			{
                if(max<grid[t.x][t.y]) {cout<<t.t<<" changed at "<<t.x<<" "<<t.y<<" "<<grid[t.x][t.y]<<endl; max=grid[t.x][t.y]; }
				for(int i=0;i<4;i++)
				{
					int xx=t.x+dx[i]; int yy=t.y+dy[i];
					if(!is_in(xx,yy)) continue;
					if(v[xx][yy]==true) continue;
					s.push(node (xx,yy,t.t+1));
				}
			}
		}
		return max;
	}
};
