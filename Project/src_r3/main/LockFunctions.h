#ifndef LOCKFUNCTIONS_H
#define LOCKFUNCTIONS_H

#include <Arduino.h>
#include "keyPadModule.h"
#include <Keypad.h>
extern String testKey;

void lockState_FSM(Keypad myKeyPad);

#endif