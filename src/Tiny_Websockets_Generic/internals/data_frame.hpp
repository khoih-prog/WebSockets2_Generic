/****************************************************************************************************************************
  data_frame.hpp
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

#include <Tiny_Websockets_Generic/internals/ws_common.hpp>

namespace websockets2_generic
{
  namespace internals2_generic
  {
    enum ContentType 
    {
      // None as error value
      None = -1,
      // Default value for empty messages
      Continuation = 0x0,
    
      // Data opcdoes
      Text = 0x1,
      Binary = 0x2,
    
      // Control opcodes
      Close = 0x8,
      Ping = 0x9,
      Pong = 0xA
    };
    
    struct WebsocketsFrame 
    {
      uint8_t fin : 1;
      uint8_t opcode : 4;
      uint8_t mask : 1;
      uint8_t mask_buf[4];
      uint64_t payload_length;
      WSString payload;
    
      bool isControlFrame() 
      {
        return fin && (opcode == 0x8 || opcode == 0x9 || opcode == 0xA);
      }
    
      bool isEmpty() 
      {
        return (fin == 0) && (opcode == 0) && (payload_length == 0);
      }
    
      bool isBeginningOfFragmentsStream() const 
      {
        return (fin == 0) && (opcode != 0);
      }
    
      bool isContinuesFragment() const 
      {
        return (fin == 0) && (opcode == 0);
      }
    
      bool isEndOfFragmentsStream() const 
      {
        return (fin == 1) && (opcode == 0);
      }
    
      bool isNormalUnfragmentedMessage() const 
      {
        return (fin == 1) && (opcode != 0);
      }
    };
    
    template <class HeaderTy> HeaderTy MakeHeader(size_t len, uint8_t opcode, bool fin, bool mask) 
    {
      HeaderTy header;
      header.fin = fin;
      header.flags = 0;
      header.opcode = opcode;
      header.mask = mask ? 1 : 0;
    
      // set payload
      if (len < 126) 
      {
        header.payload = len;
      } 
      else if (len < 65536) 
      {
        header.payload = 126;
      } 
      else 
      {
        header.payload = 127;
      }
    
      return header;
    }
    
    struct Header 
    {
      uint8_t opcode : 4;
      uint8_t flags : 3;
      uint8_t fin : 1;
      uint8_t payload : 7;
      uint8_t mask : 1;
    };
    
    struct HeaderWithExtended16 : Header 
    {      
      uint16_t extendedPayload;
    };
    
    struct HeaderWithExtended64 : Header 
    {
      uint64_t extendedPayload;
    };
  }     // namespace internals2_generic
}       // namespace websockets2_generic
