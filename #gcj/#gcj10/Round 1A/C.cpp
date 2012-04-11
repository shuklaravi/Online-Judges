/*
ID: your_id_here
PROG: test
LANG: C++
*/

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
int turn;
int gcd(int a, int b)
{
	if(b==0 || a==0) return a;
	turn++;
//	if(b>a)
//	swap(a,b);
	cout<<turn <<" ("<<a<<","<<b<<")\n";
	return gcd(b, a%b);
}

int main()
{
	int test;
	cin>>test;
	int a1,a2,b1,b2;
	while(test--)
	{
				 cin>>a1>>a2>>b1>>b2;
				 int count=0;
     			 for(int i=a1;i<=a2;i++)
				 for(int j=b1;j<=b2;j++)
				 {
						 int turn=0;
						 int I=i,J=j;
						 while(I!=0 && J!=0)
						 {
									turn++;
									if(J>I)
									swap(I,J);
									I=I%J;
									cout<<turn<<" ("<<I<<","<<J<<")\n";
						  			}
						 if(turn%2==0) count++;
				  		 }
				 cout<<count<<endl;
	 			 }
return 0;
}
