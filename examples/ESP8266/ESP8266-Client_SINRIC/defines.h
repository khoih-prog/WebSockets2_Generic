/****************************************************************************************************************************
  defines.h
  For ESP8266, using SINRIC (https://sinric.com/)

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

const char* ssid      = "ssid";       //Enter SSID
const char* password  = "password";   //Enter Password

#define SINRIC_WEBSERVER          "iot.sinric.com"
#define SINRIC_WEBSERVER_PORT     80
#define SINRIC_API_KEY            "11111111-2222-3333-4444-555555555555"

#define SINRIC_Device_ID_1        "012345678901234567890123"   // Device ID, got from Sinric

const char* websockets_server_host    = SINRIC_WEBSERVER; //Enter server address
const uint16_t websockets_server_port = SINRIC_WEBSERVER_PORT; // Enter server port

#ifdef LED_BUILTIN
#define LED_PIN     LED_BUILTIN
#else
#define LED_PIN     2
#endif

// Reversed logic
#define LED_BUILTIN_ON      LOW
#define LED_BUILTIN_OFF     HIGH

#endif      //defines_h
