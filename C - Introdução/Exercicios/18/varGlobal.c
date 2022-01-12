#include <stdio.h>
#include <stdlib.h>

int i = 1;

func(){
       int i = 100;
       i = i + 1;
       printf ("Valor de i: %d na funcao func()\n", i);
       }
int main()
{
  i = i + 1;
  func();
  printf ("Valor de i = %d\n", i);
  
  system("PAUSE");	
  return 0;
}
