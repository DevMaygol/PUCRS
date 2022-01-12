#include <TimerOne.h>

#include <TimerOne.h>

int verde = 12;
int var = 0;
int var1 = 0;
int botao = 9;
int botao2 =8;

void setup()
{
Serial.begin(9600);
pinMode(botao, INPUT);
pinMode(botao2, INPUT);

pinMode(verde, OUTPUT);


Timer1.initialize(500000); // Inicializa o Timer1 e configura para um período de 1 segundos
Timer1.attachInterrupt(callback); // Configura a função callback() como a função para ser chamada a cada interrupção do Timer1
}

void callback()
{
  digitalWrite(verde, digitalRead(verde) ^ 1);
  var1 = digitalRead(botao);
  if(var1 > 0)
  {
  var = var;  
  Serial.println(var);
  delay(1000);
  var = 0;
  }
  else{
  var++;
  //Serial.println(var);
  }

}

void loop()
{
delay(1000);
 }
