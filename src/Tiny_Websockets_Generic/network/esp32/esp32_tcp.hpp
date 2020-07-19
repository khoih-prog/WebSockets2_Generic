/****************************************************************************************************************************
  esp32_tcp.hpp
  For WebSockets2_Generic Library
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
  Version: 1.0.3

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/07/2020 Initial coding/porting to support nRF52 and SAMD21/SAMD51 boards. Add SINRIC/Alexa support
  1.0.1   K Hoang      16/07/2020 Add support to Ethernet W5x00 to nRF52, SAMD21/SAMD51 and SAM DUE boards
  1.0.2   K Hoang      18/07/2020 Add support to Ethernet ENC28J60 to nRF52, SAMD21/SAMD51 and SAM DUE boards
  1.0.3   K Hoang      18/07/2020 Add support to STM32F boards using Ethernet W5x00, ENC28J60 and LAN8742A
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
