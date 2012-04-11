
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
#define REP(i,a) for((i)=0;(i)<(a);(i)++)
#define FOR(i,a,b) for((i)=(a);(i)<(b);(i)++)
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
//END_TEMPLATE_BY_PRATYUSH_VERMA
using namespace std;
struct node {
	int n;
	node *next;
	node() {
		n=-1;
		next=NULL;
	}
};
struct data {
	char seq[4];
	int freq;
	data(char s[4], int i) {
		strcpy(seq,s);
		freq=i;
	}
};
int main()
{
ios_base::sync_with_stdio(0);
freopen("BDFS-in.txt" , "r" , stdin);
freopen("BDFS-op.txt" , "w" , stdout);
struct node *arr=new node[26];
int i,j=-1,k,p,q;
string str[100];
while(cin>>str[++j])
{
//	j++;
//	cin>>i;
//	if(i==-1) break;
//	cin>>str[j];
	for(k=0;k<str[j].length();k++)
	{
		int sz=arr[str[j][k]-'a'].n;
		node *temp=&arr[str[j][k]-'a'];
		while(sz-->=0)
		{
			temp=temp->next;
		}
		temp->next=new node();
		temp=temp->next;
		temp->n=j;
		temp->next=NULL;
		arr[str[j][k]-'a'].n++;
//		cout<<str[j]<<endl;
	}
}
for(i=0;i<j;i++)
cout<<i<<" :"<<str[i]<<endl;

char ord[100];
int ind=0;
for(i=0;i<26;i++)
{
	int sz=arr[i].n;
	node *temp=&arr[i];
	if(sz<0) continue;
	ord[ind++]='a'+i;
	cout<<(char) (i+'a')<<" : "<<sz<<endl;

	temp=temp->next;
	while(sz-->=0)
	{
		cout<<temp->n<<" ";
		temp=temp->next;
	}
	cout<<endl;

}

int mat[100][100][10];
memset(mat,0,sizeof(mat));
for(i=0;i<ind;i++)
{
	for(j=0;j<=i;j++)
	{
		if(i==j) mat[i][j][0]=arr[ord[i]-'a'].n+1;
		else
		{
			node *temp=&arr[ord[i]-'a'];
			if(temp->n<=0) continue;
			temp=temp->next;
			do
			{
				int x=temp->n;
				for(int y=0;y<str[x].length();y++)
				{
//					cout<<"testing : "<<x<<" "<<str[x]<<endl;
					if(str[x][y]==ord[j]) 
					{
						mat[i][j][0]++;
//						cout<<"matched "<<x<<":"<<str[x]<<"..."<<ord[j]<<" in "<<(char)(i+'a')<<endl;
						break;
					}
				}
				temp=temp->next;
			}while(temp!=NULL);
		}
	}
}
/*vector<data> sequ;
for(j=0;j<ind;j++)
{
	for(i=j+1;i<ind;i++)
	{
		for(int x=j+1;x<ind;x++)
		{
			if(x==i) continue;
			char str[4];
			str[0]=(char)(ord[j]);
			str[1]=(char)(ord[i]);
			str[2]=(char)(ord[x]);
			str[3]='/0';
			data temp(str,mat[i][j]+mat[x][j]-mat[j][j]);
			sequ.push_back(data (str,temp));
		}
	}
}
for(i=0;i<sequ.size();i++)
{
	cout<<sequ[i].str<<" "<<sequ[i].freq<<" -- ";
}
cout<<endl;
*/for(i=0;i<ind;i++)
{
	for(j=0;j<=i;j++)
	{
		cout<<mat[i][j][0]<<" ";
	}
	cout<<endl;
}
system("pause");
return 0;
}
