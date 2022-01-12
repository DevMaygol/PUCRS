int contador = 1000;

void setup() {

  pinMode(7, OUTPUT);
}

void loop() {
 
  digitalWrite(7, HIGH);   
  delay(contador);                       
  digitalWrite(7, LOW);   
  delay(contador);

  contador -= 10;

                         
}
