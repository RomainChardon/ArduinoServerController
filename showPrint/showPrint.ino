#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);
String value;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(1);

   lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello, world!");
}

void loop() {
  // put your main code here, to run repeatedly:
  while (!Serial.available());
  value = Serial.readString();
  
  Serial.print(value);
}
