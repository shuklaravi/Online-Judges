#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;


int calc(int x,int y,int m)
{

int a[4]={0};

a[0]= abs(1-x)+abs(1-y);
a[1]= abs(1-x)+abs(m-y);
a[2]= abs(m-x)+abs(1-y);
a[3]= abs(m-x)+abs(m-y);
// for(int i=0;i<4;i++) cout<<"\n:"<<a[i];
return *min_element(a,a+4);
}
int main()
{
int n;
while(cin>>n)
{
int m=0;
cin>>m;
int x[1000]={0},y[1000]={0};
for(int i=0;i<m;i++) cin>>x[i];
for(int i=0;i<m;i++) cin>>y[i];
int total=0;
for(int i=0;i<m;i++)
{
// cout<<"\nfor "<<x[i]<<y[i]<<" "<<calc(x[i],y[i],n);
total=total+calc(x[i],y[i],n);


}

cout<<total<<endl;

}



return 0;
}
