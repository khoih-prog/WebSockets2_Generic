/****************************************************************************************************************************
  ws_config_defs.hpp
  For WebSockets2_Generic Library
  
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

