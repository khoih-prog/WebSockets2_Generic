/****************************************************************************************************************************
  SocketAndHttp_Teensy41_Server.ino
  For Teensy 4.1 with QNEthernet.

  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52, SAMD21/SAMD51, SAM DUE, Teensy boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/
/*
  Teensy41 Websockets Server and Http Server (using QNEthernet).
  Combining the Teensy41-Server-Multiple-Clients example with the QNEthernet
  WebServer example (https://github.com/vjmuzik/NativeEthernet/blob/master/examples/WebServer/WebServer.ino).

  This sketch:
  1. Connects to a ethernet network
  2. Starts a websocket server on port 8080
  3. Starts a http server at the default port 8080 or 81
  4. Waits for both http and websockets connections
  5. Once a http client connects, it serves an html document, once a socket
     client wants to connect, it checks whether a free slot is available and
     accepts it accordingly
  5. If the socket client is accepted it sends a welcome message and echoes any
     messages from the client
  6. Goes back to step 4

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

#include <EthernetWebServer.h>

#include <TeensyID.h>

using namespace websockets2_generic;

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
const uint16_t websocketsPort = 8080;

// Define how many clients we accept simultaneously.
const byte maxSocketClients = 4;

WebsocketsClient socketClients[maxSocketClients];
WebsocketsServer socketServer;

#define WEBSERVER_PORT      80
//EthernetServer httpServer;
EthernetServer httpServer(WEBSERVER_PORT);

void setup()
{
#if USE_NATIVE_ETHERNET
  // Set the MAC address.
  teensyMAC(mac);
#endif

  // Start Serial and wait until it is ready.
  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  Serial.print("\nStart SocketAndHttp_Teensy41_Server on "); Serial.print(BOARD_NAME);
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
  socketServer.listen(websocketsPort);

  if (!socketServer.available())
  {
    Serial.println("Websockets Server not available!");
  }

  // Start http server.
  //httpServer.begin(80);
  httpServer.begin();
  
  Serial.print("Visit http://");
  Serial.print(Ethernet.localIP());
  Serial.println(" in the browser to connect.");
}

int8_t getFreeSocketClientIndex()
{
  // If a client in our list is not available, it's connection is closed and we
  // can use it for a new client.
  for (byte i = 0; i < maxSocketClients; i++)
  {
    if (!socketClients[i].available())
      return i;
  }

  return -1;
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

void listenForSocketClients()
{
  if (socketServer.poll())
  {
    int8_t freeIndex = getFreeSocketClientIndex();

    if (freeIndex >= 0)
    {
      WebsocketsClient newClient = socketServer.accept();

      Serial.printf("Accepted new websockets client at index %d\n", freeIndex);
      newClient.onMessage(handleMessage);
      newClient.onEvent(handleEvent);
      newClient.send("Hello from Teensy");
      socketClients[freeIndex] = newClient;
    }
  }
}

void pollSocketClients()
{
  for (byte i = 0; i < maxSocketClients; i++)
  {
    socketClients[i].poll();
  }
}

void sendHttpReply(EthernetClient &client)
{
  // Send a website that connects to the websocket server and allows to
  // communicate with the teensy.

  const char* header =
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html\r\n"
    "Connection: close\r\n"
    "\r\n";

  const char* document =
    "<!DOCTYPE html>\n"
    "<title>Teensy 4.1 Websockets</title>\n"
    "<meta charset='UTF-8'>\n"
    "<style>\n"
    "  body {\n"
    "    display: grid;\n"
    "    grid-template: min-content auto / auto min-content;\n"
    "    grid-gap: 1em;\n"
    "    margin: 0;\n"
    "    padding: 1em;\n"
    "    height: 100vh;\n"
    "    box-sizing: border-box;\n"
    "  }\n"
    "  #output {\n"
    "    grid-column-start: span 2;\n"
    "    overflow-y: scroll;\n"
    "    padding: 0.1em;\n"
    "    border: 1px solid;\n"
    "    font-family: monospace;\n"
    "  }\n"
    "</style>\n"
    "<input type='text' id='message' placeholder='Send a message and Teensy will echo it back!'>\n"
    "<button id='send-message'>send</button>\n"
    "<div id='output'></div>\n"
    "<script>\n"
    "  const url = `ws://${window.location.host}:8080`\n"
    "  const ws = new WebSocket(url)\n"
    "  let connected = false\n"
    "  const sendMessage = document.querySelector('#send-message')\n"
    "  const message = document.querySelector('#message')\n"
    "  const output = document.querySelector('#output')\n"
    "  function log(message, color = 'black') {\n"
    "    const el = document.createElement('div')\n"
    "    el.innerHTML = message\n"
    "    el.style.color = color\n"
    "    output.append(el)\n"
    "    output.scrollTop = output.scrollHeight\n"
    "  }\n"
    "  ws.addEventListener('open', () => {\n"
    "    connected = true\n"
    "    log('(✔️) Open', 'green')\n"
    "  })\n"
    "  ws.addEventListener('close', () => {\n"
    "    connected = false\n"
    "    log('(❌) Close', 'red')\n"
    "  })\n"
    "  ws.addEventListener('message', ({ data }) =>\n"
    "    log(`(💌) ${data}`)\n"
    "  )\n"
    "  sendMessage.addEventListener('click', () => {\n"
    "    connected && ws.send(message.value)\n"
    "  })\n"
    "  message.addEventListener('keyup', ({ keyCode }) => {\n"
    "     connected && keyCode === 13 && ws.send(message.value)\n"
    "  })\n"
    "  log(`(📡) Connecting to ${url} ...`, 'blue')\n"
    "</script>\n";

  client.write(header);
  client.write(document);
}

void listenForHttpClients()
{
  // Listen for incoming http clients.
  EthernetClient client = httpServer.available();

  if (client)
  {
    Serial.println("Http client connected!");

    // An http request ends with a blank line.
    bool currentLineIsBlank = true;

    while (client.connected())
    {
      if (client.available())
      {
        char c = client.read();

        if (c == '\n' && currentLineIsBlank)
        {
          // If we've gotten to the end of the line (received a newline
          // character) and the line is blank, the http request has ended,
          // so we can send a reply.
          sendHttpReply(client);
          break;
        }
        else if (c == '\n')
        {
          // Starting a new line.
          currentLineIsBlank = true;
        }
        else if (c != '\r')
        {
          // Read a character on the current line.
          currentLineIsBlank = false;
        }
      }
    }

    // The NativeEthernet's WebServer example adds a small delay here. For me it
    // seems to work without the delay. Uncomment to following line if you have
    // issues connecting to the website in the browser.
    // delay(1);

    // Close the connection.
    client.stop();
  }
}

void loop()
{
  listenForSocketClients();
  pollSocketClients();
  listenForHttpClients();
}
