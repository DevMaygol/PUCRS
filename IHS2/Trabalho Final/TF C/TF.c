#include <stdlib.h>
#include <stdio.h>

struct horario
{
	int hora;
	int minuto;
	int segundo;
};
	
int main ()
{
	void receberHorarios (struct horario list[4]);
	void printarHorarios (struct horario list[4]);
	struct horario listaHorarios [4];	
	
	receberHorarios (listaHorarios);
	printarHorarios (listaHorarios);
	
	struct horario agora, *depois;
	depois = &agora;
	
	depois -> hora = 20;
	depois -> minuto = 80;
	depois -> segundo = 50;
	
	int diferenca = 100;
	
	struct horario antes;
	
	antes.hora 	= diferenca - depois->segundo;
	antes.minuto= diferenca - depois-> minuto;
	antes.segundo= diferenca - depois-> segundo; 
	
	printf("%d:%d:%d\n", antes.hora, antes.minuto, antes.segundo);
	
	system ("pause");
	return 0;
}

	void receberHorarios (struct horario list[4]){
		int i;
		for (i = 0; i<4; i++){
			printf("Digite o %d horario (hh:mm:ss): \n", i + 1);
			scanf("%d:%d:%d", 	&list[i]. hora,
								&list[i]. minuto,
								&list[i]. segundo);
		}
	}
	
	void printarHorarios (struct horario list[4]){
		int i;
		for (i = 0; i < 4; i++){
			printf("O %d horario eh: %d:%d:%d\n", 	i + 1,
													list[i]. hora,
													list[i]. minuto,
													list[i]. segundo);
		}
	}
