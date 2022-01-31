/****************************************************************************************************************************
  Teensy41_Ethernet_tcp.hpp
  For Teensy 4.1 boards with QNEthernet.
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52, SAMD21/SAMD51, SAM DUE, Teensy, RP2040 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
  Version: 1.10.0

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
  1.1.0   K Hoang      08/12/2020 Add support to Teensy 4.1 using NativeEthernet  
  1.2.0   K Hoang      16/04/2021 Add limited support (client only) to ESP32-S2 and LAN8720 for STM32F4/F7
  1.2.1   K Hoang      16/04/2021 Add support to new ESP32-S2 boards. Restore Websocket Server function for ESP32-S2.
  1.2.2   K Hoang      16/04/2021 Add support to ESP32-C3
  1.2.3   K Hoang      02/05/2021 Update CA Certs and Fingerprint for EP32 and ESP8266 secured exampled.
  1.2.4   K Hoang      05/05/2021 Add InSecure mode for ESP32 and examples for ESP32/ESP8266
  1.3.0   K Hoang      20/05/2021 Add support to WiFi101
  1.4.0   K Hoang      25/05/2021 Add support to RP2040-based boards using Arduino-pico and Arduino mbed_rp2040 core
  1.5.0   K Hoang      08/07/2021 Add support to WT32_ETH01 (ESP32 + LAN8720) boards
  1.6.0   K Hoang      06/09/2021 Add support to QNEthernet Library for Teensy 4.1
  1.7.0   K Hoang      18/09/2021 Add support to Portenta_H7, using either WiFi or Vision-shield Ethernet
  1.8.0   K Hoang      03/10/2021 Add support to RP2040, using WiFiNINA, such as Nano_RP2040_Connect
  1.8.1   K Hoang      12/10/2021 Update `platform.ini` and `library.json`
  1.9.0   K Hoang      30/11/2021 Auto detect ESP32 core version. Fix bug in examples
  1.9.1   K Hoang      17/12/2021 Fix QNEthernet TCP interface
  1.10.0  K Hoang      18/12/2021 Supporting case-insensitive headers, according to RFC2616
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
          client.write(reinterpret_cast<uint8_t*>(const_cast<char*>(data.c_str())), data.size());
        }
    
        void send(const WSString&& data) override
        {
          client.write(reinterpret_cast<uint8_t*>(const_cast<char*>(data.c_str())), data.size());
        }
    
        void send(const uint8_t* data, const uint32_t len) override
        {
          client.write(data, len);
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
          client.close();
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
