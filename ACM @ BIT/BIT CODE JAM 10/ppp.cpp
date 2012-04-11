/* @BEGIN_OF_SOURCE_CODE */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int i,j,move;
    long long index[10002];
    for(i=1;i<10002;i++)
    index[i]=i*i;
    int A,B,a,b;
    bool turn=false;
    while(cin>>A>>B)
    {
                    turn =false;
                    a=A;
                    b=B;
                    move=0;
                    while(a!=0 || b!=0)
                    {
                               move++;
                               if(index[10000]<a)
                               a-=index[10000];
                               else
                               {
                                   for(i=0;!(index[i]<a && index[i+1]>a) && i<10001;i++)
                                   {
                                                    if(index[i]==a)
                                                    break;
                                   }
                                   a-=index[i];
                                   if(index[i]==a)
                                   break;
                               }
                               if(index[10000]<b)
                               b-=index[10000];
                               else
                               {
                                   for(j=0;!(index[j]<b && index[j+1]>b) && j<10001;j++)
                                   {
                                                    if(index[j]==b)
                                                    break;
                                   }
                                   b-=index[j];
                                   if(index[j]==b)
                                   break;
                               }
//                               cout<<"move : "<<move<<" -- "<<!turn<<" "<<a<<" "<<b<<endl;
                               turn=!turn;
                    }
                    if(index[i]==a || index[j]==b)
                    {
                              if(!turn && move==1)
                              cout<<"A will win after 1 move.";
                              else if(turn && move==1)
                              cout<<"B will win after 1 move.";
                              else if(!turn)
                              cout<<"A will win after "<<move<<" moves.";
                              else if(turn)
                              cout<<"B will win after "<<move<<" moves.";
                              cout<<endl;
                    }
                    else
                    {
                              if(!turn && move==1)
                              cout<<"B will win after 1 move.";
                              else if(turn && move==1)
                              cout<<"A will win after 1 move.";
                              else if(!turn)
                              cout<<"B will win after "<<move<<" moves.";
                              else if(turn)
                              cout<<"A will win after "<<move<<" moves.";
                              cout<<endl;
                    }

    }
return 0;
}
/* @END_OF_SOURCE_CODE */

