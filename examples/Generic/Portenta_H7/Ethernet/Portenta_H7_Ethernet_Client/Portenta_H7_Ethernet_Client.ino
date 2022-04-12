/****************************************************************************************************************************
  Portenta_H7_Ethernet_Client.ino
  For Portenta_H7 with Portenta_H7 Vision-shield Ethernet.
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32
  
  The library provides simple and easy interface for websockets (Client and Server).
  
  Example first created on: 10.05.2018
  Original Author: Markus Sattler
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/
/*
  Portenta_H7 Websockets Client (using Portenta_H7 Vision-shield Ethernet)

  This sketch:
  1. Connects to a ethernet network
  2. Connects to a websockets server at port 8080
  3. Sends the websockets server a message ("Hello Server")
  4. Prints all incoming messages while the connection is open

  Note:
  Make sure you share your computer's internet connection with the Portenta_H7 via ethernet.

*/

#if ( ( defined(ARDUINO_PORTENTA_H7_M7) || defined(ARDUINO_PORTENTA_H7_M4) ) && defined(ARDUINO_ARCH_MBED) )

  #if defined(BOARD_NAME)
    #undef BOARD_NAME
  #endif

  #if defined(CORE_CM7)
    #warning Using Portenta H7 M7 core
    #define BOARD_NAME            "PORTENTA_H7_M7"
  #else
    #warning Using Portenta H7 M4 core
    #define BOARD_NAME            "PORTENTA_H7_M4"
  #endif

  #define SHIELD_TYPE           "Ethernet using Portenta_Ethernet Library"

  #define ETHERNET_USE_PORTENTA_H7  true
  #define USE_ETHERNET_PORTENTA_H7  true

#else

  #error For Portenta_H7 only
  
#endif

#define WEBSOCKETS_USE_PORTENTA_H7_ETHERNET     true

#define DEBUG_WEBSOCKETS_PORT     Serial
// Debug Level from 0 to 4
#define _WEBSOCKETS_LOGLEVEL_     3

// Uncomment to test sending WS headers in lower-case
//#define WS_HEADERS_NORMAL_CASE    false

#include <WebSockets2_Generic.h>

using namespace websockets2_generic;

WebsocketsClient client;

/////////////////////////////////////////////

// Enter a MAC address and IP address for your controller below.
#define NUMBER_OF_MAC      20

byte mac[][NUMBER_OF_MAC] =
{
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x01 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x02 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x03 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x04 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x05 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x06 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x07 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x08 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x09 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0A },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0B },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0C },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0D },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0E },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0F },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x10 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x11 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x12 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x13 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x14 },
};

// Select the IP address according to your local network
IPAddress clientIP(192, 168, 2, 225);

/////////////////////////////////////////////

// Enter websockets url.
// Note: wss:// currently not working.
// ws://echo.websocket.org is no longer working. Please create your own WS Local Server to test
//const char* url  = "ws://echo.websocket.org";
const char* url  = "ws://192.168.2.30:8080";

void setup() 
{
  // Start Serial and wait until it is ready.
  Serial.begin(115200);
  while (!Serial && millis() < 5000);
 
  Serial.print("\nStarting Portenta_H7_Ethernet_Client on "); Serial.print(BOARD_NAME); 
  Serial.print(" "); Serial.println(SHIELD_TYPE);
  Serial.println(WEBSOCKETS2_GENERIC_VERSION);

  // start the ethernet connection and the server:
  // Use DHCP dynamic IP and random mac
  uint16_t index = millis() % NUMBER_OF_MAC;
  // Use Static IP
  //Ethernet.begin(mac[index], clientIP);
  Ethernet.begin(mac[index]);
  
  Serial.print("WebSockets Client @ IP address: ");
  Serial.println(Ethernet.localIP());

  // Connect to websocket server.
  if (client.connect(url)) 
  {
    Serial.print("Connected to server : "); Serial.println(url);
    // Send welcome message.
    client.send("Hello Server");
  } 
  else 
  {
    Serial.print("Couldn't connect to server : "); Serial.println(url);
  }

  // Run callback when messages are received.
  client.onMessage([&](WebsocketsMessage message) 
  {
    Serial.print("Got Message: ");
    Serial.println(message.data());
  });
}

void loop() 
{
  // Check for incoming messages.
  if (client.available()) 
  {
    client.poll();
  }
}
