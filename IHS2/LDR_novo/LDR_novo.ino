int LDR = A0;
int valorLDR;
int luminosidade;

void setup() {
  pinMode (LDR, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  valorLDR = analogRead(LDR);
  luminosidade = map(valorLDR, 0, 1023, 0, 100);
  Serial.println(luminosidade);
  
  if (luminosidade <= 50){
    digitalWrite (LED_BUILTIN, HIGH);
    delay (luminosidade* 5);
    digitalWrite (LED_BUILTIN, LOW);
    delay (luminosidade*5);
    }
    else {
      }

  
}
