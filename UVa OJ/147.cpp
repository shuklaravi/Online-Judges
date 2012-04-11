using namespace std;
# include<iostream>
# include<cstdio>
# include<cstring>

int main()
{
    unsigned long long nway[50000];
    int coin[11]={10000,5000,2000,1000,500,200,100,50,20,10,5},c;
    int num,i,j;
    double fnum;
    while(scanf("%lf",&fnum))
    {
         num=(int)(fnum*100);
         num = (int)(fnum*100 + 1E-5);
      //   cout<<num<<endl;
         if(fnum==0)
              break;
         for(i=1;i<=num;i++)
              nway[i]=0;
         for(i=0;i<11;i++)
         {
             c=coin[i];
             nway[0]=1;
             for(j=c;j<=num;j++)
                  nway[j]+=nway[j-c];
         }
         printf("%6.2lf%17llu\n",fnum,nway[num]);
    }
    return 0;
}
    
