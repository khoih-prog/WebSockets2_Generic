/****************************************************************************************************************************
  WebSockets2_Generic_Debug.h
  For WebSockets2_Generic Library

  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52, SAMD21/SAMD51, SAM DUE, Teensy, RP2040 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).

  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license

  Version: 1.13.2

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/07/2020 Initial coding/porting to support nRF52 and SAMD21/SAMD51 boards. Add SINRIC/Alexa support
  ...
  1.9.0   K Hoang      30/11/2021 Auto detect ESP32 core version. Fix bug in examples
  1.9.1   K Hoang      17/12/2021 Fix QNEthernet TCP interface
  1.10.0  K Hoang      18/12/2021 Supporting case-insensitive headers, according to RFC2616
  1.10.1  K Hoang      26/02/2022 Reduce QNEthernet latency
  1.10.2  K Hoang      14/03/2022 Fix bug when using QNEthernet staticIP. Add staticIP option to NativeEthernet
  1.10.3  K Hoang      11/04/2022 Use Ethernet_Generic library as default. Support SPI1/SPI2 for RP2040
  1.11.0  K Hoang      08/10/2022 Add support to ESP32 using W5x00 Ethernet
  1.12.0  K Hoang      09/10/2022 Add support to ENC28J60 using EthernetENC or UIPEthernet for all supported boards
  1.12.1  K Hoang      09/10/2022 Fix bug in examples
  1.13.0  K Hoang      11/10/2022 Add support to RP2040W using CYW43439 WiFi
  1.13.1  K Hoang      24/11/2022 Using new WiFi101_Generic library
  1.13.2  K Hoang      06/12/2022 Fix compiler error using QNEthernet v0.17.0
 *****************************************************************************************************************************/

#ifndef WebSockets2_Generic_Debug_h
#define WebSockets2_Generic_Debug_h

#pragma once

#include <stdio.h>

/////////////////////////////////////////////////////

#ifdef DEBUG_WEBSOCKETS_PORT
  #define WS_DBG_PORT      DEBUG_WEBSOCKETS_PORT
#else
  #define WS_DBG_PORT      Serial
#endif

/////////////////////////////////////////////////////

// Change _WEBSOCKETS_LOGLEVEL_ to set tracing and logging verbosity
// 0: DISABLED: no logging
// 1: ERROR: errors
// 2: WARN: errors and warnings
// 3: INFO: errors, warnings and informational (default)
// 4: DEBUG: errors, warnings, informational and debug

#ifndef _WEBSOCKETS_LOGLEVEL_
  #define _WEBSOCKETS_LOGLEVEL_       1
#endif

///////////////////////////////////////

const char WS_MARK[]  = "[WS] ";
const char WS_SPACE[] = " ";

#define WS_PRINT        WS_DBG_PORT.print
#define WS_PRINTLN      WS_DBG_PORT.println

#define WS_PRINT_MARK   WS_PRINT(WS_MARK)
#define WS_PRINT_SP     WS_PRINT(WS_SPACE)
#define WS_PRINT_LINE   WS_PRINT(WS_LINE)

///////////////////////////////////////

#define LOGERROR(x)         if(_WEBSOCKETS_LOGLEVEL_>0) { WS_PRINT_MARK; WS_PRINTLN(x); }
#define LOGERROR0(x)        if(_WEBSOCKETS_LOGLEVEL_>0) { WS_PRINT(x); }
#define LOGERROR1(x,y)      if(_WEBSOCKETS_LOGLEVEL_>0) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINT_SP; WS_PRINTLN(y); }
#define LOGERROR2(x,y,z)    if(_WEBSOCKETS_LOGLEVEL_>0) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINT_SP; WS_PRINT(y); WS_PRINT_SP; WS_PRINTLN(z); }
#define LOGERROR3(x,y,z,w)  if(_WEBSOCKETS_LOGLEVEL_>0) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINT_SP; WS_PRINT(y); WS_PRINT_SP; WS_PRINT(z); WS_PRINT_SP; WS_PRINTLN(w); }
///////////////////////////////////////

#define LOGWARN(x)        if(_WEBSOCKETS_LOGLEVEL_>1) { WS_PRINT_MARK; WS_PRINTLN(x); }
#define LOGWARN0(x)       if(_WEBSOCKETS_LOGLEVEL_>1) { WS_PRINT(x); }
#define LOGWARN1(x,y)     if(_WEBSOCKETS_LOGLEVEL_>1) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINT_SP; WS_PRINTLN(y); }
#define LOGWARN2(x,y,z)   if(_WEBSOCKETS_LOGLEVEL_>1) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINT_SP; WS_PRINT(y); WS_PRINT_SP; WS_PRINTLN(z); }
#define LOGWARN3(x,y,z,w) if(_WEBSOCKETS_LOGLEVEL_>1) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINT_SP; WS_PRINT(y); WS_PRINT_SP; WS_PRINT(z); WS_PRINT_SP; WS_PRINTLN(w); }
///////////////////////////////////////

#define LOGINFO(x)        if(_WEBSOCKETS_LOGLEVEL_>2) { WS_PRINT_MARK; WS_PRINTLN(x); }
#define LOGINFO0(x)       if(_WEBSOCKETS_LOGLEVEL_>2) { WS_PRINT(x); }
#define LOGINFO1(x,y)     if(_WEBSOCKETS_LOGLEVEL_>2) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINT_SP; WS_PRINTLN(y); }
#define LOGINFO2(x,y,z)   if(_WEBSOCKETS_LOGLEVEL_>2) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINT_SP; WS_PRINT(y); WS_PRINT_SP; WS_PRINTLN(z); }
#define LOGINFO3(x,y,z,w) if(_WEBSOCKETS_LOGLEVEL_>2) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINT_SP; WS_PRINT(y); WS_PRINT_SP; WS_PRINT(z); WS_PRINT_SP; WS_PRINTLN(w); }

///////////////////////////////////////

#define LOGDEBUG(x)         if(_WEBSOCKETS_LOGLEVEL_>3) { WS_PRINT_MARK; WS_PRINTLN(x); }
#define LOGDEBUG0(x)        if(_WEBSOCKETS_LOGLEVEL_>3) { WS_PRINT(x); }
#define LOGDEBUG1(x,y)      if(_WEBSOCKETS_LOGLEVEL_>3) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINT_SP; WS_PRINTLN(y); }
#define LOGDEBUG2(x,y,z)    if(_WEBSOCKETS_LOGLEVEL_>3) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINT_SP; WS_PRINT(y); WS_PRINT_SP; WS_PRINTLN(z); }
#define LOGDEBUG3(x,y,z,w)  if(_WEBSOCKETS_LOGLEVEL_>3) { WS_PRINT_MARK; WS_PRINT(x); WS_PRINT_SP; WS_PRINT(y); WS_PRINT_SP; WS_PRINT(z); WS_PRINT_SP; WS_PRINTLN(w); }

///////////////////////////////////////

#endif    //WebSockets2_Generic_Debug_h
