#include <stdio.h>
#include <stdlib.h>

int adicao(int a, int b){
    int s;
    s = a + b;
    return s;
    }

int main()
{
  int soma;
  soma = adicao(60,7);
  printf ("Resultado: %d\n", soma);
  
  system("PAUSE");	
  return 0;
}
