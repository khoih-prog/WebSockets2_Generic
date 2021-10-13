/****************************************************************************************************************************
  WebSockets2_Generic_Endpoint.hpp
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

#ifndef _WEBSOCKETS2_GENERIC_ENDPOINT_H
#define _WEBSOCKETS2_GENERIC_ENDPOINT_H

#pragma once

// KH
#include <WebSockets2_Generic.h>

#include <Tiny_Websockets_Generic/internals/websockets_endpoint.hpp>

namespace websockets2_generic
{
  CloseReason GetCloseReason(uint16_t reasonCode)
  {
    switch (reasonCode)
    {
      case CloseReason_NormalClosure:
        return CloseReason_NormalClosure;
  
      case CloseReason_GoingAway:
        return CloseReason_GoingAway;
  
      case CloseReason_ProtocolError:
        return CloseReason_ProtocolError;
  
      case CloseReason_UnsupportedData:
        return CloseReason_UnsupportedData;
  
      case CloseReason_AbnormalClosure:
        return CloseReason_AbnormalClosure;
  
      case CloseReason_InvalidPayloadData:
        return CloseReason_InvalidPayloadData;
  
      case CloseReason_PolicyViolation:
        return CloseReason_PolicyViolation;
  
      case CloseReason_MessageTooBig:
        return CloseReason_MessageTooBig;
  
      case CloseReason_NoStatusRcvd:
        return CloseReason_NoStatusRcvd;
  
      case CloseReason_InternalServerError:
        return CloseReason_InternalServerError;
  
      default: return CloseReason_None;
    }
  }
  
  namespace internals2_generic
  {
    uint32_t swapEndianess(uint32_t num)
    {
      uint32_t highest = (num >> 24);
      uint32_t second = (num << 8) >> 24;
      uint32_t third = (num << 16) >> 24;
      uint32_t lowest = (num << 24) >> 24;
    
      return highest | (second << 8) | (third << 16) | (lowest << 24);
    }
    
    uint64_t swapEndianess(uint64_t num)
    {
      uint32_t upper = (num >> 32);
      uint32_t lower = (num << 32) >> 32;
    
      upper = swapEndianess(upper);
      lower = swapEndianess(lower);
    
      uint64_t upperLong = upper;
      uint64_t lowerLong = lower;
    
      return upperLong | (lowerLong << 32);
    }
    
    WebsocketsEndpoint::WebsocketsEndpoint(std::shared_ptr<network2_generic::TcpClient> client, FragmentsPolicy fragmentsPolicy) :
      _client(client),
      _fragmentsPolicy(fragmentsPolicy),
      _recvMode(RecvMode_Normal),
      _streamBuilder(fragmentsPolicy == FragmentsPolicy_Notify ? true : false),
      _closeReason(CloseReason_None)
    {
      // Empty
    }
    
    WebsocketsEndpoint::WebsocketsEndpoint(const WebsocketsEndpoint& other) :
      _client(other._client),
      _fragmentsPolicy(other._fragmentsPolicy),
      _recvMode(other._recvMode),
      _streamBuilder(other._streamBuilder),
      _closeReason(other._closeReason),
      _useMasking(other._useMasking)
    {
      const_cast<WebsocketsEndpoint&>(other)._client = nullptr;
    }
    
    WebsocketsEndpoint::WebsocketsEndpoint(const WebsocketsEndpoint&& other) :
      _client(other._client),
      _fragmentsPolicy(other._fragmentsPolicy),
      _recvMode(other._recvMode),
      _streamBuilder(other._streamBuilder),
      _closeReason(other._closeReason),
      _useMasking(other._useMasking)
    {
      const_cast<WebsocketsEndpoint&>(other)._client = nullptr;
    }
    
    WebsocketsEndpoint& WebsocketsEndpoint::operator=(const WebsocketsEndpoint& other) {
      this->_client = other._client;
      this->_fragmentsPolicy = other._fragmentsPolicy;
      this->_recvMode = other._recvMode;
      this->_streamBuilder = other._streamBuilder;
      this->_closeReason = other._closeReason;
      this->_useMasking = other._useMasking;
    
      const_cast<WebsocketsEndpoint&>(other)._client = nullptr;
    
      return *this;
    }
    
    WebsocketsEndpoint& WebsocketsEndpoint::operator=(const WebsocketsEndpoint&& other) 
    {
      this->_client = other._client;
      this->_fragmentsPolicy = other._fragmentsPolicy;
      this->_recvMode = other._recvMode;
      this->_streamBuilder = other._streamBuilder;
      this->_closeReason = other._closeReason;
      this->_useMasking = other._useMasking;
    
      const_cast<WebsocketsEndpoint&>(other)._client = nullptr;
    
      return *this;
    }
    
    void WebsocketsEndpoint::setInternalSocket(std::shared_ptr<network2_generic::TcpClient> socket) 
    {
      this->_client = socket;
    }
    
    bool WebsocketsEndpoint::poll() 
    {
      return this->_client->poll();
    }
    
    uint32_t readUntilSuccessfullOrError(network2_generic::TcpClient& socket, uint8_t* buffer, const uint32_t len) 
    {
      auto numRead = socket.read(buffer, len);
      
      while (numRead == static_cast<uint32_t>(-1) && socket.available()) 
      {
        numRead = socket.read(buffer, len);
      }
      
      return numRead;
    }
    
    Header readHeaderFromSocket(network2_generic::TcpClient& socket) 
    {
      Header header;
      header.payload = 0;
      
      readUntilSuccessfullOrError(socket, reinterpret_cast<uint8_t*>(&header), 2);
      
      return header;
    }
    
    uint64_t readExtendedPayloadLength(network2_generic::TcpClient& socket, const Header& header) 
    {
      uint64_t extendedPayload = header.payload;
      
      // in case of extended payload length
      if (header.payload == 126) 
      {
        // read next 16 bits as payload length
        uint16_t tmp = 0;
        readUntilSuccessfullOrError(socket, reinterpret_cast<uint8_t*>(&tmp), 2);
        tmp = (tmp << 8) | (tmp >> 8);
        extendedPayload = tmp;
      }
      else if (header.payload == 127) 
      {
        uint64_t tmp = 0;
        readUntilSuccessfullOrError(socket, reinterpret_cast<uint8_t*>(&tmp), 8);
        extendedPayload = swapEndianess(tmp);
      }
    
      return extendedPayload;
    }
    
    void readMaskingKey(network2_generic::TcpClient& socket, uint8_t* outputBuffer) 
    {
      readUntilSuccessfullOrError(socket, reinterpret_cast<uint8_t*>(outputBuffer), 4);
    }
    
    WSString readData(network2_generic::TcpClient& socket, uint64_t extendedPayload) 
    {
      const uint64_t BUFFER_SIZE = _WS_BUFFER_SIZE;
    
      WSString data(extendedPayload, '\0');
      uint8_t buffer[BUFFER_SIZE];
      uint64_t done_reading = 0;
      
      while (done_reading < extendedPayload && socket.available()) 
      {
        uint64_t to_read = extendedPayload - done_reading >= BUFFER_SIZE ? BUFFER_SIZE : extendedPayload - done_reading;
        uint32_t numReceived = readUntilSuccessfullOrError(socket, buffer, to_read);
    
        // On failed reads, skip
        if (!socket.available()) 
          break;
    
        for (uint64_t i = 0; i < numReceived; i++) 
        {
          data[done_reading + i] = static_cast<char>(buffer[i]);
        }
    
        done_reading += numReceived;
      }
      
      // KH, Don't need return std::move(data);
      return data;
    }
    
    void remaskData(WSString& data, const uint8_t* const maskingKey, uint64_t payloadLength) 
    {
      for (uint64_t i = 0; i < payloadLength; i++) 
      {
        data[i] = data[i] ^ maskingKey[i % 4];
      }
    }
    
    WebsocketsFrame WebsocketsEndpoint::_recv() 
    {
      auto header = readHeaderFromSocket(*this->_client);
      
      if (!_client->available()) 
        return WebsocketsFrame(); // In case of faliure
    
      uint64_t payloadLength = readExtendedPayloadLength(*this->_client, header);
      
      if (!_client->available()) 
        return WebsocketsFrame(); // In case of faliure
    
    #ifdef _WS_CONFIG_MAX_MESSAGE_SIZE
      if (payloadLength > _WS_CONFIG_MAX_MESSAGE_SIZE) 
      {
        return WebsocketsFrame();
      }
    #endif
    
      uint8_t maskingKey[4];
      
      // if masking is set
      if (header.mask) 
      {
        readMaskingKey(*this->_client, maskingKey);
        
        if (!_client->available()) 
          return WebsocketsFrame(); // In case of faliure
      }
    
      WebsocketsFrame frame;
      // read the message's payload (data) according to the read length
      frame.payload = readData(*this->_client, payloadLength);
      
      if (!_client->available()) 
        return WebsocketsFrame(); // In case of faliure
    
      // if masking is set un-mask the message
      if (header.mask) 
      {
        remaskData(frame.payload, maskingKey, payloadLength);
      }
    
      // Construct frame from data and header that was read
      frame.fin = header.fin;
      frame.mask = header.mask;
    
      frame.mask_buf[0] = maskingKey[0];
      frame.mask_buf[1] = maskingKey[1];
      frame.mask_buf[2] = maskingKey[2];
      frame.mask_buf[3] = maskingKey[3];
    
      frame.opcode = header.opcode;
      frame.payload_length = payloadLength;
    
      // KH, Don't need return std::move(frame);
      return frame;
    }
    
    WebsocketsMessage WebsocketsEndpoint::handleFrameInStreamingMode(WebsocketsFrame& frame) 
    {
      
      if (frame.isControlFrame()) 
      {
        auto msg = WebsocketsMessage::CreateFromFrame(std::move(frame));
        this->handleMessageInternally(msg);
        
        // KH, Don't need return std::move(msg);
        return msg;
        
      }
      else if (frame.isBeginningOfFragmentsStream()) 
      {
        this->_recvMode = RecvMode_Streaming;
    
        if (this->_streamBuilder.isEmpty()) 
        {
          this->_streamBuilder.first(frame);
          
          // if policy is set to notify, return the frame to the user
          if (this->_fragmentsPolicy == FragmentsPolicy_Notify) 
          {
            return WebsocketsMessage(this->_streamBuilder.type(), std::move(frame.payload), MessageRole::First);
          }
          else 
            return {};
        }
      }
      else if (frame.isContinuesFragment()) 
      {
        this->_streamBuilder.append(frame);
        
        if (this->_streamBuilder.isOk()) 
        {
          // if policy is set to notify, return the frame to the user
          if (this->_fragmentsPolicy == FragmentsPolicy_Notify) 
          {
            return WebsocketsMessage(this->_streamBuilder.type(), std::move(frame.payload), MessageRole::Continuation);
          }
          else 
            return {};
        }
      }
      else if (frame.isEndOfFragmentsStream()) 
      {
        this->_recvMode = RecvMode_Normal;
        this->_streamBuilder.end(frame);
        
        if (this->_streamBuilder.isOk()) 
        {
          // if policy is set to notify, return the frame to the user
          if (this->_fragmentsPolicy == FragmentsPolicy_Aggregate) 
          {
            auto completeMessage = this->_streamBuilder.build();
            this->_streamBuilder = WebsocketsMessage::StreamBuilder(false);
            this->handleMessageInternally(completeMessage);
            
            return completeMessage;
          }
          else 
          { 
            // in case of notify policy
            auto messageType = this->_streamBuilder.type();
            this->_streamBuilder = WebsocketsMessage::StreamBuilder(true);
            
            return WebsocketsMessage(messageType, std::move(frame.payload), MessageRole::Last);
          }
        }
      }
    
      // Error
      close(CloseReason_ProtocolError);
      
      return {};
    }
    
    WebsocketsMessage WebsocketsEndpoint::handleFrameInStandardMode(WebsocketsFrame& frame) 
    {
      // Normal (unfragmented) frames are handled as a complete message
      if (frame.isNormalUnfragmentedMessage() || frame.isControlFrame()) 
      {
        auto msg = WebsocketsMessage::CreateFromFrame(std::move(frame));
        this->handleMessageInternally(msg);
        
        // KH, Don't need return std::move(msg);
        return msg;
      }
      else if (frame.isBeginningOfFragmentsStream()) 
      {
        return handleFrameInStreamingMode(frame);
      }
    
      // This is an error. a bad combination of opcodes and fin flag arrived.
      close(CloseReason_ProtocolError);
      
      return {};
    }
    
    WebsocketsMessage WebsocketsEndpoint::recv() 
    {
      auto frame = _recv();
      
      if (frame.isEmpty()) 
      {
        return {};
      }
    
      if (this->_recvMode == RecvMode_Normal) 
      {
        return handleFrameInStandardMode(frame);
      }
      else 
      { 
        /* this->_recvMode == RecvMode_Streaming */
        return handleFrameInStreamingMode(frame);
      }
    }
    
    void WebsocketsEndpoint::handleMessageInternally(WebsocketsMessage& msg) 
    {
      if (msg.isPing()) 
      {
        pong(internals2_generic::fromInterfaceString(msg.data()));
      } 
      else if (msg.isClose()) 
      {
        // is there a reason field
        if (internals2_generic::fromInterfaceString(msg.data()).size() >= 2) 
        {
          uint16_t reason = *(reinterpret_cast<const uint16_t*>(msg.data().c_str()));
          reason = reason >> 8 | reason << 8;
          this->_closeReason = GetCloseReason(reason);
        } 
        else 
        {
          this->_closeReason = CloseReason_GoingAway;
        }
        
        close(this->_closeReason);
      }
    }
    
    bool WebsocketsEndpoint::send(const char* data, const size_t len, const uint8_t opcode, const bool fin) 
    {
      return this->send(data, len, opcode, fin, this->_useMasking);
    }
    
    bool WebsocketsEndpoint::send(const WSString& data, const uint8_t opcode, const bool fin) 
    {
      return this->send(data, opcode, fin, this->_useMasking);
    }
    
    bool WebsocketsEndpoint::send(const WSString& data, const uint8_t opcode, const bool fin, const bool mask, const char* maskingKey) 
    {
      return send(data.c_str(), data.size(), opcode, fin, mask, maskingKey);
    }
    
    std::string WebsocketsEndpoint::getHeader(uint64_t len, uint8_t opcode, bool fin, bool mask) 
    {
      std::string header_data;
    
      if (len < 126) 
      {
        auto header = MakeHeader<Header>(len, opcode, fin, mask);
        header_data = std::string(reinterpret_cast<char*>(&header), 2 + 0);
      } 
      else if (len < 65536) 
      {
        auto header = MakeHeader<HeaderWithExtended16>(len, opcode, fin, mask);
        header.extendedPayload = (len << 8) | (len >> 8);
        header_data = std::string(reinterpret_cast<char*>(&header), 2 + 2);
      } 
      else 
      {
        auto header = MakeHeader<HeaderWithExtended64>(len, opcode, fin, mask);
        // header.extendedPayload = swapEndianess(len);
        header.extendedPayload = swapEndianess(len);
    
        header_data = std::string(reinterpret_cast<char*>(&header), 2);
        header_data += std::string(reinterpret_cast<char*>(&header.extendedPayload), 8);
      }
    
      return header_data;
    }
    
    void remaskData(WSString& data, const char* const maskingKey, size_t first, size_t len) 
    {
      for (size_t i = first; i < first + len; i++) 
      {
        data[i] = data[i] ^ maskingKey[i % 4];
      }
    }
    
    bool WebsocketsEndpoint::send(const char* data, const size_t len, const uint8_t opcode, const bool fin, const bool mask, const char* maskingKey) 
    {
    
    #ifdef _WS_CONFIG_MAX_MESSAGE_SIZE
      if (len > _WS_CONFIG_MAX_MESSAGE_SIZE) 
      {
        return false;
      }
    #endif
      // send the header
      std::string message_data = getHeader(len, opcode, fin, mask);
    
      if (mask) 
      {
        message_data += std::string(maskingKey, 4);
      }
    
      size_t data_start = message_data.size();
      message_data += std::string(data, len);
    
      if (mask && memcmp(maskingKey, __TINY_WS_INTERNAL_DEFAULT_MASK, 4) != 0) 
      {
        remaskData(message_data, maskingKey, data_start, len);
      }
    
      this->_client->send(reinterpret_cast<const uint8_t*>(message_data.c_str()), message_data.size());
      
      return true; // TODO dont assume success
    }
    
    void WebsocketsEndpoint::close(CloseReason reason) 
    {
      this->_closeReason = reason;
    
      if (!this->_client->available()) 
        return;
    
      if (reason == CloseReason_None) 
      {
        send(nullptr, 0, internals2_generic::ContentType::Close, true, this->_useMasking);
      } 
      else 
      {
        uint16_t reasonNum = static_cast<uint16_t>(reason);
        reasonNum = (reasonNum >> 8) | (reasonNum << 8);
        send(reinterpret_cast<const char*>(&reasonNum), 2, internals2_generic::ContentType::Close, true, this->_useMasking);
      }
      
      this->_client->close();
    }
    
    CloseReason WebsocketsEndpoint::getCloseReason() const 
    {
      return _closeReason;
    }
    
    bool WebsocketsEndpoint::ping(const WSString& msg) 
    {
      // Ping data must be shorter than 125 bytes
      if (msg.size() > 125) 
      {
        return false;
      }
      else 
      {
        return send(msg, ContentType::Ping, true, this->_useMasking);
      }
    }
    bool WebsocketsEndpoint::ping(const WSString&& msg) 
    {
      // Ping data must be shorter than 125 bytes
      if (msg.size() > 125) 
      {
        return false;
      }
      else 
      {
        return send(msg, ContentType::Ping, true, this->_useMasking);
      }
    }
    
    bool WebsocketsEndpoint::pong(const WSString& msg) 
    {
      // Pong data must be shorter than 125 bytes
      if (msg.size() > 125)  
      {
        return false;
      }
      else 
      {
        return this->send(msg, ContentType::Pong, true, this->_useMasking);
      }
    }
    bool WebsocketsEndpoint::pong(const WSString&& msg) 
    {
      // Pong data must be shorter than 125 bytes
      if (msg.size() > 125)  
      {
        return false;
      }
      else 
      {
        return this->send(msg, ContentType::Pong, true, this->_useMasking);
      }
    }
    
    void WebsocketsEndpoint::setFragmentsPolicy(FragmentsPolicy newPolicy) 
    {
      this->_fragmentsPolicy = newPolicy;
    }
    
    FragmentsPolicy WebsocketsEndpoint::getFragmentsPolicy() const 
    {
      return this->_fragmentsPolicy;
    }
    
    WebsocketsEndpoint::~WebsocketsEndpoint() {}
  }   // namespace internals2_generic
}     // namespace websockets2_generic

#endif    // _WEBSOCKETS2_GENERIC_ENDPOINT_H
