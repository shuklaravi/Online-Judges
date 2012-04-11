#include<iostream>
#define max 100000

using namespace std;
int main()
{
 int luck[150];
 int i,j,k,num,n;
 luck[0]=4;luck[1]=7;
 int Res[max+1];
 i=0;k=2;
 while(k<130)
 {
  luck[k]=luck[i]*10+4;
  k++;
  luck[k]=luck[i]*10+7;
  k++;
  i++;
 }
 
 Res[2]=Res[1]=Res[3]=max;
 for(i=0;i<126;i++)
  Res[luck[i]]=1;
   for(i=5;i<=max;i++)
 {
  Res[i]=max;
  for(j=0;j<130;j++)
  {
   if(i>=luck[j] && Res[i-luck[j]]!=max)
     if(Res[i]>Res[ i - luck[j] ] + 1)
       Res[i] = Res[ i - luck[j] ] + 1;
  }
  //cout<<Res[i]<<endl;
 }
    // Res[i] = min(Res[ i - lucky[j] ] + 1)
    
  while(cin>>n)
   {if(Res[n]==max) cout<<"NOT POSSIBLE"<<endl;
    else
   cout<<Res[n]<<endl;}
  return 0;
}
 

 
