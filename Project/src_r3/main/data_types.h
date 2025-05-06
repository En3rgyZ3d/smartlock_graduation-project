#ifndef MAIN_DATA_TYPES_H
#define MAIN_DATA_TYPES_H


#define LED_ERR 2
#define LED_OPEN 3
#define LED_CLOSED 4



typedef enum {
  L_CLOSED,
  L_VERIFY,
  L_OPEN
} lockStatus_t;

typedef enum {
  RED, GREEN, BLUE,
  B_RED, B_GREEN, B_BLUE // BLINKING STATES
} ledStatus_t;


#endif