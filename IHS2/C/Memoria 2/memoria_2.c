#include <stdio.h>

int main() {
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

// ESCREVENDO NO ARQUIVO

oi = fopen ("oi.txt","w");
fprintf(oi,"Hello! Mundo & pao\n");
fclose(oi);

// LENDO O ARQUIVO

char line [1000];

oi = fopen ("oi.txt", "r");
//fscanf (oi,"%s", line);
while (fgets (line, 1000, oi) != NULL)
	printf("Ler a linha %s\n",line);

fclose(oi);
}
