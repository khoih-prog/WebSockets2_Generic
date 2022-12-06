/****************************************************************************************************************************
  websockets_endpoint.hpp
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

#include <Tiny_Websockets_Generic/internals/ws_common.hpp>
#include <Tiny_Websockets_Generic/network/tcp_client.hpp>
#include <Tiny_Websockets_Generic/internals/data_frame.hpp>
#include <Tiny_Websockets_Generic/message.hpp>
#include <memory>

#define __TINY_WS_INTERNAL_DEFAULT_MASK "\00\00\00\00"

namespace websockets2_generic 
{
  enum FragmentsPolicy 
  {
    FragmentsPolicy_Aggregate,
    FragmentsPolicy_Notify
  };
  
  enum CloseReason 
  {
    CloseReason_None                =       -1,
    CloseReason_NormalClosure       =       1000,
    CloseReason_GoingAway           =       1001,
    CloseReason_ProtocolError       =       1002,
    CloseReason_UnsupportedData     =       1003,
    CloseReason_NoStatusRcvd        =       1005,
    CloseReason_AbnormalClosure     =       1006,
    CloseReason_InvalidPayloadData  =       1007,
    CloseReason_PolicyViolation     =       1008,
    CloseReason_MessageTooBig       =       1009,
    CloseReason_InternalServerError =       1011,
  };
  
  CloseReason GetCloseReason(uint16_t reasonCode);
  
  namespace internals2_generic 
  {
  
    class WebsocketsEndpoint 
    {
      public:
        WebsocketsEndpoint(std::shared_ptr<network2_generic::TcpClient> socket, FragmentsPolicy fragmentsPolicy = FragmentsPolicy_Aggregate);
    
        WebsocketsEndpoint(const WebsocketsEndpoint& other);
        WebsocketsEndpoint(const WebsocketsEndpoint&& other);
    
        WebsocketsEndpoint& operator=(const WebsocketsEndpoint& other);
        WebsocketsEndpoint& operator=(const WebsocketsEndpoint&& other);
    
        void setInternalSocket(std::shared_ptr<network2_generic::TcpClient> socket);
    
        bool poll();
        WebsocketsMessage recv();
        bool send(const char* data, const size_t len, const uint8_t opcode, const bool fin, const bool mask, const char* maskingKey = __TINY_WS_INTERNAL_DEFAULT_MASK);
        bool send(const WSString& data, const uint8_t opcode, const bool fin, const bool mask, const char* maskingKey = __TINY_WS_INTERNAL_DEFAULT_MASK);
    
        bool send(const char* data, const size_t len, const uint8_t opcode, const bool fin);
        bool send(const WSString& data, const uint8_t opcode, const bool fin);
    
        bool ping(const WSString& msg);
        bool ping(const WSString&& msg);
    
        bool pong(const WSString& msg);
        bool pong(const WSString&& msg);
    
        void close(const CloseReason reason = CloseReason_NormalClosure);
        CloseReason getCloseReason() const;
    
        void setFragmentsPolicy(const FragmentsPolicy newPolicy);
        FragmentsPolicy getFragmentsPolicy() const;
    
        void setUseMasking(bool useMasking) 
        {
          _useMasking = useMasking;
        }
    
        virtual ~WebsocketsEndpoint();
        
      private:
        std::shared_ptr<network2_generic::TcpClient> _client;
        FragmentsPolicy _fragmentsPolicy;
        
        enum RecvMode 
        {
          RecvMode_Normal,
          RecvMode_Streaming
        } _recvMode;
        
        WebsocketsMessage::StreamBuilder _streamBuilder;
        CloseReason _closeReason;
        bool _useMasking = true;
    
        WebsocketsFrame _recv();
        void handleMessageInternally(WebsocketsMessage& msg);
    
        WebsocketsMessage handleFrameInStreamingMode(WebsocketsFrame& frame);
        WebsocketsMessage handleFrameInStandardMode(WebsocketsFrame& frame);
    
        std::string getHeader(uint64_t len, uint8_t opcode, bool fin, bool mask);
    };    // class WebsocketsEndpoint
  }       // namespace internals2_generic 
}         // websockets::internals
