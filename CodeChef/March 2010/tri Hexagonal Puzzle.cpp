#include <iostream>
#include <string.h>
using namespace std;

#define N 13

int const moves[2][3][7] = {
    {
        {0, 2, 5, 8, 6, 3, 0},
        {1, 3, 6, 9, 7, 4, 1},
        {6, 8, 10, 12, 11, 9, 6}
    },
    {
        {0, 3, 6, 8, 5, 2, 0},
        {1, 4, 7, 9, 6, 3, 1},
        {6, 9, 11, 12, 10, 8, 6}
    }
};

int q[1 << N], pr[1 << N][3], bit[N], d[1 << N];
bool used[1 << N];
char s[20];

int main() {
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    bit[0] = 1;
    for(int i = 1; i < 13; ++i)
        bit[i] = bit[i - 1] << 1;

    memset(used, false, sizeof used);
    memset(d, 0, sizeof d);

    int start = bit[3] | bit[6] | bit[8] | bit[9];
    int h = 0, t = 1;
    q[h] = start;
    used[start] = true;

    while (h < t) {
        int cur = q[h++];
        for(int sh = 0; sh < 2; ++sh)
            for(int wheel = 0; wheel < 3; ++wheel) {
                int msk = cur;
                for(int i = 1; i < 7; ++i) {
                    msk &= ~bit[moves[sh][wheel][i]];
                    if (cur & bit[moves[sh][wheel][i - 1]])
                        msk |= bit[moves[sh][wheel][i]];
                }
                if (!used[msk]) {
                    used[msk] = true;
                    q[t++] = msk;
                    d[msk] = d[cur] + 1;
                    pr[msk][0] = cur;
                    pr[msk][1] = sh ^ 1;
                    pr[msk][2] = wheel;
                }
            }
    }

    int tk;
    scanf("%d\n", &tk);
    while (tk --> 0) {
        gets(s);
        int v = 0;
        for(int i = 0; i < 13; ++i)
            if (s[i] == '1') v |= bit[i];

        printf("%d\n", d[v]);
        while (v != start) {
            printf("%d %d\n", pr[v][2], pr[v][1]);
            v = pr[v][0];
        }
    }

    return 0;
}
