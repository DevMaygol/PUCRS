#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,j,k, p1, p2, p3; //p1 = pontuação1
	
	printf("digite um valor de 1 a 6\n");
	scanf("%d",&i);
	printf("digite um valor de 1 a 6\n");
	scanf("%d",&j);
	printf("digite um valor de 1 a 6\n");
	scanf("%d",&k);
	
	//Jogador 1
	
if (i>=4 && i<=6 || j>=4 && j<=6 || k>=4 && k<=6){
	if (i==j&&j==k){
		printf("Venceu a rodada\n");
	}
}
//duplas de 6
if (i==6 && j==6 && i != 1 && j != 1){
	printf("Venceu a rodada!");
}
if (i>=1 && i<=3 || j>=1 && j<=3 || k>=1 && k<=3){
	if (i==j&&j==k){
		printf("Perdeu a rodada\n");
	}	
}
//duplas de 1
if (i==1 && j==1 && i != 6 && j != 6){
	printf("Perdeu a Rodada!");
}
//não devia aprecer a pontuação depois de digitar os dados
//testa a pontuação, tem erros ao digitar duplas de 1 e 6, pois esses valores dão ganho automático.

//ACHO QUE FUNCIONOU, TESTAR MAIS TARDE TUDO
//REPETIR TODO CÓDIGO PARA OS OUTROS JOGADORES
 
else if (i>=2 && i<=5 || j>=2 && j<=5 || k>=2 && k<=5){
	
	if(i==j && i != k){
		p1 = k;
		printf ("Pontuacao %d\n",p1);
	}
	else if(i==k && i != j){
		p2 = j;
		printf ("Pontuacao %d\n",p2);
	}
	else if(j==k && i!= k){
		p3 = i;
		printf ("Pontuacao %d\n",p3);
	}

}
	return 0;
}
