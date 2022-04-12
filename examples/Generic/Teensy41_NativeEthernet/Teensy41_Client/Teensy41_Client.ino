/****************************************************************************************************************************
  Teensy41_Client.ino
  For Teensy 4.1 with NativeEthernet.

  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52, SAMD21/SAMD51, SAM DUE, Teensy boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/
/*
  Teensy41 Websockets Client (using NativeEthernet)

  This sketch:
  1. Connects to a ethernet network
  2. Connects to a websockets server at port 80
  3. Sends the websockets server a message ("Hello Server")
  4. Prints all incoming messages while the connection is open

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

#include <TeensyID.h>     // https://github.com/sstaub/TeensyID
#include <SPI.h>

using namespace websockets2_generic;

WebsocketsClient client;

// We will set the MAC address at the beginning of `setup()` using TeensyID's
// `teensyMac` helper.
byte mac[6];

// Enter websockets url.
// Note: wss:// currently not working.
// ws://echo.websocket.org is no longer working. Please create your own WS Local Server to test
//const char* url  = "ws://echo.websocket.org";
const char* url  = "ws://192.168.2.30:8080";

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

  Serial.println("\nStart Teensy41_Client on Teensy 4.1 NativeEthernet");
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

  // Connect to websocket server.
  if (client.connect(url)) 
  {
    Serial.printf("Connected to server %s\n", url);
    // Send welcome message.
    client.send("Hello Server from Teensy 4.1 NativeEthernet");
  } 
  else 
  {
    Serial.println("Couldn't connect to server!");
  }

  // Run callback when messages are received.
  client.onMessage([&](WebsocketsMessage message) 
  {
    Serial.print("Got Message: ");
    Serial.println(message.data());
  });
}

void loop() 
{
  // Check for incoming messages.
  if (client.available()) 
  {
    client.poll();
  }
}
