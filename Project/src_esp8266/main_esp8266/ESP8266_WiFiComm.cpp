#include "ESP8266_WiFiComm.h"
#include <ESP8266WiFi.h>


void setupWiFiComm(const char* ssid, const char* password) {
    WiFi.begin(ssid, password);

    Serial.print("Connecting"); // Assume the serial connection already initialised

    unsigned long startAttemptTime = millis();
    unsigned long timeout = 5000; // 10 seconds

    while (WiFi.status() != WL_CONNECTED && (millis() - startAttemptTime < timeout) )
    {
        delay(500);
        Serial.print(".");
      }
      Serial.println();
   if (checkWiFiComm()) { 
      Serial.print("Connected, IP address: ");
      Serial.println(WiFi.localIP());
}
}

bool checkWiFiComm() {
  if (WiFi.status() != WL_CONNECTED) return false;
  return true;
}
