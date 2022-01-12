void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned short int aux;
  char comando;
  unsigned char data;
  if(Serial.available())
  {
    comando = Serial.read(); // lê serial
    if(comando == 'R'){
      aux = analogRead(A0);
      data = aux;// Pega a parte baixa do aux (8 ultimos bits)
      Serial.write(data); // Envia pela serial
      data = aux >> 8; // Pega a parte alta
      Serial.write(data);// Envia a parte alta
    }
  }
}
