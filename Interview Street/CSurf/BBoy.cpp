/* Enter your code here. Read input from STDIN. Print output to STDOUT *//* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n, a, b;
        scanf("%d",&n);
        if(n==1) {
            printf("0 0\n");
            continue;
        }
        for(a = 1; a <= n; ++a)
            if(n % a == ((n-1)/2)) break;

        for(b = n/2; b <= n; ++b)
            if(n % b == ((n-1)/2)) break;
        printf("%d %d\n",a, b);
    }
}
