/****************************************************************************************************************************
  WebSockets2_Generic_Server.hpp
  For WebSockets2_Generic Library
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52, SAMD21/SAMD51, SAM DUE, Teensy, RP2040 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
  Version: 1.10.0

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
  1.9.0   K Hoang      30/11/2021 Auto detect ESP32 core version. Fix bug in examples
  1.9.1   K Hoang      17/12/2021 Fix QNEthernet TCP interface
  1.10.0  K Hoang      18/12/2021 Supporting case-insensitive headers, according to RFC2616
 *****************************************************************************************************************************/

#ifndef _WEBSOCKETS2_GENERIC_SERVER_H
#define _WEBSOCKETS2_GENERIC_SERVER_H

#pragma once

// KH
#include <WebSockets2_Generic.h>
#include "WebSockets2_Generic_Debug.h"

#include <Tiny_Websockets_Generic/server.hpp>
#include <Tiny_Websockets_Generic/internals/wscrypto/crypto.hpp>
#include <memory>
#include <map>

// Important for Teensy, or compile error
#include <algorithm>

namespace websockets2_generic
{
  WebsocketsServer::WebsocketsServer(network2_generic::TcpServer* server) : _server(server) {}
  
  bool WebsocketsServer::available() 
  {
    return this->_server->available();
  }
  
  /////////////////////////////////////////////////////////
  
  void WebsocketsServer::listen(uint16_t port) 
  {
    this->_server->listen(port);
  }
  
  /////////////////////////////////////////////////////////
  
  bool WebsocketsServer::poll() 
  {
    return this->_server->poll();
  }
  
  /////////////////////////////////////////////////////////
  
  struct ParsedHandshakeParams 
  {
    WSString head;
    
    // To store original headers
    std::map<WSString, WSString> headers;
    
    // To store lowercased headers
    std::map<WSString, WSString> lowheaders;
  };
  
  /////////////////////////////////////////////////////////
  
  ParsedHandshakeParams recvHandshakeRequest(network2_generic::TcpClient& client) 
  {
    ParsedHandshakeParams result;
  
    result.head = client.readLine();
  
    WSString line = client.readLine();
    
    do 
    {
      WSString key = "", value = "";
      
      size_t idx = 0;
  
      // read key
      while (idx < line.size() && line[idx] != ':') 
      {
        key += line[idx];
        idx++;
      }
  
      // skip key and whitespace
      idx++;
      while (idx < line.size() && (line[idx] == ' ' || line[idx] == '\t')) 
        idx++;
  
      // read value (until \r\n)
      while (idx < line.size() && line[idx] != '\r') 
      {
        value += line[idx];
        idx++;
      }
      
      // KH
      LOGINFO1("WebsocketsServer::recvHandshakeRequest: key =", internals2_generic::fromInternalString(key));
      LOGINFO1("WebsocketsServer::recvHandshakeRequest: value =", internals2_generic::fromInternalString(value));
      //////
      
      // store headers before tolower(), so we can search both
      result.headers[key] = value;
     
      // convert to lower case
      std::transform(key.begin(), key.end(), key.begin(), ::tolower);
      
      // Important, don't change these case-sensitive data : `Sec-WebSocket-Key` and `Origin`
      if ( (key != WS_KEY_LOWER_CASE) && (key != HEADER_ORIGIN_LOWER_CASE) )
      {    
        std::transform(value.begin(), value.end(), value.begin(), ::tolower);
      }
      //////
  
      // store header after tolower()
      result.lowheaders[key] = value;
      
      // KH
      LOGDEBUG1("WebsocketsServer::recvHandshakeRequest: lowkey =", internals2_generic::fromInternalString(key));
      LOGDEBUG1("WebsocketsServer::recvHandshakeRequest: lowvalue =", internals2_generic::fromInternalString(value));
      //////
        
      line = client.readLine();
    } while (client.available() && line != HEADER_HOST_RN);    
      
    return result;
  }
  
  /////////////////////////////////////////////////////////
  
  WebsocketsClient WebsocketsServer::accept() 
  {           
    std::shared_ptr<network2_generic::TcpClient> tcpClient(_server->accept());
    
    // KH add v1.0.6
    if (!tcpClient)
    {
      return {};
    }
    //////
       
    if (tcpClient->available() == false)
    {
      // KH
      LOGERROR("WebsocketsServer::accept: tcpClient not available");
      //////
      return {};
    }
  
    auto params = recvHandshakeRequest(*tcpClient);
  
    if ( (params.headers[HEADER_CONNECTION_NORMAL].find(HEADER_UPGRADE_NORMAL) == std::string::npos) && 
         (params.lowheaders[HEADER_CONNECTION_LOWER_CASE].find(HEADER_UPGRADE_LOWER_CASE) == std::string::npos) )     
    {
      // KH
      LOGERROR("WebsocketsServer::accept: Connection != Upgrade");
      //////
      return {};
    }
      
    if ( (params.headers[HEADER_UPGRADE_NORMAL] != HEADER_WEBSOCKET_LOWER_CASE) && 
         (params.lowheaders[HEADER_UPGRADE_LOWER_CASE] != HEADER_WEBSOCKET_LOWER_CASE) )
    {
      // KH
      LOGERROR("WebsocketsServer::accept: Upgrade != websocket");
      //////
      return {};
    }
      
    if ( (params.headers[WS_VERSION_NORMAL] != "13") && (params.lowheaders[WS_VERSION_LOWER_CASE] != "13") )
    { 
      // KH
      LOGERROR("WebsocketsServer::accept: Version != 13");
      //////
      return {};
    }
      
    if ( (params.headers[WS_KEY_NORMAL] == "") && (params.lowheaders[WS_KEY_LOWER_CASE] == "") )
    {
      // KH
      LOGERROR("WebsocketsServer::accept: Key == NULL");
      //////
      return {};
    }
  
    auto serverAccept = crypto2_generic::websocketsHandshakeEncodeKey(params.lowheaders[WS_KEY_LOWER_CASE]);
  
    tcpClient->send("HTTP/1.1 101 Switching Protocols\r\n");
    tcpClient->send(HEADER_CONNECTION_UPGRADE_NORMAL);
    tcpClient->send(HEADER_UPGRADE_WS_NORMAL);
    tcpClient->send(HEADER_WS_VERSION_13_NORMAL);
    tcpClient->send(HEADER_WS_ACCEPT_NORMAL + serverAccept + HEADER_HOST_RN);
    tcpClient->send(HEADER_HOST_RN);
  
    WebsocketsClient wsClient(tcpClient);
    // Don't use masking from server to client (according to RFC)
    wsClient.setUseMasking(false);
    return wsClient;
  }
   
  WebsocketsServer::~WebsocketsServer() 
  {
    this->_server->close();
  }

} // namespace websockets2_generic

#endif    // _WEBSOCKETS2_GENERIC_SERVER_H
