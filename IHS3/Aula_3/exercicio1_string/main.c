#include <stdio.h>
#include <string.h>

int main()
{
    char texto[100];
    int aux;

    printf("Digite seu nome: \n");
    //scanf ("%s", texto);
    gets(texto);
    printf("Nome: %s\n", texto);

    printf("Digite sua idade:\n");
    scanf("%d", &aux);
    printf("Idade: %d\n", aux);
    return 0;
}
