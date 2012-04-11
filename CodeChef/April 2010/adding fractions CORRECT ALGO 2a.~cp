#include<cstdio>
struct FRAC
{
	int num, den;
	float val;
};
typedef struct FRAC frac;
int gcd(int a, int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int t, i, n,j,tmp;
	char str[50];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		frac num[n], ans[n];
		int ptr[n];
		for(i=0; i<n; i++)
		{
			scanf("%s",str);
			num[i].num=num[i].den=0;
			for(j=0;str[j]!='/';j++)
			num[i].num=num[i].num*10+str[j]-'0';
			for(j++; str[j]!='\0'; j++)
			num[i].den=num[i].den*10+str[j]-'0';
			num[i].val=(float)num[i].num/num[i].den;
//			printf("%d %d %f\n",num[i].num,num[i].den,num[i].val);
		}
//		printf("\n");
		for(i=n-1; i>=0; i--)
		{
			ans[i]=num[i];
			ptr[i]=i;
			j=i+1;
			while(ans[i].val<ans[j].val&&j<n)
			{
				ans[i].num+=ans[j].num;
				ans[i].den+=ans[j].den;
				ans[i].val=(float)ans[i].num/ans[i].den;
				ptr[i]=ptr[j];
				j=ptr[i]+1;
			}
		}
		for(i=0;i<n;i++)
		{
		tmp=gcd(ans[i].num,ans[i].den);
		printf("%d/%d\n",ans[i].num/tmp,ans[i].den/tmp);
		}
		if(t)
		printf("\n");
	}
	return 0;
}

