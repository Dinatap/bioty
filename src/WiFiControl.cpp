#include "WiFiControl.h"
#include <ESP8266WiFi.h>

// WiFi settings
const char* ssid = "Sayoti Office_ext";
const char* password = "solusiiot";

void setupWiFi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi connected - IP address: ");
  Serial.println(WiFi.localIP());
}
