using namespace std;
#include<iostream>
#include<cstdio>
#include<bitset>
#include<string>
#include<map>
int main()
{   string S; int M,a,h; long long D;
    map<string,int> val;
    map<int,string> dir;
    val["North"]=0;    val["East"]=1;    val["South"]=2;    val["West"]=3;
    dir[0]="North";    dir[1]="East";    dir[2]="South";    dir[3]="West";
    while(cin>>S>>M>>D)
    { a=val[S]; 
      bitset<50> B(D);
      h=(int)(B.count()); 
      a+=h%4; 
      a+=(4-((M-h)%4))%4; 
      a%=4;
      cout<<dir[a]<<endl;
    }
    return 0;
}
                       
