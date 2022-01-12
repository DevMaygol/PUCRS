 struct Nomes{
  String nome1;
  String nome2;
};
 void setup() {
  Serial.begin(9600);
  Serial.println("Insira o nome do jogador 1 e depois do jogador 2:");
}

void loop() {
 
  if (Serial.available())
  {
    struct Nomes Jogadores;
    Jogadores.nome1 = Serial.read();
    Jogadores.nome2 = Serial.read();
    
    Serial.println(Jogadores.nome1);
//    int nome1 = Serial.read();
//    
//    int nome2 = Serial.read();
   
//    Serial.write(nome1);   
    }

}
