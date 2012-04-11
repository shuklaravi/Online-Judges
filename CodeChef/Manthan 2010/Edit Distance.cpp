/* @BEGIN_OF_SOURCE_CODE */
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int test;
    int l1,l2,i,j,I,J,ii,jj;
    int mat[2][3005];
    char a[3005],b[3005],temp[3005];
    int no;
    char ch;
    scanf("%d\n",&test);
    while(test--)
    {
//                 string a,b,temp;
                 scanf("%d ",&l1);
                 I=J=0;
                 for(i=0;i<l1;i++)
                 {
                                  scanf("%c%d",&ch,&no);
//                                  printf("%c",ch);
                                  while(no--)
                                  {
//                                                     temp.push_back(ind[i]);
                                                      *(a+I)=ch;
                                                      I++;
                                                      
                                  }
//                                  a.append(temp);
                 }
                 a[I]='\0';
//                 printf("%s",a);
                 scanf("\n");
//                 cout<<a<<endl;
                 scanf("%d ",&l2);
                 for(i=0;i<l2;i++)
                 {
                                  scanf("%c%d",&ch,&no);
                                  while(no--)
                                  {
//                                                     temp.push_back(ind[i]);
                                                      *(b+J)=ch;
                                                      J++;
                                  }
//                                  a.append(temp);
                 }
                 b[J]='\0';
//                 printf("%s",b);
                 for(i=0;i<=I;i++)
                 {
                                   mat[0][i]=2*i;
                 }
                 int row,prev_row;
                 for(i=0;i<J;i++)
                 {

                                row=(i+1)%2;
                                prev_row=(row==1)?0:1;
                                mat[row][0]=i+1;

                                     for(j=0;j<I;j++)
                                     {
                                                         if(b[i]==a[j])
                                                         {
                                                                           mat[row][j+1]=mat[prev_row][j];
                                                         }
                                                         else
                                                         {
                                                             mat[row][j+1]=min(mat[prev_row][j+1]+1,mat[row][j]+2);
                                                         }
                                     }
                 for(i=0;i<=J;i++)
                 {
                                   printf("%d ",mat[0][j]);
                 }
                 printf("\n");
                for(i=0;i<=J;i++)
                 {
                                   printf("%d ",mat[1][j]);
                 }
                 printf("\n\n");
                 }


                 printf("\n\nFINAL\n\n");
                 for(i=0;i<=J;i++)
                 {
                                   printf("%d ",mat[0][j]);
                 }
                 for(i=0;i<=J;i++)
                 {
                                   printf("%d ",mat[1][j]);
                 }

                 printf("%d\n",mat[row][I]);

    }
return 0;
}
/* @END_OF_SOURCE_CODE */
