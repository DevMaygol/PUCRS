#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    
    delay(100);
    
    lcd.clear();
    
    while (Serial.available() > 0) {
      
      lcd.write(Serial.read());
    }
  }
}
