#include "SerialComm.h"  // Include the header file to link the functions
#include <Arduino.h>
#include "SoftwareSerial.h"

// Define the SoftwareSerial object for communication with ESP8266
SoftwareSerial espSerial(RX_PIN, TX_PIN); // RX, TX pins (for communication with Arduino)

// Function to set up serial communication
void serialCommSetup() {
  Serial.begin(9600);       // Start communication with Serial Monitor
  espSerial.begin(9600);    // Start communication with ESP8266 via SoftwareSerial
}

// Function to handle serial communication in the loop
void serialCommLoop() {
  // Check if data is available from ESP8266 (through TX/RX)
  if (espSerial.available()) {
    String received = espSerial.readString(); // Read the incoming data
    Serial.println("Received: " + received);  // Print it to the Serial Monitor
  }
}


void espSerial_SendData(String data) {
  espSerial.println(data);
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

