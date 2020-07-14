/****************************************************************************************************************************
  SAMD_WiFiNINA_tcp.hpp
  For SAMD21/SAMD51 boards with WiFiNINA module/shield.
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/ESP8266_AT_WebServer
  Licensed under MIT license
  Version: 0.4.17
   
  Version Modified By   Date      Comments
 ------- -----------  ---------- -----------
  0.4.17  K Hoang      12/07/2020 Initial coding and porting to support nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32       
 *****************************************************************************************************************************/
 
#pragma once

#if    ( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
      || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) \
      || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) || defined(ARDUINO_SAMD_MKRVIDOR4000) || defined(__SAMD21G18A__) \
      || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) || defined(__SAMD21E18A__) || defined(__SAMD51__) || defined(__SAMD51J20A__) || defined(__SAMD51J19A__) \
      || defined(__SAMD51G19A__) || defined(__SAMD21G18A__) )
      

#include <Tiny_Websockets_Generic/internals/ws_common.hpp>
#include <Tiny_Websockets_Generic/network/tcp_client.hpp>
#include <Tiny_Websockets_Generic/network/tcp_server.hpp>
#include <Tiny_Websockets_Generic/network/generic_esp/generic_esp_clients.hpp>

#include <WiFiNINA_Generic.h>

namespace websockets2_generic
{
  namespace network2_generic
  {
    typedef GenericEspTcpClient<WiFiClient> WiFiNINATcpClient;

    class SecuredWiFiNINATcpClient : public GenericEspTcpClient<WiFiSSLClient> 
    {
      public:
        void setInsecure() 
        {
          // KH, to fix, for testing only
          //this->client.setInsecure();
        }
    
        void setFingerprint(const char* fingerprint) 
        {
          // KH, to fix, for v1.0.0 only
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

    
    #define DUMMY_PORT 0
    
    // KH, quick fix for WiFiNINA port
    #define CLOSED     0
    
    class WiFiNINATcpServer : public TcpServer 
    {
      public:
        WiFiNINATcpServer() : server(DUMMY_PORT) {}
        
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
          // KH, to fix WiFiNINA_Generic => v1.5.3
          server.begin(port);
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
              return new WiFiNINATcpClient{client};
          }
          return new WiFiNINATcpClient;
        }
    
        bool available() override 
        {
          yield();
          return server.status() != CLOSED;
        }
    
        void close() override 
        {
          yield();
          
          // KH, to fix, for testing only
          //server.close();
          //////
        }
    
        virtual ~WiFiNINATcpServer() 
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
#endif // #ifdef SAMD
