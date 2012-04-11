
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
