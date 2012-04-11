#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    char x[1000],z[100];
    int mat[100][1000];
    int test,i,j;
    cin>>test;
    while(test--)
    {
                 x[0]=' ';
                 z[0]=' ';
                 scanf("%s",&z[1]);
                 scanf("%s",&x[1]);
                 for(i=0;i<1000;i++)
                 mat[0][i]=1;
                 for(i=1;i<strlen(z);i++)
                 {
                                         for(j=1;j<strlen(x);j++)
                                         {
                                                                 if(z[i]==x[j])
                                                                 {
                                                                               mat[i][j]=mat[i-1][j-1]+mat[i][j-1];
                                                                               
                                                                 }
                                                                 else
                                                                     mat[i][j]=mat[i][j-1];
                                         }
                 }
                 cout<<mat[strlen(z)-1][strlen(x)-1]<<endl;
    }
return 0;
}
