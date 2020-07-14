/****************************************************************************************************************************
  server.hpp
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

#include <Tiny_Websockets_Generic/internals/ws_common.hpp>
#include <Tiny_Websockets_Generic/client.hpp>
#include <functional>

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
