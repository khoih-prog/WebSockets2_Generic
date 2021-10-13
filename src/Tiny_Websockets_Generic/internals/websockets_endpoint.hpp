/****************************************************************************************************************************
  websockets_endpoint.hpp
  For WebSockets2_Generic Library
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52, SAMD21/SAMD51, SAM DUE, Teensy, RP2040 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
  Version: 1.8.1

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
