/****************************************************************************************************************************
  Teensy41_Client.ino
  For Teensy 4.1 with QNEthernet.

  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52, SAMD21/SAMD51, SAM DUE, Teensy boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).

  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/
/*
  Teensy41 Websockets Client (using QNEthernet)

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
    QNEthernet (https://github.com/ssilverman/QNEthernet)

  Hardware:
  For this sketch you need a Teensy 4.1 board and the Teensy 4.1 Ethernet Kit
  (https://www.pjrc.com/store/ethernet_kit.html).

  Written by https://github.com/arnoson
*/

#if ( defined(CORE_TEENSY) && defined(__IMXRT1062__) && defined(ARDUINO_TEENSY41) )
  // For Teensy 4.1
  #define BOARD_TYPE      "TEENSY 4.1"
  // Use true for NativeEthernet Library, false if using other Ethernet libraries
  #define USE_NATIVE_ETHERNET     false
  #define USE_QN_ETHERNET         true
#else
  #error Only Teensy 4.1 supported
#endif

#ifndef BOARD_NAME
#define BOARD_NAME    BOARD_TYPE
#endif

#define DEBUG_WEBSOCKETS_PORT       Serial
// Debug Level from 0 to 4
#define _WEBSOCKETS_LOGLEVEL_       4

#define WEBSOCKETS_USE_ETHERNET     true

#include <WebSockets2_Generic.h>

#include <TeensyID.h>     // https://github.com/sstaub/TeensyID
#include <SPI.h>

using namespace websockets2_generic;

WebsocketsClient client;

// Set the static IP address to use if the DHCP fails to assign
IPAddress myIP(192, 168, 2, 222);

#if USE_NATIVE_ETHERNET

#include "NativeEthernet.h"
#warning Using NativeEthernet lib for Teensy 4.1. Must also use Teensy Packages Patch or error
#define SHIELD_TYPE           "using NativeEthernet"

// We will set the MAC address at the beginning of `setup()` using TeensyID's
// `teensyMac` helper.
byte mac[6];

#else

#include "QNEthernet.h"       // https://github.com/ssilverman/QNEthernet
using namespace qindesign::network;
#warning Using QNEthernet lib for Teensy 4.1. Must also use Teensy Packages Patch or error

#define SHIELD_TYPE           "using QNEthernet"

//#define USING_DHCP            true
#define USING_DHCP            false

#if !USING_DHCP

IPAddress myNetmask(255, 255, 255, 0);
IPAddress myGW(192, 168, 2, 1);
//IPAddress mydnsServer(192, 168, 2, 1);
IPAddress mydnsServer(8, 8, 8, 8);
#endif

#endif

// Enter websockets url.
// Note: wss:// currently not working.
// ws://echo.websocket.org is no longer working. Please create your own WS Local Server to test
//const char* url  = "ws://echo.websocket.org";
//const char* url  = "ws://192.168.2.95:80";
const char* url  = "ws://192.168.2.30:8080";

void setup()
{
#if USE_NATIVE_ETHERNET
  // Set the MAC address.
  teensyMAC(mac);
#endif

  // Start Serial and wait until it is ready.
  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  Serial.print("\nStarting Teensy41_Client on "); Serial.print(BOARD_NAME);
  Serial.print(" "); Serial.println(SHIELD_TYPE);
  Serial.println(WEBSOCKETS2_GENERIC_VERSION);

#if USE_NATIVE_ETHERNET
  Serial.println(F("======== USE_NATIVE_ETHERNET ========"));
#elif USE_QN_ETHERNET
  Serial.println(F("=========== USE_QN_ETHERNET ==========="));
#endif

#if USE_NATIVE_ETHERNET

  // start the ethernet connection and the server:

  // Use Static IP
  //Ethernet.begin(mac, myIP);
  // Use DHCP dynamic IP
  Ethernet.begin(mac);

  Serial.println(F("========================="));
  Serial.print("Connected! IP address:"); Serial.println(Ethernet.localIP());

#else

#if USING_DHCP
  // Start the Ethernet connection, using DHCP
  Serial.print("Initialize Ethernet using DHCP => ");
  Ethernet.begin();
#else
  // Start the Ethernet connection, using static IP
  Serial.print("Initialize Ethernet using static IP => ");
  Ethernet.begin(myIP, myNetmask, myGW);
  Ethernet.setDNSServerIP(mydnsServer);
#endif

  if (!Ethernet.waitForLocalIP(5000))
  {
    Serial.println("Failed to configure Ethernet");

    if (!Ethernet.linkStatus())
    {
      Serial.println("Ethernet cable is not connected.");
    }

    // Stay here forever
    while (true)
    {
      delay(1);
    }
  }

  if (!Ethernet.waitForLink(5000))
  {
    Serial.println(F("Failed to wait for Link"));
  }
  else
  {
    Serial.print("IP Address = ");
    Serial.println(Ethernet.localIP());
  }

#endif

// give the Ethernet shield minimum 1 sec for DHCP and 2 secs for staticP to initialize:
#if USING_DHCP
  delay(1000);
#else  
  delay(2000);
#endif

  // Connect to websocket server.
  if (client.connect(url))
  {
    Serial.print("Connected to server : "); Serial.println(url);
    // Send welcome message.
    client.send("Hello Server from Teensy 4.1 QNEthernet");
  }
  else
  {
    Serial.print("Couldn't connect to server : "); Serial.println(url);
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
