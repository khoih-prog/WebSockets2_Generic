/****************************************************************************************************************************
  WebSockets2_Generic_Crypto.hpp
  For WebSockets2_Generic Library
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32


  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
  Version: 1.0.7

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
 *****************************************************************************************************************************/

#ifndef _WEBSOCKETS2_GENERIC_CRYPTO_H
#define _WEBSOCKETS2_GENERIC_CRYPTO_H

#pragma once

// KH
#include <WebSockets2_Generic.h>
 
#include <Tiny_Websockets_Generic/internals/wscrypto/crypto.hpp>
#include <Tiny_Websockets_Generic/internals/wscrypto/base64.hpp>
#include <Tiny_Websockets_Generic/internals/wscrypto/sha1.hpp>

#ifndef _WS_CONFIG_NO_TRUE_RANDOMNESS
#include <time.h>
#endif

namespace websockets2_generic
{
  namespace crypto2_generic
  {
    WSString base64Encode(WSString data)
    {
      return internals2_generic::base64_encode(reinterpret_cast<const uint8_t*>(data.c_str()), data.size());
    }
    
    WSString base64Encode(uint8_t* data, size_t len)
    {
      return internals2_generic::base64_encode(reinterpret_cast<const uint8_t*>(data), len);
    }
    
    WSString base64Decode(WSString data)
    {
      return internals2_generic::base64_decode(data);
    }
    
    WSString websocketsHandshakeEncodeKey(WSString key)
    {
      char base64[30];
      internals2_generic::sha1(key.c_str())
      .add("258EAFA5-E914-47DA-95CA-C5AB0DC85B11")
      .finalize()
      .print_base64(base64);
    
      return WSString(base64);
    }
    
    #ifdef _WS_CONFIG_NO_TRUE_RANDOMNESS
    WSString randomBytes(size_t len)
    {
      WSString result;
      result.reserve(len);
    
      for (size_t i = 0; i < len; i++)
      {
        result += "0123456789abcdef"[i % 16];
      }
    
      return result;
    }
    #else
    WSString randomBytes(size_t len)
    {
      static int onlyOnce = []()
      {
        srand(time(NULL));
        return 0;
      }();
    
      WSString result;
      result.reserve(len);
    
      for (size_t i = onlyOnce; i < len; i++)
      {
        result += "0123456789abcdefABCDEFGHIJKLMNOPQRSTUVEXYZ"[rand() % 42];
      }
    
      return result;
    }
    #endif
  }   // namespace crypto2_generic
}     // namespace websockets2_generic

#endif    // _WEBSOCKETS2_GENERIC_CRYPTO_H
