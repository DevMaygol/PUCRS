#include <SPI.h>
#include <SD.h>

File myFile;

// change this to match your SD shield or module;
//     Arduino Ethernet shield: pin 4
//     Adafruit SD shields and modules: pin 10
//     Sparkfun SD shield: pin 8
const int chipSelect = 10;


#include <Keypad.h>
int espera=0;
int t;
int linha=2, coluna=3;
int matriz_a[4][3];
int matriz_b[4][3];
int matriz_ateste[4][3];
int matriz_bteste[4][3];
int contador=0;
byte pinosLinhas[]  = {38,39,40,41};
byte pinosColunas[] = {42,43,44};
char teclas[4][3] = {{'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'},
                     {'*','0','#'},
                     }; 
int ledsa[3][3] =    {{22,23,24},
                      {25,26,27},
                      {28,29,30},
                      };     
int ledsb[3][3] =    {{31,32,33},
                      {34,35,36},
                      {37,38,39},
                      };
int seletor=0;
int i,j,i_variavel,j_variavel,i_nova,j_nova;
char tecla;
char lugar_selecionado;                     
Keypad teclado1 = Keypad( makeKeymap(teclas), pinosLinhas, pinosColunas, 4, 3); 
int status1 = 0;  // onde o jogador 1 está
int status2 = 0;  // onde o jogador 2 está
int atual   = 0;

void setup() {
  //----------------Inicialização da memória-----------------\\
  
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  pinMode(linha,INPUT);
  digitalWrite(linha,HIGH);
  pinMode(coluna,OUTPUT);
  digitalWrite(coluna,HIGH);
  pinMode(3,OUTPUT);
  for(i=0;i<4;i++){
    for(j=0;j<3;j++){
      pinMode(ledsa[i][j],OUTPUT);
      digitalWrite(ledsa[i][j],HIGH);     
    }
}
 for(i=0;i<4;i++){
    for(j=0;j<3;j++){
      pinMode(ledsb[i][j],OUTPUT);
      digitalWrite(ledsb[i][j],HIGH);     
    }
}
Serial.print("Initializing SD card...");
pinMode(SS, OUTPUT);
  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    return;
  }
 
  Serial.println("initialization done.");
myFile = SD.open("trab3.txt", FILE_WRITE);
 Serial.println("Bem vindo ao Picaria, vamos começar o jogo");
}



void loop() {
  if(contador<3){
  char tecla_pressionada = teclado1.getKey();
  //Verifica se alguma tecla foi pressionada
  
  
  //Mostra no serial monitor o caracter da matriz,
  //referente a tecla que foi pressionada
  if (tecla_pressionada)
  {
    Serial.print("Tecla: ");
    Serial.println(tecla_pressionada);
  } 
  

espera=0;

while(espera==0){
  char tecla_pressionada = teclado1.getKey();
  if (tecla_pressionada)
  {
//    Serial.println(tecla_pressionada);
    tecla = tecla_pressionada;
    espera=1;
  } 
}

//--------------- INSERÇÃO DAS POSIÇÕES NA MATRIZ
seletor=1;
dadosmatriz(tecla);

Serial.println("Jogador 2, sua vez!");
espera=0;
while(espera==0){
  char tecla_pressionada = teclado1.getKey();
  if (tecla_pressionada)
  {
//  Serial.println(tecla_pressionada);
    tecla = tecla_pressionada;
    espera=1;
  } 
}
seletor=2;
dadosmatriz(tecla);

//--------------- PRINT DA MATRIZ A NO MONITOR SERIAL
  for(i=0;i<4;i++){
    for(j=0;j<3;j++){
      Serial.print(matriz_a[i][j]);
      Serial.print(" ");
    }
    Serial.println();
  }
  for(i=0;i<4;i++){
    for(j=0;j<3;j++){
      Serial.print(matriz_b[i][j]);
      Serial.print(" ");
    }
    Serial.println();
  }
  contador=contador+1;
  }else{
int espera=0;

//---------------Escrevendo no SD----------------\\

 if (myFile) {
    Serial.print("Writing to trab3.txt...");
    for(i=0;i<4;i++){
    for(j=0;j<3;j++){
      myFile.print(matriz_a[i][j]);
      myFile.print(" ");
    }
    myFile.println();
  }

  
   for(i=0;i<4;i++){
    for(j=0;j<3;j++){
      myFile.print(matriz_b[i][j]);
      myFile.print(" ");
    }
    myFile.println();
  }
  // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening trab3.txt");
    delay(1000);
  }






}
}
void dadosmatriz(char dado){
  Serial.print("Seletor: ");
  Serial.println(seletor);
  if(seletor == 1){
   for(i=0;i<4;i++){
    for(j=0;j<3;j++){
      if(dado==teclas[i][j]){
        matriz_a[i][j] = 1;
        digitalWrite(ledsa[i][j],matriz_a[i][j]);      
      }
    }
  }
} else{ 
  for(i=0;i<4;i++){
    for(j=0;j<3;j++){
      if(dado==teclas[i][j]){
        matriz_b[i][j] = 1;
        digitalWrite(ledsb[i][j],matriz_b[i][j]);      
      }
    }
  }
}
}
