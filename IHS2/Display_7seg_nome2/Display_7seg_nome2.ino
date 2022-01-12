const byte listaDisplay[3]={
  B0000001,  //G 
  B1101010,
  B0100001  
  };

const int pinos[7]={30,31,32,33,34,35,36};
int numero;

void setup() {
  for (int i=0;i<7;i++)
  {
   pinMode(pinos[i], OUTPUT); 
  }
}

void loop() {
  
int  numero = 4;
ligarDisplay(numero); 
delay(1000);
exit(0);

    }
    void ligarDisplay (int num){
     boolean liga;
   
    for (int seg=0;seg<7;seg++)
    {
      liga = bitRead(listaDisplay[num], seg);
      digitalWrite(pinos[seg], liga);
      
      }
    }
