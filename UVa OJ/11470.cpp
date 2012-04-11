/* @BEGIN_OF_SOURCE_CODE */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int mat[11][11];
int sum1[11],sum2[11];
int main()
{
    int n,sum,no=0;
    while(1)
    {
            cin>>n;
            if(n==0)
            break;
            no++;
            cout<<"Case "<<no<<":";
            for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            cin>>mat[i][j];
            for(int i=0;i<n/2;i++)
            {
                    sum=0;
                    sum+=mat[i][i]+mat[i][n-1-i]+mat[n-1-i][i]+mat[n-1-i][n-1-i];
                    for(int j=i+1;j<n-1-i;j++)
                    {
                            sum+=mat[i][j]+mat[j][i]+mat[n-1-i][n-1-j]+mat[n-1-j][n-1-i];
                            }
                    cout<<" "<<sum;
                    }
            if(n%2==1)
            cout<<" "<<mat[n/2][n/2];
            cout<<endl;
            }
return 0;
}
/* @END_OF_SOURCE_CODE */
