// BEGIN CUT HERE

// END CUT HERE
#line 5 "JingleRingle.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
//#define REP for(int i=0;i<n;i++)
using namespace std;
class JingleRingle {
	public:
	int profit(vector <int> buyOffers, vector <int> sellOffers, int tax) {
		int i1,val,arr[1000],res;
		sort(buyOffers.begin(),buyOffers.end());
		reverse(buyOffers.begin(),buyOffers.end());
		sort(sellOffers.begin(),sellOffers.end());
		for( i1=0; i1!=buyOffers.size() && i1!=sellOffers.size();i1++)
		{
			val=(buyOffers[i1]-sellOffers[i1])-(buyOffers[i1]*tax)/100;
			if(arr[i1]<val) arr[i1]=val;
		}
		int maxi=0;
		for(int i=0;i<i1;i++)
		maxi+=arr[i];
		res=maxi;
		return res;
	}
};
