/////////////////////////////////////////////////////////////////////////////
//                             SRM 470 LEVEL 1 EASY                        //
//                                CORRECT ANSWER                           //
/////////////////////////////////////////////////////////////////////////////
// BEGIN CUT HERE

// END CUT HERE
#line 5 "LinearTravellingSalesman.cpp"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class LinearTravellingSalesman {
	public:
	int arg(int a, int b)
	{
		return a-b>0?a-b:b-a;
	}
	int findMinimumDistance(vector <int> x, vector <int> y) {
		for(int i=0;i<x.size();i++)
		{
				for(int j=i+1;j<x.size();j++)
				{
										 if(x[i]>x[j])
										 {
													  swap(x[i],x[j]);
													  swap(y[i],y[j]);
										  			  }
													  }
													  }
		int res=0;
		for(int i=0;i<x.size()-1;i++)
		{
				res+=(arg(x[i+1],x[i])+arg(y[i+1],y[i]));
		 		}
        for(int i=0;i<x.size();i++)
		{
				for(int j=i+1;j<x.size();j++)
				{
										 if(y[i]>y[j])
										 {
													  swap(x[i],x[j]);
													  swap(y[i],y[j]);
										  			  }
													  }
													  }
		int res1=0;
		for(int i=0;i<x.size()-1;i++)
		{
				res1+=(arg(x[i+1],x[i])+arg(y[i+1],y[i]));
		 		}
		return res>res1?res1:res;
	}
};
