int valorLdr = 0;
int pinoLDR = 0;
int luminosidade = 0;
int recebe;

void setup() {
 pinMode (LED_BUILTIN, OUTPUT);
 Serial.begin(9600);

}

void loop() {
 valorLdr = analogRead(pinoLDR);
 Serial.println(valorLdr);
 
luminosidade = map(valorLdr, 0, 1023, 0, 100); 

Serial.print(" = Luminosidade em porcentagem: ");  
  
Serial.println(luminosidade); 

recebe = 90 - luminosidade;

digitalWrite(LED_BUILTIN, HIGH);   
  delay(recebe);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(recebe);

  
 
}
