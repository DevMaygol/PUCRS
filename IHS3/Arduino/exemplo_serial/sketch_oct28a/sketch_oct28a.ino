void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  char aux;
  while(!Serial.available()); //Se chegar algo na serial, o programa sai do while
    aux = Serial.read();
    if(aux == 'L' ) digitalWrite (13, HIGH);
    if(aux == 'D' ) digitalWrite (13, LOW);

}
