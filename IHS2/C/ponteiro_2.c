#include <stdio.h>
#include <stdlib.h>

void troca (int *A, int *B, int *C){
	//valor � a vari�vel que ser� apontada pelo ponteiro
  	int valor;
  
  	//declara��o de vari�vel ponteiro
  	valor = *C;
  	*B = *A;
  	*A = valor;
}


int main(void) {
	int v1, v2, troc;
	printf("Digite um valor:\n");
	scanf ("%d", &v1);
	
	printf("Digite um valor para trocar com o anterior:\n");
	scanf ("%d", &v2);
	
	printf("Valor de A: %d\n", v1);
	printf("Valor de B: %d\n", v2);
	return 0;
}


