/* @BEGIN_OF_SOURCE_CODE */
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int test;
    int l1,l2,i,j,I,J,count;
    int mat[300][300];
    int in[4000],in1[4000];
    char ind[4000],ind1[4000];
//    char *a,*b,*temp;
    scanf("%d\n",&test);
    while(test--)
    {
                 string a,b,temp;
                 scanf("%d ",&l1);
                 a="";
                 for(i=0;i<l1;i++)
                 {
                                  scanf("%c%d",&ind[i],&in[i]);
                 }
                 scanf("\n");

//                 cout<<a<<endl;
                 b="";
                 scanf("%d ",&l2);
                 for(i=0;i<l2;i++)
                 {
                                  scanf("%c%d",&ind1[i],&in1[i]);
                 }
                 for(i=0;i<l2;i++)
                 {
                                  for(j=0;j<l1;j++)
                                  {
                                                   if(ind1[i]==ind[j])
                                                   {
                                                                      if(in1[i]>=in[j])
                                                                      {
//                                                                                       printf("in1[i]>=in[j] %d %c\n",in[i],ind[i]);
                                                                                       in1[i]-=in[j];
                                                                                       in[j]=0;
                                                                      }
                                                                      else
                                                                      {
  //                                                                        printf("in1[i]<in[j] %d %c\n",in[i],ind[i]);
                                                                          in[i]-=in1[j];
                                                                          in1[j]=0;
                                                                          
                                                                      }
                                                   }
                                  }
                 }
                 count=0;
                 for(i=0;i<l1;i++)
                 {
                                  if(in[i]==0)
                                  continue;
    //                              printf("%d %c\n",in[i],ind[i]);
                                  count+=(2*in[i]);
                 }
      //           printf("%d\n",count);
                 for(i=0;i<l2;i++)
                 {
                                  if(in1[i]==0)
                                  continue;
                                  count+=(in1[i]);
                 }
                 printf("%d\n",count);
    }
return 0;
}
/* @END_OF_SOURCE_CODE */
