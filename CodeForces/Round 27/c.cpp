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
//BEGIN_TEMPLATE_BY_PRATYUSH_VERMA
#define INF (1<<31)-1
#define REP(i,a) for((i)=0;(i)<(a);(i)++)
#define FOR(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define VAR(V,init) __typeof(init) V=(init)
#define FOREACH(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((int)(x.size()))
#define LENGTH(x) ((int)(x.length()))
#define SZ(x) sizeof(x)
#define MEM(m,i) memset((m),(i),SZ(m))
#define PB(x,y) (x).push_back(y)
#define MP(x,y) make_pair(x,y)
typedef long long ll;
inline string i2s(int number) { stringstream ss; ss << number; return ss.str(); }
//END_TEMPLATE_BY_PRATYUSH_VERMA

int main()
{
    int i=0,n,nn;
    cin>>n;
    nn=n;
    int arr[n];
    int diff[n];
    diff[0]=0;
    if(n==1 || n==2)
    {
        cout<<"0";
        return 0;
    }
    
    while(nn--)
    {
        cin>>arr[i++];
    }
    
    int j,k,I,J,K,p,q;
    FOR(i,1,n)
    {
        diff[i]=arr[i]-arr[i-1];
    }
    int s;
    FOR(i,1,n)
    if(diff[i]!=0) break;
    if(i==n)
    {
        cout<<"0";
        return 0;
    }
    if(diff[i]>0) s=1;
    if(diff[i]<0) s=-1;
    FOR(i,0,n)
    {
        if(s==1 && diff[i]<0)
        {
            cout<<"3\n";
            break;
        }
        if(s==2 && diff[i]>0)
        {
            cout<<"3\n";
            break;
        }
    }
    if(i==n)
    {
        cout<<"0\n";
        return 0;
    }
    FOR(i,0,n-2)
    {
        FOR(j,i+1,n-1)
        {
            FOR(k,j+1,n)
            {
                if(arr[i]>arr[j] && arr[j]<arr[k])
                {
                    cout<<i+1<<" "<<j+1<<" "<<k+1;
                    return 0;
                }
                if(arr[i]<arr[j] && arr[j]>arr[k])
                {
                    cout<<i+1<<" "<<j+1<<" "<<k+1;
                    return 0;
                }
            }
        }
    }
	return 0;
}
