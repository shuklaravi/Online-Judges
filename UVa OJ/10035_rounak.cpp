using namespace std;
# include<iostream>
# include<cstdio>
# include<cstring>

int main()
{
    unsigned long long a,b,temp;
    int pos,carry,sum,i,arr1[15],arr2[15],flag=1;
    while(scanf("%llu %llu",&a,&b) && (a!=0 || b!=0))
    {
         sum=0;
         pos=-1;
         carry=0;
         if(a<b)
         {
                temp=a;
                a=b;
                b=temp;
         }
         while(a!=0)
         {
              arr1[++pos]=a%10;
              a/=10;
         }
         for(i=0;i<=pos;i++)
         {
              if(b==0)
                   arr2[i]=0;
              else
              {
                   arr2[i]=b%10;
                   b/=10;
              }
              sum=arr1[i]+arr2[i]+sum;
              if(sum>9)
              {
                   carry++;
              }
              sum=sum/10;
         }
         if(carry==0)
              printf("No carry operation.\n");
         else if(carry==1)
              printf("%d carry operation.\n",carry);    
         else 
              printf("%d carry operations.\n",carry);             
    }
    return 0;
}
