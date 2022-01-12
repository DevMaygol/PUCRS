#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int x;
    printf ("Digite um numero inteiro:\n");
    scanf ("%d", &x);
    x = 2*x;
    printf ("O dobro eh: %d\n", x);
  system("PAUSE");	
  return 0;
}
