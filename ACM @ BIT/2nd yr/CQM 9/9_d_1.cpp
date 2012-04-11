# include <iostream>
using namespace std;

int main()
{

int I;

int X,K;

int test;
cin>>test;

while (test--)
{
long long arr[10001]={1};

cin>>X>>K;
arr[X]=1;


for (I=X;I>=2;I--)
{arr[I-1]=(arr[I-1]%1000007+arr[I]%1000007)%1000007;arr[I-2]=(arr[I-2]%1000007+arr[I]%1000007)%1000007;arr[I-3]=(arr[I-3]%1000007+arr[I]%1000007)%1000007;}




cout<<arr[K]<<endl;



}















}


