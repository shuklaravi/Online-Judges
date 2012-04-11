#include<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<deque>
using namespace std;

#define sz 13
#define forn(i,n) for(int i=0;i<(n);i++)
#define init(a,v) memset(a,v,sizeof(a))
#define GI(t) scanf("%d",&(t))

int n;
int dp[sz][sz][1<<sz];
char grid[sz][sz+1];
int numb[sz][sz];

int x[sz*sz*(1<<sz)];
int y[sz*sz*(1<<sz)];
int b[sz*sz*(1<<sz)];

int main ()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t; GI(t);
	int cnt;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	while (t--)
	{
		GI(n); cnt = 0;
		forn(i,n) scanf("%s", grid[i]);
		init(dp, -1);
		init(numb, -1);
		forn(i,n) forn(j,n) if(grid[i][j] == '*') numb[i][j] = cnt++;
		x[0] = y[0] = b[0] = 0;
		if (grid[0][0] == '*') b[0] = 1;
		if (grid[0][0] == '#') cout << -1 << endl;
		else
		{
			dp[0][0][b[0]] = 0;
			int index = 0; int size = 1;
			while (index != size)
			{
				forn(i,4)
				{
					x[size] = x[index]+dx[i];
					y[size] = y[index]+dy[i];
					b[size] = b[index];
					if (x[size] >= 0 && x[size] < n && y[size] >= 0 && y[size] < n)
						if (grid[x[size]][y[size]] != '#')
						{
							if (grid[x[size]][y[size]] == '*') b[size] |= (1<<numb[x[size]][y[size]]);
							if (dp[x[size]][y[size]][b[size]] == -1)
							{
								dp[x[size]][y[size]][b[size]] = dp[x[index]][y[index]][b[index]] + 1;
								size++;
							}
						}
				}
				if (dp[n-1][n-1][(1<<cnt)-1] != -1) break;
				index++;
			}
			cout << dp[n-1][n-1][(1<<cnt)-1] << endl;
		}
	}

	return 0;
}
