#include "ESP8266_WiFiComm.h"
#include <ESP8266WiFi.h>


void setupWiFiComm(const char* ssid, const char* password) {
    WiFi.begin(ssid, password);

    Serial.print("Connecting"); // Assume the serial connection already initialised
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
      }
      Serial.println();
    
      Serial.print("Connected, IP address: ");
      Serial.println(WiFi.localIP());
}
    
