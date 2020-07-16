/****************************************************************************************************************************
  defines.h for SAMD-Ethernet-Client_SINRIC.ino
  For SAMD21/SAMD51 with WiFiNINA module/shield, using SINRIC (https://sinric.com/)
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
  Version: 1.0.1

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/07/2020 Initial coding/porting to support nRF52 and SAMD21/SAMD51 boards. Add SINRIC/Alexa support
  1.0.1   K Hoang      16/07/2020 Add support to Ethernet W5x00 to nRF52 and SAMD21/SAMD51 boards      
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#if    ( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
      || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) \
      || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) || defined(ARDUINO_SAMD_MKRVIDOR4000) || defined(__SAMD21G18A__) \
      || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) || defined(__SAMD21E18A__) || defined(__SAMD51__) || defined(__SAMD51J20A__) || defined(__SAMD51J19A__) \
      || defined(__SAMD51G19A__) || defined(__SAMD21G18A__) )
#if defined(WEBSOCKETS_ETHERNET_USE_SAMD)
#undef WEBSOCKETS_ETHERNET_USE_SAMD
#endif
#define WEBSOCKETS_USE_ETHERNET           true
#define WEBSOCKETS_ETHERNET_USE_SAMD      true
#else
#error This code is intended to run only on the SAMD boards ! Please check your Tools->Board setting.
#endif

#if defined(WEBSOCKETS_ETHERNET_USE_SAMD)

#if defined(ARDUINO_SAMD_ZERO)
#define BOARD_TYPE      "SAMD Zero"
#elif defined(ARDUINO_SAMD_MKR1000)
#define BOARD_TYPE      "SAMD MKR1000"
#elif defined(ARDUINO_SAMD_MKRWIFI1010)
#define BOARD_TYPE      "SAMD MKRWIFI1010"
#elif defined(ARDUINO_SAMD_NANO_33_IOT)
#define BOARD_TYPE      "SAMD NANO_33_IOT"
#elif defined(ARDUINO_SAMD_MKRFox1200)
#define BOARD_TYPE      "SAMD MKRFox1200"
#elif ( defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) )
#define BOARD_TYPE      "SAMD MKRWAN13X0"
#elif defined(ARDUINO_SAMD_MKRGSM1400)
#define BOARD_TYPE      "SAMD MKRGSM1400"
#elif defined(ARDUINO_SAMD_MKRNB1500)
#define BOARD_TYPE      "SAMD MKRNB1500"
#elif defined(ARDUINO_SAMD_MKRVIDOR4000)
#define BOARD_TYPE      "SAMD MKRVIDOR4000"
#elif defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS)
#define BOARD_TYPE      "SAMD ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS"
#elif defined(ADAFRUIT_ITSYBITSY_M4_EXPRESS)
#define BOARD_TYPE      "SAMD ADAFRUIT_ITSYBITSY_M4_EXPRESS"
#elif defined(__SAMD21E18A__)
#define BOARD_TYPE      "SAMD21E18A"
#elif defined(__SAMD21G18A__)
#define BOARD_TYPE      "SAMD21G18A"
#elif defined(__SAMD51G19A__)
#define BOARD_TYPE      "SAMD51G19A"
#elif defined(__SAMD51J19A__)
#define BOARD_TYPE      "SAMD51J19A"
#elif defined(__SAMD51J20A__)
#define BOARD_TYPE      "SAMD51J20A"
#elif defined(__SAM3X8E__)
#define BOARD_TYPE      "SAM3X8E"
#elif defined(__CPU_ARC__)
#define BOARD_TYPE      "CPU_ARC"
#elif defined(__SAMD51__)
#define BOARD_TYPE      "SAMD51"
#else
#define BOARD_TYPE      "SAMD Unknown"
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

#define SINRIC_WEBSERVER          "iot.sinric.com"
#define SINRIC_WEBSERVER_PORT     80
#define SINRIC_API_KEY            "11111111-2222-3333-4444-555555555555"

#define SINRIC_Device_ID_1        "012345678901234567890123"   // Device ID, got from Sinric

const char* websockets_server_host    = SINRIC_WEBSERVER; //Enter server address
const uint16_t websockets_server_port = SINRIC_WEBSERVER_PORT; // Enter server port

#ifdef LED_BUILTIN
#define LED_PIN     LED_BUILTIN
#else
#define LED_PIN     13
#endif

uint8_t mac[6] =  { 0xDE, 0xAD, 0xBE, 0xEF, 0xAD, 0x02 };

// Select the IP address according to your local network
IPAddress clientIP(192, 168, 2, 225);

#define SDCARD_CS       4

#endif      //defines_h
