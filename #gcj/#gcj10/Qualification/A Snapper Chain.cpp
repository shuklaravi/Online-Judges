#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
	int res_no=0;
	int N,K,t;
	scanf("%d",&t);
	while(t--)
	{
		res_no++;
		int max=pow(2.0,N);
		scanf("%d%d",&N,&K);
		if(K>max)
		K=K%max;
		max--;
		if(max==K)
		printf("Case #%d: ON\n",res_no);
		else
		printf("Case #%d: OFF\n",res_no);
	}
	return 0;
}
