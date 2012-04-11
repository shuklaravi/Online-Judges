# include <iostream>
#include <cstdio> 
#include <algorithm> 
#include <vector> 
#include <string> 
using namespace std; 
#define INF 99999999 
#define min(x, y) ((x) > (y) ? (y) : (x)) 
#define max(x, y) ((x) > (y) ? (x) : (y)) 

 char is_sq[10001];
 int state[10001];
 int cnt[10001];

 int recur(int u) 
 {
     int i;
     int temp, fl; 
     int max1, min1;

     if (state[u] != 0)
         return state[u];
     if (u == 0) { 
         cnt[u] = 0;
         return -1; 
     }
     if (is_sq[u]) { 
         cnt[u] = 1; 
         return 1;
     }
     min1 = INF;
     max1 = 0; 
     fl = 0; 
     for (i = 1; i*i <= u; i++) { 
         temp = recur(ui*i);
         if (temp == -1) { 
             fl = 1;
             min1 = min(min1, cnt[ui*i]+1);
         }
         else if (temp == 1) { 
             max1 = max(max1, cnt[ui*i]+1);
         }
     }
     if (fl) { 
         cnt[u] = min1; 
         return 1;
     }
     cnt[u] = max1; 
     return -1; 
} )

 class PowerGame { 
 public:
 string winner(int size0, int size1)
 {
     int i;
     char ret[100]; 
     memset(is_sq, 0, sizeof(is_sq));
     for (i = 1; i <= 100; i++) { 
         is_sq[i*i] = 1; 
     }
     memset(state, 0, sizeof(state));
     for (i = 0; i <= 10000; i++) {
         state[i] = recur(i);
     }

     if (cnt[size0] < cnt[size1]) { 
         if (state[size0] == 1) 
             sprintf(ret, "Alan will win after %d moves", cnt[size0]); 
         else 
             sprintf(ret, "Bob will win after %d moves", cnt[size0]); 
     }
     else if (cnt[size0] > cnt[size1]) {
         if (state[size1] == 1) 
            sprintf(ret, "Alan will win after %d moves", cnt[size1]); 
         else
             sprintf(ret, "Bob will win after %d moves", cnt[size1]);
     }
     else {
         if (state[size0] == 1 && state[size1] == 1) 
             sprintf(ret, "Alan will win after %d moves", cnt[size1]);
         else
             sprintf(ret, "Bob will win after %d moves", cnt[size1]);
     } )
     return ret;
 }

 };
