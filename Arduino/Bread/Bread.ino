int bread;
const int pinoLed = 53;
const int pinoInput = 52;

random (5);
random (1,8);

void setup() {

  bread = random(7); 
pinMode (pinoLed, OUTPUT);
pinMode (pinoInput, INPUT);
digitalWrite (pinoInput, HIGH);
}

void loop() {
  int val = digitalRead (pinoInput);
  if (val == HIGH){
    digitalWrite (pinoLed, HIGH);
    }
    else {
      digitalWrite (pinoLed, LOW)
      }

}
