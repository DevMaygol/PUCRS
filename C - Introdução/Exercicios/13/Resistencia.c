#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float tensao1, tensao2, tensao3;
    float potencia, corrente;
    float resist1, resist2, resist3, req, tensao;
    
    //Serie:
    
     printf ("Calculo circuito em serie:\n\n");
     
    //Resistor 1
    printf ("Insira a tensao do Resistor 1: \n");
    scanf ("%f", &tensao1);
    
    printf ("Insira a resistencia do Resistor 1 em Ohms:\n");
    scanf("%f", &resist1);
    
    //Resistor 2
    printf ("\nInsira a tensao do Resistor 2: \n");
    scanf ("%f", &tensao2);
    
    printf ("Insira a resistencia do Resistor 2 em Ohms:\n");
    scanf("%f", &resist2); 
        
    //Resistor 3
    printf ("\nInsira a tensao do Resistor 2: \n");
    scanf ("%f", &tensao3);
    
    printf ("Insira a resistencia do Resistor 3 em Ohms:\n");
    scanf("%f", &resist3);
    
    //Calculo final
    
    req = resist1 + resist2 + resist3;
    tensao = tensao1 + tensao2 + tensao3;
    printf ("\n\nTensao: %.2f V\n\n", tensao);
    
    req = resist1 + resist2 + resist3; 
    printf ("Resistencia equivalente: %.2f Ohms\n\n", req);
    
    corrente = tensao / req;
    
    potencia = tensao * corrente;
    printf ("Potencia: %f Watts\n", potencia);
  
  system("PAUSE");	
  return 0;
}
