/****************************************************************************************************************************
  Teensy41_Server.ino
  For Teensy 4.1 with QNEthernet.

  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52, SAMD21/SAMD51, SAM DUE, Teensy boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).

  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/
/*
  Teensy41 Websockets Server and Http Server (using QNEthernet).

  This sketch:
  1. Connects to a ethernet network
  2. Starts a websocket server on port 8080 or 81
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

#if ( defined(CORE_TEENSY) && defined(__IMXRT1062__) && defined(ARDUINO_TEENSY41) )
  // For Teensy 4.1
  #define BOARD_TYPE      "TEENSY 4.1"
  // Use true for NativeEthernet Library, false if using other Ethernet libraries
  #define USE_NATIVE_ETHERNET     false
  #define USE_QN_ETHERNET         true
  //#define USE_NATIVE_ETHERNET     true
  //#define USE_QN_ETHERNET         false
#else
  #error Only Teensy 4.1 supported
#endif

#ifndef BOARD_NAME
  #define BOARD_NAME    BOARD_TYPE
#endif

#define WEBSOCKETS_USE_ETHERNET     true

#include <WebSockets2_Generic.h>

#include <TeensyID.h>

using namespace websockets2_generic;

WebsocketsServer server;

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
  
  // Static IP not working yet. Don't use now until fixed.
  #define USING_DHCP            true
  
  #if !USING_DHCP
  
    IPAddress myNetmask(255, 255, 255, 0);
    IPAddress myGW(192, 168, 2, 1);
    //IPAddress mydnsServer(192, 168, 2, 1);
    IPAddress mydnsServer(8, 8, 8, 8);
  #endif

#endif

// Enter websockets server port.
const uint16_t port = 8080;

void setup()
{
#if USE_NATIVE_ETHERNET
  // Set the MAC address.
  teensyMAC(mac);
#endif

  // Start Serial and wait until it is ready.
  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  Serial.print("\nStarting Teensy41_Server on "); Serial.print(BOARD_NAME);
  Serial.print(" "); Serial.println(SHIELD_TYPE);
  Serial.println(WEBSOCKETS2_GENERIC_VERSION);

#if USE_NATIVE_ETHERNET
  Serial.println("======== USE_NATIVE_ETHERNET ========");
#elif USE_QN_ETHERNET
  Serial.println("=========== USE_QN_ETHERNET ===========");
#endif

#if USE_NATIVE_ETHERNET

  // start the ethernet connection and the server:

  // Use Static IP
  //Ethernet.begin(mac, myIP);
  // Use DHCP dynamic IP
  Ethernet.begin(mac);

  Serial.println("=========================");
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
