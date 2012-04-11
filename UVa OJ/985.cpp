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
struct node {
	int x,y,t;
	node(int a, int b,int c) {
		x=a;y=b;t=c;
	}
};
int R,C;
int grid[505][505][4];
int bfs()
{
	node parent(0,0,0);
	queue<node> q;
	q.push(parent);
	int v[505][505]={0};
	int dx[4]={0,0,1,-1};
	int dy[4]={1,-1,0,0};
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		if(t.x==R-1 && t.y==C-1) return t.t;
		if(t.t>R*C*4) return -1;
		int g[4];
		if(v[t.x][t.y]==4) continue;
        for(int i=0;i<4;i++)
        {
        	g[i]=grid[t.x][t.y][v[t.x][t.y]+1%4];
        }
        v[t.x][t.y]++;
		for(int i=0;i<4;i++)
		{
			int xx=t.x+dx[i]; int yy=t.y+dy[i];
			if(xx<0 || xx>=R || yy<0 || yy>=C) continue;
			if(g[i]==0) continue;
			cout<<"PUSHED "<<xx<<" "<<yy<<" "<<t.t+1<<endl;
			q.push(node (xx,yy,t.t+1));
		}
	}
	return -1;
}
int main()
{
ios_base::sync_with_stdio(0);
while(cin>>R>>C)
{
	string s;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(i==R-1 && j==C-1) break;
			cin>>s;
			if(s.find('W')!=string::npos) grid[i][j][0]=1;
			if(s.find('N')!=string::npos) grid[i][j][1]=1;
			if(s.find('E')!=string::npos) grid[i][j][2]=1;
			if(s.find('S')!=string::npos) grid[i][j][3]=1;
		}
	}
	int i=bfs();
	if(i!=-1) cout<<i<<endl;
	else cout<<"no path to exit\n";
}
return 0;
}
