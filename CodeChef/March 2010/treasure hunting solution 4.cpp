#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#define N 13
#define M 13
#define K 8192
#define INF 0x6fffffff
using namespace std;

bool map[N+2][N+2];
int step[N+2][N+2];
int d[4][2] = {0,1, 1,0, 0,-1, -1,0};
int base[14] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,K};

void flood(int x,int y){
    int i;
    bool yet[N+2][N+2] = {0};
    queue<pair<int,int> > work;
    pair<int,int> now;
    work.push (make_pair(x,y));
    yet[x][y] = 1;
    step[x][y] = 0;
    while(!work.empty()){
        now = work.front();
        work.pop();
        for(i=0; i<4; i++){
            if(yet[now.first+d[i][0]][now.second+d[i][1]] || !map[now.first+d[i][0]][now.second+d[i][1]])
                continue;
            work.push (make_pair(now.first+d[i][0],now.second+d[i][1]));
            yet[now.first+d[i][0]][now.second+d[i][1]] = 1;
            step[now.first+d[i][0]][now.second+d[i][1]] = step[now.first][now.second] + 1;
        }
    }
}

int main(){
    int T;
    scanf("%d", &T);

    int n, i, j, p;
    char x;
    vector<pair<int,int> > point;
    int psize;
    int len[M+2][M+2];
    vector<pair<int,int> > state[M];
    bool inque[M][K];
    int qsize;
    int way[M][K];
    int ans;
    while(T--){
        scanf("%d\n", &n);
        for(i=0; i<=n+1; i++)
            map[i][0] = map[i][n+1] = map[0][i] = map[n+1][i] = 0;
        point.clear();
        point.push_back (make_pair(1,1));
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                scanf("%c", &x);
                map[i][j] = (x != '#');
                if(x == '*'){
                    point.push_back (make_pair(i,j));
                }
            }
            scanf("\n");
        }
        point.push_back (make_pair(n,n));
        if(n==1){
            printf("0\n");
            continue;
        }
        psize = point.size();

        for(j=0; j<psize; j++){
            flood (point[j].first , point[j].second);
            for(i=j+1; i<psize; i++){
                len[i][j] = len[j][i] = step[point[i].first][point[i].second];
                if(len[i][j]==0)
                    break;
            }
            if(i<psize)
                break;
        }
        if(j<psize){
            printf("-1\n");
            continue;
        }

        for(i=0; i<psize-2; i++){
            state[i].clear();
            for(j=0; j<base[psize-2]; j++)
                way[i][j] = INF;
        }
        for(i=0; i<psize-2; i++){
            state[0].push_back (make_pair(i,base[i]));
            way[i][base[i]] = len[0][i+1];
        }
        for(i=0; i<psize-2; i++){
            qsize = state[i].size();
            memset(inque, 0, sizeof(inque));
            for(j=0; j<qsize; j++)
                for(p=0; p<psize-2; p++)
                    if( (state[i][j].second/base[p]) % 2==0){
                        if( !inque[p][state[i][j].second+base[p]] ){
                            inque[p][state[i][j].second+base[p]] = 1;
                            state[i+1].push_back (make_pair(p,state[i][j].second+base[p]));
                        }
                        way[p][state[i][j].second+base[p]] <?= way[state[i][j].first][state[i][j].second]
                                                               + len[state[i][j].first+1][p+1];
                    }
        }
        ans = INF;
        for(i=0; i<psize-2; i++)
            ans <?= way[i][base[psize-2]-1] + len[i+1][psize-1];

        printf("%d\n", ans);
    }

    //system("pause>nul");
    return 0;
}
