/* @BEGIN_OF_SOURCE_CODE */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int adj[100][100];
    int top[100]={0};
    int no,i,j,I,J;
    cin>>no;
    char ch;
    for(j=0;j<no;j++)
    for(i=0;(ch=getchar())!='\n';i++)
    {
                                     adj[j][top[j]++]=ch-'0';
                                     }
    for(i=0;i<no;i++)
    {
                     for(j=0;j<top[i];j++)
                     cout<<adj[i][j]<<" ";
                     cout<<endl;
                     }
    system("pause");
return 0;
}
/* @END_OF_SOURCE_CODE */
