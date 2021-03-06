/*
ID: vermapr1
PROG: <prog_name>
LANG: C++
*/

// #define TRUE FALSE haha now debug this
using namespace std;
#include <algorithm>
#include<bitset>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
//BEGIN_TEMPLATE_BY_PRATYUSH_VERMA

//CONSTANT
#define INF (1<<31)-1
#define PI 3.1428571428571428571428571428571

//FUNC
#define MAX(i,j) (i)>(j)?(i):(j)
#define MIN(i,j) (i)<(j)?(i):(j)
#define REP(i,a) for((i)=0;(i)<(a);(i)++)
#define REP_(i,a) for((i)=0;(i)<=(a);(i)++)
#define FOR(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define FOR_(i,a,b) for((i)=(a);(i)<=(b);(i)++)
#define VAR(V,init) __typeof(init) V=(init)
#define FOREACH(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((int)(x.size()))
#define LENGTH(x) ((int)(x.length()))
#define SZ(x) sizeof(x)
#define MEM(m,i) memset((m),(i),SZ(m))
#define PB(x,y) (x).push_back(y)
#define MP(x,y) make_pair(x,y)
#define V(x) vector < x >

//BITWISE
#define LASTSETBIT(x) x & ~(x-1)
#define TRAILZERO(x) __builtin_ctz(x)
#define LEADZERO(x) __builtin_clz(x)
#define COUNTSETBIT(x) __builtin_popcount(x)
#define GCD(x,y) __gcd(x,y)

typedef pair<int,int>   PII;
typedef pair<char,int>  PCI;
typedef pair<int,PII>   TRI;
typedef V( int )        VI;
typedef V( PII )        VII;
typedef V( TRI )        VTRI;
typedef V( string )     VS;
typedef long long       LL;
typedef long double     LD;

template<class T> void print(const vector<T> &v){ostringstream os; for(int i=0; i<v.size(); ++i){if(i)os<<' ';os<<v[i];} cout<<os.str()<<endl;}
template<class T, class U> T cast (U x) { ostringstream os; os<<x; T res; istringstream is(os.str()); is>>res; return res; }
template<class T> vector<T> split(string s, string x=" ") {vector<T> res; for(int i=0;i<s.size();i++){string a; while(i<(int)s.size()&&x.find(s[i])==string::npos)a+=s[i++]; if(!a.empty())res.push_back(cast<T>(a));} return res;}

inline void input( int &n ) { n=0; int ch=getchar(); while( ch < '0' || ch > '9' ) ch=getchar(); while( ch >= '0' && ch <= '9' ) n = (n<<3)+(n<<1) + ch-'0', ch=getchar(); }

//END_TEMPLATE_BY_PRATYUSH_VERMA

#include <cstdlib>
#include <iostream>
#include<vector>

using namespace std;


string sumar(string n1, string n2){
    string num1;
    string num2;

    string resultado;
    int sizeNum2;

    int carry = 0;
    int diff = 0;
    int nTemp1;
    int nTemp2;
    int rTemp;
    if(n1.size() <= n2.size()){
          num1 = n1;
          num2 = n2;

    }
    else{
         num2 = n1;
         num1 = n2;
    }

    sizeNum2 = num2.size();

    resultado.resize(num2.size(), ' ');
    diff = num2.size()  - num1.size();

    for(int i = sizeNum2 -1; i >= 0; i--){
            if(i-diff >= 0){

                nTemp1 = num1[i-diff] - 48;
            }
            else{
                nTemp1 = 0;
            }
            nTemp2 = num2[i] - 48;
            rTemp = nTemp1 + nTemp2 + carry;

            if(rTemp >= 10){
                resultado[i] = (rTemp - 10 )+ 48 ;
                carry = 1;
            }
            else{
                 resultado[i] = rTemp + 48 ;
                 carry = 0;
            }
    }

    if(carry == 1){
             string uno = " ";
             uno[0] = 49;
             resultado = uno + resultado;
    }
    return resultado;
}
# define MAX_LENGTH 1000
char* subtract(string X,string Y)
 {
      char *A =(char*) X.c_str();
     char *B=(char*) Y.c_str();


    if (strlen(A) < strlen(B))
    {
       strrev(A);

       while(strlen(A)<strlen(B))
      strcat(A,"0");

       strrev(A);
    }

    if (strlen(B) < strlen(A))
    {
       strrev(B);

       while(strlen(B)<strlen(A))
      strcat(B,"0");

       strrev(B);
    }

    int length=strlen(A);

    int borrow=0;
    int difference=0;
    int digit_1=0;
    int digit_2=0;

    char Difference[5]={NULL};
    char Result[MAX_LENGTH]={NULL};

    strset(Result,NULL);
    strrev(A);
    strrev(B);

    for(int i=0;i<length;i++)
    {
       digit_1=(int(A[i])-48);
       digit_2=(int(B[i])-48);

       difference=(digit_1-digit_2-borrow);

       if(difference<0)
       {
      difference+=10;
      borrow=1;
       }

       else
      borrow=0;

       itoa(difference,Difference,10);
       strcat(Result,Difference);
    }

    while(Result[(strlen(Result)-1)]=='0')
       Result[(strlen(Result)-1)]=NULL;

    strrev(Result);

    return Result;
 }


bool great(string K,string S) {
    if (




int main()
{
    long long test,N,K;
    char ch;
    cin>>test;

    while (test--) {
        cin>>ch>>N>>K;
        string S="1";
        for ( int i = 0; i< N;i++) {
            S = sumar(S,S);
        }
        cout<<S<<endl;
        bool flag = true;
        while (S!="1") {
            //string newS = div(S,2);
            if ( great(K,S)) {
                K = sub(K,S);
            }
         //   S = div(S,2);
        }
    }



    }*/


    return 0;
}





























