/****************************************************************************************************************************
  nRF52-Ethernet_ServerAllFunctionsDemo.ino  
  For nRF52 with Ethernet module/shield.
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52 and SAMD21/SAMD51 boards besides ESP8266 and ESP32
  
  The library provides simple and easy interface for websockets (Client and Server).
  
  Example first created on: 10.05.2018
  Original Author: Markus Sattler
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/

#include "defines.h"

#include <WebSockets2_Generic.h>

#include <EthernetWebServer.h>

using namespace websockets2_generic;

WebsocketsServer SocketsServer;

#define WEBSOCKETS_PORT     8080

// Change pins according to your boards
#define RED_LED     7
#define GREEN_LED   6
#define BLUE_LED    5

EthernetWebServer server(80);

void setup()
{
#if (USE_ETHERNET || USE_ETHERNET2 || USE_ETHERNET_LARGE)
  pinMode(SDCARD_CS, OUTPUT);
  digitalWrite(SDCARD_CS, HIGH); // Deselect the SD card
#endif
  
  Serial.begin(115200);
  while (!Serial);

  Serial.println("\nStarting WebSockets2_Generic nRF52-Ethernet_ServerAllFunctionsDemo on " + String(BOARD_NAME));
  Serial.println("Ethernet using " + String(ETHERNET_TYPE));
  Serial.println(WEBSOCKETS2_GENERIC_VERSION);

#if ( USE_ETHERNET || USE_ETHERNET_LARGE || USE_ETHERNET2 || USE_ETHERNET_ENC )
  // Must use library patch for Ethernet, EthernetLarge libraries
  //Ethernet.setCsPin (USE_THIS_SS_PIN);
  Ethernet.init (USE_THIS_SS_PIN);
#endif  // ( USE_ETHERNET || USE_ETHERNET_LARGE || USE_ETHERNET2 || USE_ETHERNET_ENC )

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  digitalWrite(RED_LED, 1);
  digitalWrite(GREEN_LED, 1);
  digitalWrite(BLUE_LED, 1);

  // start the ethernet connection and the server:
  // Use Static IP
  Ethernet.begin(mac, serverIP);
  //Configure IP address via DHCP
  //Ethernet.begin(mac);

  // server address, port and URL
  Serial.print("WebSockets Server IP address: ");
  Serial.println(Ethernet.localIP());

  SocketsServer.listen(WEBSOCKETS_PORT);
 
  Serial.print(SocketsServer.available() ? "WebSockets Server Running and Ready on " : "Server Not Running on ");
  Serial.println(BOARD_NAME);
  Serial.print("IP address: ");
  Serial.print(Ethernet.localIP());
  Serial.print(", Port: ");
  Serial.println(WEBSOCKETS_PORT);    // Websockets Server Port
  
  // handle index
  server.on("/", []()
  {
    String wsServer = String("ws://192.168.2.95:") + WEBSOCKETS_PORT + "/";
    Serial.print("wsServer: ");
    Serial.println(wsServer);

        
    // send index.html
    server.send(200, "text/html", "<html><head><script>var connection = new WebSocket(wsServer, ['arduino']);connection.onopen = function () {  connection.send('Connect ' + new Date()); }; connection.onerror = function (error) {    console.log('WebSocket Error ', error);};connection.onmessage = function (e) {  console.log('Server: ', e.data);};function sendRGB() {  var r = parseInt(document.getElementById('r').value).toString(16);  var g = parseInt(document.getElementById('g').value).toString(16);  var b = parseInt(document.getElementById('b').value).toString(16);  if(r.length < 2) { r = '0' + r; }   if(g.length < 2) { g = '0' + g; }   if(b.length < 2) { b = '0' + b; }   var rgb = '#'+r+g+b;    console.log('RGB: ' + rgb); connection.send(rgb); }</script></head><body>LED Control:<br/><br/>R: <input id=\"r\" type=\"range\" min=\"0\" max=\"255\" step=\"1\" oninput=\"sendRGB();\" /><br/>G: <input id=\"g\" type=\"range\" min=\"0\" max=\"255\" step=\"1\" oninput=\"sendRGB();\" /><br/>B: <input id=\"b\" type=\"range\" min=\"0\" max=\"255\" step=\"1\" oninput=\"sendRGB();\" /><br/></body></html>");
  });

  server.begin();
  
  digitalWrite(RED_LED, 0);
  digitalWrite(GREEN_LED, 0);
  digitalWrite(BLUE_LED, 0);
}

WebsocketsClient* client = NULL;

void loop()
{
  server.handleClient();

  client = new WebsocketsClient;

  if (client)
  {
    *client = SocketsServer.accept();
  
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
}
