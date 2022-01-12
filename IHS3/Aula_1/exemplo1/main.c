#include <stdio.h>

int main()
{
    int aux;
    for(aux = 1; aux <= 20; aux++)
    {
        if( !(aux%2) ) continue;    //usar continue (vai printar os numeros impares),
                                    //break (vai printar somente 1) ou return 0 (termina o programa)
        printf("%d\n", aux);

    }
    printf("Saiu\n");
    return 0;
}
