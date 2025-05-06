#include "data_types.h"
#include "LedFunctions.h"
#include "LockFunctions.h"
#include "SerialComm.h"

void setup() {
  // put your setup code here, to run once:
  outputLedSetup();
  serialCommSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
  bool button_input = digitalRead(A0) == LOW;  // Emulazione dell'arrivo di una chiave, da sostituire con l'effettiva chiave che arriva
  //lockState_FSM(button_input);
  serialCommLoop();
  
}
