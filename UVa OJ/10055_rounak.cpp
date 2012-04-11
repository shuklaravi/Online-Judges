using namespace std;
# include<iostream>
# include<cstdio>
# include<cstring>

int main()
{
    long long int n1,n2;
    while(scanf("%ld",&n1)!=EOF && scanf("%ld",&n2)!=EOF)
         printf("%ld\n",n1>n2?n1-n2:n2-n1);
    return 0;
}
         
