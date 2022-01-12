#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;
    
  printf("Digite um numero:\n");
  scanf("%d",&i);
  i = i & (i<<1);

if(i & (i<<1) == 1){
  printf("Numero eh par\n");
}
  else if(i & (i<<1) == 0) {
       printf("Numero eh impar\n");
       }
  
  
  system("PAUSE");	
  return 0;
}
