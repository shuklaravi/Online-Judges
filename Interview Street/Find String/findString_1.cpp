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


map<int,string> mymap;
int p,temp;
struct node {
node *next[26];
node() {
        int i;
        REP(i,26) next[i]=NULL;
    }
};
void addAll(node *root, string s, int idx)
{
    int i;
    FOR(i,idx, s.length())
    {
        (root)->next[s[i]-'a'] = new node();
        (root) = (root)->next[s[i]-'a'];
    }
}
int addString(node **root, string s, int idx)
{
    if(idx == s.length()) return 0;
    if((*root)->next[s[idx]-'a'] == NULL)
    {
        addAll(*root, s, idx);
        return s.length()-idx;
    }
    else
    {
		return addString(&((*root)->next[s[idx]-'a']), s, idx+1);
	}
}

void traverse(node* root, string s)
{
    int i;
    //cout<<".........."<<s<<endl;
    if(p==0) {mymap[temp]=s; cout<<s<<endl; p--; return;}
    if(p<=0) return;
    p--;
    
    REP(i,26)
    {
        if(root->next[i] != NULL)
        {
            traverse(root->next[i], s+(char)(i+'a'));
            if(p<0) return;
        }
    }
}
int main()
{
    int test,i,j;
    scanf("%d",&test);
    string str;
    struct node* root = new node();
    struct node* head = root;
    getchar();
    int glob[26];
    MEM(glob,0);
    while(test--)
    {
        getline(cin,str,'\n');
        REP(j,str.length())
        {
            head = root;
            glob[str[j]-'a'] += addString(&head, str, j);
//            cout<<str[j]<<" "<<glob[str[j]-'a']<<endl;
        }
  //      REP(i,26) cout<<str<<" "<<glob[i]<<endl;
    }
    head = root;
    int max_substr = 0;
    REP(i,26) max_substr+=glob[i];
    int query;
    scanf("%d",&query);
    head = root;
    while(query--)
    {
		scanf("%d",&p);
        head = root;
        temp=p;
        if(mymap.find(temp)!=mymap.end()) {cout<<mymap[temp]<<endl; continue;}
        if(p > max_substr) printf("INVALID\n");
        else {
			REP(i,26) 
			{
				if(p - glob[i] <=0) break;
				p-=glob[i];
			}
	//		cout<<p<<" "<<i<<endl;
			p--;
			string ss(1,(char)(i+'a'));
//			cout<<"------------"<<ss<<endl;
			traverse(head->next[i], ss);
		}
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
























