/****************************************************************************************************************************
  defines.h
  For Teensy with Ethernet module/shield.

  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52, SAMD21/SAMD51, SAM DUE, Teensy boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#if ( defined(CORE_TEENSY) || defined(__IMXRT1062__) || defined(ARDUINO_TEENSY41) || defined(ARDUINO_TEENSY40) || \
      defined(__MK66FX1M0__) || defined(__MK64FX512__) || defined(__MKL26Z64__) || defined(__MK20DX256__) || \
      defined(__MK20DX128__) )
  #if defined(WEBSOCKETS_ETHERNET_USE_TEENSY)
    #undef WEBSOCKETS_ETHERNET_USE_TEENSY
  #endif
  #define WEBSOCKETS_USE_ETHERNET             true
  #define WEBSOCKETS_ETHERNET_USE_TEENSY      true
#else
  #error This code is intended to run only on the Teensy boards ! Please check your Tools->Board setting.
#endif

#if defined(WEBSOCKETS_ETHERNET_USE_TEENSY)

  #if ( defined(__IMXRT1062__) && defined(ARDUINO_TEENSY41) )
    #define BOARD_TYPE      "Teensy 4.1"
  #elif ( defined(__IMXRT1062__) && defined(ARDUINO_TEENSY40) )
    #define BOARD_TYPE      "Teensy 4.0"
  #elif defined(__MK66FX1M0__)
    #define BOARD_TYPE "Teensy 3.6"
  #elif defined(__MK64FX512__)
    #define BOARD_TYPE "Teensy 3.5"
  #elif defined(__MKL26Z64__)
    #define BOARD_TYPE "Teensy LC"
  #elif defined(__MK20DX256__)
    #define BOARD_TYPE "Teensy 3.2" // and Teensy 3.1 (obsolete)
  #elif defined(__MK20DX128__)
    #define BOARD_TYPE "Teensy 3.0"
  #elif defined(__AVR_AT90USB1286__)
    #error Teensy 2.0++ not supported yet
  #elif defined(__AVR_ATmega32U4__)
    #error Teensy 2.0 not supported yet
  #else
    // For Other Boards
    #define BOARD_TYPE      "Unknown Teensy Board"
  #endif

#endif    // WEBSOCKETS_ETHERNET_USE_TEENSY)

#if defined(ARDUINO_BOARD)
  #define BOARD_NAME    ARDUINO_BOARD
#else
  #ifndef BOARD_NAME
    #define BOARD_NAME    BOARD_TYPE
  #endif
#endif

// Just select one to be true. If all is false, default is Ethernet. 
// If more than one are true, the priority is USE_NATIVE_ETHERNET, USE_ETHERNET_GENERIC, USE_ETHERNET_ENC, USE_UIP_ETHERNET
#define USE_ETHERNET_GENERIC          true
#define USE_ETHERNET_LARGE            false
#define USE_ETHERNET_ENC              false
#define USE_UIP_ETHERNET              false
#define USE_NATIVE_ETHERNET           false

#if ( defined(__IMXRT1062__) && defined(ARDUINO_TEENSY41) && USE_NATIVE_ETHERNET )
  // Also default to Ethernet library
  #include <NativeEthernet.h>
  #define ETHERNET_TYPE               "Teensy 4.1 NativeEthernet Library"
#elif USE_ETHERNET_GENERIC
  // Also default to Ethernet_Generic library
  #include <Ethernet_Generic.h>
  #define ETHERNET_TYPE               "W5x00 and Ethernet_Generic Library"
#elif USE_ETHERNET_ENC
  #include <EthernetENC.h>
  #define ETHERNET_TYPE               "ENC28J60 and EthernetENC Library"  
#elif USE_UIP_ETHERNET
  #include <UIPEthernet.h>
  #include <utility/logging.h> 
  #define ETHERNET_TYPE               "ENC28J60 and UIPEthernet Library" 
#else
  // Default to Ethernet_Generic library
  #include <Ethernet_Generic.h>
  #define ETHERNET_TYPE               "W5x00 and Ethernet_Generic Library"
#endif

#ifndef USE_THIS_SS_PIN
  #define USE_THIS_SS_PIN   10    // For other boards
#endif

#define DEBUG_WEBSOCKETS_PORT     Serial
// Debug Level from 0 to 4
#define _WEBSOCKETS_LOGLEVEL_     2

#if USE_ETHERNET_GENERIC
  // Change to true if using old Ethernet card with built-in SD
  #define ETHERNET_WITH_SD_CARD   false
#endif

#if (defined(ETHERNET_WITH_SD_CARD) && ETHERNET_WITH_SD_CARD)
  #define W5100_CS        10
  #define SDCARD_CS       4
#endif

// Enter a MAC address and IP address for your controller below.
#define NUMBER_OF_MAC      20

byte mac[][NUMBER_OF_MAC] =
{
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x01 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x02 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x03 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x04 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x05 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x06 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x07 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x08 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x09 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0A },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0B },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0C },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0D },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0E },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0F },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x10 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x11 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x12 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x13 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x14 },
};

#endif      //defines_h
