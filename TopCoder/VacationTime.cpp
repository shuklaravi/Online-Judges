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
class VacationTime
{
	public:
		int bestSchedule(int N, int K, vector <int> workingDays)
		{
			vector<int> day(N+2,0);
			int i,j,p,q;
			FOR(i,0,workingDays.size())
			day[workingDays[i]]=1;
			int curr=0;
			int max=INF;
			int d=0;
			for(i=1;i<=N-K+1;i++)
			{
				d=0;
				curr=0;
				for(j=i;d<K;d++)
				{
					if(day[i]==1) curr++;
				}
				if(max>curr)
				max=curr;
			}
			return max;
		}

};
