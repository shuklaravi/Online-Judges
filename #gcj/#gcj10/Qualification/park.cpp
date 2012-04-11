#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    long long t,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
           long long r,k,n,j,euro=0,p,w;
           cin>>r>>k>>n;
           long long g[n],copy[n];
           for(j=0;j<n;j++)
           {
                cin>>g[j];           
           }     
           //code start....
           for(p=0;p<r;p++)
           {
               long long index;
               long long left=k,cant=0,h=0;       
               while(left!=0 && cant!=1)
               {
                      if(g[h]<=left)
                      {
                            left-=g[h];
                            h++;              
                      }         
                      else
                      {
                            cant=1;
                            index=h;    
                      }    
               }
               euro+=(k-left);
               for(w=0;w<(n-h);w++)
               {
                     copy[w]=g[w+h];               
               }
               for(w=n-h;w<n;w++)
               {
                     copy[w]=g[w-(n-h)];               
               }
               //copying copy to g
               for(w=0;w<n;w++)
               {
                     g[w]=copy[w];               
               }
               /*cout<<"\ng"<<endl;
               for(w=0;w<n;w++)
               {
                     cout<<g[w]<<"\t";               
               }
               cout<<endl;
               cout<<"copy"<<endl;
               for(w=0;w<n;w++)
               {
                     cout<<copy[w]<<"\t";               
               }
               cout<<endl;
               cout<<"euro="<<euro<<endl;*/
               
           }
           cout<<"Case #"<<i+1<<": "<<euro<<endl;
           
    }
    getch();
    return 0;    
}
