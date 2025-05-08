#include "ESP8266_WiFiStatus_Module.h"

void espStatusInit() {
  pinMode(STATUS_PIN0, OUTPUT);
  pinMode(STATUS_PIN1, OUTPUT);
  pinMode(RESERVED_PIN, OUTPUT);
  espSetStatus(STATUS_NOCONN);    // Default
  espSetReserved(false);          // Reserved off by default
}

void espSetStatus(uint8_t status) {
  digitalWrite(STATUS_PIN0, status & 0b01);
  digitalWrite(STATUS_PIN1, status & 0b10);
}

void espSetReserved(bool high) {
  digitalWrite(RESERVED_PIN, high ? HIGH : LOW);
}
