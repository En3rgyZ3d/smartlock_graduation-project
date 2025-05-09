#include "data_types.h"
#include "LedFunctions.h"
#include "LockFunctions.h"
#include "SerialComm.h"
#include "status_pins.h"

Keypad myKeypad = Keypad(makeKeymap(KEYS), rowPIN, colPIN, ROWS, COLS);


void setup() {
  // put your setup code here, to run once:
  statusPinsInit();  // Initialize the status pins (pins 5, 6, 7)

  outputLedSetup();
  serialCommSetup();
  
  /* Signals that the system is starting, giving enough time for everything to boot */

  for (int i = 0; i<10; i++);
  ledControl(RED|GREEN|BLUE); 
  delay(500); 
  ledControl(NONE); 
  delay(500); 


}

void loop() {
  // put your main code here, to run repeatedly:
  lockState_FSM(myKeypad);
  //serialCommLoop(); // Debug function

}