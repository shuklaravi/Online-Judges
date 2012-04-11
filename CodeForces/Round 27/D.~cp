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
vector<pair<int, int> > road;
bool check(int i, int j)
{
        int a = (road[i].first - road[j].first) * (road[i].second - road[j].first);
        int b = (road[i].first - road[j].second) * (road[i].second - road[j].second);
        int c = (road[j].first - road[i].first) * (road[j].second - road[i].first);
        int d = (road[j].first - road[i].second) * (road[j].second - road[i].second);
        if(a == 0 || b == 0 || c == 0 || d == 0)
                return false;
        if((a < 0) ^ (b < 0))
                return true;
        if((c < 0) ^ (d < 0))
                return true;
}

int main()
{
    int n,i,j,k,rr,p,q,r;
    cin>>n>>r;
    REP(i,r)
    {
        cin>>p>>q;
        if(p>q) swap(p,q);
        PB(road,MP(p,q));
    }
    vector<int> vis(r,-1);
    stack<int> s;
    bool flag=0;
    REP(i,r)
    {
        if(vis[i]==-1)
        {
            vis[i]=1;
            s.push(i);
            while(!s.empty())
            {
                int t=s.top();
                s.pop();
                REP(j,r)
                {
                    if(road[j]==road[t]) continue;
                    if(check(j, t))
                    {
//                        cout<<"\nintersect "<<i<<" "<<j<<endl;
                        if(vis[j]==-1)
                        {
                            vis[j]=1-vis[t];
                            s.push(j);
                        }
                        else if(vis[j]==vis[t])
                        {
                            cout<<"Impossible";
                            return 0;
//                            flag=1;
//                            break;
                        }
//                        if(road[j].c==1-t.c) break;
                        
                    }
                }
                if(flag==1) break;
            }
        }
        if(flag==1) break;
    }
    REP(i,r)
    if(vis[i]==1) cout<<"i";
    else cout<<"o";
//	system("pause"); //Windows Only
	return 0;
}



// NOT MY SOLUTION BUT STILL WORNG

/*

#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<sstream>
#include<deque>
#include<math.h>
#include<cstring>
#include <bitset>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>

#define all(v) v.begin(),v.end()
#define mpair make_pair

using namespace std;
vector<int> al[110];


int e[110][2];
int col[110];


int dfs(int v){
        for(int i=0;i<(int)al[v].size();i++)
        {
                if( col[ al[v][i] ] == -1)
                {
                        col[al[v][i]] = (col[v]==1)?0:1;
                        if( dfs(al[v][i])==0) return 0;
                }else if( col[ al[v][i] ] + col[v]!=1){
                      //cout<<al[v][i]<<" " << v<<endl;
                        return 0;
                }
       }
        return 1;
}
int main(){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
                cin>>e[i][0]>>e[i][1];
                int tmp;
                if( e[i][0]>e[i][1]){
                        tmp=e[i][0];e[i][0]=e[i][1];e[i][1]=tmp;
                }
        }
        for(int i=0;i<m;i++)
                for(int j=i+1;j<m;j++)
                {
                        if( ( e[i][0]<e[j][0] && e[j][0]<e[i][1] && e[j][1]>e[i][1]) ||
                            ( e[j][0]<e[i][0] && e[i][0]<e[j][1]) && e[i][1]>e[j][1] )
                        {
                               al[i].push_back(j);
                                al[j].push_back(i);
                        }
                }
        memset(col,-1,sizeof(col));
                bool imposs=0;
        for(int i=0;i<m;i++)
                        if( col[i]==-1) {
                                col[i]=0;
                                if( dfs(i)==0) {
                                        imposs=1;
                                        break;
                                }
                        }
                if( imposs)
                cout<<"Impossible"<<endl;
        else{
        for(int i=0;i<m;i++)
                if( col[i]==0)
                        cout<<"i";
               else
                        cout<<"o";
        cout<<endl;
                }
        return 0;
}
*/
