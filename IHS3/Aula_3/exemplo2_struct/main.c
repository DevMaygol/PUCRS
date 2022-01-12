#include <stdio.h>

struct aluno
{
    char  nome[100];
    float P1;
    float P2;
    float T1;
    int   faltas;
};

//typedef tipo_existente apelido;
typedef unsigned short int uint16;

struct aluno le_al_teclado(void);

int main()
{
    struct aluno alunos[22];
    alunos[0] = le_al_teclado();
    alunos[1] = le_al_teclado();
    printf("%d\n", alunos[0].faltas);

    return 0;
}

struct aluno le_al_teclado(void)
{
    struct aluno aux;
    printf("Digite nome: ");
    fflush(stdin); //limpa buffer de entrada
    gets (aux.nome);
    printf("Digite P1: ");
    scanf("%f", &aux.P1);
    printf("Digite P2: ");
    scanf("%f", &aux.P2);
    printf("Digite T1: ");
    scanf("%f", &aux.T1);
    printf("Digite faltas: ");
    scanf("%d", &aux.faltas);
    return aux;
}
