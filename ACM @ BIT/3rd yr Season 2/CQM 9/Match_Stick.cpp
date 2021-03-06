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
#define INF (1<<31)-1
#define PI 3.1428571428571428571428571428571

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

template<class T> void print(const vector<T> &v){ostringstream os; for(int i=0; i<v.size(); ++i){if(i)os<<' ';os<<v[i];} cout<<os.str()<<endl;}
template<class T, class U> T cast (U x) { ostringstream os; os<<x; T res; istringstream is(os.str()); is>>res; return res; }
template<class T> vector<T> split(string s, string x=" ") {vector<T> res; for(int i=0;i<s.size();i++){string a; while(i<(int)s.size()&&x.find(s[i])==string::npos)a+=s[i++]; if(!a.empty())res.push_back(cast<T>(a));} return res;}

inline void input( int &n ) { n=0; int ch=getchar(); while( ch < '0' || ch > '9' ) ch=getchar(); while( ch >= '0' && ch <= '9' ) n = (n<<3)+(n<<1) + ch-'0', ch=getchar(); }


string func(string& s, string& ss)
{
    sort(ALL(s));
    sort(ALL(ss));

    reverse(ALL(s));
    reverse(ALL(ss));

    if (s.size() > 0 && s[0] == '0')
      s = "0";

    if (ss.size() > 0 && ss[0] == '0')
      ss = "0";
    if(s.size()==ss.size()) return s > ss? s:ss;

    return s.size() > ss.size() ? s : ss;
}
int main()
{
    string s,ret,temp;
    vector<int> v;

    int i,j,k,p,n,q;
    while(getline(cin,s,'\n'))
    {
        cin>>n;
        getchar();

        ret="";
        v.clear();
        vector<string> t(n+1);
        stringstream ss(s);
        while(ss>>i)
        {
            PB(v,i);
        }
        FOR_(i,1,n)
        {
            REP(j,v.size())
            {
                if(i-v[j]>=0)
                {
                    char ch=j+'0';
                    temp=ch + t[i-v[j]];
                    t[i]=func(temp,t[i]);
                }
            }
        }
        REP_(i,n)
        {
            ret=func(ret,t[i]);
        }
        cout<<ret<<endl;
    }
    return 0;

}
