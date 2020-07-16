/****************************************************************************************************************************
  defines.h for SAMDUE-Ethernet-Minimal-Client.ino
  For SAM DUE with Ethernet module/shield.
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
  Version: 1.0.1

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/07/2020 Initial coding/porting to support nRF52 and SAMD21/SAMD51 boards. Add SINRIC/Alexa support 
  1.0.1   K Hoang      16/07/2020 Add support to SAM DUE. Add support to Ethernet W5x00 to nRF52, SAMD, SAM DUE boards.        
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#if ( defined(ARDUINO_SAM_DUE) || defined(__SAM3X8E__) )
  #if defined(WEBSOCKETS_ETHERNET_USE_SAMDUE)
    #undef WEBSOCKETS_ETHERNET_USE_SAMDUE
  #endif
  #define WEBSOCKETS_USE_ETHERNET             true
  #define WEBSOCKETS_ETHERNET_USE_SAMDUE      true
#else
  #error This code is intended to run only on the SAMD boards ! Please check your Tools->Board setting.
#endif

#if defined(WEBSOCKETS_ETHERNET_USE_SAMDUE)

// For SAM DUE
#if defined(ARDUINO_SAM_DUE)
#define BOARD_TYPE      "SAM DUE"
#elif defined(__SAM3X8E__)
#define BOARD_TYPE      "SAM SAM3X8E"
#else
#define BOARD_TYPE      "SAM Unknown"
#endif

#endif

// Just select one to be true. If all is false, default is Ethernet. 
// If more than one are true, the priority is USE_ETHERNET_LIB, USE_ETHERNET2_LIB, USE_ETHERNET_LARGE_LIB
#define USE_ETHERNET_LIB              false
#define USE_ETHERNET2_LIB             false
#define USE_ETHERNET_LARGE_LIB        true

#if USE_ETHERNET_LIB
  // Also default to Ethernet library
  #include <Ethernet.h>
#elif USE_ETHERNET2_LIB
  #include <Ethernet2.h>
#elif USE_ETHERNET_LARGE_LIB
  #include <EthernetLarge.h>
#else
  // Default to Ethernet library
  #include <Ethernet.h>
#endif

#define DEBUG_WEBSOCKETS_PORT     Serial
// Debug Level from 0 to 4
#define _WEBSOCKETS_LOGLEVEL_     3

//const char* websockets_server_host = "192.168.2.95"; //Enter server address
//const char* websockets_server_host = "192.168.2.99"; //Enter server address
const char* websockets_server_host = "192.168.2.152"; //Enter server address
//const char* websockets_server_host = "serverip_or_name"; //Enter server address

const uint16_t websockets_server_port = 8080; // Enter server port

uint8_t mac[6] =  { 0xDE, 0xAD, 0xBE, 0xEF, 0xDE, 0x03 };

// Select the IP address according to your local network
IPAddress clientIP(192, 168, 2, 225);

#define SDCARD_CS       4

#endif      //defines_h
