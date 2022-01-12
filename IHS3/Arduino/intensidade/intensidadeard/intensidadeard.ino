void setup() {
 
  
}
unsigned char aux = 0;
void loop() {
    analogWrite(13, aux); 
    aux ++;
    delay(10);

}
