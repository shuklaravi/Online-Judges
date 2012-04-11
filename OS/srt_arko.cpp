#include<stdio.h>   
#include<conio.h>
int main()
{
     int a[10]={0,3,5,9,10,12,14,16,17,19};
     int c[10]={6,2,1,7,5,3,4,5,7,2};
     int d[10]={0,3,5,9,10,12,14,16,17,19}; 
     int r[10]={6,2,1,7,5,3,4,5,7,2};
     int w[10]={0};
     int i,j,q;
     for(i=0;i<10;i++)
     {
                    for(j=i+1;j<10;j++)
                      {
                                         if(a[i]+c[i]>a[j]+c[j] )
                                         {
                                                                
                                                                if(a[j]>a[i])
                                                                c[i]=a[i]+c[i]-a[j];
                                                                a[i]=a[j]+c[j];
                                                                q=a[i];
                                                                a[i]=a[j];
                                                                a[j]=q;
                                                                q=c[i];
                                                                c[i]=c[j];
                                                                c[j]=q;
                                                                
                                                                q=d[i];
                                                                d[i]=d[j];
                                                                d[j]=q;
                                                                
                                                                
                                         }
                                         else
                                         {
                                             if(a[j]<a[i]+c[i])
                                             {
                                                               a[j]=a[i]+c[i];
                                             }
                                         }
                      }
                      
     }
     for(i=0;i<10;i++)
     {
                      for(j=i+1;j<10;j++)
                      {
                               if(d[i]>d[j])
                               {
                                            q=d[i];
                                            d[i]=d[j];
                                            d[j]=q;
                                            
                                            q=a[i];
                                            a[i]=a[j];
                                            a[j]=q;
                                            q=c[i];
                                            c[i]=c[j];
                                            c[j]=q;
                                            }
                      }
     }
     for(i=0;i<10;i++)
     w[i]=a[i]-d[i]-(r[i]-c[i]);
      printf("a\tc\tw\n");
     for(i=0;i<10;i++)
     printf("%d\t%d\t%d\n",d[i],r[i],w[i]);
     getch();
     return 0;
}
