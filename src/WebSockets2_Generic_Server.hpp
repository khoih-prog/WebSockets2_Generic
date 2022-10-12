/****************************************************************************************************************************
  WebSockets2_Generic_Server.hpp
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
      LOGINFO1("WebsocketsServer::recvHandshakeRequest: lowkey =", internals2_generic::fromInternalString(key));
      LOGINFO1("WebsocketsServer::recvHandshakeRequest: lowvalue =", internals2_generic::fromInternalString(value));
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
      LOGINFO("WebsocketsServer::accept: tcpClient not available");
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
