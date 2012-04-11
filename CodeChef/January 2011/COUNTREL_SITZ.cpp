#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;

#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
#define REP(i, N)    for(i=1; i<=N; i++)
#define INF    INT_MAX
#define EPS    1e-10
#define sqr(x) (x)*(x)
#define MOD    100000007

int64 power(int64 A, int64 B){
      if(B == 1)
           return A;
      int64 V = power(A, B/2);
      if(B%2 == 0)
             return ( V%MOD * V%MOD )%MOD;
      else
          return ( V%MOD * V%MOD * A%MOD )%MOD;
}

int main(){
    int T;
    cin >> T;
    while(T--){
               int64 N;
               cin >> N;
               N++;
               int64 R1 = ( ( 1 ) + ( power(3, N-1) ) - ( power(2, N) ) )%MOD;
               if(R1%2==0)
                R1 = R1 / ( int64 ) 2;
               else
                R1 = ( R1 + MOD ) / ( int64 ) 2;
               if(R1 < 0)
                R1 += MOD;
               int64 R2 = ( ( power(4, N - 1 ) ) - ( power(3, N) ) + ( 3 * power(2, N - 1 ) ) - ( 1 ) )%MOD;
               if ( R2 % 2 == 0 )
                R2 = R2 / ( int64 ) 2;
               else
                R2 = ( R2 + MOD ) / ( int64 ) 2;
               if(R2 < 0)
                R2 += MOD;
               cout<< R1 << " " << R2 << endl;
    }
    return 0;
}
