#include <Wire.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp1;
Adafruit_BMP280 bmp2;

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(100);

  if (!bmp1.begin(0x76)) {
    Serial.println("Помилка: Датчик 1 (0x76) не знайдено!");
  }

  if (!bmp2.begin(0x77)) {
    Serial.println("Помилка: Датчик 2 (0x77) не знайдено!");
  }
}

void loop() {
  Serial.print("Датчик 1: ");
  Serial.print(bmp1.readTemperature());
  Serial.print(" *C | ");
  Serial.print(bmp1.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.print("Датчик 2: ");
  Serial.print(bmp2.readTemperature());
  Serial.print(" *C | ");
  Serial.print(bmp2.readPressure() / 100.0F);
  Serial.println(" hPa");

  delay(2000);
}