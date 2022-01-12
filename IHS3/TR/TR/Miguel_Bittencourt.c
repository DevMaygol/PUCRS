#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int nivel=0, x=0, y=0;

int level(int nvl)
{
    x = (rand () % nvl+1);
    y = (rand () % nvl+1);
    return nvl;
}

int main()
{
    // criando a variável ponteiro para o arquivo
    FILE *pont_arq;

    int  i, j, resp = 0, resp_user=0, n=0, acerto=0, rpt=0;
    float total=0;
    clock_t start_t=0, end_t=0;

    srand (time(NULL));

    //abrindo o arquivo
    pont_arq = fopen("RESPOSTAS.txt", "w");
    do
    {
        start_t = clock();
        printf("\n\t\t\tTrabalho TR:\n\nVoce fara um teste de multiplicacoes, tente acertar as questoes:\n\n");
        printf("Nivel do teste (ate qual valor sera tomada a tabuada): ");
        scanf("%d", &nivel);
        if (nivel == 0){
            printf("Por favor, inserir um valor acima de zero: ");
            scanf("%d", &nivel);
        }
        for (i = 0; i<1;i++)
        {
            for(j = 0; j<10; j++)
            {
                n++;
                level(nivel);
                resp = (x * y);
                printf("Questao: %d\t%d x %d = ", n, x, y);
                fprintf(pont_arq ,"Questao: %d\t%d x %d = ", n, x, y);
                scanf("%d", &resp_user);
                fprintf(pont_arq ,"%d", resp_user);
                if (resp_user==resp){
                    printf("\tCorreto\n\n");
                    fprintf(pont_arq ,"\tCorreto\n\n");
                    acerto++;
                }
                else{
                    printf("\tErrado\n");
                    printf("\tGabarito: %d\n\n", resp);
                    fprintf(pont_arq ,"\tErrado\n");
                    fprintf(pont_arq ,"\tGabarito: %d\n\n", resp);
                }
                //fprintf(pont_arq, "%s", palavra);
            }
        }

        printf("Acertos: %d de 10\n\n", acerto);
        fprintf(pont_arq ,"Acertos: %d de 10\n\n", acerto);
        end_t = clock();
        total = end_t - start_t;
        printf("Tempo para realizar o teste: %.2f segundos\n", total/1000);
        fprintf(pont_arq, "Tempo para realizar o teste: %.2f segundos\n", total/1000);
        printf("Tempo medio por questao: %.2f segundos\n\n", (total/1000)/10);
        fprintf(pont_arq, "Tempo medio por questao: %.2f segundos\n\n", (total/1000)/10);

        //mensagem para o usuário
        printf("O arquivo foi criado com sucesso!\n\n");
        printf("Pressione '1' para realizar novamente e '0' para sair: ");
        scanf("%d", &rpt);
        n=0;
        acerto = 0;
    }

    while(rpt == 1);
    // fechando arquivo
    fclose(pont_arq);

    return 0;
}
