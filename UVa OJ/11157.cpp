/* @BEGIN_OF_SOURCE_CODE */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int test;
    cin>>test;
    char ch;
    while(test--)
    {
                 vector<int> path(0);
                 int n,d,t;
                 cin>>n>>d;
                 path[0]=0;
                 for(int i=1;i<n;i++)
                 {
                         cin>>ch>>ch>>t;
                         if(i)
                         t=(t-path[i-2]);
                         cout<<i<<" "<<t<<endl;
                         path.push_back(t);
                         }
                 path.push_back(d-path[n-2]);
                 int max=-1;
                 for(int i=0;i<path.size();i+=2)
                 if(max<path[i]) max=path[i];
                 for(int i=1;i<path.size();i+=2)
                 if(max<path[i]) max=path[i];
                 cout<<max<<endl;
                 }
return 0;
}
/* @END_OF_SOURCE_CODE */
