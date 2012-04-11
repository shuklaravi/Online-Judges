#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <map>
#include <set>
using namespace std;
//BEGINTEMPLATE_BY_TOKENS
typedef long long       LL;
typedef long double     LD;
typedef unsigned long long       UL;
typedef pair<long,long> PL;

//FUN_ _
#define SIZE(X) ((int)(X.size()))          //NOTES:SIZE(
#define L(X) ((int)(X.length()))      //NOTES:LENGTH(
#define MAX(i,j) (i)>(j)?(i):(j)
#define MIN(i,j) (i)<(j)?(i):(j)
#define FOR(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define REP(i,a) for((i)=0;(i)<(a);(i)++)
#define MEM(m,i) memset((m),(i),SZ(m))
#define PB(x,y) (x).push_back(y)
#define MP(x,y) make_pair(x,y)
#define INF 100000000
#define EPI 1e-7
const int MaxMatrixSize=40;
using namespace std;
template<class T> inline T checkMod(T n,T m) {return (n%m+m)%m;}          //NOTES:checkMod(
template<class T> inline T gcd(T a,T b)        //NOTES:gcd(
  {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b)             //NOTES:lcm(
  {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline void showMatrix(int n,T A[MaxMatrixSize][MaxMatrixSize])//NOTES:showMatrix(
  {for (int i=0;i<n;i++){for (int j=0;j<n;j++)cout<<A[i][j];cout<<endl;}}

//@niteshvishnoi.................//
int main()
{
    int test;
    cin>>test;
    getchar();
    for(int cases=0;cases<test;cases++)
    {
					  string s;
					  getline(cin,s,'\n');
					  LL occur[8]={0},minm=INF;
					  for(int i=0;i<s.length();i++)
					  {
								  if(s[i]=='H')
								     occur[0]++;
								  else if(s[i]=='A')
								     occur[1]++;
										else if(s[i]=='C')
								     occur[2]++;
										else if(s[i]=='K')
								     occur[3]++;
										else if(s[i]=='E')
								     occur[4]++;
										else if(s[i]=='R')
								     occur[5]++;
										else if(s[i]=='U')
								     occur[6]++;
										else if(s[i]=='P')
								     occur[7]++;
							}
							occur[2]/=2;
							for(int i=0;i<8;i++)
										if(minm>occur[i])
										   minm=occur[i];
							cout<<"Case #"<<cases+1<<": "<<minm<<endl;
				}

    return 0;
}
