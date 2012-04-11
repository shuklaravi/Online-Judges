#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <bitset>

//BEGINTEMPLATE_BY_TOKENS
typedef long long LL;
typedef long double LD;
typedef unsigned long long UL;

//FUN_ _
#define SIZE(X) ((int)(X.size())) //NOTES:SIZE(
#define L(X) ((int)(X.length())) //NOTES:LENGTH(
#define MAX(i,j) (i)>(j)?(i):(j)
#define MIN(i,j) (i)<(j)?(i):(j)
#define FOR(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define REP(i,a) for((i)=0;(i)<(a);(i)++)
#define MEM(m,i) memset((m),(i),SZ(m))
#define PB(x,y) (x).push_back(y)
#define MP(x,y) make_pair(x,y)
const int MaxMatrixSize=40;
using namespace std;
template<class T> inline T checkMod(T n,T m) {return (n%m+m)%m;} //NOTES:checkMod(
template<class T> inline T gcd(T a,T b) //NOTES:gcd(
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b) //NOTES:lcm(
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline void showMatrix(int n,T A[MaxMatrixSize][MaxMatrixSize])//NOTES:showMatrix(
{for (int i=0;i<n;i++){for (int j=0;j<n;j++)cout<<A[i][j];cout<<endl;}}

//@niteshvishnoi.................//
LL count1 ( LL num)
{
LL sum=0,bit=64;
while(num && bit)
{
if(num&0x0000000000000001)
sum++;
num>>=1;
bit--;
}
return sum;
}

int main()
{
        freopen("input_test_2.in" , "r" , stdin);
    freopen("output_test_2_nitesh.out" , "w" , stdout);
UL n,q,i;
scanf("%llu%llu",&n,&q);
int indx = n/64;
indx++;
LL flip[indx];
memset(flip,0,sizeof(flip));
REP(i,q)
{
bool state;
LL strt,end;
cin>>state;
scanf("%llu%llu",&strt,&end);
if(!state)
{
int a1=strt/64;
int a2=strt%64;
int b1=end/64;
int b2=end%64;
int j,k=0;
LL val;
if(a2>31)
{
k=a2-32;
val=0xFFFFFFFF00000000LL;
val<<= k;
}
else
{
val=0xFFFFFFFFFFFFFFFFLL;
val = val<<a2;
}
flip[a1]^=val;
FOR(j,a1+1,b1)
flip[j]^=-1;
if(b2<32)
{
val=0x00000000FFFFFFFFLL;
k=31-b2;
val>>= k;
}
else
{
if(b2==63)
val=0xFFFFFFFFFFFFFFFFLL;
else
{
val=0x7FFFFFFFFFFFFFFFLL;
k=63-b2-1;
val>>= k;
}
}
flip[b1]^=val;
if(a1==b1)
flip[a1]^=0xFFFFFFFFFFFFFFFFLL;
}
else
{
int a1=strt/64;
int a2=strt%64;
int b1=end/64;
int b2=end%64;
int j,k=0;
LL val,val1,cnt=0;
if(a2>31)
{
k=a2-32;
val=0xFFFFFFFF00000000LL;
val<<=k;
}
else
{
val=0xFFFFFFFFFFFFFFFFLL;
val<<=a2;
}
val&=flip[a1];
if(a1!=b1)
{
cnt+=count1(val);
}
FOR(j,a1+1,b1)
{
cnt+=count1(flip[j]);
}
if(b2<32)
{
val1=0x00000000FFFFFFFFLL;
k=31-b2;
val1>>=k;
}
else
{
if(b2==63)
val1=0xFFFFFFFFFFFFFFFFLL;
else
{
val1=0x7FFFFFFFFFFFFFFFLL;
k=63-b2-1;
val1>>= k;
}
}
val1&=flip[b1];
if(a1==b1)
{
val&=val1;
cnt=count1(val);
}
else
{
cnt+=count1(val1);
}
printf("%lld\n",cnt);
}
}
return 0;
}
