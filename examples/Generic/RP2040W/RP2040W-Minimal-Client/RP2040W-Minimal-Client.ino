/****************************************************************************************************************************
  RP2040W-Minimal-Client.ino
  For RP2040W with CYW43439 WiFi.
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52, SAMD21/SAMD51, RP2040 boards besides ESP8266 and ESP32


  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/
/****************************************************************************************************************************
  RP2040W-Minimal-Client: Minimal RP2040W Websockets Client

  This sketch:
        1. Connects to a WiFi network
        2. Connects to a Websockets server
        3. Sends the websockets server a message ("Hello to Server from ......")
        4. Sends the websocket server a "ping"
        5. Prints all incoming messages while the connection is open

    NOTE:
    The sketch dosen't check or indicate about errors while connecting to
    WiFi or to the websockets server. For full example you might want
    to try the example named "RP2040W-Client".


  Hardware:
        For this sketch you only need a RP2040W board.

  Originally Created  : 15/02/2019
  Original Author     : By Gil Maimon
  Original Repository : https://github.com/gilmaimon/ArduinoWebsockets

*****************************************************************************************************************************/

#include "defines.h"

const char* websockets_server_host = "192.168.2.30"; //Enter server address
//const char* websockets_server_host = "serverip_or_name"; //Enter server address

#define WEBSOCKETS_PORT     8080

const uint16_t websockets_server_port = WEBSOCKETS_PORT; // Enter server port

int status = WL_IDLE_STATUS;

#include <WebSockets2_Generic.h>

using namespace websockets2_generic;

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

WebsocketsClient client;

void printWifiStatus()
{
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("Local IP Address: ");
  Serial.println(ip);
}

void setup()
{
  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  Serial.println("\nStarting RP2040W-Minimal-Client on " + String(BOARD_NAME));
  Serial.println(WEBSOCKETS2_GENERIC_VERSION);
  
  ///////////////////////////////////

  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE)
  {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }

  Serial.print(F("Connecting to SSID: "));
  Serial.println(ssid);
 
  status = WiFi.begin(ssid, pass);

  delay(1000);
   
  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED)
  {
    delay(500);
        
    // Connect to WPA/WPA2 network
    status = WiFi.status();
  }

  printWifiStatus();

  ///////////////////////////////////

  Serial.print("Connecting to WebSockets Server @");
  Serial.println(websockets_server_host);
  
  // run callback when messages are received
  client.onMessage(onMessageCallback);

  // run callback when events are occuring
  client.onEvent(onEventsCallback);

  // Connect to server
  client.connect(websockets_server_host, websockets_server_port, "/");

  // Send a message
  String WS_msg = String("Hello to Server from ") + BOARD_NAME;
  client.send(WS_msg);

  // Send a ping
  client.ping();
}

void loop() 
{
  client.poll();
}
