#include <Keypad.h>

int espera=0;
int t;
int linha=2, coluna=3;
int matriz_a[3][3];
int matriz_b[3][3];
byte pinosLinhas[]  = {5,6,7,8};
byte pinosColunas[] = {9,10,11};
char teclas[4][3] = {{'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'},
                     {'*','0','9'},
                     };
int leds[3][3] =    {{22,23,24},
                     {25,26,27},
                     {28,29,30},
                     };                 

int i,j,i_variavel,j_variavel;                     
Keypad teclado1 = Keypad( makeKeymap(teclas), pinosLinhas, pinosColunas, 3, 3); 
int status1 = 0;  // onde o jogador 1 está

int status2 = 0;  // onde o jogador 2 está

int atual   = 0;

void setup() {

  Serial.begin(9600);

  Serial.println("Teclado 4x4 com Biblioteca Keypad");

  Serial.println("Aguardando acionamento das teclas...");

  Serial.println();

}
void loop() {

  //Verifica se alguma tecla foi pressionada

  char tecla_pressionada = teclado1.getKey();
  
  // aqui vai ser lida a coluna e a linha do led ---> digitalRead()
  
  if (tecla_pressionada)
  {
    Serial.print("Tecla: ");
    Serial.println(tecla_pressionada);
  }
//---------------------- Jogador vai escolher onde quer ir ----------------------------
int espera=0;
 
while(espera==0){
  char tecla_pressionada = teclado1.getKey();
    if (tecla_pressionada)
      {
        Serial.println("Escolha o lugar que voce vai mexer");
        Serial.println(tecla_pressionada);
        espera=1;
      } 
}
int i_nova, j_nova;
if (matriz_a[i_nova][j_nova] = 1){
  Serial.println("Lugar ocupado!"); 
}
if (matriz_a[i_nova][j_nova] = 0){
  for(int i=0;i<4;i++){
    for(int j =0;j<3;j++){
      if(tecla_pressionada==teclas[i][j]){
        int i_nova = i;
        int j_nova = j;
        matriz_a[i_nova][j_nova] = 0;
      }
    }
  }
  for(int i=0;i<4;i++){
    for(int j =0;j<3;j++){
      if(tecla_pressionada==teclas[i][j]){
        int i_nova = i;
        int j_nova = j;
        matriz_a[i_nova][j_nova] = 1;
      }
    }
  }  
}

//-------------------- Fim da escolha de onde quer ir ---------------------------------

//-------------------- Inicio da parte que o jogador diz onde ele está ----------------
espera = 0;

while(espera==0){
  char tecla_pressionada = teclado1.getKey();
  
    if (tecla_pressionada)
      {
        Serial.println("Qual lugar que você está?");
        Serial.println(tecla_pressionada);
        espera=1;
      } 
}
if (matriz_a[i_nova][j_nova] = 0){
  for(int i=0;i<4;i++){
    for(int j =0;j<3;j++){
      if(tecla_pressionada==teclas[i][j]){
        int i_nova = i;
        int j_nova = j;
        matriz_a[i_nova][j_nova] = 0;
      }
    }
  }
  for(int i=0;i<4;i++){
    for(int j =0;j<3;j++){
      if(tecla_pressionada==teclas[i][j]){
        int i_nova = i;
        int j_nova = j;
        matriz_a[i_nova][j_nova] = 0;
      }
    }
  }  
}
// ------------------- fim da parte que ele escolhe onde está ----------------------------

// ------------ teste ganha linha --------------
if (matriz_a[i][j] = 1){
  for(int i=0;i<4;i++){
      if (i == 1){
        Serial.println("Venceu a partida!!");
      }
    }
Serial.println("Saiu");
}
}
