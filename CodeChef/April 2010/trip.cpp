/* @BEGIN_OF_SOURCE_CODE */
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int trip[100005],fwd[100005],rev[100005]; // ADD EXTRA ZERO...................
    long long tank,N,M;
    long long i,j,stopf=0,stopr;
    scanf("%ld %ld",&N,&tank);
    M=tank;
    for(i=0;i<N;i++)
    cin>>trip[i];
    N--;
    for(i=0;i<N;i++ )
    {
                    (trip[i+1]-trip[i]>M)?(M=tank-trip[i+1]+trip[i],fwd[stopf++]=i) : (M-=trip[i+1]+trip[i]);
    }
    N++;
    M=tank;
    stopr=stopf-1;
    for(i=N-1;i>0;i--)
    {
                    (trip[i]-trip[i-1]>M)?(rev[stopr--]=i,M=tank-trip[i]+trip[i-1]) : (M-=trip[i]-trip[i-1]);
    }
    long long ans=1;
    for(i=0;i<stopf;i++)
    {
                        ans=((ans%1000000007)*((fwd[i]-rev[i]+1)%1000000007))%1000000007;
    }
    printf("%ld ",stopf);
    printf("%ld\n",ans);
    getchar();
    getchar();
return 0;
}
/* @END_OF_SOURCE_CODE */
