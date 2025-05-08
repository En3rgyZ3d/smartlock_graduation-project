#ifndef ESP8266_HTTPCOMM_H
#define ESP8266_HTTPCOMM_H
#include <Arduino.h>

int sendHttpRequest(String serverUrl, String keyValue);
bool handleHttpResponse(int httpCode);
int httpHealthStatus(String serverUrl);

#endif