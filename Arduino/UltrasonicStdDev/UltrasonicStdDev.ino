#include <Ultrasonic.h>

#define TRIGGER_PIN    12
#define ECHO_PIN       13

#define NUMBER_BUFFERS 3
#define BUFFER_SIZE    3

#define BUFFER_01      0
#define BUFFER_02      1
#define BUFFER_03      2

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
bool disableSD = false;

#define CYCLES 50
size_t count = 0;
int pinBuzzer = 11;
int PWMvalue = 25;

void setup()
  {
    
  Serial.begin(9600);
  Serial.println("Starting Ultasonic Test using standard deviation ...");

  if(!ultrasonic.sampleCreate(NUMBER_BUFFERS, BUFFER_SIZE, BUFFER_SIZE,
      BUFFER_SIZE))
    {
    disableSD = true;
    Serial.println("Could not allocate memory.");
    }

    pinMode (pinBuzzer, OUTPUT);
    
  }

void loop()
  {
  float cmMsec, inMsec;
  float msStdDev, cmStdDev, inStdDev;
  long microsec = ultrasonic.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);

  if(count < CYCLES)
    {
    if(disableSD)
      {
      Serial.print("CM: ");
      Serial.print(cmMsec);
      Serial.print(", IN: ");
      Serial.println(inMsec);
      }
    else
      {
      msStdDev = ultrasonic.unbiasedStdDev((float) microsec, BUFFER_01);
      cmStdDev = ultrasonic.unbiasedStdDev(cmMsec, BUFFER_02);
      inStdDev = ultrasonic.unbiasedStdDev(inMsec, BUFFER_03);
      Serial.print(count + 1);
      Serial.print(") MS: ");
      Serial.print(microsec);
      Serial.print(", SD: ");
      Serial.print(msStdDev);
      Serial.print(", CM: ");
      Serial.print(cmMsec);
      Serial.print(", SD: ");
      Serial.print(cmStdDev, 2);
      Serial.print(", IN: ");
      Serial.print(inMsec);
      Serial.print(", SD: ");
      Serial.println(inStdDev, 2);
      }
      digitalWrite (pinBuzzer, LOW);

    if (cmMsec < 10){
     digitalWrite (pinBuzzer, LOW);

    analogWrite (pinBuzzer, PWMvalue);
    delay (500);
    analogWrite (pinBuzzer,0);
    delay (1000);
      }

    count++;
    }

  delay(500);
  }
