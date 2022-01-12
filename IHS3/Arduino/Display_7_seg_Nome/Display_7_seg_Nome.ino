  byte A [7]={B1101010};
  byte B [7]={B0100001};
  byte C [7]={B1100011};
  byte D [7]={B0110000};
  byte E [7]={B1110001};
  
  int numero;
  
  int portas[7]={30,31,32,33,34,35,36};
                                                      
void setup() {
  
  for(int n=0; n<=7; n++)
  {
    pinMode(portas[n], OUTPUT);
  }
 
}

void loop() {
  
  for(numero=0; numero<=7;numero++) {
    delay(700);
    
    for (int D = 0; D <= 8; D++) {
     digitalWrite(portas[D], HIGH);
     
  }
    }
}
