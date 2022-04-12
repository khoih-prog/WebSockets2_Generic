/****************************************************************************************************************************
  Teensy41_Server.ino
  For Teensy 4.1 with NativeEthernet.

  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52, SAMD21/SAMD51, SAM DUE, Teensy boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/
/*
  Teensy41 Websockets Server (using NativeEthernet)

  This sketch:
  1. Connects to a ethernet network
  2. Starts a websocket server on port 80
  3. Waits for connections
  4. Once a client connects, it wait for a message from the client
  5. Echoes the message to the client
  6. Closes the connection and goes back to step 3

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

#include <WebSockets2_Generic.h>

#include <TeensyID.h>

using namespace websockets2_generic;

WebsocketsServer server;

// We will set the MAC address at the beginning of `setup()` using TeensyID's
// `teensyMac` helper.
byte mac[6];

// Enter websockets server port.
const uint16_t port = 80;

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

  Serial.println("\nStart Teensy41_Server on Teensy 4.1 NativeEthernet");
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
