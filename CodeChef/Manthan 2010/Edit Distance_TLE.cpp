/* @BEGIN_OF_SOURCE_CODE */
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
int main()
{

    int test;
    int l1,l2,i,j,I,J;
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
                                  temp="";
                                  scanf("%c%d",&ind[i],&in[i]);
                                  for(j=0;j<in[i];j++)
                                  {
                                                     temp.push_back(ind[i]);
                                  }
                                  a.append(temp);
                 }
                 scanf("\n");

//                 cout<<a<<endl;
                 b="";
                 scanf("%d ",&l2);
                 for(i=0;i<l2;i++)
                 {
                                  scanf("%c%d",&ind1[i],&in1[i]);
                                  temp="";
                                  for(j=0;j<in1[i];j++)
                                  {
                                                      temp.push_back(ind1[i]);
                                  }
                                  b.append(temp);
                 }
//                 scanf("\n");

                 for(i=0;i<l2;i++)
                 {
                 }
//                 cout<<b<<endl;
                 int alen=a.length();
                 int blen=b.length();
//                 vector< vector<int> > mat(blen+1, vector <int> (alen+1) );
                 for(i=0;i<=blen;i++)
                 {
                                   mat[i][0]=i;
                 }
                 for(i=0;i<=alen;i++)
                 {
                                   mat[0][i]=2*i;
                 }
                 for(i=0;i<blen;i++)
                 {
                                     for(j=0;j<alen;j++)
                                     {
                                                         if(b[i]==a[j])
                                                         {
//                                                                           cout<<"\nsame"<<i<<" "<<j<<" "<<endl;
                                                                           mat[i+1][j+1]=mat[i][j];
                                                         }
                                                         else
                                                         {
//                                                             cout<<"\ndiff"<<endl;
//                                                             mat[i+1][j+1]=mat[i+1][j]+2;
                                                             mat[i+1][j+1]=min(mat[i][j+1]+1,mat[i+1][j]+2);
                                                         }
                                     }
                 }
/*
                 for(i=0;i<=blen;i++)
                 {
                                   for(j=0;j<=alen;j++)
                                   printf("%d ",mat[i][j]);
                                   printf("\n");
                 }
*/
                 printf("%d\n",mat[blen][alen]);
    }
return 0;
}
/* @END_OF_SOURCE_CODE */
