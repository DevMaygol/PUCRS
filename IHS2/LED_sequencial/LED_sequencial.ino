int led1 = 2;
int pino;
int pot = A0;
int valorpot;
int velo;
int led6 = 7;
int led4 = 4;

void setup() {
  
  //variavel pino que serve para o for somente
  
  for (pino = led1; pino < led1+6 ; pino++)
    {
      pinMode (pino, OUTPUT);
    }
    
    pinMode(led6, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(pot, INPUT);
    
    Serial.begin (9600);
}

void loop() {
  
valorpot = analogRead(pot);
velo = map(valorpot, 0, 1023, 0, 300);
Serial.println(velo);
  
    for (pino = led1; pino < led1+6 ; pino++) //desliga os leds
      {
        digitalWrite (pino, LOW);
      }
    
  digitalWrite(led1, HIGH); //liga o primeiro led
  delay(velo);

        for (pino = led1+1; pino < led1+3 ; pino++) //liga os seguintes e repete
        {
          digitalWrite(pino, HIGH);
          digitalWrite(pino-1, LOW);       
          delay(velo);
        }
        
        digitalWrite(led4, LOW);
        
        for (pino = led4; pino > led1; pino--) //inverso
          {
            digitalWrite (pino, LOW);
            digitalWrite (pino-1, HIGH);
            delay(velo);
          }
        digitalWrite(led1, LOW);
        
        for (pino = led1+1; pino < led1+6 ; pino++) //liga os seguintes e repete
        {
          digitalWrite(pino, HIGH);
          digitalWrite(pino-1, LOW);       
          delay(velo);
        }
        
        digitalWrite(led6, LOW);
        
          for (pino = led6; pino > led1; pino--) //inverso
          {
            digitalWrite (pino, LOW);
            digitalWrite (pino-1, HIGH);
            delay(velo);
          }
 }
