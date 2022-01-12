#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    float Bx = 3;
    float By = 4;
    float Bz = 12;
    float M;
    float ab;
    float B = 6;
    
    M = sqrt(pow(Bx, 2) + pow(By, 2) + pow(Bz, 2));
    printf ("Modulo: %.2f\n", M);
    
    ab = B / M;
    printf ("Resultado ab: %.2f\n", ab);   
  
  system("PAUSE");	
  return 0;
}
