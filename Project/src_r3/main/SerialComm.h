#ifndef SERIALCOMM_H
#define SERIALCOMM_H

#include <SoftwareSerial.h>  // Include SoftwareSerial library
#include <Arduino.h>
#define TX_PIN 11
#define RX_PIN 10


// Declare SoftwareSerial object
extern SoftwareSerial espSerial;

// Function prototypes
void serialCommSetup();
void serialCommLoop();
void espSerial_SendData(String data);
String ReadData_max256();
String stripAtFirstLineEnd(String input);

#endif
