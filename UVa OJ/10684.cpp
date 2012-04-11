#include <iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
		break;
		int arr[n],i;
		for(i=0;i<n;i++)
		cin>>arr[i];
//		dp[0]=arr[0];
		int max=0;
		for(i=1;i<n;i++)
		{
			if(arr[i]<(arr[i-1]+arr[i]))
			arr[i]=(arr[i-1]+arr[i]);
			max=arr[i]>max?arr[i]:max;
		}
		if(max>0)
		cout<<"The maximum winning streak is "<<max<<".\n";
		else
		cout<<"Losing streak.\n";
	}
	return 0;
}
