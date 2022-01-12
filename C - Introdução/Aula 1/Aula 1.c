#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int x;
    int y;
    int soma;
    
    printf ("Digite um numero inteiro:\n");
    scanf ("%d", &x);
    
    printf ("Digite outro numero inteiro:\n");
    scanf ("%d", &y);
    
    soma = x+y;
    printf ("A soma eh: %d\n", soma);
  system("PAUSE");	
  return 0;
}
