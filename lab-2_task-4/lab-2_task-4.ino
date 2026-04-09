#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

int deviceCount = 0;

void setup() {
  Serial.begin(115200);
  sensors.begin();

  deviceCount = sensors.getDeviceCount();
  Serial.print("Знайдено датчиків: ");
  Serial.println(deviceCount);
}

void loop() {
  if (deviceCount == 0) {
    Serial.println("Датчики не знайдено. Перевірте підключення та резистор!");
    delay(5000);
    return;
  }

  sensors.requestTemperatures(); 

  for (int i = 0; i < deviceCount; i++) {
    float tempC = sensors.getTempCByIndex(i);
    Serial.print("Датчик ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(tempC);
    Serial.println(" *C");
  }

  Serial.println("----------------------------------");
  delay(3000);
}