/*
Author : Continuum
Date   : 2010-09-24

*/


//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<bitset>


//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;


#define FOR(i,a,b)                            for(int i=a;i<b;i++)
#define REP(i,n)                            FOR(i,0,n)
#define pb                                push_back
#define s(n)                                scanf("%d",&n)
#define sl(n)                                 scanf("%lld",&n)
#define sf(n)                                 scanf("%lf",&n)
#define fill(a,v)                             memset(a, v, sizeof a)
#define sz                                size()
#define INF                                (int)1e9
#define EPS                                1e-9
#define bitcount                            __builtin_popcount
#define all(x)                                x.begin(), x.end()
#define gcd                                __gcd


typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef vector<string> VS;
typedef pair<int, int > PII;

/*Main code begins now */

int m,n;
vector<vector<int> > adjList;
int visited[10005];
int heights[10005];

int dfs(int i)
{
    if(visited[i]==1) return -1;
    if(visited[i]==2) return heights[i];
    visited[i]=1;

    int its=0;
    for(int j=0;j<adjList[i].size();j++)
    {
        int temp=dfs(adjList[i][j]);
        if(temp<0) return -1;
        its=max(its,temp);
    }
    visited[i]=2;
    heights[i]=its+1;

    return its+1;
}

int solve()
{
    int height=0;
    REP(i,n)
        if(!visited[i])
        {
            int temp=dfs(i);
            if(temp<0) return -1;
            height=max(height,temp);
        }
        return height;
}



int main()
{
    int t; s(t);
    while(t--)
    {
        adjList.clear();
        fill(visited,0);
        fill(heights,0);

        s(n),s(m);
        adjList.resize(n);
        REP(i,m)
        {
            int a, b;
            s(a),s(b);
            a--; b--;
            adjList[a].pb(b);
        }

        int ans=solve();
        if(ans<0)
            cout<<"IMPOSSIBLE\n";
        else
            printf("%d\n",ans);

    }
}
