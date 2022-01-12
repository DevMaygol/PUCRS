void ligarDisplay (int num){
  
boolean liga; //vai ser somente 1 ou 0, poderia colocar int, mas isso ocupa menos
int seg; 

  for (seg = 0; seg<7; seg++)
  {
    liga = bitRead (num, seg);
    digitalWrite (30 + seg, liga);
    }
  }

void setup() {
  int i;
for (i = 0; i < 7;i++)
  {
  pinMode (30 + i, OUTPUT);  
  }
}

void loop() {
  int t = 1000;
  
//Numeros

ligarDisplay (B0111111); //0
delay (t);
ligarDisplay (B0000110); //1
delay (t);
ligarDisplay (B1011011); //2
delay (t);
ligarDisplay (B1001111); //3
delay (t);
ligarDisplay (B1100110); //4
delay (t);
ligarDisplay (B1101101); //5
delay (t);
ligarDisplay (B1111101); //6
delay (t);
ligarDisplay (B0000111); //7
delay (t);
ligarDisplay (B1111111); //8
delay (t);
ligarDisplay (B1101111); //9
delay (t);

 //Letras
 
ligarDisplay (B1010101); //M
delay (t);
ligarDisplay (B0101010); //V
delay (t);
ligarDisplay (B1111100); //B
delay (t);


}
