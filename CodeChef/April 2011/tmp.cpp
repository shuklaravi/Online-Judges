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
#include <ctime>
#include <stdint.h>
#include <unistd.h>
#define LL long long

using namespace std;


#define MAXX 20000000
char *ipos,*opos,InpFile[MAXX],OutFile[MAXX],DIP[30];
inline int input_int(int flag=0){while(*ipos<=32)++ipos;if(flag)return(*ipos++-'0');int x=0,neg=0;char c;while(true){c=*ipos++;if(c=='-')neg=1;else{if(c<=32)return neg?-x:x;x=(x<<1)+(x<<3)+c-'0';}}}
inline LL input_LL(int flag=0){while(*ipos<=32)++ipos;if(flag)return(*ipos++-'0');LL x=0,neg=0;char c;while(true){c=*ipos++;if(c=='-')neg=1;else{if(c<=32)return neg?-x:x;x=(x<<1)+(x<<3)+c-'0';}}}
inline void input_st(char *s){while(*ipos<=32)++ipos;int pos=0;char c;while(true){c=*ipos++;if(c<=32){s[pos]='\0';break;}else s[pos++]=c;}}
inline char input_ch(){while(*ipos<=32)++ipos;char c=*ipos++;return c;}
inline void output(int x){int y;int dig = 0;while(x||!dig){y=x/10;DIP[dig++]=x-((y<<3)+(y<<1))+'0';x=y;}while(dig--)*opos++=DIP[dig];}
//inline void InitFASTIO(){ipos = InpFile; opos = OutFile;fread_unlocked(InpFile, MAXX, 1, stdin);}
//inline void FlushFASTIO(){fwrite_unlocked(OutFile, opos - OutFile, 1, stdout);}


inline void input( int &n ) { n=0; int ch=getchar(); while( ch < '0' || ch > '9' ) ch=getchar(); while( ch >= '0' && ch <= '9' ) n = (n<<3)+(n<<1) + ch-'0', ch=getchar(); }

struct node
{
    int left;
    int right;
    long long int value;
    long long int to_update;
} tree[4005000];


void build(int node, int l, int r, int c)
{
        tree[node].left = l;
        tree[node].right = r;
        tree[node].value = c;
        tree[node].to_update = 0;
        if (l != r)
        {
                build(2*node, l, (l+r)/2, c);
                build(2*node + 1, (l+r)/2 + 1, r, c);
        }
}


inline void update_node(int node)
{
        if(!tree[node].to_update)
        return;
        else
        {
                tree[node].value += tree[node].to_update;
                if(tree[node].left != tree[node].right)
                {
                        tree[2*node].to_update += tree[node].to_update;
                        tree[2*node+1].to_update += tree[node].to_update;
                }
                tree[node].to_update = 0;
        }
}


void update(int node, int left, int right, int c)
{
        if (tree[node].left==left && tree[node].right==right)
        {
                tree[node].to_update += c;
                update_node(node);
        }
        else
        {
                if (left > tree[2*node].right)
                {
                        update(2*node+1, left, right, c);
                }
                else if (right <= tree[2*node].right)
                {
                        update(2*node, left, right, c);
                }
                else
                {
                        update(2*node, left, tree[2*node].right, c);
                        update(2*node+1, tree[2*node].right + 1, right, c);
                }
        }

}


long long int query(int p)
{
    int current = 1;
    while (!(tree[current].left == p && tree[current].right == p))
    {
                update_node(current);
                if (p >= tree[2*current].left && p <= tree[2*current].right)
                        current = 2*current;
                else
                        current = 2*current + 1;
        }
        update_node(current);
        return tree[current].value;
}


int main()
{
        int n, m, c;
//        InitFASTIO();
        input(n);input(m);input(c);
//        n = input_int();
//        m = input_int();
//        c = input_int();

        build(1,1,n,c);
        while (m--)
        {
                char c;
                scanf("%c",&c);
//                c = input_ch();
                if (c == 'Q')
                {
                        int p;
                        input(p);
                        //p = input_int();
                        printf("%lld\n",query(p));
                }
                else
                {
                        int u, v, k;
                        input(u);input(v);input(k);
//                        u = input_int();
//                        v = input_int();
//                        k = input_int();

                        update(1,u,v,k);
                }
        }
    return 0;
}
