/****************************************************************************************************************************
  message.hpp
  For WebSockets2_Generic Library
  
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

#ifndef _MESSAGE_HPP_
#define _MESSAGE_HPP_

#pragma once

#include <Tiny_Websockets_Generic/internals/data_frame.hpp>

// KH, from v1.0.1
#if WEBSOCKETS_USE_ETHERNET
  #if USE_UIP_ETHERNET
    // KH, from v1.0.2
    #warning WEBSOCKETS_USE_ETHERNET and USE_UIP_ETHERNET in message.hpp
    #include <Tiny_Websockets_Generic/internals/ws_common_UIPEthernet.hpp>
  #elif USE_LAN8742A_ETHERNET
    // KH, from v1.0.3
    #warning WEBSOCKETS_USE_ETHERNET and USE_LAN8742A_ETHERNET in message.hpp
    #include <Tiny_Websockets_Generic/internals/ws_common_LAN8742AEthernet.hpp>
  #else
    #warning WEBSOCKETS_USE_ETHERNET in message.hpp
    #include <Tiny_Websockets_Generic/internals/ws_common_Ethernet_W5x00.hpp>
  #endif
#elif WEBSOCKETS_USE_WIFININA
  #warning WEBSOCKETS_USE_WIFININA in message.hpp
  #include <Tiny_Websockets_Generic/internals/ws_common_WiFiNINA.hpp>
#else
  #warning WEBSOCKETS_USE_ESP_WIFI in message.hpp
  #include <Tiny_Websockets_Generic/internals/ws_common.hpp>  
#endif
//////

namespace websockets2_generic
{
  enum class MessageType
  {
    Empty,
    Text, Binary,
    Ping, Pong, Close
  };
  
  MessageType messageTypeFromOpcode(uint8_t opcode);
  
  enum class MessageRole
  {
    Complete, First, Continuation, Last
  };
  
  // The class the user will interact with as a message
  // This message can be partial (so practically this is a Frame and not a message)
  struct WebsocketsMessage
  {
    WebsocketsMessage(MessageType msgType, const WSString& msgData, MessageRole msgRole = MessageRole::Complete) : _type(msgType), _length(msgData.size()), _data(msgData), _role(msgRole) {}
    WebsocketsMessage() : WebsocketsMessage(MessageType::Empty, "", MessageRole::Complete) {}

    static WebsocketsMessage CreateFromFrame(internals2_generic::WebsocketsFrame frame, MessageType overrideType = MessageType::Empty) 
    {
      auto type = overrideType;
      
      if (type == MessageType::Empty)
      {
        type = messageTypeFromOpcode(frame.opcode);
      }

      // deduce role
      MessageRole msgRole = MessageRole::Complete;
      if (frame.isNormalUnfragmentedMessage()) 
      {
        msgRole = MessageRole::Complete;
      } 
      else if (frame.isBeginningOfFragmentsStream()) 
      {
        msgRole = MessageRole::First;
      } 
      else if (frame.isContinuesFragment()) 
      {
        msgRole = MessageRole::Continuation;
      } 
      else if (frame.isEndOfFragmentsStream()) 
      {
        msgRole = MessageRole::Last;
      }

      return WebsocketsMessage(type, std::move(frame.payload), msgRole);
    }

    // for validation
    bool isEmpty() const 
    {
      return this->_type == MessageType::Empty;
    }

    // Type Helper Functions
    MessageType type() const 
    {
      return this->_type;
    }

    bool isText() const 
    {
      return this->_type == MessageType::Text;
    }
    
    bool isBinary() const 
    {
      return this->_type == MessageType::Binary;
    }

    bool isPing() const 
    {
      return this->_type == MessageType::Ping;
    }
    
    bool isPong() const 
    {
      return this->_type == MessageType::Pong;
    }

    bool isClose() const 
    {
      return this->_type == MessageType::Close;
    }

    // Role Helper Function
    MessageRole role() const 
    {
      return this->_role;
    }

    bool isComplete() const 
    {
      return this->_role == MessageRole::Complete;
    }
    
    bool isPartial() const 
    {
      return this->_role != MessageRole::Complete;
    }
    
    bool isFirst() const 
    {
      return this->_role == MessageRole::First;
    }
    
    bool isContinuation() const 
    {
      return this->_role == MessageRole::Continuation;
    }
    
    bool isLast() const 
    {
      return this->_role == MessageRole::Last;
    }

    WSInterfaceString data() const 
    {
      return internals2_generic::fromInternalString(this->_data);
    }
    
    const WSString& rawData() const 
    {
      return this->_data;
    }
    
    const char* c_str() const 
    {
      return this->_data.c_str();
    }

    uint32_t length() const 
    {
      return this->_length;
    }

    class StreamBuilder 
    {
      public:
        StreamBuilder(bool dummyMode = false) : _dummyMode(dummyMode), _empty(true) {}

        void first(const internals2_generic::WebsocketsFrame& frame) 
        {
          if (this->_empty == false) 
          {
            badFragment();
            return;
          }

          this->_empty = false;
          
          if (frame.isBeginningOfFragmentsStream()) 
          {
            this->_isComplete = false;
            this->_didErrored = false;

            if (this->_dummyMode == false) 
            {
              this->_content = std::move(frame.payload);
            }

            this->_type = messageTypeFromOpcode(frame.opcode);
            
            if (this->_type == MessageType::Empty) 
            {
              badFragment();
            }
          } 
          else 
          {
            this->_didErrored = true;
          }
        }

        void append(const internals2_generic::WebsocketsFrame& frame) 
        {
          if (isErrored()) 
            return;
            
          if (isEmpty() || isComplete()) 
          {
            badFragment();
            return;
          }

          if (frame.isContinuesFragment()) 
          {
            if (this->_dummyMode == false) 
            {
              this->_content += std::move(frame.payload);
            }
          } 
          else 
          {
            badFragment();
          }
        }

        void end(const internals2_generic::WebsocketsFrame& frame) 
        {
          if (isErrored()) 
            return;
            
          if (isEmpty() || isComplete()) 
          {
            badFragment();
            return;
          }

          if (frame.isEndOfFragmentsStream()) 
          {
            if (this->_dummyMode == false) 
            {
              this->_content += std::move(frame.payload);
            }
            
            this->_isComplete = true;
          } 
          else 
          {
            badFragment();
          }
        }

        void badFragment() 
        {
          this->_didErrored = true;
          this->_isComplete = false;
        }

        bool isErrored() 
        {
          return this->_didErrored;
        }

        bool isOk() 
        {
          return !this->_didErrored;
        }

        bool isComplete() 
        {
          return this->_isComplete;
        }

        bool isEmpty() 
        {
          return this->_empty;
        }

        MessageType type() 
        {
          return this->_type;
        }

        WebsocketsMessage build() 
        {
          return WebsocketsMessage(
                   this->_type,
                   std::move(this->_content),
                   MessageRole::Complete
                 );
        }

      private:
        bool _dummyMode;
        bool _empty;
        bool _isComplete = false;
        WSString _content;
        MessageType _type;
        bool _didErrored;
        
    };    // class StreamBuilder 
  
    private:
      const MessageType _type;
      const uint32_t _length;
      const WSString _data;
      const MessageRole _role;
      
  };    // struct WebsocketsMessage
}       // namespace websockets2_generic

#endif    // _MESSAGE_HPP_
