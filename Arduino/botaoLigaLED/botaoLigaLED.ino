int botao = 30;
int buttonState;  
int led = 53;
int bread;
       
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(botao, INPUT);
  pinMode(led, OUTPUT);
  random (5);
  random (1,4);
  bread = random (1,4);
}

void loop() {
   
  buttonState = digitalRead(botao);

  if (buttonState == LOW) {
    digitalWrite(bread, LOW); 
  } else {
    digitalWrite(bread, HIGH);
  }
}
