#include "ESP8266_SerialComm.h"

void setup() {
  // put your setup code here, to run once:
  SerialSetup();

}

void loop() {
  // put your main code here, to run repeatedly:
  String testEsp = "ESP8266: Im alive!";
  SendData_uart(testEsp);
  String response = ReadData_max256();
  Serial.println(response);
  delay(2000);
}
