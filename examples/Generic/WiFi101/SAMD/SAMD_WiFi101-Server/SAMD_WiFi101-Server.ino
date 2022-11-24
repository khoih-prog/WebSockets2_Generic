/****************************************************************************************************************************
  SAMD_WiFi101-Server.ino
  For SAMD21/SAMD51 with WiFi101 module/shield.

  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).

  Example first created on: 10.05.2018
  Original Author: Markus Sattler

  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/
/****************************************************************************************************************************
  SAMD Websockets Server : Minimal SAMD21/SAMD51 Websockets Server

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

void heartBeatPrint()
{
  static int num = 1;

  if (WiFi.status() == WL_CONNECTED)
    Serial.print("H");        // H means server WiFi connected
  else
    Serial.print("F");        // F means server WiFi not connected

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
  Serial.begin(115200);

  while (!Serial && millis() < 5000);

  Serial.println("\nStarting SAMD_WiFi101-Server with WiFi101_Generic on " + String(BOARD_NAME));
  Serial.println(WEBSOCKETS2_GENERIC_VERSION);

  // check for the WiFi module:
  if (WiFi.status() == WL_NO_SHIELD)
  {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    return;
  }

  String fv = WiFi.firmwareVersion();
  Serial.print("Firmware version installed: ");
  Serial.println(fv);

  String latestFv;

  if (REV(GET_CHIPID()) >= REV_3A0)
  {
    // model B
    latestFv = WIFI_FIRMWARE_LATEST_MODEL_B;
  }
  else
  {
    // model A
    latestFv = WIFI_FIRMWARE_LATEST_MODEL_A;
  }

  if (fv < latestFv)
  {
    Serial.println("Please upgrade the firmware");
    // Print required firmware version
    Serial.print("Latest firmware version available : ");
    Serial.println(latestFv);
  }

  Serial.print("Attempting to connect to SSID: ");
  Serial.println(ssid);

  // Connect to wifi
  // Static IP
  WiFi.config(serverIP);
  WiFi.begin(ssid, password);

  // Wait some time to connect to wifi
  for (int i = 0; i < 15 && WiFi.status() != WL_CONNECTED; i++)
  {
    Serial.print(".");
    delay(1000);
  }

  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("\nWiFi connected");
  }
  else
  {
    Serial.println("\nNo WiFi");
    return;
  }

  server.listen(WEBSOCKETS_PORT);

  Serial.print(server.available() ? "WebSockets Server Running and Ready on " : "Server Not Running on ");
  Serial.println(BOARD_NAME);
  Serial.print("IP address: ");
  Serial.print(WiFi.localIP());     //You can get IP address assigned to SAMD
  Serial.print(", Port: ");
  Serial.println(WEBSOCKETS_PORT);    // Websockets Server Port
}

void loop()
{
  check_status();

  WebsocketsClient client = server.accept();

  if (client.available())
  {
    WebsocketsMessage msg = client.readNonBlocking();

    // log
    Serial.print("Got Message: ");
    Serial.println(msg.data());

    // return echo
    client.send("Echo: " + msg.data());

    // close the connection
    client.close();
  }

  delay(1000);
}
