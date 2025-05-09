#include "ESP8266_SerialComm.h"
#include "ESP8266_WiFiComm.h"
#include "ESP8266_HTTPComm.h"
#include "ESP8266_WiFiStatus_Module.h"
#include <Arduino.h>

const String serverUrl = "http://10.1.1.128:8000/auth/";
const String healthUrlCheck = "http://10.1.1.128:8000/status/";

String mockKey = "12345678";

const char *ssid = "IoT-Testing-GradProj";
const char *password = "t3sT1nG-gR4d";

void setup()
{
  SerialSetup();
  delay(5000);
  espStatusInit(); // Initialize the status signaling pins
  delay(2000);
  setupWiFiComm(ssid, password);
  delay(1000);
}

void loop()
{
  // put your main code here, to run repeatedly:
  String key = "";

  if (checkWiFiComm())
  {

    espSetStatus(STATUS_CONN);

    while (httpHealthStatus(healthUrlCheck) != 200)
    {

      espSetStatus(STATUS_SERVERDOWN);
      delay(250);
    }

    espSetStatus(STATUS_SERVERUP);

    while (!espSerial.available()); // Blocking read
    delay(200);
    String response = ReadData_max256();
      int number_of_characters = response.length();
      if (number_of_characters > 0)
      {

        key = stripAtFirstLineEnd(response);
        Serial.print("Debug: |");
        Serial.print(key);
        Serial.println("|");
      }    
      if (httpHealthStatus(healthUrlCheck) == 200) // After i receive the data i do another check and then i can send it to http
    {

      // String key = mockKey; //uncomment to test this
      int statusCode = -1;
      statusCode = sendHttpRequest(serverUrl, key);

      if (statusCode != -1)
      {
        espSetStatus(STATUS_SERVERUP);

        Serial.print("Status code from HTTP Server: ");
        Serial.println(statusCode);

        if (statusCode == 200)
        {
          espSerial.println("AUTH_VALID");
        }
        else
        {
          espSerial.println("AUTH_NONVALID");
        }
      }
      else
      {
        espSetStatus(STATUS_SERVERDOWN);

        Serial.println("Error: HTTP Server not reachable.");
      }

      delay(2000);
    }
    else {
      espSetStatus(STATUS_SERVERDOWN);
      Serial.println("Error: Can't process request (HTTP Server not reachable).");
    }
  }
  else
  {
    espSetStatus(STATUS_NOCONN);
    delay(4000);
  }
}
