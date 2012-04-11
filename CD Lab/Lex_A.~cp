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
#define EPS 1e-11
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



class Lex_A {
    public:
        string str;
	string delI;
	string opStr;
	string temp;
	vector<string> keyW,opeR;
	vector<string> validIdent;
	vector<string> literal;
	vector<string> err;
	vector<string> operatorr;
	vector<char> delimiter;
	vector<char> token;
        Lex_A (string ss)
	{
		str=ss;
		ifstream key("keywords.txt");
		// READ FROM THE TEXT FILE FROM HERE AND INSERT INTO keyW;
		while(key>>temp)
		{
			PB(keyW,temp);
			cout<<temp<<endl;
		}
	        // READ FROM THE TEXT FILE FROM HERE AND INSERT INTO opeR;
		ifstream oper("operators.txt");
		while(oper>>temp)
		{
			PB(opeR,temp);
		}
		opStr="+-/*%=<>|&^";
		delI=";,:{}[]()";
        }
	bool chkIdent (char s)
	{
		return ( isalpha(s)||s=='_'||s=='.'||isdigit(s) ? 1:0 );
	}
	bool isOper(char s)
	{
		for(int i=0;i<opStr.length();i++)
		{
			if(opStr[i]==s) return true;
		}
		return false;
	}
	bool isDelimi (char s)
	{
		for(int i=0;i,delI.length();i++)
		{
			if(delI[i]==s) return true;
		}
		return false;
	}
	void lexical()
	{
		int idx=0;
		string str_cpy="";
		while(str[idx]!='\0')
		{
			cout<<str[idx]<<" ..... ";
			str_cpy="";
			if(chkIdent(str[idx]))
			{
				while(chkIdent(str[idx++]))
				{
					str_cpy+=str[idx-1];
					if(!chkIdent(str[idx]))
					{
						PB(validIdent,str_cpy);
					}
				}
			}
			else if(str[idx]=='"')
			{
				bool flag=false;
				int k;
				for(k=idx+1;k<str.length();k++)
				{
					if(str[k]=='"')
					{
						PB(literal,str.substr( idx+1 , k-idx ));
						flag=true;
					}
				}
				if(flag)
				{
					PB(err,str.substr(idx,k-idx ));
					idx=k+1;
				}
			}
			else if(str[idx]=='\'')
			{
				int k=1;
				if(str[idx+2]=='\'')
				{
					PB(literal,str.substr(idx+1,1));
					idx+=3;
				}
				else if(str[idx+1]=='\\' && str[idx+3]=='\'')
				{
					PB(literal,str.substr(idx+2,1));
					idx+=4;
				}
				else
				{
					int k,count=1;
					for(k=idx+1;k<str.length() && str[k]!='\'' && str[k] ;k++,count++);
					PB(err,str.substr ( idx+1 , k-idx+1 ));
					idx+=count+1;
				}
			}
			else if(isOper(str[idx]))
			{
				int len=idx;
				while(isOper(str[len++]))
				{
					if(!isOper(str[len]))
					{
						PB(operatorr,str.substr(idx,len));
					}
				}
				idx+=(len-idx);
			}
			else if(isDelimi(str[idx]))
			{
				PB(delimiter,str[idx]);
				idx+=1;
			}
			else if(str[idx]!=' ')
			{
				PB(token,str[idx]);
				idx++;
			}
			else
			{
				idx++;
			}
		}
	}
	void display()
	{
		cout<<"Identifiers : \n";
		for(int i=0;i<validIdent.size();i++)
		{
			cout<<validIdent[i]<<endl;
		}
		cout<<"Literals"<<endl;
		for(int i=0;i<literal.size();i++)
		{
			cout<<literal[i]<<endl;
		}
		for(int i=0;i<operatorr.size();i++)
		{
			cout<<operatorr[i]<<endl;
		}
	}
};

int main()
{
    string str;
    printf("\n\n\tEnter String: ");
    getline(cin,str,'\n');
    fflush(stdin);
    Lex_A ob(str);
    ob.lexical();
    cout<<str<<endl;
    ob.display();
//	system("pause");
	return 0;
}







































