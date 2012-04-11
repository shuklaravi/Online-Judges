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
#define INF 1<<31
#define REP(i,a) for((i)=0;(i)<(a);(i)++)
#define FOR(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define FOREACH(i,c) for(__typeof((c).begin()) (i)=(c).begin();(i)!=(c).end();(i)++)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((int)(x.size()))
#define LENGTH(x) ((int)(x.length()))
#define MP(x,y) make_pair(x,y)
using namespace std;

int main(){
int num=0;
int test,p,no;

freopen("B.txt" , "r" , stdin);
freopen("bbb.txt" , "w" , stdout);
cin>>test;
for(no=1;no<=test;no++)
{
cin>>p;
int i,j,sub_res[10000][10000],ip[10000],mini[10000][10000];
for(i=0;i<(1<<p);i++)
cin>>ip[i];
for(i=0;i<p;i++)
{
    for(j=0;j<(1<<(p-i-1));j++)
	cin>>sub_res[i][j];
}
for(i=0;i<(1<<(p-1));i++)
{
	mini[0][i]=min(ip[2*i],ip[2*i+1]);
    if(mini[0][i]>0)
	{
		mini[0][i]--;
		sub_res[0][i]--;
	}
}
for(i=1;i<p;i++)
{
    for(j=0;j<(1<<(p-i-1));j++)
    {
  		mini[i][j]=min(mini[i-1][2*j],mini[i-1][j*2 +1]);
        if(mini[i][j]>0)
        {
            mini[i][j]--;
            sub_res[i][j]--;
        }
	}
}
int count=0;
for(i=0;i<p;i++)
for(j=0;j<(1<<(p-i-1));j++)
count+=sub_res[i][j];
cout<<"Case #"<<no<<": "<<count<<endl;
}
return 0;
}
