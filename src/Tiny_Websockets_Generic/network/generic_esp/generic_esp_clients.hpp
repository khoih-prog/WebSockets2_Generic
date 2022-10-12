/****************************************************************************************************************************
  generic_esp_clients.hpp
  For WebSockets2_Generic Library
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52, SAMD21/SAMD51, SAM DUE, Teensy, RP2040 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
  
  Version: 1.13.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/07/2020 Initial coding/porting to support nRF52 and SAMD21/SAMD51 boards. Add SINRIC/Alexa support
  ...
  1.9.0   K Hoang      30/11/2021 Auto detect ESP32 core version. Fix bug in examples
  1.9.1   K Hoang      17/12/2021 Fix QNEthernet TCP interface
  1.10.0  K Hoang      18/12/2021 Supporting case-insensitive headers, according to RFC2616
  1.10.1  K Hoang      26/02/2022 Reduce QNEthernet latency
  1.10.2  K Hoang      14/03/2022 Fix bug when using QNEthernet staticIP. Add staticIP option to NativeEthernet
  1.10.3  K Hoang      11/04/2022 Use Ethernet_Generic library as default. Support SPI1/SPI2 for RP2040
  1.11.0  K Hoang      08/10/2022 Add support to ESP32 using W5x00 Ethernet
  1.12.0  K Hoang      09/10/2022 Add support to ENC28J60 using EthernetENC or UIPEthernet for all supported boards
  1.12.1  K Hoang      09/10/2022 Fix bug in examples
  1.13.0  K Hoang      11/10/2022 Add support to RP2040W using CYW43439 WiFi
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
 
// KH mod for ESP32 Ethernet        
#if ( ( defined(ESP32) || defined(ESP8266) ) && !WEBSOCKETS_USE_ETHERNET )
          client.setNoDelay(true);
#endif          
        }
    
        GenericEspTcpClient() {}
    
        bool connect(const WSString& host, const int port) 
        {
          yield();
          auto didConnect = client.connect(host.c_str(), port);
          
// KH mod for ESP32 Ethernet        
#if ( ( defined(ESP32) || defined(ESP8266) ) && !WEBSOCKETS_USE_ETHERNET )         
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
          
          const uint64_t millisBeforeReadingHeaders = millis();
          
          while( ch != '\n' && available()) 
          {
            if (millis() - millisBeforeReadingHeaders > _CONNECTION_TIMEOUT) 
              return "";
              
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
