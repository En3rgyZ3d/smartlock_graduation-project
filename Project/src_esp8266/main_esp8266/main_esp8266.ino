#include "ESP8266_SerialComm.h"
#include "ESP8266_WiFiComm.h"

  const char* ssid = "IoT-Testing-GradProj";
  const char* password = "t3sT1nG-gR4d";

void setup() {
  // put your setup code here, to run once:
  SerialSetup();
  setupWiFiComm(ssid, password);
}

void loop() {
  // put your main code here, to run repeatedly:
  String testEsp = "ESP8266: Im alive!";
  SendData_uart(testEsp);
  String response = ReadData_max256();
  int number_of_characters = response.length();
  if (number_of_characters >0) {
  
  Serial.println(response);
  }
  delay(2000);
}
