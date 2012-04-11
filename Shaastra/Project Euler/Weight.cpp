//
// Dear Judge:
//
// Once you are done trying to 'bug/debug' this routine,
// and have realized what a terrible mistake that was,
// please increment the following counter as a warning
// to the next guy:
//
// total_hours_wasted_here = INF
// know what the MACRO means scroll down..
//

using namespace std;
#include <algorithm>
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
#define INF (1<<31)-1
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

typedef pair<int,int>   PII;
typedef pair<char,int>  PCI;
typedef pair<int,PII>   TRI;
typedef V( int )        VI;
typedef V( PII )        VII;
typedef V( TRI )        VTRI;
typedef V( string )     VS;
typedef long long       LL;
typedef long double     LD;

inline string i2s(int number) { stringstream ss; ss << number; return ss.str(); }
//END_TEMPLATE_BY_PRATYUSH_VERMA
bool arr[10000001];
vector< vector<int> > prime(10000001);
//vector<vector<int> > v;
LL weight[10000001];
LL pos[10000001];
int main()
{


    MEM(weight,0);
    MEM(pos,0);
    MEM(arr,1);
    long long int i,j,k,p=1,q;

        FOR(i,2,10000001)
    {
        if (arr[i])
        {

            weight[i]=i;
            pos[i]=p++;


            for(j=i*2;j<10000001;j=j+i)
            arr[j]=0;
        }
    }

    for ( i=2;i<10000001;i++) {
        if (weight[i]==0) {
        LL w=1;
            long long k=i-1;
            for (;k>=2;k--) {
                if (arr[k]==true) {
                    if (i%k==0) {
                        //cout<<k<<endl;
                         LL p=pos[k];
                         //cout<<p<<endl;
                                LL g=1;
                                while(p--)
                                g=(g%1000000007 *k%1000000007)%1000000007 ;
                           //             cout<<"g  "<<g<<endl;
                                w=(w%1000000007 *g%1000000007 )%1000000007 ;

                    }
                }
            }
           // cout<<i<<" "<<w<<endl;
            weight[i]=w;
        }
        long long k=i;
            for (;k>=2;k--) {
                if (arr[k]==true) {
                    if (i%k==0) {
                      //  cout<<i<<" "<<endl;

                    for (j=i*i;j<10000001;j*=i)

                        { if (weight[j]!=0) break; weight[j]=weight[i];}

                    }
                }
            }
         //   if (i%100000==0)
           // cout<<"yes"<<endl;
            //cout<<i<<endl;
            //cout<<i<<" "<<weight[i]<<endl;

    }


 
   cout<<"FDF"<<endl;
   LL tot=0;
   for (LL i=2;i<10000001;i++) {
        tot =(tot%1000000007 + weight[i]%1000000007)%1000000007;
}

cout<<tot<<endl;
getchar();



            
    
    
    


    
    
    
	system("pause"); //Windows Only
	return 0;
}
