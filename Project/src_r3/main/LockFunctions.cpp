#include "LockFunctions.h"
#include "data_types.h"
#include "LedFunctions.h"
#include <Arduino.h>
void lockState_FSM(int key) {
  
    static lockStatus_t currentState = L_CLOSED;
  
  
  
    switch (currentState) {
      case L_CLOSED:
        {
          ledControl(BLUE);
  
          // If a key arrives, then we go into the verification state
          if (key) currentState = L_VERIFY;
  
          break;
        }
  
      case L_VERIFY:
        {
          ledControl(BLUE);
          bool auth = false;
  
          // TODO: add functions to send data to server and wait for OK from the server
  
          delay(2000);  // Emulation of the verify
          auth = true;
  
          if (auth == true) currentState = L_OPEN;
  
          break;
        }
      case L_OPEN:
        {
          ledControl(GREEN);
          delay(5000);
          currentState = L_CLOSED;
        }
        break;
  
      default:
        {
          ledControl(RED);
          delay(2000);
          currentState = L_CLOSED;
        }
    }
  }
  
  
  