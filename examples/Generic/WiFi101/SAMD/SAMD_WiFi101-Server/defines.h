/****************************************************************************************************************************
  defines.h for SAMD_WiFi101-Client.ino
  For SAMD21/SAMD51 with WiFi101 module/shield.

  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).

  Example first created on: 10.05.2018
  Original Author: Markus Sattler

  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#if    ( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
      || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) \
      || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) || defined(ARDUINO_SAMD_MKRVIDOR4000) || defined(__SAMD21G18A__) \
      || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) || defined(__SAMD21E18A__) || defined(__SAMD51__) || defined(__SAMD51J20A__) || defined(__SAMD51J19A__) \
      || defined(__SAMD51G19A__) || defined(__SAMD51P19A__) || defined(__SAMD21G18A__) )
#if defined(WEBSOCKETS_WIFI101_USE_SAMD)
  #undef WEBSOCKETS_WIFI101_USE_SAMD
#endif
#define WEBSOCKETS_USE_WIFI101           true
#define WEBSOCKETS_WIFI101_USE_SAMD      true
#warning Using WiFi101_Generic Library for MKR1000 and MKRWIFI1010
#else
#error This code is intended to run only on the SAMD boards using WiFi101_Generic! Please check your Tools->Board setting.
#endif

#if defined(WEBSOCKETS_WIFI101_USE_SAMD)

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
  #elif defined(ADAFRUIT_FEATHER_M0_EXPRESS)
    #define BOARD_TYPE      "SAMD21 ADAFRUIT_FEATHER_M0_EXPRESS"
  #elif defined(ADAFRUIT_METRO_M0_EXPRESS)
    #define BOARD_TYPE      "SAMD21 ADAFRUIT_METRO_M0_EXPRESS"
  #elif defined(ADAFRUIT_CIRCUITPLAYGROUND_M0)
    #define BOARD_TYPE      "SAMD21 ADAFRUIT_CIRCUITPLAYGROUND_M0"
  #elif defined(ADAFRUIT_GEMMA_M0)
    #define BOARD_TYPE      "SAMD21 ADAFRUIT_GEMMA_M0"
  #elif defined(ADAFRUIT_TRINKET_M0)
    #define BOARD_TYPE      "SAMD21 ADAFRUIT_TRINKET_M0"
  #elif defined(ADAFRUIT_ITSYBITSY_M0)
    #define BOARD_TYPE      "SAMD21 ADAFRUIT_ITSYBITSY_M0"
  #elif defined(ARDUINO_SAMD_HALLOWING_M0)
    #define BOARD_TYPE      "SAMD21 ARDUINO_SAMD_HALLOWING_M0"
  #elif defined(ADAFRUIT_METRO_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_METRO_M4_EXPRESS"
  #elif defined(ADAFRUIT_GRAND_CENTRAL_M4)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_GRAND_CENTRAL_M4"
  #elif defined(ADAFRUIT_FEATHER_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_FEATHER_M4_EXPRESS"
  #elif defined(ADAFRUIT_ITSYBITSY_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_ITSYBITSY_M4_EXPRESS"
  #elif defined(ADAFRUIT_TRELLIS_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_TRELLIS_M4_EXPRESS"
  #elif defined(ADAFRUIT_PYPORTAL)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_PYPORTAL"
  #elif defined(ADAFRUIT_PYPORTAL_M4_TITANO)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_PYPORTAL_M4_TITANO"
  #elif defined(ADAFRUIT_PYBADGE_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_PYBADGE_M4_EXPRESS"
  #elif defined(ADAFRUIT_METRO_M4_AIRLIFT_LITE)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_METRO_M4_AIRLIFT_LITE"
  #elif defined(ADAFRUIT_PYGAMER_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_PYGAMER_M4_EXPRESS"
  #elif defined(ADAFRUIT_PYGAMER_ADVANCE_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_PYGAMER_ADVANCE_M4_EXPRESS"
  #elif defined(ADAFRUIT_PYBADGE_AIRLIFT_M4)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_PYBADGE_AIRLIFT_M4"
  #elif defined(ADAFRUIT_MONSTER_M4SK_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_MONSTER_M4SK_EXPRESS"
  #elif defined(ADAFRUIT_HALLOWING_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_HALLOWING_M4_EXPRESS"
  #elif defined(SEEED_WIO_TERMINAL)
    #define BOARD_TYPE      "SAMD SEEED_WIO_TERMINAL"
  #elif defined(SEEED_FEMTO_M0)
    #define BOARD_TYPE      "SAMD SEEED_FEMTO_M0"
  #elif defined(SEEED_XIAO_M0)
    #define BOARD_TYPE      "SAMD SEEED_XIAO_M0"
  #elif defined(Wio_Lite_MG126)
    #define BOARD_TYPE      "SAMD SEEED Wio_Lite_MG126"
  #elif defined(WIO_GPS_BOARD)
    #define BOARD_TYPE      "SAMD SEEED WIO_GPS_BOARD"
  #elif defined(SEEEDUINO_ZERO)
    #define BOARD_TYPE      "SAMD SEEEDUINO_ZERO"
  #elif defined(SEEEDUINO_LORAWAN)
    #define BOARD_TYPE      "SAMD SEEEDUINO_LORAWAN"
  #elif defined(SEEED_GROVE_UI_WIRELESS)
    #define BOARD_TYPE      "SAMD SEEED_GROVE_UI_WIRELESS"
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

#ifndef BOARD_NAME
  #define BOARD_NAME    BOARD_TYPE
#endif

#define USE_WIFI101       true

#include <SPI.h>
#include <WiFi101_Generic.h>
#include <driver/source/nmasic.h>

#define DEBUG_WEBSOCKETS_PORT     Serial
// Debug Level from 0 to 4
#define _WEBSOCKETS_LOGLEVEL_     3

const char* ssid = "ssid"; //Enter SSID
const char* password = "password"; //Enter Password

const char* websockets_server_host = "192.168.2.95"; //Enter server address
//const char* websockets_server_host = "serverip_or_name"; //Enter server address

const uint16_t websockets_server_port = 8080; // Enter server port

// Select the static IP address according to your local network
IPAddress clientIP(192, 168, 2, 223);

// Select the IP address according to your local network
IPAddress serverIP(192, 168, 2, 95);

#define WEBSOCKETS_PORT     8080

#endif      //defines_h
