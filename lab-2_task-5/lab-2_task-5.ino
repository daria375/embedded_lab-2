#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

Adafruit_BMP280 bmp; 

#define LDR_PIN 34

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(100);

  Serial.println("--- ПІДСУМКОВА РОБОТА ---");

  sensors.begin();

  if (!bmp.begin(0x76)) {
    Serial.println("Помилка BMP280! Перевірте контакти.");
  }

  Serial.println("Система готова.");
}

void loop() {
  sensors.requestTemperatures();
  float tempDS = sensors.getTempCByIndex(0);

  float tempBMP = bmp.readTemperature();
  float pressure = bmp.readPressure() / 100.0F;

  int ldrValue = analogRead(LDR_PIN);

  Serial.print("DS18B20 Temp: "); Serial.print(tempDS); Serial.println(" *C");
  Serial.print("BMP280 Temp: "); Serial.print(tempBMP); Serial.println(" *C");
  Serial.print("Pressure: "); Serial.print(pressure); Serial.println(" hPa");
  Serial.print("Light Level: "); Serial.println(ldrValue);
  
  Serial.println("------------------------------------");
  delay(2000);
}