/****************************************************************************************************************************
  WebSockets2_Generic_Message.cpp
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

#include <Tiny_Websockets_Generic/message.hpp>

namespace websockets2_generic
{
  MessageType messageTypeFromOpcode(uint8_t opcode) 
  {
    switch (opcode) 
    {
      case internals2_generic::ContentType::Binary: return MessageType::Binary;
      case internals2_generic::ContentType::Text: return MessageType::Text;
      case internals2_generic::ContentType::Ping: return MessageType::Ping;
      case internals2_generic::ContentType::Pong: return MessageType::Pong;
      case internals2_generic::ContentType::Close: return MessageType::Close;
      default: return MessageType::Empty;
    }
  }
}   // namespace websockets2_generic
