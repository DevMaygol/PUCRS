#include <stdio.h>
#include <stdlib.h>

int integer;
float floating;

int main(int argc, char *argv[])
{
    floating  = 1.0 / 2.0;
            printf ("%.2f\n", floating);
            
    integer = 1 / 3;
            printf ("%d\n", integer);
            
    floating = (1 / 2) + (1 / 2);
            printf ("%.2f\n", floating);
            
    floating = 3.0 / 2.0;
            printf ("%.2f\n", floating);
            
    integer = floating;
            printf ("%.2f\n", floating);
            
            printf ("%d\n", integer);
  
  system("PAUSE");	
  return 0;
}
