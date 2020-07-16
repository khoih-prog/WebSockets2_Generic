/****************************************************************************************************************************
  tcp_socket.hpp
  For WebSockets2_Generic Library
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
  Version: 1.0.1

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/07/2020 Initial coding/porting to support nRF52 and SAMD21/SAMD51 boards. Add SINRIC/Alexa support
  1.0.1   K Hoang      16/07/2020 Add support to Ethernet W5x00 to nRF52 and SAMD21/SAMD51 boards    
 *****************************************************************************************************************************/
 
#pragma once

#include <Tiny_Websockets_Generic/internals/ws_common.hpp>

namespace websockets2_generic 
{
  namespace network2_generic 
  {
    struct TcpSocket 
    {
      public:
          virtual bool available() = 0;
          virtual void close() = 0;
          virtual ~TcpSocket() {}
      protected:
          virtual int getSocket() const = 0;
    };
  }   // namespace network2_generic
}     // namespace websockets2_generic 
