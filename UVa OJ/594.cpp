using namespace std;
# include<iostream>
# include<cstdio>
# include<cstring>

int main()
{
    int n,val,total,dec,add,arr[30],temp,num;
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
         num=n;
         dec=0;
         i=0;

         dec |= ( num<<24 & 0xff000000 );
         dec |= (  num<<8 & 0x00ff0000 );
         dec |= (  num>>8 & 0x0000ff00 );
         dec |= ( num>>24 & 0x000000ff );
         
         printf("%d converts to %d\n",num,dec);
    }
    return 0;
}
