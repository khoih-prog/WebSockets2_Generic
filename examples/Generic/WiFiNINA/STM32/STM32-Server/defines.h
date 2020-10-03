/****************************************************************************************************************************
  defines.h for SAMD-Server.ino
  For STM32F/L/H/G/WB/MP1 with WiFiNINA module/shield.
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32
  
  The library provides simple and easy interface for websockets (Client and Server).
  
  Example first created on: 10.05.2018
  Original Author: Markus Sattler
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
  Version: 1.0.7

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/07/2020 Initial coding/porting to support nRF52 and SAMD21/SAMD51 boards. Add SINRIC/Alexa support
  1.0.1   K Hoang      16/07/2020 Add support to Ethernet W5x00 to nRF52, SAMD21/SAMD51 and SAM DUE boards
  1.0.2   K Hoang      18/07/2020 Add support to Ethernet ENC28J60 to nRF52, SAMD21/SAMD51 and SAM DUE boards
  1.0.3   K Hoang      18/07/2020 Add support to STM32F boards using Ethernet W5x00, ENC28J60 and LAN8742A 
  1.0.4   K Hoang      27/07/2020 Add support to STM32F/L/H/G/WB/MP1 and Seeeduino SAMD21/SAMD51 using 
                                  Ethernet W5x00, ENC28J60, LAN8742A and WiFiNINA. Add examples and Packages' Patches.
  1.0.5   K Hoang      29/07/2020 Sync with ArduinoWebsockets v0.4.18 to fix ESP8266 SSL bug.
  1.0.6   K Hoang      06/08/2020 Add non-blocking WebSocketsServer feature and non-blocking examples.       
  1.0.7   K Hoang      03/10/2020 Add support to Ethernet ENC28J60 using EthernetENC and UIPEthernet v2.0.9
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#if  ( defined(STM32F0) || defined(STM32F1) || defined(STM32F2) || defined(STM32F3)  ||defined(STM32F4) || defined(STM32F7) || \
       defined(STM32L0) || defined(STM32L1) || defined(STM32L4) || defined(STM32H7)  ||defined(STM32G0) || defined(STM32G4) || \
       defined(STM32WB) || defined(STM32MP1) )
#if defined(WEBSOCKETS_WIFININA_USE_STM32)
#undef WEBSOCKETS_WIFININA_USE_STM32
#endif
#define WEBSOCKETS_USE_WIFININA           true
#define WEBSOCKETS_WIFININA_USE_STM32      true
#else
#error This code is intended to run only on the STM32F/L/H/G/WB/MP1 boards ! Please check your Tools->Board setting.
#endif

#if defined(WEBSOCKETS_WIFININA_USE_STM32)

// For STM32
  #if defined(STM32F0)
    #define BOARD_TYPE  "STM32F0"
    #error Board STM32F0 not supported
  #elif defined(STM32F1)
    #define BOARD_TYPE  "STM32F1"
  #elif defined(STM32F2)
    #define BOARD_TYPE  "STM32F2"
  #elif defined(STM32F3)
    #define BOARD_TYPE  "STM32F3"
  #elif defined(STM32F4)
    #define BOARD_TYPE  "STM32F4"
  #elif defined(STM32F7)
    #define BOARD_TYPE  "STM32F7"
  #elif defined(STM32L0)
    #define BOARD_TYPE  "STM32L0"  
  #elif defined(STM32L1)
    #define BOARD_TYPE  "STM32L1"
  #elif defined(STM32L4)
    #define BOARD_TYPE  "STM32L4"
  #elif defined(STM32H7)
    #define BOARD_TYPE  "STM32H7"
  #elif defined(STM32G0)
    #define BOARD_TYPE  "STM32G0"
  #elif defined(STM32G4)
    #define BOARD_TYPE  "STM32G4"
  #elif defined(STM32WB)
    #define BOARD_TYPE  "STM32WB"
  #elif defined(STM32MP1)
    #define BOARD_TYPE  "STM32MP1"  
  #else
    #warning STM32 unknown board selected
    #define BOARD_TYPE  "STM32 Unknown"
  #endif

#endif

#ifndef BOARD_NAME
  #define BOARD_NAME    BOARD_TYPE
#endif

#include <WiFiNINA_Generic.h>

#define DEBUG_WEBSOCKETS_PORT     Serial
// Debug Level from 0 to 4
#define _WEBSOCKETS_LOGLEVEL_     3

const char* ssid = "ssid"; //Enter SSID
const char* password = "password"; //Enter Password

// Select the IP address according to your local network
IPAddress serverIP(192, 168, 2, 95);


#define WEBSOCKETS_PORT     8080

#endif      //defines_h
