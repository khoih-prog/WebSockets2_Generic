/****************************************************************************************************************************
  defines.h for WT32_ETH01_Client_SINRIC.ino
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

#define SINRIC_WEBSERVER          "iot.sinric.com"
#define SINRIC_WEBSERVER_PORT     80

#define SINRIC_API_KEY            "11111111-2222-3333-4444-555555555555"
#define SINRIC_Device_ID_1        "012345678901234567890123"   // Device ID, got from Sinric

const char* websockets_server_host    = SINRIC_WEBSERVER; //Enter server address
const uint16_t websockets_server_port = SINRIC_WEBSERVER_PORT; // Enter server port

// Select the IP address according to your local network
IPAddress myIP(192, 168, 2, 232);
IPAddress myGW(192, 168, 2, 1);
IPAddress mySN(255, 255, 255, 0);

// Google DNS Server IP
IPAddress myDNS(8, 8, 8, 8);

#define LED_PIN     12      // GPIO12 (pin 16) of WT32_ETH01

#endif      //defines_h
