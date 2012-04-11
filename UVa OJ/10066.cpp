/* @BEGIN_OF_SOURCE_CODE */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int lis(vector<int> a)
{
    int ls=1;
    int last=a[0];
    int len=a.size();
    for(int i=1;i<len;i++)
    {
            
                      if(a[i]>=last)
                      {
                                    ls++;
                      }
                      last=a[i];
    }
    return ls;
}
int main()
{
    int n1,n2,i,j,temp;
    vector<int> a,b;

    while(cin>>n1>>n2)
    {
                      for(i=0;i<n1;i++)
                      {
                                       cin>>temp;
                                       a.push_back(temp);
                      }
                      for(j=0;j<n2;j++)
                      {
                                       cin>>temp;
                                       b.push_back(temp);
                      }
                      cout<<"a="<<lis(a)<<endl;
                      cout<<"b="<<lis(b)<<endl;
                      int x=max(lis(a),lis(b));
//                      vector<int> aa( a.rbegin(), a.rend() );
//                      vector<int> bb( b.rbegin(), b.rend() );
                      for(i=0;i<a.size();i++)
                      a[i]=-1*a[i];
                      for(i=0;i<b.size();i++)
                      b[i]=-1*b[i];
                      cout<<"aa="<<lis(a)<<endl;
                      cout<<"bb="<<lis(b)<<endl;
                      int y=max(lis(a),lis(b));
                      cout<<max(x,y);
    }
return 0;
}
/* @END_OF_SOURCE_CODE */
