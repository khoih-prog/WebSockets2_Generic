/****************************************************************************************************************************
  server.hpp
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

#ifndef _SERVER_HPP_
#define _SERVER_HPP_

#pragma once

#include <Tiny_Websockets_Generic/client.hpp>
#include <functional>

// KH, from v1.0.1
#if WEBSOCKETS_USE_ETHERNET
  #if USE_UIP_ETHERNET
    // KH, from v1.0.2
    #warning WEBSOCKETS_USE_ETHERNET and USE_UIP_ETHERNET in server.hpp
    #include <Tiny_Websockets_Generic/internals/ws_common_UIPEthernet.hpp>
  #elif USE_LAN8742A_ETHERNET
    // KH, from v1.0.3
    #warning WEBSOCKETS_USE_ETHERNET and USE_LAN8742A_ETHERNET in server.hpp
    #include <Tiny_Websockets_Generic/internals/ws_common_LAN8742AEthernet.hpp>  
  #else
    #warning WEBSOCKETS_USE_ETHERNET in server.hpp
    #include <Tiny_Websockets_Generic/internals/ws_common_Ethernet_W5x00.hpp>
  #endif
#elif WEBSOCKETS_USE_WIFININA
  #warning WEBSOCKETS_USE_WIFININA in server.hpp
  #include <Tiny_Websockets_Generic/internals/ws_common_WiFiNINA.hpp>
#else
  #warning WEBSOCKETS_USE_ESP_WIFI in server.hpp
  #include <Tiny_Websockets_Generic/internals/ws_common.hpp>  
#endif
//////

namespace websockets2_generic
{
  class WebsocketsServer 
  {
    public:
      WebsocketsServer(network2_generic::TcpServer* server = new WSDefaultTcpServer);
  
      WebsocketsServer(const WebsocketsServer& other) = delete;
      WebsocketsServer(const WebsocketsServer&& other) = delete;
  
      WebsocketsServer& operator=(const WebsocketsServer& other) = delete;
      WebsocketsServer& operator=(const WebsocketsServer&& other) = delete;
  
      bool available();
      void listen(uint16_t port);
      bool poll();
      WebsocketsClient accept();
  
      virtual ~WebsocketsServer();
  
    private:
      network2_generic::TcpServer* _server;
  };
}     // namespace websockets2_generic

#endif    // _SERVER_HPP_
