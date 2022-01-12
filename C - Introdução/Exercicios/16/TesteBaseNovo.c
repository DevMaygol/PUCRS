#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;
    printf("Entre com numero de base 10\n");
    scanf("%d", &i);
    printf("Valor de i (em decimal) = %d\n", i);
 
    printf("Entre com numero de base 8\n");
    scanf("%o", &i);
    printf("Valor de i (em decimal) = %d\n", i);
    
    printf("Entre com numero de base 16\n");
    scanf("%x", &i);
    printf("Valor de i (em decimal) = %d\n", i); 
    
  system("PAUSE");	
  return 0;
}
