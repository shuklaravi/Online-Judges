/* @BEGIN_OF_SOURCE_CODE */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int test;
    cin>>test;
    string str;
    while(test--)
    {
                 int len=0;
                 cin>>str;
                 for(int i=0;i<str.length();i++)
                 {
                         len+=str[i];
                 }
                 len/=str.length();
                 cout<<(char)len<<endl;
    }
return 0;
}
/* @END_OF_SOURCE_CODE */
