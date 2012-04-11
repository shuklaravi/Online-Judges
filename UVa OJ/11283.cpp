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
	int x,y,s;
	node(int a, int b, int c)
	{
		x=a;y=b;s=c;
	}
};
bool is_in(int x, int y)
{
	if(x<0 || x>=4 || y<0 || y>=4) return false;
	return true;
}
int dfs(string ss, string str[], int i, int j)
{
	bool v[4][4]={false};
	node parent(i,j,1);
	stack<node> s;
	s.push(parent);
	int dx[8]={+0,+0,+1,-1,-1,-1,+1,+1};
	int dy[8]={+1,-1,+0,+0,+1,-1,+1,-1};
	while(!s.empty())
	{
		node t=s.top();
		s.pop();
		v[t.x][t.y]=1;
		if(t.s==ss.length()) return t.s;
		for(int i=0;i<8;i++)
		{
			int xx=t.x+dx[i]; int yy=t.y+dy[i];
			if(!is_in(xx,yy)) continue;
			if(v[xx][yy]) continue;
			if(str[xx][yy]==ss[t.s])
			{
//				cout<<"\t\tFOUND char "<<ss[t.s]<<" here "<<xx<<" "<<yy<<endl;
				s.push(node (xx,yy,t.s+1));
			}
		}
	}
	return 0;
}
int main()
{
ios_base::sync_with_stdio(0);
int t;
cin>>t;
int no=0;
while(t--)
{
	string str[4];
	int i,j;
	for(int i=0;i<4;i++)
	cin>>str[i];
	int dic;
	cin>>dic;
	string s;
	int ans=0;
	while(dic--)
	{
		int max=0,temp;
		cin>>s;
		for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		if(s[0]==str[i][j])	if((temp=dfs(s, str, i, j))>max) max=temp;
		if(max==0) max=0;
		else if(max==3 || max==4 ) max=1;
		else if(max==5) max=2;
		else if(max==6) max=3;
		else if(max==7) max=5;
		else max=11;
		ans+=max;
//		cout<<s<<" max = "<<max<<endl;
	}
	cout<<"Score for Boggle game #"<<++no<<": "<<ans<<endl;
}
cin>>t;
return 0;
}
