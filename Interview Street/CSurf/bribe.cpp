/* Enter your code here. Read input from STDIN. Print output to STDOUT *//* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
vector<int> arr;
int n, size;
int res;
void dfs(long long sum, int start)
{
    if(sum > n) return;
    if(sum==n)
    {
        res++;
        return ;
    }
    int res = 0;
    for(int i = start; i < size; ++i)
    {
        if(sum+arr[i]>n) continue;
//        if(sum+arr[i]==n) {
  //          res++;
    //        continue;
      //  }
        dfs(sum+arr[i], i+1);
    }
    //cout<<"!"<<start<<" "<<res<<endl;

}
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        res = 0;
        arr.clear();
        int t;
        scanf("%d",&size);
        for(int i = 0; i < size; ++i)
        {
            scanf("%d",&t);
            arr.push_back(t);
        }
        scanf("%d",&n);
        sort(arr.begin(), arr.end());
//        for(int i = 0; i < size; ++i)
            dfs(0, 0);
        printf("%d\n",res);
    }
}
