// BEGIN CUT HERE

// END CUT HERE
#line 5 "EllysPlaylists.cpp"
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

class EllysPlaylists {
	public:
	int countPlaylists(vector <string> songs, int K) {
		map<string, int> m;
		int sz=songs.size();
		int i,j;
		for(i=0;i<sz;i++)
		m[songs[i]]=i;
		map<string, string> dic;
		for(i=0;i<sz;i++)
		{
			for(j=0;j<sz;j++)
			if(songs[i].substr(songs[i].length()-3, songs[i].length())==songs[j].substr(songs[j].length()-3, songs[j].length()));
			dic[i].insert(j)
		}
		string str="";
		for(i=0;i<)
		for(int i=0;i<songs.size()-1;i++)
		{
			for(int j=i+1;j<songs.size();j++)
	}
};
