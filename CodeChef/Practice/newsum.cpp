#include<iostream>
using namespace std;
long long power(long long x,long long y)
{
long long b=x, r=1, e=y;
while(e)
{
if(e&1)
r=(r*b)%8388608;
b=(b*b)%8388608;
e>>=1;
}
return r%8388608;
}
int main()
{
    long long n=0,x=0,y=0,z=0;
    int t=0;
    scanf("%d",&t);
    while(t--)
    {
    scanf("%lld",&n);
    x=n%8388608;
    x=((x*(x-1))%8388608+2)%8388608;
    y=power(2,n-1);
    //cout<<x<<"\n"<<y<<"\n";
    x=(x*y)%8388608;
    printf("%lld\n",(x-1+8388608)%8388608);
    }
    //system("PAUSE");
    return 0;
}
