#include <stdio.h>

/*void muda(int *aux1,int *aux2)
{
    *aux1 = rand()%10;
    *aux2 = rand()%10;
}*/
void troca (int *, int *);
int main()
{
    int a, b, c;
    /*muda(&a, &b);
    printf("%d %d\n", a, b);
    c = a;
    a = b;
    muda(&a, &b);
    b = a;
    printf("%d %d\n", a, b);*/

    printf("Digite a e depois b: ");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("Valor de a: %d, valor de b: %d\n", a, b);
    troca(&a, &b);
    printf("Valor de a: %d, valor de b: %d\n", a, b);

    return 0;
}
void troca (int *ptr01, int *ptr02)
{
    int aux;
    aux = *ptr01;
    *ptr01 = *ptr02;
    *ptr02 = aux;
}

