
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



struct node {
    int i ; char c;
    node (int ii, char cc) {
        i=ii; c=cc;
    }
};
bool func(node a, node b) {
    if(a.i >b.i) return false;
    return true;
}
class Filtering
{
public:

vector <int> designFilter(vector <int> sizes, string outcome)
{
	vector <int> res;
    vector<node> v;
    int i,j,k,p,q;
    REP(i,sizes.size())
    {
        v.push_back(node (sizes[i],outcome[i]));
    }
    sort(v.begin(),v.end(),func);
    int flag=0;
    int strt,end=-1;
    REP(i,v.size())
    {
        if(flag==2 && v[i].c=='A') {
            return res;
        }
        if(flag==0 && v[i].c=='A') {
            strt=v[i].i;
            flag++;
        }
        if( flag==1 && v[i].c=='R' && v[i-1].c=='A') {
            flag++;
            end=v[i-1].i;
        }
    }
    if(i==sizes.size() && end==-1 && outcome[sizes.size()-1]=='A')  {
        end=v[sizes.size()-1].i;
    }
    PB(res,strt); PB(res,end);
	return res;
}

};
