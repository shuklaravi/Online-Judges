
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
#include <bitset>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>


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

typedef pair<int,int>   PII;
typedef pair<char,int>  PCI;
typedef pair<int,PII>   TRI;
typedef V( int )        VI;
typedef V( PII )        VII;
typedef V( TRI )        VTRI;
typedef V( string )     VS;
typedef map<int,VI>     MAP;
typedef long long       LL;
typedef long double     LD;

inline string i2s(int number) { stringstream ss; ss << number; return ss.str(); }

bool first = false;
int tree[500000][4];


void initialise(int node, int start, int end) {

   tree[node][0] = end - start + 1;

   if(start < end) {
      int mid = (start + end)/2;
      initialise(node*2+1,start,mid);
      initialise(node*2+2,mid+1,end);
   }
}

void update(int node,int start, int end, int i, int j) {
   if(i > end || j < start) {
      return;
   }
   if(start >= i && end <= j) {
        cout<<"DFD"<<endl;
      tree[node][3] = tree[node][3]*-1;
   }
   else {
      int mid = (start + end)/2, t1, t2;
      update(node*2+1,start,mid,i,j);
      update(node*2+2,mid+1,end,i,j);


      REP(i,3) {
	 t1 = 3 - tree[2*node+1][3] + i;// if(t1 >= 3) t1 -= 3;
	 t2 = 3 - tree[2*node+2][3] + i; //if(t2 >= 3) t2 -= 3;
	 tree[node][i] = tree[2*node+1][t1] + tree[2*node+2][t2];
      }

         }
}

int query(int node,int start,int end,int i,int j) {
   if(i > end || j < start) {
      return 0;
   }
   if(start >= i && end <= j) {
	int t = node, increment = 0;
	while(true) {
	   increment += tree[t][3];
	   if(!t) break; t = (t - 1)/2;
	}
	t = 3 - increment;
	return tree[node][t];
   }
   else {
      int mid = (start + end)/2;
      return query(2*node+1,start,mid,i,j) + query(2*node+2,mid+1,end,i,j);
   }
}


int main() {

    //  cout<<"SDFS"<<endl;

   int n, queries, t, a, b, t1, t2;


   scanf("%d%d",&n,&queries);

   initialise(0,0,n-1);


    int i;
   REP(i,queries) {
        for ( int i = 0; i < n; i++) {
            for ( int j = 0; j < 4; j++) {
                cout<<tree[i][j]<<" ";
            }
            cout<<endl;
        }
      scanf("%d%d%d",&t,&a,&b);
      if(!t) {
	 update(0,0,n-1,a,b);
    }

      else {
	 t1 = query(0,0,n-1,a,b);

	 printf("%d\n",t1);
      }
   }
cin>>n;

   return 0;
}
