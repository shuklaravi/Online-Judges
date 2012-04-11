//DS includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<bitset>
#include<complex>

//Other Includes
#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>



#define oo 					(int)13e7
#define getcx getchar_unlocked
inline void s( int &n )
{
	n=0;
	int ch=getcx();
	while( ch < '0' || ch > '9' ) ch=getcx();

	while(  ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
}
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define fill(a,v) 				memset(a, v, sizeof a)
#define ull 					unsigned long long
#define ll 						long long
#define bitcount 			__builtin_popcount
#define all(x) 				x.begin(), x.end()
#define pb( z ) 				push_back( z )
#define gcd					__gcd
using namespace std;


const int mxn = 100007;
struct fract
{
	ull a, b;
	inline void put( ull X, ull Y )
	{
		a=X; b=Y;
	}
	inline void put( int X, int Y )
	{
		a=X; b=Y;
	}
	bool operator < ( const fract& f ) const
	{
		return a*(f.b) < b*(f.a);
	}
	fract operator + ( const fract& z ) const
	{
		fract f;
		f.put( a+z.a, b+z.b );
		return f;
	}
};
fract a[mxn];
fract sol[mxn];
int nxt[mxn];
int main()
{
	int runs;
	s( runs );
	while( runs-- )
	{
		int n;
		s( n );

		for(int i=0; i < n; i++)
		{
			int x, y;
			s( x ); s( y );
			a[i].put( x, y );
		}

		sol[n-1] = a[n-1];
		nxt[n-1] = n;
		for(int i=n-2; i >= 0; --i)
		{
			sol[i] = a[i];
			int &z = nxt[i];
			z = i+1;
			fract tmp = a[i];
			while( z < n )
			{
				fract tmp2 = tmp+sol[z];
				tmp = tmp2;
				if( sol[i] < tmp )
				{
					sol[i] = tmp;
					z = nxt[z];
				}
				else
					break;
			}

		}

		for(int i=0; i < n; i++)
		{
			ll D = gcd( sol[i].a, sol[i].b );
			printf("%llu/%llu\n", sol[i].a / D, sol[i].b / D );
		}
		puts("");
	}
	return 0;
}
