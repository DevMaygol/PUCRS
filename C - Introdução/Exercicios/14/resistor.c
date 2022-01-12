#include <stdio.h>
#include <stdlib.h>
float resistor (float a, float b){
      float r;
      r = (1/a) + (1/b);
      r = 1/r;
      return r; 
      }

int main()
{
  float res1, res2, resistencia;
  printf("Digite um valor de resistencia:\n");
  scanf("%f",&res1);
  printf ("Digite um valor de resistencia:\n");
  scanf("%f", &res2);
  resistencia = resistor (res1, res2);
  printf ("Valor da resistencia total: %.2f\n", resistencia);
  
  system("PAUSE");	
  return 0;
}
