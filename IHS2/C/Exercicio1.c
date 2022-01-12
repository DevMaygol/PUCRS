#include <stdio.h>

int main(void) {

  int vetor[10];
  int i;

  for(i=1;i<=10;i++){
    vetor[i]=1+i;
    printf("%d \n", i);
  }

  printf("\n");

  for(i=10;i>=0;i--){
    vetor[i]=i-1;
    printf("%d \n", i);
  }

  system("PAUSE");	
  return 0;
}
