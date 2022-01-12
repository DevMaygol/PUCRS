#include <stdio.h>
/*
Faça uma função que imprima N elementos da série de Fibonacci.
Além disso, a função deve retornar a aproximação do número de ouro.

tipo_retorno identificador (tipo id01, tipo id02)
{
    comando;
    return algo; //(se tiver retorno numérico)
}
*/
float fibonacci (int n);
int main()
{
    fibonacci(10);
    printf("\n");
    return 0;
}


float fibonacci (int n)
{
  int atual = 1, passado = 1, aux;
  if(n < 2) return 0;
  else
  {
      n -=2;
      printf("1 1 ");
      do
      {
          aux = atual + passado;
          passado = atual;
          atual = aux;
          printf("%d ", aux);
      }while(--n);

  }
}

