#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int numero;
  
  printf ("Digite um numero qualquer: \n");
  scanf ("%d", &numero);
  
  if (numero % 2 == 0){
          printf ("O numero eh par\n");
          }
  else{
       printf ("O numero eh impar\n");
       }
  
  system("PAUSE");	
  return 0;
}
