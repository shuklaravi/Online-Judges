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

#define INF    INT_MAX
#define EPS    1e-10
#define sqr(x) (x)*(x)

int main(){
    string str;
    while ( cin >> str ){
          if( str == "0" )
               break;
          int L = str.length();
          int64 vec[L+1];
          memset( vec, 0, sizeof vec);
          int i, j;
          vec[L] = 1;
          FOD(i, L-1, 0){
                 if( str[i] != '0' )
                     vec[i] = vec[i+1];
                 if( i < L-1 && str[i] != '0' ){
                     int num = (str[i] - '0') * 10 + (str[i+1] - '0');
                     if( num >= 1 && num <= 26 )
                            vec[i] += vec[i+2];
                 }
          }
          cout << vec[0] << endl;
    }
    return 0;
}
