#include <Arduino.h>
#include <Wire.h>

int SDA_pin = D1;
int SCL_pin = D2;

void setup() {
  Wire.begin(SDA_pin,SCL_pin);
  Serial.begin(9600);
}

void loop() {
  byte error,address;
  int nDevices;
  Serial.print("Scanning...");
  nDevices = 0;
  for(address = 0; address<127;address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if(error==0) {
      Serial.print("I2C terbaca pada alamat 0x");
      if(address < 16) {
        Serial.print("0");
      }
      Serial.println(address,HEX);
      Serial.println("!");
      nDevices++;
    }else if(error==4){
      Serial.print("Ada error yang tidak diketahui pada alamat 0x");
      if(address<16){
        Serial.print("0");
      }
      Serial.print(address, HEX);
    }
  }
  if(nDevices==0) {
    Serial.print("Tidak ada satupun alamat I2C yang ditemukan \n");
  }else{
    Serial.print("Selesai");
  }
  delay(5000);
}