/****************************************************************************************************************************
  win_tcp_client.hpp
  For WebSockets2_Generic Library
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52, SAMD21/SAMD51, SAM DUE, Teensy, RP2040 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/
 
#pragma once

#ifdef _WIN32 

#include <Tiny_Websockets_Generic/internals/ws_common.hpp>
#include <Tiny_Websockets_Generic/network/tcp_client.hpp>

#define WIN32_LEAN_AND_MEAN

#undef _WIN32_WINNT
#define _WIN32_WINNT 0x501

#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#include <iostream>

namespace websockets2_generic
{
  namespace network2_generic
  {
    class WinTcpClient : public TcpClient 
    {
      public:
        WinTcpClient(const SOCKET s = INVALID_SOCKET);
        bool connect(const WSString& host, const int port) override;
        bool poll() override;
        bool available() override;
        void send(const WSString& data) override;
        void send(const WSString&& data) override;
        void send(const uint8_t* data, const uint32_t len) override;
        WSString readLine() override;
        void read(uint8_t* buffer, const uint32_t len) override;
        void close() override;
        virtual ~WinTcpClient();
    
      protected:
        int getSocket() const override;
    
      private:
        SOCKET socket;
    };
  }   // namespace network2_generic
}     // namespace websockets2_generic


#endif // #ifdef _WIN32 
