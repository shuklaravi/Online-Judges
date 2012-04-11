#include<iostream>
using namespace std;
int main(){
freopen("B_new1.in" , "r" , stdin);
freopen("B_new1_szk.txt" , "w" , stdout);

long long num=0,c,b,t,k,i,n,x[55],v[55];
cin>>c;
while(c--){
long long c1=0,count=0;
cin>>n>>k>>b>>t;
for(i=0;i<n;i++)cin>>x[i];
for(i=0;i<n;i++)cin>>v[i];
for(i=n-1;i>=0;i--){
if(x[i]+v[i]*t<b)count++;
else c1+=count;
if(n-i-count==k)break;
}

cout<<"Case #"<<++num<<": ";
if(n-count<k)cout<<"IMPOSSIBLE\n";
else cout<<c1<<endl;
}
return 0;

}
