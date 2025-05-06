#ifndef SERIALCOMM_H
#define SERIALCOMM_H

#include <SoftwareSerial.h>  // Include SoftwareSerial library

#define TX_PIN 11
#define RX_PIN 10


// Declare SoftwareSerial object
extern SoftwareSerial espSerial;

// Function prototypes
void serialCommSetup();
void serialCommLoop();

#endif
