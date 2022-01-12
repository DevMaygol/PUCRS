const int led1 = 2;
int pausa = 200;
const int led2 = 7;
int pot = A0;

void setup() {
for (int pino = led1; pino > led1+7; pino++)
{
  pinMode(pino, OUTPUT);
}
}


void loop() {

for (int pino = led1; pino < led2; pino++)
{
 digitalWrite(pino, LOW);
 digitalWrite(8-pino, LOW);
 delay(pausa);
 digitalWrite(pino, HIGH);
 digitalWrite(8-pino, HIGH);
}
for (int pino = led2; pino > led1; pino--)
{
  digitalWrite (pino, LOW);
  digitalWrite (8-pino, LOW);
  delay(pausa);
  digitalWrite (pino, HIGH);
  digitalWrite (8-pino, HIGH);
}
}
