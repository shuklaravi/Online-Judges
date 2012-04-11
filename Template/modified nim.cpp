#include<iostream>
using namespace std;
char grid[100][100];
bool check(int p,int q)
{
     int i,j,k;
     for(i=p;i>=0;i--)
     {
                     if(grid[i][q]=='p') return true;
                      }
     for(j=q;j>=0;j--)
     {
                     if(grid[p][j]=='p') return true;
                      }
     for(i=p,j=q;i>=0 && j>=0 ; i--,j--)
     {
                      if(grid[i][j]=='p') return true;
                      }
     return false;
 }
int main()
{
    int i,j,k,p,q;
    for(i=0;i<100;i++)
                      for(j=0;j<100;j++)
                      grid[i][j]='.';
    grid[0][0]='p';
    for(i=1;i<100;i++)
    {
                      grid[i][0]='n';
                      grid[0][i]='n';
                      grid[i][i]='n';
    }
    bool flag=1;int x;
    for(i=1;i<100;i++)
    {
                      for(j=1;j<100;j++)
                      {
                                        if(grid[i][j]!='.') continue;
                                        if(check(i,j))
                                        {
                                                      grid[i][j]='n';
                                                      }
                                        else
                                        {
 
                                            for(x=i+1;x<100;x++)
                                            grid[x][j]='n';
                                            for(x=j+1;x<100;x++)
                                            grid[i][x]='n';
                                            grid[i][j]='p';
                                            break;                                           
                                            }
                      }
                      for(j=1;j<100;j++)
                      {
                                        if(grid[j][i]!='.') continue;
                                        if(check(j,i))
                                        {
                                                      grid[j][i]='n';
                                                      }
                                        else
                                        {
                                            
                                            for(x=i+1;x<100;x++)
                                            grid[x][j]='n';
                                            for(x=j+1;x<100;x++)
                                            grid[i][x]='n';
                                            grid[j][i]='p';
                                            break;
                                            }
                      }
    }
    for(i=0;i<100;i++)
    {
                      for(j=0;j<100;j++)
                      if(grid[i][j]=='p')
                      {
                                         cout<<i<<" "<<j<<endl;
                                         grid[j][i]='n';
                                         }
                      }
//    system("pause");
}
