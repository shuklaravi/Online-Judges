using namespace std;
# include<iostream>
# include<cstdio>

int arr[100];
bool c[100],cfinal[100];
int tracks,n,counts=0,limit,sum,oldsum=0;

void display()
{
     int i,sums=0;
     
     if(sum!=n)
     {
          for(i=0;i<tracks;i++)
          {
               if(cfinal[i]==true)
               {
                    sums+=arr[i];
                    printf("%d ",arr[i]);
               }
          }
          printf("sum:%d\n",sums);
          return;
     } 
     
     for(i=0;i<=limit;i++)
     {
          if(c[i]==true)
               cout<<arr[i]<<" ";
     }
     printf("sum:%d\n",n);
}
int totalVal(int x)
{
     int i;
     int s=0;
     for(i=0;i<=x;i++)
     {
          if(c[i]==true)
               s+=arr[i];
     }
     return s;
}

void comb(int k)
{
     int i;
     if(k==tracks)
     {
          sum=totalVal(k);
          if(sum>oldsum && sum<n)
          {
               for(i=0;i<k;i++)
                    cfinal[i]=c[i];
               oldsum=sum;
          }
          return;
     }
     else
     {
          c[k]=true;
          sum=totalVal(k);
          if(sum<n)
               comb(k+1);
          if(sum==n)
          {
               counts++;
               if(counts==1)
                    limit=k;
               return;
          }
          
          
          c[k]=false;
          comb(k+1);
     }
}

int main()
{
     int i;
     while(scanf("%d",&n)!=EOF)
     {
          counts=0;
          oldsum=0;
          scanf("%d",&tracks);
          for(i=0;i<tracks;i++)
               scanf("%d",&arr[i]);
               sort(arr,arr+tracks);
          comb(0);
          display();
     }
     return 0;
}
