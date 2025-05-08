#ifndef ESP8266_SERIALCOMM_H
#define ESP8266_SERIALCOMM_H

#include <Arduino.h>
#include "SoftwareSerial.h"

#define RX_EMULATED_PIN D6
#define TX_EMULATED_PIN D5

extern SoftwareSerial espSerial;  


void SerialSetup();
void SendData_Monitor(String str);
void SendData_uart(String str);
String ReadData_max256();
String stripAtFirstLineEnd(String input);


#endif
