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
#define REP(i,a) for((i)=0;(i)<(a);(i)++)
#define FOR(i,a,b) for((i)=(a);(i)<(b);(i)++)
int main()
{
    int t,test;
    cin>>test;
    t=test;
    vector<bool> v(3005,0);
    int i,max=-1;
    while(test--)
    {
        cin>>i;
        if(i>max) max=i;
        v[i]=1;
    }
    FOR(i,1,max+1)
    {
        if(v[i]==0)
        {
            cout<<i;
            return 0;
        }
    }
    if(i==max+1)
    cout<<max+1;
	return 0;
}

