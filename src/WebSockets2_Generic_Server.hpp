/****************************************************************************************************************************
  WebSockets2_Generic_Server.hpp
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

namespace websockets2_generic
{
  WebsocketsServer::WebsocketsServer(network2_generic::TcpServer* server) : _server(server) {}
  
  bool WebsocketsServer::available() 
  {
    return this->_server->available();
  }
  
  void WebsocketsServer::listen(uint16_t port) 
  {
    this->_server->listen(port);
  }
  
  bool WebsocketsServer::poll() 
  {
    return this->_server->poll();
  }
  
  struct ParsedHandshakeParams 
  {
    WSString head;
    std::map<WSString, WSString> headers;
  };
  
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
  
      // store header
      result.headers[key] = value;
      
      // KH
      LOGWARN1("WebsocketsServer::recvHandshakeRequest: value =", internals2_generic::fromInternalString(value));
      //////
  
      line = client.readLine();
    } while (client.available() && line != "\r\n");
    
      
    return result;
  }
  
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
      LOGDEBUG("WebsocketsServer::accept: tcpClient not available");
      //////
      return {};
    }
  
    auto params = recvHandshakeRequest(*tcpClient);
  
    if (params.headers["Connection"].find("Upgrade") == std::string::npos) 
    {
      // KH
      LOGWARN("WebsocketsServer::accept: Connection != Upgrade");
      //////
      return {};
    }
      
    if (params.headers["Upgrade"] != "websocket")
    {
      // KH
      LOGWARN("WebsocketsServer::accept: Upgrade != websocket");
      //////
      return {};
    }
      
    if (params.headers["Sec-WebSocket-Version"] != "13")
    { 
      // KH
      LOGWARN("WebsocketsServer::accept: Version != 13");
      //////
      return {};
    }
      
    if (params.headers["Sec-WebSocket-Key"] == "") 
    {
      // KH
      LOGWARN("WebsocketsServer::accept: Key == NULL");
      //////
      return {};
    }
  
    auto serverAccept = crypto2_generic::websocketsHandshakeEncodeKey(
                          params.headers["Sec-WebSocket-Key"]
                        );
  
    tcpClient->send("HTTP/1.1 101 Switching Protocols\r\n");
    tcpClient->send("Connection: Upgrade\r\n");
    tcpClient->send("Upgrade: websocket\r\n");
    tcpClient->send("Sec-WebSocket-Version: 13\r\n");
    tcpClient->send("Sec-WebSocket-Accept: " + serverAccept + "\r\n");
    tcpClient->send("\r\n");
  
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
