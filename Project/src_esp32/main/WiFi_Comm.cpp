#include "WiFi_Comm.h"
#include <WiFi.h>
#include <WiFiAP.h>
#include <Arduino.h>


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