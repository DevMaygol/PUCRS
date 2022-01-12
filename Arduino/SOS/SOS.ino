int led1=2;
void setup() {

  pinMode(led1, OUTPUT);
}

void loop() {
  //S
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(200);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(200);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(200);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(200);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(200);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(400);
  
  //O
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(600);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(200);
   digitalWrite(LED_BUILTIN, HIGH);   
  delay(200);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);   
  delay(400);
 

  //S
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(200);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(200);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(200);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(200);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(200);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(200);

   digitalWrite(LED_BUILTIN, LOW);   
  delay(1000);
                         
}
