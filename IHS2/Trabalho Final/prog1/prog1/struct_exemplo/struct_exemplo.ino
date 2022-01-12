#include <string.h>

struct dados{
    String nome1, nome2, nome3, nome4;
    unsigned long tempo1, tempo2, tempo3, tempo4;
    unsigned long total1, total2;
};

void setup(){

  Serial.begin(9600);
 
  Serial.println("ESTE PROGRAMA É UM PROTÓTIPO, PODEM HAVER ERROS E BUGS");
  Serial.println("DESCONSIDERE-OS!");
  Serial.println();
  Serial.println();
  
  delay(1000);
  
  Serial.println("Bem vindo ao jogo do Cofre!");
  Serial.println();
  Serial.println("Essas sao as regras do jogo:");
  Serial.println();
  Serial.println("Gire o potenciometro e espere 2 segundos para verificar se a posição esta correta");
  Serial.println("Quem acertar a senha de 7 digitos para abrir o cofre no menor tempo eh o vencedor!");
  Serial.println();
  Serial.println("Estamos testando quem digita o nome mais rapido para adaptar ao potemciometro!");
  Serial.println("Antes de começar, digite o nome de quem vai começar:");
  Serial.println();
  Serial.println("Rodada do jogador 1:");
}

void loop(){
  
  //------------- Jogador 1 ---------------
  // parte para testar a diferença de tempo para o jogadores e inputs de informações para obtermos os tempos
  // esta sendo testado quem ganha, se voce digitar o nome do jog1 e do 2 mais rapido, só precisa adaptar isso para os dados do potenciometro
  

 struct dados Nomes;
 
  while(Serial.available()==0){
    }
    Nomes.nome1 = Serial.readString();
    Serial.print("Jogador 1 eh: ");
    Serial.println(Nomes.nome1);
    Nomes.tempo1 = millis ();
    Serial.println("Digite seu nome de novo!");
  
 while(Serial.available()==0){
   }
   Nomes.nome2 = Serial.readString();
   Serial.print("Nome: ");
   Serial.println(Nomes.nome2);
   Nomes.tempo2 = millis ();

 struct dados dif;
   dif.total1 = (Nomes.tempo2 - Nomes.tempo1);
   Serial.print("Tempo de diferença: ");
   Serial.println(dif.total1);
   Serial.println();

   //------------- Jogador 2 ---------------
  Serial.println("Rodada do jogador 2:");
  Serial.println();
  Serial.println("Digite seu nome:");
  while(Serial.available()==0){
  }
  Nomes.nome3 = Serial.readString();
  Serial.print("Jogador 2 eh: ");
  Serial.println(Nomes.nome3);
  Nomes.tempo3 = millis ();
  Serial.println("Digite seu nome de novo!");

  while(Serial.available()==0){
  }
   Nomes.nome4 = Serial.readString();
   Serial.print("Nome: ");
   Nomes.tempo4 = millis (); 
   Serial.println(Nomes.nome4);
   
   dif.total2 = (Nomes.tempo4 - Nomes.tempo3);
   Serial.print("Tempo de diferença: ");
   Serial.println(dif.total2);
   
// -------------- TESTE PARA VER QUEM GANHOU --------------
   Serial.println();
   if (dif.total2 < dif.total1){
      Serial.print(Nomes.nome3);
      Serial.println("Venceu!");
    }
   else {
      Serial.print(Nomes.nome1);
      Serial.println("Venceu!");
    }
   Serial.println(); 
   Serial.print("Agora eh a vez do(a) ");
   Serial.println(Nomes.nome1);
}
