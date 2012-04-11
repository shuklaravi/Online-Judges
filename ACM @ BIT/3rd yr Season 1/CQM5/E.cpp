//#define TRUE FALSE haha now debug this..
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

typedef pair<int,int>   PII;
typedef pair<char,int>  PCI;
typedef pair<int,PII>   TRI;
typedef V( int )        VI;
typedef V( PII )        VII;
typedef V( TRI )        VTRI;
typedef V( string )     VS;
typedef long long       LL;
typedef long double     LD;

char outfile[10000000] , infile[2000000],D[20],*opos,*ipos;
inline string i2s(int number) { stringstream ss; ss << number; return ss.str(); }
int max;
int input()
{
	while(*ipos <= 32) ++ipos;
	int x=0;char c;
	while  ( true ) {
		c=*ipos++;
		if (c<=32) return x;
		x=(x<<1)+(x<<3)+c-'0';
	}
	return x;
}
//END_TEMPLATE_BY_PRATYUSH_VERMA
int count;

struct node {
    int data;
    struct node *left, *right;
}root;

void insert(struct node *root, int n)
{
    if(root->right==NULL && root->data < n)
    {
        node *temp=new node();
        root->right=temp;
        temp->data=n;
    }
    else if(root->left==NULL && root->data > n)
    {
        node *temp=new node();
        root->left=temp;
        temp->data=n;
    }
    else if(root->data > n && root->left!=NULL)
    {
        insert(root->left, n);
    }
    else if(root->data < n && root->right!=NULL)
    {
        insert(root->right, n);
    }
}
int height(struct node * root, int h)
{
    if(::max<h) ::max=h;
    if(root->left!=0)
    {
        height(root->left,h+1);
    }
    if(root->right!=0)
    {
        height(root->right,h+1);
    }
}
int main()
{

    int test,n,i,j,p,q,I,J,front,end;
    vector<int> arr;
    cin>>test;
    while(test--)
    {
        ::max=0;
        cin>>n;
        cin>>p;
        root.left=NULL;
        root.right=NULL;
        root.data=p;

        REP(i,n-1)
        {
            cin>>p;
            insert(&root,p);
        }
        height(&root, 0);
        printf("%d\n",::max+1);
    }
//	system("pause"); //Windows Only
	return 0;
}




















