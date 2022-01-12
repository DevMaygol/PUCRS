  int numero;
  
  int portas[7]={30,31,32,33,34,35,36};
    
  int displayConfig[10][7]= {{0,0,0,0,0,0,1},
                             {1,0,0,1,1,1,1}, // 1
                             {0,0,1,0,0,1,0}, // 2
                             {0,0,0,0,1,1,0}, // 3
                             {1,0,0,1,1,0,0}, // 4
                             {0,1,0,0,1,0,0}, // 5
                             {0,1,0,0,0,0,0}, // 6
                             {0,0,0,1,1,1,1}, // 7
                             {0,0,0,0,0,0,0}, // 8
                             {0,0,0,0,1,0,0}, // 9
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
delay(700);
    for (int D = 0; D <= 10; D++) {
     digitalWrite(portas[D], displayConfig[numero][D]);
     
  }
   }



}
