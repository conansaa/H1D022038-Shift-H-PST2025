#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int Trig_PIN = D0;
int ECHO_PIN = D1;

LiquidCrystal_I2C lcd(0x27, 16, 2); 

long bacaJarak() {
  digitalWrite(Trig_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2; // cm
  return distance;
};

void setup() {
  pinMode(Trig_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("SISTEM SIAP...");
  delay(1500);
  lcd.clear();
}

void loop() {
  long distance = bacaJarak();

  lcd.setCursor(0, 0);
  lcd.print("Jarak: ");
  lcd.print(distance);
  lcd.print(" cm    ");

  lcd.setCursor(0, 1);
  if (distance < 100) {
    lcd.print("AREA BERBAHAYA");
  } else {
    lcd.print("STATUS: AMAN  ");
  }

  delay(250);
}