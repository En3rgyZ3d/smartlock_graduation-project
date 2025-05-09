#include <Keypad.h>
#include "keyPadModule.h"

#define COLS 4
#define ROWS 4
char KEYS[ROWS][COLS]={
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};
byte colPIN[COLS] = { 3, 2, 13, 0 }; // From left to right (white cables, last 4 pins)
byte rowPIN[ROWS] = { 7, 6, 5, 4 }; // From left to right (green cables, first 4 pins)
