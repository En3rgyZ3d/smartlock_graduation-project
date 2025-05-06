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

  // Check if data is available from the Serial Monitor (USB)
  if (Serial.available()) {
    String dataToSend = Serial.readString(); // Read input from Serial Monitor
    espSerial.println(dataToSend);           // Send it to the ESP8266
  }
}
