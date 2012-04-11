// BEGIN CUT HERE

// END CUT HERE
#line 5 "ChessMetric.cpp"
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
class ChessMetric {
	public:
//	int d[16][2];
    long long memo[110][110][51];
    int sz,sr,sc;
	long long howMany(int size, vector <int> start, vector <int> end, int numMoves) 
	{
		    int d[16][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1},{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
			memset(memo,-1,sizeof(memo));
			sr=start[0];
			sc=start[1];
			if(numMoves==0)
			{
				if(start[0]==end[0] && start[1]==end[1])
				return 1;
				else
				return 0;
			}
			sz=size;
			return func(d,end[0],end[1], numMoves);
	}
	long long func(int d[][2],int r, int c, int movLeft)
	{
		if(movLeft==0)
		{
				if(sr==r && sc==c)
				return 1;
				else
				return 0;
		}
		if(memo[r][c][movLeft]!=-1)
		return memo[r][c][movLeft];
		long long x=0;
		for(int i=0;i<16;i++)
		{
			int R=r+d[i][0];
			int C=c+d[i][0];
			if(!(R>0 && C>0 && R<=sz && C<=sz)) continue;
			x+=func(d,R,C,movLeft-1);
		}
		memo[r][c][movLeft]=x;
		return x;
	}
};
