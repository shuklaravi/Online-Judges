/* @BEGIN_OF_SOURCE_CODE */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int test,temp,N,c,i,j;
    cin>>test;
    while(test--)
    {
                 int coin[1001],change[100001];
                 cin>>N;
                 cin>>c;
                 coin[0]=0;
                 for(i=1;i<=c;i++)
                                 cin>>coin[i];
//                 change[0]=0;
                 for(i=0;i<=c;i++)
                                  change[coin[i]]=1;
                 change[0]=0;
                 for(i=1;i<100001;i++)
                 {

                                      for(j=1;j<=c;j++)
                                      if(i==coin[j]) break;
                                      if(j<=c) continue;
                                     if(coin[1]>i)
                                     temp=99999;
                                     else
                                     {
                                         if(change[i-coin[1]] != 99999)
                                         temp=change[i-coin[1]]+1;
                                         else
                                         temp=99999;
                                     }
                                     for(j=2;j<=c;j++)
                                     {
//                                                      cout<<temp<<i<<" "<<-coin[j]<<endl;
                                                      if(coin[j]<i)
                                                      if(temp>change[i-coin[j]])
                                                                                temp=change[i-coin[j]]+1;
                                                                                
                                     }

                                     change[i]=temp;
                 }
//                 cout<<change[1400];
                 for(i=N;change[i]==99999 && i<=10000;i++);
                 cout<<i<<" "<<change[i]<<endl;
//                 for(i=0;i<10001;i++)
//                 cout<<change[i]<<endl;
    }
return 0;
}
/* @END_OF_SOURCE_CODE */
