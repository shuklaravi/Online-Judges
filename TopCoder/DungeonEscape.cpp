// BEGIN CUT HERE

// END CUT HERE
#line 5 "DungeonEscape.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
struct node {
	   int x,y,t;
	   node(int a, int b, int c) {
				x=a;y=b;t=c;
				}
	   friend bool operator< (const node &a, const node &b)
	   {
			  return a.t>b.t;
	   		  }
};
class DungeonEscape {
	public:
	int I,J;
	bool v[55][55];
	bool is_in(int a, int b)
	{
		 return (a>=-1 && a<I && b>=0 && b<J);
	}
	int djk(vector<string> u,vector<string> d,vector<string> e,vector<string> w,int sx, int sy)
	{
		priority_queue <node> q;
		node parent(sx,sy,0);
		q.push(parent);
		int dx[4]={1,-1,0,0};
		int dy[4]={0,0,1,-1};
		vector<vector<string> > c(4);
		c[0]=d;c[1]=u;c[2]=e;c[3]=w;
		while(!q.empty())
		{
						 node t=q.top();
						 if(t.x==-1) return t.t;
						 v[t.x][t.y]=true;
						 for(int i=0;i<4;i++)
						 {
								 int xx=t.x+dx[i]; int yy=t.y+dy[i];
								 if(!is_in(xx,yy)) continue;
								 if(v[xx][yy]) continue;
								 if(c[i][t.x][t.y]=='x')continue;
								 int nt=t.t+c[i][t.x][t.y]-'0';
								 if(xx>=0 && xx>=I-(nt/J)) continue;
								 q.push(node (xx,yy,t.t+nt));
								 }
		 				 }
	   return -1;
	}
	int exitTime(vector <string> up, vector <string> down, vector <string> east, vector <string> west, int startLevel, int startEasting) {
//		u=up;d=down;e=east;w=west;
		I=up.size();J=up[0].length();
		memset(v,false,sizeof(v));
		return djk(up,down,east,west,startLevel,startEasting);
	}
};
