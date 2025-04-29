#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 26, 2);
int SDA_pin = D1;
int SCL_pin = D2;

void setup() {
  Wire.begin(SDA_pin,SCL_pin);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Sistem Tertanam");
  lcd.setCursor(0,1);
  lcd.print("Informatika");
}

void loop() {
  lcd.scrollDisplayLeft();
  delay(300);
}