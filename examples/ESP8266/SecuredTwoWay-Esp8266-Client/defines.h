/****************************************************************************************************************************
  defines.h for SecuredTwoWay-ESP8266-Client.ino
  For ESP8266.
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/ESP8266_AT_WebServer
  Licensed under MIT license
  Version: 1.0.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/07/2020 Initial coding/porting to support nRF52 and SAMD21/SAMD51 boards. Add SINRIC/Alexa support     
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#if (ESP8266)
  #define BOARD_TYPE      "ESP8266"
#else
  #error This code is intended to run only on the ESP8266 boards ! Please check your Tools->Board setting.
#endif

#define DEBUG_WEBSOCKETS_PORT     Serial
// Debug Level from 0 to 4
#define _WEBSOCKETS_LOGLEVEL_     2

const char* ssid = "ssid"; //Enter SSID
const char* password = "password"; //Enter Password

const char* websockets_connection_string = "wss://echo.websocket.org/"; //Enter server adress

// To update SHA1 fingerprint, use Google Chrome to connect to https://www.websocket.org/echo.html 
// Then "View Site Information" => "Certificate Viewer" => Copy SHA1 fingerprint
// This latest SHA1 fingerprint was updated 13.07.2020
const char echo_org_ssl_fingerprint[] PROGMEM   = "F0 DC 2E 40 A6 6D 29 B5 73 8F E1 E8 A9 EA 2A 9B 50 68 80 E3";

#endif      //defines_h
