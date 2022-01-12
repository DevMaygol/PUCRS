#include <stdio.h>
#include <stdlib.h>

int maior, a, b;

int main(int argc, char *argv[])
{    
    printf ("Digite um valor:\n");
    scanf ("%d", &a);
    printf ("Digite outro valor:\n");
    scanf ("%d", &b);
    maior = numeros (a,b);
  
  system("PAUSE");	
  return 0;
}

int numeros(int x, int y){
    int m;
    
    if (x > y){
          printf ("%d eh maior!\n", a);
          m = x;
          }
          else if (x < y){
               printf ("%d eh maior!\n", b);
               m = y;
               }
               else if (x = y){
               printf ("Sao iguais, idiota!\n");
               }
               return m;
    }
