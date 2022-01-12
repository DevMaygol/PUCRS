float floating;
int integer;

void setup() {
floating = 1.0 / 2.0;
Serial.begin (9600);
Serial.println("Floating");
Serial.println(floating);

integer = 1/3;
Serial.println("Integer");
Serial.println(integer);

floating = (1 / 2) + (1 / 2);
Serial.println("Floating");
Serial.println(floating);

floating = 3.0/2.0;
Serial.println("Floating");
Serial.println(floating);

integer = floating;
Serial.println("Integer");
Serial.println(integer);
}

void loop() {
  

}
