int pot_val;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);  
}

void loop() {
  pot_val = analogRead(0);
  Serial.println (pot_val);
  // put your main code here, to run repeatedly:

}
