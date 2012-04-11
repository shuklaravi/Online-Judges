#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;
struct node{int ttl,n;
node(int a,int tty){ttl=tty;n=a;}
};

int main()
{
int n,a,b,c=1;
ifstream i("input.txt");
ofstream o("op.txt");
while((i>>n)!=0)
{
   
    map<int, vector<int> > adj;
    map<int,int> visited,copy; map<int,int>::iterator it;set<int> s;set<int>::iterator it1;
    int max;
    while(n--){
    i>>a>>b;
    visited[a]=0;
    visited[b]=0;
    s.insert(a);
    s.insert(b);
    adj[a].push_back(b);
    adj[b].push_back(a);    
    }
    int q1,q2;
    copy=visited;
    while(i>>q1>>q2 && (q1||q2))
    {
    queue<node> q;
    q.push(node(q1,0));
    visited[q1]=1;
    int tt;
    while(!q.empty())
    {
      int temp=q.front().n;
      tt=q.front().ttl;
      q.pop();
      if(tt==q2)break;
      for(int i=0;i<adj[temp].size();i++)
      if(visited[adj[temp][i]]==0){q.push(node(adj[temp][i],tt+1));visited[adj[temp][i]]=1;}
    }
    int cnt=0;
    for(it=visited.begin();it!=visited.end();it++)if((*it).second==0)cnt++;
    o<<"Case "<<c<<": "<<cnt<<" nodes not reachable from node "<<q1<<" with TTL = "<<q2<<'\n';
    c++;
    visited=copy;
    }
    }
    i.close();
    o.close();
    system("pause");
    return 0;
}
