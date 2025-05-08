#include "WiFi_Comm.h"

// Set these to your desired credentials.
const char *ssid = "IoT-Testing-GradProj";
const char *password = "t3sT1nG-gR4d";


void setup() {
  setupWiFiAP(ssid,password);
}

void loop() {

  //clientWiFiLogging();
  logConnectedStations();
}