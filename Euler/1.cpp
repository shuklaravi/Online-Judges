#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
    int i,j;
    int count=0;
    for(i=1;i<1000;i++)
    {
                       if(i%3==0)cout<<"3 - "<<i<<endl,count+=i;
                       else if(i%5==0)cout<<"5 - "<<i<<endl,count+=i;
                       }
    cout<<count;
    cin>>i;
return 0;
}
