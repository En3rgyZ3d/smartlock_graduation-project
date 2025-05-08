#include "ESP8266_SerialComm.h"
#include <Arduino.h>
#include "SoftwareSerial.h"

SoftwareSerial espSerial(RX_EMULATED_PIN, TX_EMULATED_PIN); // RX, TX pins (for communication with Arduino)

void SerialSetup() {
    Serial.begin(9600); // This initiates the channel from TX and RX pins
    espSerial.begin(9600);    // Start communication with R3 via SoftwareSerial

    Serial.println("ESP8266 DEBUG: Connection online!"); // Debugging message

    espSerial.println("ESP8266: Connection online!");

}

void SendData_Monitor(String str) {
    Serial.println(str);
}


void SendData_uart(String str) {
    espSerial.println(str);
}


String ReadData_max256() {
  String result = "";
  result.reserve(256); // Preallocate memory to avoid fragmentation

  while (espSerial.available() && result.length() < 256) {
    result += (char)espSerial.read();
  }

  return result;
}


String stripAtFirstLineEnd(String input) {
  int index = input.indexOf("\r\n");
  if (index == -1) {
    index = input.indexOf("\n\r");
  }

  if (index != -1) {
    return input.substring(0, index);
  }

  // If neither sequence is found, return the whole string
  return input;
}
