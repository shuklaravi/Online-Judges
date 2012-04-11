#include<iostream>
#include<algorithm>
using namespace std;

int main()
{

int n;

cin>>n;
int input[101][3];
int actual[101]={0};
int result[101]={0};
for(int i=0;i<n;i++)
{
cin>>input[i][0];
cin>>input[i][1];
actual[i]=input[i][0];
result[i]=input[i][0]+input[i][1];
}

int count=0;
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
if(result[i]==actual[j]) count++;

}



}

if(count==2) cout<<"YES"<<endl;
else cout<<"NO"<<endl;
return 0;
}
