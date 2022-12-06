/****************************************************************************************************************************
  ws_config_defs.hpp
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

#define _WS_CONFIG_NO_TRUE_RANDOMNESS

#define _WS_BUFFER_SIZE       512
#define _CONNECTION_TIMEOUT   1000

// KH, Common headers used for Client/Server

#if !defined(WS_HEADERS_NORMAL_CASE)
  #define WS_HEADERS_NORMAL_CASE     true
#endif

#if (_WEBSOCKETS_LOGLEVEL_ > 3)
  #if WS_HEADERS_NORMAL_CASE
    #warning Not using WS Header lowercase
  #else
    #warning Using WS Header lowercase
  #endif
#endif

  // Common
  #define HEADER_HOST_RN                      "\r\n"
  #define WS_KEY_LOWER_CASE                   "sec-websocket-key"

  #define WS_VERSION_NORMAL                   "Sec-WebSocket-Version"
  #define WS_VERSION_LOWER_CASE               "sec-websocket-version"

  #define WS_KEY_NORMAL                       "Sec-WebSocket-Key"
  #define WS_KEY_LOWER_CASE                   "sec-websocket-key"
  
  #define WS_ACCEPT_NORMAL                    "Sec-WebSocket-Accept"
  
  /////////////////////////////////////////////////////

  // Not using all lowercase headers
  #define HEADER_HOST_NORMAL                      "Host: "
  #define HEADER_CONNECTION_NORMAL                "Connection"
  #define HEADER_CONNECTION_UPGRADE_NORMAL        "Connection: Upgrade\r\n"
  #define HEADER_UPGRADE_NORMAL                   "Upgrade"
  #define HEADER_UPGRADE_WS_NORMAL                "Upgrade: websocket\r\n"
  #define HEADER_WEBSOCKET_NORMAL                 "websocket"
  #define HEADER_WS_VERSION_NORMAL                "Sec-WebSocket-Version: "
  #define HEADER_WS_VERSION_13_NORMAL             "Sec-WebSocket-Version: 13\r\n"
  #define HEADER_WS_KEY_NORMAL                    "Sec-WebSocket-Key: "
  #define HEADER_USER_AGENT_NORMAL                "User-Agent"
  #define HEADER_USER_AGENT_VALUE_NORMAL          "User-Agent: TinyWebsockets Client\r\n"
  #define HEADER_AUTH_BASIC_NORMAL                "Authorization: Basic "
  #define HEADER_ORIGIN_NORMAL                    "Origin"
  #define HEADER_ORIGIN_VALUE_NORMAL              "Origin: https://github.com/khoih-prog/Websockets2_Generic\r\n"
  
  #define HEADER_WS_ACCEPT_NORMAL                 "Sec-WebSocket-Accept: "
  
  /////////////////////////////////////////////////////
  
  // Lowercase headers
  #define HEADER_HOST_LOWER_CASE                  "host: "
  #define HEADER_CONNECTION_LOWER_CASE            "connection"
  #define HEADER_CONNECTION_UPGRADE_LOWER_CASE    "connection: upgrade\r\n"
  #define HEADER_UPGRADE_LOWER_CASE               "upgrade"
  #define HEADER_UPGRADE_WS_LOWER_CASE            "upgrade: websocket\r\n"
  #define HEADER_WEBSOCKET_LOWER_CASE             "websocket"
  #define HEADER_WS_VERSION_LOWER_CASE            "sec-webSocket-version: "
  #define HEADER_WS_VERSION_13_LOWER_CASE         "sec-webSocket-version: 13\r\n"
  #define HEADER_WS_KEY_LOWER_CASE                "sec-webSocket-key: "
  #define HEADER_USER_AGENT_LOWER_CASE            "user-agent"
  #define HEADER_USER_AGENT_VALUE_LOWER_CASE      "user-agent: TinyWebsockets Client\r\n"
  #define HEADER_AUTH_BASIC_LOWER_CASE            "authorization: basic "
  #define HEADER_ORIGIN_LOWER_CASE                "origin"
  #define HEADER_ORIGIN_VALUE_LOWER_CASE          "origin: https://github.com/khoih-prog/Websockets2_Generic\r\n"
  
  /////////////////////////////////////////////////////
  
#if WS_HEADERS_NORMAL_CASE
  // Not using all lowercase headers
  #define HEADER_HOST                             HEADER_HOST_NORMAL
  #define HEADER_CONNECTION                       HEADER_CONNECTION_NORMAL
  #define HEADER_CONNECTION_UPGRADE               HEADER_CONNECTION_UPGRADE_NORMAL
  #define HEADER_UPGRADE                          HEADER_UPGRADE_NORMAL
  #define HEADER_UPGRADE_WS                       HEADER_UPGRADE_WS_NORMAL
  #define HEADER_WEBSOCKET                        HEADER_WEBSOCKET_NORMAL
  #define HEADER_WS_VERSION                       HEADER_WS_VERSION_NORMAL
  #define HEADER_WS_VERSION_13                    HEADER_WS_VERSION_13_NORMAL
  #define HEADER_WS_KEY                           HEADER_WS_KEY_NORMAL
  #define HEADER_USER_AGENT                       HEADER_USER_AGENT_NORMAL
  #define HEADER_USER_AGENT_VALUE                 HEADER_USER_AGENT_VALUE_NORMAL
  #define HEADER_AUTH_BASIC                       HEADER_AUTH_BASIC_NORMAL
  #define HEADER_ORIGIN                           HEADER_ORIGIN_NORMAL
  #define HEADER_ORIGIN_VALUE                     HEADER_ORIGIN_VALUE_NORMAL
  
#else
  // Lowercase headers
  #define HEADER_HOST                             HEADER_HOST_LOWER_CASE
  #define HEADER_CONNECTION                       HEADER_CONNECTION_LOWER_CASE
  #define HEADER_CONNECTION_UPGRADE               HEADER_CONNECTION_UPGRADE_LOWER_CASE
  #define HEADER_UPGRADE                          HEADER_UPGRADE_LOWER_CASE
  #define HEADER_UPGRADE_WS                       HEADER_UPGRADE_WS_LOWER_CASE
  #define HEADER_WEBSOCKET                        HEADER_WEBSOCKET_LOWER_CASE
  #define HEADER_WS_VERSION                       HEADER_WS_VERSION_LOWER_CASE
  #define HEADER_WS_VERSION_13                    HEADER_WS_VERSION_13_LOWER_CASE
  #define HEADER_WS_KEY                           HEADER_WS_KEY_LOWER_CASE
  #define HEADER_USER_AGENT                       HEADER_USER_AGENT_LOWER_CASE
  #define HEADER_USER_AGENT_VALUE                 HEADER_USER_AGENT_VALUE_LOWER_CASE
  #define HEADER_AUTH_BASIC                       HEADER_AUTH_BASIC_LOWER_CASE
  #define HEADER_ORIGIN                           HEADER_ORIGIN_LOWER_CASE
  #define HEADER_ORIGIN_VALUE                     HEADER_ORIGIN_VALUE_LOWER_CASE
  
#endif

