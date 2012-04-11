using namespace std;
# include<iostream>
# include<cstdio>
# include<cstring>
bool isdiv(long long int cop,long long int x)
{
     int rem;
     while(x!=0)
     {
          rem=x%10;
          x=x/10;
          if(rem!=0)
          {
               if(cop%rem==0)
                    continue;
               else
                    return false;
          }
     }
     return true;
}


int main()
{
    long long int num,n,val,dig,newnum;
    while(scanf("%lld",&num)!=EOF)
    {
         if(isdiv(num,num))
         {
              printf("%lld\n",num);
              continue;
         }
         n=num;
         val=10;
         dig=0;
         while(1)
         {
                 newnum=(num*val)+dig;
              //   cout<<newnum<<endl;
                 if(isdiv(newnum,n))
                 {
                      printf("%lld\n",newnum);
                      break;
                 }
                 dig++;
                 if(dig==val)
                 {
                      val*=10;
                      dig=0;
                 }
         }
    }
    return 0;
}

