#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long int64;

const int maxn=1000+5;
int m,s,n,A[maxn];
int G[maxn],Q[maxn];
int64 S[maxn];

int64 solve()
{
	memset(G,255,sizeof(G));
	int p=0;
	Q[0]=G[0]=S[0]=0;
	for (int i=1;i<=m;i++)
	{
		int oldp=p,left=s;
		for (;p-oldp<n && left>=A[p%n];p++) left-=A[p%n];
		Q[i]=p;
		S[i]=S[i-1]+(s-left);
		if (G[p%n]>=0)
		{
			int64 c=i-G[p%n];
			int64 d=S[i]-S[G[p%n]];
			int64 R=S[i];
			R+=(m-i)/c*d;
			R+=S[G[p%n]+(m-i)%c]-S[G[p%n]];
			return R;
		}
		G[p%n]=i;
	}
	return S[m];
}
int main()
{
//	freopen("C.in","r",stdin);
//	freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
//	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
	freopen("C_1299_large.in","r",stdin);freopen("C-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	for (int caseId=1;caseId<=testcase;caseId++)
	{
		scanf("%d%d%d",&m,&s,&n);
		for (int i=0;i<n;i++) scanf("%d",&A[i]);
		int64 R=solve();
		cout<<"Case #"<<caseId<<": "<<R<<endl;
	}
	return 0;
}
