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
//BEGIN_TEMPLATE_BY_PRATYUSH_VERMA
#define INF 1<<31
#define REP(i,a) for((i)=0;(i)<(a);(i)++)
#define FOR(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define FOREACH(i,c) for(__typeof((c).begin()) (i)=(c).begin();(i)!=(c).end();(i)++)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((int)(x.size()))
#define LENGTH(x) ((int)(x.length()))
#define MP(x,y) make_pair(x,y)
//END_TEMPLATE_BY_PRATYUSH_VERMA
using namespace std;
int main()
{
ios_base::sync_with_stdio(0);
//freopen("A.in" , "r" , stdin);
//freopen("A.txt" , "w" , stdout);
int test,no;
cin>>test;
for(no=1;no<=test;no++)
{
	int p,i,j,x,y;
	cin>>p;
	int arr[1<<p][1<<p];
	for(i=0;i<(2*p);i++)
	{
		cin>>arr[i][0];
	}
	int count=0;
	for(i=1;i<=p;i++)
	{
		for(j=0;j<((1<<p)/(1<<i));j++)
		{
   			int temp=min(arr[i-1][2*j]-1,arr[i-1][2*j+1]-1);
			if(temp<0)
			{
				count++;
				arr[i][j]=0;
			}
			else
			arr[i][j]=temp;
		}
	}
	for(i=1;i<=p;i++)
	{
		for(j=0;j<((1<<p)/(1<<i));j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Case #"<<no<<": "<<count<<endl;
}
return 0;
}
