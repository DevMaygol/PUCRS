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

int i,j,k,p1,p2,p3,t;

void setup() {
  
  Serial.begin(9600);
  
  for(int t=0;t<7;t++){
    pinMode(pinos[t],OUTPUT);
  }

  randomSeed(analogRead(0));
  
}


void loop() { 
    Serial.println("\nBem vindo ao jogo Cee-Io");
  Serial.println("Antes de começar, digite o nome de quem vai começar como banco:");
  while(Serial.available()==0){
  }
  nome1 = Serial.readString();
  Serial.print("O banco eh:");
  Serial.println(nome1);
  Serial.println("Agora digite o nome do jogador:");
  
  
  
  while(Serial.available()==0){
  }
    nome2 = Serial.readString();
    Serial.print("O jogador eh: ");
    Serial.println(nome2);
    Serial.println("Para sortear os dados do banco, aperte qualquer tecla");
  
  
  
 while(Serial.available()==0){
 }
    Serial.println("O primeiro dado: ");
    dado1 = random(1,6);
    i=dado1;
    ligarDisplay(dado1);
    Serial.println(dado1);
    delay(500);
    Serial.println("O segundo dado:");
    dado2 = random(1,6);
    j=dado2;
    ligarDisplay(dado2);
    Serial.println(dado2);
    delay(500);
    Serial.println("O terceiro dado:");
    dado3 = random(1,6);
    k=dado3;
    ligarDisplay(dado3);
    Serial.println(dado3);
    delay(500);
    
    Serial.println("Para sortear os dados do jogador, aperte qualquer tecla");
    Serial.end();
    Serial.begin(9600);
    
 while(Serial.available()==0){
 
 }
 
    Serial.println("O primeiro dado: ");
    dado4 = random(1,6);
    Serial.println(dado4);
    ligarDisplay(dado4);
    delay(500);
    Serial.println("O segundo dado:");
    dado5 = random(1,6);
    Serial.println(dado5);
    ligarDisplay(dado5);
    delay(500);
    Serial.println("O terceiro dado:");
    dado6 = random(1,6);
    Serial.println(dado6);
    ligarDisplay(dado6);
    delay(500);
    
    Serial.end();
    Serial.begin(9600);
    
     while(Serial.available()==0){
 }

 Serial.println("parou");
 Serial.println(dado1);
 Serial.println(dado2);
 Serial.println(dado3);
 

 
if (dado1>=4 && dado1<=6 || dado2>=4 && dado2<=6 || dado3>=4 && dado3<=6){ //3 dados iguais
  if (dado1==dado2&&dado2==dado3){
    Serial.println("Venceu a rodada!\n");
    delay(1000);
  }
  
  //duplas de 6
  else if (dado1==6 && dado2==6 && dado1 != 1 && dado2 != 1){
    Serial.println("Venceu a rodada!");
     delay(1000);
  }
  else if (dado1==6 && dado3==6 && dado1 != 1 && dado3 != 1){
    Serial.println("Venceu a rodada!");
     delay(1000);
  }
  else if (dado2==6 && dado3==6 && dado2 != 1 && dado3 != 1){
    Serial.println("Venceu a rodada!");
     delay(1000);
  }
  //fim da dupla de 6
}
  if (dado1>=1 && dado1<=3 || dado2>=1 && dado2<=3 || dado3>=1 && dado3<=3){ //3 dados iguais
  
  if (dado1==dado2&&dado2==dado3){
    Serial.println("Perdeu a rodada!\n");
     delay(1000);
  }
  //duplas de 1
  else if (dado1==1 && dado2==1 && dado1 != 6 && dado2 != 6){
    Serial.println("Perdeu a Rodada!");
     delay(1000);
  }
  else if (dado1==1 && dado3==1 && dado1 != 6 && dado3 != 6){
    Serial.println("Perdeu a Rodada!");
     delay(1000);
  }
  else if (dado1==1 && dado3==1 && dado2 != 6 && dado3 != 6){
    Serial.println("Perdeu a Rodada!");
     delay(1000);
  }
  //fim da duplas de 1  
}
//Pontuacao caso houver um par de 2 a 5 
  if (dado1>=2 && dado1<=5 || dado2>=2 && dado2<=5 || dado3>=2 && dado3<=5){
  if(dado1==dado2 && dado1!= dado3 && dado1!=1 && dado1!=6){
    p1 = dado3;
     Serial.println("Pontuacao:");
    Serial.println(dado3); 
     delay(1000);  
  }
  else if(dado1==dado3 && dado1 != dado2 && dado1!=1 && dado1!=6){
    p2 = dado2;
    Serial.println("Pontuacao:");
    Serial.print(dado2);
     delay(1000);
  }
  else if(dado2==dado3 && dado1!= dado2 && dado2!=1 && dado2!=6){
    p3 = dado1;
    Serial.print("Pontuacao:");
    Serial.println(dado1);
   delay(1000);
  }

 
}
//Se todos os dados forem diferentes
if(dado1!=dado2 && dado1!=dado3 && dado2!=dado3){
  Serial.println("Jogue novamente!");
}
  Serial.end();
  Serial.begin(9600);
}



 void ligarDisplay(int num){
    boolean liga;
    for(int seg=0;seg<7;seg++)
    {
      liga = bitRead(listaDisplay[num],seg);
      digitalWrite(pinos[seg],liga);
    }
  }
