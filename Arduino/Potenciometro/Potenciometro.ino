int pot;
int const led1 = 2;
int const led2 = 3;
int const led3 = 4;
int const led4 = 5;
int const led5 = 6;
int const led6 = 7;

void setup() {
Serial.begin (9600);
pinMode (led1, OUTPUT);
pinMode (led2, OUTPUT);
pinMode (led3, OUTPUT);
pinMode (led4, OUTPUT);
pinMode (led5, OUTPUT);
pinMode (led6, OUTPUT);
pinMode (pot, INPUT);
}

void loop() {
  pot = analogRead(0);
  Serial.println(pot/170);
 
  switch(pot/170){
    case 0:
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
    digitalWrite(led5, 0);
    digitalWrite(led6, 0);
    
    break;
    case 1:
    digitalWrite(led1, 1023);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
    digitalWrite(led5, 0);
    digitalWrite(led6, 0);
    
    break;
    case 2:
    digitalWrite(led1, 1023);
    digitalWrite(led2, 1023);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
    digitalWrite(led5, 0);
    digitalWrite(led6, 0);
    
    break;
    case 3:
    digitalWrite(led1, 1023);
    digitalWrite(led2, 1023);
    digitalWrite(led3, 1023);
    digitalWrite(led4, 0);
    digitalWrite(led5, 0);
    digitalWrite(led6, 0);
    
    break;
    case 4:
    digitalWrite(led1, 1023);
    digitalWrite(led2, 1023);
    digitalWrite(led3, 1023);
    digitalWrite(led4, 1023);
    digitalWrite(led5, 0);
    digitalWrite(led6, 0);
    
    break;
    case 5:
    digitalWrite(led1, 1023);
    digitalWrite(led2, 1023);
    digitalWrite(led3, 1023);
    digitalWrite(led4, 1023);
    digitalWrite(led5, 1023);
    digitalWrite(led6, 0);
    
    break;
    
    }

}
