#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char *ssid = "wifi_ssid";
const char *password = "wifi_password";
const char *mqttBroker = "xxx.xxx.xxx.xxx";
const int mqttPort = 1883;
const char *mqttClientId = "nodemcu_client";
const char *mqttTopic = "lm35/temperature";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  delay(10);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  client.setServer(mqttBroker, mqttPort);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }

  // Read data from Arduino Uno via Serial
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');  // Read until newline character
    
    // Parse the received data
    String prefix = data.substring(0, data.indexOf(':'));
    String tempValue = data.substring(data.indexOf(':') + 1);

    // Check if the received data is valid
    if (prefix == "Temperature") {
      // Convert the temperature value to a float
      float temperature = tempValue.toFloat();

      // Do something with the temperature value (you can print or use it as needed)
      Serial.print("Received Temperature: ");
      Serial.println(temperature);
      sendDataToRPi(temperature);
    }
  }

  client.loop();
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");
    if (client.connect(mqttClientId)) {
      Serial.println("Connected to MQTT broker");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" Retrying in 5 seconds...");
      delay(5000);
    }
  }
}

void sendDataToRPi(float data) {
  // Publish temperature data to the MQTT topic
  char msg_out[8];
  dtostrf(data,2,2,msg_out);
  client.publish(mqttTopic, msg_out);
}
