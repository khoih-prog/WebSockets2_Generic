/****************************************************************************************************************************
  generic_esp_clients.hpp
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
#include <Tiny_Websockets_Generic/network/tcp_client.hpp>

namespace websockets2_generic
{
  namespace network2_generic
  {
    template <class WifiClientImpl>
    class GenericEspTcpClient : public TcpClient 
    {
      public:
        GenericEspTcpClient(WifiClientImpl c) : client(c) 
        {
        
#if ( defined(ESP32)  || defined(ESP8266) )   
          client.setNoDelay(true);
#endif          
        }
    
        GenericEspTcpClient() {}
    
        bool connect(const WSString& host, const int port) 
        {
          yield();
          auto didConnect = client.connect(host.c_str(), port);
          
#if ( defined(ESP32)  || defined(ESP8266) )           
          client.setNoDelay(true);
#endif
          
          return didConnect;
        }
    
        bool poll() 
        {
          yield();
          return client.available();
        }
    
        bool available() override 
        {
          return client.connected();
        }
    
        void send(const WSString& data) override 
        {
          yield();
          client.write(reinterpret_cast<uint8_t*>(const_cast<char*>(data.c_str())), data.size());
          yield();
        }
    
        void send(const WSString&& data) override 
        {
          yield();
          client.write(reinterpret_cast<uint8_t*>(const_cast<char*>(data.c_str())), data.size());
          yield();
        }
    
        void send(const uint8_t* data, const uint32_t len) override 
        {
          yield();
          client.write(data, len);
          yield();
        }
    
        WSString readLine() override 
        {
          WSString line = "";
    
          int ch = -1;
          
          while ( ch != '\n' && available()) 
          {
            ch = client.read();
            
            if (ch < 0) 
              continue;
              
            line += (char) ch;
          }
    
          return line;
        }
    
        uint32_t read(uint8_t* buffer, const uint32_t len) override 
        {
          yield();
          
          return 
            client.read(buffer, len);
        }
    
        void close() override 
        {
          yield();
          client.stop();
        }
    
        virtual ~GenericEspTcpClient() 
        {
          client.stop();
        }
    
      protected:
        WifiClientImpl client;
    
        int getSocket() const override 
        {
          return -1;
        }
    };
  }   // namespace network2_generic
}     // namespace websockets2_generic
