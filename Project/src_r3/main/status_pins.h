#ifndef STATUS_PINS_H
#define STATUS_PINS_H

// Define the pins used for reading status from ESP8266
#define STATUS_PIN0 A3  
#define STATUS_PIN1 A4  
#define RESERVED_PIN A5 

enum status_t {
  STATUS_NOCONN,
  STATUS_CONN,
  STATUS_SERVERUP,
  STATUS_SERVERDOWN
};

void statusPinsInit();
status_t readStatus();
void printStatus(status_t status);

#endif
