#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;
    printf("Digite um numero:\n");
    scanf("%d", &i);
    i = i &(i<<3) ;
    printf("%d\n", i); 
  system("PAUSE");	
  return 0;
}
