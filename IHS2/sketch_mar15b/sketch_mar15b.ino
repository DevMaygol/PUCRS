int numero;
  
  int portas[7]={30,31,32,33,34,35,36};
    
  int displayConfig[10][7]= {
  B0000001,
  B1001111,
  B0010010,
  B0000110,
  B1001100,
  B0100100, 
  B0100000,
  B0001111,
  B0000000,
  B0000100
  };
                             
void setup() {
  
  for(int n=0; n<=7; n++)
  {
    pinMode(portas[n], OUTPUT);
  }
 
}

void loop() {

  boolean liga;
  
  for(numero=0; numero<=9;numero++) {
delay(1000);
    for (int D = 0; D <= 10; D++) {
     digitalWrite(portas[D], displayConfig[numero][D]);
     
  }
   }
}
