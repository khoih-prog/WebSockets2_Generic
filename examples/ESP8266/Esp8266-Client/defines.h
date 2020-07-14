/****************************************************************************************************************************
  defines.h for ESP8266-Client.ino
  For ESP8266.
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
  Version: 1.0.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/07/2020 Initial coding/porting to support nRF52 and SAMD21/SAMD51 boards. Add SINRIC/Alexa support     
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#if (ESP8266)
  #define BOARD_TYPE      "ESP8266"
#else
  #error This code is intended to run only on the ESP8266 boards ! Please check your Tools->Board setting.
#endif

#define DEBUG_WEBSOCKETS_PORT     Serial
// Debug Level from 0 to 4
#define _WEBSOCKETS_LOGLEVEL_     2

const char* ssid = "ssid"; //Enter SSID
const char* password = "password"; //Enter Password

const char* websockets_server_host = "192.168.2.95"; //Enter server address
//const char* websockets_server_host = "192.168.2.99"; //Enter server address
//const char* websockets_server_host = "192.168.2.105"; //Enter server address
//const char* websockets_server_host = "serverip_or_name"; //Enter server address

const uint16_t websockets_server_port = 8080; // Enter server port

#endif      //defines_h
