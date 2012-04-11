#include <stdio.h>
#include <string.h>
#include<iostream.h>
void transfermem(char* destination[], char* source[], int startIndex, int numBytes)
{
  while(numBytes--)
  {
                      cout<<destination<<"\n"<<source<<"\n"<<startIndex<<"\n"<<numBytes<<"\n";
    *(startIndex + destination++) = *source++;
    break;
  }
}

int main()
{
  char str[20]="CodeFest \061\x30\088";
  char *str2=str;
  float i=0.15;
  int p;
  int arr1[10] = {9,8,7};
  int arr2[7] = {1,2,3,4,5,6};
  float me = 1.1, other;
  double you = 1.25;
  printf("%s %d %d %d %d %d\n",str,strlen(str),sizeof(str),sizeof(str2),sizeof("CodeFest \001\x30\088"),sizeof(i=0.25));
  other=me+i;
  if(me==1.1)
  {
    if(me+i==you)
      printf("I love U\n");
    else
      printf("I hate U\n");
  }
  else
  {
    if(other==1.35)
      printf("I am confused\n");
    else
    {
      if(other==you)
        printf("Her sister is cute too ;)\n");
      else
        printf("Damn these girls\n");
    }
  }
  cout<<str<<"\n"<<"IT-BHU 2010"<<"\n"<<9<<"\n"<<6<<"\n\n..............";
char strx[]="IT-BHU 2010";
  transfermem("asd","asd",9,6);

cout<<str<<"\n"<<""<<"\n"<<15<<"\n"<<1<<"\n\n..............";
  //transfermem(str,"",15,1);
  printf("%s\nxxxxxxxxx\n",str2);
  cout<<arr1<<"\n"<<arr2<<"\n"<<12<<"\n"<<28<<"\n\n.......iiiiii.....";
  //transfermem(arr1,arr2,12,28);
  cout<<arr1<<"\n"<<arr2<<"\n"<<12<<"\n"<<28<<"\n\n.......iiiiiii......";
  for(p=0;p<10;p++)
    printf("%d ___________",arr1[p]);
  printf("\n");
  cout<<"///////////////\n"<<'\088';
  getchar();
  return 0;
  }
