#include "LedFunctions.h"
#include "data_types.h"
#include <Arduino.h>

void outputLedSetup() {
    pinMode(LED_ERR, OUTPUT);
    pinMode(LED_OPEN, OUTPUT);
    pinMode(LED_CLOSED, OUTPUT);
    pinMode(A0, INPUT_PULLUP);
}



void ledControl(ledStatus_t input) {
  digitalWrite(LED_ERR,     (input & RED)   ? HIGH : LOW);
  digitalWrite(LED_OPEN,    (input & GREEN) ? HIGH : LOW);
  digitalWrite(LED_CLOSED,  (input & BLUE)  ? HIGH : LOW);
}
