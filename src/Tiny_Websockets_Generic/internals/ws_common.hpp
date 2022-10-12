/****************************************************************************************************************************
  ws_common.hpp
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

// KH
#include <WebSockets2_Generic.h>

#include <Tiny_Websockets_Generic/ws_config_defs.hpp>
#include <string>
#include <Arduino.h>

namespace websockets2_generic
{
  typedef std::string WSString;
  typedef String WSInterfaceString;
  
  namespace internals2_generic
  {
    WSString fromInterfaceString(const WSInterfaceString& str);
    WSString fromInterfaceString(const WSInterfaceString&& str);
    WSInterfaceString fromInternalString(const WSString& str);
    WSInterfaceString fromInternalString(const WSString&& str);
  }   // namespace internals2_generic 
}     // namespace websockets 2_generic

#ifdef ESP8266

  // Using ESP8266 WiFi
  #warning Using ESP8266 WiFi for ESP8266 in ws_common.hpp
    
  #define PLATFORM_DOES_NOT_SUPPORT_BLOCKING_READ
  
  #include <Tiny_Websockets_Generic/network/esp8266/esp8266_tcp.hpp>
  #define WSDefaultTcpClient websockets2_generic::network2_generic::Esp8266TcpClient
  #define WSDefaultTcpServer websockets2_generic::network2_generic::Esp8266TcpServer
  
  #ifndef _WS_CONFIG_NO_SSL
  // OpenSSL Dependent
  #define WSDefaultSecuredTcpClient websockets2_generic::network2_generic::SecuredEsp8266TcpClient
  #endif //_WS_CONFIG_NO_SSL

#elif defined(ESP32)

  #if !(WEBSOCKETS_USE_ETHERNET)

		// Using ESP32 WiFi
		#warning Using ESP32 WiFi for ESP32 in ws_common.hpp

		#define PLATFORM_DOES_NOT_SUPPORT_BLOCKING_READ
		
		#include <Tiny_Websockets_Generic/network/esp32/esp32_tcp.hpp>
		#define WSDefaultTcpClient websockets2_generic::network2_generic::Esp32TcpClient
		#define WSDefaultTcpServer websockets2_generic::network2_generic::Esp32TcpServer
		
		#ifndef _WS_CONFIG_NO_SSL
		  // OpenSSL Dependent
		  #define WSDefaultSecuredTcpClient websockets2_generic::network2_generic::SecuredEsp32TcpClient
		#endif //_WS_CONFIG_NO_SSL
  
  #endif
      
#endif    // ESP8266



