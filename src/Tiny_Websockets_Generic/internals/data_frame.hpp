/****************************************************************************************************************************
  data_frame.hpp
  For WebSockets2_Generic Library
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52, SAMD21/SAMD51, SAM DUE, Teensy, RP2040 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
  Version: 1.8.1

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/07/2020 Initial coding/porting to support nRF52 and SAMD21/SAMD51 boards. Add SINRIC/Alexa support
  1.0.1   K Hoang      16/07/2020 Add support to Ethernet W5x00 to nRF52, SAMD21/SAMD51 and SAM DUE boards
  1.0.2   K Hoang      18/07/2020 Add support to Ethernet ENC28J60 to nRF52, SAMD21/SAMD51 and SAM DUE boards
  1.0.3   K Hoang      18/07/2020 Add support to STM32F boards using Ethernet W5x00, ENC28J60 and LAN8742A 
  1.0.4   K Hoang      27/07/2020 Add support to STM32F/L/H/G/WB/MP1 and Seeeduino SAMD21/SAMD51 using 
                                  Ethernet W5x00, ENC28J60, LAN8742A and WiFiNINA. Add examples and Packages' Patches.
  1.0.5   K Hoang      29/07/2020 Sync with ArduinoWebsockets v0.4.18 to fix ESP8266 SSL bug.
  1.0.6   K Hoang      06/08/2020 Add non-blocking WebSocketsServer feature and non-blocking examples.       
  1.0.7   K Hoang      03/10/2020 Add support to Ethernet ENC28J60 using EthernetENC and UIPEthernet v2.0.9
  1.1.0   K Hoang      08/12/2020 Add support to Teensy 4.1 using NativeEthernet  
  1.2.0   K Hoang      16/04/2021 Add limited support (client only) to ESP32-S2 and LAN8720 for STM32F4/F7
  1.2.1   K Hoang      16/04/2021 Add support to new ESP32-S2 boards. Restore Websocket Server function for ESP32-S2.
  1.2.2   K Hoang      16/04/2021 Add support to ESP32-C3
  1.2.3   K Hoang      02/05/2021 Update CA Certs and Fingerprint for EP32 and ESP8266 secured exampled.
  1.2.4   K Hoang      05/05/2021 Add InSecure mode for ESP32 and examples for ESP32/ESP8266
  1.3.0   K Hoang      20/05/2021 Add support to WiFi101
  1.4.0   K Hoang      25/05/2021 Add support to RP2040-based boards using Arduino-pico and Arduino mbed_rp2040 core
  1.5.0   K Hoang      08/07/2021 Add support to WT32_ETH01 (ESP32 + LAN8720) boards
  1.6.0   K Hoang      06/09/2021 Add support to QNEthernet Library for Teensy 4.1
  1.7.0   K Hoang      18/09/2021 Add support to Portenta_H7, using either WiFi or Vision-shield Ethernet
  1.8.0   K Hoang      03/10/2021 Add support to RP2040, using WiFiNINA, such as Nano_RP2040_Connect
  1.8.1   K Hoang      12/10/2021 Update `platform.ini` and `library.json`
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
