#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int num_r1, num_r2, num_r3;

int jogar1 (int num_r1){
    
    num_r1 = 0+(rand())%7;
    return num_r1; 
    }
    
int jogar2 (int num_r2){
    
    num_r2 = 0+(rand())%7;
    return num_r2; 
    }
    
int jogar3 (int num_r3){
    
    num_r3 = 0+(rand())%7;
    return num_r3; 
    }

int main()
{
  int dado1, dado2, dado3, soma;
  
      srand((unsigned) time(NULL));
  
          dado1 = jogar1(num_r1);
                printf ("Valor do primeiro dado: %d\n", dado1);
   
          dado2 = jogar2(num_r2);
                printf ("Valor do segundo dado: %d\n", dado2);
   
          dado3 = jogar3(num_r3);
                printf ("Valor do terceiro dado: %d\n", dado3);
  
soma = dado1 + dado2 + dado3;
     printf ("Valor da soma: %d\n", soma);
  
  system("PAUSE");	
  return 0;
}
