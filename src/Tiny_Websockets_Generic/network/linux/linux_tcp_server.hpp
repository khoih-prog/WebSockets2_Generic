/****************************************************************************************************************************
  linux_tcp_server.hpp
  For WebSockets2_Generic Library
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52, SAMD21/SAMD51, SAM DUE, Teensy, RP2040 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/
 
#pragma once

#ifdef __linux__ 

#include <Tiny_Websockets_Generic/internals/ws_common.hpp>
#include <Tiny_Websockets_Generic/network/tcp_server.hpp>
#include <Tiny_Websockets_Generic/network/linux/linux_tcp_client.hpp>

#define DEFAULT_BACKLOG_SIZE 5

namespace websockets2_generic
{
  namespace network2_generic
  {
    class LinuxTcpServer : public TcpServer 
    {
      public:
        LinuxTcpServer(size_t backlog = DEFAULT_BACKLOG_SIZE) : _num_backlog(backlog) {}
        bool listen(const uint16_t port) override;
        bool poll() override;
        TcpClient* accept() override;
        bool available() override;
        void close() override;
        virtual ~LinuxTcpServer();
    
      protected:
        virtual int getSocket() const override 
        {
          return _socket;
        }
    
      private:
        int _socket;
        size_t _num_backlog;
    };
  }   // namespace network2_generic
}     // namespace websockets2_generic

#endif // #ifdef __linux__ 
