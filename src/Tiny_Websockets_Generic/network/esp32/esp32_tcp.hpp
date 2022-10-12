/****************************************************************************************************************************
  esp32_tcp.hpp
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

#ifdef ESP32 

#include <Tiny_Websockets_Generic/internals/ws_common.hpp>
#include <Tiny_Websockets_Generic/network/tcp_client.hpp>
#include <Tiny_Websockets_Generic/network/tcp_server.hpp>
#include <Tiny_Websockets_Generic/network/generic_esp/generic_esp_clients.hpp>

#include <WiFi.h>
#include <HTTPClient.h>

namespace websockets2_generic
{
  namespace network2_generic
  {
    typedef GenericEspTcpClient<WiFiClient> Esp32TcpClient;
    
    class SecuredEsp32TcpClient : public GenericEspTcpClient<WiFiClientSecure>
    {
      public:
        void setCACert(const char* ca_cert)
        {
          this->client.setCACert(ca_cert);
        }
    
        void setCertificate(const char* client_ca)
        {
          this->client.setCertificate(client_ca);
        }
    
        void setPrivateKey(const char* private_key)
        {
          this->client.setPrivateKey(private_key);
        }

        void setInsecure()
        {
          this->client.setInsecure();
        }
    };
    
    
    class Esp32TcpServer : public TcpServer
    {
      public:
        Esp32TcpServer() {}
    
        bool poll() override
        {
          yield();
          return server.hasClient();
        }
    
        bool listen(const uint16_t port) override
        {
          yield();
          server = WiFiServer(port);
          server.begin(port);
          return available();
        }
           
        TcpClient* accept() override
        {
          while (available())
          {
            auto client = server.available();
    
            if (client)
            {
              return new Esp32TcpClient{client};
            }
            // KH, from v1.0.6, add to enable non-blocking when no WS Client
            else
            {
              // Return NULL Client. Remember to test for NULL and process correctly
              return NULL;
            }  
          }
          
          return new Esp32TcpClient;
        }
    
        bool available() override
        {
          yield();
          return static_cast<bool>(server);
        }
    
        void close() override
        {
          yield();
          server.close();
        }
    
        virtual ~Esp32TcpServer()
        {
          if (available()) 
            close();
        }
    
      protected:
        int getSocket() const override
        {
          return -1; // Not Implemented
        }
    
      private:
        WiFiServer server;
    };
  }   // namespace network2_generic
}     // namespace websockets2_generic

#endif // #ifdef ESP32 
