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

bool isSquare(int64 A){
     int64 root = (int64)sqrt(A);
     if( root * root == A )
         return true;
     return false;
}

int main(){
    freopen("q1i.txt", "r", stdin);
    freopen("q1o.txt", "w", stdout);
    int64 i;
    /*
    const int64 MAX = (int64)INT_MAX;
    int64 MLIM = (int64)sqrt(MAX), i;
    set<int64> square;
    set<int64>::iterator it;
    FOI(i, 0, MLIM)
           square.insert(i*i);
    */
    int N;
    cin >> N;
    while( N-- ){
           int64 X;
           cin >> X;
           int64 LIM = (int64)sqrt(X);
           int64 ans = 0;
           FOI(i, 0, LIM){
                  int64 lo = i * i;
                  int64 hi = X - lo;
                  if( isSquare(hi) && hi>=LIM && hi<=X && hi>=lo )
                      ans++;
           }
           cout << ans << endl;
    }
    return 0;
}
