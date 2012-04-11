#include<iostream>
#include<algorithm>

using namespace std;

int arr[200]={0};

int main()
{
for(int i=0;i<200;i++)
arr[i]=i*i;

int p1,p2;
while(cin>>p1)
{
cin>>p2;



bool chance=true;
int turn=0;
int flag=0;
while(1)
{
// cout<<"\np1:"<<p1<<" p2:"<<p2;

// withdraw frm 1

if(p1<=0) {flag=1;//cout<<"\nbreak p1";
break;}
else {
int i=0;
while(p1>=arr[i]) i++;
int maxwithdraw=arr[i-1];
// cout<<"\nmax wid="<<maxwithdraw;
p1=p1-maxwithdraw;
flag=0;


}



/// widthdraw frm 2
if(p2<=0) {flag=1;//cout<<"\nbreak p2";
break;}
else {
int i=0;
while(p2>=arr[i]) i++;
int maxwithdraw=arr[i-1];
//cout<<"\nmax wid="<<maxwithdraw;
p2=p2-maxwithdraw;
flag=0;

}

if(flag==0) {turn++; chance=!chance;//cout<<"\nchange chance"<<chance;
//getchar();
}






}

if(flag==1) { chance=!chance;
if(chance==true) cout<<"A";
else cout<<"B";

cout<<" will win after "<<turn<<" move";
if(turn>1) cout<<"s";
else ;
cout<<".\n";
}


}


return 0;

}
