#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{int i;
  i = 20;
  printf ("i(dec) = %d\n", i);
  
  i=020;
  printf ("i(dec) = %d\n",i);
  
   i=0x20;
  printf ("i(dec) = %d\n",i);
  system("PAUSE");	
  return 0;
}
