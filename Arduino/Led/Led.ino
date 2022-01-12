const int led1=2;
void setup() {

  pinMode(led1, OUTPUT);
}

void loop() {
  //S
  digitalWrite(led1, HIGH);   
  delay(200);                       
  digitalWrite(led1, LOW);   
  delay(200);
}
