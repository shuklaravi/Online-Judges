/* @BEGIN_OF_SOURCE_CODE */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define MAX(a, b) (a > b ? a: b)
#define MIN(a, b) (a > b ? b: a)

using namespace std;
int main()
{
    int n,coin,temp;
    int i,j,move,X,Y;
    vector<int> x,y;
    while(cin>>n)
    {
                 x.clear();
                 y.clear();
                 int board[105][105]={0};
                 move=0;
                 cin>>coin;
                 for(i=0;i<coin;i++)
                 {
                                    cin>>temp;
                                    x.push_back(temp);
                 }
                 for(i=0;i<coin;i++)
                 {
                                    cin>>temp;
                                    y.push_back(temp);
                 }
                 for(i=0;i<coin;i++)
                 {
                                    X=MIN(x[i]-1,n-x[i]);
                                    Y=MIN(y[i]-1,n-y[i]);
                                    move+=(X+Y);
//                                    cout<<"."<<move<<endl;
                 }
                 cout<<move<<endl;
    }
return 0;
}
/* @END_OF_SOURCE_CODE */
