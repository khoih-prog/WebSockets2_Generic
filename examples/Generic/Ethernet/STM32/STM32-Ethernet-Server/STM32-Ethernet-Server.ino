/****************************************************************************************************************************
  STM32-Ethernet-Server.ino
  For STM32 with Ethernet module/shield.

  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).

  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
  Version: 1.0.3

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/07/2020 Initial coding/porting to support nRF52 and SAMD21/SAMD51 boards. Add SINRIC/Alexa support
  1.0.1   K Hoang      16/07/2020 Add support to Ethernet W5x00 to nRF52, SAMD21/SAMD51 and SAM DUE boards
  1.0.2   K Hoang      18/07/2020 Add support to Ethernet ENC28J60 to nRF52, SAMD21/SAMD51 and SAM DUE boards
  1.0.3   K Hoang      18/07/2020 Add support to STM32F boards using Ethernet W5x00, ENC28J60 and LAN8742A
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

WebsocketsServer* server = NULL;
WebsocketsClient* client = NULL;

#define WEBSOCKETS_PORT     8080

void heartBeatPrint(void)
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

void setup()
{
#if (USE_ETHERNET_LIB || USE_ETHERNET2_LIB || USE_ETHERNET_LARGE_LIB)
  pinMode(SDCARD_CS, OUTPUT);
  digitalWrite(SDCARD_CS, HIGH); // Deselect the SD card
#endif

  Serial.begin(115200);
  while (!Serial);

  Serial.println("\nStarting WebSockets2_Generic STM32-Ethernet-Server on " + String(BOARD_NAME));
  Serial.println("Ethernet using " + String(ETHERNET_TYPE));

  // start the ethernet connection and the server:
  // Use Static IP
  Ethernet.begin(mac, serverIP);
  //Configure IP address via DHCP
  //Ethernet.begin(mac);

  server = new WebsocketsServer;
  server->listen(WEBSOCKETS_PORT);

  Serial.print(server->available() ? "WebSockets Server Running and Ready on " : "Server Not Running on ");
  Serial.println(BOARD_NAME);
  Serial.print("IP address: ");
  Serial.print(Ethernet.localIP());
  Serial.print(", Port: ");
  Serial.println(WEBSOCKETS_PORT);    // Websockets Server Port

  // Important, don't reduce this waiting time.
  for (uint8_t t = 3; t > 0; t--)
  {
    Serial.println("[SETUP] SERVER WAIT " + String(t));
    Serial.flush();
    delay(1000);
  }
}

void loop()
{
  check_status();

  client = new WebsocketsClient;

  if (client)
  {
    *client = server->accept();
  
    if (client->available())
    {
      WebsocketsMessage msg = client->readBlocking();
  
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
