#include <iostream>
  2 #include <cstdio>
  3 #include <algorithm>
  4 #include <vector>
  5 #include <string>
  6 using namespace std;
  7 #define INF 99999999
  8 #define min(x, y) ((x) > (y) ? (y) : (x))
  9 #define max(x, y) ((x) > (y) ? (x) : (y))
 10
 11 char is_sq[10001];
 12 int state[10001];
 13 int cnt[10001];
 14
 15 int recur(int u)
 16 {
 17     int i;
 18     int temp, fl;
 19     int max1, min1;
 20
 21     if (state[u] != 0)
 22         return state[u];
 23     if (u == 0) {
 24         cnt[u] = 0;
 25         return -1;
 26     }
 27     if (is_sq[u]) {
 28         cnt[u] = 1;
 29         return 1;
 30     }
 31     min1 = INF;
 32     max1 = 0;
 33     fl = 0;
 34     for (i = 1; i*i <= u; i++) {
 35         temp = recur(u-i*i);
 36         if (temp == -1) {
 37             fl = 1;
 38             min1 = min(min1, cnt[u-i*i]+1);
 39         }
 40         else if (temp == 1) {
 41             max1 = max(max1, cnt[u-i*i]+1);
 42         }
 43     }
 44     if (fl) {
 45         cnt[u] = min1;
 46         return 1;
 47     }
 48     cnt[u] = max1;
 49     return -1;
 50 }
 51
 52 class PowerGame {
 53 public:
 54
 55 string winner(int size0, int size1)
 56 {
 57     int i;
 58     char ret[100];
 59     memset(is_sq, 0, sizeof(is_sq));
 60     for (i = 1; i <= 100; i++) {
 61         is_sq[i*i] = 1;
 62     }
 63     memset(state, 0, sizeof(state));
 64     for (i = 0; i <= 10000; i++) {
 65         state[i] = recur(i);
 66     }
 67
 68     if (cnt[size0] < cnt[size1]) {
 69         if (state[size0] == 1)
 70             sprintf(ret, "Alan will win after %d moves", cnt[size0]);
 71         else
 72             sprintf(ret, "Bob will win after %d moves", cnt[size0]);
 73     }
 74     else if (cnt[size0] > cnt[size1]) {
 75         if (state[size1] == 1)
 76             sprintf(ret, "Alan will win after %d moves", cnt[size1]);
 77         else
 78             sprintf(ret, "Bob will win after %d moves", cnt[size1]);
 79     }
 80     else {
 81         if (state[size0] == 1 && state[size1] == 1)
 82             sprintf(ret, "Alan will win after %d moves", cnt[size1]);
 83         else
 84             sprintf(ret, "Bob will win after %d moves", cnt[size1]);
 85     }
 86     return ret;
 87 }
 88
 89 };

