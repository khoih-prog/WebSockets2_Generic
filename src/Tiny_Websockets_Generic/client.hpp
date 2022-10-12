/****************************************************************************************************************************
  client.hpp
  For WebSockets2_Generic Library
  
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

#ifndef _CLIENT_HPP_
#define _CLIENT_HPP_

#pragma once

/////////////////////////////////////////////////////

#include <Tiny_Websockets_Generic/network/tcp_client.hpp>
#include <Tiny_Websockets_Generic/internals/data_frame.hpp>
#include <Tiny_Websockets_Generic/internals/websockets_endpoint.hpp>
#include <Tiny_Websockets_Generic/message.hpp>
#include <memory>
#include <functional>
#include <vector>

/////////////////////////////////////////////////////

#if (WEBSOCKETS_USE_ETHERNET || WEBSOCKETS_USE_PORTENTA_H7_ETHERNET)
  #if USE_UIP_ETHERNET
    // KH, from v1.0.2
    #warning WEBSOCKETS_USE_ETHERNET and USE_UIP_ETHERNET in client.hpp
    #include <Tiny_Websockets_Generic/internals/ws_common_UIPEthernet.hpp>
  #elif USE_ETHERNET_ENC
    // KH, from v1.11.1
    #warning WEBSOCKETS_USE_ETHERNET and USE_ETHERNET_ENC in client.hpp
    #include <Tiny_Websockets_Generic/internals/ws_common_EthernetENC.hpp>  
  #elif ( USING_LAN8720 )
    // KH, from v1.0.3
    #warning WEBSOCKETS_USE_ETHERNET and USING_LAN8720 in client.hpp
    #include <Tiny_Websockets_Generic/internals/ws_common_LAN8742AEthernet.hpp>
  #elif ( USE_LAN8742A_ETHERNET )
    // KH, from v1.0.3
    #warning WEBSOCKETS_USE_ETHERNET and USE_LAN8742A_ETHERNET in client.hpp
    #include <Tiny_Websockets_Generic/internals/ws_common_LAN8742AEthernet.hpp>  
  #elif USE_NATIVE_ETHERNET
    // KH, from v1.1.0
    #warning WEBSOCKETS_USE_ETHERNET and USE_NATIVE_ETHERNET in client.hpp
    #include <Tiny_Websockets_Generic/internals/ws_common_NativeEthernet.hpp>
  #elif USE_QN_ETHERNET
    // KH, from v1.6.0
    #warning WEBSOCKETS_USE_ETHERNET and USE_QN_ETHERNET in client.hpp
    #include <Tiny_Websockets_Generic/internals/ws_common_QNEthernet.hpp>
  #elif (USE_ETHERNET_PORTENTA_H7 || WEBSOCKETS_USE_PORTENTA_H7_ETHERNET)
    // KH, from v1.7.0
    #warning WEBSOCKETS_USE_ETHERNET and USE_ETHERNET_PORTENTA_H7 in client.hpp
    #include <Tiny_Websockets_Generic/internals/ws_common_Ethernet_Portenta_H7.hpp>
  #else
    #warning WEBSOCKETS_USE_ETHERNET in client.hpp
    #include <Tiny_Websockets_Generic/internals/ws_common_Ethernet_W5x00.hpp>
  #endif

/////////////////////////////////////////////////////
  
#elif WEBSOCKETS_USE_RP2040W
  #warning WEBSOCKETS_USE_RP2040W in client.hpp
  #include <Tiny_Websockets_Generic/internals/ws_common_RP2040W.hpp> 

/////////////////////////////////////////////////////
    
#elif WEBSOCKETS_USE_WIFININA
  #warning WEBSOCKETS_USE_WIFININA in client.hpp
  #include <Tiny_Websockets_Generic/internals/ws_common_WiFiNINA.hpp>

/////////////////////////////////////////////////////
  
#elif WEBSOCKETS_USE_WIFI101
  #warning WEBSOCKETS_USE_WIFI101 in client.hpp
  #include <Tiny_Websockets_Generic/internals/ws_common_WiFi101.hpp>

/////////////////////////////////////////////////////
  
#elif WEBSOCKETS_USE_PORTENTA_H7_WIFI
  #warning WEBSOCKETS_USE_PORTENTA_H7_WIFI in client.hpp
  #include <Tiny_Websockets_Generic/internals/ws_common_WiFi_Portenta_H7.hpp> 

/////////////////////////////////////////////////////
  
#else
  #warning WEBSOCKETS_USE_ESP_WIFI in client.hpp
  #include <Tiny_Websockets_Generic/internals/ws_common.hpp>  
#endif

/////////////////////////////////////////////////////

namespace websockets2_generic 
{
  enum class WebsocketsEvent 
  {
    ConnectionOpened,
    ConnectionClosed,
    GotPing, GotPong
  };

  /////////////////////////////////////////////////////
  
  class WebsocketsClient;
  typedef std::function<void(WebsocketsClient&, WebsocketsMessage)> MessageCallback;
  typedef std::function<void(WebsocketsMessage)> PartialMessageCallback;
  
  typedef std::function<void(WebsocketsClient&, WebsocketsEvent, WSInterfaceString)> EventCallback;
  typedef std::function<void(WebsocketsEvent, WSInterfaceString)> PartialEventCallback;

  /////////////////////////////////////////////////////
   
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
      bool connectSecure(const WSInterfaceString host, const int port, const WSInterfaceString path);
  
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
  
      WebsocketsMessage readNonBlocking();
      
      WebsocketsMessage readBlocking();
  
      bool ping(const WSInterfaceString data = "");
      bool pong(const WSInterfaceString data = "");
  
      void close(const CloseReason reason = CloseReason_NormalClosure);
      CloseReason getCloseReason() const;
        
      /////////////////////////////////////////////////////
 
      void setUseMasking(bool useMasking) 
      {
        _endpoint.setUseMasking(useMasking);
      }
        
      /////////////////////////////////////////////////////
   
      void setInsecure();
      
  #ifdef ESP8266
      void setFingerprint(const char* fingerprint);
      void setClientRSACert(const X509List *cert, const PrivateKey *sk);
      // KH, New in v1.0.5 (sync with v0.4.18)
      void setClientECCert(const X509List *cert, const PrivateKey *sk);
      void setTrustAnchors(const X509List *ta);
      void setKnownKey(const PublicKey *pk);
      //////
  #elif defined(ESP32)
      void setCACert(const char* ca_cert);
      void setCertificate(const char* client_ca);
      void setPrivateKey(const char* private_key);
  #endif
  
      virtual ~WebsocketsClient();
      
      void setAuthorization(const char * user, const char * password);
      WSString getAuthorization(void);
  
    private:

      WSString base64Authorization;    ///< Base64 encoded Auth request
    
      std::shared_ptr<network2_generic::TcpClient> _client;
      std::vector<std::pair<WSString, WSString>> _customHeaders;
      internals2_generic::WebsocketsEndpoint _endpoint;
      bool _connectionOpen;
      MessageCallback _messagesCallback;
      EventCallback _eventsCallback;
        
      /////////////////////////////////////////////////////
       
      enum SendMode 
      {
        SendMode_Normal,
        SendMode_Streaming
      } _sendMode; 
        
      /////////////////////////////////////////////////////
   
  #ifdef ESP8266
      const char* _optional_ssl_fingerprint = nullptr;
      const X509List* _optional_ssl_trust_anchors = nullptr;
      
      // KH, New in v1.0.5 (sync with v0.4.18)
      const PublicKey*  _optional_ssl_known_key       = nullptr;
      const X509List*   _optional_ssl_rsa_cert        = nullptr;
      const PrivateKey* _optional_ssl_rsa_private_key = nullptr;
      const X509List*   _optional_ssl_ec_cert         = nullptr;
      const PrivateKey* _optional_ssl_ec_private_key  = nullptr; 
      //////
  #elif defined(ESP32)
      const char* _optional_ssl_ca_cert     = nullptr;
      const char* _optional_ssl_client_ca   = nullptr;
      const char* _optional_ssl_private_key = nullptr;
  #endif
  
      void _handlePing(WebsocketsMessage);
      void _handlePong(WebsocketsMessage);
      void _handleClose(WebsocketsMessage);
      
      void upgradeToSecuredConnection();
  };
  
  /////////////////////////////////////////////////////
 
}   // namespace websockets2_generic 

#endif    // _CLIENT_HPP_
