#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
    double n=100;
    cin>>n;
    long long qs,sq=n*n*(n+1)*(n+1)/4.00;
    qs=n*(n+1)*((2*n)+1)/6.00;
    cout<<(sq-qs);
    cin>>n;
return 0;
}
