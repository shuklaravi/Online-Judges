#include <algorithm>
#include <iostream>
#include <stack>
#include <sstream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FORT(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,n) for(int i=n;i>=0;i--)
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define VI(i) vector<i>
using namespace std;
int arr[30][30];
bool flag;
#define BUF 4096

char ibuf[BUF];
int ipt = BUF;

int readInt() {
	while (ipt < BUF && ibuf[ipt] < '0') ipt++;
	if (ipt == BUF) {
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] < '0') ipt++;
	}
	int n = 0;
	while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
	if (ipt == BUF) {
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
	}
	return n;
}

int readString( char *s){
	while (ipt < BUF && ibuf[ipt] < 'a') ipt++;
	if (ipt == BUF) {
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] < 'a') ipt++;
	}

	int n = 0;
	while (ipt < BUF && ibuf[ipt] >= 'a') s[n++] = ibuf[ipt++];
	if (ipt == BUF) {
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] >= 'a') s[n++] = ibuf[ipt++];
	}
	s[n] = '\0';
	return n;
}

int main()
{
    int T,N,diff[30],c1,ch;
    char str[1010];
    bool dp[30];
    stack<int> st;
    T=readInt();//    scanf("%d",&T);
    while(T--){
               flag=true;
               N=readInt();//               scanf("%d",&N);
               FOR(i,26){dp[i]=false; diff[i]=0; FOR(j,26) arr[i][j]=0; }
               FOR(i,N){
                    int lengthy = readString(str);//                 scanf("%s",str);
                  diff[ (int)(str[0]-'a') ]++;
                  diff[ str[strlen(str)-1]-'a' ]--;
                  dp[ str[0]-'a' ]=true;
                  dp[ str[strlen(str)-1]-'a' ]=true;
                  arr[ str[0]-'a' ][ str[strlen(str)-1]-'a' ]++;
                        }
                        ch=(int)(str[0]-'a');
                        c1=0;
               FOR(i,26){
                         if(diff[i]==1) ch=i;
                         diff[i]= abs( diff[i] );
                         if(diff[i] > 1) { flag=false;  break; }
                         if(diff[i]==1) c1++;
                         }
               if(c1>2) { flag=false; }
               if(flag){
                        while(!st.empty()) st.pop();
                        st.push(ch);
                        int V;
                        dp[ch]=false;
                        while( !st.empty() ){
                               V=st.top();
                               st.pop();
                               FOR(i,26) if(arr[V][i]>0 && dp[i]) {st.push(i); dp[i]=false; }
                               
                               }
                        FOR(i,26) if(dp[i]) { flag=false; break; }
                        }
                        if(flag) printf("Ordering is possible.\n");
                        else printf("The door cannot be opened.\n");
               }
    return 0;
}
}
