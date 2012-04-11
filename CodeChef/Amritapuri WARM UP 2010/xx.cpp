#include <stdio.h>
#include <string.h>

int F[ 10001 ] ;
char set[ 10001 ] ;

int main () {
	int test ;
	scanf("%d",&test ) ;
	int a, b ;
	int n , m ;
	int max ;
	bool p ;
	while ( test -- ) {
		scanf("%d%d",&n,&m) ;
		memset ( set , 0 , sizeof(set)) ;
		max = 0 ;
		p = false ;
		for ( int i = 0 ; i < m ; i ++ ) {
			scanf("%d%d",&a,&b) ;
			if ( set[a] == 1 && set[b] == 1 ) {
				if ( !( F[a] < F[b]) ) {
					if ( !p ) {
						printf("IMPOSSIBLE\n") ; p = true ;
				       	}
				}
			} else if ( set[a] == 1 ) {
				F[b] = F[a] + 1 ;
				set[b] = 1 ;
				if ( F[b] > max ) { max = F[b] ; }
			} else if ( set[b] == 1 ) {
				F[a] = F[b] - 1 ;
				set[a] = 1 ;
			} else {
				F[a] = 1 ;
				F[b] = 2 ;
				set[a] = 1 ;
				set[b] = 1 ;
				if ( F[b] > max ) { max = F[b] ; }
			}
		}
		if ( !p ) {
			printf("%d\n",max ) ;
		}
	}
	return 0 ;
}
