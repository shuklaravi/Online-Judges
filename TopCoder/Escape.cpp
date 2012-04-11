// BEGIN CUT HERE

// END CUT HERE
#line 5 "Escape.cpp"
#include <sstream>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
struct node{
	   int posX,posY,life;
	   node(int xx,int yy,int l){
				posX=xx;
				posY=yy;
				life=l;
				}
	   node (){}
	   };
class Escape {
	public:
 	char grid[501][501];
 	int life[501][501];
	bool is_in(int a, int b)
	{
		 if(a<0 || a>500 || b<0 || b>500) return true;
		 return false;
 	}
	int bfs(char grid[][501],node parent)
	{
		queue<node> q;
		q.push(parent);
		int dx[4]={1,-1,0,0};
		int dy[4]={0,0,1,-1};
		while(!q.empty())
		{
						 node temp=q.front();
						 q.pop();
						 for(int i=0;i<4;i++)
						 {
								 if(grid[temp.posX+dx[i]][temp.posY+dy[i]]=='d' || is_in(temp.posX+dx[i],temp.posY+dy[i])) continue;
								 int next=life[temp.posX][temp.posY]+(bool)(grid[temp.posX+dx[i]][temp.posY+dy[i]]=='h');
								 if(life[temp.posX+dx[i]][temp.posY+dy[i]]>next || life[temp.posX+dx[i]][temp.posY+dy[i]]==-1)
								 {
                                                                          life[temp.posX+dx[i]][temp.posY+dy[i]]=next;
																		  q.push(node (temp.posX+dx[i],temp.posY+dy[i],next));
								  										  }
						  		 }
								 }
	   return life[500][500];
	 }
	int lowest(vector <string> harmful, vector <string> deadly) {
		memset(grid,'s',sizeof(grid));
		memset(life,-1,sizeof(life));
		int i,x1,y1,x2,y2,x,y;
		node parent(0,0,0);
		for(i=0;i<harmful.size();i++)
		{
									 stringstream ss(harmful[i]);
									 while(ss>>x1>>y1>>x2>>y2)
									 {
												  if(x1>x2)
						   		   				  swap(x1,x2);
												  if(y1>y2)
												  swap(y1,y2);
												  for(x=x1;x<=x2;x++)
												  for(y=y1;y<=y2;y++)
												  grid[x][y]='h';
                                                  }
		 							 }
        for(i=0;i<deadly.size();i++)
		{
									 stringstream sss(deadly[i]);
									 while(sss>>x1>>y1>>x2>>y2)
									 {
												  if(x1>x2)
						   		   				  swap(x1,x2);
												  if(y1>y2)
												  swap(y1,y2);
												  for(x=x1;x<=x2;x++)
												  for(y=y1;y<=y2;y++)
												  {
												   					 grid[x][y]='d';
												   					 life[x][y]=-5;
																	 }
                                                  }
		 							 }
		grid[0][0]='s';
		return bfs(grid,parent);
	}
};
int main()
{
	string s="0 0 250 250";
	string s1="250 250 500 500";
	string ss="0 251 249 500";
	string ss1="251 0 500 249";
	Escape d;
	vector<string> v;
	v.push_back(s);
	v.push_back(s1);
	vector<string> vv;
	vv.push_back(ss);
	vv.push_back(ss1);
	cout<<d.lowest(v,vv);
	cin>>s;
	return 0;
}
