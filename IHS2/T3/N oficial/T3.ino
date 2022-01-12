#include <RTClib.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
File myFile;

RTC_DS1307 RTC;
// ##################################### TRABALHO 2 #################################
// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;
#include <Keypad.h>
int espera=0;
int t;
int linha=2, coluna=3;
int matriz_a[4][3];
int matriz_b[4][3];
int matriz_ateste[4][3];
int matriz_bteste[4][3];
int contador=0;
byte pinosLinhas[]  = {5,6,7,8};
byte pinosColunas[] = {9,10,11};
char teclas[4][3] = {{'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'},
                     {'*','0','#'},
                     };
int leds[3][3] =    {{22,23,24},
                     {25,26,27},
                     {28,29,30},
                     };                 
int seletor=0;
int i,j,i_variavel,j_variavel,i_nova,j_nova;
char tecla;
char lugar_selecionado;                     
Keypad teclado1 = Keypad( makeKeymap(teclas), pinosLinhas, pinosColunas, 4, 3); 
int status1 = 0;  // onde o jogador 1 está
int status2 = 0;  // onde o jogador 2 está
int atual   = 0;

const int chipSelect = 10;
int pino1 = 51;
int pino2 = 50;
int pino3 = 52;
int pino4 = 53;

//############################################ _____________ SETUP _____________ ###########################################

void setup() {
  Serial.begin(9600);
  pinMode (pino1, OUTPUT);
  pinMode (pino2, OUTPUT);
  pinMode (pino3, OUTPUT);
  pinMode (pino4, OUTPUT);
  pinMode(linha,INPUT);
  digitalWrite(linha,HIGH);
  pinMode(coluna,OUTPUT);
  digitalWrite(coluna,HIGH);
  pinMode(3,OUTPUT);

  Wire.begin();
  RTC.begin();

  if (! RTC.isrunning()) {
    Serial.println ("RTC is not running!");
  }
  RTC.adjust(DateTime (__DATE__, __TIME__));

  //#########################################______________ CARD INFO ______________#########################################

 // Open serial communications and wait for port to open:
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin 
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output 
  // or the SD library functions will not work. 
   pinMode(SS, OUTPUT);
   
  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("test.txt", FILE_WRITE);
  
  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
  // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  
  // re-open the file for reading:
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");
    
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
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
  
Serial.println("Vamos começar o jogo. Jogador 1, escolha um local no teclado para posicionar sua peça");
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
//Serial.println("Saiu");
Serial.println(tecla);

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
//---------------------- Jogador vai escolher onde quer ir ----------------------------
int espera=0;

Serial.println("Agora iremos para a segunda fase. Jogador 1, escolha o lugar que voce quer que uma peça va");

char tecla_pressionada = teclado1.getKey();

while(espera==0){
  char tecla_pressionada = teclado1.getKey();
    if (tecla_pressionada)
      {
        lugar_selecionado = tecla_pressionada;
        Serial.println(lugar_selecionado);
        espera=1;
       
   for(i=0;i<4;i++){
    for(j=0;j<3;j++){
      if(lugar_selecionado==teclas[i][j]){
        if ((matriz_ateste[i][j] = matriz_a[i][j])&& matriz_a[i][j]==1){
          Serial.println("Lugar ocupado!"); 
        }

        else{
          for(int i=0;i<4;i++){
            for(int j =0;j<3;j++){
              if(lugar_selecionado==teclas[i][j]){
                  int i_nova = i;
                  int j_nova = j;
                  matriz_a[i_nova][j_nova] = 1;
              }
            }
          }
            for(int i=0;i<4;i++){
              for(int j =0;j<3;j++){
                if(lugar_selecionado==teclas[i][j]){
                  int i_nova = i;
                  int j_nova = j;
                  matriz_a[i][j] = 1;
                }
              }
            }  
          }
        matriz_a[i][j] = 1;     
      }
    }
  }
}
}  
Serial.print("LUGAR SELECIONADO:");
Serial.println(lugar_selecionado);
Serial.println("Qual lugar que você está?");




//-------------------- Fim da escolha de onde quer ir ---------------------------------

//-------------------- Inicio da parte que o jogador diz onde ele está ----------------
espera = 0;

while(espera==0){
  char tecla_pressionada = teclado1.getKey();
    if (tecla_pressionada)
      {
        
        lugar_selecionado = tecla_pressionada;
        Serial.println(lugar_selecionado);
        espera=1;
       
   for(i=0;i<4;i++){
    for(j=0;j<3;j++){
      if(lugar_selecionado==teclas[i][j]){
        if ((matriz_ateste[i][j] = matriz_a[i][j])&& matriz_a[i][j]==1){
          Serial.println("Lugar ocupado!"); 
        }

        else{
          for(int i=0;i<4;i++){
            for(int j =0;j<3;j++){
              if(lugar_selecionado==teclas[i][j]){
                  int i_nova = i;
                  int j_nova = j;
                  matriz_a[i_nova][j_nova] = 1;
              }
            }
          }
            for(int i=0;i<4;i++){
              for(int j =0;j<3;j++){
                if(lugar_selecionado==teclas[i][j]){
                  int i_nova = i;
                  int j_nova = j;
                  matriz_a[i][j] = 1;
                }
              }
            }  
          }
        matriz_a[i][j] = 0;     
      }
    }
  }
}
}
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
// ------------------- fim da parte que ele escolhe onde está ----------------------------

}
DateTime now = RTC.now();
  Serial.print(now.day(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.year(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  Serial.println();
  delay(2000);
}
void dadosmatriz(char dado){
  Serial.print("Seletor: ");
  Serial.println(seletor);
  if(seletor == 1){
   for(i=0;i<4;i++){
    for(j=0;j<3;j++){
      if(dado==teclas[i][j]){
        matriz_a[i][j] = 1;
        digitalWrite(leds[i][j],matriz_a[i][j]);      
      }
    }
  }
} else{ 
  for(i=0;i<4;i++){
    for(j=0;j<3;j++){
      if(dado==teclas[i][j]){
        matriz_b[i][j] = 1;
        digitalWrite(leds[i][j],matriz_b[i][j]);      
      }
    }
  }
}
}
