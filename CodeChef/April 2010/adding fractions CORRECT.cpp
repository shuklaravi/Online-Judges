#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;

/*========================================Templates=============================================*/
#define REP(i,n)		for(int i=0;i<(n);++i)
#define FOR(i,a,b)		for(int i=(a);i<=(b);++i)
#define FORN(i,a,b,n)	for(int i=(a);i<=(b);i+=n)
#define FORD(i,a,b)		for(int i=(a);i>=(b);--i)
#define FORDN(i,a,b,n)	for(int i=(a);i>=(b);i-=n)
#define FOREACH(i,c)	for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define ALL(x)			(x).begin(),(x).end()
//#define S(n)			scanf("%d",&n)
#define S2(n1,n2)		scanf("%d %d",&n1,&n2)
#define S3(n1,n2,n3)	scanf("%d %d %d",&n1,&n2,&n3)
#define SL(n)			scanf("%lld",&n)
#define SD(n)			scanf("%f",&n)
#define SS(a)			scanf("%s",a)
#define DB(x)			cout<<#x<<" : "<<x<<endl;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UINT;
ULL gcd( ULL a, ULL b ) {  if( !b ) return a;  return gcd( b, a % b ); }

//===================================================================================
int sign;
int ch;
inline void S( int &x )
{
			x=0;
			while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)	ch=getchar_unlocked();
			if (ch=='-')
				sign=-1 , ch=getchar_unlocked();
			else
				sign=1;

			do
				x=(x<<3)+(x<<1)+ch-'0';
			while((ch=getchar_unlocked())>='0' && ch<='9');
			x*=sign;
}
//===================================================================================

/*===============================================================================================*/

#define MAX 100007
int n;
struct Fraction
{
	int p,q;
};
Fraction inp[MAX];
Fraction msum[MAX];

int dp[MAX]={0};

int main()
{
	int tc;
	S(tc);
	while(tc--)
	{
		S(n);
		FOR( i , 1 , n )
			S(inp[i].p) , S(inp[i].q);

		dp[n]=n;
		msum[n].p=inp[n].p;
		msum[n].q=inp[n].q;

		int t;
		FORD( i , n-1 , 1 )
		{
			t=i+1;
			msum[i] = (Fraction){ inp[i].p , inp[i].q };
			while ( (LL)msum[i].p * msum[t].q < (LL)msum[i].q * msum[t].p && t<=n )
			{
				msum[i] = (Fraction){ msum[i].p + msum[t].p , msum[i].q + msum[t].q };
				t=dp[t]+1;
			}
			dp[i]=t-1;
		}

		FOR( i , 1 , n )
		{
			t=gcd(msum[i].p,msum[i].q);
			printf( "%d/%d\n" , (msum[i].p)/t , (msum[i].q)/t );
		}
		if (tc)	printf("\n");
	}
	return 0;
}






