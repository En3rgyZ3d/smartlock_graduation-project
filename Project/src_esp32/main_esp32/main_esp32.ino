#include "ESP32_WiFi_Comm.h"
#include <WiFi.h>
#include <WiFiAP.h>

// Set these to your desired credentials.
const char *ssid = "IoT-Testing-GradProj";
const char *password = "t3sT1nG-gR4d";

IPAddress local_ip(10, 1, 1, 1);  // AP's IP address
IPAddress gateway(10, 1, 1, 1);   // Gateway IP address (same as AP IP)
IPAddress subnet(255, 255, 255, 0); // Subnet mask


void setup() {
  setupWiFiAP(ssid,password, local_ip, gateway, subnet);
}

void loop() {

  //clientWiFiLogging();
  logConnectedStations();
}