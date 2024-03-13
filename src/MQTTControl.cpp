#include "MQTTControl.h"

// MQTT settings
const char* mqtt_server = "192.168.18.17";
const int mqtt_port = 1883;
const char* mqtt_username = "sayoti";
const char* mqtt_password = "solusiiot123!!!";
const char* mqtt_stepper_topic = "esp1/stepper/control";
const char* mqtt_stepper_topic2 = "esp1/stepper/control2";  // MQTT topic to control the stepper motor
const char* mqtt_servo_topic = "esp1/servo/control"; // MQTT topic to control the servo motor

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

void setupMQTT() {
  mqttClient.setServer(mqtt_server, mqtt_port);
  mqttClient.setCallback(mqttCallback);

  while (!mqttClient.connected()) {
    Serial.println("Connecting to MQTT...");
    if (mqttClient.connect("ESP8266Client", mqtt_username, mqtt_password)) {
      Serial.println("Connected to MQTT");
      mqttClient.subscribe(mqtt_stepper_topic);
      mqttClient.subscribe(mqtt_servo_topic);
    } else {
      Serial.print("MQTT connection failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" Retrying in 5 seconds...");
      delay(5000);
    }
  }
}

void mqttCallback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.println(topic);
  String message = "";
  for (unsigned int i = 0; i < length; i++) { // Change int to unsigned int
    message += (char)payload[i];
  }
  Serial.println("Message received: " + message);
}


