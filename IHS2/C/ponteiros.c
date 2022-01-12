#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	//valor é a variável que será apontada pelo ponteiro
  	int valor = 100;
  
  	//declaração de variável ponteiro
  	int *ponteiro;
  
 	//atribuindo o endereço da variável valor ao ponteiro
  	ponteiro = &valor;
  
  	printf("Utilizando ponteiros\n\n");
  	
  	printf ("Conteudo da variavel valor: %d\n", valor);
  	printf ("Endereco da variavel valor: %d \n", &valor);
  	printf ("Conteudo da variavel ponteiro X: %X", &ponteiro);
	
	return 0;
}
