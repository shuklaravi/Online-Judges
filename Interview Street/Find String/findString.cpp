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

vector<string> res;
struct node {
char ch;
node *next[26];
node(char c) {
        ch = c;
        int i;
        REP(i,26) next[i]=NULL;
    }
};
void addAll(node *root, string s, int idx)
{
    int i;
//    cout<<"adding all : "<<s<<" @@ "<<idx<<endl;
    FOR(i,idx, s.length())
    {
  //      cout<<"---[ "<<(root)->ch<<", "<<(&root)<<" ]---";
        (root)->next[s[i]-'a'] = new node(s[i]);
        (root) = (root)->next[s[i]-'a'];
    }
    //cout<<"---[ "<<(root)->ch<<", "<<(&root)<<" ]---";
}
void addString(node **root, string s, int idx)
{
    int i;
    if(idx == s.length()) return;
//    cout<<"\nadding string : "<<s<<" @ "<<idx<<", currently in node "<<(*root)->ch<<" with index \'"<<(*root)<<"\'"<<endl;
  //  cout<<"---[ "<<(*root)->ch<<", "<<(*root)<<" ]---\n";
    //cout<<endl<<"______\n";
//    REP(i,26) cout<<(*root)->next[i];
//    cout<<"------"<<endl;
    if((*root)->next[s[idx]-'a'] == NULL)
    {
        addAll(*root, s, idx);
        return;
    }
    else
        addString(&((*root)->next[s[idx]-'a']), s, idx+1);
}

void traverse(node* root, string s)
{
    int i;
    PB(res,s);
    REP(i,26)
    {
        if(root->next[i] != NULL)
        {
            traverse(root->next[i], s+(char)(i+'a'));
        }
    }
}
int count(node* root, int& max_substr)
{
    int i;
    REP(i,26)
    {
        if(root->next[i] != NULL)
        {
            count(root->next[i], max_substr);
            max_substr++;
        }
    }
}
int main()
{
    int test,i,j;
    scanf("%d",&test);
    string str;
    struct node* root = new node('*');
    struct node* head = root;
    while(test--)
    {
        cin>>str;
        REP(j,str.length())
        {
            head = root;
//            cout<<"addString : "<<str<<", "<<j<<" from "<<root->ch<<endl;
            addString(&head, str, j);
        }
        head = root;
  //      res.clear();
    //    traverse(head, "");
      //  print(res);
        //cout<<endl<<endl;
    }
    head = root;
    int max_substr = 0;
    count(head, max_substr);
    int query;
    cin>>query;
    head = root;
    traverse(head, "");
    print(res);
    while(query--)
    {
        int p;
        cin>>p;
        if(p > max_substr) cout<<"INVALID\n";
        else cout<<res[p]<<endl;
    }
	return 0;
}
/*

6
zyx
zzz
z
x
y
100



*/


























