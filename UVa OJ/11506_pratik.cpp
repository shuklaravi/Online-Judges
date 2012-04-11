#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<sstream>
#include<set>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>



#define oo 					(int)13e7
#define s(n)					scanf("%d",&n)
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
int m, w;
const int mxn = 512;
int a[mxn][mxn];
vector<int> adjl[mxn];
int q[mxn], vis[mxn], prev[mxn], vid;
void clear()
{
	fill( a, 0 );
	for(int i=0; i < mxn; i++)
		adjl[i].clear();
}
int src, sink;
int in( int x )
{

	return x;
}
int out( int x )
{

	return x+50;
}
inline void addEdge( int F, int T, int W)
{
	a[F][T] = W;

	adjl[F].pb( T );
	adjl[T].pb( F );
}
int flow()
{
	++vid;
	int r=0, f=0, reach=0;
	q[r++] = src;
	vis[src] = vid;
	prev[src] = src;
	while( r != f )
	{
		int z = q[f++];
		if( z == sink )
		{
			reach = 1;break;
		}
		int zsz=adjl[z].size();
		for(int i=0; i < zsz;++i)
		{
			int ai = adjl[z][i];
			if( vis[ai] != vid )
			if( a[ z ][ ai ] > 0 )
			{
				vis[ai] = vid;
				prev[ai] = z;
				q[r++] = ai;
			}
		}
	}
	if( !reach )
		return 0;
	int bneck = int(2e9); //find flow
	for(int i=sink; i != src; i = prev[i] )
	{
		bneck = min( bneck, a[ prev[i] ][ i ] );
	}
	//augment paths
	for(int i=sink; i != src; i = prev[i] )
	{
		a[ prev[i] ][ i ] -= bneck;
		a[ i ][ prev[i] ] += bneck;
	}
	return bneck;
}
int main()
{
	while( true )
	{

		scanf("%d %d", &m, &w );
		if( (m|w) == 0 )
			break;
		clear();
		src = 1, sink = m;
		addEdge( in(src), out(src), 0);
		addEdge( in(sink), out(sink), 0 );
		src = out( 1 );
		sink = in( m );
		for(int i=2; i <= m-1; i++)
		{
			int W, id;
			if(~s( id )); else exit(0);
			if(~s( W )); else exit(0);
			addEdge( in(id), out(id), W);
		}
		while( w-- )
		{
			int j, k, d;
			s( j );s( k ); s( d );


			addEdge( out(k), in(j), d);
			addEdge( out(j), in(k), d);
		}
		/*
		for(int i=0; i < mxn; i++)
		{
			sort( all( adjl[i] ) );
			unique( all( adjl[i] ) );
		}*/


		int z, ans =0;
		while( (z=flow()) >  0 )
		{
//            cout<<vid<<"\n";;
			ans += z;
		}
		printf("%d\n", ans );

	}
	return 0;
}
