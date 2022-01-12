String numero;
int n;

void setup() {
  Serial.begin(9600);
  Serial.println("Digite um numero:");
  
}

void loop() {
  //n = numero.toInt();
  
  if(Serial.available() > 0){
    
    Serial.print(numero);
    numero = Serial.readString();
    
  for(numero >= '0';numero <= '9'; numero++){
    if{
    Serial.println("Numero recebido: ");
    Serial.println(numero);
    }
    
    else {
      Serial.println("Não é um numero!");
    }
      }  
  }
}
