#include<iostream>

using namespace std;

int main()
{
long long a,b;
while(cin>>a)
{

cin>>b;

long long m,n;
m=a;n=b;
int d1,d2;
d1=0,d2=0;
long long count=0;
long long flag=0;
while(m && n)
{
d1=m%10;
d2=n%10;
// cout<<d1<<" "<<d2<<endl;
if((d1==8)&&(d2==8)) count++;

m=m/10;n=n/10;
//cout<< m<< " "<<n<<endl;
}

if(( m==0) && (n!=0)) cout<<0<<endl;
else if(( m!=0) && (n==0)) cout<<0<<endl;
else
cout<<count<<endl;
}

return 0;
}
