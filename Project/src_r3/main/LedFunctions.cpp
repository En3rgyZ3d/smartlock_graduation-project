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

    switch (input) {
      case RED:
        {
          digitalWrite(LED_ERR, HIGH);
          digitalWrite(LED_OPEN, LOW);
          digitalWrite(LED_CLOSED, LOW);
          break;
        }
      case GREEN:
        {
          digitalWrite(LED_ERR, LOW);
          digitalWrite(LED_OPEN, HIGH);
          digitalWrite(LED_CLOSED, LOW);
  
          break;
        }
      case BLUE:
        {
          digitalWrite(LED_ERR, LOW);
          digitalWrite(LED_OPEN, LOW);
          digitalWrite(LED_CLOSED, HIGH);
  
          break;
        }
      default:
        {
          digitalWrite(LED_ERR, LOW);
          digitalWrite(LED_OPEN, LOW);
          digitalWrite(LED_CLOSED, LOW);
        }
    }
  }
  