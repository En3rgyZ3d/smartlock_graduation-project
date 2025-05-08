#ifndef ESP32_WIFI_COMM_H
#define ESP32_WIFI_COMM_H

#include <NetworkClient.h>
#include <NetworkServer.h>

#ifndef LED_BUILTIN
#define LED_BUILTIN 2
#endif

extern NetworkServer server;


void _serialDebugSetup();

void setupWiFiAP(const char *ssid, const char *password);
void clientWiFiLogging();

void logConnectedStations(); 


#endif