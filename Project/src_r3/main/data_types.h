#ifndef MAIN_DATA_TYPES_H
#define MAIN_DATA_TYPES_H


#define LED_ERR 8
#define LED_OPEN 9
#define LED_CLOSED 10



typedef enum {
  L_IDLE,
  L_CLOSED,
  L_VERIFY,
  L_OPEN,
  ST_CONN, ST_NOCONN,
  ST_SERVERUP, ST_SERVERDOWN,
  AUTH_NONVALID
} lockStatus_t;

typedef enum {
  NONE  = 0,
  RED   = 1 << 0,  // 0001
  GREEN = 1 << 1,  // 0010
  BLUE  = 1 << 2   // 0100
} ledStatus_t;


#endif