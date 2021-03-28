#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int x,y,suma,i;

  x=0;
  y=1;
 
  printf("0\n1\n",suma);
 
  for (i=1;i<=20;i=i+1)
  {
      suma=x+y;
      printf("%d\n",suma);
      x=y;
      y=suma;
  }
     
  return 0;
}
