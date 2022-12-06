/****************************************************************************************************************************
  esp8266_tcp.hpp
  For WebSockets2_Generic Library
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52, SAMD21/SAMD51, SAM DUE, Teensy, RP2040 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
  
  Version: 1.13.2

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
  1.13.1  K Hoang      24/11/2022 Using new WiFi101_Generic library
  1.13.2  K Hoang      06/12/2022 Fix compiler error using QNEthernet v0.17.0
 *****************************************************************************************************************************/
 
#pragma once

#ifdef ESP8266 

#include <Tiny_Websockets_Generic/internals/ws_common.hpp>
#include <Tiny_Websockets_Generic/network/tcp_client.hpp>
#include <Tiny_Websockets_Generic/network/tcp_server.hpp>
#include <Tiny_Websockets_Generic/network/generic_esp/generic_esp_clients.hpp>

#include <ESP8266WiFi.h>

namespace websockets2_generic
{
  namespace network2_generic
  {
    typedef GenericEspTcpClient<WiFiClient> Esp8266TcpClient;
    
    class SecuredEsp8266TcpClient : public GenericEspTcpClient<WiFiClientSecure> 
    {
      public:
        void setInsecure() 
        {
          this->client.setInsecure();
        }
    
        void setFingerprint(const char* fingerprint) 
        {
          this->client.setFingerprint(fingerprint);
        }
        
        // KH, New in v1.0.5 (sync with v0.4.18)
    
        void setKnownKey(const PublicKey *pk) 
        {
          this->client.setKnownKey(pk);
        }

        void setTrustAnchors(const X509List *ta)
        {
          this->client.setTrustAnchors(ta);
        }

        void setClientRSACert(const X509List *cert, const PrivateKey *sk) 
        {
          this->client.setClientRSACert(cert, sk);
        }

        void setClientECCert(const X509List *cert, const PrivateKey *sk) 
        {
          this->client.setClientECCert(cert, sk, 0xFFFF, 0);
        }
        //////
    
    };
    
    #define DUMMY_PORT 0
    
    class Esp8266TcpServer : public TcpServer 
    {
      public:
        Esp8266TcpServer() : server(DUMMY_PORT) {}
        
        bool poll() override 
        {
          yield();
          return server.hasClient();
        }
    
        bool listen(const uint16_t port) override 
        {
          yield();
          server.begin(port);
          return available();
        }
           
        TcpClient* accept() override 
        {
          while (available()) 
          {
            yield();
            auto client = server.available();
            
            if (client) 
            {
              return new Esp8266TcpClient{client};
            }
            // KH, from v1.0.6, add to enable non-blocking when no WS Client
            else
            {
              // Return NULL Client. Remember to test for NULL and process correctly
              return NULL;
            }  
          }
          
          return new Esp8266TcpClient;
        }
    
        bool available() override 
        {
          yield();
          return server.status() != CLOSED;
        }
    
        void close() override 
        {
          yield();
          server.close();
        }
    
        virtual ~Esp8266TcpServer() 
        {
          if (available()) close();
        }
    
      protected:
        int getSocket() const override 
        {
          return -1;
        }
    
      private:
        WiFiServer server;
    };
  }   // namespace network2_generic
}     // namespace websockets2_generic
#endif // #ifdef ESP8266 
