/* @BEGIN_OF_SOURCE_CODE */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int test,n,i,j,des[100000]={0},arr[100000]={0},res[100000];
    cin>>test;
    while(test--)
    {
                 int time=0;
                 cin>>n;
                 for(i=0;i<n;i++)
                 cin>>arr[i];
                 sort(arr,arr+n);
                 bool turn=true;
                 int last=n-1;
                 int resl=0;
                 while(last>1)
                 {
                         if(turn)
                         {
                                 res[resl++]=arr[0];res[resl++]=arr[1];
//                                 cout<<arr[0]<<" "<<arr[1]<<endl;
                                 time+=arr[1];
                                 time+=arr[0];
                                 res[resl++]=arr[0];
//                                 cout<<arr[0]<<endl;
                                 turn=false;
                         }
                         else
                         {
                             if(last-1!=1)
                             {
                                          res[resl++]=arr[last-1];
                                          res[resl++]=res[last];
//                                          cout<<arr[last-1]<<" "<<arr[last]<<endl;
                             }
                             else
                             {
                                 res[resl++]=arr[0];
                                 res[resl++]=arr[last];
//                                 cout<<arr[0]<<" "<<arr[last]<<endl;
                             }
                             time+=arr[last];
                             if(last!=2)
                             time+=arr[1];
  //                           else
//                             time+=arr[0];
                             if(last!=2)
                             {
                                        res[resl++]=arr[1];
//                                        cout<<arr[1]<<endl;
                             }
                             last-=2;
                             turn=true;
                         }
                 }
                 cout<<time<<endl;
                 bool flag=true;
                 for(i=0;i<resl;)
                 {
                                    if(flag)
                                    {
                                            cout<<res[i]<<" "<<res[i+1]<<endl;
                                            i+=2;
                                            flag=false;
                                    }
                                    else
                                    {
                                        cout<<res[i++]<<endl;
                                        flag=true;
                                    }
                 }
                 if(test!=0)
                 cout<<endl;
    }
return 0;
}
/* @END_OF_SOURCE_CODE */
