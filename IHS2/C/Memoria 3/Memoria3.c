#include <stdio.h>

int main() {
	
int vetor [5] = {1,2,3,4,5};
int i;
int media;
int soma;

FILE *oi;

// VERIFICANDO SE ABRIU O ARQUIVO

oi = fopen ("oi.txt","r");

if(!oi){
	printf("Error!\n");
}
	else{
			printf ("LEU\n");
	}
fclose(oi);

for(i=0;i<5;i++){
soma = soma + vetor[i];
printf ("%d", soma);
}

//oi = fopen ("oi.txt","w");



}
