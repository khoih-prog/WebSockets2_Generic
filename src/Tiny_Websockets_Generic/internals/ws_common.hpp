/****************************************************************************************************************************
  ws_common.hpp
  For WebSockets2_Generic Library
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
  Version: 1.0.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/07/2020 Initial coding/porting to support nRF52 and SAMD21/SAMD51 boards. Add SINRIC/Alexa support       
 *****************************************************************************************************************************/
 
#pragma once

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
}   // namespace websockets 2_generic

#ifdef ESP8266
  #define PLATFORM_DOES_NOT_SUPPORT_BLOCKING_READ
  
  #include <Tiny_Websockets_Generic/network/esp8266/esp8266_tcp.hpp>
  #define WSDefaultTcpClient websockets2_generic::network2_generic::Esp8266TcpClient
  #define WSDefaultTcpServer websockets2_generic::network2_generic::Esp8266TcpServer
  
  #ifndef _WS_CONFIG_NO_SSL
  // OpenSSL Dependent
  #define WSDefaultSecuredTcpClient websockets2_generic::network2_generic::SecuredEsp8266TcpClient
  #endif //_WS_CONFIG_NO_SSL

#elif defined(ESP32)

  #define PLATFORM_DOES_NOT_SUPPORT_BLOCKING_READ
  
  #include <Tiny_Websockets_Generic/network/esp32/esp32_tcp.hpp>
  #define WSDefaultTcpClient websockets2_generic::network2_generic::Esp32TcpClient
  #define WSDefaultTcpServer websockets2_generic::network2_generic::Esp32TcpServer
  
  #ifndef _WS_CONFIG_NO_SSL
  // OpenSSL Dependent
  #define WSDefaultSecuredTcpClient websockets2_generic::network2_generic::SecuredEsp32TcpClient
  #endif //_WS_CONFIG_NO_SSL
  
#elif    ( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
      || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) \
      || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) || defined(ARDUINO_SAMD_MKRVIDOR4000) || defined(__SAMD21G18A__) \
      || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) || defined(__SAMD21E18A__) || defined(__SAMD51__) || defined(__SAMD51J20A__) || defined(__SAMD51J19A__) \
      || defined(__SAMD51G19A__) || defined(__SAMD21G18A__) )
      
  #define PLATFORM_DOES_NOT_SUPPORT_BLOCKING_READ
  
  #include <Tiny_Websockets_Generic/network/SAMD_WiFiNINA/SAMD_WiFiNINA_tcp.hpp>
  #define WSDefaultTcpClient websockets2_generic::network2_generic::WiFiNINATcpClient
  #define WSDefaultTcpServer websockets2_generic::network2_generic::WiFiNINATcpServer
  
  #ifndef _WS_CONFIG_NO_SSL
  // OpenSSL Dependent
  #define WSDefaultSecuredTcpClient websockets2_generic::network2_generic::SecuredWiFiNINATcpClient
  #endif //_WS_CONFIG_NO_SSL      

#elif ( defined(NRF52840_FEATHER) || defined(NRF52832_FEATHER) || defined(NRF52_SERIES) || defined(ARDUINO_NRF52_ADAFRUIT) || \
      defined(NRF52840_FEATHER_SENSE) || defined(NRF52840_ITSYBITSY) || defined(NRF52840_CIRCUITPLAY) || defined(NRF52840_CLUE) || \
      defined(NRF52840_METRO) || defined(NRF52840_PCA10056) || defined(PARTICLE_XENON) || defined(NINA_B302_ublox) || defined(NINA_B112_ublox) )
  
  #define PLATFORM_DOES_NOT_SUPPORT_BLOCKING_READ
  
  #include <Tiny_Websockets_Generic/network/nRF52_WiFiNINA/nRF52_WiFiNINA_tcp.hpp>
  #define WSDefaultTcpClient websockets2_generic::network2_generic::WiFiNINATcpClient
  #define WSDefaultTcpServer websockets2_generic::network2_generic::WiFiNINATcpServer
  
  #ifndef _WS_CONFIG_NO_SSL
  // OpenSSL Dependent
  #define WSDefaultSecuredTcpClient websockets2_generic::network2_generic::SecuredWiFiNINATcpClient
  #endif //_WS_CONFIG_NO_SSL   
        
#endif
