#include <Arduino.h>
#include "WiFiControl.h"
#include "MQTTControl.h"

const int ledPin = D2; // Pin connected to LED indicator

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  setupWiFi();
  setupMQTT();
}

void loop() {
  if (!mqttClient.connected()) {
    setupMQTT();
  }
  mqttClient.loop();
}
