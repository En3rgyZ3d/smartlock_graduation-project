#include "ESP32_WiFi_Comm.h"
#include <WiFi.h>
#include <WiFiAP.h>
#include <Arduino.h>
#include <esp_wifi.h>                // For esp_wifi_ap_get_sta_list




NetworkServer server(80);



void setupWiFiAP(const char *ssid, const char *password)
{
  pinMode(LED_BUILTIN, OUTPUT);

  _serialDebugSetup();

  Serial.println("Configuring access point...");

  // a valid password must have more than 7 characters
  if (!WiFi.softAP(ssid, password))
  {
    log_e("Soft AP creation failed.");
    while (1)
      ;
  }
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();

  Serial.println("Server started");
}


void _serialDebugSetup() {

  Serial.begin(115200);
  Serial.println();

}

void clientWiFiLogging() {
  NetworkClient client = server.accept();  // listen for incoming clients
  if (client) {                     // if you get a client,
    Serial.println("New Client Connected");
    Serial.print("Client IP: ");
    Serial.println(client.remoteIP());  // Log the client's IP address

    String currentLine = "";        // make a String to hold incoming data from the client
    while (client.connected()) {    // loop while the client's connected
    }
    // After the client is done, close the connection
    client.stop();
    Serial.println("Client Disconnected");


  }

  
  
}

void logConnectedStations()
{
  wifi_sta_list_t sta_list;

  if (esp_wifi_ap_get_sta_list(&sta_list) == ESP_OK) {
    Serial.printf("Connected stations: %d\n", sta_list.num);

    for (int i = 0; i < sta_list.num; ++i) {
      wifi_sta_info_t station = sta_list.sta[i];
      char macStr[18];
      snprintf(macStr, sizeof(macStr),
               "%02X:%02X:%02X:%02X:%02X:%02X",
               station.mac[0], station.mac[1], station.mac[2],
               station.mac[3], station.mac[4], station.mac[5]);

      Serial.printf("Client #%d: %s\n", i + 1, macStr);
    }
  } else {
    Serial.println("Failed to get station list.");
  }

  delay(5000);  // Check every 5 seconds
}