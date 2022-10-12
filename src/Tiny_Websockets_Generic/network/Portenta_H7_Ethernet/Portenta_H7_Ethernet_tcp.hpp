/****************************************************************************************************************************
  Portenta_H7_Ethernet_tcp.hpp
  For Portenta_H7 boards with Vision-shield Ethernet.
  
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

#if ( ( defined(ARDUINO_PORTENTA_H7_M7) || defined(ARDUINO_PORTENTA_H7_M4) ) && defined(ARDUINO_ARCH_MBED) ) && USE_ETHERNET_PORTENTA_H7

#include <Tiny_Websockets_Generic/internals/ws_common.hpp>
#include <Tiny_Websockets_Generic/network/tcp_client.hpp>
#include <Tiny_Websockets_Generic/network/tcp_server.hpp>

#include <PortentaEthernet.h>
#include <EthernetClient.h>
#include <EthernetServer.h>

namespace websockets2_generic
{
  namespace network2_generic
  {
    class EthernetTcpClient : public TcpClient
    {
      public:
        EthernetTcpClient(EthernetClient c) : client(c) {}
    
        EthernetTcpClient() {}
    
        bool connect(const WSString& host, const int port)
        {
          yield();
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
    
          while ( ch != '\n' && available())
          {
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
          yield();
          return client.read(buffer, len);
        }
    
        void close() override
        {
          yield();
          client.stop();
        }
    
        virtual ~EthernetTcpClient()
        {
          client.stop();
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
        //EthernetTcpServer() {}
        EthernetTcpServer() : server(DUMMY_PORT) {}
    
        bool poll() override 
        {
          yield();
          
          return server.available();
        }
    
        bool listen(const uint16_t port) override 
        {
          yield();
          server = EthernetServer(port);
          //server.begin(port);
          server.begin();
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
          // Not Implemented
        }
    
        virtual ~EthernetTcpServer() 
        {
          // Not Implemented
        }
    
      protected:
        int getSocket() const override 
        {
          return -1; // Not Implemented
        }
    
      private:
        EthernetServer server;
    };
  }
} // websockets2_generic::network2_generic

#else
  #error This is designed only for Portenta_H7. Please check your Tools-> Boards  
#endif // #if ( ( defined(ARDUINO_PORTENTA_H7_M7) || defined(ARDUINO_PORTENTA_H7_M4) ) && defined(ARDUINO_ARCH_MBED) ) && USE_ETHERNET_PORTENTA_H7
