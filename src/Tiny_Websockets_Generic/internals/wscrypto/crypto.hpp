/****************************************************************************************************************************
  crypto.hpp
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

namespace websockets2_generic
{
  namespace crypto2_generic
  {
    WSString base64Encode(WSString data);
    WSString base64Encode(uint8_t* data, size_t len);
    WSString base64Decode(WSString data);
    WSString websocketsHandshakeEncodeKey(WSString key);
    WSString randomBytes(size_t len);
  }       // namespace crypto2_generic
}         // namespace websockets2_generic
