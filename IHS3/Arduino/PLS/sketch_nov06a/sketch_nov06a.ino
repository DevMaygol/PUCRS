int e = 0;
char data;
void setup() {

  pinMode(13,OUTPUT);
  Serial.begin(9600);
  
  digitalWrite(13,LOW);
}

void loop() {

  while(!Serial.available());
  data = Serial.read();
  if(data=='L')
  {
   digitalWrite(13,HIGH);
   e = 1; 
  }
  if(data=='D')
  {
    digitalWrite(13,LOW);
    e = 0;
  }
  if(data=='I')
  {
    if(e)
    {
     digitalWrite(13,LOW);
     e = 0;
    }
    else
    {
      digitalWrite(13,HIGH);
      e = 1;  
    }
  }
}
