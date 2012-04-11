/* @BEGIN_OF_SOURCE_CODE */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int len,N,arr[50],I,J,K;
    while (cin>>len&&len!=0)
    {
          cin>>N;
          for (I=0;I<N;I++)
          cin>>arr[I];

          int m[10][10];
        
          for (I=0;I<=N;I++)
          {
                
              m[I][I]=0;
              for (int L=1;L<=N;I++)
              {
                  for (I=0;I<=N-L+1;I++)
                  {
                      J=I+L-1;
                      m[I][J]=10000;
                       cout<<"GF";
                      for (K=I;K<=J-1;K++)
                      {
                          int q=m[I][K]+m[K+1][J]+J-I;
                          if (q<m[I][J])
                          m[I][J]=q;
                          }
                  }
              }
          }
       
        cout<<m[0][10]<<endl;
        }
        return 0;
    }
              

          
          
          



/* @END_OF_SOURCE_CODE */
