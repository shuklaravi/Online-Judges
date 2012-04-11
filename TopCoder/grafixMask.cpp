// BEGIN CUT HERE

// END CUT HERE
#line 5 "grafixMask.cpp"
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <memory>
#include <stack>
#include <cstdio>
#include <algorithm>
#define R 400
#define C 600
#define FOR(x,a,b) for((x)=(a);(x)<(b);(x)++)
using namespace std;
struct node {
	int x,y;
	node (int a, int b) {
		x=a;
		y=b;
	}
};
class grafixMask {
	public:
	bool board[405][605];
	vector <int> sortedAreas(vector <string> rectangles) {
		int i,j,z;
		for(i=0;i<R;i++)
		for(j=0;j<C;j++)
		board[i][j]=true;
		vector<int> result;
		int r0,c0,r1,c1;
		for(z=0;z<(int)rectangles.size();z++)
		{
            sscanf(rectangles[z].c_str(), "%d %d %d %d", &r0, &c0, &r1, &c1);
			for(i=r0;i<=r1;i++)
			{
				for(j=c0;j<=c1;j++)
				{
					board[i][j]=false;struct node {
	int x,y;
	node (int a, int b) {
		x=a;
		y=b;
	}
};
class grafixMask {
	public:
	bool board[405][605];
	vector <int> sortedAreas(vector <string> rectangles) {
		int i,j,z;
		for(i=0;i<R;i++)
		for(j=0;j<C;j++)
		board[i][j]=true;
		vector<int> result;
		int r0,c0,r1,c1;
		for(z=0;z<(int)rectangles.size();z++)
		{
            sscanf(rectangles[z].c_str(), "%d %d %d %d", &r0, &c0, &r1, &c1);
			for(i=r0;i<=r1;i++)
			{
				for(j=c0;j<=c1;j++)
				{
					board[i][j]=false;
				}
			}
		}
		for(i=0;i<R;i++)
		{
			for(j=0;j<C;j++)
			{
				if(board[i][j])
				{
					node parent(i,j);
					result.push_back(dfs(parent));
				}
			}
		}
		sort(result.begin(),result.end());
		return result;
	}
	int dfs(node parent)
	{
		int dxdy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1} };
		int res=0;
		stack<node> s;
		s.push(parent);
		while(!s.empty())
		{
			node temp=s.top();
			s.pop();
			if(temp.x<0 || temp.x>=400) continue;
			if(temp.y<0 || temp.y>=600) continue;
			if(!board[temp.x][temp.y]) continue;
			board[temp.x][temp.y]=false;
			res++;
			for(int p=0;p<4;p++)
			{
				int r=temp.x+dxdy[p][0];
				int c=temp.y+dxdy[p][1];
				node pp(r,c);
				s.push(pp);
			}
		}
		return res;
	}
};

				}
			}
		}
		for(i=0;i<R;i++)
		{
			for(j=0;j<C;j++)
			{
				if(board[i][j])
				{
					node parent(i,j);
					result.push_back(dfs(parent));
				}
			}
		}
		sort(result.begin(),result.end());
		return result;
	}
	int dfs(node parent)
	{
		int dxdy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1} };
		int res=0;
		stack<node> s;
		s.push(parent);
		while(!s.empty())
		{
			node temp=s.top();
			s.pop();
			if(temp.x<0 || temp.x>=400) continue;
			if(temp.y<0 || temp.y>=600) continue;
			if(!board[temp.x][temp.y]) continue;
			board[temp.x][temp.y]=false;
			res++;
			for(int p=0;p<4;p++)
			{
				int r=temp.x+dxdy[p][0];
				int c=temp.y+dxdy[p][1];
				node pp(r,c);
				s.push(pp);
			}
		}
		return res;
	}
};
/*
int main()
{
	string str="0 292 399 307";
//	string str="48 192 351 207";
//	string str1= "48 392 351 407";
//	string str2= "120 52 135 547";
//	string str3= "260 52 275 547";
	vector<string> v;
	v.push_back(str);
//	v.push_back(str1);
//	v.push_back(str2);
//	v.push_back(str3);
	grafixMask d;
	vector<int> res;
	res=d.sortedAreas(v);
	int i;
	for(i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
	}
	return 0;
}
*/
