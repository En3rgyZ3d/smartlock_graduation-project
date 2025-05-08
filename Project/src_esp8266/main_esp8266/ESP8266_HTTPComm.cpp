#include "ESP8266_HTTPComm.h"

#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include <Arduino.h>

// Function to send HTTP POST request with JSON payload
int sendHttpRequest(String serverUrl, String keyValue)
{
    HTTPClient http;
    WiFiClient client;

    // Create JSON payload
    StaticJsonDocument<200> doc;
    doc["key"] = keyValue; // Assign dynamic value to the "key" field

    // Serialize JSON to string
    String jsonString;
    serializeJson(doc, jsonString);

    // Begin HTTP request
    http.begin(client, serverUrl);
    http.addHeader("Content-Type", "application/json"); // Set content type header

    // Send POST request with JSON payload
    int httpCode = http.POST(jsonString); // Send request

    // End HTTP request
    http.end();

    return httpCode; // Return HTTP response code
}

// Function to handle the response and check if the status code is 200
bool handleHttpResponse(int httpCode)
{
    if (httpCode == 200)
    {
        Serial.println("Request successful: Status code 200");
        return true; // Indicate success
    }
    else
    {
        Serial.print("Request failed: HTTP code ");
        Serial.println(httpCode);
        return false; // Indicate failure
    }
}

int httpHealthStatus(String serverUrl) {

    HTTPClient http;
    WiFiClient client;
    http.begin(client, serverUrl);
    int httpCode = http.GET();  // Send the GET request
    http.end();
    return httpCode;
}