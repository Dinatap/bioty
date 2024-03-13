#ifndef MQTTCONTROL_H
#define MQTTCONTROL_H

#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFiClient.h>

extern const char* mqtt_server;
extern const int mqtt_port;
extern const char* mqtt_username;
extern const char* mqtt_password;
extern const char* mqtt_stepper_topic;
extern const char* mqtt_servo_topic;

extern WiFiClient wifiClient;
extern PubSubClient mqttClient;

void setupMQTT();
void mqttCallback(char* topic, byte* payload, unsigned int length);

#endif
