#include<iostream>
using namespace std;
int main()
{
    long long  test,cas,other,i,rank,j;
    long long me[100002];
    bool poss=false;
    cin>>test;
    for(i=0;i<test;i++)
    cin>>me[i];
    cin>>cas;
    for(j=0;j<cas;i++,j++)
    cin>>me[i];
    int k=0;
    while(k<test)
    {
                 poss=false;
                 rank=1;
                 for(i=0;i<(cas+test);i++)
                 {
                                   if(me[k]<me[i])
                                   {
                                                  rank++;
                                                  }
                                   if(rank>5)
                                   {
                                             poss=true;
                                             break;
                                   }
                 }
                 if(poss)
                 cout<<"Not Eligible\n";
                 else
                 cout<<"Eligible\n";
                 k++;
                 }
return 0;
}
