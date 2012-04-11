#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
    long long i=0,n=1,x=1;
    long long count=0;
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    for(i=3;i<4000000;i++)
    arr.push_back(arr[i-1]+arr[i-2]);
    for(i=2;i<4000000;i++)
    if(arr[i]<4000000 && arr[i]%2==0)count+=arr[i];
                    cout<<count;
                     cin>>x;
return 0;
}
