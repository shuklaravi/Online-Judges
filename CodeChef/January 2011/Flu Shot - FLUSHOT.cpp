#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

double diff, inp[10005];
int N;
bool ispossible(double val)
{
	double prev=0.0;
	int i;
	prev=max(0.0, inp[0]-val);
	for(i=1;i<N;i++)
	{
		if(prev+diff-inp[i] > val)
				return false;
		prev=max(inp[i]-val,prev+diff);
	}
	return true;
}

int main()
{
	double min,max,mid,ans;
	int t,i;
	cin>>t;
	while(t--)
	{
		scanf("%d%lf",&N,&diff);
		for(i=0;i<N;i++)
			scanf("%lf",&inp[i]);
		min=0.0, max=1e14; ans=0.0;
		while(max-min > 1e-8)
		{
			mid=(min+max)/2.0000f;
			if(ispossible(mid))
				max=mid , ans=mid;
			else	min=mid;
			//if(min==max)
			//	break;
		}

		/*for(i=0;i<N;i++)
			cout<<inp[i]<<" ";
		cout<<endl;*/
		printf("%.4lf\n",ans);

	}
	return 0;
}
