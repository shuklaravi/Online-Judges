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
#define INF 1000000000000
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
					  int w,h;
					  cin>>w>>h;
					  int size = w<h?w:h;
					  int arr[1000],n=0,k=0,i;
					  getline(cin,s,'\n');
					  for(i=1;i<s.length();i++)
					  {
								   if(s[i]==' '){
								     arr[n++]=k;
								     k=0;
											}
											else k++;
							}
							arr[n++]=k;
	//							cout<<s<<endl;
		//					for(i=0;i<n;i++)
				//			  cout<<arr[i]<<endl;
							while(size>0)
							{
						//		  cout<<endl<<size<<" : ";
										int ch=0,cv=size;
										for(i=0;i<n;)
								  {
								//			  cout<<"ch == "<<ch<<"  cv == "<<cv<<"  ";
													if(cv>h)
											     break;
											  if((ch+(size*arr[i]))<=w)
													{
														  ch = ch + size*arr[i];
										//				  cout<<arr[i]<<"   ";
														  ++i;
																if(i!=n)
																{
																   if(ch + size <=w)
																      ch = ch + size;
																   else
																   {
																				 ch=size;
																				 cv+=size;
																			}
																}
													}
													else
													{
														  cv+=size;
														  ch=0;
													}
										}
										if(i==n)
										  break;
										else size--;
							}

							cout<<"Case #"<<cases+1<<": "<<size<<endl;
				}

    return 0;
}
