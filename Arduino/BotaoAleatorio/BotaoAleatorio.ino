const int buttonPin = 3;     
const int led1 =  13;   
const int led2 =  12;
int numero;   

int buttonState = 0;         

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buttonPin, INPUT);
  numero = random(0 , 2);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    numero = random(0 , 2);
    if (numero == 0){
       digitalWrite(led1, HIGH);
       digitalWrite(led2, LOW);
      }
    else {
      digitalWrite(led2, HIGH);
      digitalWrite(led1, LOW);

  
      
      }
      delay (1000);
  }
}
