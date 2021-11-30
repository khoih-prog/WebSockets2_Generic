/****************************************************************************************************************************
  defines.h
  For WT32_ETH01 (ESP32 + LAN8720)

  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32


  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#if ( ARDUINO_ESP32S2_DEV || ARDUINO_FEATHERS2 || ARDUINO_ESP32S2_THING_PLUS || ARDUINO_MICROS2 || \
        ARDUINO_METRO_ESP32S2 || ARDUINO_MAGTAG29_ESP32S2 || ARDUINO_FUNHOUSE_ESP32S2 || \
        ARDUINO_ADAFRUIT_FEATHER_ESP32S2_NOPSRAM )
  #define BOARD_TYPE      "ESP32-S2"
#elif ( ARDUINO_ESP32C3_DEV )
  #warning Using ESP32-C3 boards
  #define BOARD_TYPE      "ESP32-C3"
#elif ESP32
  #define BOARD_TYPE      "ESP32"
#else
  #error This code is intended to run on the ESP32 platform! Please check your Tools->Board setting.  
#endif

#define DEBUG_WEBSOCKETS_PORT               Serial
// Debug Level from 0 to 4
#define _WEBSOCKETS_LOGLEVEL_               3
#define _ETHERNET_WEBSERVER_LOGLEVEL_       3

#include <WebServer_WT32_ETH01.h>     // https://github.com/khoih-prog/WebServer_WT32_ETH01
#include <ESPmDNS.h>

#define WEBSOCKETS_PORT     8080

const uint16_t websockets_server_port = WEBSOCKETS_PORT; // Enter server port

// Select the IP address according to your local network
IPAddress serverIP(192, 168, 2, 96);

IPAddress static_GW(192, 168, 2, 1);
IPAddress static_SN(255, 255, 255, 0);

// Google DNS Server IP
IPAddress myDNS(8, 8, 8, 8);

#endif      //defines_h
