/****************************************************************************************************************************
  WebSockets2_Generic.h
  For WebSockets2_Generic Library
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52, SAMD21/SAMD51, SAM DUE, Teensy, RP2040 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
  
  Version: 1.13.0

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
 *****************************************************************************************************************************/

#pragma once

#ifndef _WEBSOCKETS2_GENERIC_H
#define _WEBSOCKETS2_GENERIC_H

/////////////////////////////////////////////////////

#define WEBSOCKETS2_GENERIC_VERSION     "WebSockets2_Generic v1.13.0"

#define WEBSOCKETS2_GENERIC_VERSION_MAJOR    1
#define WEBSOCKETS2_GENERIC_VERSION_MINOR    13
#define WEBSOCKETS2_GENERIC_VERSION_PATCH    0

#define WEBSOCKETS2_GENERIC_VERSION_INT      1013000

/////////////////////////////////////////////////////

#include "Tiny_Websockets_Generic/message.hpp"
#include "Tiny_Websockets_Generic/client.hpp"
#include "Tiny_Websockets_Generic/server.hpp"

/////////////////////////////////////////////////////

#include <WebSockets2_Generic_Client.hpp>
#include <WebSockets2_Generic_Server.hpp>
#include <WebSockets2_Generic_Message.hpp>
#include <WebSockets2_Generic_Crypto.hpp>
#include <WebSockets2_Generic_Endpoint.hpp>
#include <WebSockets2_Generic_Common.hpp>
//////

#endif //_WEBSOCKETS2_GENERIC_H
