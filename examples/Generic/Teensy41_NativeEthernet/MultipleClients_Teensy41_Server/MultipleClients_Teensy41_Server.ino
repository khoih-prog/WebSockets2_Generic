/****************************************************************************************************************************
  MultiClients_Teensy41_Server.ino
  For Teensy 4.1 with NativeEthernet.

  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52, SAMD21/SAMD51, SAM DUE, Teensy boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/
/*
  Teensy41 Websockets Server and Http Server (using NativeEthernet).
  Combining the Teensy41-Server example with the NativeEthernet WebServer
  example (https://github.com/vjmuzik/NativeEthernet/blob/master/examples/WebServer/WebServer.ino).

  This sketch:
  1. Connects to a ethernet network
  2. Starts a websocket server on port 80
  3. Waits for connections
  4. As soon as a client wants to establish a connection, it checks whether a
     free slot is available and accepts it accordingly
  5. If the client is accepted it sends a welcome message and echoes any
     messages from the client
  6. Goes back to step 3

  Note:
  Make sure you share your computer's internet connection with the Teensy
  via ethernet.

  Libraries:
  To use this sketch install
    TeensyID library (https://github.com/sstaub/TeensyID)
    NativeEthernet (https://github.com/vjmuzik/NativeEthernet)

  Hardware:
  For this sketch you need a Teensy 4.1 board and the Teensy 4.1 Ethernet Kit
  (https://www.pjrc.com/store/ethernet_kit.html).

  Written by https://github.com/arnoson
*/

#if !(defined(__IMXRT1062__) && defined(ARDUINO_TEENSY41))
  #error This is designed only for Teensy 4.1. Please check your Tools-> Boards
#endif

#define WEBSOCKETS_USE_ETHERNET     true
#define USE_NATIVE_ETHERNET         true

//#include <NativeEthernet.h>

//#include <ArduinoWebsockets.h>
#include <WebSockets2_Generic.h>

#include <TeensyID.h>

using namespace websockets2_generic;

// We will set the MAC address at the beginning of `setup()` using TeensyID's
// `teensyMac` helper.
byte mac[6];

// Enter websockets server port.
const uint16_t port = 81;

// Define how many clients we accept simultaneously.
const byte maxClients = 4;

WebsocketsClient clients[maxClients];
WebsocketsServer server;

//#define USING_DHCP            true
#define USING_DHCP            false

#if !USING_DHCP
  // Set the static IP address to use if the DHCP fails to assign
  IPAddress myIP(192, 168, 2, 222);
  IPAddress myNetmask(255, 255, 255, 0);
  IPAddress myGW(192, 168, 2, 1);
  //IPAddress mydnsServer(192, 168, 2, 1);
  IPAddress mydnsServer(8, 8, 8, 8);
#endif

void setup()
{
  // Set the MAC address.
  teensyMAC(mac);

  // Start Serial and wait until it is ready.
  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  Serial.println("\nStart MultiClients_Teensy41_Server on Teensy 4.1 NativeEthernet");
  Serial.println(WEBSOCKETS2_GENERIC_VERSION);

  // Connect to ethernet.
#if USING_DHCP  
  if (Ethernet.begin(mac)) 
  {
    Serial.print("Ethernet connected (");
    Serial.print(Ethernet.localIP());
    Serial.println(")");
  }
  else 
  {
    Serial.println("Ethernet failed");
  }

  // give the Ethernet shield minimum 1 sec for DHCP 
  delay(1000);
#else
  // Use Static IP
  Ethernet.begin(mac, myIP, mydnsServer);
  
  Serial.print("Ethernet connected (");
  Serial.print(Ethernet.localIP());
  Serial.println(")");

  // give the Ethernet shield minimum 2 secs for staticP to initialize:
  delay(2000);
#endif

  // Start websockets server.
  server.listen(port);

  if (server.available())
  {
    Serial.print("Server available at ws://");
    Serial.print(Ethernet.localIP());
    // Also log any non default port.
    if (port != 80)
      Serial.printf(":%d", port);

    Serial.println();
  }
  else
  {
    Serial.println("Server not available!");
  }
}

void handleMessage(WebsocketsClient &client, WebsocketsMessage message)
{
  auto data = message.data();

  // Log message
  Serial.print("Got Message: ");
  Serial.println(data);

  // Echo message
  client.send("Echo: " + data);
}

void handleEvent(WebsocketsClient &client, WebsocketsEvent event, String data)
{
  if (event == WebsocketsEvent::ConnectionClosed)
  {
    Serial.println("Connection closed");
  }
}

int8_t getFreeClientIndex()
{
  // If a client in our list is not available, it's connection is closed and we
  // can use it for a new client.
  for (byte i = 0; i < maxClients; i++)
  {
    if (!clients[i].available())
      return i;
  }

  return -1;
}

void listenForClients()
{
  if (server.poll())
  {
    int8_t freeIndex = getFreeClientIndex();

    if (freeIndex >= 0)
    {
      WebsocketsClient newClient = server.accept();

      Serial.printf("Accepted new websockets client at index %d\n", freeIndex);
      newClient.onMessage(handleMessage);
      newClient.onEvent(handleEvent);
      newClient.send("Hello from Teensy 4.1 NativeEthernet");
      clients[freeIndex] = newClient;
    }
  }
}

void pollClients()
{
  for (byte i = 0; i < maxClients; i++)
  {
    clients[i].poll();
  }
}

void loop()
{
  listenForClients();
  pollClients();
}
