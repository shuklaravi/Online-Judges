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
#define REP_(i,a) for((i)=0;(i)<=(a);(i)++)
#define FOR(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define FOR_(i,a,b) for((i)=(a);(i)<=(b);(i)++)
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
//END_TEMPLATE_BY_PRATYUSH_VERMA
vector<int> arr(100005,0);
int main()
{
    int n;
    cin>>n;
    int i,k,j,p,q;
//    MEM(arr,false);
    int arr1[100005];
    MEM(arr1,0);
//    set<int>
    REP(i,n)
    {
        cin>>p>>q;
        arr1[p]++;
        arr1[q]++;
        arr[p]=q;
        arr[q]=p;
    }
    REP(i,10005) if(arr1[i]==1) break;
    cout<<i<<" ";
//    cout<<"0. found 1 @ "<<i<<" "<<j<<" where arr1[i] = "<<arr1[i]<<" "<<" and arr1[j] = "<<arr1[j]<<endl;
    REP(j,10005)
    {
        if(arr[i]!=0)
        {
            cout<<"i changed to "<<i;
            i=arr[i];
            cout<<" "<<i<<"\n";
            arr[i]=0;
            arr[arr[i]]=0;
//            cout<<"1. found 1 @ "<<i<<" "<<j<<" where arr1[i] = "<<arr1[i]<<" "<<" and arr1[j] = "<<arr1[j]<<endl;
            break;
        }
    }
    for(;;)
    {
        cout<<i<<" ";
//        cout<<"2. found 1 @ "<<i<<" "<<j<<" where arr1[i] = "<<arr1[i]<<" "<<" and arr1[j] = "<<arr1[j]<<endl;
            if(arr1[i]==1)
            {
                j=arr[i];
//                arr[i][k]=false;
//               arr[j][i]=false;
//                cout<<j<<" ";
//                cout<<"3. found 1 @ "<<i<<" "<<j<<" where arr1[i] = "<<arr1[i]<<" "<<" and arr1[k] = "<<arr1[k]<<endl;
                system("pause");
                return 0;
            }
            if(arr1[i]==2)
            {
                cout<<"i changed to "<<i;
                i=arr[i];
                cout<<" "<<i<<"\n";
                arr[i]=0;
                arr[arr[i]]=0;
//                cout<<"41. found 1 @ "<<i<<" "<<j<<" where arr1[i] = "<<arr1[i]<<" "<<" and arr1[k] = "<<arr1[k]<<endl;
            }
            system("pause");
    }
	return 0;
}

