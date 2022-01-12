#include <stdio.h>

int main(void) {

  int vetor[10];
  int decre[10];
  int i;
  int soma;

  for(i=0;i<9;i++){
    vetor[i]=1+i;
    printf("%d \n", vetor[i]);
  }

  printf("\n");

  for(i=11;i>1;i--){
    decre[i]=i-1;
    printf("%d \n", decre[i]);
  }
for(i = 0;i<9; i++){
    soma = vetor[i] + decre[i];
    printf("%d\n", soma);
}

  return 0;
}
