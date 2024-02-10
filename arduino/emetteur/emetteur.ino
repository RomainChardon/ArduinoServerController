#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
String value;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(1);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);
}

void loop() {
  // Mettre en pause si pas de data
  while (!Serial.available());
  lcd.clear();
  delay(100);

  value = Serial.readString();
  
  // Affichage sur le LCD
  lcd.print(value);

  // Envoi vers prumpt Python
  Serial.print(value);
}
