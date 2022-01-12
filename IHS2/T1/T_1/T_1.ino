const byte listaDisplay[12] = {
  B0000001,
  B1001111,
  B0010010,
  B0000110,
  B1001100,
  B0100100,
  B0100000,
  B0001111,
  B0000000,
  B0000100,
  B1000010,
  B1101000,
};

int pinos[7] = {8, 7, 6, 5, 4, 3, 2};

String nome1, nome2;

int dado1, dado2, dado3, dado4, dado5, dado6;

int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 1, h = 1; //Variáveis para fazer a comparação dos resultados finais de cada condição

int i, j, k, p1, p2, p3, t;
int somadorb = 0, somadorj = 0;

void setup() {

  Serial.begin(9600);
  Serial.println("Bem vindo ao jogo Cee-Io");
  for (int t = 0; t < 7; t++) {
    pinMode(pinos[t], OUTPUT);
  }

  randomSeed(analogRead(0));

}


void loop() {

  Serial.println("\nAntes de começar, digite o nome de quem vai começar como banco:");
  while (Serial.available() == 0) {
  }
  nome1 = Serial.readString();
  Serial.print("O banco eh: ");
  Serial.println(nome1);
  Serial.println("Agora digite o nome do jogador: ");



  while (Serial.available() == 0) {
  }
  nome2 = Serial.readString();
  Serial.print("O jogador eh: ");
  Serial.println(nome2);
  Serial.println("Para sortear os dados do banco, aperte qualquer tecla");



  while (Serial.available() == 0) {
  }
  Serial.println("O primeiro dado: ");
  dado1 = random(1, 6);
  i = dado1;
  ligarDisplay(dado1);
  Serial.println(dado1);
  delay(500);
  Serial.println("O segundo dado:");
  dado2 = random(1, 6);
  j = dado2;
  ligarDisplay(dado2);
  Serial.println(dado2);
  delay(500);
  Serial.println("O terceiro dado:");
  dado3 = random(1, 6);
  k = dado3;
  ligarDisplay(dado3);
  Serial.println(dado3);
  delay(500);

  Serial.println("Para sortear os dados do jogador, aperte qualquer tecla");
  Serial.end();
  Serial.begin(9600);

  while (Serial.available() == 0) {

  }

  Serial.println("O primeiro dado: ");
  dado4 = random(1, 6);
  Serial.println(dado4);
  ligarDisplay(dado4);
  delay(500);
  Serial.println("O segundo dado:");
  dado5 = random(1, 6);
  Serial.println(dado5);
  ligarDisplay(dado5);
  delay(500);
  Serial.println("O terceiro dado:");
  dado6 = random(1, 6);
  Serial.println(dado6);
  ligarDisplay(dado6);
  delay(500);

  Serial.end();
  Serial.begin(9600);

  while (Serial.available() == 0) {
  }

  Serial.println("Os resultados:\n");
  //Serial.println(dado1);
  //Serial.println(dado2);
  //Serial.println(dado3);


  // ----------------------------- Para os dados 1, 2 e 3, a seguir --------------------------------
  if (dado1 >= 4 && dado1 <= 6 || dado2 >= 4 && dado2 <= 6 || dado3 >= 4 && dado3 <= 6) { //3 dados iguais
    if (dado1 == dado2 && dado2 == dado3) {
      Serial.println("O Banco venceu a rodada!\n");
      e = 1;
      delay(1000);
    }

    //duplas de 6
    else if (dado1 == 6 && dado2 == 6 && dado1 != 1 && dado2 != 1) {
      Serial.println("O Banco venceu a rodada!");
      a = 1;
      delay(1000);
    }
    else if (dado1 == 6 && dado3 == 6 && dado1 != 1 && dado3 != 1) {
      Serial.println("O Banco venceu a rodada!");
      a = 1;
      delay(1000);
    }
    else if (dado2 == 6 && dado3 == 6 && dado2 != 1 && dado3 != 1) {
      Serial.println("O Banco venceu a rodada!");
      a = 1;
      delay(1000);
    }
    //fim da dupla de 6
  }
  if (dado1 >= 1 && dado1 <= 3 || dado2 >= 1 && dado2 <= 3 || dado3 >= 1 && dado3 <= 3) { //3 dados iguais

    if (dado1 == dado2 && dado2 == dado3) {
      Serial.println("O Banco Perdeu a rodada!\n");
      g = 1;
      delay(1000);
    }
    //duplas de 1
    else if (dado1 == 1 && dado2 == 1 && dado1 != 6 && dado2 != 6) {
      Serial.println("O Banco Perdeu a Rodada!");
      b = 1;
      delay(1000);
    }
    else if (dado1 == 1 && dado3 == 1 && dado1 != 6 && dado3 != 6) {
      Serial.println("O Banco Perdeu a Rodada!");
      b = 1;
      delay(1000);
    }
    else if (dado1 == 1 && dado3 == 1 && dado2 != 6 && dado3 != 6) {
      Serial.println("O Banco Perdeu a Rodada!");
      b = 1;
      delay(1000);
    }
    //fim da duplas de 1
  }
  //Pontuacao caso houver um par de 2 a 5
  if (dado1 >= 2 && dado1 <= 5 || dado2 >= 2 && dado2 <= 5 || dado3 >= 2 && dado3 <= 5) {
    if (dado1 == dado2 && dado1 != dado3 && dado1 != 1 && dado1 != 6) {
      p1 = dado3;
      Serial.println("Pontuacao do banco:");
      Serial.println(dado3);
      somadorb = somadorb + dado3;
      delay(1000);
    }
    else if (dado1 == dado3 && dado1 != dado2 && dado1 != 1 && dado1 != 6) {
      p2 = dado2;
      Serial.println("Pontuacao do banco:");
      Serial.print(dado2);
      somadorb = somadorb + dado2;
      delay(1000);
    }
    else if (dado2 == dado3 && dado1 != dado2 && dado2 != 1 && dado2 != 6) {
      p3 = dado1;
      Serial.print("Pontuacao do banco:");
      Serial.println(dado1);
      somadorb = somadorb + dado1;
      delay(1000);
    }


  }
  //Se todos os dados forem diferentes
  if (dado1 != dado2 && dado1 != dado3 && dado2 != dado3) {
    Serial.println("Jogue novamente!");
  }
  Serial.end();
  Serial.begin(9600);

  // ----------------------------- Para os dados 4,5 e 6, a seguir --------------------------------

  if (dado4 >= 4 && dado4 <= 6 || dado5 >= 4 && dado5 <= 6 || dado6 >= 4 && dado6 <= 6) { //3 dados iguais
    if (dado4 == dado5 && dado5 == dado6) {
      Serial.println("O Jogador venceu a rodada!\n");
      f = 1;
      delay(1000);
    }

    //duplas de 6
    else if (dado4 == 6 && dado5 == 6 && dado4 != 1 && dado5 != 1) {
      Serial.println("O Jogador Venceu a rodada!");
      c = 1;
      delay(1000);
    }
    else if (dado4 == 6 && dado6 == 6 && dado4 != 1 && dado6 != 1) {
      Serial.println("O Jogador Venceu a rodada!");
      c = 1;
      delay(1000);
    }
    else if (dado5 == 6 && dado6 == 6 && dado5 != 1 && dado6 != 1) {
      Serial.println("O Jogador Venceu a rodada!");
      c = 1;
      delay(1000);
    }
    //fim da dupla de 6
  }
  if (dado4 >= 1 && dado4 <= 3 || dado5 >= 1 && dado5 <= 3 || dado6 >= 1 && dado6 <= 3) { //3 dados iguais

    if (dado4 == dado5 && dado5 == dado6) {
      Serial.println("O Jogador Perdeu a rodada!\n");
      h = 1;
      delay(1000);
    }
    //duplas de 1
    else if (dado4 == 1 && dado5 == 1 && dado4 != 6 && dado5 != 6) {
      Serial.println("O Jogador Perdeu a Rodada!");
      d = 1;
      delay(1000);
    }
    else if (dado4 == 1 && dado6 == 1 && dado4 != 6 && dado6 != 6) {
      Serial.println("O Jogador Perdeu a Rodada!");
      d = 1;
      delay(1000);
    }
    else if (dado4 == 1 && dado6 == 1 && dado5 != 6 && dado6 != 6) {
      d = 1;
      Serial.println("O Jogador Perdeu a Rodada!");
      delay(1000);
    }
    //fim da duplas de 1
  }




  //Pontuacao caso houver um par de 2 a 5
  if (dado4 >= 2 && dado4 <= 5 || dado5 >= 2 && dado5 <= 5 || dado6 >= 2 && dado6 <= 5) {
    if (dado4 == dado5 && dado4 != dado6 && dado4 != 1 && dado4 != 6) {
      p1 = dado6;
      Serial.println("\nPontuacao do Jogador:");
      Serial.println(dado6);
      somadorj = somadorj + dado6;
      delay(1000);
    }
    else if (dado4 == dado6 && dado4 != dado5 && dado4 != 1 && dado4 != 6) {
      p2 = dado5;
      Serial.println("Pontuacao do Jogador:");
      Serial.print(dado5);
      somadorj = somadorj + dado5;
      delay(1000);
    }
    else if (dado5 == dado6 && dado4 != dado5 && dado5 != 1 && dado5 != 6) {
      p3 = dado4;
      Serial.print("Pontuacao do Jogador:");
      Serial.println(dado4);
      somadorj = somadorj + dado4;
      delay(1000);
    }
  }



  //Se todos os dados forem diferentes
  if (dado4 != dado5 && dado4 != dado6 && dado5 != dado6) {
    Serial.println("Jogue novamente!");
  }
  
  delay(800);
  Serial.println("\nA pontuação do banco ate agora eh: ");
  Serial.println(somadorb);
  delay(800);
  Serial.println("\nA pontuação do jogador ate agora eh: ");
  Serial.println(somadorj);
  Serial.end();
  Serial.begin(9600);


}



void ligarDisplay(int num) {
  boolean liga;
  for (int seg = 1; seg < 7; seg++)
  {
    liga = bitRead(listaDisplay[num], seg);
    digitalWrite(pinos[seg], liga);
  }
}
