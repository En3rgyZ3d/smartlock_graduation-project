#include "LockFunctions.h"
#include "data_types.h"
#include "LedFunctions.h"
#include <Arduino.h>
#include "SerialComm.h"
#include "status_pins.h"

String testKey = "12345678";

// 5 red blinks for no conn
// 10 red blinks for server down
// 3 red blinks for conn

void lockState_FSM(bool start) {

  static lockStatus_t currentState = L_IDLE;
  status_t espStatus = readStatus();  // Read the current status from the ESP8266
  switch (currentState) {
    case L_IDLE:
      {

      if (espStatus == STATUS_NOCONN) {
        currentState = ST_NOCONN;  // No connection status
      } 

      if (espStatus == STATUS_CONN) {
        currentState = ST_CONN;  // Connection established, check server status
      } 

      if (espStatus == STATUS_SERVERUP) {
        currentState = L_CLOSED;  // Server is reachable
      }

      if (espStatus == STATUS_SERVERDOWN) {
        currentState = ST_SERVERDOWN;  // Server is down
      }

        break;
      }

    case L_CLOSED:
      {
        ledControl(BLUE);

        // If a key arrives, then we go into the verification state
        if (start) currentState = L_VERIFY;
        break;
      }

    case L_VERIFY:
      {
        ledControl(BLUE);

        espSerial_SendData(testKey);

        while (!espSerial.available())
          ;
        String authStr = ReadData_max256();
        authStr = stripAtFirstLineEnd(authStr);
        if (authStr.startsWith("AUTH_")) {

          String code = authStr.substring(5);  // Extract after "AUTH_"
          if (code == "VALID") {

            currentState = L_OPEN;
          } else if (code == "NONVALID") {
            ledControl(BLUE | RED);
            delay(2000);
            currentState = L_CLOSED;
          }
        } else currentState = L_CLOSED;
        break;
      }
    case L_OPEN:
      {
        ledControl(GREEN);
        delay(5000);
        currentState = L_CLOSED;
      }
      break;

    case ST_NOCONN:
      {
        for (int i = 0; i<5; i++) {
          ledControl(RED);
          delay(1000);
          ledControl(NONE);
          delay(1000);
        }
        currentState = L_IDLE;
        delay(2000);

        break;
      }
    case ST_SERVERDOWN:
        {
        for (int i = 0; i<10; i++) {
          ledControl(RED);
          delay(500);
          ledControl(NONE);
          delay(500);

        }
        currentState = L_IDLE;
        delay(2000);

        break;
      }
    case ST_CONN:
      {
        ledControl(NONE); // delay a bit before checking again
        delay(1000);
        currentState = L_IDLE;
        break;
      }
    default:
      {
        ledControl(RED);
        delay(5000);
        currentState = L_IDLE;
      }
  }
}

