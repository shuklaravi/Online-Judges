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

int main()
{


    long long P,C,I;
    while (cin>>P>>C>>I) {
          long long mon = 0;
          long long tot = 1;
          long long prof = 0;
          while (1) {
                mon++;
                prof+=P*tot;
                if (prof>=C) {

                         tot += prof/C;
                         prof=prof%C;


                }
                if (tot>I)
                   break;
          }
          long long y = mon/12;
          long long m = mon%12;
          if (y==1) {
                    cout<<y<<"year";
                    if(m>=1)
                    cout<<" ";
          }
          if (y > 1) {
                 cout<<y<<"years";
                 if(m>=1)
                    cout<<" ";
          }
          if (m==1) {
                    cout<<m<<"month";

          }
         if (m > 1) {
                 cout<<m<<"months";

          }
          cout<<endl;





    }
    return 0;
}





