/*
ID: vermapr1
PROG: <prog_name>
LANG: C++
*/

// #define TRUE FALSE haha now debug this
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
// FAST I/O
//#define MAXX 20000000
//char *ipos, *opos, InpFile[MAXX], OutFile[MAXX], DIP[30];
//inline int input_int(int flag = 0){
//    while(*ipos <= 32)    ++ipos;
//    if ( flag  ) return (*ipos++ - '0');
//    int x = 0, neg = 0; char c;
//    while( true ) {
//        c = *ipos++; if(c == '-')    neg = 1;
//        else{
//            if(c <= 32)    return neg ? -x : x;
//            x = (x << 1) + (x << 3) + c - '0';
//        }
//    }
//}
//inline LL input_LL(int flag = 0){
//    while(*ipos <= 32)    ++ipos;
//    if ( flag  ) return (*ipos++ - '0');
//    LL x = 0, neg = 0; char c;
//    while( true ) {
//        c = *ipos++; if(c == '-')    neg = 1;
//        else{
//            if(c <= 32)    return neg ? -x : x;
//            x = (x << 1) + (x << 3) + c - '0';
//        }
//    }
//}
//inline void input_st(char *s){
//    while(*ipos <= 32)    ++ipos;
//    int pos = 0;char c;
//    while( true ) {
//        c = *ipos++;
//        if(c <= 32)    {s[pos] = '\0'; break;}
//        else s[pos++] = c;
//    }
//}
//inline void output(int x, int flag){
//    int y;
//    int dig = 0;
//    while(x || !dig)    {y = x / 10; DIP[dig++] = x - ((y << 3) + (y << 1)) + '0'; x = y;}
//    while(dig--)    *opos++ = DIP[dig];
//    *opos++ = flag ? '\n' : ' ';
//}
//inline void InitFASTIO(){
//    ipos = InpFile; opos = OutFile;
//    fread_unlocked(InpFile, MAXX, 1, stdin);
//}
//inline void FlushFASTIO(){
//    fwrite_unlocked(OutFile, opos - OutFile, 1, stdout);
//}
////End of FAST I/O


int n,k,a,b;
int arr[20][100005];
struct node {
    int l,r,state;
    node *child1, *child2;
    bool flag;
    node(int ll, int rr) {
        l=ll; r=rr; state=0; child1=NULL; child2=NULL; flag=0;
    }
    node(int ll) {
        l=ll; r=-1; state=0; child1=NULL; child2=NULL; flag=0;
    }
    node() {flag=0; child1=NULL; child2=NULL;state=0;}
};
void init(node *temp)
{
    if(temp->l+2<temp->r) {
        temp->child1=new node( temp->l, (temp->r+temp->l)/2 );
        temp->child2=new node( (temp->r+temp->l)/2 + 1, temp->r );
        init(temp->child1);
        init(temp->child2);
    }
    else if(temp->l+2==temp->r) {
        temp->child1=new node( temp->l, (temp->r+temp->l)/2 );
        temp->child2=new node( temp->r );
        init(temp->child1);
    }
    else if(temp->l+1==temp->r) {
        temp->child1=new node( temp->l );
        temp->child2=new node( temp->r );
    }

}
void traverse(node temp, bool fg) {

//    cout<<"["<<temp.l << ","<<temp.r<<"] = "<<temp.state<<" & "<<temp.flag<<endl;

    if(temp.child1!=NULL) {
        traverse(*temp.child1, fg^temp.flag );
    }
    if(temp.child2!=NULL) {
        traverse(*temp.child2, fg^temp.flag);
    }
    if(temp.r==-1) {
        cout<<(fg^temp.state)<<" ";
    }
}
int flip( node *temp, int a, int b) {
    if(a==temp->l && b==temp->r) {
        temp->flag=!temp->flag;
        if(temp->flag==1) return b-a+1-( temp->state );
        return temp->state;
    }
    int mid = ( temp->l + temp->r ) / 2;
    if(temp->l==a && temp->r==-1) return temp->state=temp->state^1;
    else if(b <= mid ) {
        temp->state=flip(temp->child1, a, b ) + temp->child2->state;
    }
    else if( a<=mid && b > mid ) {
        flip(temp->child1, a, mid );
        temp->state=temp->child1->state;
        flip(temp->child2, mid+1, b );
        temp->state+=temp->child2->state;
    }
     else if( a >mid ) {
         temp->state=flip ( temp->child2, a, b) + temp->child1->state;
     }
    return 0;
}

int count( node temp, int a, int b) {
    int mid = ( temp.l + temp.r ) / 2;
    if(temp.l==a && temp.r==-1) return temp.state;
    else if(b <= mid ) {
        if(temp.flag==1) return min(temp.r,b)-max(temp.l,a) + 1 - count(*temp.child1, a, b );
        return count(*temp.child1, a, b );

    }
    else if( a<=mid && b > mid ) {
        int t=count(*temp.child1, a, mid );
        t+=count (*temp.child2, mid+1, b );
        if(temp.flag ==1) t=(min(temp.r,b)-max(temp.l,a) + 1 )-t;
        return t;

    }
     else if( a >mid && b>mid ) {
         if(temp.flag==1) return (min(temp.r,b)-max(temp.l,a) + 1 ) -count( *temp.child2, a, b);
         return count( *temp.child2, a, b);
     }
     return 0;
}
void del(node *temp) {
          if(temp->child1!=NULL) del(temp->child1);
          if(temp->child2!=NULL) del(temp->child2);
          delete temp;
}
int main()
{
//       InitFASTIO();
//    input_int(n);input_int(k);

    freopen("input_test_3.in" , "r" , stdin);
    freopen("output_test_3_me_dbg.out" , "w" , stdout);
    input(n);input(k);
    int c;
    node *head=new node();

    if(n!=1)
    { head->l=1; head->r=n; head->child1=NULL; head->child2=NULL; head->state=0; }
    if(n==1)
    { head->l=1; head->r=-1; head->child1=NULL; head->child2=NULL; head->state=0; }

    init(head);
    while(k--)
    {
//        input_int(c);
//        input_int(a);
//        input_int(b);
        input(c);
        input(a);
        input(b);
        a++; b++;
        if(c==0) flip(head, a, b);
//        if(c==1) //output(count(*head, a,b),0);
//        printf("%d\n",count(*head,a,b));
        traverse(*head,0);
        cout<<endl;
    }
    del(head);
//    FlushFASTIO();
    return 0;
}


























