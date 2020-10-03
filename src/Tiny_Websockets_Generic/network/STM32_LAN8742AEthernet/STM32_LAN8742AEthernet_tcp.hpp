/****************************************************************************************************************************
  STM32_STM32Ethernet_tcp.hpp
  For STM32F/L/H/G/WB/MP1 boards with STM32Ethernet LAN8742A built-in module/shield.
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32


  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
  Version: 1.0.7

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/07/2020 Initial coding/porting to support nRF52 and SAMD21/SAMD51 boards. Add SINRIC/Alexa support
  1.0.1   K Hoang      16/07/2020 Add support to Ethernet W5x00 to nRF52, SAMD21/SAMD51 and SAM DUE boards
  1.0.2   K Hoang      18/07/2020 Add support to Ethernet ENC28J60 to nRF52, SAMD21/SAMD51 and SAM DUE boards
  1.0.3   K Hoang      18/07/2020 Add support to STM32F boards using Ethernet W5x00, ENC28J60 and LAN8742A 
  1.0.4   K Hoang      27/07/2020 Add support to STM32F/L/H/G/WB/MP1 and Seeeduino SAMD21/SAMD51 using 
                                  Ethernet W5x00, ENC28J60, LAN8742A and WiFiNINA. Add examples and Packages' Patches.
  1.0.5   K Hoang      29/07/2020 Sync with ArduinoWebsockets v0.4.18 to fix ESP8266 SSL bug.
  1.0.6   K Hoang      06/08/2020 Add non-blocking WebSocketsServer feature and non-blocking examples.       
  1.0.7   K Hoang      03/10/2020 Add support to Ethernet ENC28J60 using EthernetENC and UIPEthernet v2.0.9
 *****************************************************************************************************************************/
 
#pragma once

#if  ( defined(STM32F0) || defined(STM32F1) || defined(STM32F2) || defined(STM32F3)  ||defined(STM32F4) || defined(STM32F7) || \
       defined(STM32L0) || defined(STM32L1) || defined(STM32L4) || defined(STM32H7)  ||defined(STM32G0) || defined(STM32G4) || \
       defined(STM32WB) || defined(STM32MP1) )
      
#include <Tiny_Websockets_Generic/internals/ws_common.hpp>
#include <Tiny_Websockets_Generic/network/tcp_client.hpp>
#include <Tiny_Websockets_Generic/network/tcp_server.hpp>
#include <Tiny_Websockets_Generic/network/generic_esp/generic_esp_clients.hpp>

// KH, from v1.0.3
#if USE_LAN8742A_ETHERNET
  #warning Using STM32Ethernet Lib for built-in LAN8742A in STM32_LAN8742AEthernet_tcp.hpp
  #include <LwIP.h>
  #include <STM32Ethernet.h>
#else
  // Default to STM32Ethernet library
  #warning Using default STM32Ethernet Lib for built-in LAN8742A in STM32_LAN8742AEthernet_tcp.hpp
  #include <LwIP.h>
  #include <STM32Ethernet.h>
#endif
//////

namespace websockets2_generic
{
  namespace network2_generic
  {
    typedef GenericEspTcpClient<EthernetClient> EthernetTcpClient;

#if 0
    // KH, no SSL support for Ethernet
    class SecuredEthernetTcpClient : public GenericEspTcpClient<EthernetSSLClient> 
    {
      public:
        void setInsecure() 
        {
          // KH, to fix, for v1.0.0 only
          //this->client.setInsecure();
        }
    
        void setFingerprint(const char* fingerprint) 
        {
          // KH, to fix, for testing only
          //this->client.setFingerprint(fingerprint);
        }

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
    };
#endif
    
    #ifndef WEBSOCKETS_PORT
      #define DUMMY_PORT    8080
    #else
      #define DUMMY_PORT    WEBSOCKETS_PORT
    #endif
    
    // KH, quick fix for Ethernet port
    #define CLOSED     0
    
    class EthernetTcpServer : public TcpServer 
    {
      public:
        EthernetTcpServer() : server(DUMMY_PORT) {}
        
        bool poll() override 
        {
          yield();
          
          // KH, to fix, for testing only
          //return server.hasClient();
          return true;
          //////
        }
    
        bool listen(const uint16_t port) override 
        {
          yield();
          // KH, already use WEBSOCKETS_PORT
          //server.begin(port);
          server.begin();
          //////
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
              return new EthernetTcpClient{client};
            }
            // KH, from v1.0.6, add to enable non-blocking when no WS Client
            else
            {
              // Return NULL Client. Remember to test for NULL and process correctly
              return NULL;
            }            
          }
                   
          return new EthernetTcpClient;
        }
    
        bool available() override 
        {
          yield();
          
          // KH
          //return server.status() != CLOSED;
          // Use EthernetServer::operator bool()
          //return (server);
          return true;
        }
    
        void close() override 
        {
          yield();
          
          // KH, to fix, for testing only
          //server.close();
          //////
        }
    
        virtual ~EthernetTcpServer() 
        {
          if (available()) close();
        }
    
      protected:
        int getSocket() const override 
        {
          return -1;
        }
    
      private:
        EthernetServer server;
    };
  }   // namespace network2_generic
}     // namespace websockets2_generic
#endif // #ifdef STM32
