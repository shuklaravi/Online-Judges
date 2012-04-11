/*
ID: vermapr1
PROG: <prog_name>
LANG: C++
*/

// #define TRUE FALSE haha now debug this
using namespace std;

#include <iostream>

//BEGIN_TEMPLATE_BY_PRATYUSH_VERMA

//CONSTANT
#define EPS 1e-11
#define INF (1<<31)-1
#define PI 3.1428571428571428571428571428571

//FUNC
#define MAX(i,j) (i)>(j)?(i):(j)
#define MIN(i,j) (i)<(j)?(i):(j)
#define REP(i,a) for((i)=0;(i)<(a);(i)++)
#define REP_(i,a) for((i)=0;(i)<=(a);(i)++)
#define FOR(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define FOR_(i,a,b) for((i)=(a);(i)<=(b);(i)++)
#define VAR(V,init) __typeof(init) V=(init)
#define FOREACH(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((int)(x.size()))
#define LENGTH(x) ((int)(x.length()))
#define SZ(x) sizeof(x)
#define MEM(m,i) memset((m),(i),SZ(m))
#define PB(x,y) (x).push_back(y)
#define MP(x,y) make_pair(x,y)
#define V(x) vector < x >

//BITWISE
#define LASTSETBIT(x) x & ~(x-1)
#define TRAILZERO(x) __builtin_ctz(x)
#define LEADZERO(x) __builtin_clz(x)
#define COUNTSETBIT(x) __builtin_popcount(x)
#define GCD(x,y) __gcd(x,y)



//END_TEMPLATE_BY_PRATYUSH_VERMA
int n,m,k,nn,mm;
int maze[105][105];
bool vis[105][105];
struct node {
    int i,j,k;
    node(int a, int b, int c)
    {
        i=a;j=b;k=c;
    }
    node() {}
};
bool is_in(int a, int b)
{
    if(a<=0 || a>n || b<=0 || b>m) return false;
    return true;
}
int dir[]={0,1,2,3};
void dfs(int i, int j, int k)
{
    cout<<"in finc "<<i<<" "<<j<<" "<<k<<endl;
    bool flag;
    int ii,dd;
    vis[i][j]=1;
        if(i == nn && j==mm)
        {
            cout<<" in destination \n";
            maze[j][i] = (maze[j][i]+1)%k;
            cout<<i<<" "<<j<<"...............";
            return ;
        }
        vis[i][j]=true;
        dd=k;
        flag=false;
        REP(ii,2)
        {
            if(flag)
            {
                dd=(k+1)%4;
            }
            int xx, yy;
            if(dd==0)
            {
                xx=i;
                yy=j+1;
            }
            else if(dd==1)
            {
                xx=i+1;
                yy=j;
            }
            else if(dd==2)
            {
                xx=i;
                yy=j-1;
            }
            else if(dd==3)
            {
                xx=i-1;
                yy=j;
            }
            flag=true;
            if(!is_in(xx,yy)) continue;
            if(vis[xx][yy]) continue;
            if(maze[xx][yy]==-1) continue;
            cout<<"calling "<<xx<<" "<<yy<<" "<<dd<<endl;
            dfs(xx,yy,dd);
            vis[xx][yy]=false;
        }
        cout<<"exiting func "<<i<<" "<<j<<" "<<k<<endl;
//        getchar();
}
int main()
{
    cin>>n>>m>>k;
    MEM(vis,false);
    int asd,p,i,j,k;
    MEM(maze,0);
    cin>>nn>>mm;
    cin>>p;
    REP(asd,p)
    {
        cin>>i>>j;
        maze[j][i]=-1;
    }
    dfs(1,1,0);
    cout<<maze[mm][nn]%k<<endl;
	system("pause");
	return 0;
}














