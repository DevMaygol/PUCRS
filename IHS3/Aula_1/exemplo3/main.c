#include <stdio.h>
#include <stdlib.h>
#define NCOL 10
#define NLIN 10

int main()
{
    int MAT [NCOL][NLIN], i , j;
    int maior, menor, soma = 0;
    srand (time(NULL));
    for (i = 0; i<NCOL;i++)
    {
        for(j = 0; j<NLIN; j++)
        {
            MAT[i][j] = (rand () % 201) - (NCOL * NLIN);
            printf("%5d", MAT[i][j]);
        }
        putchar('\n');
    }
    maior = MAT[0][0];
    menor = MAT[0][0];
    for (i = 0; i<NCOL;i++)
    {
        for(j = 0; j<NCOL; j++)
        {
            soma += MAT[i][j];
            //soma = soma + MAT[j][k];
            if(MAT[i][j] > maior) maior = MAT[i][j];
            if(MAT[i][j] < menor) menor = MAT[i][j];
        }
        putchar('\n');
    }
    printf("Maior elemento: %d\n", maior);
    printf("Menor elemento: %d\n", menor);
    printf("Media: %f\n", (float) soma/(NCOL * NLIN));
    return 0;
}
