# include <stdio.h>
#include<conio.h>
int main()
{

int I,J;
int a[]={0,3,5,9,10,12,14,16,17,19};
int c[]={6,2,1,7,5,3,4,5,7,2};
int arr[3][10] ={0};


int sec=0,jobno=0;

for (I=0;;I++)
{
if (I==a[sec])
{
arr[0][jobno]=jobno;
arr[1][jobno]=c[jobno];
sec=++jobno;

}

int min=100,currentjob,J,K;

for (J=0;J<jobno;J++)
if (arr[1][J]!=0&&(arr[1][J]<min))
{min=arr[1][J];currentjob=J;}

if (min==100)
break;

for (K=0;K<jobno;K++)
if (K!=currentjob)
{
if (arr[1][K]!=0)
arr[2][K]++;
}
arr[1][currentjob]--;


}
for (I=0;I<jobno;I++)
printf("%d ",arr[2][I]);
getch();
return 0;

}
