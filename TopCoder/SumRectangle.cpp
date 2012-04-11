// BEGIN CUT HERE

// END CUT HERE
#line 5 "SumRectangle.cpp"
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

class SumRectangle {
	public:
	int getCorner(vector <int> leftColumn, vector <int> topRow) {
		int arr[15][15];
		for(int i=0;i<topRow.size();i++)
		arr[0][i]=topRow[i];
		for(int i=0;i<leftColumn.size();i++)
		arr[i][0]=leftColumn[i];
		for(int j=1;j<topRow.size();j++)
		for(int i=1;i<leftColumn.size();i++)
		{
			arr[i][j]=arr[i-1][j-1]-arr[i-1][j]-arr[i][j-1];
		}
		return arr[leftColumn.size()-1][topRow.size()-1];
	}
};
