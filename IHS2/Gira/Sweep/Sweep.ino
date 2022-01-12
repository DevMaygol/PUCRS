#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  Serial.println("Digite um valor para o motor girar (de 0 a 180):");
  
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  
}

void loop() {
  String gira;
  if (Serial.available()){
    Serial.print("I received: ");

    gira = Serial.readString();
    Serial.println(gira);
        }
  for (pos = 0; pos <= gira.toInt(); pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = gira.toInt(); pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
