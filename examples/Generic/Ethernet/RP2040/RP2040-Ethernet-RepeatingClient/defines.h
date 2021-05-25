/****************************************************************************************************************************
  defines.h
  For RP2040 with Ethernet module/shield.
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1,nRF52, RP2040 and SAMD21/SAMD51 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#if ( defined(ARDUINO_ARCH_RP2040) || defined(ARDUINO_RASPBERRY_PI_PICO) || defined(ARDUINO_ADAFRUIT_FEATHER_RP2040) || defined(ARDUINO_GENERIC_RP2040) )
  #if defined(WEBSOCKETS_ETHERNET_USE_RP2040)
    #undef WEBSOCKETS_ETHERNET_USE_RP2040
  #endif
  #define WEBSOCKETS_USE_ETHERNET             true
  #define WEBSOCKETS_ETHERNET_USE_RP2040       true
  
  #if defined(ETHERNET_USE_RPIPICO)
    #undef ETHERNET_USE_RPIPICO
  #endif
  #define ETHERNET_USE_RPIPICO      true

  // Default pin 5 for MBED and 17 for Earl Arduino-pico
  #define USE_THIS_SS_PIN         SS
#else
  #error This code is intended to run only on the RP2040 boards ! Please check your Tools->Board setting.
#endif

#if defined(ARDUINO_BOARD)
  #define BOARD_NAME    ARDUINO_BOARD
#else
  #ifndef BOARD_NAME
    #define BOARD_NAME    BOARD_TYPE
  #endif
#endif

// Just select one to be true. If all is false, default is Ethernet. 
// If more than one are true, the priority is USE_ETHERNET, USE_ETHERNET2, USE_ETHERNET_LARGE, USE_UIP_ETHERNET
#define USE_ETHERNET                  false
#define USE_ETHERNET2                 false
#define USE_ETHERNET_LARGE            true
#define USE_ETHERNET_ENC              false

#define USE_UIP_ETHERNET              false

#if USE_ETHERNET
  // Also default to Ethernet library
  #include <Ethernet.h>
  #define ETHERNET_TYPE               "W5x00 and Ethernet Library"
#elif USE_ETHERNET2
  #include <Ethernet2.h>
  #define ETHERNET_TYPE               "W5x00 and Ethernet2 Library"
#elif USE_ETHERNET_LARGE
  #include <EthernetLarge.h>
  #define ETHERNET_TYPE               "W5x00 and EthernetLarge Library"
#elif USE_ETHERNET_ENC
  #include <EthernetENC.h>
  #define ETHERNET_TYPE               "ENC28J60 and EthernetENC Library"  
#elif USE_UIP_ETHERNET
  #include <UIPEthernet.h>
  #include <utility/logging.h> 
  #define ETHERNET_TYPE               "ENC28J60 and UIPEthernet Library"
  #error ENC28J60 and UIPEthernet Library not yet supported for RP2040
#else
  // Default to Ethernet library
  #include <Ethernet.h>
  #define ETHERNET_TYPE               "W5x00 and Ethernet Library"
#endif

#define DEBUG_WEBSOCKETS_PORT     Serial
// Debug Level from 0 to 4
#define _WEBSOCKETS_LOGLEVEL_     3

uint8_t mac[6] =  { 0xDE, 0xAD, 0xBE, 0xEF, 0x20, 0x40 };

// Select the IP address according to your local network
IPAddress serverIP(192, 168, 2, 135);

const char* websockets_server_host = "192.168.2.135"; //Enter server address
//const char* websockets_server_host = "serverip_or_name"; //Enter server address

#define WEBSOCKETS_PORT   8080

const uint16_t websockets_server_port = WEBSOCKETS_PORT; // Enter server port

#define SDCARD_CS       4

#endif      //defines_h
