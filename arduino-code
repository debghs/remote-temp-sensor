// Arduino Uno Code for LM35 Sensor
const int lm35Pin = A0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int sensorValue = analogRead(lm35Pin);
  float temperature = (sensorValue * 5.0 / 1024) * 100.0;
  if()
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Send temperature as a float via Serial
  Serial.write((uint8_t*)&temperature, sizeof(temperature));

  delay(1000); // Adjust delay as needed
}
