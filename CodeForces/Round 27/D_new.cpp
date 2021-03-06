using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
//BEGIN_TEMPLATE_BY_PRATYUSH_VERMA
#define INF (1<<31)-1
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
typedef long long ll;
inline string i2s(int number) { stringstream ss; ss << number; return ss.str(); }
//END_TEMPLATE_BY_PRATYUSH_VERMA
int road[105][2];
int vis[105];
int n,m,i,j,k,p,q;
bool dfs(int I)
{
    stack<int> s;
    s.push(I);
    while(!s.empty())
    {
        int t=s.top();
        s.pop();
//        cout<<"\npopped "<<t<<endl;
        REP(i,m)
        {
            if(t==i) continue;
            if( !(( road[t][0]<road[i][0] && road[i][0]<road[t][1] && road[i][1]>road[t][1]) ||
                            ( road[i][0]<road[t][0] && road[t][0]<road[i][1]) && road[t][1]>road[i][1] ))
                            {
//                                cout<<"\nno conflict found in "<<i<<" "<<t<<endl;
                                continue;
                            }
            if(vis[i]==-1)
            {
//                cout<<"\n coloring node "<<i<<" to color = "<<1-vis[t]<<endl;
                vis[i]=1-vis[t];
                s.push(i);
            }
            else if(vis[i]==vis[t])
            {
//                cout<<"\nCONFLICT\n";
                return true;
            }
            else if(vis[i]==1-vis[t])
            {
//                cout<<"\n node "<<i<<"  already colored = "<<vis[i]<<endl;
                continue;
            }
//            else cout<<"\nERROR\n";
        }
    }
    return false;
}
int main()
{
    cin>>n>>m;
    MEM(road,0);
    MEM(vis,-1);
    REP(i,m)
    {
        cin>>road[i][0]>>road[i][1];
        if(road[i][0]>road[i][1]) swap(road[i][0],road[i][1]);
    }
    REP(i,m)
    {
        if(vis[i]==-1)
        {
            vis[i]=1;
//            cout<<"\n starting from node "<<i<<"color = "<<1<<endl;
            if(dfs(i))
            {
                cout<<"Impossible";
//                system("pause");
                return 0;
            }
        }
    }
//    cout<<"\nFINAL COLOR\n";
//    REP(i,m)
//    cout<<vis[i]<<" ";
//    cout<<endl;
    REP(i,m)
    if(vis[i]==1) cout<<"i";
    else cout<<"o";
//	system("pause"); //Windows Only
	return 0;
}






















