/****************************************************************************************************************************
  tcp_client.hpp
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
#include <Tiny_Websockets_Generic/network/tcp_socket.hpp>

namespace websockets2_generic 
{
  namespace network2_generic 
  {
    struct TcpClient : public TcpSocket 
    {
      virtual bool poll() = 0;
      virtual void send(const WSString& data) = 0;
      virtual void send(const WSString&& data) = 0;
      virtual void send(const uint8_t* data, const uint32_t len) = 0;
      virtual WSString readLine() = 0;
      virtual uint32_t read(uint8_t* buffer, const uint32_t len) = 0;
      virtual bool connect(const WSString& host, int port) = 0;
      virtual ~TcpClient() {}
    };
  }   // namespace network2_generic
}     // namespace websockets2_generic 
