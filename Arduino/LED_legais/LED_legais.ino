const int led1 = 2;
const int led7 = 7;
int pot = A0; 
int val = 100;


void setup() 
{

for(int pino = led1; pino<= led7; pino++) 
{
pinMode(pino, OUTPUT);
pinMode(pot, INPUT);
Serial.begin(9600);
}
}

void loop() 
{
val = analogRead(pot);
val = map(val,0,1023, 0, 255);
Serial.println(val);

for( int pino = led1; pino < led7;pino++) 
{
digitalWrite(pino, HIGH);
digitalWrite(9-pino, HIGH);
delay(val);
digitalWrite(pino, LOW);
digitalWrite(9-pino, LOW);
}

/*for( int pino = led7; pino > led1;pino--)
{
digitalWrite(pino, HIGH);
digitalWrite(8-pino, HIGH);
delay(val);
digitalWrite(pino, LOW);
digitalWrite(8-pino, LOW);
}
*/
}


