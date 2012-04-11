
#include <cmath>
#include <cstdio>
#include <cctype>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define GI ({int _t; scanf("%d", &_t); _t;})
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define REP(i, a) FOR(i, 0, a)
#define sz size()
#define pb push_back
#define cs c_str()
#define DBGV(_v) { REP(_i, _v.sz) { cout << _v[_i] << "\t";} cout << endl;}







int main()
{

int test;
cin>>test;
while(test--)
{
set<int> ss;
set<int>::iterator it;

int n;
cin>>n;
int a;
REP(i,n) { cin>>a; ss.insert(a);}

int max=0,curr=1;
// for ( it=ss.begin(); it!=ss.end();it++) cout<<":"<<*it<<endl;


for ( it=ss.begin(); it!=ss.end();)
{
// cout<<*it<<endl;

int x= *it;
it++;
int y=*it;
//cout<<x<<y<<endl;
if(x+1==y)curr++;
else {
if(max<curr) max=curr;
curr=1;
}

// getchar();
}

// for(int i=0;i<n-1;i++)
// if(arr[i]+1==arr[i+1]) curr++;
// else {
// if(max<curr) max=curr;
// curr=1;
// }
if(max<curr) max=curr;
cout<<max<<endl;




}


// system("pause"); /// for output .. delete pls...
return 0;
}

