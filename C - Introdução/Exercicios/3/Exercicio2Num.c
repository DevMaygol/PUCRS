#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;
    printf("Digite um numero decimal:\n");
    scanf("%d", &i);
    i = i >> 1;
    printf("%d\n",i);
  
  system("PAUSE");	
  return 0;
}
