using namespace std;
# include<iostream>
# include<cstdio>
# include<cstring>
int pos,arr[500][500],ars[500];

void calculate(int k);

int main()
{
    char str[500];
    int x,y,i,len,l,j,val;
  while(gets(str))
  { 
    if(strcmp(str,"0")==0)
         break;
    pos=1;
    for(i=0;i<strlen(str);i++)
    {
         x=str[i]-'0';
         if(str[i+1]!='\0')
         {
              y=str[i+1]-'0';
              if(y==0)
              {
                   x*=10;
                   i++;
              }
         }
         ars[pos]=x;
         pos++;
    }
    len=pos-1;
    
    for(i=1;i<=len;i++)
         arr[i][i]=1;
    for(i=1;i<=len;i++)
         arr[i][0]=1;
    for(i=1;i<=len;i++)
         arr[0][i]=1;
         
    for(l=2;l<=len;l++)
    {
         for(i=1;i<=(len-l+1);i++)
         {
              j=i+l-1;
              arr[i][j]=arr[i][j-1]*arr[j][j];
              if(ars[j]>9 || ars[j-1]>9)
                   continue;
              else
              {
                  val= (ars[j-1]*10)+ars[j];
                  if(val<=26)
                       arr[i][j]+=arr[i][j-2];
              }
         }
    }
    cout<<arr[1][len]<<endl;
  }
    return 0;
}


