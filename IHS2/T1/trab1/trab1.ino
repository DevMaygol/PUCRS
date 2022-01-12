const byte listaDisplay[12] = {
B0000001,
B1001111,
B0010010,
B0000110,
B1001100,
B0100100,
B0100000,
B0001111,
B0000000,
B0000100,
B1000010,
B1101000,
};

int pinos[7] = {7,6,5,4,3,2,1};

String nome1, nome2;

int dado1,dado2,dado3,dado4,dado5,dado6;

int b=1,j=2;

void setup() {

Serial.begin(9600);

for(int i=0;i<7;i++){
pinMode(pinos[i],OUTPUT);
}

Serial.println("Bem vindo ao jogo Cee-Io");
Serial.println("Antes de começar, digite o nome de quem vai começar como banco:");

}


void loop() {
  //while(Serial.available()==0){
if(Serial.available()>0){
nome1 = Serial.readString();
Serial.print("O banco eh:");
Serial.println(nome1);
Serial.println("Agora digite o nome do jogador:");
}
  

if(Serial.available()>0){
nome2 = Serial.readString();
Serial.print("O jogador eh: ");
Serial.println(nome2);
Serial.println("Para sortear os dados do banco, aperte qualquer tecla");
}


if(Serial.available()>0){
Serial.println("O primeiro dado: ");
dado1 = random(1,6);
Serial.println(dado1);
delay(1000);
Serial.println("O segundo dado:");
dado2 = random(1,6);
Serial.println(dado2);
delay(1000);
Serial.println("O terceiro dado:");
dado3 = random(1,6);
Serial.println(dado3);
delay(1000);
}
  
while(Serial.available()==0){
  if (dado1==dado2 && dado2 == dado3){
    Serial.println("Venceu a rodada");
    }
}


}
