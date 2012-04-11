#include<iostream>
#include<algorithm>
using namespace std;
int jl=25,ml=10;
int jn=1,bl=1;
struct job {
       int jno,jtime,tleft,jsize,wait,alloc;
       job()
       {
            alloc=-1;
            jno=jn++;
            wait=-1;
             wait=0;
       }};
struct memory {
       int blk,bsize,sleft;
       bool vacant;
       memory()
       {
               blk=bl++;
               vacant=false;
               }};
void jobstat(job j[])
{
     cout<<endl<<"JOB NO.\tJOB TIME\tTIME LEFT\tJOB SIZE\tSTATUS\n";
     for(int i=0;i<jl;i++)
     cout<<j[i].jno<<"|\t"<<j[i].jtime<<"|\t"<<j[i].tleft<<"|\t"<<j[i].jsize<<"|\t"<<j[i].wait<<","<<j[i].alloc<<endl;
 }
void memstat(memory m[])
{
     cout<<endl<<"BLOCK\tBLOCK SIZE\tSIZE LEFT\n";
     for(int i=0;i<ml;i++)
     cout<<m[i].blk<<"\t"<<m[i].bsize<<"\t"<<m[i].sleft<<endl;
}
int all_alloc(job j[],int t)
{
    int i;
    for(i=0;i<10;i++)
    if(j[i].tleft==0);
    if(i==10)
    return 1;
    return 0;
}
int main()
{
    int it=0,i,J;
    job j[50];
    memory mem[50];
    for(int i=0;i<25;i++)
    {
           cin>>j[i].jtime>>j[i].jsize;
            j[i].tleft=j[i].jtime;
            }
    for(int i=0;i<10;i++)
    {
            cin>>mem[i].bsize;
            mem[i].sleft=mem[i].bsize;
            }
    cout<<"STATUS AT it = "<<it<<endl;
    jobstat(j);
    memstat(mem);
    int time=0,s;
            for(time=0;time<20;time++)
            {
                cout<<"STATUS AT it = "<<time<<endl;
                jobstat(j);
                memstat(mem);
                
                         for( J=0;J<10;J++)
                         {
                                          for(i=0;i<25;i++)
                                          if(j[i].tleft==0)
                                          {
    //                                                       cout<<"...........................................";
                                                           j[i].alloc=-1;
                                                           mem[j[i].alloc].vacant=true;
                                          }

                         }
                         s=all_alloc(j,time);
//                         if(s==1 && time)
  //                             break;
                         for(i=0;i<25;i++)
                         {
                                 if(j[i].wait==-1)
                                 {
                                 for(J=0;J<10;J++)
                                 {
                                                  if(j[i].jsize>=mem[J].bsize)
                                                  {
                                                                              cout<<"////////////////////////////////";
                                                                              j[i].alloc=J;
                                                                              mem[J].vacant=false;
                                                                              mem[J].sleft=j[i].jsize-mem[J].bsize;
                                                                              j[i].wait=0;
                                                                              j[i].tleft=j[i].jtime;
                                                  }
                                 }
                                 if(J==10)
                                 {
                                          j[i].wait++;
                                 }
                                 }
                                 else
                                 {
                                     j[i].tleft--;
                                 }
                         }
            }
    system("pause");
    return 0;
}
