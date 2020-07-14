/****************************************************************************************************************************
  WebSockets2_Generic_Common.cpp
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
 
#include <Tiny_Websockets_Generic/internals/ws_common.hpp>

namespace websockets2_generic
{
  namespace internals2_generic
  {
    WSString fromInterfaceString(const WSInterfaceString& str)
    {
      return str.c_str();
    }
    
    WSString fromInterfaceString(const WSInterfaceString&& str)
    {
      return str.c_str();
    }
    
    WSInterfaceString fromInternalString(const WSString& str)
    {
      return str.c_str();
    }
    
    WSInterfaceString fromInternalString(const WSString&& str)
    {
      return str.c_str();
    }
  }   // namespace internals2_generic
}     // namespace websockets2_generic
