# include <iostream>
using namespace std;
int main()
{
    int x1,y1,x2,y2,x3,y3,x4,y4;
    int tx,ty,bx,by;
    int test;
    cin>>test;
    while (test--)
    {
          cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
          
          if (x3<x1)
          {swap(x3,x1);swap(y3,y1);swap(x2,x4);swap(y2,y4);}
          if(x3<x2)
          {
                   tx=x3;
                   if (y1>=y3&&y1<y4)
                   ty=y1;
                   else  if (y3<y2&&y3>=y1)
                   ty=y3;
                   if (y4<=y1) {cout<<"GOOD PASTE\n";continue;}
          }
          if (y4<=y2&&y4>=y1)
          {
                    by=y4;
                    if ( x4>x2)
                    {
                         bx=x2;
                    }
                    else bx=x4;
          }
          else if (y4>y2&&y3<y2)
          {
               bx=x2;
               by=y2;
          }
          else  {cout<<"GOOD PASTE\n";continue;}
                    
    cout<<tx<<" "<<ty<<" "<<bx<<" "<<by<<endl;
                         
                    
    }   
}
                   
                   
                   
          
                    
          
                    
          
