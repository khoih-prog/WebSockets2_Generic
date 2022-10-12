/****************************************************************************************************************************
  WebSockets2_Generic_Client.hpp
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

#ifndef _WEBSOCKETS2_GENERIC_CLIENT_H
#define _WEBSOCKETS2_GENERIC_CLIENT_H

#pragma once

// KH
#include <WebSockets2_Generic.h>
#include "WebSockets2_Generic_Debug.h"

#include <Tiny_Websockets_Generic/internals/ws_common.hpp>
#include <Tiny_Websockets_Generic/network/tcp_client.hpp>
#include <Tiny_Websockets_Generic/message.hpp>
#include <Tiny_Websockets_Generic/client.hpp>
#include <Tiny_Websockets_Generic/internals/wscrypto/crypto.hpp>

namespace websockets2_generic
{
  
  WebsocketsClient::WebsocketsClient() : WebsocketsClient(std::make_shared<WSDefaultTcpClient>())
  {
    // Empty
  }
  
  /////////////////////////////////////////////////////////
  
  WebsocketsClient::WebsocketsClient(std::shared_ptr<network2_generic::TcpClient> client) :
    _client(client),
    _endpoint(client),
    _connectionOpen(client->available()),
    _messagesCallback([](WebsocketsClient &, WebsocketsMessage) {}),
  _eventsCallback([](WebsocketsClient&, WebsocketsEvent, WSInterfaceString) {}),
  _sendMode(SendMode_Normal)
  {
    // Empty
  }
  
  /////////////////////////////////////////////////////////
  
  WebsocketsClient::WebsocketsClient(const WebsocketsClient& other) :
    _client(other._client),
    _endpoint(other._endpoint),
    _connectionOpen(other._client->available()),
    _messagesCallback(other._messagesCallback),
    _eventsCallback(other._eventsCallback),
    _sendMode(other._sendMode)
  {
  
    // delete other's client
    const_cast<WebsocketsClient&>(other)._client = nullptr;
    const_cast<WebsocketsClient&>(other)._connectionOpen = false;
  }
  
  /////////////////////////////////////////////////////////
  
  WebsocketsClient::WebsocketsClient(const WebsocketsClient&& other) :
    _client(other._client),
    _endpoint(other._endpoint),
    _connectionOpen(other._client->available()),
    _messagesCallback(other._messagesCallback),
    _eventsCallback(other._eventsCallback),
    _sendMode(other._sendMode)
  {
  
    // delete other's client
    const_cast<WebsocketsClient&>(other)._client = nullptr;
    const_cast<WebsocketsClient&>(other)._connectionOpen = false;
  }
  
  /////////////////////////////////////////////////////////
  
  WebsocketsClient& WebsocketsClient::operator=(const WebsocketsClient& other)
  {
    // call endpoint's copy operator
    _endpoint = other._endpoint;
  
    // get callbacks and data from other
    this->_client = other._client;
    this->_messagesCallback = other._messagesCallback;
    this->_eventsCallback = other._eventsCallback;
    this->_connectionOpen = other._connectionOpen;
    this->_sendMode = other._sendMode;
  
    // delete other's client
    const_cast<WebsocketsClient&>(other)._client = nullptr;
    const_cast<WebsocketsClient&>(other)._connectionOpen = false;
    
    return *this;
  }
  
  /////////////////////////////////////////////////////////
  
  WebsocketsClient& WebsocketsClient::operator=(const WebsocketsClient&& other)
  {
    // call endpoint's copy operator
    _endpoint = other._endpoint;
  
    // get callbacks and data from other
    this->_client = other._client;
    this->_messagesCallback = other._messagesCallback;
    this->_eventsCallback = other._eventsCallback;
    this->_connectionOpen = other._connectionOpen;
    this->_sendMode = other._sendMode;
  
    // delete other's client
    const_cast<WebsocketsClient&>(other)._client = nullptr;
    const_cast<WebsocketsClient&>(other)._connectionOpen = false;
    
    return *this;
  }
  
  /////////////////////////////////////////////////////////
  
  // KH
  
  void WebsocketsClient::setAuthorization(const char * user, const char * password)
  {
    if (user && password)
    {
      String auth = user;
      auth += ":";
      auth += password;
      base64Authorization = crypto2_generic::base64Encode((uint8_t *)auth.c_str(), auth.length());     
    }
  }
  
  /////////////////////////////////////////////////////////
  
  WSString WebsocketsClient::getAuthorization(void)
  {
    return base64Authorization;
  }
  
  /////////////////////////////////////////////////////////
  
  struct HandshakeRequestResult
  {
    WSString requestStr;
    WSString expectedAcceptKey;
  };
  
  /////////////////////////////////////////////////////////
  
  bool shouldAddDefaultHeader(const std::string& keyWord, const std::vector<std::pair<WSString, WSString>>& customHeaders)
  {
    for (const auto& header : customHeaders)
    {
      if (!keyWord.compare(header.first))
      {
        return false;
      }
    }
  
    return true;
  }
  
  /////////////////////////////////////////////////////////
  
  // KH 
  HandshakeRequestResult generateHandshake(const WSString& host, const WSString& uri,
      const std::vector<std::pair<WSString, WSString>>& customHeaders) 
  {
    WSString key = crypto2_generic::base64Encode(crypto2_generic::randomBytes(16));
  
    WSString handshake = "GET " + uri + " HTTP/1.1\r\n";
    handshake += HEADER_HOST + host + HEADER_HOST_RN;
    handshake += HEADER_WS_KEY + key + HEADER_HOST_RN;
  
    for (const auto& header : customHeaders)
    {
      handshake += header.first + ": " + header.second + HEADER_HOST_RN;
    }
  
    if (shouldAddDefaultHeader(HEADER_UPGRADE_NORMAL, customHeaders))
    {
      handshake += HEADER_UPGRADE_WS;
    }
  
    if (shouldAddDefaultHeader(HEADER_CONNECTION_NORMAL, customHeaders))
    {
      handshake += HEADER_CONNECTION_UPGRADE;
    }
  
    if (shouldAddDefaultHeader(HEADER_WS_VERSION_NORMAL, customHeaders))
    {
      handshake += HEADER_WS_VERSION_13;
    }
  
    if (shouldAddDefaultHeader(HEADER_USER_AGENT_NORMAL, customHeaders))
    {
      handshake += HEADER_USER_AGENT_VALUE;
    }
  
    if (shouldAddDefaultHeader(HEADER_ORIGIN_NORMAL, customHeaders))
    {
      handshake += HEADER_ORIGIN_VALUE;
    }
  
    handshake += HEADER_HOST_RN;
  
    HandshakeRequestResult result;
    result.requestStr = handshake;
    

    // KH
    LOGINFO1("WebsocketsClient::generateHandshake: handshake =", internals2_generic::fromInternalString(handshake));
    ////// 

  
  #ifndef _WS_CONFIG_SKIP_HANDSHAKE_ACCEPT_VALIDATION
    result.expectedAcceptKey = crypto2_generic::websocketsHandshakeEncodeKey(key);
  #endif
  
    // KH, Don't need return std::move(result);
    return result;
  }
  
  /////////////////////////////////////////////////////////
  
  HandshakeRequestResult generateHandshake(const WSString& host, const WSString& uri,
      const std::vector<std::pair<WSString, WSString>>& customHeaders, const WSString& base64Authorization) 
  {  
    WSString key = crypto2_generic::base64Encode(crypto2_generic::randomBytes(16));
  
    WSString handshake = "GET " + uri + " HTTP/1.1\r\n";
    handshake += HEADER_HOST + host + HEADER_HOST_RN;
    handshake += HEADER_WS_KEY + key + HEADER_HOST_RN;
  
    for (const auto& header : customHeaders)
    {
      handshake += header.first + ": " + header.second + HEADER_HOST_RN;
    }
  
    if (shouldAddDefaultHeader(HEADER_UPGRADE_NORMAL, customHeaders))
    {
      handshake += HEADER_UPGRADE_WS;
    }
  
    if (shouldAddDefaultHeader(HEADER_CONNECTION_NORMAL, customHeaders))
    {
      handshake += HEADER_CONNECTION_UPGRADE;
    }
  
    if (shouldAddDefaultHeader(HEADER_WS_VERSION_NORMAL, customHeaders))
    {
      handshake += HEADER_WS_VERSION_13;
    }
  
    if (shouldAddDefaultHeader(HEADER_USER_AGENT_NORMAL, customHeaders))
    {
      handshake += HEADER_USER_AGENT_VALUE;
    }
  
    // KH
    //if (WebsocketsClient::base64Authorization.size() > 0)
    {
      handshake += HEADER_AUTH_BASIC;  
      handshake += base64Authorization + HEADER_HOST_RN;
      
      // KH
      LOGINFO1("WebsocketsClient::generateHandshake: base64Authorization =", internals2_generic::fromInternalString(base64Authorization));
      //////
    }

    if (shouldAddDefaultHeader(HEADER_ORIGIN_NORMAL, customHeaders))
    {
      handshake += HEADER_ORIGIN_VALUE;
    }
    //////
  
    handshake += HEADER_HOST_RN;
  
    HandshakeRequestResult result;
    result.requestStr = handshake;
    
    // KH
    LOGINFO1("WebsocketsClient::generateHandshake: handshake =", internals2_generic::fromInternalString(handshake));
    ////// 
  
  #ifndef _WS_CONFIG_SKIP_HANDSHAKE_ACCEPT_VALIDATION
    result.expectedAcceptKey = crypto2_generic::websocketsHandshakeEncodeKey(key);
  #endif
  
    // KH, Don't need return std::move(result);
    return result;
  }
  
  /////////////////////////////////////////////////////////

  bool isWhitespace(char ch)
  {
    return ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n';
  }
  
  /////////////////////////////////////////////////////////

  struct HandshakeResponseResult
  {
    bool isSuccess;
    WSString serverAccept;
  };
  
  /////////////////////////////////////////////////////////

  bool isCaseInsensetiveEqual(const WSString lhs, const WSString rhs)
  {
    if (lhs.size() != rhs.size())
      return false;
  
    for (size_t i = 0; i < lhs.size(); i++)
    {
      char leftLowerCaseChar = lhs[i] >= 'A' && lhs[i] <= 'Z' ? lhs[i] - 'A' + 'a' : lhs[i];
      char righerLowerCaseChar = rhs[i] >= 'A' && rhs[i] <= 'Z' ? rhs[i] - 'A' + 'a' : rhs[i];
  
      if (leftLowerCaseChar != righerLowerCaseChar)
        return false;
    }
  
    return true;
  }
  
  /////////////////////////////////////////////////////////

  HandshakeResponseResult parseHandshakeResponse(std::vector<WSString> responseHeaders)
  {
    bool didUpgradeToWebsockets = false, isConnectionUpgraded = false;
    WSString serverAccept = "";
  
    for (WSString header : responseHeaders)
    {
      auto colonIndex = header.find_first_of(':');
  
      WSString key = header.substr(0, colonIndex);
      WSString value = header.substr(colonIndex + 2); // +2 (ignore space and ':')
      
      // KH
      LOGINFO1("WebsocketsClient::generateHandshake: key =", internals2_generic::fromInternalString(key));
      LOGINFO1("WebsocketsClient::generateHandshake: value =", internals2_generic::fromInternalString(value));
      ////// 
  
      if (isCaseInsensetiveEqual(key, HEADER_UPGRADE_LOWER_CASE))
      {
        didUpgradeToWebsockets = isCaseInsensetiveEqual(value, HEADER_WEBSOCKET_LOWER_CASE);
      }
      else if (isCaseInsensetiveEqual(key, HEADER_CONNECTION_LOWER_CASE))
      {
        isConnectionUpgraded = isCaseInsensetiveEqual(value, HEADER_UPGRADE_LOWER_CASE);
      }
      else if (isCaseInsensetiveEqual(key, WS_ACCEPT_NORMAL))
      {
        serverAccept = value;
      }
    }
  
    HandshakeResponseResult result;
    result.isSuccess = serverAccept != "" && didUpgradeToWebsockets && isConnectionUpgraded;
    result.serverAccept = serverAccept;
  
    return result;
  }
  
  /////////////////////////////////////////////////////////

  bool doestStartsWith(WSString str, WSString prefix)
  {
    if (str.size() < prefix.size())
    {
      // KH
      LOGDEBUG3("WebsocketsClient::doestStartsWith: str.size =", str.size(), ", prefix.size = ", prefix.size());
      ////// 
      return false;
    }
      
    for (size_t i = 0; i < prefix.size(); i++)
    {     
      if (str[i] != prefix[i])
      {
        return false;
      }
    }
    
    // KH
    LOGDEBUG1("WebsocketsClient::doestStartsWith: str =", internals2_generic::fromInternalString(str));
    LOGDEBUG1("WebsocketsClient::doestStartsWith: prefix =", internals2_generic::fromInternalString(prefix));
    ////// 
          
    return true;
  }
  
  /////////////////////////////////////////////////////////

  // KH, New in v1.0.5 (sync with v0.4.18)
  void WebsocketsClient::upgradeToSecuredConnection()
  {
  #ifndef _WS_CONFIG_NO_SSL
    auto client = new WSDefaultSecuredTcpClient;

  #ifdef ESP8266

    if    (this->_optional_ssl_fingerprint
           ||  (this->_optional_ssl_rsa_cert && this->_optional_ssl_rsa_private_key)
           ||  (this->_optional_ssl_ec_cert && this->_optional_ssl_ec_private_key)
           ||  this->_optional_ssl_trust_anchors
           ||  this->_optional_ssl_known_key)
    {
      if (this->_optional_ssl_fingerprint) 
      {
        client->setFingerprint(this->_optional_ssl_fingerprint);
      }
      
      if (this->_optional_ssl_trust_anchors) 
      {
        client->setTrustAnchors(this->_optional_ssl_trust_anchors);
      }
      
      if (this->_optional_ssl_known_key) 
      {
        client->setKnownKey(this->_optional_ssl_known_key);
      }
      
      if (this->_optional_ssl_rsa_cert && this->_optional_ssl_rsa_private_key) 
      {
        client->setClientRSACert(this->_optional_ssl_rsa_cert, this->_optional_ssl_rsa_private_key);
      }
      
      if (this->_optional_ssl_ec_cert && this->_optional_ssl_ec_private_key) 
      {
        client->setClientECCert(this->_optional_ssl_ec_cert, this->_optional_ssl_ec_private_key);
      }
    } 
    else 
    {
      client->setInsecure();
    }
    
  #elif defined(ESP32)

    if (this->_optional_ssl_ca_cert || this->_optional_ssl_client_ca || this->_optional_ssl_private_key)
    {
      if (this->_optional_ssl_ca_cert)
      {
        client->setCACert(this->_optional_ssl_ca_cert);
      }

      if (this->_optional_ssl_client_ca)
      {
        client->setCertificate(this->_optional_ssl_client_ca);
      }

      if (this->_optional_ssl_private_key)
      {
        client->setPrivateKey(this->_optional_ssl_private_key);
      }
    }
    else
    {
      client->setInsecure();
    }
    
  #endif

    this->_client = std::shared_ptr<WSDefaultSecuredTcpClient>(client);
    this->_endpoint.setInternalSocket(this->_client);
    
    // KH
    LOGDEBUG("WebsocketsClient::upgradeToSecuredConnection: SSL exit");
    //////
  #endif //_WS_CONFIG_NO_SSL
  }
  
  /////////////////////////////////////////////////////////
  
  void WebsocketsClient::addHeader(const WSInterfaceString key, const WSInterfaceString value)
  {
    _customHeaders.push_back({internals2_generic::fromInterfaceString(key), internals2_generic::fromInterfaceString(value)});
  }
  
  /////////////////////////////////////////////////////////

  bool WebsocketsClient::connect(WSInterfaceString _url)
  {
    WSString url = internals2_generic::fromInterfaceString(_url);
    WSString protocol = "";
    int defaultPort = 0;
  
    if (doestStartsWith(url, "http://"))
    {
      defaultPort = 80;
      protocol = "http";
      url = url.substr(7); //strlen("http://") == 7
    }
    else if (doestStartsWith(url, "ws://"))
    {
      defaultPort = 80;
      protocol = "ws";
      url = url.substr(5); //strlen("ws://") == 5
    }
  
  #ifndef _WS_CONFIG_NO_SSL
    else if (doestStartsWith(url, "wss://"))
    {
      defaultPort = 443;
      protocol = "wss";
      url = url.substr(6); //strlen("wss://") == 6
  
      // KH
      LOGINFO("WebsocketsClient::connect: wss upgradeToSecuredConnection");
      //////
      
      upgradeToSecuredConnection();
    }
    else if (doestStartsWith(url, "https://"))
    {
      defaultPort = 443;
      protocol = "https";
      url = url.substr(8); //strlen("https://") == 8
      
      // KH
      LOGINFO("WebsocketsClient::connect: https upgradeToSecuredConnection");
      //////
  
      upgradeToSecuredConnection();
    }
  #endif
  
    else
    {
      return false;
      // Not supported
    }
  
    auto uriBeg = url.find_first_of('/');
    std::string host = url, uri = "/";
  
    if (static_cast<int>(uriBeg) != -1)
    {
      uri = url.substr(uriBeg);
      host = url.substr(0, uriBeg);
    }
  
    auto portIdx = host.find_first_of(':');
    int port = defaultPort;
  
    if (static_cast<int>(portIdx) != -1)
    {
      auto onlyHost = host.substr(0, portIdx);
      ++portIdx;
      port = 0;
  
      while (portIdx < host.size() && host[portIdx] >= '0' && host[portIdx] <= '9') {
        port = port * 10 + (host[portIdx] - '0');
  
        ++portIdx;
      }
  
      host = onlyHost;
    }
  
    return this->connect(
             internals2_generic::fromInternalString(host),
             port,
             internals2_generic::fromInternalString(uri)
           );
  }
  
  /////////////////////////////////////////////////////////

  bool WebsocketsClient::connect(WSInterfaceString host, int port, WSInterfaceString path)
  {
    // KH
    LOGDEBUG("WebsocketsClient::connect: step 1");
    //////
    
    this->_connectionOpen = this->_client->connect(internals2_generic::fromInterfaceString(host), port);
  
    if (!this->_connectionOpen)
    {
      // KH
      LOGINFO3("WebsocketsClient::connect: not _connectionOpen, host =", host, ", port =", port);
      //////
    
      return false;
    }
  
    // KH
    //auto handshake = generateHandshake(internals2_generic::fromInterfaceString(host), internals2_generic::fromInterfaceString(path), _customHeaders);
    
    auto handshake = generateHandshake(internals2_generic::fromInterfaceString(host), 
                        internals2_generic::fromInterfaceString(path), _customHeaders, base64Authorization);
                        
    LOGINFO1("WebsocketsClient::connect: base64Authorization =", internals2_generic::fromInternalString(base64Authorization));
    //////
    
    // KH
    LOGDEBUG("WebsocketsClient::connect: step 2");
    //////
    
    this->_client->send(handshake.requestStr);
    
    // KH
    LOGDEBUG("WebsocketsClient::connect: step 3");
    //////
  
    // This check is needed because of an ESP32 lib bug that wont signal that the connection had
    // failed in `->connect` (called above), sometimes the disconnect will only be noticed here (after a `send`)
    if (!available())
    {
      return false;
    }
  
    auto head = this->_client->readLine();
    
    // KH
    LOGDEBUG("WebsocketsClient::connect: step 4");
    //////
    
    // KH
    if (!doestStartsWith(head, "HTTP/1.1 101"))
    //
    {
      close(CloseReason_ProtocolError);
      
      // KH
      LOGERROR("WebsocketsClient::connect: CloseReason_ProtocolError");
      //////
    
      return false;
    }
  
    std::vector<WSString> serverResponseHeaders;
    WSString line = "";
  
    // KH
    LOGDEBUG("WebsocketsClient::connect: step 5");
    //////
    
    while (true)
    {
      line = this->_client->readLine();
  
      if (line.size() < 2)
      {
        close(CloseReason_ProtocolError);
        return false;
      }
  
      if (line == HEADER_HOST_RN)
        break;
  
      // remove /r/n from line end
      line = line.substr(0, line.size() - 2);
  
      serverResponseHeaders.push_back(line);
    }
    
    // KH
    LOGDEBUG("WebsocketsClient::connect: step 6");
    //////
  
    auto parsedResponse = parseHandshakeResponse(serverResponseHeaders);
  
  #ifdef _WS_CONFIG_SKIP_HANDSHAKE_ACCEPT_VALIDATION
    bool serverAcceptMismatch = false;
  #else
    bool serverAcceptMismatch = parsedResponse.serverAccept != handshake.expectedAcceptKey;
  #endif
  
    if (parsedResponse.isSuccess == false || serverAcceptMismatch)
    {
      // KH
      LOGERROR("WebsocketsClient::connect: parseHandshakeResponse not successful => CloseReason_ProtocolError");
      //////
      close(CloseReason_ProtocolError);
      return false;
    }
    
    // KH
    LOGDEBUG("WebsocketsClient::connect: step 7");
    //////
  
    this->_eventsCallback(*this, WebsocketsEvent::ConnectionOpened, {});
    return true;
  }
  
  /////////////////////////////////////////////////////////
  
  bool WebsocketsClient::connectSecure(WSInterfaceString host, int port, WSInterfaceString path) 
  {
    upgradeToSecuredConnection();

    return connect(host, port, path);
  }
  
  /////////////////////////////////////////////////////////

  void WebsocketsClient::onMessage(MessageCallback callback)
  {
    this->_messagesCallback = callback;
  }
  
  /////////////////////////////////////////////////////////

  void WebsocketsClient::onMessage(PartialMessageCallback callback)
  {
    this->_messagesCallback = [callback](WebsocketsClient&, WebsocketsMessage msg)
    {
      callback(msg);
    };
  }
  
  /////////////////////////////////////////////////////////

  void WebsocketsClient::onEvent(EventCallback callback)
  {
    this->_eventsCallback = callback;
  }
  
  /////////////////////////////////////////////////////////

  void WebsocketsClient::onEvent(PartialEventCallback callback)
  {
    this->_eventsCallback = [callback](WebsocketsClient&, WebsocketsEvent event, WSInterfaceString data)
    {
      callback(event, data);
    };
  }
  
  /////////////////////////////////////////////////////////

  bool WebsocketsClient::poll()
  {
    bool messageReceived = false;
    while (available() && _endpoint.poll())
    {
      auto msg = _endpoint.recv();
  
      if (msg.isEmpty())
      {
        continue;
      }
  
      messageReceived = true;
  
      if (msg.isBinary() || msg.isText())
      {
        this->_messagesCallback(*this, std::move(msg));
      }
      else if (msg.isContinuation())
      {
        // continuation messages will only be returned when policy is appropriate
        this->_messagesCallback(*this, std::move(msg));
      }
      else if (msg.isPing())
      {
        _handlePing(std::move(msg));
      }
      else if (msg.isPong())
      {
        _handlePong(std::move(msg));
      }
      else if (msg.isClose())
      {
        this->_connectionOpen = false;
        _handleClose(std::move(msg));
      }
    }
  
    return messageReceived;
  }
  
  // KH add in v1.0.6
  WebsocketsMessage WebsocketsClient::readNonBlocking()
  {
    auto msg = _endpoint.recv();

    if (!msg.isEmpty())
      return msg;
    else
      return {};  
  }
  
  /////////////////////////////////////////////////////////
  
  WebsocketsMessage WebsocketsClient::readBlocking()
  {
    while (available())
    {
  #ifdef PLATFORM_DOES_NOT_SUPPORT_BLOCKING_READ
      while (available() && _endpoint.poll() == false) continue;
  #endif
      auto msg = _endpoint.recv();
  
      if (!msg.isEmpty())
        return msg;
    }
  
    return {};
  }
  
  /////////////////////////////////////////////////////////

  bool WebsocketsClient::send(const WSInterfaceString& data)
  {
    auto str = internals2_generic::fromInterfaceString(data);
    return this->send(str.c_str(), str.size());
  }
  
  /////////////////////////////////////////////////////////

  bool WebsocketsClient::send(const WSInterfaceString&& data)
  {
    auto str = internals2_generic::fromInterfaceString(data);
    return this->send(str.c_str(), str.size());
  }
  
  /////////////////////////////////////////////////////////

  bool WebsocketsClient::send(const char* data)
  {
    return this->send(data, strlen(data));
  }
  
  /////////////////////////////////////////////////////////

  bool WebsocketsClient::send(const char* data, const size_t len)
  {
    if (available())
    {
      // if in normal mode
      if (this->_sendMode == SendMode_Normal)
      {
        // send a normal message
        return _endpoint.send(
                 data,
                 len,
                 internals2_generic::ContentType::Text,
                 true
               );
      }
      // if in streaming mode
      else if (this->_sendMode == SendMode_Streaming)
      {
        // send a continue frame
        return _endpoint.send(
                 data,
                 len,
                 internals2_generic::ContentType::Continuation,
                 false
               );
      }
    }
    
    return false;
  }
  
  /////////////////////////////////////////////////////////

  bool WebsocketsClient::sendBinary(WSInterfaceString data)
  {
    auto str = internals2_generic::fromInterfaceString(data);
    return this->sendBinary(str.c_str(), str.size());
  }
  
  /////////////////////////////////////////////////////////

  bool WebsocketsClient::sendBinary(const char* data, const size_t len)
  {
    if (available())
    {
      // if in normal mode
      if (this->_sendMode == SendMode_Normal)
      {
        // send a normal message
        return _endpoint.send(
                 data,
                 len,
                 internals2_generic::ContentType::Binary,
                 true
               );
      }
      // if in streaming mode
      else if (this->_sendMode == SendMode_Streaming)
      {
        // send a continue frame
        return _endpoint.send(
                 data,
                 len,
                 internals2_generic::ContentType::Continuation,
                 false
               );
      }
    }
    return false;
  }
  
  /////////////////////////////////////////////////////////

  bool WebsocketsClient::stream(const WSInterfaceString data)
  {
    if (available() && this->_sendMode == SendMode_Normal)
    {
      this->_sendMode = SendMode_Streaming;
      return _endpoint.send(
               internals2_generic::fromInterfaceString(data),
               internals2_generic::ContentType::Text,
               false
             );
    }
    return false;
  }
  
  /////////////////////////////////////////////////////////

  bool WebsocketsClient::streamBinary(const WSInterfaceString data)
  {
    if (available() && this->_sendMode == SendMode_Normal)
    {
      this->_sendMode = SendMode_Streaming;
      return _endpoint.send(
               internals2_generic::fromInterfaceString(data),
               internals2_generic::ContentType::Binary,
               false
             );
    }
    return false;
  }
  
  /////////////////////////////////////////////////////////

  bool WebsocketsClient::end(const WSInterfaceString data)
  {
    if (available() && this->_sendMode == SendMode_Streaming)
    {
      this->_sendMode = SendMode_Normal;
      return _endpoint.send(
               internals2_generic::fromInterfaceString(data),
               internals2_generic::ContentType::Continuation,
               true
             );
    }
    return false;
  }
  
  /////////////////////////////////////////////////////////

  void WebsocketsClient::setFragmentsPolicy(const FragmentsPolicy newPolicy)
  {
    _endpoint.setFragmentsPolicy(newPolicy);
  }
  
  /////////////////////////////////////////////////////////

  bool WebsocketsClient::available(const bool activeTest)
  {
    if (activeTest)  
    {
      _endpoint.ping("");
    }
  
    bool updatedConnectionOpen = this->_connectionOpen && this->_client && this->_client->available();
  
    if (updatedConnectionOpen != this->_connectionOpen)
    {
      _endpoint.close(CloseReason_AbnormalClosure);
      this->_eventsCallback(*this, WebsocketsEvent::ConnectionClosed, "");
    }
  
    this->_connectionOpen = updatedConnectionOpen;
    
    return this->_connectionOpen;
  }
  
  /////////////////////////////////////////////////////////

  bool WebsocketsClient::ping(const WSInterfaceString data)
  {
    if (available())
    {
      return _endpoint.ping(internals2_generic::fromInterfaceString(data));
    }
  
    return false;
  }
  
  /////////////////////////////////////////////////////////

  bool WebsocketsClient::pong(const WSInterfaceString data)
  {
    if (available())
    {
      return _endpoint.pong(internals2_generic::fromInterfaceString(data));
    }
  
    return false;
  }
  
  /////////////////////////////////////////////////////////

  void WebsocketsClient::close(const CloseReason reason)
  {
    if (available())
    {
      this->_connectionOpen = false;
      _endpoint.close(reason);
      _handleClose({});
    }
  }
  
  /////////////////////////////////////////////////////////

  CloseReason WebsocketsClient::getCloseReason() const
  {
    return _endpoint.getCloseReason();
  }
  
  /////////////////////////////////////////////////////////

  void WebsocketsClient::_handlePing(const WebsocketsMessage message)
  {
    this->_eventsCallback(*this, WebsocketsEvent::GotPing, message.data());
  }
  
  /////////////////////////////////////////////////////////

  void WebsocketsClient::_handlePong(const WebsocketsMessage message)
  {
    this->_eventsCallback(*this, WebsocketsEvent::GotPong, message.data());
  }
  
  /////////////////////////////////////////////////////////

  void WebsocketsClient::_handleClose(const WebsocketsMessage message)
  {
    this->_eventsCallback(*this, WebsocketsEvent::ConnectionClosed, message.data());
  }
  
  /////////////////////////////////////////////////////////
  
  #ifdef ESP8266
  void WebsocketsClient::setFingerprint(const char* fingerprint)
  {
    this->_optional_ssl_fingerprint = fingerprint;
  }
  
  /////////////////////////////////////////////////////////

  // KH, New in v1.0.5 (sync with v0.4.18)
  void WebsocketsClient::setInsecure() 
  {
    this->_optional_ssl_fingerprint = nullptr;
    this->_optional_ssl_rsa_cert = nullptr;
    this->_optional_ssl_rsa_private_key = nullptr;
    this->_optional_ssl_ec_cert = nullptr;
    this->_optional_ssl_ec_private_key = nullptr;
    this->_optional_ssl_trust_anchors = nullptr;
    this->_optional_ssl_known_key = nullptr;
  }
  
  /////////////////////////////////////////////////////////

  void WebsocketsClient::setClientRSACert(const X509List *cert, const PrivateKey *sk) 
  {
    this->_optional_ssl_rsa_cert = cert;
    this->_optional_ssl_rsa_private_key = sk;
  }
  
  /////////////////////////////////////////////////////////

  void WebsocketsClient::setClientECCert(const X509List *cert, const PrivateKey *sk) 
  {
    this->_optional_ssl_ec_cert = cert;
    this->_optional_ssl_ec_private_key = sk;
  }
  
  /////////////////////////////////////////////////////////

  void WebsocketsClient::setTrustAnchors(const X509List *ta) 
  {
    this->_optional_ssl_trust_anchors = ta;
  }
  
  /////////////////////////////////////////////////////////

  void WebsocketsClient::setKnownKey(const PublicKey *pk) 
  {
    this->_optional_ssl_known_key = pk;
  }
  
  /////////////////////////////////////////////////////////
  
  #elif defined(ESP32)
  void WebsocketsClient::setCACert(const char* ca_cert)
  {
    this->_optional_ssl_ca_cert = ca_cert;
  }
  
  /////////////////////////////////////////////////////////

  void WebsocketsClient::setCertificate(const char* client_ca)
  {
    this->_optional_ssl_client_ca = client_ca;
  }
  
  /////////////////////////////////////////////////////////

  void WebsocketsClient::setPrivateKey(const char* private_key)
  {
    this->_optional_ssl_private_key = private_key;
  }
  
  /////////////////////////////////////////////////////////

  void WebsocketsClient::setInsecure()
  {
    this->_optional_ssl_ca_cert = nullptr;
    this->_optional_ssl_client_ca = nullptr;
    this->_optional_ssl_private_key = nullptr;
  }
  #endif
  
  /////////////////////////////////////////////////////////

  WebsocketsClient::~WebsocketsClient()
  {
    if (available())
    {
      this->close(CloseReason_GoingAway);
    }
  }
  
  /////////////////////////////////////////////////////////

}    //namespace websockets2_generic

#endif    // _WEBSOCKETS2_GENERIC_CLIENT_H
