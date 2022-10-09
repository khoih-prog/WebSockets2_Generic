/****************************************************************************************************************************
  SAMDUE-Ethernet-Server.ino
  For SAM DUE with Ethernet module/shield.
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32


  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license      
 *****************************************************************************************************************************/
/****************************************************************************************************************************
  SAM DUE Websockets Server : Minimal SAM DUE Websockets Server

  This sketch:
        1. Connects to a WiFi network
        2. Starts a websocket server on port 8080
        3. Waits for connections
        4. Once a client connects, it wait for a message from the client
        5. Sends an "echo" message to the client
        6. closes the connection and goes back to step 3

  Hardware:
        For this sketch you only need a SAMD21/SAMD51 board.

  Originally Created  : 15/02/2019
  Original Author     : By Gil Maimon
  Original Repository : https://github.com/gilmaimon/ArduinoWebsockets

*****************************************************************************************************************************/

#include "defines.h"

#include <WebSockets2_Generic.h>

using namespace websockets2_generic;

WebsocketsServer server;

#define WEBSOCKETS_PORT     8080

// Select the IP address according to your local network
IPAddress serverIP(192, 168, 2, 93);

void heartBeatPrint()
{
  static int num = 1;

  Serial.print("H");        // H means server alive

  if (num == 80)
  {
    Serial.println();
    num = 1;
  }
  else if (num++ % 10 == 0)
  {
    Serial.print(" ");
  }
}

void check_status()
{
  static unsigned long checkstatus_timeout = 0;

  //KH
#define HEARTBEAT_INTERVAL    10000L
  // Print hearbeat every HEARTBEAT_INTERVAL (10) seconds.
  if ((millis() > checkstatus_timeout) || (checkstatus_timeout == 0))
  {
    heartBeatPrint();
    checkstatus_timeout = millis() + HEARTBEAT_INTERVAL;
  }
}

void initEthernet()
{
#if USE_ETHERNET_GENERIC
  LOGWARN(F("=========== USE_ETHERNET_GENERIC ==========="));  
#elif USE_ETHERNET_ESP8266
  LOGWARN(F("=========== USE_ETHERNET_ESP8266 ==========="));
#elif USE_ETHERNET_ENC
  LOGWARN(F("=========== USE_ETHERNET_ENC ==========="));  
#else
  LOGWARN(F("========================="));
#endif

#if (USING_SPI2)
  #if defined(CUR_PIN_MISO)
    LOGWARN(F("Default SPI pinout:"));
    LOGWARN1(F("MOSI:"), CUR_PIN_MOSI);
    LOGWARN1(F("MISO:"), CUR_PIN_MISO);
    LOGWARN1(F("SCK:"),  CUR_PIN_SCK);
    LOGWARN1(F("SS:"),   CUR_PIN_SS);
    LOGWARN(F("========================="));
  #endif
#else
  LOGWARN(F("Default SPI pinout:"));
  LOGWARN1(F("MOSI:"), MOSI);
  LOGWARN1(F("MISO:"), MISO);
  LOGWARN1(F("SCK:"),  SCK);
  LOGWARN1(F("SS:"),   SS);
  LOGWARN(F("========================="));
#endif

  pinMode(USE_THIS_SS_PIN, OUTPUT);
  digitalWrite(USE_THIS_SS_PIN, HIGH);
  
  LOGWARN2(BOARD_NAME, F(" setCsPin:"), USE_THIS_SS_PIN);

  // For other boards, to change if necessary
  #if ( USE_ETHERNET_GENERIC || USE_ETHERNET_ENC )
    // Must use library patch for Ethernet, EthernetLarge libraries
    // For RPI Pico using Arduino Mbed RP2040 core
    // SCK: GPIO2,  MOSI: GPIO3, MISO: GPIO4, SS/CS: GPIO5
    // For RPI Pico using E. Philhower RP2040 core
    // SCK: GPIO18,  MOSI: GPIO19, MISO: GPIO16, SS/CS: GPIO17
    // Default pin 5/17 to SS/CS
  
    //Ethernet.setCsPin (USE_THIS_SS_PIN);
    Ethernet.init (USE_THIS_SS_PIN);
     
  #endif    //( USE_ETHERNET_GENERIC || USE_ETHERNET_ENC )

  LOGWARN(F("========================="));
  
  #if defined(CUR_PIN_MISO)
    LOGWARN(F("Currently Used SPI pinout:"));
    LOGWARN1(F("MOSI:"), CUR_PIN_MOSI);
    LOGWARN1(F("MISO:"), CUR_PIN_MISO);
    LOGWARN1(F("SCK:"),  CUR_PIN_SCK);
    LOGWARN1(F("SS:"),   CUR_PIN_SS);
  #else
    LOGWARN(F("Currently Used SPI pinout:"));
    LOGWARN1(F("MOSI:"), MOSI);
    LOGWARN1(F("MISO:"), MISO);
    LOGWARN1(F("SCK:"),  SCK);
    LOGWARN1(F("SS:"),   SS);
  #endif
  
  LOGWARN(F("========================="));
}

void setup()
{
#if (defined(ETHERNET_WITH_SD_CARD) && ETHERNET_WITH_SD_CARD)
  pinMode(SDCARD_CS, OUTPUT);
  digitalWrite(SDCARD_CS, HIGH); // Deselect the SD card
#endif
  
  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  Serial.println("\nStarting SAMDUE-Ethernet-Server on " + String(BOARD_NAME));
  Serial.println("Ethernet using " + String(ETHERNET_TYPE));
  Serial.println(WEBSOCKETS2_GENERIC_VERSION);

  initEthernet();

  // start the ethernet connection and the server:
  // Use DHCP dynamic IP and random mac
  uint16_t index = millis() % NUMBER_OF_MAC;
  // Use Static IP
  //Ethernet.begin(mac[index], serverIP);
  Ethernet.begin(mac[index]);

  // server address, port and URL
  Serial.print("WebSockets Server IP address: ");
  Serial.println(Ethernet.localIP());

  server.listen(WEBSOCKETS_PORT);
 
  Serial.print(server.available() ? "WebSockets Server Running and Ready on " : "Server Not Running on ");
  Serial.println(BOARD_NAME);
  Serial.print("IP address: ");
  Serial.print(Ethernet.localIP());
  Serial.print(", Port: ");
  Serial.println(WEBSOCKETS_PORT);    // Websockets Server Port
}

WebsocketsClient* client = NULL;

void loop()
{
  check_status();

  client = new WebsocketsClient;

  if (client)
  {
    *client = server.accept();
  
    if (client->available())
    {
      WebsocketsMessage msg = client->readNonBlocking();
  
      // log
      Serial.print("Got Message: ");
      Serial.println(msg.data());
  
      // return echo
      client->send("Echo: " + msg.data());
  
      // close the connection
      client->close();
    }

    delete client;
  }

  //delay(1000);
}
