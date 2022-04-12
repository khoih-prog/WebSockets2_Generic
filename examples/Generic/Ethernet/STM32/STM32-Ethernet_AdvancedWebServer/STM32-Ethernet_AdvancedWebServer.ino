/****************************************************************************************************************************
  SATM32-Ethernet_AdvancedWebServer.ino
  For STM32F/L/H/G/WB/MP1 with Ethernet module/shield.

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

#include <EthernetWebServer_STM32.h>

using namespace websockets2_generic;

WebsocketsServer SocketsServer;

#define WEBSOCKETS_PORT     8080

EthernetWebServer server(80);

// Select the IP address according to your local network
IPAddress serverIP(192, 168, 2, 95);

int reqCount = 0;                // number of requests received

void handleRoot()
{
#define BUFFER_SIZE     400

  char temp[BUFFER_SIZE];
  int sec = millis() / 1000;
  int min = sec / 60;
  int hr = min / 60;
  int day = hr / 24;

  hr %= 24;

  snprintf(temp, BUFFER_SIZE - 1,
           "<html>\
<head>\
<meta http-equiv='refresh' content='5'/>\
<title>AdvancedWebServer %s</title>\
<style>\
body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
</style>\
</head>\
<body>\
<h2>WebSockets&WebServer!</h2>\
<h3>both on %s</h3>\
<p>Uptime: %d d %02d:%02d:%02d</p>\
<img src=\"/test.svg\" />\
</body>\
</html>", BOARD_NAME, BOARD_NAME, day, hr % 24, min % 60, sec % 60);

  server.send(200, "text/html", temp);
}

void handleNotFound()
{
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for (uint8_t i = 0; i < server.args(); i++)
  {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }

  server.send(404, "text/plain", message);
}

void drawGraph()
{
  String out;
  out.reserve(3000);
  char temp[70];
  out += "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"310\" height=\"150\">\n";
  out += "<rect width=\"310\" height=\"150\" fill=\"rgb(250, 230, 210)\" stroke-width=\"5\" stroke=\"rgb(0, 0, 0)\" />\n";
  out += "<g stroke=\"blue\">\n";

  int y = rand() % 130;

  for (int x = 15; x < 300; x += 15)
  {
    int y2 = rand() % 130;
    sprintf(temp, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke-width=\"1\" />\n", x, 140 - y, x + 15, 140 - y2);
    out += temp;
    y = y2;
  }

  out += "</g>\n</svg>\n";

  server.send(200, "image/svg+xml", out);
}

void initEthernet()
{
#if USE_LAN8742A_ETHERNET
  LOGWARN(F("=========== USE_LAN8742A_ETHERNET ===========")); 
#elif USE_ETHERNET_GENERIC
  LOGWARN(F("=========== USE_ETHERNET_GENERIC ==========="));  
#elif USE_ETHERNET_ESP8266
  LOGWARN(F("=========== USE_ETHERNET_ESP8266 ==========="));
#elif USE_ETHERNET_ENC
  LOGWARN(F("=========== USE_ETHERNET_ENC ==========="));  
#else
  LOGWARN(F("========================="));
#endif

#if !(USE_BUILTIN_ETHERNET)
  #if (USING_SPI2)
    #if defined(CUR_PIN_MISO)
      LOGWARN(F("Default SPI pinout:"));
      LOGWARN1(F("MOSI:"), CUR_PIN_MOSI);
      LOGWARN1(F("MISO:"), CUR_PIN_MISO);
      LOGWARN1(F("SCK:"),  CUR_PIN_SCK);
      LOGWARN1(F("SS:"),   CUR_PIN_SS);
      LOGWARN(F("========================="));
    #endif
  #else
    LOGWARN(F("Default SPI pinout:"));
    LOGWARN1(F("MOSI:"), MOSI);
    LOGWARN1(F("MISO:"), MISO);
    LOGWARN1(F("SCK:"),  SCK);
    LOGWARN1(F("SS:"),   SS);
    LOGWARN(F("========================="));
  #endif

  pinMode(USE_THIS_SS_PIN, OUTPUT);
  digitalWrite(USE_THIS_SS_PIN, HIGH);
  
  LOGWARN2(BOARD_NAME, F(" setCsPin:"), USE_THIS_SS_PIN);
  
  // For other boards, to change if necessary
  #if ( USE_ETHERNET_GENERIC || USE_ETHERNET_ENC )
    // Must use library patch for Ethernet, EthernetLarge libraries
    // For RPI Pico using Arduino Mbed RP2040 core
    // SCK: GPIO2,  MOSI: GPIO3, MISO: GPIO4, SS/CS: GPIO5
    // For RPI Pico using E. Philhower RP2040 core
    // SCK: GPIO18,  MOSI: GPIO19, MISO: GPIO16, SS/CS: GPIO17
    // Default pin 5/17 to SS/CS
  
    //Ethernet.setCsPin (USE_THIS_SS_PIN);
    Ethernet.init (USE_THIS_SS_PIN);
     
  #endif    //( USE_ETHERNET_GENERIC || USE_ETHERNET_ENC )

  LOGWARN(F("========================="));
  
  #if defined(CUR_PIN_MISO)
    LOGWARN(F("Currently Used SPI pinout:"));
    LOGWARN1(F("MOSI:"), CUR_PIN_MOSI);
    LOGWARN1(F("MISO:"), CUR_PIN_MISO);
    LOGWARN1(F("SCK:"),  CUR_PIN_SCK);
    LOGWARN1(F("SS:"),   CUR_PIN_SS);
  #else
    LOGWARN(F("Currently Used SPI pinout:"));
    LOGWARN1(F("MOSI:"), MOSI);
    LOGWARN1(F("MISO:"), MISO);
    LOGWARN1(F("SCK:"),  SCK);
    LOGWARN1(F("SS:"),   SS);
  #endif
  
  LOGWARN(F("========================="));

#endif  
}

void setup()
{
#if (defined(ETHERNET_WITH_SD_CARD) && ETHERNET_WITH_SD_CARD)
  pinMode(SDCARD_CS, OUTPUT);
  digitalWrite(SDCARD_CS, HIGH); // Deselect the SD card
#endif

  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  Serial.println("\nStarting STM32-Ethernet_AdvancedWebServer on " + String(BOARD_NAME));
  Serial.println("Ethernet using " + String(ETHERNET_TYPE));
  Serial.println(WEBSOCKETS2_GENERIC_VERSION);

  initEthernet();

  // start the ethernet connection and the server:
  // Use DHCP dynamic IP and random mac
  uint16_t index = millis() % NUMBER_OF_MAC;
  // Use Static IP
  //Ethernet.begin(mac[index], serverIP);
  Ethernet.begin(mac[index]);

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

  server.on("/", handleRoot);
  server.on("/test.svg", drawGraph);
  server.on("/inline", []()
  {
    server.send(200, "text/plain", "This works as well");
  });

  server.onNotFound(handleNotFound);
  server.begin();
}

void loop()
{
  server.handleClient();

  WebsocketsClient client = SocketsServer.accept();

  if (client.available())
  {
    WebsocketsMessage msg = client.readNonBlocking();

    // log
    Serial.print("Got Message: ");
    Serial.println(msg.data());

    // return echo
    client.send("Echo: " + msg.data());

    // close the connection
    client.close();
  }
}
