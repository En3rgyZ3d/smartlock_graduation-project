#include "status_pins.h"
#include <Arduino.h>

void statusPinsInit() {
  pinMode(STATUS_PIN0, INPUT);   // Set the status pins as INPUT
  pinMode(STATUS_PIN1, INPUT);   // Set the status pins as INPUT
  pinMode(RESERVED_PIN, INPUT);  // Reserved pin as INPUT (if necessary)
}

status_t readStatus() {
  int pin0 = analogRead(STATUS_PIN0) > 600 ? 1:0; // Read the status of D5 (STATUS_PIN0)
  int pin1 = analogRead(STATUS_PIN1)> 600 ? 1:0; // Read the status of D6 (STATUS_PIN1)
  int pin2 = analogRead(RESERVED_PIN)> 600 ? 1:0; // Read the status of D7 (RESERVED_PIN)

  uint8_t code = (pin2 << 2) | (pin1 << 1) | pin0;

  switch (code) {
    case 0b000:
      return STATUS_NOCONN;
    case 0b001:
      return STATUS_CONN;
    case 0b010:
      return STATUS_SERVERUP;
    case 0b011:
      return STATUS_SERVERDOWN;
    default:
      return STATUS_NOCONN;  // Fallback default
  }
}

void printStatus(status_t status) {
  switch (status) {
    case STATUS_NOCONN:
      Serial.println("Status: No Connection");
      break;
    case STATUS_CONN:
      Serial.println("Status: Connected");
      break;
    case STATUS_SERVERUP:
      Serial.println("Status: Server Up");
      break;
    case STATUS_SERVERDOWN:
      Serial.println("Status: Server Down");
      break;
    default:
      Serial.println("Unknown Status");
  }
}
