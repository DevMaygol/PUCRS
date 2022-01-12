#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int mat[10][10], k, i, j;
    int *ptr;

    ptr = &mat[0][0]; //ptr aponta para mat00

    for (k=0; k<100; k++)
    {
        *(ptr+k) = rand()%101;
    }

    for(i = 0; i<10 ; i++)
    {
        for(j=0 ; j<10 ; j++)
        {
            printf("%5d", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
