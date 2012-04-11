#include<iostream>
using namespace std;

int main()
{
    int count=1;
    long long num[4600],mul;
    num[0]=1;
    int i;
    int temp=1;
    int temp1=1;
    int point=0;
    while(count<4599)
    {
                     mul=num[point]*2;
                     while(num[temp1-1]>mul)
                                            temp1-=1;
                     if(num[temp1-1]<mul)
                     {
                                        for(i=temp;i>temp1;i--)
                                                  num[i]=num[i-1];
                                        num[temp1]=mul;
                                        temp+=1;
                                        temp1=temp;
                                        count+=1;
                     }
                     temp1=temp;
                     
                     mul=num[point]*3;
                     while(num[temp1-1]>mul)
                                            temp1-=1;
                     if(num[temp1-1]<mul)
                     {
                                        for(i=temp;i>temp1;i--)
                                                  num[i]=num[i-1];
                                        num[temp1]=mul;
                                        temp+=1;
                                        temp1=temp;
                                        count+=1;
                                        
                     }
                     temp1=temp;
                     
                     mul=num[point]*5;
                     while(num[temp1-1]>mul)
                                            temp1-=1;
                     if(num[temp1-1]<mul)
                     {
                                        for(i=temp;i>temp1;i--)
                                                  num[i]=num[i-1];
                                        num[temp1]=mul;
                                        temp+=1;
                                        temp1=temp;
                                        count+=1;
                                       
                     }
                     temp1=temp;
                     point+=1; 
    }
    cout<<"The 1500'th ugly number is "<<num[1499]<<".\n";
//    The 1500'th ugly number is 859963392.
//    system("pause");
    return 0;
}
