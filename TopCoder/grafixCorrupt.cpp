// BEGIN CUT HERE

// END CUT HERE
#line 5 "grafixCorrupt.cpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class grafixCorrupt {
	public:
	int selectWord(vector <string> dictionary, string candidate) {
		int i,j;
		int min=-1,indx=-1;
		int diff=0;
		for(i=0;i<dictionary.size();i++)
		{
										if(dictionary[i].compare(candidate)==0)
										return i;
										diff=0;
										for(j=0;j<dictionary[i].length();j++)
										{
																			 if(dictionary[i][j]==candidate[j])
																			 diff++;
										 									 }
										if(min<diff && diff!=0)
										{
										 			min=diff;
										 			indx=i;
													}
		 								}
		return min!=0?indx:-1;
	}
};
