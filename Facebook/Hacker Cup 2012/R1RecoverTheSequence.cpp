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
string s;
int idx;

map<int,int> merge(int low, int high)
{
	map<int,int> m;
	cout<<low<<" "<<high<<endl;
	if(high - low == 0) {
		m[1] = low;
		return m;
	}
	if(high - low == 1) {
		if(s[idx] == '1') {
			m[1] = 1;
			m[2] = 2;
		}
		else {
			m[1] = 2;
			m[2] = 1;
		}
		return m;
	}
	int mid = (low + high)/2;
	map<int,int> left = merge(low, mid);
	map<int,int> right = merge(mid+1, high);
	int Lidx, Ridx, Fidx;
	Lidx = left.size();
	Ridx = right.size();
	Fidx = 1;
	cout<<"LEFT\n";
	for(map<int,int>::iterator it = left.begin(); it!=left.end();it++)
	{
		cout<<(*it).first<<" "<<(*it).second<<endl;
	}
	cout<<"RIGHT\n";
	for(map<int,int>::iterator it = right.begin(); it!=right.end();it++)
	{
		cout<<(*it).first<<" "<<(*it).second<<endl;
	}
	int n = high-low-1;
	while(!left.empty() && !right.empty())
	{
		if(s[idx++]=='1') {
			m[Fidx++] = (*left.begin()).second;
			left.erase(left.begin());
		}
		else {
			m[Fidx++] = (*right.begin()).second;
			right.erase(right.begin());
		} n--;
	}
	while(!left.empty()) {
		m[Fidx++] = (*left.begin()).second;
		left.erase(left.begin());
		n--;
	}
	while(!right.empty()) {
		m[Fidx++] = (*right.begin()).second;
		right.erase(right.begin());
		n--;
	}
	while(n>0) {
		m[Fidx] = Fidx++;
	}
	
	cout<<"FINAL\n";
	for(map<int,int>::iterator it = m.begin(); it!=m.end();it++)
	{
		cout<<(*it).first<<" "<<(*it).second<<endl;
	}
	
	return m;
}
int checksum(vector<int> arr)
{
    LL result = 1;
    for (int i=0;i<arr.size();i++)
    {
		result = (31 * result + arr[i]) % 1000003;
	}
    return result;
}
int main()
{
	int t;
	cin>>t;
	for(int cases = 1; cases <= t; cases++)
	{
		int n,nn;
		cin>>n;
		nn=n;
		cin>>s;
		idx=0;
		map<int,int> heap = merge(1, n);
		vector<int> res(n,0);
		int ele=1;
		
		while(!heap.empty())
		{
			int idx = (*heap.begin()).second;
			heap.erase(heap.begin());
			res[idx] = ele++;
			
		}
		for(int i=0;i<n;i++) if(res[i]==0) res[i]=ele++;
		print(res);
		cout<<"Case #"<<cases<<": "<<checksum(res)<<endl;
	}
//	system("pause");
	return 0;
}

