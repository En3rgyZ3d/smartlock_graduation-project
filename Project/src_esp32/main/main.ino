#include "WiFi_Comm.h"

// Set these to your desired credentials.
const char *ssid = "yourAP";
const char *password = "yourPassword";


void setup() {
  setupWiFiAP(ssid,password);
}

void loop() {

  //clientWiFiLogging();
  logConnectedStations();
}