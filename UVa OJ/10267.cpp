/* @BEGIN_OF_SOURCE_CODE */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#define FOR(I) for(int i=0;i<I;i++)
#define FOR(J) for(int j=0;j<J;j++)
using namespace std;
char ed[255][255];
int I,J,i,j;
void fi(int x,int y)
{
     I=x;
     J=y;
     i=0;
     j=0;
     for(int i=0;i<I;i++)
     {
         for(int j=0;j<J;j++)
         ed[i][j]='O';
         }
}
void fc()
{
     i=0;
     j=0;
     for(int i=0;i<I;i++)
             for(int j=0;j<J;j++)
             ed[i][j]='O';
}
int main()
{
    string str;
    char f,a1,a2,a3,a4,a5;
    while((f=getchar())!='X')
    {
            if(f=='I')
            {
                      cout<<"in I\n";
                      getchar();
                      scanf("%c%c",&a1,&a2);
                      fi(a1,a2);
                      getchar();
                      }
            else if(f=='C')
            {
                 fc();
                 }
            else if(f=='L')
            {
                 cin>>a1>>a2>>a3;
//                 fl(a1,a2,a3);
                 }
            else if(f=='V')
            {
                 cin>>a1>>a2>>a3>>a4;
  //               fv(a1,a2,a3,a4);
                 }
            else if(f=='H')
            {
                 cin>>a1>>a2>>a3>>a4;
    //             fh(a1,a2,a3,a4);
                 }
            else if(f=='K')
            {
                 cin>>a1>>a2>>a3>>a4>>a5;
      //           fk(a1,a2,a3,a4,a5);
                 }
            else if(f=='F')
            {
                 cin>>a1>>a2>>a3;
        //         ff(a1,a2,a3);
                 }
            else if(f=='S')
            {
                 cin>>str;
          //       fs(str);
                 }
            else
            cout<<"ERROR"<<endl;
            }
    FOR(I)
    {
          FOR(J)
          cout<<ed[i][j];
          cout<<endl;
          }
          cin>>a1;
return 0;
}
/* @END_OF_SOURCE_CODE */
