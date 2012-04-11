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
using namespace std;
#define GI ({int _t; scanf("%d", &_t); _t;})
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define REP(i, a) FOR(i, 0, a)
#define sz size()
#define pb push_back
#define cs c_str()
#define DBGV(_v) { REP(_i, _v.sz) { cout << _v[_i] << "\t";} cout << endl;}

# define LLD unsigned long long int

int mygcd(int a ,int b){
    return b?mygcd(b,a%b):a ;}

int main(){
    int n,m,diff,csum;LLD tcases;
    cin>>tcases;
    while(tcases--){
                    cin>>n>>m;
                    diff=abs(n-m);
                    csum=n+m;
                    int t=mygcd(diff,csum);
                    diff /=t;csum /=t;
                    cout<<diff<<"/"<<csum;
                    if(tcases)
                    cout<<endl;
                    }
 /// for output .. delete pls...
    return 0;
}
