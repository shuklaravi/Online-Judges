#include <stdio.h>

/* TURTLE problem: Weights and Measures
 * Dwight Makaroff
 * Adapted by solution from discussion group on the internet
 */

/*
  mw(i,k) (i is number of step).
if mw(i-1,k-1)+weight(i)<=strength(i)
          mw(i,k) = min(mw(i-1,k), mw(i-1,k-1)+weight(i))
    or else mw(i,k) = mw(i-1,k).
 Answer is maximum k with mw(n,k)<infinity. */

/* I'd need to draw the picture to give a full and clear idea of how to
 * approach this problem. It's a hard problem, as in it's a tricky thing of
 * dynamic programming, but a neat solution. We can follow the idea, but I
 * can't currently write down the solution idea in an intermediate level of
 * detail at this point.
 */

#define MAX 5608
#define MAXINT 2000000000
typedef struct turtle
{
  int weight;
  int load;
  int diff;
  int hs;
} TURTLE;

int minweight[2][MAX];

TURTLE turtles[MAX];
int numTurtles;

void swap(TURTLE *T, int i, int j)
{
  TURTLE temp;

  temp.weight = T[i].weight;  temp.hs = T[i].hs;  temp.load = T[i].load;
  temp.diff = T[i].diff;

  T[i].weight = T[j].weight;  T[i].hs = T[j].hs;  T[i].load = T[j].load;
  T[i].diff = T[j].diff;

  T[j].weight = temp.weight;  T[j].hs = T[i].hs;  T[j].load = temp.load;
  T[j].diff = temp.diff;
}

/* Quicksort */
void sortTurtles(TURTLE *T, int left, int right)
{
  int i, last;
  if (left >= right) return;
  swap(T, left, (left+right)/2);
  last = left;
  for (i = left+1; i <= right; i++)

    /* sort by load major */
    if ((T[i].load < T[left].load)
	|| (T[i].load  == T[left].load && T[i].weight < T[left].weight))
      swap(T, ++last, i);
  swap(T, left, last);
  sortTurtles(T,left, last -1);
  sortTurtles(T,last+1, right);
}

void printTurtles(int Size)
{
  int i;
  printf("Sorted %d\n",Size);
  for (i=0;i<Size;i++)
    /* printf("Turtle %3d: W:%6d\t  D:%6d\t Key:%llu\n", i, turtles[i].weight,
	  turtles[i].diff, turtles[i].sortkey); */
    printf ("%d %d\n", turtles[i].weight, turtles[i].load);
}

int solve(int load, int size){
  int i,k;
  int curMax = 0; /* max height of the stack so far */
  int clear;

  /* only use 2 rows, because we don't care about previous */
  for (i=0;i<=numTurtles;i++) {    minweight[0][i] = MAXINT; }
  for (i=0;i<=2;i++) {       minweight[i][0] = 0;    }

  for (i=1;i<=numTurtles;i++)
    {
      for (k=1;k<=numTurtles;k++)
	{
	/* we can lift the next turtle */
	if (minweight[0][k-1]+turtles[i].weight<=turtles[i].load)
	  {
	    if (minweight[0][k]< minweight[0][k-1] +  turtles[i].weight)
	      {
		minweight[1][k] = minweight[0][k];
	      }
	    else
	      {
		minweight[1][k] = minweight[0][k-1] +  turtles[i].weight;
	      }
	    if (k > curMax && minweight[1][k] < MAXINT) curMax = k;
	  }
	else
	  minweight[1][k] = minweight[0][k];
	}

      /* copy over the calculation from this iteration to make it the
	 previous iteration. Get rid of previous iteration by overwriting
      */
      for (clear = 0; clear<= i; clear++)
	minweight[0][clear] =  minweight[1][clear];

      }
  return (curMax);
}


int main()
{
  int i = 1;
  int max = 0;

#if DEBUG
  printf("Original\n");
#endif

  /* Read input from the data file */
  while (scanf("%d %d",&(turtles[i].weight), &(turtles[i].load)) != EOF)
  {
    turtles[i].diff = turtles[i].load - turtles[i].weight;

#if DEBUG
     printf("Turtle %3d: W:%6d\t  D:%6d\t Key:%llu\n",i, turtles[i].weight,
       turtles[i].diff, turtles[i].sortkey);
#endif
    i++;
  }

  sortTurtles(turtles,1,i-1);
  numTurtles = i-1;

#if DEBUG
  printTurtles(i);
#endif
  max = solve(0,0);
  printf("%d\n", max);
  return 0;
}
