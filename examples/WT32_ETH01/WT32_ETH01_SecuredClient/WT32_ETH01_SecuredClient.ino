/****************************************************************************************************************************
  WT32_ETH01_SecuredClient.ino
  For WT32_ETH01 (ESP32 + LAN8720)

  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32


  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/
/*
 Secured WT32_ETH01 Websockets Client

  This sketch:
        1. Connects to an Ethernet network
        2. Connects to a Websockets server (using WSS)
        3. Sends the websockets server a message ("Hello Server from ......")
        4. Sends the websocket server a "ping"
        5. Prints all incoming messages while the connection is open

    NOTE:
    The sketch dosen't check or indicate about errors while connecting to
    WiFi or to the websockets server. For full example you might want
    to try the example named "-Client" (And use the ssl methods).

  Hardware:
        For this sketch you only need an WT32_ETH01 board.

  Originally Created  : 15/02/2019
  Original Author     : By Gil Maimon
  Original Repository : https://github.com/gilmaimon/ArduinoWebsockets

*****************************************************************************************************************************/

#include "defines.h"

#include <WebSockets2_Generic.h>

using namespace websockets2_generic;

WebsocketsClient client;

void onMessageCallback(WebsocketsMessage message) 
{
  Serial.print("Got Message: ");
  Serial.println(message.data());
}

void onEventsCallback(WebsocketsEvent event, String data) 
{
  (void) data;
  
  if (event == WebsocketsEvent::ConnectionOpened) 
  {
    Serial.println("Connnection Opened");
  } 
  else if (event == WebsocketsEvent::ConnectionClosed) 
  {
    Serial.println("Connnection Closed");
  } 
  else if (event == WebsocketsEvent::GotPing) 
  {
    Serial.println("Got a Ping!");
  } 
  else if (event == WebsocketsEvent::GotPong) 
  {
    Serial.println("Got a Pong!");
  }
}

void setup() 
{
  Serial.begin(115200);
  while (!Serial && millis() < 5000);
  
  Serial.print("\nStart WT32_ETH01_SecuredClient on "); Serial.print(ARDUINO_BOARD);
  Serial.print(" with "); Serial.println(SHIELD_TYPE);
  Serial.println(WEBSERVER_WT32_ETH01_VERSION);
  Serial.println(WEBSOCKETS2_GENERIC_VERSION);

  // To be called before ETH.begin()
  WT32_ETH01_onEvent();

  //bool begin(uint8_t phy_addr=ETH_PHY_ADDR, int power=ETH_PHY_POWER, int mdc=ETH_PHY_MDC, int mdio=ETH_PHY_MDIO, 
  //           eth_phy_type_t type=ETH_PHY_TYPE, eth_clock_mode_t clk_mode=ETH_CLK_MODE);
  //ETH.begin(ETH_PHY_ADDR, ETH_PHY_POWER, ETH_PHY_MDC, ETH_PHY_MDIO, ETH_PHY_TYPE, ETH_CLK_MODE);
  ETH.begin(ETH_PHY_ADDR, ETH_PHY_POWER);

  // Static IP, leave without this line to get IP via DHCP
  //bool config(IPAddress local_ip, IPAddress gateway, IPAddress subnet, IPAddress dns1 = 0, IPAddress dns2 = 0);
  ETH.config(myIP, myGW, mySN, myDNS);

  WT32_ETH01_waitForConnect();

  Serial.print("Connected. Connecting to WebSockets Server @");
  Serial.println(websockets_connection_string);

  // run callback when messages are received
  client.onMessage(onMessageCallback);

  // run callback when events are occuring
  client.onEvent(onEventsCallback);

  // Before connecting, set the ssl fingerprint of the server
  client.setCACert(echo_org_ssl_ca_cert);

  // Connect to server
  bool connected = client.connect(websockets_connection_string);

  if (connected) 
  {
    Serial.println("Connected!");

    String WS_msg = String("Hello to Server from ") + ARDUINO_BOARD;
    client.send(WS_msg);

    // Send a ping
    client.ping();
  } 
  else 
  {
    Serial.println("Not Connected!");
  }
}

void loop() 
{
  client.poll();
}
