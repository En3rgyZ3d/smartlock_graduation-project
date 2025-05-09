#include "LockFunctions.h"
#include "data_types.h"
#include "LedFunctions.h"
#include <Arduino.h>
#include "SerialComm.h"
#include "status_pins.h"
#include "keyPadModule.h"

String testKey = "12345678";

// 5 red blinks for no conn
// 10 red blinks for server down
// 3 red blinks for conn

void lockState_FSM(Keypad myKeyPad) {

  static lockStatus_t currentState = L_IDLE;
  status_t espStatus = readStatus();  // Read the current status from the ESP8266
  static String inputStr;
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
        Serial.println("Insert the key: ");
        ledControl(BLUE);
        inputStr = "";
        bool send = false;
        while (inputStr.length() < 32 && (!send)) {
          char pressedKey = myKeyPad.getKey();
          delay(50);  // enough to avoid bouncing

          if (pressedKey) {
            if (pressedKey == '#') {  // Optional: Use '#' to finish early
              send = true;
            } else {
              inputStr += pressedKey;
              Serial.print(pressedKey);
            }
          }
        }
        Serial.println();
        Serial.println("Sending key...");
        currentState = L_VERIFY;
        // If a key arrives, then we go into the verification state



        break;
      }

    case L_VERIFY:
      {
        ledControl(BLUE);
        espSerial_SendData(inputStr);

        while (!espSerial.available()) { // waits for a response if the server is not down;
      
        if (readStatus() != STATUS_SERVERUP) {
          break;
        }
      
      
      }  
        delay(500);
        String authStr = ReadData_max256();
        int currentAttempt = 0;
        while ((readStatus() != STATUS_SERVERUP) && currentAttempt <5) {
          Serial.print("Attempt ");
          Serial.print(currentAttempt+1);
          Serial.println();
          currentState = ST_SERVERDOWN;
          delay(2000);
          currentAttempt++;
        }

        if (currentAttempt <5) {

        
          authStr = stripAtFirstLineEnd(authStr);
          if (authStr.startsWith("AUTH_")) {

            String code = authStr.substring(5);  // Extract after "AUTH_"
            if (code == "VALID") {

              currentState = L_OPEN;
            } else if (code == "NONVALID") {
              Serial.println("KEY NOT VALID.");
              ledControl(BLUE | RED);
              delay(4000);
              currentState = L_CLOSED;
            }

          } else currentState = L_CLOSED;
        }
        break;
      }
    case L_OPEN:
      {
        Serial.println("ACCESS GRANTED.");
        ledControl(GREEN);
        delay(5000);
        currentState = L_CLOSED;
      }
      break;

    case ST_NOCONN:
      {
        Serial.println("ERROR: Lock not connected to WLAN.");
        for (int i = 0; i < 5; i++) {
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
        Serial.println("ERROR: HTTP Server unreachable.");
        for (int i = 0; i < 10; i++) {
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
        ledControl(NONE);  // delay a bit before checking again
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
