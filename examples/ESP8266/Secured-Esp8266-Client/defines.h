/****************************************************************************************************************************
  defines.h for Secured-ESP8266-Client.ino
  For ESP8266.
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32


  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#if (ESP8266)
  #define BOARD_TYPE      "ESP8266"
#else
  #error This code is intended to run only on the ESP8266 boards ! Please check your Tools->Board setting.
#endif

#ifndef BOARD_NAME
  #define BOARD_NAME    BOARD_TYPE
#endif

#define DEBUG_WEBSOCKETS_PORT     Serial
// Debug Level from 0 to 4
#define _WEBSOCKETS_LOGLEVEL_     3

const char* ssid = "ssid"; //Enter SSID
const char* password = "password"; //Enter Password

// Deprecated echo.websocket.org to be replaced or it won't work
const char* websockets_connection_string = "wss://echo.websocket.org/"; //Enter server adress

// To update SHA1 fingerprint, use Google Chrome to connect to https://www.websocket.org/echo.html 
// Then "View Site Information" => "Certificate Viewer" => Copy SHA1 fingerprint
// KH, This SHA1 fingerprint was updated 15.04.2021, 
// Issued on Mar 15th 2021, expired on June 13th 2021
const char echo_org_ssl_fingerprint[] PROGMEM   = "34 A2 66 08 A1 4D 1E 83 1A 0E 49 3C 4A 84 45 9E 4A 0D 08 FE";

#endif      //defines_h
