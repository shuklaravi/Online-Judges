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
#define INF (1<<31)-1
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
typedef long long ll;
inline string i2s(int number) { stringstream ss; ss << number; return ss.str(); }
//END_TEMPLATE_BY_PRATYUSH_VERMA

int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        if(!(m || n)) break;
        int arr[m][m];
        MEM(arr,0);
        int i,j,k,p,q;
        REP(i,n)
        {
            cin>>p>>q>>k;
            p--; q--;
            if(k==1)
            arr[p][q]=1;
            else
            {
                arr[p][q]=1;
                arr[q][p]=1;
            }
        }
        REP(k,m)
        REP(i,m)
        REP(j,m)
        arr[i][j]=arr[i][j]|(arr[i][k]&arr[k][j]);
        bool flag=0;
        REP(i,m)
        {
            REP(j,m)
            if(arr[i][j]==0 || arr[j][i]==0)
            {
                flag=1; break;
            }
        }
        if(flag==1) cout<<"0\n";
        else cout<<"1\n";
    }
//	system("pause"); //Windows Only
	return 0;
}
