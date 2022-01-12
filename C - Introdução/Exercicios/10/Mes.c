#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int mes;
        printf ("Insira um numero de 1 a 12\n");
        scanf("%d", &mes);
        
        switch (mes){
               case 1: case 3: case 5: case 7:case 8: case 10: case 12:
                    printf ("O mes escolhido tem 31 dias\n");
                    break;
               
               case 4: case 6: case 9: case 11:
                    printf ("O mes escolhido tem 30 dias\n");
                    break;
               
               case 2:
                    printf ("O mes escolhido tem 28 ou 29 dias\n");
                    break;
                                   
               default:
                       printf ("Digite um mes de 1 a 12!!!!\n");
               
               }
  
  system("PAUSE");	
  return 0;
}
