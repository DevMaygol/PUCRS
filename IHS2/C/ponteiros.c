#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	//valor � a vari�vel que ser� apontada pelo ponteiro
  	int valor = 100;
  
  	//declara��o de vari�vel ponteiro
  	int *ponteiro;
  
 	//atribuindo o endere�o da vari�vel valor ao ponteiro
  	ponteiro = &valor;
  
  	printf("Utilizando ponteiros\n\n");
  	
  	printf ("Conteudo da variavel valor: %d\n", valor);
  	printf ("Endereco da variavel valor: %d \n", &valor);
  	printf ("Conteudo da variavel ponteiro X: %X", &ponteiro);
	
	return 0;
}
