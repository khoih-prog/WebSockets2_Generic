/****************************************************************************************************************************
  RP2040W-RepeatingClient.ino
  For RP2040W with CYW43439 WiFi.
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52, SAMD21/SAMD51, RP2040 boards besides ESP8266 and ESP32


  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/
/****************************************************************************************************************************
	RP2040W Websockets Repeating Client

	This sketch:
        1. Connects to a WiFi network
        2. Connects to a Websockets server
        3. Sends the websockets server a message ("Hello to Server from ......")
        4. Prints all incoming messages while the connection is open
        5. Repeat 2-4 every REPEAT_INTERVAL (10 seconds)


	Hardware:
        For this sketch you only need a RP2040W board.

	Originally Created  : 15/02/2019
	Original Author     : By Gil Maimon
	Original Repository : https://github.com/gilmaimon/ArduinoWebsockets

*****************************************************************************************************************************/

#include "defines.h"

const char* websockets_server_host = "192.168.2.30"; //Enter server address
//const char* websockets_server_host = "serverip_or_name"; //Enter server address

const uint16_t websockets_server_port = 8080; // Enter server port

int status = WL_IDLE_STATUS;

#include <WebSockets2_Generic.h>

using namespace websockets2_generic;

WebsocketsClient client;

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

  Serial.println("\nStarting RP2040W-RepeatingClient on " + String(BOARD_NAME));
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
  client.onMessage([&](WebsocketsMessage message) 
  {
    Serial.print("Got Message: ");
    Serial.println(message.data());
  });

  // run callback when events are occuring
  client.onEvent(onEventsCallback);
}

void sendMessage()
{
// try to connect to Websockets server
  bool connected = client.connect(websockets_server_host, websockets_server_port, "/");
  
  if (connected) 
  {
    Serial.println("Connected!");

    String WS_msg = String("Hello to Server from ") + BOARD_NAME;
    client.send(WS_msg);
  } 
  else 
  {
    Serial.println("Not Connected!");
  }
}

void checkToSendMessage()
{
  #define REPEAT_INTERVAL    10000L
  
  static unsigned long checkstatus_timeout = 1000;

  // Send WebSockets message every REPEAT_INTERVAL (10) seconds.
  if (millis() > checkstatus_timeout)
  {
    sendMessage();
    checkstatus_timeout = millis() + REPEAT_INTERVAL;
  }
}

void loop() 
{

  checkToSendMessage();
  
  // let the websockets client check for incoming messages
  if (client.available()) 
  {
    client.poll();
  }
}
