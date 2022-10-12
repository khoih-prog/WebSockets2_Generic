/****************************************************************************************************************************
  RP2040W-AdvancedWebServer.ino
  For RP2040W with CYW43439 WiFi.
  
  Based on and modified from Gil Maimon's ArduinoWebsockets library https://github.com/gilmaimon/ArduinoWebsockets
  to support STM32F/L/H/G/WB/MP1, nRF52, SAMD21/SAMD51, RP2040 boards besides ESP8266 and ESP32


  The library provides simple and easy interface for websockets (Client and Server).
  
  Built by Khoi Hoang https://github.com/khoih-prog/Websockets2_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/

#include "defines.h"

const uint16_t websockets_server_port = 8080; // Enter server port

// Select the IP address according to your local network
IPAddress serverIP(192, 168, 2, 95);

int status = WL_IDLE_STATUS;

#include <WebSockets2_Generic.h>

#include <WiFiWebServer.h>

using namespace websockets2_generic;

WebsocketsServer SocketsServer;

#define WEBSOCKETS_PORT     8080

WiFiWebServer server(80);

#define BUFFER_SIZE         640
char temp[BUFFER_SIZE];

void handleRoot()
{
  int sec = millis() / 1000;
  int min = sec / 60;
  int hr = min / 60;
  int day = hr / 24;

  snprintf(temp, BUFFER_SIZE - 1,
           "<html>\
<head>\
<meta http-equiv='refresh' content='10'/>\
<title>RP2040W-AdvancedWebServer %s</title>\
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

#define ORIGINAL_STR_LEN        4000
#define TEMP_STR_LEN            80

String out;
  
void drawGraph()
{  
  char temp[TEMP_STR_LEN];
  static uint16_t previousStrLen = ORIGINAL_STR_LEN;
    
  if (out.length() == 0)
  {
    LOGWARN1(F("String Len = 0, extend to"), ORIGINAL_STR_LEN);
    out.reserve(ORIGINAL_STR_LEN);
  }

  out = F( "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"310\" height=\"150\">\n" \
           "<rect width=\"310\" height=\"150\" fill=\"rgb(250, 230, 210)\" stroke-width=\"3\" stroke=\"rgb(0, 0, 0)\" />\n" \
           "<g stroke=\"blue\">\n");
 
  int y = rand() % 130;

  for (int x = 15; x < 300; x += 15)
  {
    int y2 = rand() % 130;

    memset(temp, TEMP_STR_LEN, 0);
    
    //sprintf(temp, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke-width=\"2\" />\n", x, 140 - y, x + 10, 140 - y2);
    snprintf(temp, TEMP_STR_LEN - 1, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke-width=\"2\" />\n", x, 140 - y, x + 15, 140 - y2);

    if (out.length() > previousStrLen - TEMP_STR_LEN)
    {  
      LOGERROR3(F("String Len > "), previousStrLen, F(", extend to"), previousStrLen + TEMP_STR_LEN * 2);
      
      // Add twice to be safe
      previousStrLen += TEMP_STR_LEN * 2;     
      
      out.reserve(previousStrLen);
    }
    
    out += temp;
    y = y2;
  }
  
  out += F("</g>\n</svg>\n");

  server.send(200, "image/svg+xml", out);
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

  Serial.print("\nStarting RP2040W-AdvancedWebServer on "); Serial.println(BOARD_NAME);
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

  server.on("/", handleRoot);
  server.on("/test.svg", drawGraph);
  server.on("/inline", []()
  {
    server.send(200, "text/plain", "This works as well");
  });

  server.onNotFound(handleNotFound);
  server.begin();

  ///////////////////////////////////

  SocketsServer.listen(WEBSOCKETS_PORT);

  Serial.print(SocketsServer.available() ? "WebSockets Server Running and Ready on " : "Server Not Running on ");
  Serial.println(BOARD_NAME);
  Serial.print("IP address: ");
  Serial.print(WiFi.localIP());
  Serial.print(", Port: ");
  Serial.println(WEBSOCKETS_PORT);    // Websockets Server Port
}

void checkClient()
{
  static unsigned long checkClient_timeout = 2000;

#define CLIENT_CHECK_INTERVAL     1000L

  // Send status report every STATUS_REPORT_INTERVAL (60) seconds: we don't need to send updates frequently if there is no status change.
  if ((millis() > checkClient_timeout))
  {
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
    
    checkClient_timeout = millis() + CLIENT_CHECK_INTERVAL;
  }
}

void loop()
{
  server.handleClient();

  checkClient();
}
