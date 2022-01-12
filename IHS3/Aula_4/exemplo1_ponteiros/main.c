#include <stdio.h>

int main()
{
    int a, b;
    int *ptr;

    a=10;
    b=20;

    printf("Endereco: %x, valor: %d\n", &a, a);
    printf("Endereco: %x, valor: %d\n", &b, b);
    printf("Endereco: %x, valor: %d\n", &ptr, ptr);

    ptr = &a;
    printf("Endereco: %x, valor: %x\n", &ptr, ptr);

    *ptr = 35;
    printf("Endereco: %x, valor: %d\n", &a, a);

    printf("Endereco: %x, valor: %x\n", &ptr, ptr);
    ptr--;
    printf("Endereco: %x, valor: %x\n", &ptr, ptr);
    return 0;
}
