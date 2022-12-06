/****************************************************************************************************************************
  STM32_Ethernet_tcp.hpp
  For STM32F/L/H/G/WB/MP1 boards with WiFiNINA module/shield.
  
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

#if  ( defined(STM32F0) || defined(STM32F1) || defined(STM32F2) || defined(STM32F3)  ||defined(STM32F4) || defined(STM32F7) || \
       defined(STM32L0) || defined(STM32L1) || defined(STM32L4) || defined(STM32H7)  ||defined(STM32G0) || defined(STM32G4) || \
       defined(STM32WB) || defined(STM32MP1) )
      
#include <Tiny_Websockets_Generic/internals/ws_common.hpp>
#include <Tiny_Websockets_Generic/network/tcp_client.hpp>
#include <Tiny_Websockets_Generic/network/tcp_server.hpp>
#include <Tiny_Websockets_Generic/network/generic_esp/generic_esp_clients.hpp>

/////////////////////////

#if (USE_ETHERNET_GENERIC_LIB || USE_ETHERNET_GENERIC)
  #warning Using Ethernet_Generic Lib in RP2040_Ethernet_tcp.hpp
  #include <Ethernet_Generic.h>
#elif (USE_ETHERNET_LIB || USE_ETHERNET)
  #warning Using Ethernet Lib in RP2040_Ethernet_tcp.hpp
  #include <Ethernet.h>
#elif (USE_ETHERNET2_LIB || USE_ETHERNET2)
  #warning Using Ethernet2 Lib in RP2040_Ethernet_tcp.hpp
  #include <Ethernet2.h>
#elif (USE_ETHERNET_LARGE_LIB || USE_ETHERNET_LARGE)
  #warning Using EthernetLarge Lib in RP2040_Ethernet_tcp.hpp
  #include <EthernetLarge.h>
#elif (USE_ETHERNET_ENC_LIB || USE_ETHERNET_ENC)
  #warning Using EthernetENC Lib in RP2040_Ethernet_tcp.hpp
  #include <EthernetENC.h>  
#else
  // Default to Ethernet_Generic library
  #warning Using default Ethernet_Generic Lib in RP2040_Ethernet_tcp.hpp
  #include <Ethernet_Generic.h>
#endif

/////////////////////////

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
          (void) port;
          
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
