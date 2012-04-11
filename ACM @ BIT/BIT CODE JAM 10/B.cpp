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
                               i=j=-1;
                               move++;
                               if(sqrt((float)a)==(float)ceil(sqrt((float)a)))
                               break;
                               else
                               {
                                   for(i=0;!(index[i]<a && index[i+1]>a) && i<10001;i++);
                                   a-=index[i];
                               }
                               if(sqrt((float)b)==(float)ceil(sqrt((float)b)))
                               break;
                               else
                               {
                                   for(i=0;!(index[i]<b && index[i+1]>b) && i<10001;i++);
                                   b-=index[i];
                               }
//                               cout<<"move : "<<move<<" -- "<<!turn<<" "<<a<<" "<<b<<endl;
                               turn=!turn;
                    }
                    if(i==-1 || j==-1)
                    {

                              if(!turn)
                              cout<<"A ";
                              else if(turn)
                              cout<<"B ";
                              cout<<"will win after "<<move<<" move";
                              if(move!=1)
                              cout<<"s";
                              cout<<".";


/*                              if(!turn && move==1)
                              cout<<"A will win after 1 move.";
                              else if(!turn)
                              cout<<"A will win after "<<move<<" moves.";
                              else if(turn)
                              cout<<"B will win after "<<move<<" moves.";
                              cout<<endl;
 */                   }
                    else
                    {
                              if(turn)
                              cout<<"A ";
                              else if(!turn)
                              cout<<"B ";
                              cout<<"will win after "<<move<<" move";
                              if(move!=1)
                              cout<<"s";
                              cout<<".";
/*
                              
                              else if(turn)
                              cout<<"A will win after "<<move<<" moves.";
                              cout<<endl;
*/
                    }
                    cout<<endl;

    }
return 0;
}
/* @END_OF_SOURCE_CODE */

