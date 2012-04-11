#include <cstdio>
#include <cstdlib>
#include <queue>
#define MAX 8192
#define L 13
#define S 600     // list2num("0001001011000")=600
using namespace std;

queue<int> work;

struct node{
    int len, n, a, father;
    bool p;
    char list[L+1];
} map[MAX];

int list2num(char* l){
    int i, ans = 0, base = 1;
    for(i=L-1; i>=0; i--){
        if(l[i] == '1')
            ans += base;
        base *= 2;
    }
    return ans;
}

void rot(int xn,int p1,int p2,int p3,int p4,int p5,int p6,int q,int t){
    int num;
    char line[L+1], tmp = map[xn].list[p6];
    strcpy(line, map[xn].list);
    line[p6] = line[p5];
    line[p5] = line[p4];
    line[p4] = line[p3];
    line[p3] = line[p2];
    line[p2] = line[p1];
    line[p1] = tmp;
    num = list2num(line);

    if(map[num].p == 1)
        return;

    map[num].p = 1;
    map[num].len = map[xn].len + 1;
    map[num].n = q;
    map[num].a = t;
    map[num].father = xn;
    strcpy(map[num].list, line);
    work.push(num);
}

void print(int num){
    printf("%d\n", map[num].len);
    int now = num;
    while(now != S){
        printf("%d %d\n", map[now].n, map[now].a);
        now = map[now].father;
    }
}

int main(){
    int T;
    scanf("%d\n", &T);

    map[S].len = 0;
    map[S].p = 1;
    strcpy (map[S].list , "0001001011000");

    int x;
    work.push(S);
    while (!work.empty()){
        x = work.front();
        work.pop();

        rot(x, 0,3,6,8,5,2, 0,0);
        rot(x, 2,5,8,6,3,0, 0,1);
        rot(x, 1,4,7,9,6,3, 1,0);
        rot(x, 3,6,9,7,4,1, 1,1);
        rot(x, 6,9,11,12,10,8, 2,0);
        rot(x, 8,10,12,11,9,6, 2,1);
    }

    int pro;
    char s[L+1];
    while(T--){
        scanf("%s\n", s);
        print(list2num(s));
    }

    //system("pause>nul");
    return 0;
}
