/****************************************************************************************************************************
  linux_tcp_client.hpp
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

#ifdef __linux__ 

#include <Tiny_Websockets_Generic/internals/ws_common.hpp>
#include <Tiny_Websockets_Generic/network/tcp_client.hpp>
#include <Tiny_Websockets_Generic/network/tcp_socket.hpp>

#define INVALID_SOCKET -1

namespace websockets2_generic
{
  namespace network2_generic
  {
    class LinuxTcpClient : public TcpClient 
    {
      public:
        LinuxTcpClient(int socket = INVALID_SOCKET);
        bool connect(const WSString& host, int port) override;
        bool poll() override;
        bool available() override;
        void send(const WSString& data) override;
        void send(const WSString&& data) override;
        void send(const uint8_t* data, const uint32_t len) override;
        WSString readLine() override;
        void read(uint8_t* buffer, const uint32_t len) override;
        void close() override;
        virtual ~LinuxTcpClient();
    
      protected:
        virtual int getSocket() const override 
        {
          return _socket;
        }
    
      private:
        int _socket;
    };
  }   // namespace network2_generic
}     // namespace websockets2_generic

#endif // #ifdef __linux__ 
