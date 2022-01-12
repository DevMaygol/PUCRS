#include <stdio.h>
struct PREGUICA
{
    float bocejo;
    int poca_voia;
};
int main()
{
    struct PREGUICA aux, *ptr;
    ptr = &aux;
    ptr -> bocejo = 54.8;
    ptr -> poca_voia = 10;
    printf("Valor: %f, valor: %d\n", aux.bocejo, aux.poca_voia);
    return 0;
}
