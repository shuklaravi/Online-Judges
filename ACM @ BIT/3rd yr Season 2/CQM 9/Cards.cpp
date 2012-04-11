    ////anmolkapooor
//// HI !!!!! TRYING TO CODE... IF POSSIBLE.. PLEASE IGNORE THE ERRORS..!!1
//// QUESTION:

#include <cmath>
#include <cstdio>
#include <cctype>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define GI ({int _t; scanf("%d", &_t); _t;})
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define REP(i, a) FOR(i, 0, a)
#define sz size()
#define pb push_back
#define cs c_str()
#define DBGV(_v) { REP(_i, _v.sz) { cout << _v[_i] << "\t";} cout << endl;}

//using maps now...

int main()
{
int n;
while(cin>>n)
{
    bool flag=1;
    long long i,j,maxx=-999;
    string str,final;
    map<string,long long> person;
    map<string,long long>:: iterator it; // iterator...
    for (int i=0;i<n;i++)
    {
        cin>>str;
        long long p;
        cin>>p;
        if(flag!=0)
        {
            if(str=="Arka")
                flag=0;
            person[str]+=p;
            if(maxx<person[str])
            {
                maxx=person[str];
                final=str;
            }
        }
    }
    if(flag==0)
        cout<<"Arka"<<endl;
    else
        cout<<final<<endl;
}
return 0;
}
