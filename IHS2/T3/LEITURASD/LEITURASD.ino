/*
  SD card read/write
 
 This example shows how to read and write data to and from an SD card file   
 The circuit:
 * SD card attached to SPI bus as follows:
 ** UNO:  MOSI - pin 11, MISO - pin 12, CLK - pin 13, CS - pin 4 (CS pin can be changed)
  and pin #10 (SS) must be an output
 ** Mega:  MOSI - pin 51, MISO - pin 50, CLK - pin 52, CS - pin 4 (CS pin can be changed)
  and pin #52 (SS) must be an output
 ** Leonardo: Connect to hardware SPI via the ICSP header

 
 created   Nov 2010  by David A. Mellis
 modified 9 Apr 2012  by Tom Igoe
 
 This example code is in the public domain.
   
 */
 
#include <SPI.h>
#include <SD.h>
#include "RTClib.h"
RTC_DS1307 RTC;

File myFile;
char linha1 [3];
char linha2 [3];
char linha3 [3];
int contador=0;
// change this to match your SD shield or module;
//     Arduino Ethernet shield: pin 4
//     Adafruit SD shields and modules: pin 10
//     Sparkfun SD shield: pin 8
const int chipSelect = 10;

void setup()
{
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
  
  // re-open the file for reading:
  myFile = SD.open("tr3.txt");
  if (myFile) {
    Serial.println("tr3.txt:");
    
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening tr3.txt");
  }
  RTC.adjust(DateTime(__DATE__, __TIME__));
}

void loop()
{
  Serial.println("As matrizes salvas são:");
  Serial.println("Matriz A");
  myFile = SD.open("tr3.txt"); //Abertura do arquivo
  
    if (myFile) {
    // read from the file until there's nothing else in it:
    for(contador=0;contador<23;contador++) {
      Serial.write(myFile.read());
      
      delay(300);
    }
    Serial.write("\n");
    Serial.println("Matriz B");
    for(contador=0;contador<25;contador++) {
      Serial.write(myFile.read());
      delay(300);
  }
}

//---------------Escrevendo no SD----------------\\

 if (myFile) {
  DateTime now = RTC.now();
 Serial.print(now.year(), DEC);
 Serial.print('/');
 Serial.print(now.month(), DEC);
 Serial.print('/');
 Serial.print(now.day(), DEC);
 Serial.print(' ');
 Serial.print(now.hour(), DEC);
 Serial.print(':');
 Serial.print(now.minute(), DEC);
 Serial.print(':');
 Serial.print(now.second(), DEC);
 Serial.println();
 Serial.println();
    Serial.print("mostrou");
 }
 // close the file:
    myFile.close();
 


}
