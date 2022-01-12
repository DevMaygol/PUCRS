#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float m = 2.0;
    float N;
    float Fatrito;
    float aceleracao;
    float F1 = 5;
    float Ftotal;
    
    N = m * 9.8;
    printf ("Peso ou Normal: %.2f\n", N);
    
    Fatrito = 0.2 * N;
    printf ("Forca de Atrito: %.2f\n", Fatrito);  
      
    Ftotal = F1 - Fatrito;
    printf ("Forca Total: %.2f\n", Ftotal);
    
    aceleracao = Ftotal / m;
    
    printf ("Aceleracao: %.2f\n", aceleracao);
  
  system("PAUSE");	
  return 0;
}
