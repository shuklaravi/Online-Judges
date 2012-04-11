// #define TRUE FALSE haha now debug this

#line 7 "GameOfLifeDivTwo.cpp"

using namespace std;
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

class GameOfLifeDivTwo
{
public:
string theSimulation(string init, int T)
{
    string res;
	res=init;
	int i,j,k,p,q;
	for(j=0;j<T;j++)
	{
		for(i=0;i<init.length();i++)
		{
			if(i==0) {
				if(init[i]=='1') {
					if(init[init.length()-1]=='1' || init[i+1]=='1') {
						res[i]='1';
					}
					else {
						res[i]='0';
					}
				}
				else {
					if(init[init.length()-1]=='1' && init[i+1]=='1') {
						res[i]='1';
					}
					else {
						res[i]='0';
					}
				} 
			}
			else if(i==init.length()-1) {
				if(init[i]=='1') {
					if(init[i-1]=='1' || init[0]=='1') {
						res[i]='1';
					}
					else {
						res[i]='0';
					}
				}
				else {
					if(init[i-1]=='1' && init[0]=='1') {
						res[i]='1';
					}
					else {
						res[i]='0';
					}
				} 
			}
			else {
				if(init[i]=='1') {
					if(init[i-1]=='1' || init[i+1]=='1') {
						res[i]='1';
					}
					else {
						res[i]='0';
					}
				}
				else {
					if(init[i+1]=='1' && init[i-1]=='1') {
						res[i]='1';
					}
					else {
						res[i]='0';
					}
				} 
			}
		}
		init=res;
		cout<<init<<endl;
	}
    return res;
}


};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
