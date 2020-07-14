/****************************************************************************************************************************
  win_tcp_server.hpp
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

#ifdef _WIN32 

#include <Tiny_Websockets_Generic/internals/ws_common.hpp>
#include <Tiny_Websockets_Generic/network/tcp_server.hpp>

#define WIN32_LEAN_AND_MEAN

#undef _WIN32_WINNT
#define _WIN32_WINNT 0x501

#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

namespace websockets2_generic
{
  namespace network2_generic
  {
    class WinTcpServer : public TcpServer 
    {
      public:
        bool listen(uint16_t port) override;
        TcpClient* accept() override;
        bool available() override;
        bool poll() override;
        void close() override;
        virtual ~WinTcpServer();
    
      protected:
        int getSocket() const override;
    
      private:
        SOCKET socket;
    };
  }   // namespace network2_generic
}     // namespace websockets2_generic


#endif // #ifdef _WIN32 
