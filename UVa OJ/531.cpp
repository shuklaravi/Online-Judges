/* @BEGIN_OF_SOURCE_CODE */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int  res[110];
void func(int mat[][110],int dir[][110], int i, int j,int res[])
{
 if (i==0||j==0)
 return;
     if(dir[i][j]==5)
     {
                     res[mat[i][j]]=i;
                     func(mat,dir,i-1,j-1,res);
                     }
     else if (dir[i][j]==1)
     func(mat,dir,i-1,j,res);
     else func(mat,dir,i,j-1,res);
 }
int main()
{
    int i,j,I,J;
    char str[110][35],str1[110][35];
    int mat[110][110],dir[110][110];
    char s[35];
    while(cin>>s)
    {
            str[1][0]='*';
            str1[1][0]='*';
            strcpy(str[1],s);
            for(i=2;cin>>str[i] && str[i][0]!='#';i++);
            for(j=1;cin>>str1[j] && str1[j][0]!='#';j++);
            I=i;J=j;
            for(i=0;i<I;i++)
            mat[0][i]=0,mat[i][0]=0;
            for(i=1;i<I;i++)
            {
                            for(j=1;j<J;j++)
                            {
                                            if(strcmp(str[i],str1[j])==0)
                                            {
                                                                            mat[i][j]=mat[i-1][j-1]+1;
                                                                            dir[i][j]=5;
                                                                            }
                                            else
                                            {
                                                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
                                                dir[i][j]=((mat[i-1][j]>=mat[i][j-1]) ? 1:-1);
                                            }
                                            }
                                            }
            func(mat,dir,I-1,J-1,res);
            cout<<str[res[1]];
            for(i=2;i<=mat[I-1][J-1];i++)
            cout<<" "<<str[res[i]];
            cout<<endl;
            }
return 0;
}
/* @END_OF_SOURCE_CODE */
