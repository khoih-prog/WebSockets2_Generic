/****************************************************************************************************************************
  ws_common_EthernetENC.hpp
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
}     // namespace websockets 2_generic

#if    ( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
      || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) \
      || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) || defined(ARDUINO_SAMD_MKRVIDOR4000) || defined(__SAMD21G18A__) \
      || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) || defined(__SAMD21E18A__) || defined(__SAMD51__) || defined(__SAMD51J20A__) || defined(__SAMD51J19A__) \
      || defined(__SAMD51G19A__) || defined(__SAMD51P19A__) || defined(__SAMD21G18A__) )
         
    // Using Ethernet ENC28J60
    #warning Using EthernetENC for SAMD in ws_common_EthernetENC.hpp
    
    #define PLATFORM_DOES_NOT_SUPPORT_BLOCKING_READ
    #define _WS_CONFIG_NO_SSL   true
    
    #include <Tiny_Websockets_Generic/network/SAMD_EthernetENC/SAMD_EthernetENC_tcp.hpp>
    #define WSDefaultTcpClient websockets2_generic::network2_generic::EthernetTcpClient
    #define WSDefaultTcpServer websockets2_generic::network2_generic::EthernetTcpServer
    
    #ifndef _WS_CONFIG_NO_SSL
    // OpenSSL Dependent
    #define WSDefaultSecuredTcpClient websockets2_generic::network2_generic::SecuredEthernetTcpClient
    #endif //_WS_CONFIG_NO_SSL
    
#elif ( defined(NRF52840_FEATHER) || defined(NRF52832_FEATHER) || defined(NRF52_SERIES) || defined(ARDUINO_NRF52_ADAFRUIT) || \
    defined(NRF52840_FEATHER_SENSE) || defined(NRF52840_ITSYBITSY) || defined(NRF52840_CIRCUITPLAY) || defined(NRF52840_CLUE) || \
    defined(NRF52840_METRO) || defined(NRF52840_PCA10056) || defined(PARTICLE_XENON) || defined(NINA_B302_ublox) || defined(NINA_B112_ublox) )
 
  // Using Ethernet ENC28J60
  #warning Using EthernetENC for NRF52 in ws_common_EthernetENC.hpp
  
  #define PLATFORM_DOES_NOT_SUPPORT_BLOCKING_READ
  #define _WS_CONFIG_NO_SSL   true
  
  #include <Tiny_Websockets_Generic/network/nRF52_EthernetENC/nRF52_EthernetENC_tcp.hpp>
  #define WSDefaultTcpClient websockets2_generic::network2_generic::EthernetTcpClient
  #define WSDefaultTcpServer websockets2_generic::network2_generic::EthernetTcpServer
  
  #ifndef _WS_CONFIG_NO_SSL
  // OpenSSL Dependent
  #define WSDefaultSecuredTcpClient websockets2_generic::network2_generic::SecuredEthernetTcpClient
  #endif //_WS_CONFIG_NO_SSL      
  
  
#elif ( defined(ARDUINO_SAM_DUE) || defined(__SAM3X8E__) )

  // Using Ethernet ENC28J60
  #warning Using EthernetENC for SAM DUE in ws_common_EthernetENC.hpp
  
  #define PLATFORM_DOES_NOT_SUPPORT_BLOCKING_READ
  #define _WS_CONFIG_NO_SSL   true
  
  #include <Tiny_Websockets_Generic/network/DUE_EthernetENC/DUE_EthernetENC_tcp.hpp>
  #define WSDefaultTcpClient websockets2_generic::network2_generic::EthernetTcpClient
  #define WSDefaultTcpServer websockets2_generic::network2_generic::EthernetTcpServer
  
  #ifndef _WS_CONFIG_NO_SSL
  // OpenSSL Dependent
  #define WSDefaultSecuredTcpClient websockets2_generic::network2_generic::SecuredEthernetTcpClient
  #endif //_WS_CONFIG_NO_SSL    
  
#elif ( defined(STM32F0) || defined(STM32F1) || defined(STM32F2) || defined(STM32F3)  ||defined(STM32F4) || defined(STM32F7) || \
        defined(STM32L0) || defined(STM32L1) || defined(STM32L4) || defined(STM32H7)  ||defined(STM32G0) || defined(STM32G4) || \
        defined(STM32WB) || defined(STM32MP1) )

  // Using Ethernet ENC28J60
  #warning Using EthernetENC for STM32 in ws_common_EthernetENC.hpp
  
  #define PLATFORM_DOES_NOT_SUPPORT_BLOCKING_READ
  #define _WS_CONFIG_NO_SSL   true
  
  #include <Tiny_Websockets_Generic/network/STM32_EthernetENC/STM32_EthernetENC_tcp.hpp>
  #define WSDefaultTcpClient websockets2_generic::network2_generic::EthernetTcpClient
  #define WSDefaultTcpServer websockets2_generic::network2_generic::EthernetTcpServer
  
  #ifndef _WS_CONFIG_NO_SSL
  // OpenSSL Dependent
  #define WSDefaultSecuredTcpClient websockets2_generic::network2_generic::SecuredEthernetTcpClient
  #endif //_WS_CONFIG_NO_SSL   

#elif ( defined(CORE_TEENSY) || defined(__IMXRT1062__) || defined(ARDUINO_TEENSY41) || defined(ARDUINO_TEENSY40) || \
    defined(__MK66FX1M0__) || defined(__MK64FX512__) || defined(__MKL26Z64__) || defined(__MK20DX256__) || \
    defined(__MK20DX128__) )
  
  // Using Ethernet ENC28J60
  #warning Using EthernetENC for Teensy in ws_common_EthernetENC.hpp
  
  #define PLATFORM_DOES_NOT_SUPPORT_BLOCKING_READ
  #define _WS_CONFIG_NO_SSL   true
  
  #include <Tiny_Websockets_Generic/network/Teensy_EthernetENC/Teensy_EthernetENC_tcp.hpp>
  #define WSDefaultTcpClient websockets2_generic::network2_generic::EthernetTcpClient
  #define WSDefaultTcpServer websockets2_generic::network2_generic::EthernetTcpServer
  
  #ifndef _WS_CONFIG_NO_SSL
  // OpenSSL Dependent
  #define WSDefaultSecuredTcpClient websockets2_generic::network2_generic::SecuredEthernetTcpClient
  #endif //_WS_CONFIG_NO_SSL
    
#elif ( defined(ARDUINO_ARCH_RP2040) || defined(ARDUINO_RASPBERRY_PI_PICO) || defined(ARDUINO_ADAFRUIT_FEATHER_RP2040) || \
    defined(ARDUINO_GENERIC_RP2040) )    
  // Using Ethernet ENC28J60
  #warning Using EthernetENC for RP2040 in ws_common_EthernetENC.hpp
  
  #define PLATFORM_DOES_NOT_SUPPORT_BLOCKING_READ
  #define _WS_CONFIG_NO_SSL   true
  
  #include <Tiny_Websockets_Generic/network/RP2040_EthernetENC/RP2040_EthernetENC_tcp.hpp>
  #define WSDefaultTcpClient websockets2_generic::network2_generic::EthernetTcpClient
  #define WSDefaultTcpServer websockets2_generic::network2_generic::EthernetTcpServer
  
  #ifndef _WS_CONFIG_NO_SSL
  // OpenSSL Dependent
  #define WSDefaultSecuredTcpClient websockets2_generic::network2_generic::SecuredEthernetTcpClient
  #endif //_WS_CONFIG_NO_SSL 

#elif ( defined(ESP32) )
  // Using Ethernet W5x00
  #warning Using EthernetENC for ESP32 in ws_common_EthernetENC.hpp
  
  #define PLATFORM_DOES_NOT_SUPPORT_BLOCKING_READ
  #define _WS_CONFIG_NO_SSL   true
  
  #include <Tiny_Websockets_Generic/network/ESP32_EthernetENC/ESP32_EthernetENC_tcp.hpp>
  #define WSDefaultTcpClient websockets2_generic::network2_generic::EthernetTcpClient
  #define WSDefaultTcpServer websockets2_generic::network2_generic::EthernetTcpServer
  
  #ifndef _WS_CONFIG_NO_SSL
  // OpenSSL Dependent
  #define WSDefaultSecuredTcpClient websockets2_generic::network2_generic::SecuredEthernetTcpClient
  #endif //_WS_CONFIG_NO_SSL    
#endif  
