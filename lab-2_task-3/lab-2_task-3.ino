#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

#define BMP_CS1 5
#define BMP_CS2 17

Adafruit_BMP280 bmp1(BMP_CS1); 
Adafruit_BMP280 bmp2(BMP_CS2); 

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(100);

  if (!bmp1.begin()) {
    Serial.println("Помилка: Датчик 1 (SPI) не знайдено!");
  }

  if (!bmp2.begin()) {
    Serial.println("Помилка: Датчик 2 (SPI) не знайдено!");
  }
}

void loop() {
  Serial.print("SPI Датчик 1: T = ");
  Serial.print(bmp1.readTemperature());
  Serial.print(" *C, P = ");
  Serial.print(bmp1.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.print("SPI Датчик 2: T = ");
  Serial.print(bmp2.readTemperature());
  Serial.print(" *C, P = ");
  Serial.print(bmp2.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.println("----------------------------------------");
  delay(2000);
}