// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheMoviesLevelOneDivTwo.cpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class TheMoviesLevelOneDivTwo {
	public:
	int find(int n, int m, vector <int> row, vector <int> seat) {
			int avail=0;
			int i,j;
			int arr[50][50]={0};
			for(i=0;i<seat.size();i++)
			{
				arr[row[i]][seat[i]]=1;
			}
			for(i=1;i<=n;i++)
			{
				for(j=1;j<m;j++)
				{
					if(arr[i][j]==0 && arr[i][j+1]==0)
					{
						avail++;
					}
				}
			}
			return avail;
	}
};
/*
int main()
{
	vector <int> m;
	m.push_back(1);
	m.push_back(9);
	m.push_back(6);
	m.push_back(10);
	m.push_back(2);
	m.push_back(2);
	vector <int> mm;
	mm.push_back(2);
	mm.push_back(3);
	mm.push_back(3);
	mm.push_back(1);
	mm.push_back(2);
	mm.push_back(3);
	TheMoviesLevelOneDivTwo d;
	cout<<d.find(10,8,m,mm);
	return 0;
	
}
*/
