/* @BEGIN_OF_SOURCE_CODE */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int coin[6]={0,1,5,10,25,50};
    int c,change[6][7490],i,j;
    for(i=0;i<6;i++)
    change[i][0]=1;
    for(i=1;i<6;i++)
    {
                       for(j=1;j<7490;j++)
                       {
                                       if(coin[i]>j)
                                                    change[i][j]=change[i-1][j];
                                       else
                                       {
                                           change[i][j]=change[i-1][j]+change[i][j-coin[i]];
                                       }
                       }
    }
    while(cin>>c)
    {
                 cout<<change[5][c]<<endl;
    }
return 0;
}
/* @END_OF_SOURCE_CODE */
