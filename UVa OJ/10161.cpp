#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define p(a,b) printf("%d %d\n",a,b)

int main(int argc, char *argv[])
{
        int n=0;
        while( scanf("%d",&n) && n ){

                  int dimension=ceil(sqrtf(n));

                  int row=dimension,col=dimension;

                  int middle=(dimension*dimension)-(dimension-1);

                  int diferencia=(n>middle)?n-middle:middle-n;

                  if(middle<n)row-=diferencia;
              else      col-=diferencia;


                  if(dimension%2==0)p(col,row);
                  else p(row,col);

          }

  return 0;
}
