## WebSockets2_Generic

[![arduino-library-badge](https://www.ardu-badge.com/badge/WebSockets2_Generic.svg?)](https://www.ardu-badge.com/WebSockets2_Generic)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/WebSockets2_Generic.svg)](https://github.com/khoih-prog/WebSockets2_Generic/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/WebSockets2_Generic/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/WebSockets2_Generic.svg)](http://github.com/khoih-prog/WebSockets2_Generic/issues)

---

### Why do we need this [WebSockets2_Generic library](https://github.com/khoih-prog/WebSockets2_Generic)

Many Web services require WebSockets library, which is so far written only for ESP8266/ESP32 boards. The ESP boards so far rely on the [Markus Sattler's WebSockets Library](https://github.com/Links2004/arduinoWebSockets) to connect to Alexa via Sinric or SinricPro skills.

This [WebSockets2_Generic library](https://github.com/khoih-prog/WebSockets2_Generic) is based on and modified from [Gil Maimon's ArduinoWebSockets Library](https://github.com/gilmaimon/ArduinoWebsockets) to provide support to many more boards, such as ***Arduino SAMD21, Adafruit SAMD21/SAMD51, nRF52, STM32F, Teensy, SAM DUE, etc.*** and enable those boards to use WebSockets services, including voice-controlled Alexa along with Blynk. Those supported boards can also run ***WebSockets Server.*** The WebSockets can be used with ***ESP’s WiFi, WiFiNINA, W5x00/ENC28J60/LAN8742A Ethernet, ESP8266/ESP32-AT modules/shields.***

---

#### New in v1.0.3

1. Add support to STM32F boards with built-in Ethernet such as :
  - ***Nucleo-144 (F429ZI, F767ZI)***
  - ***Discovery (STM32F746G-DISCOVERY)***
  - ***All STM32F Boards with Built-in Ethernet LAN8742A***

2. Add support to ***STM32F1,2,3,4,7 boards (with 64+K Flash)*** using ***Ethernet W5x00, ENC28J60 or LAN8742A***
3. Add Packages' Patches to ***Adafruit nRF52, SAMD, Arduino SAMD*** to enable displaying ***BOARD_NAME***
4. Enhance examples and update README.md

#### New in v1.0.2

1. Add support to ***Ethernet ENC28J60, using UIPEthernet library***, for nRF52, SAMD21/SAMD51 and SAM DUE boards.

#### New in v1.0.1

1. Add support to ***SAM DUE*** boards.
2. Add support to ***Ethernet W5x00, using either Ethernet, EthernetLarge or Ethernet2 library.***
3. Restructure code to provide flexibility to support many more WiFi/Ethernet modules/shields in the future. Please delete the *.cpp files, replaced with coresponding *.hpp files, in the library src directory, if the *.cpp files still exist after installing new version.

#### New in v1.0.0

1. Add support to ***nRF52*** boards, such as ***AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc.***,  using WiFiNINA with [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic)
2. Add support to ***SAMD51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)*** , using WiFiNINA with [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic).
3. Add support to ***SAMD21 (ZERO, MKR, NANO_33_IOT, M0, M0 Pro, AdaFruit CIRCUITPLAYGROUND_EXPRESS, etc.)***, using WiFiNINA with [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic).
4. Add Alexa/[`SINRIC`](https://sinric.com) examples and supports to those boards as well as ESP8266/ESP32


#### Supported features of RFC6455 #####

 - text frame
 - binary frame
 - connection close
 - ping
 - pong
 - continuation frame

---
 
## Prerequisite
 1. [`Arduino IDE v1.8.12+` for Arduino](https://www.arduino.cc/en/Main/Software)
 2. [`ESP32 core v1.0.4+`](https://github.com/espressif/arduino-esp32/releases) for ESP32 boards. ***Ready*** from v1.0.0.
 3. [`ESP8266 core v2.7.2+` for Arduino](https://github.com/esp8266/Arduino#installing-with-boards-manager) for ESP8266 boards. ***Ready*** from v1.0.0.
 4. `Arduino AVR core v1.8.2+` for Arduino (Use Arduino Board Manager).
 5. [`Teensy core v1.53+`](https://www.pjrc.com/teensy/td_download.html) for Teensy (4.1, 4.0, 3.6, 3.5, 3,2, 3.1, 3.0) boards. ***Not ready*** in v1.0.3.
 6. [`Arduino SAM DUE core v1.6.12+`](https://www.arduino.cc/en/Guide/ArduinoDue) for SAM DUE ARM Cortex-M3 boards. ***Ready*** from v1.0.1.
 7. [`Arduino SAMD core v1.8.6+`](https://www.arduino.cc/en/Guide/ArduinoM0) for SAMD ARM Cortex-M0+ boards. ***Ready*** from v1.0.0.
 8. [`Adafruit SAMD core v1.5.14+`](https://www.adafruit.com/) for SAMD ARM Cortex-M0+ and M4 boards (Nano 33 IoT, etc.). ***Ready*** from v1.0.0.
 9. [`Adafruit nRF52 v0.20.5+`](https://www.adafruit.com/) for nRF52 boards such as AdaFruit Feather nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc. ***Ready*** from v1.0.0.
10. [`Arduino Core for STM32 v1.9.+`](https://github.com/khoih-prog/Arduino_Core_STM32) for STM32 boards. To install go to Arduino IDE, select Boards Manager, search for ***`STM32`***. ***Ready*** from v1.0.3.
11. [`WiFiNINA_Generic library v1.5.3+`](https://github.com/khoih-prog/WiFiNINA_Generic) if for WiFiNINA. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiNINA_Generic.svg?)](https://www.ardu-badge.com/WiFiNINA_Generic). ***Ready*** from v1.0.0.
12. Depending on which Ethernet module/shield you're using :
   - [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) for W5100, W5200 and W5500. ***Ready*** from v1.0.1.
   - [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2) for W5500 (Deprecated, use Arduino Ethernet library). ***Ready*** from v1.0.1.
   - [`Ethernet3 library`](https://github.com/sstaub/Ethernet3) for W5500/WIZ550io/WIZ850io/USR-ES1 with Wiznet W5500 chip. ***Not yet ready*** in v1.0.3.
   - [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge) for W5100, W5200 and W5500. ***Ready*** from v1.0.1.
   - [`UIPEthernet library v2.0.8+`](https://github.com/UIPEthernet/UIPEthernet) for ENC28J60. ***Ready*** from v1.0.2.
   - [`STM32Ethernet library v1.2.0+`](https://github.com/stm32duino/STM32Ethernet) for built-in Ethernet LAN8742A on (Nucleo-144, Discovery). To be used with [STM32duino_LwIP library v2.1.2+](https://github.com/stm32duino/LwIP). ***Ready*** from v1.0.3. 
13. [`ESP_AT_Lib library v1.0.0+`](https://github.com/khoih-prog/ESP_AT_Lib) if necessary to use ESP8288/ESP32-AT shields. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/ESP_AT_Lib.svg?)](https://www.ardu-badge.com/ESP_AT_Lib). ***Not ready*** in v1.0.3.

## Installation

### Use Arduino Library Manager
The best and easiest way is to use `Arduino Library Manager`. Search for `WebSockets2_Generic`, then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/WebSockets2_Generic.svg?)](https://www.ardu-badge.com/WebSockets2_Generic) for more detailed instructions.

### Manual Install

Another way to install is to:

1. Navigate to [WebSockets2_Generic](https://github.com/khoih-prog/WebSockets2_Generic) page.
2. Download the latest release `WebSockets2_Generic-master.zip`.
3. Extract the zip file to `WebSockets2_Generic-master` directory 
4. Copy whole `WebSockets2_Generic-master` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO:
1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install **WebSockets2_Generic** library by using [Library Manager](https://docs.platformio.org/en/latest/librarymanager/)
4. Use included [platformio.ini](examples/platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automaticly.

[![arduino-library-badge](https://www.ardu-badge.com/badge/WebSockets2_Generic.svg?)](https://www.ardu-badge.com/WebSockets2_Generic)

---

### Important notes

1. ***To be able to compile, run and automatically detect and display BOARD_NAME on nRF52840 boards***, you have to copy the whole [nRF52 0.20.5](https://github.com/khoih-prog/WebSockets2_Generic/tree/master/Packages_Patches/adafruit/hardware/nrf52/0.20.5) directory into Adafruit nRF52 directory (~/.arduino15/packages/adafruit/hardware/nrf52/0.20.5). 

Supposing the Adafruit nRF52 version is 0.20.5. These files must be copied into the directory:
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.20.5/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.20.5/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.20.5/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.20.5/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.20.5/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.20.5/variants/NINA_B112_ublox/variant.cpp`

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z
These files must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.cpp`

2. ***To be able to compile and run on Teensy boards***, you have to copy the file [Teensy boards.txt](https://github.com/khoih-prog/WebSockets2_Generic/blob/master/Packages_Patches/hardware/teensy/avr/boards.txt) into Teensy hardware directory (./arduino-1.8.12/hardware/teensy/avr/boards.txt). 

Supposing the Arduino version is 1.8.12. This file must be copied into the directory:

- `./arduino-1.8.12/hardware/teensy/avr/boards.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `./arduino-x.yy.zz/hardware/teensy/avr/boards.txt`

3. ***To be able to compile and run on SAM DUE boards***, you have to copy the whole [SAM DUE](https://github.com/khoih-prog/WebSockets2_Generic/tree/master/Packages_Patches/arduino/hardware/sam/1.6.12) directory into Arduino sam directory (~/.arduino15/packages/arduino/hardware/sam/1.6.12). 

Supposing the Arduino SAM core version is 1.6.12. This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/1.6.12/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/x.yy.zz/platform.txt`

4. ***To be able to automatically detect and display BOARD_NAME on Arduino SAMD (Nano-33-IoT, etc) boards***, you have to copy the file [Arduino SAMD platform.txt](https://github.com/khoih-prog/WebSockets2_Generic/tree/master/Packages_Patches/arduino/hardware/samd/1.8.6) into Arduino samd directory (~/.arduino15/packages/arduino/hardware/samd/1.8.6). 

Supposing the Arduino SAMD core version is 1.8.6. This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.6/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/x.yy.zz/platform.txt`

5. ***To be able to automatically detect and display BOARD_NAME on Adafruit SAMD (Itsy-Bitsy M4, etc) boards***, you have to copy the file [Adafruit SAMD platform.txt](https://github.com/khoih-prog/WebSockets2_Generic/tree/master/Packages_Patches/adafruit/hardware/samd/1.5.14) into Adafruit samd directory (~/.arduino15/packages/adafruit/hardware/samd/1.5.14). 

Supposing the Adafruit SAMD core version is 1.5.14. This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/1.5.14/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/platform.txt`

6. ***To be able to compile and run on nRF52 boards with ENC28J60 using UIPEthernet library***, you have to copy these following files into the UIPEthernet `utility` directory to overwrite the old files:

  - [Enc28J60Network.h](LibraryPatches/UIPEthernet/utility/Enc28J60Network.h)
  - [Enc28J60Network.cpp](LibraryPatches/UIPEthernet/utility/Enc28J60Network.cpp)

7. From v1.0.1, code is restructured to provide flexibility to make it easy to support many more WiFi/Ethernet modules/shields in the future. Please delete the *.cpp files, replaced by *.hpp files, in the src directory, if *.cpp files still exist after installing new version.

8. For ***Adafruit nRF52***, use the SPI's  pin as follows:

  - SS/CS     = 10
  - SPI_MOSI  = MO(SI)
  - SPI_MISO  = MI(SO)
  - SPI_SCK   = SCK

9. For ***Adafruit SAMD21/SAMD51***, use the SPI's CS/SS pin as follows:

  - Itsy-Bitsy M0/M4, Feather M0 (Express), Hallowing M0 Express, Zero, Metro M0 => use CS = 16 = pin A2
  - Feather M4 (SAMD51)   => use SS/CS = 9
  - Grand Central M4      => use SS/CS = 53
  - Hallowing M4          => use SS/CS = 10
  - Metro M4 AirLift      => use SS/CS = 36

To know the default CS/SS pins of not listed boards, check the related `variant.h` files in 

`~/.arduino15/packages/adafruit/hardware/samd/x.y.zz/variants/board_name/variant.h`

10. For ***Arduino SAM DUE***, use the SPI's  pin as follows:

  - SS/CS     = 10
  - SPI_MOSI  = 75 ( pin 4 @ [ICSP connector](pics/ICSP_connector.jpg) )
  - SPI_MISO  = 74 ( pin 1 @ [ICSP connector](pics/ICSP_connector.jpg) )
  - SPI_SCK   = 76 ( pin 3 @ [ICSP connector](pics/ICSP_connector.jpg) )
  
<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/blob/master/pics/ICSP_connector.jpg">
</p>
  
---

## Basic Usage

### Client

#### Creating a client and connecting to a server:

```c++
WebsocketsClient client;
client.connect("ws://your-server-ip:port/uri");
```

#### Sending a message:

```c++
client.send("Hello Server!");
```

#### Waiting for messages:

1. Using Lambda function

```c++
// run callback when messages are received
client.onMessage([&](WebsocketsMessage message) 
{
  Serial.print("Got Message: ");
  Serial.println(message.data());
});
```
2. Using normal calback function

```cpp
// run callback when events are occuring
  client.onMessage(onMessageCallback);
```

and

```cpp
void onMessageCallback(WebsocketsMessage message)
{
  //Doing something with received String message.data() type
  
  String received_message = message.data();
  .....
}
```


#### In order to keep receiving messages, you should:
```c++
void loop() 
{
  client.poll();
}
```

### Server

#### Creating a server and listening for connections:

```c++
WebsocketsServer server;
server.listen(8080);
```

#### Accepting connections:

```c++
WebsocketsClient client = server.accept();

// handle client as described before :)
// run callback when messages are received
client.onMessage([&](WebsocketsMessage message) 
{
  Serial.print("Got Message: ");
  Serial.println(message.data());
});
```
---

### To use WiFiNINA module/shield with WiFiNINA_Generic library

```cpp
#define WEBSOCKETS_USE_WIFININA           true
```
###  For SAMD21/SAMD51, nRF52, SAM DUE using Ethernet W5x0 or ENC28J60

### To use Ethernet W5x00 module/shield with Ethernetx library

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/blob/master/pics/W5500.jpg">
</p>

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/blob/master/pics/W5500_1.jpg">
</p>

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/blob/master/pics/W5100.jpg">
</p>

1. To use Ethernet `W5x00` module/shield with one of the Ethernet libraries

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_UIP_ETHERNET                  false
```

 - To use `W5x00` module/shield with `Ethernet` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET_LIB                  true
#define USE_ETHERNET2_LIB                 false
#define USE_ETHERNET_LARGE_LIB            false

#define USE_UIP_ETHERNET                  false
```

 - To use `W5x00` module/shield with `Ethernet2` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET_LIB                  false
#define USE_ETHERNET2_LIB                 true
#define USE_ETHERNET_LARGE_LIB            false

#define USE_UIP_ETHERNET                  false
```
 - To use` W5x00` module/shield with `EthernetLarge` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true
#define USE_ETHERNET_LIB                  false
#define USE_ETHERNET2_LIB                 false
#define USE_ETHERNET_LARGE_LIB            true
#define USE_UIP_ETHERNET                  false
```

2. To use Ethernet `ENC28J60` module/shield with `UIPEthernet` library

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/blob/master/pics/ENC28J60.jpg">
</p>

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_UIP_ETHERNET                  true
#define USE_ETHERNET_LIB                  false
#define USE_ETHERNET2_LIB                 false

#define USE_ETHERNET_LARGE_LIB            false
```

3. It's much easier just add to the sketch

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

// Just select one to be true. If all is false, default is Ethernet. 
// If more than one are true, the priority is USE_ETHERNET_LIB, USE_ETHERNET2_LIB, USE_ETHERNET_LARGE_LIB, USE_UIP_ETHERNET
#define USE_ETHERNET_LIB              false
#define USE_ETHERNET2_LIB             false
#define USE_ETHERNET_LARGE_LIB        false

#define USE_UIP_ETHERNET              true

#if USE_ETHERNET_LIB
  // Also default to Ethernet library
  #include <Ethernet.h>
  #define ETHERNET_TYPE               "W5x00 and Ethernet Library"
#elif USE_ETHERNET2_LIB
  #include <Ethernet2.h>
  #define ETHERNET_TYPE               "W5x00 and Ethernet2 Library"
#elif USE_ETHERNET_LARGE_LIB
  #include <EthernetLarge.h>
  #define ETHERNET_TYPE               "W5x00 and EthernetLarge Library"
#elif USE_UIP_ETHERNET
  #include <UIPEthernet.h>
  #include <utility/logging.h> 
  #define ETHERNET_TYPE               "ENC28J60 and UIPEthernet Library"
#else
  // Default to Ethernet library
  #include <Ethernet.h>
  #define ETHERNET_TYPE               "W5x00 and Ethernet Library"
#endif
```

###  For STM32F  using Ethernet W5x0, ENC28J60 or LAN8742A

### To use Ethernet W5x00 module/shield with Ethernetx library

1. To use Ethernet `W5x00` module/shield with one of the Ethernet libraries

```cpp
#define WEBSOCKETS_USE_ETHERNET           true
#define USE_UIP_ETHERNET                  false
#define USE_LAN8742A_ETHERNET             false
```

 - To use `W5x00` module/shield with `Ethernet` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET_LIB                  true
#define USE_ETHERNET2_LIB                 false
#define USE_ETHERNET_LARGE_LIB            false

#define USE_UIP_ETHERNET                  false
#define USE_LAN8742A_ETHERNET             false
```

 - To use `W5x00` module/shield with `Ethernet2` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET_LIB                  false
#define USE_ETHERNET2_LIB                 true
#define USE_ETHERNET_LARGE_LIB            false

#define USE_UIP_ETHERNET                  false
#define USE_LAN8742A_ETHERNET             false
```
 - To use` W5x00` module/shield with `EthernetLarge` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET_LIB                  false
#define USE_ETHERNET2_LIB                 false
#define USE_ETHERNET_LARGE_LIB            true

#define USE_UIP_ETHERNET                  false
#define USE_LAN8742A_ETHERNET             false
```

2. To use Ethernet `ENC28J60` module/shield with `UIPEthernet` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_UIP_ETHERNET                  true
#define USE_LAN8742A_ETHERNET             false

#define USE_ETHERNET_LIB                  false
#define USE_ETHERNET2_LIB                 false
#define USE_ETHERNET_LARGE_LIB            false
```

3. To use Ethernet `LAN8742A` built-in module/shield with `STM32Ethernet` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_UIP_ETHERNET                  false
#define USE_LAN8742A_ETHERNET             true

#define USE_ETHERNET_LIB                  false
#define USE_ETHERNET2_LIB                 false
#define USE_ETHERNET_LARGE_LIB            false
```

4. It's much easier just add to the sketch

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

// Just select one to be true. If all is false, default is Ethernet. 
// If more than one are true, the priority is USE_ETHERNET_LIB, USE_ETHERNET2_LIB, USE_ETHERNET_LARGE_LIB, USE_UIP_ETHERNET, USE_BUILTIN_ETHERNET

#define USE_ETHERNET_LIB              false
#define USE_ETHERNET2_LIB             false
#define USE_ETHERNET_LARGE_LIB        false

#define USE_UIP_ETHERNET              false
#define USE_LAN8742A_ETHERNET         true

#if USE_ETHERNET_LIB
  // Also default to Ethernet library
  #include <Ethernet.h>
  #define ETHERNET_TYPE               "W5x00 and Ethernet Library"
#elif USE_ETHERNET2_LIB
  #include <Ethernet2.h>
  #define ETHERNET_TYPE               "W5x00 and Ethernet2 Library"
#elif USE_ETHERNET_LARGE_LIB
  #include <EthernetLarge.h>
  #define ETHERNET_TYPE               "W5x00 and EthernetLarge Library"
#elif USE_UIP_ETHERNET
  #include <UIPEthernet.h>
  #include <utility/logging.h> 
  #define ETHERNET_TYPE               "ENC28J60 and UIPEthernet Library"
#elif USE_LAN8742A_ETHERNET
  #include <LwIP.h>
  #include <STM32Ethernet.h>
  #define ETHERNET_TYPE               "LAN8742A and STM32Ethernet Library"  
#else
  // Default to Ethernet library
  #include <Ethernet.h>
  #define ETHERNET_TYPE               "W5x00 and Ethernet Library"
#endif
```

### To use ESP8266/ESP32 native WiFi

Default is using `ESP8266/ESP32 native WiFi`. You don't need to do anything special.

---

### Examples

#### For ESP32 boards

1. [Esp32-Client](examples/ESP32/Esp32-Client)
2. [Minimal-Esp32-Client](examples/ESP32/Minimal-Esp32-Client)
3. [Secured-Esp32-Client](examples/ESP32/Secured-Esp32-Client)
4. [ESP32-Client_SINRIC](examples/ESP32/ESP32-Client_SINRIC)
5. [Esp32-Server](examples/ESP32/Esp32-Server)

#### For ESP8266 boards

1. [Esp8266-Client](examples/ESP8266/Esp8266-Client)
2. [Minimal-Esp8266-Client](examples/ESP8266/Minimal-Esp8266-Client)
3. [Secured-Esp8266-Client](examples/ESP8266/Secured-Esp8266-Client)
4. [SecuredTwoWay-Esp8266-Client](examples/ESP8266/SecuredTwoWay-Esp8266-Client)
5. [ESP8266-Client_SINRIC](examples/ESP8266/ESP8266-Client_SINRIC)
6. [Esp8266-Server](examples/ESP8266/Esp8266-Server)

#### For nRF52 boards using WiFiNINA

1. [nRF52-Client](examples/Generic/WiFiNINA/nRF52/nRF52-Client)
2. [nRF52-Minimal-Client](examples/Generic/WiFiNINA/nRF52/nRF52-Minimal-Client)
3. [nRF52-Client_SINRIC](examples/Generic/WiFiNINA/nRF52/nRF52-Client_SINRIC)
4. [nRF52-Server](examples/Generic/WiFiNINA/nRF52/nRF52-Server)

#### For SAMD21/SAMD51 boards using WiFiNINA

1. [SAMD-Client](examples/Generic/WiFiNINA/SAMD/SAMD-Client)
2. [SAMD-Minimal-Client](examples/Generic/WiFiNINA/SAMD/SAMD-Minimal-Client)
3. [SAMD-Client_SINRIC](examples/Generic/WiFiNINA/SAMD/SAMD-Client_SINRIC)
4. [SAMD-Server](examples/Generic/WiFiNINA/SAMD/SAMD-Server)

#### For nRF52 boards using Ethernet (W5x00 or ENC28J60)

1. [nRF52-Ethernet-Client](examples/Generic/Ethernet/nRF52/nRF52-Ethernet-Client)
2. [nRF52-Ethernet-Minimal-Client](examples/Generic/Ethernet/nRF52/nRF52-Ethernet-Minimal-Client)
3. [nRF52-Ethernet-Client_SINRIC](examples/Generic/Ethernet/nRF52/nRF52-Ethernet-Client_SINRIC)
4. [nRF52-Ethernet-Server](examples/Generic/Ethernet/nRF52/nRF52-Ethernet-Server)

#### For SAMD21/SAMD51 boards using Ethernet (W5x00 or ENC28J60)

1. [SAMD-Ethernet-Client](examples/Generic/Ethernet/SAMD/SAMD-Ethernet-Client)
2. [SAMD-Ethernet-Minimal-Client](examples/Generic/Ethernet/SAMD/SAMD-Ethernet-Minimal-Client)
3. [SAMD-Ethernet-Client_SINRIC](examples/Generic/Ethernet/SAMD/SAMD-Ethernet-Client_SINRIC)
4. [SAMD-Ethernet-Server](examples/Generic/Ethernet/SAMD/SAMD-Ethernet-Server)

#### For SAM-DUE boards using Ethernet (W5x00 or ENC28J60)

1. [SAMDUE-Ethernet-Client](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet-Client)
2. [SAMDUE-Ethernet-Minimal-Client](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet-Minimal-Client)
3. [SAMDUE-Ethernet-Client_SINRIC](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet-Client_SINRIC)
4. [SAMDUE-Ethernet-Server](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet-Server)

#### For STM32F boards using Ethernet (W5x00, ENC28J60 or LAN8742A)

1. [STM32-Ethernet-Client](examples/Generic/Ethernet/STM32/STM32-Ethernet-Client)
2. [STM32-Ethernet-Minimal-Client](examples/Generic/Ethernet/STM32/STM32-Ethernet-Minimal-Client)
3. [STM32-Ethernet-Client_SINRIC](examples/Generic/Ethernet/STM32/STM32-Ethernet-Client_SINRIC)
4. [STM32-Ethernet-Server](examples/Generic/Ethernet/STM32/STM32-Ethernet-Server)

---

### Example [SAMD-Client_SINRIC](examples/Generic/WiFiNINA/SAMD/SAMD-Client_SINRIC)

Please take a look at other examples, as well.

1. File [SAMD-Client_SINRIC.ino](examples/Generic/WiFiNINA/SAMD/SAMD-Client_SINRIC/SAMD-Client_SINRIC.ino)

```cpp
#include "defines.h"

#define DEBUG_LOCAL   2

#include <WebSockets2_Generic.h>
#include <ArduinoJson.h>          // https://arduinojson.org/ or install via Arduino library manager

using namespace websockets2_generic;

WebsocketsClient client;

#define HEARTBEAT_INTERVAL      300000 // 5 Minutes 

bool isConnected                = false;
uint64_t heartbeatTimestamp     = 0;
uint64_t now                    = 0;

//To increase no of devices as needed
void turnOn(String deviceId)
{
  if (deviceId == SINRIC_Device_ID_1) // Device ID of 1st device
  {
#if (DEBUG_LOCAL > 1)
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
#endif
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
#if (DEBUG_LOCAL > 1)
    Serial.print("Turn on for unknown device id: ");
    Serial.println(deviceId);
#endif
  }
}

//To increase no of devices as needed
void turnOff(String deviceId)
{

  if (deviceId == SINRIC_Device_ID_1) // Device ID of 1st device
  {
#if (DEBUG_LOCAL > 1)
    Serial.print("Turn off Device ID: ");
    Serial.println(deviceId);
#endif
    digitalWrite(LED_PIN, LOW);
  }
  else
  {
#if (DEBUG_LOCAL > 1)
    Serial.print("Turn off for unknown device id: ");
    Serial.println(deviceId);
#endif
  }
}

void onEventsCallback(WebsocketsEvent event, String data)
{
  if (event == WebsocketsEvent::ConnectionOpened)
  {
    if (!isConnected)
      isConnected = true;

    Serial.println("Connnection Opened");
  }
  else if (event == WebsocketsEvent::ConnectionClosed)
  {
    if (isConnected)
      isConnected = false;

    Serial.println("Connnection Closed");
  }
  else if (event == WebsocketsEvent::GotPing)
  {
    if (!isConnected)
      isConnected = true;

    Serial.println("Got a Ping!");
  }
  else if (event == WebsocketsEvent::GotPong)
  {
    if (!isConnected)
      isConnected = true;

    Serial.println("Got a Pong!");
  }
}

void onMessagesCallback(WebsocketsMessage message)
{
  String SINRIC_message = message.data();

  Serial.print("Got Message: ");
  Serial.println(SINRIC_message /*message.data()*/);

  // Example payloads

  // For Switch or Light device types
  // {"deviceId": xxxx, "action": "setPowerState", value: "ON"} // https://developer.amazon.com/docs/device-apis/alexa-powercontroller.html

  // For Light device type
  // Look at the light example in github

#if (ARDUINOJSON_VERSION_MAJOR >= 6)
  DynamicJsonDocument json(1024);
  //auto deserializeError = deserializeJson(json, (char*)message.data());
  auto deserializeError = deserializeJson(json, SINRIC_message);

  if ( deserializeError )
  {
    Serial.println("JSON parseObject() failed");
    return;
  }
  //serializeJson(json, Serial);
#else
  DynamicJsonBuffer jsonBuffer;
  // Parse JSON string
  JsonObject& json = jsonBuffer.parseObject(SINRIC_message);
  // Test if parsing succeeds.
  if (!json.success())
  {
    Serial.println("JSON parseObject() failed");
    return;
  }
#endif

  String deviceId = json ["deviceId"];
  String action = json ["action"];

  if (action == "setPowerState")
  {
    // Switch or Light
    String value = json ["value"];
    if (value == "ON")
    {
      turnOn(deviceId);
    }
    else
    {
      turnOff(deviceId);
    }
  }
}

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.begin(115200);
  while (!Serial);

  Serial.println("\nStarting WebSockets2_Generic SAMD-Client_SINRIC with WiFiNINA on " + String(BOARD_NAME));

  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE)
  {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    return;
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION)
  {
    Serial.println("Please upgrade the firmware");
  }

  Serial.print("Attempting to connect to SSID: ");
  Serial.println(ssid);

  // Connect to wifi
  WiFi.begin(ssid, password);

  // Wait some time to connect to wifi
  for (int i = 0; i < 10 && WiFi.status() != WL_CONNECTED; i++)
  {
    Serial.print(".");
    delay(1000);
  }

  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.print("Connected to Wifi, IP address: ");
    Serial.println(WiFi.localIP());
    Serial.print("Connecting to WebSockets Server @");
    Serial.println(websockets_server_host);
  }
  else
  {
    Serial.println("\nNo WiFi");
    return;
  }

  // run callback when events are occuring
  client.onMessage(onMessagesCallback);

  // try to connect to Websockets server
  client.addHeader("apikey", SINRIC_API_KEY);
  client.setAuthorization("apikey", SINRIC_API_KEY);

  bool connected = client.connect(websockets_server_host, websockets_server_port, "/");

  if (connected)
  {
    Serial.println("Connected!");
  }
  else
  {
    Serial.println("Not Connected!");
  }
}

void loop()
{
  // let the websockets client check for incoming messages
  if (client.available())
  {
    client.poll();

    now = millis();

    // Send heartbeat in order to avoid disconnections during ISP resetting IPs over night. Thanks @MacSass
    if ((now - heartbeatTimestamp) > HEARTBEAT_INTERVAL)
    {
      heartbeatTimestamp = now;
      client.send("H");
    }
  }
}
```

2. File [defines.h](examples/Generic/WiFiNINA/SAMD/SAMD-Client_SINRIC/defines.h)

```cpp
#ifndef defines_h
#define defines_h

#if    ( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
      || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) \
      || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) || defined(ARDUINO_SAMD_MKRVIDOR4000) || defined(__SAMD21G18A__) \
      || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) || defined(__SAMD21E18A__) || defined(__SAMD51__) || defined(__SAMD51J20A__) || defined(__SAMD51J19A__) \
      || defined(__SAMD51G19A__) || defined(__SAMD21G18A__) )
#if defined(WEBSOCKETS_WIFININA_USE_SAMD)
#undef WEBSOCKETS_WIFININA_USE_SAMD
#endif
#define WEBSOCKETS_USE_WIFININA             true
#define WEBSOCKETS_WIFININA_USE_SAMD        true
#else
#error This code is intended to run only on the SAMD boards ! Please check your Tools->Board setting.
#endif

#if defined(WEBSOCKETS_WIFININA_USE_SAMD)

#if defined(ARDUINO_SAMD_ZERO)
#define BOARD_TYPE      "SAMD Zero"
#elif defined(ARDUINO_SAMD_MKR1000)
#define BOARD_TYPE      "SAMD MKR1000"
#elif defined(ARDUINO_SAMD_MKRWIFI1010)
#define BOARD_TYPE      "SAMD MKRWIFI1010"
#elif defined(ARDUINO_SAMD_NANO_33_IOT)
#define BOARD_TYPE      "SAMD NANO_33_IOT"
#elif defined(ARDUINO_SAMD_MKRFox1200)
#define BOARD_TYPE      "SAMD MKRFox1200"
#elif ( defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) )
#define BOARD_TYPE      "SAMD MKRWAN13X0"
#elif defined(ARDUINO_SAMD_MKRGSM1400)
#define BOARD_TYPE      "SAMD MKRGSM1400"
#elif defined(ARDUINO_SAMD_MKRNB1500)
#define BOARD_TYPE      "SAMD MKRNB1500"
#elif defined(ARDUINO_SAMD_MKRVIDOR4000)
#define BOARD_TYPE      "SAMD MKRVIDOR4000"
#elif defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS)
#define BOARD_TYPE      "SAMD ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS"
#elif defined(ADAFRUIT_ITSYBITSY_M4_EXPRESS)
#define BOARD_TYPE      "SAMD ADAFRUIT_ITSYBITSY_M4_EXPRESS"
#elif defined(__SAMD21E18A__)
#define BOARD_TYPE      "SAMD21E18A"
#elif defined(__SAMD21G18A__)
#define BOARD_TYPE      "SAMD21G18A"
#elif defined(__SAMD51G19A__)
#define BOARD_TYPE      "SAMD51G19A"
#elif defined(__SAMD51J19A__)
#define BOARD_TYPE      "SAMD51J19A"
#elif defined(__SAMD51J20A__)
#define BOARD_TYPE      "SAMD51J20A"
#elif defined(__SAM3X8E__)
#define BOARD_TYPE      "SAM3X8E"
#elif defined(__CPU_ARC__)
#define BOARD_TYPE      "CPU_ARC"
#elif defined(__SAMD51__)
#define BOARD_TYPE      "SAMD51"
#else
#define BOARD_TYPE      "SAMD Unknown"
#endif

#endif

#ifndef BOARD_NAME
  #define BOARD_NAME    BOARD_TYPE
#endif

#include <WiFiNINA_Generic.h>

#define DEBUG_WEBSOCKETS_PORT     Serial
// Debug Level from 0 to 4
#define _WEBSOCKETS_LOGLEVEL_     3

const char* ssid = "ssid"; //Enter SSID
const char* password = "password"; //Enter Password

#define SINRIC_WEBSERVER          "iot.sinric.com"
#define SINRIC_WEBSERVER_PORT     80
#define SINRIC_API_KEY            "11111111-2222-3333-4444-555555555555"

#define SINRIC_Device_ID_1        "012345678901234567890123"   // Device ID, got from Sinric

const char* websockets_server_host    = SINRIC_WEBSERVER; //Enter server address
const uint16_t websockets_server_port = SINRIC_WEBSERVER_PORT; // Enter server port

#ifdef LED_BUILTIN
#define LED_PIN     LED_BUILTIN
#else
#define LED_PIN     13
#endif            

#endif      //defines_h
```

---

This is the terminal output when running [SAMD-Client_SINRIC](examples/Generic/WiFiNINA/SAMD/SAMD-Client_SINRIC) example on ***Nano-33 IoT***:

```
Starting WebSockets2_Generic SAMD-Client_SINRIC with WiFiNINA on SAMD NANO_33_IOT
WiFi-begin: return1 = 3
WiFi-begin: return2 = 3
Connected to Wifi, Connecting to WebSockets Server @iot.sinric.com
[WS] WebsocketsClient::generateHandshake: base64Authorization = ***************
[WS] WebsocketsClient::generateHandshake: handshake = GET / HTTP/1.1
Host: iot.sinric.com
Sec-WebSocket-Key: *********
apikey: 11111111-2222-3333-4444-555555555555
Upgrade: websocket
Connection: Upgrade
Sec-WebSocket-Version: 13
User-Agent: TinyWebsockets Client
Authorization: Basic ***************
Origin: https://github.com/khoih-prog/Websockets2_Generic

[WS] WebsocketsClient::generateHandshake: key = Server
[WS] WebsocketsClient::generateHandshake: value = nginx/1.10.3 (Ubuntu)
[WS] WebsocketsClient::generateHandshake: key = Date
[WS] WebsocketsClient::generateHandshake: value = Tue, 14 Jul 2020 02:27:30 GMT
[WS] WebsocketsClient::generateHandshake: key = Connection
[WS] WebsocketsClient::generateHandshake: value = upgrade
[WS] WebsocketsClient::generateHandshake: key = Upgrade
[WS] WebsocketsClient::generateHandshake: value = websocket
[WS] WebsocketsClient::generateHandshake: key = Sec-WebSocket-Accept
[WS] WebsocketsClient::generateHandshake: value = *********
Connected!
Got Message: {"deviceId":"012345678901234567890123","action":"setPowerState","value":"ON"}
Turn on device id: 012345678901234567890123
Got Message: {"deviceId":"012345678901234567890123","action":"setPowerState","value":"OFF"}
Turn off Device ID: 012345678901234567890123
```
---

### Binary Data

For binary data it is recommended to use `msg.rawData()` which returns a `std::string`, or `msg.c_str()` which returns a `const char*`. 
The reason is that `msg.data()` returns an Arduino `String`, which is great for Serial printing and very basic memory handling but bad for most binary usages.

See [issue #32](https://github.com/gilmaimon/ArduinoWebsockets/issues/32) for further information.

### SSL and WSS Support

No matter what board you are using, in order to use WSS (websockets over SSL) you need to use

```c++
client.connect("wss://your-secured-server-ip:port/uri");
```

The next sections describe board-specific code for using WSS with the library.

### ESP8266

With the ESP8266 there are 2 ways for using WSS. By default, `WebSockets2_Generic` does not validate the certificate chain. This can be set explicitly using:

```c++
client.setInsecure();
```

You can also use an `SSL Fingerprint` to validate the SSL connection, for example:

```c++
// To update SHA1 fingerprint, use Google Chrome to connect to https://www.websocket.org/echo.html 
// Then "View Site Information" => "Certificate Viewer" => Copy SHA1 fingerprint
// This latest SHA1 fingerprint was updated 13.07.2020
const char ssl_fingerprint[] PROGMEM = "F0 DC 2E 40 A6 6D 29 B5 73 8F E1 E8 A9 EA 2A 9B 50 68 80 E3";

client.setFingerprint(ssl_fingerprint);
```

### ESP32

With the ESP32 you could either provide the full certificate, or provide no certificate. An example for setting CA Certificate:

```c++
const char ssl_ca_cert[] PROGMEM = \
    "-----BEGIN CERTIFICATE-----\n" \
    "MIIEkjCCA3qgAwIBAgIQCgFBQgAAAVOFc2oLheynCDANBgkqhkiG9w0BAQsFADA/\n" \
    "MSQwIgYDVQQKExtEaWdpdGFsIFNpZ25hdHVyZSBUcnVzdCBDby4xFzAVBgNVBAMT\n" \
    "DkRTVCBSb290IENBIFgzMB4XDTE2MDMxNzE2NDA0NloXDTIxMDMxNzE2NDA0Nlow\n" \
    "SjELMAkGA1UEBhMCVVMxFjAUBgNVBAoTDUxldCdzIEVuY3J5cHQxIzAhBgNVBAMT\n" \
    "GkxldCdzIEVuY3J5cHQgQXV0aG9yaXR5IFgzMIIBIjANBgkqhkiG9w0BAQEFAAOC\n" \
    "AQ8AMIIBCgKCAQEAnNMM8FrlLke3cl03g7NoYzDq1zUmGSXhvb418XCSL7e4S0EF\n" \
    "q6meNQhY7LEqxGiHC6PjdeTm86dicbp5gWAf15Gan/PQeGdxyGkOlZHP/uaZ6WA8\n" \
    "SMx+yk13EiSdRxta67nsHjcAHJyse6cF6s5K671B5TaYucv9bTyWaN8jKkKQDIZ0\n" \
    "Z8h/pZq4UmEUEz9l6YKHy9v6Dlb2honzhT+Xhq+w3Brvaw2VFn3EK6BlspkENnWA\n" \
    "a6xK8xuQSXgvopZPKiAlKQTGdMDQMc2PMTiVFrqoM7hD8bEfwzB/onkxEz0tNvjj\n" \
    "/PIzark5McWvxI0NHWQWM6r6hCm21AvA2H3DkwIDAQABo4IBfTCCAXkwEgYDVR0T\n" \
    "AQH/BAgwBgEB/wIBADAOBgNVHQ8BAf8EBAMCAYYwfwYIKwYBBQUHAQEEczBxMDIG\n" \
    "CCsGAQUFBzABhiZodHRwOi8vaXNyZy50cnVzdGlkLm9jc3AuaWRlbnRydXN0LmNv\n" \
    "bTA7BggrBgEFBQcwAoYvaHR0cDovL2FwcHMuaWRlbnRydXN0LmNvbS9yb290cy9k\n" \
    "c3Ryb290Y2F4My5wN2MwHwYDVR0jBBgwFoAUxKexpHsscfrb4UuQdf/EFWCFiRAw\n" \
    "VAYDVR0gBE0wSzAIBgZngQwBAgEwPwYLKwYBBAGC3xMBAQEwMDAuBggrBgEFBQcC\n" \
    "ARYiaHR0cDovL2Nwcy5yb290LXgxLmxldHNlbmNyeXB0Lm9yZzA8BgNVHR8ENTAz\n" \
    "MDGgL6AthitodHRwOi8vY3JsLmlkZW50cnVzdC5jb20vRFNUUk9PVENBWDNDUkwu\n" \
    "Y3JsMB0GA1UdDgQWBBSoSmpjBH3duubRObemRWXv86jsoTANBgkqhkiG9w0BAQsF\n" \
    "AAOCAQEA3TPXEfNjWDjdGBX7CVW+dla5cEilaUcne8IkCJLxWh9KEik3JHRRHGJo\n" \
    "uM2VcGfl96S8TihRzZvoroed6ti6WqEBmtzw3Wodatg+VyOeph4EYpr/1wXKtx8/\n" \
    "wApIvJSwtmVi4MFU5aMqrSDE6ea73Mj2tcMyo5jMd6jmeWUHK8so/joWUoHOUgwu\n" \
    "X4Po1QYz+3dszkDqMp4fklxBwXRsW10KXzPMTZ+sOPAveyxindmjkW8lGy+QsRlG\n" \
    "PfZ+G6Z6h7mjem0Y+iWlkYcV4PIWL1iwBi8saCbGS5jN2p8M+X+Q7UNKEkROb3N6\n" \
    "KOqkqm57TH2H3eDJAkSnh6/DNFu0Qg==\n" \
    "-----END CERTIFICATE-----\n";

client.setCACert(ssl_ca_cert);
```
---

### Debug Termimal Output Samples

1. This is terminal debug output when running [SAMD-Ethernet-Client_SINRIC](examples/Generic/Ethernet/SAMD/SAMD-Ethernet-Client_SINRIC) on SAMD51 ***Adafruit Itsy-Bitsy M4 Express using ENC28J60 Ethernet module.***

```
Starting WebSockets2_Generic SAMD-Ethernet-Client_SINRIC on SAMD ADAFRUIT_ITSYBITSY_M4_EXPRESS
Ethernet using ENC28J60 and UIPEthernet Library
[SETUP] BOOT WAIT 4
[SETUP] BOOT WAIT 3
[SETUP] BOOT WAIT 2
[SETUP] BOOT WAIT 1
ENC28J60_CONTROL_CS =16
SS =16
SPI_MOSI =25
SPI_MISO =23
SPI_SCK =24
WebSockets Client IP address: 192.168.2.137
Connecting to WebSockets Server @iot.sinric.com
[WS] WebsocketsClient::generateHandshake: base64Authorization = ********
[WS] WebsocketsClient::generateHandshake: handshake = GET / HTTP/1.1
Host: iot.sinric.com
Sec-WebSocket-Key: ********
apikey: 11111111-2222-3333-4444-555555555555
Upgrade: websocket
Connection: Upgrade
Sec-WebSocket-Version: 13
User-Agent: TinyWebsockets Client
Authorization: Basic ********
Origin: https://github.com/khoih-prog/Websockets2_Generic

[WS] WebsocketsClient::connect: base64Authorization = ********
[WS] WebsocketsClient::doestStartsWith: str = HTTP/1.1 101 Switching Protocols
[WS] WebsocketsClient::doestStartsWith: prefix = HTTP/1.1 101
[WS] WebsocketsClient::generateHandshake: key = Server
[WS] WebsocketsClient::generateHandshake: value = nginx/1.10.3 (Ubuntu)
[WS] WebsocketsClient::generateHandshake: key = Date
[WS] WebsocketsClient::generateHandshake: value = Fri, 17 Jul 2020 00:04:17 GMT
[WS] WebsocketsClient::generateHandshake: key = Connection
[WS] WebsocketsClient::generateHandshake: value = upgrade
[WS] WebsocketsClient::generateHandshake: key = Upgrade
[WS] WebsocketsClient::generateHandshake: value = websocket
[WS] WebsocketsClient::generateHandshake: key = Sec-WebSocket-Accept
[WS] WebsocketsClient::generateHandshake: value = ********
Connected!
Got Message: {"deviceId":"012345678901234567890123","action":"setPowerState","value":"ON"}
Turn on device id: 012345678901234567890123
Got Message: {"deviceId":"012345678901234567890123","action":"setPowerState","value":"OFF"}
Turn off Device ID: 012345678901234567890123
```

2. This is terminal debug output when running [SAMDUE-Ethernet-Server](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet-Server) on ***SAM DUE board with Ethernet W5100 shield using EthernetLarge library***, and receiving WebSockets connection from an ESP8266 board.

```
Starting WebSockets2_Generic SAMDUE-Ethernet-Server on SAM DUE
Ethernet using W5x00 and EthernetLarge Library
[SETUP] BOOT WAIT 4
[SETUP] BOOT WAIT 3
[SETUP] BOOT WAIT 2
[SETUP] BOOT WAIT 1

W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 10
W5100::init: W5100, SSIZE =4096
WebSockets Server Running and Ready on SAM DUE
IP address: 192.168.2.153, Port: 8080
H[WS] WebsocketsServer::recvHandshakeRequest: value = 192.168.2.153
[WS] WebsocketsServer::recvHandshakeRequest: value = ********
[WS] WebsocketsServer::recvHandshakeRequest: value = websocket
[WS] WebsocketsServer::recvHandshakeRequest: value = Upgrade
[WS] WebsocketsServer::recvHandshakeRequest: value = 13
[WS] WebsocketsServer::recvHandshakeRequest: value = TinyWebsockets Client
[WS] WebsocketsServer::recvHandshakeRequest: value = Basic 
[WS] WebsocketsServer::recvHandshakeRequest: value = https://github.com/khoih-prog/Websockets2_Generic
Got Message: Hello to Server from ESP8266
[WS] WebsocketsServer::recvHandshakeRequest: value = 192.168.2.153
[WS] WebsocketsServer::recvHandshakeRequest: value = ********
[WS] WebsocketsServer::recvHandshakeRequest: value = websocket
[WS] WebsocketsServer::recvHandshakeRequest: value = Upgrade
[WS] WebsocketsServer::recvHandshakeRequest: value = 13
[WS] WebsocketsServer::recvHandshakeRequest: value = TinyWebsockets Client
[WS] WebsocketsServer::recvHandshakeRequest: value = Basic 
[WS] WebsocketsServer::recvHandshakeRequest: value = https://github.com/khoih-prog/Websockets2_Generic
Got Message: Hello to Server from ESP8266
HHHHHHHHH
```

3. This is terminal debug output when running [nRF52-Ethernet-Server](examples/Generic/Ethernet/nRF52/nRF52-Ethernet-Server) on ***Adafruit nRF52840 Itsy-Bitsy Express board with Ethernet ENC28J60 shield using UIPEthernet library***, and receiving WebSockets connection from an ESP8266 board.

```
Starting WebSockets2_Generic nRF52-Ethernet-Server on NRF52840_ITSYBITSY_EXPRESS
Ethernet using ENC28J60 and UIPEthernet Library
[SETUP] BOOT WAIT 4
[SETUP] BOOT WAIT 3
[SETUP] BOOT WAIT 2
[SETUP] BOOT WAIT 1
ENC28J60_CONTROL_CS =10
SS =5
SPI_MOSI =24
SPI_MISO =23
SPI_SCK =25
WebSockets Server Running and Ready on NRF52840_ITSYBITSY_EXPRESS
IP address: 192.168.2.95, Port: 8080
H[WS] WebsocketsServer::recvHandshakeRequest: value = 192.168.2.95
[WS] WebsocketsServer::recvHandshakeRequest: value = ********
[WS] WebsocketsServer::recvHandshakeRequest: value = websocket
[WS] WebsocketsServer::recvHandshakeRequest: value = Upgrade
[WS] WebsocketsServer::recvHandshakeRequest: value = 13
[WS] WebsocketsServer::recvHandshakeRequest: value = TinyWebsockets Client
[WS] WebsocketsServer::recvHandshakeRequest: value = Basic 
[WS] WebsocketsServer::recvHandshakeRequest: value = https://github.com/khoih-prog/Websockets2_Generic
Got Message: Hello to Server from ESP8266
[WS] WebsocketsServer::recvHandshakeRequest: value = 192.168.2.95
[WS] WebsocketsServer::recvHandshakeRequest: value = ********
[WS] WebsocketsServer::recvHandshakeRequest: value = websocket
[WS] WebsocketsServer::recvHandshakeRequest: value = Upgrade
[WS] WebsocketsServer::recvHandshakeRequest: value = 13
[WS] WebsocketsServer::recvHandshakeRequest: value = TinyWebsockets Client
[WS] WebsocketsServer::recvHandshakeRequest: value = Basic 
[WS] WebsocketsServer::recvHandshakeRequest: value = https://github.com/khoih-prog/Websockets2_Generic
Got Message: Hello to Server from ESP8266
HHHHHHHHH
```

4. This is terminal debug output when running [STM32-Ethernet-Client_SINRIC](examples/Generic/Ethernet/STM32/STM32-Ethernet-Client_SINRIC) on ***Nucleo-144 NUCLEO_F767ZI board with built-in Ethernet LAN8742A using STMEthernet library***.

```
Starting WebSockets2_Generic STM32-Ethernet-Client_SINRIC on NUCLEO_F767ZI
Ethernet using LAN8742A and STM32Ethernet Library
[SETUP] BOOT WAIT 4
[SETUP] BOOT WAIT 3
[SETUP] BOOT WAIT 2
[SETUP] BOOT WAIT 1
WebSockets Client IP address: 192.168.2.135
Connecting to WebSockets Server @iot.sinric.com
[WS] WebsocketsClient::generateHandshake: base64Authorization = ********
[WS] WebsocketsClient::generateHandshake: handshake = GET / HTTP/1.1
Host: iot.sinric.com
Sec-WebSocket-Key: ********
apikey: 11111111-2222-3333-4444-555555555555
Upgrade: websocket
Connection: Upgrade
Sec-WebSocket-Version: 13
User-Agent: TinyWebsockets Client
Authorization: Basic ********
Origin: https://github.com/khoih-prog/Websockets2_Generic

[WS] WebsocketsClient::connect: base64Authorization = ********
[WS] WebsocketsClient::doestStartsWith: str = HTTP/1.1 101 Switching Protocols
[WS] WebsocketsClient::doestStartsWith: prefix = HTTP/1.1 101
[WS] WebsocketsClient::generateHandshake: key = Server
[WS] WebsocketsClient::generateHandshake: value = nginx/1.10.3 (Ubuntu)
[WS] WebsocketsClient::generateHandshake: key = Date
[WS] WebsocketsClient::generateHandshake: value = Sat, 18 Jul 2020 06:42:54 GMT
[WS] WebsocketsClient::generateHandshake: key = Connection
[WS] WebsocketsClient::generateHandshake: value = upgrade
[WS] WebsocketsClient::generateHandshake: key = Upgrade
[WS] WebsocketsClient::generateHandshake: value = websocket
[WS] WebsocketsClient::generateHandshake: key = Sec-WebSocket-Accept
[WS] WebsocketsClient::generateHandshake: value = ********
Connected!
Got Message: {"deviceId":"012345678901234567890123","action":"setPowerState","value":"ON"}
Turn on device id: 012345678901234567890123
Got Message: {"deviceId":"012345678901234567890123","action":"setPowerState","value":"OFF"}
Turn off Device ID: 012345678901234567890123
```

---

### Debug

Debug is enabled by default on Serial. Debug Level from 0 to 4. To disable, change the _WEBSOCKETS_LOGLEVEL_ to 0

```cpp
// Use this to output debug msgs to Serial
#define DEBUG_WEBSOCKETS_PORT     Serial
// Use this to disable all output debug msgs
//#define DEBUG_WEBSOCKETS_PORT
// Debug Level from 0 to 4
#define _WEBSOCKETS_LOGLEVEL_     3
```

---

### TO DO

 1. Support more boards (Teensy, etc.)
 2. Support ESP8266/ESP32-AT shields.
 3. Add SSL support to SAMD and nRF52 using WiFiNINA.

### DONE

 1. Add support to SAMD21, SAMD51.
 2. Add support to nRF52.
 3. Add support to WiFiNINA using [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic).
 4. Add support to [`SINRIC`](https://sinric.com)
 5. Split each example into several manageable files.
 6. Add support to SAM DUE.
 7. Add support to Ethernet W5x00, using either [Ethernet](https://www.arduino.cc/en/Reference/Ethernet), [Ethernet2](https://github.com/khoih-prog/Ethernet2) or [EthernetLarge](https://github.com/OPEnSLab-OSU/EthernetLarge) library
 8. Add support to Ethernet ENC28J60, using [UIPEthernet](https://github.com/UIPEthernet/UIPEthernet) library
 9. Add support to STM32F.
 8. Add support to Ethernet LAN8742A, using [`STM32Ethernet library`](https://github.com/stm32duino/STM32Ethernet)
 
---

#### New in v1.0.3

1. Add support to STM32F boards with built-in Ethernet such as :
  - ***Nucleo-144 (F429ZI, F767ZI)***
  - ***Discovery (STM32F746G-DISCOVERY)***
  - ***All STM32 Boards with Built-in Ethernet LAN8742A***

2. Add support to ***STM32F1,2,3,4,7 boards (with 64+K Flash)*** using either ***Ethernet W5x00, ENC28J60 or LAN8742A***
3. Add Packages' Patches to Adafruit nRF52, SAMD, Arduino SAMD to enable displaying BOARD_NAME
4. Enhance examples and update README.md

#### New in v1.0.2

1. Add support to ***Ethernet ENC28J60, using UIPEthernet library.*** for nRF52, SAMD21/SAMD51 and SAM DUE boards.

#### New in v1.0.1

1. Add support to ***SAM DUE*** boards.
2. Add support to ***Ethernet W5x00, using either Ethernet, EthernetLarge or Ethernet2 library.***
3. Restructure code to provide flexibility to support many more WiFi/Ethernet modules/shields in the future. Please delete the *.cpp files, replaced by *.hpp files, in the src directory, if *.cpp files still exist after installing new version.

#### New in v1.0.0

1. Add support to ***nRF52*** boards, such as ***AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc.***.
2. Add support to ***SAMD51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)***.
3. Add support to ***SAMD21 (ZERO, MKR, NANO_33_IOT, M0, M0 Pro, AdaFruit CIRCUITPLAYGROUND_EXPRESS, etc.)***.
4. Add Alexa / [`SINRIC`](https://sinric.com) examples and supports to those boards as well as ESP8266/ESP32
5. Add support to WiFiNINA using [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic).

---

### Issues ###

Submit issues to: [WebSockets2_Generic issues](https://github.com/khoih-prog/WebSockets2_Generic/issues)

### Contributions and thanks

1. Based on and modified from [Gil Maimon's ArduinoWebsockets](https://github.com/gilmaimon/ArduinoWebsockets)
2. Thanks to good work of [Miguel Alexandre Wisintainer](https://github.com/tcpipchip) for initiating, inspriring, working with, developing, debugging and testing. Without that, support to nRF52, especially ***U-Blox B302 running as nRF52840 and U-Blox B112 running as nRF52832***, has never been started and finished. See [u-blox nina b](https://github.com/khoih-prog/WiFiNINA_Generic/issues/1)

## Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library


### License and credits ###

- Most of the credits go to original author [Gil Maimon](https://github.com/gilmaimon) as well as contributors in original library [ArduinoWebsockets Contributors](https://github.com/gilmaimon/ArduinoWebsockets#contributors)

- The library is licensed under [GPLv3.0](https://github.com/gilmaimon/ArduinoWebsockets/blob/master/LICENSE) and [MIT](https://github.com/khoih-prog/WebSockets2_Generic/blob/master/LICENSE)

- `base64` written by René Nyffenegger.

### Copyright

1. Copyright (c) 2019- Gil Maimon
2. Copyright (c) 2020- Khoi Hoang


