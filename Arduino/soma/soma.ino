void setup() {
Serial.begin(9600);

}
int number = 0;

void loop() {
  Serial.println ("The number is ");
  Serial.println (number);

  delay (500);
  number = number - 1;
}
