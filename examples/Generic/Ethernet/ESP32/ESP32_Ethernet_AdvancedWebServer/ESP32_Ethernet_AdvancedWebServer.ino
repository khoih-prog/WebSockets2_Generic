/****************************************************************************************************************************
  ESP32_Ethernet_AdvancedWebServer.ino
  For ESP32 with Ethernet module/shield.

  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52, RP2040, SAMD21/SAMD51, SAM DUE, Teensy boards besides ESP8266 and ESP32

  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/

#include "defines.h"

#include <WebSockets2_Generic.h>

#include <EthernetWebServer.h>

using namespace websockets2_generic;

WebsocketsServer SocketsServer;

#define WEBSOCKETS_PORT     8080

EthernetWebServer server(80);

int reqCount = 0;                // number of requests received

// Select the IP address according to your local network
IPAddress serverIP(192, 168, 2, 93);

void handleRoot()
{
#define BUFFER_SIZE     512

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

#define ORIGINAL_STR_LEN        2048

void drawGraph()
{
  static String out;
  static uint16_t previousStrLen = ORIGINAL_STR_LEN;

  if (out.length() == 0)
  {
    LOGWARN1(F("String Len = 0, extend to"), ORIGINAL_STR_LEN);
    out.reserve(ORIGINAL_STR_LEN);
  }

  out = F( "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"310\" height=\"150\">\n" \
           "<rect width=\"310\" height=\"150\" fill=\"rgb(250, 230, 210)\" stroke-width=\"3\" stroke=\"rgb(0, 0, 0)\" />\n" \
           "<g stroke=\"blue\">\n");

  char temp[70];
  
  int y = rand() % 130;

  for (int x = 10; x < 300; x += 10)
  {
    int y2 = rand() % 130;
    sprintf(temp, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke-width=\"2\" />\n", x, 140 - y, x + 10, 140 - y2);
    out += temp;
    y = y2;
  }
  
  out += F("</g>\n</svg>\n");

  LOGDEBUG1(F("String Len = "), out.length());

  if (out.length() > previousStrLen)
  {
    LOGERROR3(F("String Len > "), previousStrLen, F(", extend to"), out.length() + 48);

    previousStrLen = out.length() + 48;
    
    out.reserve(previousStrLen);
  }
  else
  {
    server.send(200, "image/svg+xml", out);
  }
}

void initEthernet()
{ 
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

// You can use Ethernet.init(pin) to configure the CS pin
//Ethernet.init(10);  // Most Arduino shields
//Ethernet.init(5);   // MKR ETH shield
//Ethernet.init(0);   // Teensy 2.0
//Ethernet.init(20);  // Teensy++ 2.0
//Ethernet.init(15);  // ESP8266 with Adafruit Featherwing Ethernet
//Ethernet.init(33);  // ESP32 with Adafruit Featherwing Ethernet

#ifndef USE_THIS_SS_PIN
  #define USE_THIS_SS_PIN   5   //22    // For ESP32
#endif

LOGWARN1(F("ESP32 setCsPin:"), USE_THIS_SS_PIN);

// For other boards, to change if necessary
#if ( USE_ETHERNET_GENERIC || USE_ETHERNET_ENC )
  // Must use library patch for Ethernet, EthernetLarge libraries
  // ESP32 => GPIO2,4,5,13,15,21,22 OK with Ethernet, Ethernet2, EthernetLarge
  // ESP32 => GPIO2,4,5,15,21,22 OK with Ethernet3

  //Ethernet.setCsPin (USE_THIS_SS_PIN);
  Ethernet.init (USE_THIS_SS_PIN);

#elif USE_CUSTOM_ETHERNET

  // You have to add initialization for your Custom Ethernet here
  // This is just an example to setCSPin to USE_THIS_SS_PIN, and can be not correct and enough
  Ethernet.init(USE_THIS_SS_PIN); 

#endif  //( USE_ETHERNET_GENERIC || USE_ETHERNET_ENC )

/////////////////////////////////////

  // start the ethernet connection and the server:
  // Use DHCP dynamic IP and random mac
  uint16_t index = millis() % NUMBER_OF_MAC;
  // Use Static IP
  //Ethernet.begin(mac[0], ip);
  Ethernet.begin(mac[index]);

#if USE_ETHERNET_GENERIC

  LOGWARN(F("========================="));
  
  // Just info to know how to connect correctly
  // To change for other SPI
  LOGWARN(F("Currently Used SPI pinout:"));
  LOGWARN1(F("MOSI:"), PIN_MOSI);
  LOGWARN1(F("MISO:"), PIN_MISO);
  LOGWARN1(F("SCK:"),  PIN_SCK);
  LOGWARN1(F("SS:"),   PIN_SS);
  
  LOGWARN(F("========================="));
  
#endif

  Serial.print(F("Using mac index = "));
  Serial.println(index);
}

void setup()
{
#if (defined(ETHERNET_WITH_SD_CARD) && ETHERNET_WITH_SD_CARD)
  pinMode(SDCARD_CS, OUTPUT);
  digitalWrite(SDCARD_CS, HIGH); // Deselect the SD card
#endif

  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  delay(500);

  Serial.println("\nStarting ESP32_Ethernet_AdvancedWebServer on " + String(BOARD_NAME));
  Serial.println("Ethernet using " + String(ETHERNET_TYPE));
  Serial.println(WEBSOCKETS2_GENERIC_VERSION);

  initEthernet();

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
