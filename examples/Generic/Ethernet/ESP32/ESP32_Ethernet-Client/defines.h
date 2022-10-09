/****************************************************************************************************************************
  defines.h
  For ESP32 with Ethernet module/shield.
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1,nRF52, RP2040 and SAMD21/SAMD51 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#if ( defined(ESP32) )
  #if defined(WEBSOCKETS_ETHERNET_USE_ESP32)
    #undef WEBSOCKETS_ETHERNET_USE_ESP32
  #endif
  #define WEBSOCKETS_USE_ETHERNET             true
  #define WEBSOCKETS_ETHERNET_USE_ESP32       true
  
  #if defined(ETHERNET_USE_ESP32)
    #undef ETHERNET_USE_ESP32
  #endif
  #define ETHERNET_USE_ESP32      true
  
  //#define SS_PIN_DEFAULT        USE_THIS_SS_PIN

  // For ESP32
  #warning Use ESP32 architecture
  
#else
  #error This code is intended to run only on the ESP32 boards ! Please check your Tools->Board setting.
#endif

#if defined(ARDUINO_BOARD)
  #define BOARD_NAME    ARDUINO_BOARD
#endif

// Just select one to be true. If all is false, default is Ethernet_Generic. 
// If more than one are true, the priority is USE_ETHERNET_GENERIC, USE_ETHERNET_ENC, USE_UIP_ETHERNET
#define USE_ETHERNET_GENERIC          true
#define USE_ETHERNET_ENC              false
#define USE_UIP_ETHERNET              false

#if USE_ETHERNET_GENERIC

  #include <soc/spi_pins.h>
    
  // Optional SPI2
  //#define USING_SPI2                          true
  
  #if USING_SPI2
    #define PIN_MISO          HSPI_IOMUX_PIN_NUM_MISO
    #define PIN_MOSI          HSPI_IOMUX_PIN_NUM_MOSI
    #define PIN_SCK           HSPI_IOMUX_PIN_NUM_CLK
    #define PIN_SS            HSPI_IOMUX_PIN_NUM_CS
  
    #define SHIELD_TYPE       "W5x00 using Ethernet_Generic Library on SPI2"
    
  #else
  
    #define PIN_MISO          MISO
    #define PIN_MOSI          MOSI
    #define PIN_SCK           SCK
    #define PIN_SS            SS
  
    #define SHIELD_TYPE       "W5x00 using Ethernet_Generic Library on SPI"
    
  #endif
  
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

#define DEBUG_WEBSOCKETS_PORT     Serial
// Debug Level from 0 to 4
#define _WEBSOCKETS_LOGLEVEL_     4

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
