using namespace std;
# include<iostream>
# include<cstdio>
# include<cstring>

int main()
{
    int n,val,total,dec,add,arr[30],temp,num;
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
         num=n;
         dec=0;
         total=32;

         //Finds the 32-bit binary equivalent
         while(total>0)
         {
              val=n&(-2147483648);

              if(val==(-2147483648))
                   val=1;

           //   printf("%d",val);
              arr[33-total]=val;
              n=n<<1;
              total--;
         }

         //these 2 loops swap the bytes 1,4 and 2,3
         for(i=1,j=25;i<=8;i++,j++)
         {
              temp=arr[i];
              arr[i]=arr[j];
              arr[j]=temp;
         }

         for(i=9,j=17;i<=16;i++,j++)
         {
              temp=arr[i];
              arr[i]=arr[j];
              arr[j]=temp;
         }

         //this converts to the decimal number
         total=32;
         while(total>0)
         {
              if(arr[33-total]==0)
              {
                   total--;
                   continue;
              }
              add=1;
              for(i=1;i<total;i++)
              add=add<<1;
                   dec=dec|add;
              total--;
         }
         printf("%d converts to %d\n",num,dec);
    }
    return 0;
}
