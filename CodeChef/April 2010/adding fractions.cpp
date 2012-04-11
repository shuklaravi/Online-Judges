#include <cstdio>
long long gcd(long long a, long long b)
{
    if (b == 0)
       return a;
    else
       return gcd(b, a%b);
}
inline void putint(long long n) {
char buffer[100];
long long i=0,n2;
do{
n2=n/10;
buffer[i++]=n-(n2<<3)-(n2<<1)+'0';
}while((n=n2)) ;
while(i)
putchar(buffer[--i]);
}
using namespace std;
int main()
{
    
    long long ip_N[1000005],ip_D[1000005];
    long long T,N,i,j;
    long long temp;
    char ch;
    scanf("%ld",&T);
    while(T--)
    {
              scanf("%ld",&N);
              
              long long ans_N[N+1],ans_D[N+1];
              for(i=0;i<N;i++)
              scanf("%ld%c%ld",&ip_N[i],&ch,&ip_D[i]);
              ans_N[N-1]=ip_N[N-1];
              ans_D[N-1]=ip_D[N-1];
              for(i=N-2;i>-1;i--)
              {
                                 if(ip_N[i]/ip_D[i] > ((ip_N[i]+ans_N[i+1])/(ip_D[i]+ans_D[i+1])) )
                                 {
                                                    ans_N[i]=ip_N[i];
                                                    ans_D[i]=ip_D[i];
                                 }
                                 else
                                 {
                                                    ans_N[i]=ip_N[i]+ans_N[i+1];
                                                    ans_D[i]=ip_D[i]+ans_D[i+1];
                                 }
              }
              for(i=0;i<N;i++)
              {
                              temp=gcd(ans_N[i],ans_D[i]);
                              ans_N[i]/=temp;
                              ans_D[i]/=temp;
//                              putint(ans_N[i]);
  //                            putchar('/');
    //                          putint(ans_D[i]);
      //                        putchar('\n');
                              printf("%ld/",ans_N[i]);
                              printf("%ld\n",ans_D[i]);
                              }
              if(N!=0)
              putchar('\n');
    }
return 0;
}
