#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <list>
#include <set>

using namespace std;

vector <int> store[100],bridge;
vector <int> :: iterator vt;
queue <int> q;
int color[100],prev[100],d[100],f[100],low[100];
int tim,flag;
list <int> art;
list <int> :: iterator it;

int root;
int dfs(int v);

int main()
{
//	freopen("in2.txt","r",stdin);
//	freopen("out2.txt","w",stdout);
    set<int> arti;
	int v,e,a,b,i,j;
	
	cin >> v >> e;
	
	for(i=1;i<=e;i++)
	{
		cin >> a >> b;
		store[a].push_back(b);
		store[b].push_back(a);
	}
	for(i=1;i<=v;i++)
	{
		color[i]=0;
		prev[i] = -1;
		low[i]=10000;
		d[i]=10000;
		f[i] = 10000;
	}
	int count,res;
	count=0;
	for(i=1;i<=v;i++)
	{
		if(color[i]==0)
		{
			count++;
			root = i;
			res = dfs(i);
			printf("\n");
		}
	}
	for(i=1;i<=v;i++)
	{
		printf("Vertex %d has discovery time %d and finishing time %d\n",i,d[i],f[i]);
	}
	art.unique();
	art.sort();
	for(it=art.begin();it!=art.end();it++)
		arti.insert(*it);//printf("%d is a articulation point\n",*it);
	
	if(res>=2) arti.insert(0);//printf("Root is an articulation point\n");
	else printf("Root is not an articulation point\n");
	int m,n;
	for(vt=bridge.begin();vt!=bridge.end();vt++)
	{
		m = *vt;
		vt++;
		n = *vt;
		printf("(%d,%d) is a bridge\n",m,n);
	}
	printf("ans = %d\n",arti.size());
	system("pause");
	return 0;
}

int dfs(int i)
{
	int c = 0;
	color[i]=1;
	tim++;
	d[i] = tim;
	low[i] = d[i];
	int t,p;
	for(t=0;t<store[i].size();t++)
	{
		p = store[i][t];
		if(color[p]==0)
		{
			prev[p] = i;
			if(i==root)c++;
			//printf("(%d,%d) is a tree edge\n",i,p);
			dfs(p);
			if(low[p]>=d[i])
			{
				if(low[p]>d[i])
				{
					bridge.push_back(i);
					bridge.push_back(p);
				}
                               if(i!=root)			
				art.push_back(i);
			}
                        if(low[p]<low[i])
			     low[i] = low[p];
		}
		else if(color[p]==1 && prev[i]!=p)
		{
        	if (d[p] < low[i]) 
  				low[i] = d[p];
		}
	}
	color[i]=2;
	tim++;
	f[i]=tim;
        if(i==root && c>1)
             art.push_back(i);
	return c;
}
