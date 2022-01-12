const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int led5 = 6;
const int led6 = 7;
int pot;

void setup() {
Serial.begin(9600);
  
pinMode (led1, OUTPUT);
pinMode (led2, OUTPUT);
pinMode (led3, OUTPUT);
pinMode (led4, OUTPUT);
pinMode (led5, OUTPUT);
pinMode (led6, OUTPUT);
pinMode (pot,INPUT);

}

void loop() {
pot = analogRead(0);
  Serial.println(pot/170);
  
  switch(pot/170){
    case 0:
    digitalWrite (led1, HIGH);
    digitalWrite (led2, LOW);
    digitalWrite (led3, LOW);
    digitalWrite (led4, LOW);
    digitalWrite (led5, LOW);
    digitalWrite (led6, LOW);
    break;
     case 1:
    digitalWrite (led2, HIGH);
    digitalWrite (led1, HIGH);
    digitalWrite (led3, LOW);
    digitalWrite (led4, LOW);
    digitalWrite (led5, LOW);
    digitalWrite (led6, LOW);
    break;
     case 2:
    digitalWrite (led3, HIGH);
    digitalWrite (led2, HIGH);
    digitalWrite (led1, HIGH);
    digitalWrite (led4, LOW);
    digitalWrite (led5, LOW);
    digitalWrite (led6, LOW);
    break;
     case 3:
    digitalWrite (led4, HIGH);
     digitalWrite (led3, HIGH);
    digitalWrite (led2, HIGH);
    digitalWrite (led1, HIGH);
    digitalWrite (led5, LOW);
    digitalWrite (led6, LOW);
    break;
     case 4:
    digitalWrite (led5, HIGH);
    digitalWrite (led4, HIGH);
     digitalWrite (led3, HIGH);
    digitalWrite (led2, HIGH);
    digitalWrite (led1, HIGH);
    digitalWrite (led6, LOW);
    break;
     case 5:
    digitalWrite (led6, HIGH);
     digitalWrite (led5, HIGH);
    digitalWrite (led4, HIGH);
     digitalWrite (led3, HIGH);
    digitalWrite (led2, HIGH);
    digitalWrite (led1, HIGH);
    break;
    
    }
    delay (100);
 

}
