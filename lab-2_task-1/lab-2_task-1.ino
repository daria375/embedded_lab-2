
const int photoPin = 34;
const int ledPin = 25;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12); 
}

void loop() {
  int lightLevel = analogRead(photoPin);

  int dacValue = map(lightLevel, 0, 4095, 0, 255);
 
  dacWrite(ledPin, dacValue);
  
  Serial.print("ADC Value: ");
  Serial.print(lightLevel);
  Serial.print(" | DAC Output: ");
  Serial.println(dacValue);
  
  delay(500);
}