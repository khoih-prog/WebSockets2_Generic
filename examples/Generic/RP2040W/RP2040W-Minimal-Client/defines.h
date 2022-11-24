/****************************************************************************************************************************
  defines.h
  For RP2040W with CYW43439 WiFi.

  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52, SAMD21/SAMD51, RP2040 boards besides ESP8266 and ESP32


  The library provides simple and easy interface for websockets (Client and Server).

  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#if ( defined(ARDUINO_RASPBERRY_PI_PICO_W) )
  #if defined(WEBSOCKETS_USE_RP2040W)
    #undef WEBSOCKETS_USE_RP2040W
  #endif
  #define WEBSOCKETS_USE_RP2040W            true
  #define USE_RP2040W_WIFI                  true
  #define USE_WIFI_NINA                     false
#else
  #error This code is intended to run only on the RP2040W boards ! Please check your Tools->Board setting.
#endif

#include <WiFi.h>

#define DEBUG_WEBSOCKETS_PORT     Serial
// Debug Level from 0 to 4
#define _WEBSOCKETS_LOGLEVEL_     3

const char* ssid  = "ssid";       //Enter SSID
const char* pass  = "password";   //Enter Password

#endif      //defines_h
