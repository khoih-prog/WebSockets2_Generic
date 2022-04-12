/****************************************************************************************************************************
  Portenta_H7_Ethernet_Server.ino
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
  Portenta_H7 Websockets Server and Http Server (using Portenta_H7 Vision-shield Ethernet).

  This sketch:
  1. Connects to a ethernet network
  2. Starts a websocket server on port 8080 or 81
  3. Waits for connections
  4. Once a client connects, it wait for a message from the client
  5. Echoes the message to the client
  6. Closes the connection and goes back to step 3

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

#include <WebSockets2_Generic.h>

using namespace websockets2_generic;

WebsocketsServer server;

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

// Enter websockets server port.
const uint16_t port = 8080;

void setup()
{
  // Start Serial and wait until it is ready.
  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  Serial.print("\nStarting Portenta_H7_Ethernet_Server on "); Serial.print(BOARD_NAME);
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

  // Start websockets server.
  server.listen(port);

  if (server.available())
  {
    Serial.print("Server available at ws://");
    Serial.print(Ethernet.localIP());
    Serial.print(":"); Serial.println(port);  
  }
  else
  {
    Serial.println("Server not available!");
  }
}

void loop()
{
  WebsocketsClient client = server.accept();

  if (client.available())
  {
    Serial.println("Client connected");

    // Read message from client and log it.
    WebsocketsMessage msg = client.readBlocking();
    Serial.print("Got Message: ");
    Serial.println(msg.data());

    // Echo the message.
    client.send("Echo: " + msg.data());

    // Close the connection.
    client.close();
    Serial.println("Client closed");
  }
}
