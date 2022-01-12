const int led1 = 8;
const int led2 = 9;
const int led3 = 10;

int x = 0;
int val = 0;

void setup() {
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
}




void loop() {

  val = bitRead(x,0);

  digitalWrite (led1,val);

  val = bitRead(x,1);

  digitalWrite (led2,val);

  val = bitRead(x,2);

  digitalWrite (led3,val);

  
  delay(1000);

  

  x++;
  
  
  
}
