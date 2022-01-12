String my_str = "Essa eh a string.";

void setup() {
 
 Serial.begin(9600);
 
 Serial.println(my_str);
 //Normal
 my_str.toUpperCase();
 Serial.println(my_str);
 
 //Tudo maiusculo
 my_str = "Essa eh a nova string.";
 Serial.println(my_str);
 
 //Substitui uma palavra, no caso "string", com Arduino Sketch
 my_str.replace("string", "Arduino sketch");
 Serial.println(my_str);
 
 //tamanho da string
 Serial.print("String length is: ");
 Serial.println(my_str.length());

 }

void loop() {
 
}
