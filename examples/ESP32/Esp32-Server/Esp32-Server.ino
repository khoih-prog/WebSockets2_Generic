/****************************************************************************************************************************
  ESP32-Server.ino
  For ESP32.

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
/****************************************************************************************************************************
  ESP32 Websockets Server : Minimal ESP32 Websockets Server

  This sketch:
        1. Connects to a WiFi network
        2. Starts a websocket server on port 8080
        3. Waits for connections
        4. Once a client connects, it wait for a message from the client
        5. Sends an "echo" message to the client
        6. closes the connection and goes back to step 3

  Hardware:
        For this sketch you only need an ESP32 board.

  Originally Created  : 15/02/2019
  Original Author     : By Gil Maimon
  Original Repository : https://github.com/gilmaimon/ArduinoWebsockets

*****************************************************************************************************************************/

#include "defines.h"

#define DEBUG_LOCAL   2

#include <WebSockets2_Generic.h>
#include <WiFi.h>

using namespace websockets2_generic;

WebsocketsServer server;

#define WEBSOCKETS_PORT     8080

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  Serial.println("\nStarting WebSockets2_Generic ESP32-Server on " + String(BOARD_TYPE));

  // Connect to wifi
  WiFi.begin(ssid, password);

  // Wait some time to connect to wifi
  for (int i = 0; i < 15 && WiFi.status() != WL_CONNECTED; i++)
  {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nWiFi connected");

  server.listen(WEBSOCKETS_PORT);
  
  Serial.print(server.available() ? "WebSockets Server Running and Ready on " : "Server Not Running on ");
  Serial.println(BOARD_TYPE);
  Serial.print("IP address: ");
  Serial.print(WiFi.localIP());     //You can get IP address assigned to SAMD
  Serial.print(", Port: ");
  Serial.println(WEBSOCKETS_PORT);    // Websockets Server Port
}

void loop()
{
  WebsocketsClient client = server.accept();

  if (client.available())
  {
    WebsocketsMessage msg = client.readBlocking();

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
