#include <stdio.h>

int main()
{
    unsigned short int lad;
    float tensao;
    lad = 500;
    tensao = (5.0*lad)/1023; //(float) eh um cast, mudando a conversao da expressao
    printf("%f\n", tensao);
    return 0;
}
