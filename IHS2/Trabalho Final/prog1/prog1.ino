String randNumber1,randNumber2; //Variáveis para as sequências do cofre para os dois jogadores

#include <Wire.h>
#include <string.h>

struct dados{
    String nome1, nome2, nome3;
    unsigned long tempo1, tempo2, tempo3, tempo4;
    unsigned long total1, total2;
};

int c = 0; //Contador do LED
int cc = 0; //Contador do loop do cofre

int numeropot=0; //Variável para salvar a conversão do valor analógico para um inteiro de 0 a 9
int pinoPOT = A1; //Porta que registrará o valor analógico do potenciômetro

void setup() {
  Wire.begin();
  Serial.begin(9600);
  int *atraso;
  int vaiAtrasar = 1000;
  atraso = &vaiAtrasar;
  
  Serial.println("ESTE PROGRAMA É UM PROTÓTIPO, PODEM HAVER ERROS E BUGS");
  Serial.println("DESCONSIDERE-OS!");
  Serial.println();
  Serial.println();
  
  delay(*atraso);
  
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
  

//pinMode(50,OUTPUT); //Porta do LED indicativo do cofre
//digitalWrite(10,LOW); //Garante o desativamento o LED
//
//
//
//randomSeed(analogRead(0));
//randNumber1 = random(1000000,9999999); //Gera número aleatório na faixa abordada para o jogador 1
//randNumber2 = random(1000000,9999999); //Gera número aleatório na faixa abordada para o jogador 2
//Serial.println(randNumber1);
//Serial.println(randNumber2);
//
//pinMode(pinoPOT,INPUT); //Pino de entrada de dados do potenciômetro

}

void loop() {
  
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
   String *ponteiro;
   String nome4;
   nome4 = Serial.readString();
   ponteiro= &nome4;
   Serial.print("Nome: ");
   Nomes.tempo4 = millis (); 
   Serial.println(*ponteiro);
   
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
  //randNumber1 = random(1000000,9999999); //Gera número aleatório na faixa abordada
  //Serial.println(randNumber); //REGISTRAR HORÁRIO DE COMEÇO
  
//  for(c=0;c<3;c++){ //Loop para o LED piscar indicando que o número foi gerado
//    digitalWrite(50,HIGH);
//    delay(500);
//    digitalWrite(50,LOW);
//    delay(500);
//  }
//  
//  while(cc<=10){ //Começo do loop do cofre do jogador 1
//  
//  
//  numeropot = map(analogRead(pinoPOT),0,1023,0,9); //Leitura do potenciômetro
//  Serial.println(numeropot);
//  
//  twosec(numeropot);
//  delay(500);
//  
//  }
//Serial.println("Tempo do 1: ");
//tempo1 = millis ();
//Serial.println(tempo1);
//
//while(Serial.read() == 0){ //Pausa enquanto o jogador 1 não pressiona uma tecla
//  }
//  Serial.println("Tempo do 2: ");
//tempo2 = millis ();
//Serial.println(tempo2); 

}
//-----Função para o funcionamento do LED

void twosec(int numeropot){
  
  if(numeropot == randNumber1[1]){
    Serial.println("bateu o valor"); 
  }
}
