//#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <EEPROM.h>
#include<math.h>

// Define constants

#define STEP_PIN  18
#define DIR_PIN   19
#define ENABLE_PIN 21
#define pi 3.1416
#define DEG2RAD 0.0175
#define ch1 4
#define ch2 2
#define Stepdevider 1


#define MEMORY_SIZE 4*sizeof(float)

#define ADDRESS_V 0
#define ADDRESS_R (ADDRESS_V + sizeof(float))
#define ADDRESS_TSR (ADDRESS_R + sizeof(float))
#define ADDRESS_THETA (ADDRESS_TSR + sizeof(float))
