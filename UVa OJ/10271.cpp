#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int T,N,K;
	cin>>T;
	while(T--)
	{
		cin>>K>>N;
		K+=8;
		int i,j,stk[N];
		for(i=0;i<N;i++)
		{
			cin>>stk[i];
		}
		for(i=0;i<N-1;i++)
		stk[i]=(stk[i]-stk[i+1])<0?(stk[i+1]-stk[i]):0;
		sort(stk,stk+N-1);
		int res=0;
		for(i=0;i<N-1;i++)
		cout<<stk[i]<<" ";
		cout<<endl;
		for(i=0;i<(3*K);i+=3)
		{
			res+=((stk[i]-stk[i+1])*(stk[i]-stk[i+1]));
		}
		cout<<res<<endl;
	}
	return 0;
}
