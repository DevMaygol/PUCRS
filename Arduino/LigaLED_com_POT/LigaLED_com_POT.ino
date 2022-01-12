
int  pot = 0;

int pot_val;
int led1; int led2; int led3; 
int led4; int led5; int led6;

void setup() {
Serial.begin(9600); 
digitalRead (led1, 52);


 
  }
  
void loop() {
  pot_val = analogRead(0);

  Serial.println (pot_val);
  
  switch (pot_val)
 {
  case 50:
  digitalWrite (led1, HIGH);
  break;

  case 100:
  digitalWrite (led2, HIGH);
  break;

  case 150:
  digitalWrite (led3, HIGH);
  break;

  case 200:
  digitalWrite (led4, HIGH);
  break;

  case 250:
  digitalWrite (led5, HIGH);
  break;

  case 300:
  digitalWrite (led6, HIGH);
  break;
  

 }
}
