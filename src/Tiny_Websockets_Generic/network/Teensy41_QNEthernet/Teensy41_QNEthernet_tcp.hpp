/****************************************************************************************************************************
  Teensy41_Ethernet_tcp.hpp
  For Teensy 4.1 boards with QNEthernet.
  
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

#if (defined(__IMXRT1062__) && defined(ARDUINO_TEENSY41) && USE_QN_ETHERNET)

#include <memory>
#include <utility>

#include <Tiny_Websockets_Generic/internals/ws_common.hpp>
#include <Tiny_Websockets_Generic/network/tcp_client.hpp>
#include <Tiny_Websockets_Generic/network/tcp_server.hpp>

#include <QNEthernet.h>
#include <QNEthernetClient.h>
#include <QNEthernetServer.h>

using namespace qindesign::network;

namespace websockets2_generic
{
  namespace network2_generic
  {
    class EthernetTcpClient : public TcpClient
    {
      public:
        EthernetTcpClient(EthernetClient c) : client(std::move(c)) {}
    
        EthernetTcpClient() {}
    
        bool connect(const WSString& host, const int port)
        {
          const char* hostStr = host.c_str();
          // Teensy's NativeEthernet library doesn't accept a char buffer
          // as an IP (it will try to resolve it). So we have to convert
          // it if necessary.
          IPAddress ip;
                   
          if (ip.fromString(hostStr))
          {
          	LOGDEBUG3("QNEthernet::connect: ip =", ip, ", port = ", port);
          }
          else
          {
          	LOGDEBUG3("QNEthernet::connect: hostStr =", hostStr, ", port = ", port);
          }
          
          return (ip.fromString(hostStr)
                  ? client.connect(ip, port)
                  : client.connect(hostStr, port)
                 );
        }
    
        bool poll()
        {
          return client.available();
        }
    
        bool available() override
        {
          return client.connected();
        }
    
        void send(const WSString& data) override
        {
          client.writeFully(reinterpret_cast<uint8_t*>(const_cast<char*>(data.c_str())), data.size());
          client.flush();
        }
    
        void send(const WSString&& data) override
        {
          client.writeFully(reinterpret_cast<uint8_t*>(const_cast<char*>(data.c_str())), data.size());
          client.flush();
        }
    
        void send(const uint8_t* data, const uint32_t len) override
        {
          client.writeFully(data, len);
          client.flush();
        }
        
        WSString readLine() override
        {
          WSString line = "";
    
          int ch = -1;
          
          const uint64_t millisBeforeReadingHeaders = millis();
             
          while ( ch != '\n' && available())
          {
            if (millis() - millisBeforeReadingHeaders > _CONNECTION_TIMEOUT) 
              return "";
              
            // It is important to call `client.available()`. Otherwise no data can be read.
            if (client.available())
            {
              ch = client.read();
    
              if (ch >= 0)
              {
                line += (char) ch;
              }
            }
          }
    
          return line;
        }
       
        uint32_t read(uint8_t* buffer, const uint32_t len) override
        {
          return client.read(buffer, len);
        }
    
        void close() override
        {
          client.stop();
        }
    
        virtual ~EthernetTcpClient()
        {
          close();
        }
    
      protected:
        EthernetClient client;
    
        int getSocket() const override
        {
          return -1;
        }
    };
    
    ///////////////////////////////////////////////////////////////////
    #ifndef WEBSOCKETS_PORT
      #define DUMMY_PORT    8080
    #else
      #define DUMMY_PORT    WEBSOCKETS_PORT
    #endif
    ///////////////////////////////////////////////////////////////////
    
    class EthernetTcpServer : public TcpServer 
    {
      public:
        EthernetTcpServer() {}
    
        bool poll() override 
        {
          if (server == nullptr) 
          {
            return false;
          }
          
          return server->available();
        }
    
        bool listen(const uint16_t port) override 
        {
          if (server == nullptr || server->port() != port) 
          {
            if (server != nullptr) 
            {
              server->end();
            }
            
            server = std::make_unique<EthernetServer>(port);
            server->begin();
          }
          
          return available();
        }
    
        TcpClient* accept() override 
        {
          if (server == nullptr) 
          {
            return nullptr;  // Watch out for this!
          }
          
          auto client = server->accept();
          
          return new EthernetTcpClient(client);
        }
    
        bool available() override 
        {
          if (server == nullptr) 
          {
            return false;
          }
          
          return static_cast<bool>(*server);
        }
    
        void close() override 
        {
          if (server == nullptr) 
          {
            return;
          }
          
          server->end();
        }
    
        virtual ~EthernetTcpServer() 
        {
          close();
        }
    
      protected:
        int getSocket() const override 
        {
          return -1; // Not Implemented
        }
    
      private:
        std::unique_ptr<EthernetServer> server;
    };
  }
} // websockets2_generic::network2_generic

#else
  #error This is designed only for Teensy 4.1. Please check your Tools-> Boards  
#endif // #if (defined(__IMXRT1062__) && defined(ARDUINO_TEENSY41) && USE_QN_ETHERNET)
