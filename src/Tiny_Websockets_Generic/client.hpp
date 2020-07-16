/****************************************************************************************************************************
  client.hpp
  For WebSockets2_Generic Library
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
  Version: 1.0.1

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/07/2020 Initial coding/porting to support nRF52 and SAMD21/SAMD51 boards. Add SINRIC/Alexa support
  1.0.1   K Hoang      16/07/2020 Add support to Ethernet W5x00 to nRF52 and SAMD21/SAMD51 boards    
 *****************************************************************************************************************************/

#ifndef _CLIENT_HPP_
#define _CLIENT_HPP_

#pragma once

// KH, from v1.0.1
#if WEBSOCKETS_USE_ETHERNET
  #warning WEBSOCKETS_USE_ETHERNET in client.hpp
  #include <Tiny_Websockets_Generic/internals/ws_common_Ethernet_W5x00.hpp>
#elif WEBSOCKETS_USE_WIFININA
  #warning WEBSOCKETS_USE_WIFININA in client.hpp
  #include <Tiny_Websockets_Generic/internals/ws_common_WiFiNINA.hpp>
#else
  #warning WEBSOCKETS_USE_ESP_WIFI in client.hpp
  #include <Tiny_Websockets_Generic/internals/ws_common.hpp>  
#endif
//////

#include <Tiny_Websockets_Generic/network/tcp_client.hpp>
#include <Tiny_Websockets_Generic/internals/data_frame.hpp>
#include <Tiny_Websockets_Generic/internals/websockets_endpoint.hpp>
#include <Tiny_Websockets_Generic/message.hpp>
#include <memory>
#include <functional>
#include <vector>

namespace websockets2_generic 
{
  enum class WebsocketsEvent 
  {
    ConnectionOpened,
    ConnectionClosed,
    GotPing, GotPong
  };
  
  class WebsocketsClient;
  typedef std::function<void(WebsocketsClient&, WebsocketsMessage)> MessageCallback;
  typedef std::function<void(WebsocketsMessage)> PartialMessageCallback;
  
  typedef std::function<void(WebsocketsClient&, WebsocketsEvent, WSInterfaceString)> EventCallback;
  typedef std::function<void(WebsocketsEvent, WSInterfaceString)> PartialEventCallback;
  
  class WebsocketsClient 
  {
    public:
      WebsocketsClient();
      WebsocketsClient(std::shared_ptr<network2_generic::TcpClient> client);
  
      WebsocketsClient(const WebsocketsClient& other);
      WebsocketsClient(const WebsocketsClient&& other);
  
      WebsocketsClient& operator=(const WebsocketsClient& other);
      WebsocketsClient& operator=(const WebsocketsClient&& other);
  
      void addHeader(const WSInterfaceString key, const WSInterfaceString value);
  
      bool connect(const WSInterfaceString url);
      bool connect(const WSInterfaceString host, const int port, const WSInterfaceString path);
  
      void onMessage(const MessageCallback callback);
      void onMessage(const PartialMessageCallback callback);
  
      void onEvent(const EventCallback callback);
      void onEvent(const PartialEventCallback callback);
  
      bool poll();
      bool available(const bool activeTest = false);
  
      bool send(const WSInterfaceString&& data);
      bool send(const WSInterfaceString& data);
      bool send(const char* data);
      bool send(const char* data, const size_t len);
  
      bool sendBinary(const WSInterfaceString data);
      bool sendBinary(const char* data, const size_t len);
  
      // stream messages
      bool stream(const WSInterfaceString data = "");
      bool streamBinary(const WSInterfaceString data = "");
      bool end(const WSInterfaceString data = "");
  
      void setFragmentsPolicy(const FragmentsPolicy newPolicy);
      FragmentsPolicy getFragmentsPolicy() const;
  
      WebsocketsMessage readBlocking();
  
      bool ping(const WSInterfaceString data = "");
      bool pong(const WSInterfaceString data = "");
  
      void close(const CloseReason reason = CloseReason_NormalClosure);
      CloseReason getCloseReason() const;
  
      void setUseMasking(bool useMasking) 
      {
        _endpoint.setUseMasking(useMasking);
      }
  
      void setInsecure();
  #ifdef ESP8266
      void setFingerprint(const char* fingerprint);
      void setClientRSACert(const X509List *cert, const PrivateKey *sk);
      void setTrustAnchors(const X509List *ta);
  #elif defined(ESP32)
      void setCACert(const char* ca_cert);
      void setCertificate(const char* client_ca);
      void setPrivateKey(const char* private_key);
  #endif
  
      virtual ~WebsocketsClient();
      
      // KH add
      void setAuthorization(const char * user, const char * password);
      WSString getAuthorization(void);
      //////
  
    private:
      // KH add
      WSString base64Authorization;    ///< Base64 encoded Auth request
      //////
    
      std::shared_ptr<network2_generic::TcpClient> _client;
      std::vector<std::pair<WSString, WSString>> _customHeaders;
      internals2_generic::WebsocketsEndpoint _endpoint;
      bool _connectionOpen;
      MessageCallback _messagesCallback;
      EventCallback _eventsCallback;
      enum SendMode 
      {
        SendMode_Normal,
        SendMode_Streaming
      } _sendMode;
  
  
  #ifdef ESP8266
      const char* _optional_ssl_fingerprint = nullptr;
      const X509List* _optional_ssl_trust_anchors = nullptr;
      const X509List* _optional_ssl_cert = nullptr;
      const PrivateKey* _optional_ssl_private_key = nullptr;
  #elif defined(ESP32)
      const char* _optional_ssl_ca_cert = nullptr;
      const char* _optional_ssl_client_ca = nullptr;
      const char* _optional_ssl_private_key = nullptr;
  #endif
  
      void _handlePing(WebsocketsMessage);
      void _handlePong(WebsocketsMessage);
      void _handleClose(WebsocketsMessage);
  
      void upgradeToSecuredConnection();
  };
}   // namespace websockets2_generic 

#endif    // _CLIENT_HPP_
