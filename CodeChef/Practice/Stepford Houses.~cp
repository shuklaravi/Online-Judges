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
    int data, nright;
    struct node *left, *right;
}root;

void insert(struct node *root, int n)
{
    if(root->right==NULL && root->data < n)
    {
        if(root->data+1 == n)
        {
            root->data=n;
            root->nright++;
            return;
        }
        root->nright++;
        node *temp=new node();
        root->right=temp;
        temp->data=n;
        temp->nright=0;
    }
    else if(root->left==NULL && root->data > n)
    {
        ::count+=root->nright+1;
        if(root->data-1 == n)
        {
            
            root->nright++;
            return;
        }
        node *temp=new node();
        root->left=temp;
        temp->data=n;
        temp->nright=0;
    }
    else if(root->data > n && root->left!=NULL)
    {
        ::count+=root->nright+1;
        insert(root->left, n);
    }
    else if(root->data < n && root->right!=NULL)
    {
        root->nright++;
        insert(root->right, n);
    }
}
void travel(struct node * root)
{
    cout<<"node has data = "<<root->data<<endl;
//    cout<<"node has left = "<<root->nleft<<endl;
    cout<<"node has right = "<<root->nright<<endl;
    if(root->left!=0)
    {
        cout<<"recursing to its left child \n";
        travel(root->left);
    }
    if(root->right!=0)
    {
        cout<<"recursing to its right child \n";
        travel(root->right);
    }
}
int main()
{
    opos = outfile;
	ipos = infile;
    int n,i,j,p,q,I,J,front,end;
    vector<int> arr;
//    while(input(n))
    {
        fread_unlocked(infile,20000000,1,stdin);
        n=input();
        front=0;end=0;I=J=0;
        arr.clear();
        ::count=0;
        REP(i,n)
        {
            p=input();
            PB(arr,p);
        }
        vector<int> ord=arr;
        sort(ALL(ord));
        REP(i,n)
        if(ord[i]==arr[i])
        {
            I++;
        }
        else break;
        
//        root.parent=NULL;
        root.nright=I;
        root.left=NULL;
        root.right=NULL;
        root.data=arr[I];
        
        FOR(i,I+1,n)
        {
            
//            cout<<"INSERTING "<<p<<endl;
            insert(&root,arr[i]);
//            cout<<"count increased to = "<<::count<<endl;
        }
//        travel(&root);
        printf("%d\n",::count);
    }
//	system("pause"); //Windows Only
	return 0;
}




















