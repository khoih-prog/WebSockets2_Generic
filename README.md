## WebSockets2_Generic

[![arduino-library-badge](https://www.ardu-badge.com/badge/WebSockets2_Generic.svg?)](https://www.ardu-badge.com/WebSockets2_Generic)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/WebSockets2_Generic.svg)](https://github.com/khoih-prog/WebSockets2_Generic/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/WebSockets2_Generic/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/WebSockets2_Generic.svg)](http://github.com/khoih-prog/WebSockets2_Generic/issues)

---
---

### Why do we need this [WebSockets2_Generic library](https://github.com/khoih-prog/WebSockets2_Generic)

Many Web services require WebSockets library, which is so far written only for ESP8266/ESP32 boards. The ESP boards so far rely on the [**Markus Sattler's WebSockets Library**](https://github.com/Links2004/arduinoWebSockets) to connect to Alexa via Sinric or SinricPro skills.

This [**WebSockets2_Generic library**](https://github.com/khoih-prog/WebSockets2_Generic) is based on and modified from [**Gil Maimon's ArduinoWebSockets Library**](https://github.com/gilmaimon/ArduinoWebsockets) to provide support to many more boards, such as **Arduino SAMD21, Adafruit SAMD21/SAMD51, Seeeduino SAMD21/SAMD51, nRF52, STM32F/L/H/G/WB/MP1, Teensy, SAM DUE, etc.** and enable those boards to use WebSockets services, including voice-controlled Alexa along with Blynk. Those supported boards can also run **WebSockets Server.** The WebSockets can be used with **ESP’s WiFi, WiFiNINA, W5x00/ENC28J60/LAN8742A Ethernet, ESP8266/ESP32-AT modules/shields.**

#### Supported features of RFC6455 #####

 - text frame
 - binary frame
 - connection close
 - ping
 - pong
 - continuation frame

---

### New in v1.0.7

1. Add support to ENC28J60 Ethernet using **EthernetENC**.
2. Add Ethernet Library Patches for **UIPEthernet v2.0.9 and Ethernet2**
3. Update Platform.ini to support **PlatformIO 5.x owner-based dependency declaration**.

#### New in v1.0.6

1. Add **non-blocking WebSockets Server** feature to enable WS Server and WebServer running **concurrently**. See [**Support as Http server and the Websockets server on Arduino DUE**](https://github.com/khoih-prog/WebSockets_Generic/issues/1) and [**Running Http and Websocket Servers concurrently**](https://github.com/khoih-prog/WebSockets2_Generic/issues/1). Thanks to bug report and persistence of [Jake](https://github.com/jakespeed1311).
2. Add non-blocking WebSockets Server and WebServer examples. 
3. Add Ethernet Library Patches
4. Add Arduino SAMD Packages_Patches to fix compiler errors when using [Standard Template Library STL](https://en.wikipedia.org/wiki/Standard_Template_Library)

#### New in v1.0.5

1. Sync with [ArduinoWebsockets v0.4.18](https://github.com/gilmaimon/ArduinoWebsockets/releases/tag/0.4.18) to fix ESP8266 SSL bug. See [Secured-Two-Way: Client certificate is not sent if used along with setTrustAnchors](https://github.com/gilmaimon/ArduinoWebsockets/issues/84)

#### New in v1.0.4

1. Add support to all **STM32F/L/H/G/WB/MP1 (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8, etc.)**
2. Add support to **Seeeduino SAMD21/SAMD51 boards (SEEED_WIO_TERMINAL, SEEED_FEMTO_M0, SEEED_XIAO_M0, Wio_Lite_MG126, WIO_GPS_BOARD, SEEEDUINO_ZERO, SEEEDUINO_LORAWAN, SEEED_GROVE_UI_WIRELESS, etc.)**
3. Add sample Packages_Patches for **STM32 stm32** (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8)
4. Add Packages' Patches for **Seeeduino SAMD** to enable displaying **BOARD_NAME**
5. Add many examples
                                  
#### New in v1.0.3

1. Add support to STM32F boards with built-in Ethernet such as :
  - **Nucleo-144 (F429ZI, F767ZI)**
  - **Discovery (STM32F746G-DISCOVERY)**
  - **All STM32F Boards with Built-in Ethernet LAN8742A**

2. Add support to **STM32F1,2,3,4,7 boards (with 64+K Flash)** using **Ethernet W5x00, ENC28J60 or LAN8742A**
3. Add Packages' Patches to **Adafruit nRF52, SAMD, Arduino SAMD** to enable displaying **BOARD_NAME**
4. Enhance examples and update README.md

#### New in v1.0.2

1. Add support to **Ethernet ENC28J60, using UIPEthernet library**, for nRF52, SAMD21/SAMD51 and SAM DUE boards.

#### New in v1.0.1

1. Add support to **SAM DUE** boards.
2. Add support to **Ethernet W5x00, using either Ethernet, EthernetLarge or Ethernet2 library.**
3. Restructure code to provide flexibility to support many more WiFi/Ethernet modules/shields in the future. Please delete the *.cpp files, replaced with coresponding *.hpp files, in the library src directory, if the *.cpp files still exist after installing new version.

#### New in v1.0.0

1. Add support to **nRF52** boards, such as **AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc.**,  using WiFiNINA with [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic)
2. Add support to **SAMD51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)** , using WiFiNINA with [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic).
3. Add support to **SAMD21 (ZERO, MKR, NANO_33_IOT, M0, M0 Pro, AdaFruit CIRCUITPLAYGROUND_EXPRESS, etc.)**, using WiFiNINA with [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic).
4. Add Alexa/[`SINRIC`](https://sinric.com) examples and supports to those boards as well as ESP8266/ESP32

---
---
 
## Prerequisite

 1. [`Arduino IDE v1.8.13+`](https://www.arduino.cc/en/Main/Software)
 2. [`ESP32 core v1.0.4+`](https://github.com/espressif/arduino-esp32/releases) for ESP32 boards.
 3. [`ESP8266 core v2.7.4+`](https://github.com/esp8266/Arduino#installing-with-boards-manager) for ESP8266 boards.
 4. [`Arduino AVR core 1.8.3+`](https://github.com/arduino/ArduinoCore-avr) for Arduino AVR boards. Use Arduino Board Manager to install.
 5. [`Teensy core v1.53+`](https://www.pjrc.com/teensy/td_download.html) for Teensy (4.1, 4.0, 3.6, 3.5, 3,2, 3.1, 3.0) boards. **Not yet ready** in v1.0.7.
 6. [`Arduino SAM DUE core v1.6.12+`](https://www.arduino.cc/en/Guide/ArduinoDue) for SAM DUE ARM Cortex-M3 boards.
 7. [`Arduino SAMD core v1.8.8+`](https://www.arduino.cc/en/Guide/ArduinoM0) for SAMD ARM Cortex-M0+ boards.
 8. [`Adafruit SAMD core v1.6.3+`](https://www.adafruit.com/) for SAMD ARM Cortex-M0+ and M4 boards (Nano 33 IoT, etc.).
 9. [`Seeeduino SAMD core 1.7.9+`](https://www.seeedstudio.com/) for SAMD21/SAMD51 boards (XIAO M0, Wio Terminal, etc.).
10. [`Adafruit nRF52 v0.21.0+`](https://www.adafruit.com/) for nRF52 boards such as AdaFruit Feather nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc.
11. [`Arduino Core for STM32 v1.9.0+`](https://github.com/khoih-prog/Arduino_Core_STM32) for STM32F/L/H/G/WB/MP1 boards. To install go to Arduino IDE, select Boards Manager, search for **`STM32`**.
12. [`WiFiNINA_Generic library v1.7.1+`](https://github.com/khoih-prog/WiFiNINA_Generic) if for WiFiNINA. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiNINA_Generic.svg?)](https://www.ardu-badge.com/WiFiNINA_Generic).
13. [`EthernetWebServer library v1.0.13+`](https://github.com/khoih-prog/EthernetWebServer) if necessary to use Ethernet modules/shields. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer.svg?)](https://www.ardu-badge.com/EthernetWebServer)
14. Depending on which Ethernet module/shield you're using :
   - [`Ethernet library v2.0.0+`](https://www.arduino.cc/en/Reference/Ethernet) for W5100, W5200 and W5500.
   - [`Ethernet2 library v1.0.4+`](https://github.com/khoih-prog/Ethernet2) for W5500 (Deprecated, use Arduino Ethernet library).
   - [`Ethernet3 library v1.5.3+`](https://github.com/sstaub/Ethernet3) for W5500/WIZ550io/WIZ850io/USR-ES1 with Wiznet W5500 chip. **Not yet ready** in v1.0.7.
   - [`EthernetLarge library v2.0.0+`](https://github.com/OPEnSLab-OSU/EthernetLarge) for W5100, W5200 and W5500.
   - [`EthernetENC library v2.0.0+`](https://github.com/jandrassy/EthernetENC) for ENC28J60. **Ready** from v1.0.7.
   - [`UIPEthernet library v2.0.9+`](https://github.com/UIPEthernet/UIPEthernet) for ENC28J60.
   - [`STM32Ethernet library v1.2.0+`](https://github.com/stm32duino/STM32Ethernet) for built-in Ethernet LAN8742A on (Nucleo-144, Discovery). To be used with [`STM32duino_LwIP library v2.1.2+`](https://github.com/stm32duino/LwIP).
15. [`ESP_AT_Lib library v1.0.0+`](https://github.com/khoih-prog/ESP_AT_Lib) if necessary to use ESP8288/ESP32-AT shields. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/ESP_AT_Lib.svg?)](https://www.ardu-badge.com/ESP_AT_Lib). **Not yet ready** in v1.0.7.
16. [`WiFiWebServer library v1.0.7+`](https://github.com/khoih-prog/WiFiWebServer) if necessary to use certain WiFi/WiFiNINA features. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiWebServer.svg?)](https://www.ardu-badge.com/WiFiWebServer)
17. [`FlashStorage_SAMD library v1.0.0+`](https://github.com/khoih-prog/FlashStorage_SAMD) for SAMD21 and SAMD51 boards (ZERO, MKR, **NANO_33_IOT**, M0, M0 Pro, **AdaFruit Itsy-Bitsy M4**, etc.) if necessary to use certain features.
18. [`DueFlashStorage library`](https://github.com/sebnil/DueFlashStorage) for SAM DUE if necessary to use certain features.
19. [`Adafruit's LittleFS/InternalFS`](https://www.adafruit.com) for nRF52. Already included if you already installed Adafruit **nRF52 board package** from Boards Manager.
20. [`DoubleResetDetector_Generic v1.0.2+`](https://github.com/khoih-prog/DoubleResetDetector_Generic) if necessary to use some examples. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/DoubleResetDetector_Generic.svg?)](https://www.ardu-badge.com/DoubleResetDetector_Generic) if necessary to use certain features.

---

## Installation

### Use Arduino Library Manager

The best and easiest way is to use `Arduino Library Manager`. Search for [**WebSockets2_Generic**](https://github.com/khoih-prog/WebSockets2_Generic), then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/WebSockets2_Generic.svg?)](https://www.ardu-badge.com/WebSockets2_Generic) for more detailed instructions.

### Manual Install

Another way to install is to:

1. Navigate to [**WebSockets2_Generic**](https://github.com/khoih-prog/WebSockets2_Generic) page.
2. Download the latest release `WebSockets2_Generic-master.zip`.
3. Extract the zip file to `WebSockets2_Generic-master` directory 
4. Copy whole `WebSockets2_Generic-master` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO:

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**WebSockets2_Generic** library](https://platformio.org/lib/show/11239/WebSockets2_Generic) by using [Library Manager](https://platformio.org/lib/show/11239/WebSockets2_Generic/installation). Search for **WebSockets2_Generic** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---

### Packages' Patches

 1. **To be able to compile, run and automatically detect and display BOARD_NAME on nRF52840/nRF52832 boards**, you have to copy the whole [nRF52 0.21.0](Packages_Patches/adafruit/hardware/nrf52/0.21.0) directory into Adafruit nRF52 directory (~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0). 

Supposing the Adafruit nRF52 version is 0.21.0. These files must be copied into the directory:
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/cores/nRF5/Udp.h`**

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z
These files must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`**

 2. **To be able to compile and run on Teensy boards**, you have to copy the file [Teensy boards.txt](Packages_Patches/hardware/teensy/avr/boards.txt) into Teensy hardware directory (./arduino-1.8.12/hardware/teensy/avr/boards.txt). 

Supposing the Arduino version is 1.8.12. This file must be copied into the directory:

- `./arduino-1.8.12/hardware/teensy/avr/boards.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `./arduino-x.yy.zz/hardware/teensy/avr/boards.txt`

 3. **To be able to compile and run on SAM DUE boards**, you have to copy the whole [SAM DUE](Packages_Patches/arduino/hardware/sam/1.6.12) directory into Arduino sam directory (~/.arduino15/packages/arduino/hardware/sam/1.6.12). 

Supposing the Arduino SAM core version is 1.6.12. This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/1.6.12/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/x.yy.zz/platform.txt`

 4. **To be able to compile without error and automatically detect and display BOARD_NAME on Arduino SAMD (Nano-33-IoT, etc) boards**, you have to copy the whole [Arduino SAMD cores 1.8.8](Packages_Patches/arduino/hardware/samd/1.8.8) directory into Arduino SAMD directory (~/.arduino15/packages/arduino/hardware/samd/1.8.8).
 
Supposing the Arduino SAMD version is 1.8.8. These files must be copied into the directory:
- `~/.arduino15/packages/arduino/hardware/samd/1.8.8/platform.txt`
- **`~/.arduino15/packages/arduino/hardware/samd/1.8.8/cores/arduino/Arduino.h`**

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z

These files must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/x.yy.z/platform.txt`
- **`~/.arduino15/packages/arduino/hardware/samd/x.yy.z/cores/arduino/Arduino.h`**
 
 This is mandatory to fix the **notorious Arduino SAMD compiler error**. See [Improve Arduino compatibility with the STL (min and max macro)](https://github.com/arduino/ArduinoCore-samd/pull/399)
 
```
 ...\arm-none-eabi\include\c++\7.2.1\bits\stl_algobase.h:243:56: error: macro "min" passed 3 arguments, but takes just 2
     min(const _Tp& __a, const _Tp& __b, _Compare __comp)
```

Whenever the above-mentioned compiler error issue is fixed with the new Arduino SAMD release, you don't need to copy the `Arduino.h` file anymore.

 5. **To be able to automatically detect and display BOARD_NAME on Adafruit SAMD (Itsy-Bitsy M4, etc) boards**, you have to copy the file [Adafruit SAMD platform.txt](Packages_Patches/adafruit/hardware/samd/1.6.3) into Adafruit samd directory (~/.arduino15/packages/adafruit/hardware/samd/1.6.3). 

Supposing the Adafruit SAMD core version is 1.6.3. This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/1.6.3/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/platform.txt`

 6. **To be able to automatically detect and display BOARD_NAME on Seeeduino SAMD (XIAO M0, Wio Terminal, etc) boards**, you have to copy the file [Seeeduino SAMD platform.txt](Packages_Patches/Seeeduino/hardware/samd/1.7.9) into Adafruit samd directory (~/.arduino15/packages/Seeeduino/hardware/samd/1.7.9). 

Supposing the Seeeduino SAMD core version is 1.7.9. This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/1.7.9/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/platform.txt`

7. **To use Serial1 on some STM32 boards without Serial1 definition (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8, etc.) boards**, you have to copy the files [STM32 variant.h](Packages_Patches/STM32/hardware/stm32/1.9.0) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/1.9.0). You have to modify the files corresponding to your boards, this is just an illustration how to do.

Supposing the STM32 stm32 core version is 1.9.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/variants/NUCLEO_F767ZI/variant.h` for Nucleo-144 NUCLEO_F767ZI.
- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/variants/NUCLEO_L053R8/variant.h` for Nucleo-64 NUCLEO_L053R8.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
theses files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/NUCLEO_F767ZI/variant.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/NUCLEO_L053R8/variant.h`

---

### Libraries' Patches

1. If your application requires 2K+ HTML page, the current [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) must be modified if you are using W5200/W5500 Ethernet shields. W5100 is not supported for 2K+ buffer. If you use boards requiring different CS/SS pin for W5x00 Ethernet shield, for example ESP32, ESP8266, nRF52, etc., you also have to modify the following libraries to be able to specify the CS/SS pin correctly.

2. To fix [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet), just copy these following files into the [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) directory to overwrite the old files:
- [Ethernet.h](LibraryPatches/Ethernet/src/Ethernet.h)
- [Ethernet.cpp](LibraryPatches/Ethernet/src/Ethernet.cpp)
- [EthernetServer.cpp](LibraryPatches/Ethernet/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/Ethernet/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/Ethernet/src/utility/w5100.cpp)

3. To fix [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge), just copy these following files into the [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge) directory to overwrite the old files:
- [EthernetLarge.h](LibraryPatches/EthernetLarge/src/EthernetLarge.h)
- [EthernetLarge.cpp](LibraryPatches/EthernetLarge/src/EthernetLarge.cpp)
- [EthernetServer.cpp](LibraryPatches/EthernetLarge/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/EthernetLarge/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/EthernetLarge/src/utility/w5100.cpp)

4. To fix [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2), just copy these following files into the [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2) directory to overwrite the old files:

- [Ethernet2.h](LibraryPatches/Ethernet2/src/Ethernet2.h)
- [Ethernet2.cpp](LibraryPatches/Ethernet2/src/Ethernet2.cpp)

To add UDP Multicast support, necessary for this [**MDNS_Generic library**](https://github.com/khoih-prog/MDNS_Generic):

- [EthernetUdp2.h](LibraryPatches/Ethernet2/src/EthernetUdp2.h)
- [EthernetUdp2.cpp](LibraryPatches/Ethernet2/src/EthernetUdp2.cpp)

5. To fix [`Ethernet3 library`](https://github.com/sstaub/Ethernet3), just copy these following files into the [`Ethernet3 library`](https://github.com/sstaub/Ethernet3) directory to overwrite the old files:
- [Ethernet3.h](LibraryPatches/Ethernet3/src/Ethernet3.h)
- [Ethernet3.cpp](LibraryPatches/Ethernet3/src/Ethernet3.cpp)

6. **To be able to compile and run on nRF52 boards with ENC28J60 using UIPEthernet library**, you have to copy these following files into the UIPEthernet `utility` directory to overwrite the old files:

- For [UIPEthernet v2.0.8](https://github.com/UIPEthernet/UIPEthernet)

  - [UIPEthernet.h](LibraryPatches/UIPEthernet/UIPEthernet.h)
  - [UIPEthernet.cpp](LibraryPatches/UIPEthernet/UIPEthernet.cpp)
  - [Enc28J60Network.h](LibraryPatches/UIPEthernet/utility/Enc28J60Network.h)
  - [Enc28J60Network.cpp](LibraryPatches/UIPEthernet/utility/Enc28J60Network.cpp)

- For [UIPEthernet v2.0.9](https://github.com/UIPEthernet/UIPEthernet)

  - [UIPEthernet.h](LibraryPatches/UIPEthernet-2.0.9/UIPEthernet.h)
  - [UIPEthernet.cpp](LibraryPatches/UIPEthernet-2.0.9/UIPEthernet.cpp)
  - [Enc28J60Network.h](LibraryPatches/UIPEthernet-2.0.9/utility/Enc28J60Network.h)
  - [Enc28J60Network.cpp](LibraryPatches/UIPEthernet-2.0.9/utility/Enc28J60Network.cpp)

7. To fix [`ESP32 compile error`](https://github.com/espressif/arduino-esp32), just copy the following file into the [`ESP32`](https://github.com/espressif/arduino-esp32) cores/esp32 directory (e.g. ./arduino-1.8.12/hardware/espressif/cores/esp32) to overwrite the old file:

- [Server.h](LibraryPatches/esp32/cores/esp32/Server.h)

---
---

### Important Notes

1. Code is restructured to provide flexibility to make it easy to support many more **WiFi/Ethernet** modules/shields in the future. Please delete the *.cpp files, replaced by *.hpp files, in the src directory, if *.cpp files still exist after installing new version.

2. For **Adafruit nRF52**, use the SPI's  pin as follows:

  - SS/CS     = 10
  - SPI_MOSI  = MO(SI)
  - SPI_MISO  = MI(SO)
  - SPI_SCK   = SCK

3. For **Adafruit SAMD21/SAMD51**, use the SPI's CS/SS pin as follows:

  - Itsy-Bitsy M0/M4, Feather M0 (Express), Hallowing M0 Express, Zero, Metro M0 => use CS = 16 = pin A2
  - Feather M4 (SAMD51)   => use SS/CS = 9
  - Grand Central M4      => use SS/CS = 53
  - Hallowing M4          => use SS/CS = 10
  - Metro M4 AirLift      => use SS/CS = 36

To know the default CS/SS pins of not listed boards, check the related `variant.h` files in 

`~/.arduino15/packages/adafruit/hardware/samd/x.y.zz/variants/board_name/variant.h`

4. For **Arduino SAM DUE**, use the SPI's  pin as follows:

  - SS/CS     = 10
  - SPI_MOSI  = 75 ( pin 4 @ [ICSP connector](pics/ICSP_connector.jpg) )
  - SPI_MISO  = 74 ( pin 1 @ [ICSP connector](pics/ICSP_connector.jpg) )
  - SPI_SCK   = 76 ( pin 3 @ [ICSP connector](pics/ICSP_connector.jpg) )
  
<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/blob/master/pics/ICSP_connector.jpg">
</p>
  
---
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
  
  Serial.print("Got Message: ");
  Serial.println(message.data());
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

#### Reading WebSockets Client messages using non-blocking mode (new from v1.0.6):

Using this new feature to enable doing other tasks in the loop(), such as WebServer, control tasks, etc.
Server, using library version before v1.0.6, can only read Client messages in blocking mode. Therefore, the WebSocket Server can't hang, waiting for Client, and block all other tasks from running.

```c++

  // You can do some other tasks here, such as WebServer, controlling tasks, etc.
  
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
```

Please test using one of these following new examples with v1.0.6 and v1.0.5- to see the blocking effects. Please remember to change in loop() from

```
WebsocketsMessage msg = client.readNonBlocking();
```

to

```
WebsocketsMessage msg = client.readBlocking();
```

as **client.readNonBlocking() is a new function in v1.0.6+.**

##### For ESP32/ESP8266

1. [Esp32-AdvancedWebServer](examples/ESP32/Esp32-AdvancedWebServer) using ESP32
2. [Esp8266-AdvancedWebServer](examples/ESP8266/Esp8266-AdvancedWebServer) using ESP8266

##### For WiFiNINA

3. [SAMD-AdvancedWebServer](examples/Generic/WiFiNINA/SAMD/SAMD-AdvancedWebServer) using Nano-33-IoT
4. [nRF52-AdvancedWebServer](examples/Generic/WiFiNINA/nRF52/nRF52-AdvancedWebServer) using Adafruit nRF52 NRF52840_FEATHER_EXPRESS, NINA_B302_ublox and WiFiNINA W102 module.
5. [STM32-AdvancedWebServer](examples/Generic/WiFiNINA/STM32/STM32-AdvancedWebServer) using STM32 Nucleo-64 L053R8, STM32F4 and WiFiNINA W102 module.


##### For W5x00, ENC28J60 or LAN8742A Ethernet

6. [SAMDUE-Ethernet_AdvancedWebServer](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet_AdvancedWebServer) using SAM DUE and W5100 Ethernet
7. [STM32-Ethernet_AdvancedWebServer](examples/Generic/Ethernet/STM32/STM32-Ethernet_AdvancedWebServer) using STM32F7 Nucleo-144 F676ZI and built-in LAN8742A Ethernet.
8. [SAMD-Ethernet_AdvancedWebServer](examples/Generic/Ethernet/SAMD/SAMD-Ethernet_AdvancedWebServer) using Adafruit SAMD51 Itsy_Bitsy_M4, Seeeduino SAMD21 XIAO_M0 and W5500 Ethernet.
9. [nRF52-Ethernet_AdvancedWebServer](examples/Generic/Ethernet/nRF52/nRF52-Ethernet_AdvancedWebServer) using Adafruit nRF52 NRF52840_FEATHER_EXPRESS, NINA_B302_ublox and W5500 Ethernet.


---
---

### HOWTO use WiFiNINA module/shield with WiFiNINA_Generic library

```cpp
#define WEBSOCKETS_USE_WIFININA           true
```

---

###  For SAMD21/SAMD51, nRF52, SAM DUE using Ethernet W5x0 or ENC28J60

#### To use Ethernet W5x00 module/shield with Ethernetx library

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/blob/master/pics/W5500.jpg">
</p>

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/blob/master/pics/W5500_1.jpg">
</p>

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/blob/master/pics/W5100.jpg">
</p>

#### 1. To use Ethernet `W5x00` module/shield with one of the Ethernet libraries

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_UIP_ETHERNET                  false
```

 - To use `W5x00` module/shield with `Ethernet` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET                      true
#define USE_ETHERNET2                     false
#define USE_ETHERNET_LARGE                false
#define USE_ETHERNET_ENC                  false

#define USE_UIP_ETHERNET                  false
```

 - To use `W5x00` module/shield with `Ethernet2` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET                      false
#define USE_ETHERNET2                     true
#define USE_ETHERNET_LARGE                false
#define USE_ETHERNET_ENC                  false

#define USE_UIP_ETHERNET                  false
```
 - To use` W5x00` module/shield with `EthernetLarge` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET                      false
#define USE_ETHERNET2                     false
#define USE_ETHERNET_LARGE                true
#define USE_ETHERNET_ENC                  false

#define USE_UIP_ETHERNET                  false
```

#### 2. To use Ethernet `ENC28J60` module/shield with `UIPEthernet` library

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/blob/master/pics/ENC28J60.jpg">
</p>

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET                      false
#define USE_ETHERNET2                     false
#define USE_ETHERNET_LARGE                false
#define USE_ETHERNET_ENC                  false

#define USE_UIP_ETHERNET                  true
```

#### 3. To use Ethernet `ENC28J60` module/shield with new `EthernetENC` library

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/blob/master/pics/ENC28J60.jpg">
</p>

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET                      false
#define USE_ETHERNET2                     false
#define USE_ETHERNET_LARGE                false
#define USE_ETHERNET_ENC                  true

#define USE_UIP_ETHERNET                  false
```

#### 3. It's much easier just add to the sketch

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

// Just select one to be true. If all is false, default is Ethernet. 
// If more than one are true, the priority is USE_ETHERNET, USE_ETHERNET2, USE_ETHERNET_LARGE, USE_UIP_ETHERNET
#define USE_ETHERNET                  false
#define USE_ETHERNET2                 false
#define USE_ETHERNET_LARGE            true
#define USE_ETHERNET_ENC              false

#define USE_UIP_ETHERNET              false

#if USE_ETHERNET
  // Also default to Ethernet library
  #include <Ethernet.h>
  #define ETHERNET_TYPE               "W5x00 and Ethernet Library"
#elif USE_ETHERNET2
  #include <Ethernet2.h>
  #define ETHERNET_TYPE               "W5x00 and Ethernet2 Library"
#elif USE_ETHERNET_LARGE
  #include <EthernetLarge.h>
  #define ETHERNET_TYPE               "W5x00 and EthernetLarge Library"
#elif USE_ETHERNET_ENC
  #include <EthernetENC.h>
  #define ETHERNET_TYPE               "ENC28J60 and EthernetENC Library"  
#elif USE_UIP_ETHERNET
  #include <UIPEthernet.h>
  #include <utility/logging.h> 
  #define ETHERNET_TYPE               "ENC28J60 and UIPEthernet Library"
#else
  // Default to Ethernet library
  #include <Ethernet.h>
  #define ETHERNET_TYPE               "W5x00 and Ethernet Library"
#endif

#ifndef USE_THIS_SS_PIN
#define USE_THIS_SS_PIN   10    // For other boards
#endif
```

---

###  For STM32F/L/H/G/WB/MP1  using Ethernet W5x0, ENC28J60 or LAN8742A

#### To use Ethernet W5x00 module/shield with Ethernetx library

#### 1. To use Ethernet `W5x00` module/shield with one of the Ethernet libraries

```cpp
#define WEBSOCKETS_USE_ETHERNET           true
#define USE_UIP_ETHERNET                  false
#define USE_LAN8742A_ETHERNET             false
```

 - To use `W5x00` module/shield with `Ethernet` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET                      true
#define USE_ETHERNET2                     false
#define USE_ETHERNET_LARGE                false
#define USE_ETHERNET_ENC                  false

#define USE_UIP_ETHERNET                  false
#define USE_LAN8742A_ETHERNET             false
```

 - To use `W5x00` module/shield with `Ethernet2` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET                      false
#define USE_ETHERNET2                     true
#define USE_ETHERNET_LARGE                false
#define USE_ETHERNET_ENC                  false

#define USE_UIP_ETHERNET                  false
#define USE_LAN8742A_ETHERNET             false
```
 - To use` W5x00` module/shield with `EthernetLarge` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET                      false
#define USE_ETHERNET2                     false
#define USE_ETHERNET_LARGE                true
#define USE_ETHERNET_ENC                  false

#define USE_UIP_ETHERNET                  false
#define USE_LAN8742A_ETHERNET             false
```

#### 2. To use Ethernet `ENC28J60` module/shield with `UIPEthernet` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET                      false
#define USE_ETHERNET2                     false
#define USE_ETHERNET_LARGE                false
#define USE_ETHERNET_ENC                  false

#define USE_UIP_ETHERNET                  true
#define USE_LAN8742A_ETHERNET             false
```

#### 3. To use Ethernet `ENC28J60` module/shield with new `EthernetENC` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET                      false
#define USE_ETHERNET2                     false
#define USE_ETHERNET_LARGE                false
#define USE_ETHERNET_ENC                  true

#define USE_UIP_ETHERNET                  false
#define USE_LAN8742A_ETHERNET             false
```

#### 4. To use Ethernet `LAN8742A` built-in module/shield with `STM32Ethernet` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET                      false
#define USE_ETHERNET2                     false
#define USE_ETHERNET_LARGE                false
#define USE_ETHERNET_ENC                  false

#define USE_UIP_ETHERNET                  false
#define USE_LAN8742A_ETHERNET             true
```

#### 5. It's much easier just add to the sketch

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

// Just select one to be true. If all is false, default is Ethernet. 
// If more than one are true, the priority is USE_ETHERNET, USE_ETHERNET2, USE_ETHERNET_LARGE, USE_UIP_ETHERNET
#define USE_ETHERNET                  false
#define USE_ETHERNET2                 false
#define USE_ETHERNET_LARGE            true
#define USE_ETHERNET_ENC              false

#define USE_UIP_ETHERNET              false
#define USE_LAN8742A_ETHERNET         false

#if USE_ETHERNET
  // Also default to Ethernet library
  #include <Ethernet.h>
  #define ETHERNET_TYPE               "W5x00 and Ethernet Library"
#elif USE_ETHERNET2
  #include <Ethernet2.h>
  #define ETHERNET_TYPE               "W5x00 and Ethernet2 Library"
#elif USE_ETHERNET_LARGE
  #include <EthernetLarge.h>
  #define ETHERNET_TYPE               "W5x00 and EthernetLarge Library"
#elif USE_ETHERNET_ENC
  #include <EthernetENC.h>
  #define ETHERNET_TYPE               "ENC28J60 and EthernetENC Library"  
#elif USE_UIP_ETHERNET
  #include <UIPEthernet.h>
  #include <utility/logging.h> 
  #define ETHERNET_TYPE               "ENC28J60 and UIPEthernet Library"
#elif USE_LAN8742A_ETHERNET
  #define USE_BUILTIN_ETHERNET        true
  #include <LwIP.h>
  #include <STM32Ethernet.h>
  #define ETHERNET_TYPE               "LAN8742A and STM32Ethernet Library"  
#else
  // Default to Ethernet library
  #include <Ethernet.h>
  #define ETHERNET_TYPE               "W5x00 and Ethernet Library"
#endif

#ifndef USE_THIS_SS_PIN
  #define USE_THIS_SS_PIN   10    // For other boards
#endif
```
---

### To use ESP8266/ESP32 native WiFi

Default is using `ESP8266/ESP32 native WiFi`. You don't need to do anything special.

---
---

### Examples

#### For ESP32 boards

1. [Esp32-Client](examples/ESP32/Esp32-Client)
2. [Minimal-Esp32-Client](examples/ESP32/Minimal-Esp32-Client)
3. [Secured-Esp32-Client](examples/ESP32/Secured-Esp32-Client)
4. [ESP32-Client_SINRIC](examples/ESP32/ESP32-Client_SINRIC)
5. [Esp32-Server](examples/ESP32/Esp32-Server)
6. [Esp32-RepeatingClient](examples/ESP32/Esp32-RepeatingClient)
7. [Esp32-AdvancedWebServer](examples/ESP32/Esp32-AdvancedWebServer). New in v1.0.6+

#### For ESP8266 boards

1. [Esp8266-Client](examples/ESP8266/Esp8266-Client)
2. [Minimal-Esp8266-Client](examples/ESP8266/Minimal-Esp8266-Client)
3. [Secured-Esp8266-Client](examples/ESP8266/Secured-Esp8266-Client)
4. [SecuredTwoWay-Esp8266-Client](examples/ESP8266/SecuredTwoWay-Esp8266-Client)
5. [ESP8266-Client_SINRIC](examples/ESP8266/ESP8266-Client_SINRIC)
6. [Esp8266-Server](examples/ESP8266/Esp8266-Server)
7. [Esp8266-RepeatingClient](examples/ESP8266/Esp8266-RepeatingClient)
8. [Esp8266-AdvancedWebServer](examples/ESP8266/Esp8266-AdvancedWebServer). New in v1.0.6+

#### For nRF52 boards using WiFiNINA

1. [nRF52-Client](examples/Generic/WiFiNINA/nRF52/nRF52-Client)
2. [nRF52-Minimal-Client](examples/Generic/WiFiNINA/nRF52/nRF52-Minimal-Client)
3. [nRF52-Client_SINRIC](examples/Generic/WiFiNINA/nRF52/nRF52-Client_SINRIC)
4. [nRF52-Server](examples/Generic/WiFiNINA/nRF52/nRF52-Server)
5. [nRF52-RepeatingClient](examples/Generic/WiFiNINA/nRF52/nRF52-RepeatingClient)
6. [nRF52_ServerAllFunctionsDemo](examples/Generic/WiFiNINA/nRF52/nRF52_ServerAllFunctionsDemo)
7. [nRF52-AdvancedWebServer](examples/Generic/WiFiNINA/nRF52/nRF52-AdvancedWebServer). New in v1.0.6+

#### For SAMD21/SAMD51 boards using WiFiNINA

1. [SAMD-Client](examples/Generic/WiFiNINA/SAMD/SAMD-Client)
2. [SAMD-Minimal-Client](examples/Generic/WiFiNINA/SAMD/SAMD-Minimal-Client)
3. [SAMD-Client_SINRIC](examples/Generic/WiFiNINA/SAMD/SAMD-Client_SINRIC)
4. [SAMD-Server](examples/Generic/WiFiNINA/SAMD/SAMD-Server)
5. [SAMD-RepeatingClient](examples/Generic/WiFiNINA/SAMD/SAMD-RepeatingClient)
6. [SAMD_ServerAllFunctionsDemo](examples/Generic/WiFiNINA/SAMD/SAMD_ServerAllFunctionsDemo)
7. [SAMD-AdvancedWebServer](examples/Generic/WiFiNINA/SAMD/SAMD-AdvancedWebServer). New in v1.0.6+

#### For STM32F/L/H/G/WB/MP1 boards using WiFiNINA

1. [STM32-Client](examples/Generic/WiFiNINA/STM32/STM32-Client)
2. [STM32-Minimal-Client](examples/Generic/WiFiNINA/STM32/STM32-Minimal-Client)
3. [STM32-Client_SINRIC](examples/Generic/WiFiNINA/STM32/STM32-Client_SINRIC)
4. [STM32-Server](examples/Generic/WiFiNINA/STM32/STM32-Server)
5. [STM32-RepeatingClient](examples/Generic/WiFiNINA/STM32/STM32-RepeatingClient)
6. [STM32_ServerAllFunctionsDemo](examples/Generic/WiFiNINA/STM32/STM32_ServerAllFunctionsDemo)
7. [STM32-AdvancedWebServer](examples/Generic/WiFiNINA/STM32/STM32-AdvancedWebServer). New in v1.0.6+

#### For nRF52 boards using Ethernet (W5x00 or ENC28J60)

1. [nRF52-Ethernet-Client](examples/Generic/Ethernet/nRF52/nRF52-Ethernet-Client)
2. [nRF52-Ethernet-Minimal-Client](examples/Generic/Ethernet/nRF52/nRF52-Ethernet-Minimal-Client)
3. [nRF52-Ethernet-Client_SINRIC](examples/Generic/Ethernet/nRF52/nRF52-Ethernet-Client_SINRIC)
4. [nRF52-Ethernet-Server](examples/Generic/Ethernet/nRF52/nRF52-Ethernet-Server)
5. [nRF52-Ethernet-RepeatingClient](examples/Generic/Ethernet/nRF52/nRF52-Ethernet-RepeatingClient)
6. [nRF52-Ethernet_ServerAllFunctionsDemo](examples/Generic/Ethernet/nRF52/nRF52-Ethernet_ServerAllFunctionsDemo)
7. [nRF52-Ethernet_AdvancedWebServer](examples/Generic/Ethernet/nRF52/nRF52-Ethernet_AdvancedWebServer). New in v1.0.6+

#### For SAMD21/SAMD51 boards using Ethernet (W5x00 or ENC28J60)

1. [SAMD-Ethernet-Client](examples/Generic/Ethernet/SAMD/SAMD-Ethernet-Client)
2. [SAMD-Ethernet-Minimal-Client](examples/Generic/Ethernet/SAMD/SAMD-Ethernet-Minimal-Client)
3. [SAMD-Ethernet-Client_SINRIC](examples/Generic/Ethernet/SAMD/SAMD-Ethernet-Client_SINRIC)
4. [SAMD-Ethernet-Server](examples/Generic/Ethernet/SAMD/SAMD-Ethernet-Server)
5. [SAMD-Ethernet-RepeatingClient](examples/Generic/Ethernet/SAMD/SAMD-Ethernet-RepeatingClient)
6. [SAMD-Ethernet_ServerAllFunctionsDemo](examples/Generic/Ethernet/SAMD/SAMD-Ethernet_ServerAllFunctionsDemo)
7. [SAMD-Ethernet_AdvancedWebServer](examples/Generic/Ethernet/SAMD/SAMD-Ethernet_AdvancedWebServer). New in v1.0.6+

#### For SAM-DUE boards using Ethernet (W5x00 or ENC28J60)

1. [SAMDUE-Ethernet-Client](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet-Client)
2. [SAMDUE-Ethernet-Minimal-Client](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet-Minimal-Client)
3. [SAMDUE-Ethernet-Client_SINRIC](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet-Client_SINRIC)
4. [SAMDUE-Ethernet-Server](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet-Server)
5. [SAMDUE-Ethernet-RepeatingClient](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet-RepeatingClient)
6. [SAMDUE-Ethernet_ServerAllFunctionsDemo](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet_ServerAllFunctionsDemo)
7. [SAMDUE-Ethernet_AdvancedWebServer](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet_AdvancedWebServer). New in v1.0.6+

#### For STM32F/L/H/G/WB/MP1 boards using Ethernet (W5x00, ENC28J60 or LAN8742A)

1. [STM32-Ethernet-Client](examples/Generic/Ethernet/STM32/STM32-Ethernet-Client)
2. [STM32-Ethernet-Minimal-Client](examples/Generic/Ethernet/STM32/STM32-Ethernet-Minimal-Client)
3. [STM32-Ethernet-Client_SINRIC](examples/Generic/Ethernet/STM32/STM32-Ethernet-Client_SINRIC)
4. [STM32-Ethernet-Server](examples/Generic/Ethernet/STM32/STM32-Ethernet-Server)
5. [STM32-Ethernet-RepeatingClient](examples/Generic/Ethernet/STM32/STM32-Ethernet-RepeatingClient)
6. [STM32-Ethernet_ServerAllFunctionsDemo](examples/Generic/Ethernet/STM32/STM32-Ethernet_ServerAllFunctionsDemo)
7. [STM32-Ethernet_AdvancedWebServer](examples/Generic/Ethernet/STM32/STM32-Ethernet_AdvancedWebServer). New in v1.0.6+

---
---

### Example [SAMD-Client_SINRIC](examples/Generic/WiFiNINA/SAMD/SAMD-Client_SINRIC)

Please take a look at other examples, as well.

#### 1. File [SAMD-Client_SINRIC.ino](examples/Generic/WiFiNINA/SAMD/SAMD-Client_SINRIC/SAMD-Client_SINRIC.ino)

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

#### 2. File [defines.h](examples/Generic/WiFiNINA/SAMD/SAMD-Client_SINRIC/defines.h)

```cpp
#ifndef defines_h
#define defines_h

#if    ( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
      || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) \
      || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) || defined(ARDUINO_SAMD_MKRVIDOR4000) || defined(__SAMD21G18A__) \
      || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) || defined(__SAMD21E18A__) || defined(__SAMD51__) || defined(__SAMD51J20A__) || defined(__SAMD51J19A__) \
      || defined(__SAMD51G19A__) || defined(__SAMD51P19A__) || defined(__SAMD21G18A__) )
#if defined(WEBSOCKETS_WIFININA_USE_SAMD)
#undef WEBSOCKETS_WIFININA_USE_SAMD
#endif
#define WEBSOCKETS_USE_WIFININA           true
#define WEBSOCKETS_WIFININA_USE_SAMD      true
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
#elif defined(ADAFRUIT_FEATHER_M0_EXPRESS)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_FEATHER_M0_EXPRESS"
#elif defined(ADAFRUIT_METRO_M0_EXPRESS)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_METRO_M0_EXPRESS"
#elif defined(ADAFRUIT_CIRCUITPLAYGROUND_M0)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_CIRCUITPLAYGROUND_M0"
#elif defined(ADAFRUIT_GEMMA_M0)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_GEMMA_M0"
#elif defined(ADAFRUIT_TRINKET_M0)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_TRINKET_M0"
#elif defined(ADAFRUIT_ITSYBITSY_M0)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_ITSYBITSY_M0"
#elif defined(ARDUINO_SAMD_HALLOWING_M0)
#define BOARD_TYPE      "SAMD21 ARDUINO_SAMD_HALLOWING_M0"
#elif defined(ADAFRUIT_METRO_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_METRO_M4_EXPRESS"
#elif defined(ADAFRUIT_GRAND_CENTRAL_M4)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_GRAND_CENTRAL_M4"
#elif defined(ADAFRUIT_FEATHER_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_FEATHER_M4_EXPRESS"
#elif defined(ADAFRUIT_ITSYBITSY_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_ITSYBITSY_M4_EXPRESS"
#elif defined(ADAFRUIT_TRELLIS_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_TRELLIS_M4_EXPRESS"
#elif defined(ADAFRUIT_PYPORTAL)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYPORTAL"
#elif defined(ADAFRUIT_PYPORTAL_M4_TITANO)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYPORTAL_M4_TITANO"
#elif defined(ADAFRUIT_PYBADGE_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYBADGE_M4_EXPRESS"
#elif defined(ADAFRUIT_METRO_M4_AIRLIFT_LITE)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_METRO_M4_AIRLIFT_LITE"
#elif defined(ADAFRUIT_PYGAMER_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYGAMER_M4_EXPRESS"
#elif defined(ADAFRUIT_PYGAMER_ADVANCE_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYGAMER_ADVANCE_M4_EXPRESS"
#elif defined(ADAFRUIT_PYBADGE_AIRLIFT_M4)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYBADGE_AIRLIFT_M4"
#elif defined(ADAFRUIT_MONSTER_M4SK_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_MONSTER_M4SK_EXPRESS"
#elif defined(ADAFRUIT_HALLOWING_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_HALLOWING_M4_EXPRESS"
#elif defined(SEEED_WIO_TERMINAL)
#define BOARD_TYPE      "SAMD SEEED_WIO_TERMINAL"
#elif defined(SEEED_FEMTO_M0)
#define BOARD_TYPE      "SAMD SEEED_FEMTO_M0"
#elif defined(SEEED_XIAO_M0)
#define BOARD_TYPE      "SAMD SEEED_XIAO_M0"
#elif defined(Wio_Lite_MG126)
#define BOARD_TYPE      "SAMD SEEED Wio_Lite_MG126"
#elif defined(WIO_GPS_BOARD)
#define BOARD_TYPE      "SAMD SEEED WIO_GPS_BOARD"
#elif defined(SEEEDUINO_ZERO)
#define BOARD_TYPE      "SAMD SEEEDUINO_ZERO"
#elif defined(SEEEDUINO_LORAWAN)
#define BOARD_TYPE      "SAMD SEEEDUINO_LORAWAN"
#elif defined(SEEED_GROVE_UI_WIRELESS)
#define BOARD_TYPE      "SAMD SEEED_GROVE_UI_WIRELESS"
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

### Using SINRIC Service

This is the terminal output when running [SAMD-Client_SINRIC](examples/Generic/WiFiNINA/SAMD/SAMD-Client_SINRIC) example on **Nano-33 IoT**:

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
With the esp8266 there are multiple ways for using WSS. By default, `ArduinoWebsockets` does not validate the certificate chain. This can be set explicitly using:
```c++
client.setInsecure();
```

You can also use a `SSL Fingerprint` to validate the SSL connection, for example:
```c++
const char ssl_fingerprint[] PROGMEM = "D5 07 4D 79 B2 D2 53 D7 74 E6 1B 46 C5 86 4E FE AD 00 F1 98";

client.setFingerprint(ssl_fingerprint);
```

or you could use the `setKnownKey()` method to specify the public key of a certificate in order to validate the server you are connecting to.
```
PublicKey *publicKey = new PublicKey(public_key);
client.setKnownKey(publicKey);
```
or you can specify the Certificate Authority (CA) using `setTrustAnchors` method, as follows:

```
X509List *serverTrustedCA = new X509List(ca_cert);
client.setTrustAnchors(serverTrustedCA);
```

For client-side certificate validation, you can use RSA or EC certificates, using the method `setClientRSACert` or `setClientECCert` .


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

1. This is terminal debug output when running [SAMD-Ethernet-Client_SINRIC](examples/Generic/Ethernet/SAMD/SAMD-Ethernet-Client_SINRIC) on SAMD51 **ADAFRUIT_ITSYBITSY_M4_EXPRESS using ENC28J60 Ethernet module.**

```
Starting WebSockets2_Generic SAMD-Ethernet-Client_SINRIC on SAMD ADAFRUIT_ITSYBITSY_M4_EXPRESS
Ethernet using ENC28J60 and UIPEthernet Library
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

---

2. This is terminal debug output when running [SAMDUE-Ethernet-Server](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet-Server) on **SAM DUE board with Ethernet W5100 shield using EthernetLarge library**, and receiving WebSockets connection from an ESP8266 board.

```
Starting WebSockets2_Generic SAMDUE-Ethernet-Server on SAM DUE
Ethernet using W5x00 and EthernetLarge Library
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

---

3. This is terminal debug output when running [nRF52-Ethernet-Server](examples/Generic/Ethernet/nRF52/nRF52-Ethernet-Server) on **Adafruit NRF52840_ITSYBITSY_EXPRESS board with Ethernet ENC28J60 shield using UIPEthernet library**, and receiving WebSockets connection from an ESP8266 board.

```
Starting WebSockets2_Generic nRF52-Ethernet-Server on NRF52840_ITSYBITSY_EXPRESS
Ethernet using ENC28J60 and UIPEthernet Library
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

---

4. This is terminal debug output when running [STM32-Ethernet-Client_SINRIC](examples/Generic/Ethernet/STM32/STM32-Ethernet-Client_SINRIC) on **STM32F7 Nucleo-144 NUCLEO_F767ZI board with built-in Ethernet LAN8742A using STMEthernet library**.

```
Starting WebSockets2_Generic STM32-Ethernet-Client_SINRIC on NUCLEO_F767ZI
Ethernet using LAN8742A and STM32Ethernet Library
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

5. This is the terminal debug output when running [SAMDUE-Ethernet_ServerAllFunctionsDemo](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet_ServerAllFunctionsDemo) example on **SAM DUE and W5100 Ethernet**. There are 3 WebSockets Clients connecting to the WebSockets Server:

  - ESP32 running [Esp32-RepeatingClient](examples/ESP32/Esp32-RepeatingClient)
  - ESP8266 running [Esp8266-RepeatingClient](examples/ESP8266/Esp8266-RepeatingClient)
  - STM32 Nucleo-144 NUCLEO_F767ZI running [STM32-Ethernet-RepeatingClient](examples/Generic/Ethernet/STM32/STM32-Ethernet-RepeatingClient)

```
Start Generic_WebSocketServerAllFunctionsDemo_W5500
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 10
W5100::init: W5100, SSIZE =4096
WebSockets Server IP address: 192.168.2.95
WebSockets Server Running and Ready on SAM DUE
IP address: 192.168.2.95, Port: 8080
[WS] WebsocketsServer::recvHandshakeRequest: value = 192.168.2.95
[WS] WebsocketsServer::recvHandshakeRequest: value = MDEyMzQ1Njc4OWFiY2RlZg==
[WS] WebsocketsServer::recvHandshakeRequest: value = websocket
[WS] WebsocketsServer::recvHandshakeRequest: value = Upgrade
[WS] WebsocketsServer::recvHandshakeRequest: value = 13
[WS] WebsocketsServer::recvHandshakeRequest: value = TinyWebsockets Client
[WS] WebsocketsServer::recvHandshakeRequest: value = Basic 
[WS] WebsocketsServer::recvHandshakeRequest: value = https://github.com/khoih-prog/Websockets2_Generic
Got Message: Hello to Server from ESP8266
[WS] WebsocketsServer::recvHandshakeRequest: value = 192.168.2.95
[WS] WebsocketsServer::recvHandshakeRequest: value = MDEyMzQ1Njc4OWFiY2RlZg==
[WS] WebsocketsServer::recvHandshakeRequest: value = websocket
[WS] WebsocketsServer::recvHandshakeRequest: value = Upgrade
[WS] WebsocketsServer::recvHandshakeRequest: value = 13
[WS] WebsocketsServer::recvHandshakeRequest: value = TinyWebsockets Client
[WS] WebsocketsServer::recvHandshakeRequest: value = Basic 
[WS] WebsocketsServer::recvHandshakeRequest: value = https://github.com/khoih-prog/Websockets2_Generic
Got Message: Hello to Server from ESP8266
[WS] WebsocketsServer::recvHandshakeRequest: value = 192.168.2.95
[WS] WebsocketsServer::recvHandshakeRequest: value = MDEyMzQ1Njc4OWFiY2RlZg==
[WS] WebsocketsServer::recvHandshakeRequest: value = websocket
[WS] WebsocketsServer::recvHandshakeRequest: value = Upgrade
[WS] WebsocketsServer::recvHandshakeRequest: value = 13
[WS] WebsocketsServer::recvHandshakeRequest: value = TinyWebsockets Client
[WS] WebsocketsServer::recvHandshakeRequest: value = Basic 
[WS] WebsocketsServer::recvHandshakeRequest: value = https://github.com/khoih-prog/Websockets2_Generic
Got Message: Hello to Server from ESP32
[WS] WebsocketsServer::recvHandshakeRequest: value = 192.168.2.95
[WS] WebsocketsServer::recvHandshakeRequest: value = MDEyMzQ1Njc4OWFiY2RlZg==
[WS] WebsocketsServer::recvHandshakeRequest: value = websocket
[WS] WebsocketsServer::recvHandshakeRequest: value = Upgrade
[WS] WebsocketsServer::recvHandshakeRequest: value = 13
[WS] WebsocketsServer::recvHandshakeRequest: value = TinyWebsockets Client
[WS] WebsocketsServer::recvHandshakeRequest: value = Basic 
[WS] WebsocketsServer::recvHandshakeRequest: value = https://github.com/khoih-prog/Websockets2_Generic
Got Message: Hello to Server from NUCLEO_F767ZI
[WS] WebsocketsServer::recvHandshakeRequest: value = 192.168.2.95
[WS] WebsocketsServer::recvHandshakeRequest: value = MDEyMzQ1Njc4OWFiY2RlZg==
[WS] WebsocketsServer::recvHandshakeRequest: value = websocket
[WS] WebsocketsServer::recvHandshakeRequest: value = Upgrade
[WS] WebsocketsServer::recvHandshakeRequest: value = 13
[WS] WebsocketsServer::recvHandshakeRequest: value = TinyWebsockets Client
[WS] WebsocketsServer::recvHandshakeRequest: value = Basic 
[WS] WebsocketsServer::recvHandshakeRequest: value = https://github.com/khoih-prog/Websockets2_Generic
Got Message: Hello to Server from ESP32
...
```

---

### Screenshots

1. This is the screenshot when running [STM32-Ethernet_AdvancedWebServer](examples/Generic/Ethernet/STM32/STM32-Ethernet_AdvancedWebServer) example on **STM32F7 Nucleo-144 F767ZI and built-in LAN8742A Ethernet** to demonstrate the new non-blocking feature of WebSockets Server enabling WebServer and WebSockets Server to run concurrently.

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/blob/master/pics/Web_WS_Server_STM32.png">
</p>

2. This is the screenshot when running [SAMD-AdvancedWebServer](examples/Generic/WiFiNINA/SAMD/SAMD-AdvancedWebServer) example on **Arduino SAMD21 Nano-33-IoT and built-in WiFiNINA** to demonstrate the new non-blocking feature of WebSockets Server enabling WebServer and WebSockets Server to run concurrently.

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/blob/master/pics/Web_WS_Server_Nano_33_IoT.png">
</p>

---
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
 3. Add SSL support to SAMD21/SAMD51 and nRF52 using WiFiNINA.
 4. Support more non-compatible Ethernet Libraries such as Ethernet_Shield_W5200, EtherCard, EtherSia
 5. Add mDNS features.

### DONE

 1. Add support to **Arduino SAMD21 (ZERO, MKR, NANO_33_IOT, etc.)**
 2. Add support to **Adafruit SAMD21 (Itsy-Bitsy M0, Metro M0, Feather M0 Express, etc.)**.
 3. Add support to **Adafruit SAMD51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)**.
 4. Add support to **Adafruit nRF52 ( Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc.**.
 5. Add support to **WiFiNINA** using [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic).
 6. Add support to [`SINRIC`](https://sinric.com)
 7. Split each example into several manageable files.
 8. Add support to SAM DUE.
 9. Add support to **Ethernet W5x00**, using either [`Ethernet`](https://www.arduino.cc/en/Reference/Ethernet), [`Ethernet2`](https://github.com/khoih-prog/Ethernet2) or [`EthernetLarge`](https://github.com/OPEnSLab-OSU/EthernetLarge) library
10. Add support to **Ethernet ENC28J60**, using [`UIPEthernet`](https://github.com/UIPEthernet/UIPEthernet) library (v2.0.8 and v2.0.9)
11. Add support to **STM32F/L/H/G/WB/MP1.**
12. Add support to **Ethernet LAN8742A**, using [`STM32Ethernet library`](https://github.com/stm32duino/STM32Ethernet) and [`STM32duino_LwIP library`](https://github.com/stm32duino/LwIP).
13. Add support to **Seeeduino SAMD21/SAMD51: LoRaWAN, Zero, Femto M0, XIAO M0, Wio GPS Board, Wio Terminal, Grove UI Wireless, etc.**
14. Add **non-blocking WebSockets Server** feature to enable WS Server and WebServer running **concurrently**
15. Add support to **Ethernet ENC28J60**, using [`EthernetENC`](https://github.com/jandrassy/EthernetENC) library.

---
---

## Releases

### Releases v1.0.7

1. Add support to ENC28J60 Ethernet using **EthernetENC**.
2. Add Ethernet Library Patches for **UIPEthernet v2.0.9 and Ethernet2**
3. Update Platform.ini to support **PlatformIO 5.x owner-based dependency declaration**.

#### Releases v1.0.6

1. Add **non-blocking WebSockets Server** feature to enable WS Server and WebServer running **concurrently**. See [**Support as Http server and the Websockets server on Arduino DUE**](https://github.com/khoih-prog/WebSockets_Generic/issues/1) and [**Running Http and Websocket Servers concurrently**](https://github.com/khoih-prog/WebSockets2_Generic/issues/1). Thanks to bug report and persistence of [Jake](https://github.com/jakespeed1311).
2. Add non-blocking WebSockets Server and WebServer examples. 
3. Add Ethernet Library Patches
4. Add Arduino SAMD Packages_Patches to fix compiler errors when using [Standard Template Library STL](https://en.wikipedia.org/wiki/Standard_Template_Library)

#### New in v1.0.5

1. Sync with [ArduinoWebsockets v0.4.18](https://github.com/gilmaimon/ArduinoWebsockets/releases/tag/0.4.18) to fix ESP8266 SSL bug. See [Secured-Two-Way: Client certificate is not sent if used along with setTrustAnchors](https://github.com/gilmaimon/ArduinoWebsockets/issues/84)

#### New in v1.0.4

1. Add support to all **STM32F/L/H/G/WB/MP1 (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8, etc.)**
2. Add support to **Seeeduino SAMD21/SAMD51 boards (SEEED_WIO_TERMINAL, SEEED_FEMTO_M0, SEEED_XIAO_M0, Wio_Lite_MG126, WIO_GPS_BOARD, SEEEDUINO_ZERO, SEEEDUINO_LORAWAN, SEEED_GROVE_UI_WIRELESS, etc.)**
3. Add sample Packages_Patches for **STM32 stm32** (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8)
4. Add Packages' Patches for **Seeeduino SAMD** to enable displaying **BOARD_NAME**
5. Add many examples

#### New in v1.0.3

1. Add support to STM32F boards with built-in Ethernet such as :
  - **Nucleo-144 (F429ZI, F767ZI)**
  - **Discovery (STM32F746G-DISCOVERY)**
  - **All STM32 Boards with Built-in Ethernet LAN8742A**

2. Add support to **STM32F1,2,3,4,7 boards (with 64+K Flash)** using either **Ethernet W5x00, ENC28J60 or LAN8742A**
3. Add Packages' Patches to Adafruit nRF52, SAMD, Arduino SAMD to enable displaying BOARD_NAME
4. Enhance examples and update README.md

#### New in v1.0.2

1. Add support to **Ethernet ENC28J60, using UIPEthernet library.** for nRF52, SAMD21/SAMD51 and SAM DUE boards.

#### New in v1.0.1

1. Add support to **SAM DUE** boards.
2. Add support to **Ethernet W5x00, using either Ethernet, EthernetLarge or Ethernet2 library.**
3. Restructure code to provide flexibility to support many more WiFi/Ethernet modules/shields in the future. Please delete the *.cpp files, replaced by *.hpp files, in the src directory, if *.cpp files still exist after installing new version.

#### New in v1.0.0

1. Add support to **nRF52** boards, such as **AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc.**.
2. Add support to **SAMD51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)**.
3. Add support to **SAMD21 (ZERO, MKR, NANO_33_IOT, M0, M0 Pro, AdaFruit CIRCUITPLAYGROUND_EXPRESS, etc.)**.
4. Add Alexa / [`SINRIC`](https://sinric.com) examples and supports to those boards as well as ESP8266/ESP32
5. Add support to WiFiNINA using [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic).

---

### Issues ###

Submit issues to: [WebSockets2_Generic issues](https://github.com/khoih-prog/WebSockets2_Generic/issues)

---

### Contributions and thanks

1. Based on and modified from [Gil Maimon's ArduinoWebsockets](https://github.com/gilmaimon/ArduinoWebsockets)
2. Thanks to good work of [Miguel Alexandre Wisintainer](https://github.com/tcpipchip) for initiating, inspriring, working with, developing, debugging and testing. Without that, support to nRF52, especially **NINA_B302_ublox running as nRF52840 and NINA_B112_ublox running as nRF52832**, has never been started and finished. See [u-blox nina b](https://github.com/khoih-prog/WiFiNINA_Generic/issues/1)
3. Thanks to bug report and persistence of [Jake](https://github.com/jakespeed1311) to help identify and add **non-blocking WebSockets Server** feature to v1.0.6 to enable WS Server and WebServer running **concurrently**. See [**Support as Http server and the Websockets server on Arduino DUE**](https://github.com/khoih-prog/WebSockets_Generic/issues/1) and [**Running Http and Websocket Servers concurrently**](https://github.com/khoih-prog/WebSockets2_Generic/issues/1). 

<table>
  <tr>
    <td align="center"><a href="https://github.com/gilmaimon"><img src="https://github.com/gilmaimon.png" width="100px;" alt="gilmaimon"/><br /><sub><b>⭐️⭐️ Gil Maimon</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/tcpipchip"><img src="https://github.com/tcpipchip.png" width="100px;" alt="tcpipchip"/><br /><sub><b>⭐️ Miguel Wisintainer</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/jakespeed1311"><img src="https://github.com/jakespeed1311.png" width="100px;" alt="jakespeed1311"/><br /><sub><b>Jake</b></sub></a><br /></td>
  </tr> 
</table>

---

### Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License and credits ###

- Most of the credits go to original author [**Gil Maimon**](https://github.com/gilmaimon) as well as contributors in original library [ArduinoWebsockets Contributors](https://github.com/gilmaimon/ArduinoWebsockets#contributors)

- The library is licensed under [GPLv3.0](https://github.com/gilmaimon/ArduinoWebsockets/blob/master/LICENSE) and [MIT](https://github.com/khoih-prog/WebSockets2_Generic/blob/master/LICENSE)

- `base64` written by René Nyffenegger.

---

## Copyright

1. Copyright (c) 2019- Gil Maimon
2. Copyright (c) 2020- Khoi Hoang


