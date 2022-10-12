/****************************************************************************************************************************
  RP2040W_tcp.hpp
  For RP2040 boards with WiFiNINA module/shield such as Nano_RP2040_Connect
  
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

#if ( defined(ARDUINO_RASPBERRY_PI_PICO_W) && USE_RP2040W_WIFI )
      
#include <Tiny_Websockets_Generic/internals/ws_common.hpp>
#include <Tiny_Websockets_Generic/network/tcp_client.hpp>
#include <Tiny_Websockets_Generic/network/tcp_server.hpp>
#include <Tiny_Websockets_Generic/network/generic_esp/generic_esp_clients.hpp>

#include <WiFi.h>

namespace websockets2_generic
{
  namespace network2_generic
  {
    typedef GenericEspTcpClient<WiFiClient> RP2040W_TcpClient;

    /////////////////////////////////////////////////////

#if (defined(_WS_CONFIG_NO_SSL) && !_WS_CONFIG_NO_SSL)
    // KH, no SSL support yet for RP2040W
    class Secured_RP2040W_TcpClient : public GenericEspTcpClient<WiFiSSLClient> 
    {
      public:
        void setInsecure() 
        {
          // KH, to fix, for v1.0.0 only
          //this->client.setInsecure();
        }
    
        void setFingerprint(const char* fingerprint) 
        {
          (void) fingerprint;
          
          // KH, to fix, for testing only
          //this->client.setFingerprint(fingerprint);
        }
#if 0    
        void setClientRSACert(const X509List *cert, const PrivateKey *sk) 
        {
          // KH, to fix, for v1.0.0 only
          //this->client.setClientRSACert(cert, sk);
        }
    
        void setTrustAnchors(const X509List *ta) 
        {
          // KH, to fix, for v1.0.0 only
          //this->client.setTrustAnchors(ta);
        }
#endif    
    };
#endif

    /////////////////////////////////////////////////////
    
    #ifndef WEBSOCKETS_PORT
      #define DUMMY_PORT    8080
    #else
      #define DUMMY_PORT    WEBSOCKETS_PORT
    #endif
    
    // KH, quick fix for WiFiNINA port
    #define CLOSED     0

    /////////////////////////////////////////////////////
    
    class RP2040W_TcpServer : public TcpServer 
    {
      public:
        RP2040W_TcpServer() : server(DUMMY_PORT) {}

        /////////////////////////////////////////////////////
        
        bool poll() override 
        {
          yield();
          
          // KH, to fix, for testing only
          //return server.hasClient();
          return true;
          //////
        }

        /////////////////////////////////////////////////////
    
        bool listen(const uint16_t port) override 
        {
          yield();

          server.begin(port);

          return available();
        }

        /////////////////////////////////////////////////////
    
        TcpClient* accept() override 
        {   
          while (available()) 
          {
            yield();
            auto client = server.available();
            
            if (client)
            {         
              return new RP2040W_TcpClient{client};
            }
            else
            {
              // Return NULL Client. Remember to test for NULL and process correctly
              return NULL;
            }            
          }
                   
          return new RP2040W_TcpClient;
        }

        /////////////////////////////////////////////////////
    
        bool available() override 
        {
          yield();
          
          return server.status() != CLOSED;
        }

        /////////////////////////////////////////////////////
    
        void close() override 
        {
          yield();
          
          // KH, to fix, for testing only
          //server.close();
          //////
        }

        /////////////////////////////////////////////////////
    
        virtual ~RP2040W_TcpServer() 
        {
          if (available()) 
            close();
        }

        /////////////////////////////////////////////////////
    
      protected:

        /////////////////////////////////////////////////////
      
        int getSocket() const override 
        {
          return -1;
        }

        /////////////////////////////////////////////////////
    
      private:
        WiFiServer server;
    };
  }   // namespace network2_generic
}     // namespace websockets2_generic
#endif // #ifdef RP2040
