#ifndef ESP8266_WIFISTATUS_MODULE_H
#define ESP8266_WIFISTATUS_MODULE_H

#include <Arduino.h>

// Status pins (safe)
#define STATUS_PIN0 D1        // GPIO5 - LSB
#define STATUS_PIN1 D2        // GPIO4 - MSB
#define RESERVED_PIN D7       // GPIO13 - reserved for future use

// 2-bit Status codes (values 0–3)
#define STATUS_NOCONN     0b00
#define STATUS_CONN       0b01
#define STATUS_SERVERUP   0b10
#define STATUS_SERVERDOWN 0b11

void espStatusInit();
void espSetStatus(uint8_t status);
void espSetReserved(bool high);

#endif
