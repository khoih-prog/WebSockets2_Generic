## WebSockets2_Generic Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/WebSockets2_Generic.svg?)](https://www.ardu-badge.com/WebSockets2_Generic)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/WebSockets2_Generic.svg)](https://github.com/khoih-prog/WebSockets2_Generic/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/WebSockets2_Generic/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/WebSockets2_Generic.svg)](http://github.com/khoih-prog/WebSockets2_Generic/issues)


<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>


---
---

## Table of Contents

* [Why do we need this WebSockets2_Generic library](#why-do-we-need-this-websockets2_generic-library)
  * [Features](#features)
  * [Supported features of RFC6455](#supported-features-of-rfc6455)
  * [Supported features of RFC2616](#supported-features-of-RFC2616)
  * [Currently supported Boards](#currently-supported-boards)
  * [Currently supported WiFi shields/modules](#currently-supported-wifi-shieldsmodules)
  * [Currently supported Ethernet shields/modules](#currently-supported-ethernet-shieldsmodules)
* [Changelog](changelog.md) 
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Packages' Patches](#packages-patches)
  * [1. For Adafruit nRF52840 and nRF52832 boards](#1-for-adafruit-nRF52840-and-nRF52832-boards)
  * [2. For Teensy boards](#2-for-teensy-boards)
  * [3. For Arduino SAM DUE boards](#3-for-arduino-sam-due-boards)
  * [4. For Arduino SAMD boards](#4-for-arduino-samd-boards)
      * [For core version v1.8.10+](#for-core-version-v1810)
      * [For core version v1.8.9-](#for-core-version-v189-)
  * [5. For Adafruit SAMD boards](#5-for-adafruit-samd-boards)
  * [6. For Seeeduino SAMD boards](#6-for-seeeduino-samd-boards)
  * [7. For STM32 boards](#7-for-stm32-boards) 
    * [7.1. For STM32 boards to use LAN8720](#71-for-stm32-boards-to-use-lan8720)
    * [7.2. For STM32 boards to use Serial1](#72-for-stm32-boards-to-use-serial1)
  * [8. For RP2040-based boards using Earle Philhower arduino-pico core](#8-for-rp2040-based-boards-using-earle-philhower-arduino-pico-core)
    * [8.1. To use BOARD_NAME](#81-to-use-board_name)
    * [8.2. To avoid compile error relating to microsecondsToClockCycles](#82-to-avoid-compile-error-relating-to-microsecondstoclockcycles)
  * [9. For Portenta_H7 boards using Arduino IDE in Linux](#9-for-portenta_h7-boards-using-arduino-ide-in-linux)
  * [10. For RTL8720DN boards using AmebaD core](#10-for-rtl8720dn-boards-using-amebad-core)
  * [11. For SAMD21 and SAMD51 boards using ArduinoCore-fab-sam core](#11-For-SAMD21-and-SAMD51-boards-using-ArduinoCore-fab-sam-core)
  * [12. For Seeeduino RP2040 boards](#12-For-Seeeduino-RP2040-boards)
  * [13. For Seeeduino nRF52840 boards](#13-For-Seeeduino-nRF52840-boards)
* [Libraries' Patches](#libraries-patches)
  * [1. For application requiring 2K+ HTML page](#1-for-application-requiring-2k-html-page)
  * [2. For Ethernet library](#2-for-ethernet-library)
  * [3. For EthernetLarge library](#3-for-ethernetlarge-library)
  * [4. For Etherne2 library](#4-for-ethernet2-library)
  * [5. For Ethernet3 library](#5-for-ethernet3-library)
  * [6. For UIPEthernet library](#6-for-uipethernet-library)
  * [7. For fixing ESP32 compile error](#7-for-fixing-esp32-compile-error)
  * [8. For fixing ESP8266 compile error](#8-for-fixing-esp8266-compile-error)
* [Note for Platform IO using ESP32 LittleFS](#note-for-platform-io-using-esp32-littlefs) 
* [HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)](#howto-use-analogread-with-esp32-running-wifi-andor-bluetooth-btble)
  * [1. ESP32 has 2 ADCs, named ADC1 and ADC2](#1--esp32-has-2-adcs-named-adc1-and-adc2)
  * [2. ESP32 ADCs functions](#2-esp32-adcs-functions)
  * [3. ESP32 WiFi uses ADC2 for WiFi functions](#3-esp32-wifi-uses-adc2-for-wifi-functions)
* [HOWTO use STM32F4 with LAN8720](#howto-use-stm32f4-with-lan8720)
  * [1. Wiring](#1-wiring)
  * [2. HOWTO program using STLink V-2 or V-3](#2-howto-program-using-stlink-v-2-or-v-3)
  * [3. HOWTO use Serial Port for Debugging](#3-howto-use-serial-port-for-debugging)
* [Important Notes](#important-notes)
* [Basic Usage](#basic-usage)
  * [Client](#client)
    * [Creating a client and connecting to a server](#creating-a-client-and-connecting-to-a-server)
    * [Sending a message](#sending-a-message)
    * [Waiting for messages](#waiting-for-messages)
    * [HOWTO keep receiving messages](#howto-keep-receiving-messages)
  * [Server](#server)
    * [Creating a server and listening for connections](#creating-a-server-and-listening-for-connections)
    * [Accepting connections](#accepting-connections)
    * [Reading WebSockets Client messages using non-blocking mode (new from v1.0.6)](#reading-websockets-client-messages-using-non-blocking-mode-new-from-v106)
* [HOWTO use WiFiNINA module/shield with WiFiNINA_Generic library](#howto-use-wifinina-moduleshield-with-wifinina_generic-library)
* [For SAMD21/SAMD51, nRF52, SAM DUE using Ethernet W5x0 or ENC28J60](#for-samd21samd51-nrf52-sam-due-using-ethernet-w5x0-or-enc28j60)
* [For STM32F/L/H/G/WB/MP1 using Ethernet W5x0, ENC28J60, LAN8720 or LAN8742A](#for-stm32flhgwbmp1--using-ethernet-w5x0-enc28j60-or-lan8742a)
* [For Teensy 4.1, 4.0, 3.x using Ethernet W5x0, ENC28J60 or LAN8742A](#for-teensy-41-40-3x-using-ethernet-w5x0-enc28j60-or-lan8742a)
* [For Teensy 4.1 using NativeEthernet](#for-teensy-41-using-nativeethernet)
* [For Teensy 4.1 using QNEthernet](#for-teensy-41-using-qnethernet)
* [To use ESP8266/ESP32 native WiFi](#to-use-esp8266esp32-native-wifi)
* [To use RP2040W built-in WiFi](#To-use-RP2040W-built-in-WiFi)
* [Examples](#examples)
  * [For ESP32 boards](#for-esp32-boards)
  * [For ESP8266 boards](#for-esp8266-boards)
  * [For nRF52 boards using WiFiNINA](#for-nrf52-boards-using-wifinina)
  * [For SAMD21/SAMD51 boards using WiFiNINA](#for-samd21samd51-boards-using-wifinina)
  * [For SAMD21/SAMD51 boards using WiFi101](#for-samd21samd51-boards-using-wifi101)
  * [For STM32F/L/H/G/WB/MP1 boards using WiFiNINA](#for-stm32flhgwbmp1-boards-using-wifinina)
  * [For nRF52 boards using Ethernet (W5x00 or ENC28J60)](#for-nrf52-boards-using-ethernet-w5x00-or-enc28j60)
  * [For SAMD21/SAMD51 boards using Ethernet (W5x00 or ENC28J60)](#for-samd21samd51-boards-using-ethernet-w5x00-or-enc28j60)
  * [For SAM-DUE boards using Ethernet (W5x00 or ENC28J60)](#for-sam-due-boards-using-ethernet-w5x00-or-enc28j60)
  * [For STM32F/L/H/G/WB/MP1 boards using Ethernet (W5x00, ENC28J60 or LAN8742A)](#for-stm32flhgwbmp1-boards-using-ethernet-w5x00-enc28j60-or-lan8742a)
  * [For STM32F/L/H/G/WB/MP1 boards using Ethernet (LAN8720)](#for-stm32flhgwbmp1-boards-using-ethernet-lan8720)
  * [For Teensy boards using Ethernet (W5x00, ENC28J60 or LAN8742A). New in v1.1.0](#for-teensy-boards-using-ethernet-w5x00-enc28j60-or-lan8742a-new-in-v110)
  * [For Teensy 4.1 boards using NativeEthernet (KSZ8081MNX/KSZ8081RNB). New in v1.1.0](#for-teensy-41-boards-using-nativeethernet-ksz8081mnxksz8081rnb-new-in-v110)
  * [For RP2040 boards using Ethernet (W5x00 or ENC28J60)](#for-rp2040-boards-using-ethernet-w5x00-or-enc28j60).
  * [For WT32_ETH01 boards](#for-wt32_eth01-boards)
  * [For Teensy 4.1 boards using QNEthernet (KSZ8081MNX/KSZ8081RNB). New in v1.6.0](#for-teensy-41-boards-using-qnethernet-ksz8081mnxksz8081rnb-new-in-v160)
  * [For Portenta_H7 boards using Vision-shield Ethernet. New in v1.7.0](#for-portenta_h7-boards-using-vision-shield-ethernet-new-in-v170)
  * [For Portenta_H7 boards using Murata WiFi. New in v1.7.0](#for-portenta_h7-boards-using-murata-wifi-new-in-v170)
  * [For RP2040 boards using WiFiNINA. New in v1.8.0](#for-rp2040-boards-using-wifinina-new-in-v180)
  * [For ESP32 boards using Ethernet. New in v1.11.0](#for-ESP32-boards-using-Ethernet-new-in-v1110) **New**
  * [For RP2040W boards using built-in WiFi. New in v1.13.0](#for-RP2040W-boards-using-built-in-WiFi-new-in-v1130) **New**
* [Example SAMD-Client_SINRIC](#example-samd-client_sinric)
  * [1. File SAMD-Client_SINRIC.ino](#1-file-samd-client_sinricino)
  * [2. File defines.h](#2-file-definesh)
* [Using SINRIC Service](#using-sinric-service)
* [Binary Data](#binary-data)
* [SSL and WSS Support](#ssl-and-wss-support)
  * [ESP8266](#esp8266)
  * [ESP32](#esp32)
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
* [Screenshots](#screenshots)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License and credits](#license-and-credits)
* [Copyright](#copyright)


### Why do we need this [WebSockets2_Generic library](https://github.com/khoih-prog/WebSockets2_Generic)

#### Features

Many Web services require WebSockets library, which is so far written only for ESP8266/ESP32 boards. The ESP boards so far rely on the [**Markus Sattler's WebSockets Library**](https://github.com/Links2004/arduinoWebSockets) to connect to `Alexa` via `Sinric` or `SinricPro` skills.

This [**WebSockets2_Generic library**](https://github.com/khoih-prog/WebSockets2_Generic) is based on and modified from [**Gil Maimon's ArduinoWebSockets Library**](https://github.com/gilmaimon/ArduinoWebsockets) to provide support to many more boards, such as **WT32_ETH01 (ESP32 + LAN8720), Arduino SAMD21, Adafruit SAMD21/SAMD51, Seeeduino SAMD21/SAMD51, nRF52, STM32F/L/H/G/WB/MP1, Teensy, SAM DUE, Portenta_H7, etc.** and enable those boards to use WebSockets services, including voice-controlled Alexa along with Blynk. Those supported boards can also run **WebSockets Server.** The WebSockets can be used with **ESP’s WiFi, WiFiNINA, WiFi101, W5x00/ENC28J60/LAN8742A Ethernet, Teensy 4.1 NativeEthernet/QNEthernet, ESP8266/ESP32-AT modules/shields, Portenta_H7 WiFi/Ethernet, RP2040-based boards, such as Nano_RP2040_Connect, RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040, using WiFiNINA**.

Please see [the TinyWebsockets wiki](https://github.com/gilmaimon/TinyWebsockets/wiki) for roughly-accurate information about the API not covered here.

#### Supported features of RFC6455

 - text frame
 - binary frame
 - connection close
 - ping
 - pong
 - continuation frame
 
#### Supported features of RFC2616

 - Field names are `case-insensitive` as in [**Message Headers**](https://datatracker.ietf.org/doc/html/rfc2616#section-4.2)
 
 ---
 
#### Currently supported Boards

This [**WebSockets_Generic2** library](https://github.com/khoih-prog/WebSockets2_Generic) currently supports these following boards:

 1. **nRF52 boards**, such as **AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc.**
 
 2. **SAMD21**
  - Arduino SAMD21: ZERO, MKRs, NANO_33_IOT, etc.
  - Adafruit SAMD21 (M0): ItsyBitsy M0, Feather M0, Feather M0 Express, Metro M0 Express, Circuit Playground Express, Trinket M0, PIRkey, Hallowing M0, Crickit M0, etc.
  - Seeeduino:  LoRaWAN, Zero, Femto M0, XIAO M0, Wio GPS Board, etc.
  
 3. **SAMD51**
  - Adafruit SAMD51 (M4): Metro M4, Grand Central M4, ItsyBitsy M4, Feather M4 Express, Trellis M4, Metro M4 AirLift Lite, MONSTER M4SK Express, Hallowing M4, etc.
  - Seeeduino: Wio Terminal, Grove UI Wireless
  
 4. **SAM DUE** 
 5. **Teensy (4.1, 4.0, 3.6, 3.5, 3,2, 3.1, 3.0)**
 6. **STM32F/L/H/G/WB/MP1 boards (with 32+K Flash)**
  - Nucleo-144
  - Nucleo-64
  - Discovery
  - Generic STM32F0, STM32F1, STM32F2, STM32F3, STM32F4, STM32F7 (with 64+K Flash): x8 and up
  - STM32L0, STM32L1, STM32L4
  - STM32G0, STM32G4
  - STM32H7
  - STM32WB
  - STM32MP1
  - LoRa boards
  - 3-D printer boards
  - Generic Flight Controllers
  - Midatronics boards

 7. **ESP32, using either WiFi or Ethernet**
 8. **ESP8266**
 
 9. RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed) or [**Earle Philhower's arduino-pico** core](https://github.com/earlephilhower/arduino-pico).

10. **WT32_ETH01 boards** using ESP32-based boards and LAN8720 Ethernet

11. **Portenta_H7** using either `Murata WiFi` or `Vision-shield Ethernet`

12. **RP2040-based boards, such as Nano_RP2040_Connect, RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040**, using WiFiNINA or Ethernet

13. **RP2040W boards, such as RASPBERRY_PI_PICO_W**, using Cyw43439 WiFi or Ethernet


---

#### Currently supported WiFi shields/modules

1. WiFiNINA using [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic)
2. WiFi101 using [`WiFi101_Generic library`](https://github.com/khoih-prog/WiFi101_Generic)  **New**
3. U-Blox W101, W102 using [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic)
4. ESP32 and ESP8266 WiFi
5. **Portenta_H7 built-in Murata WiFi**
6. **RP2040W built-in CYW43439 WiFi**

---

#### Currently supported Ethernet shields/modules

1. W5x00 using [`Ethernet_Generic`](https://github.com/khoih-prog/Ethernet_Generic) library
2. W5x00 using [`Ethernet`](https://www.arduino.cc/en/Reference/Ethernet), [`EthernetLarge`](https://github.com/OPEnSLab-OSU/EthernetLarge), [`Ethernet2`](https://github.com/adafruit/Ethernet2) or [`Ethernet3`](https://github.com/sstaub/Ethernet3) library
3. ENC28J60 using [`EthernetENC`](https://github.com/jandrassy/EthernetENC) or [`UIPEthernet`](https://github.com/UIPEthernet/UIPEthernet) library
4. LAN8720 Ethernet used in `WT32_ETH01` boards
5. `LAN8742A or LAN8720` using [`STM32Ethernet`](https://github.com/stm32duino/STM32Ethernet) and [`LwIP`](https://github.com/stm32duino/LwIP) libraries.
6. `Teensy 4.1` built-in Ethernet using [`NativeEthernet`](https://github.com/vjmuzik/NativeEthernet) library
7. `Teensy 4.1` built-in Ethernet using [`QNEthernet`](https://github.com/ssilverman/QNEthernet) library
8. Portenta_H7 using Ethernet from [Portenta Vision shields](https://store-usa.arduino.cc/products/arduino-portenta-vision-shield-ethernet)
  
<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/raw/master/pics/Portenta_Vision.jpg">
</p>

---
---


## Prerequisites

 1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
 2. [`Arduino AVR core 1.8.6+`](https://github.com/arduino/ArduinoCore-avr) for Arduino (Use Arduino Board Manager) AVR boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-avr.svg)](https://github.com/arduino/ArduinoCore-avr/releases/latest)
 3. [`Teensy core v1.57+`](https://github.com/PaulStoffregen/cores) for Teensy (4.1, 4.0, 3.6, 3.5, 3,2, 3.1, 3.0) boards. [![GitHub release](https://img.shields.io/github/release/PaulStoffregen/cores.svg)](https://github.com/PaulStoffregen/cores/releases/latest)
 4. [`Arduino SAM DUE core v1.6.12+`](https://github.com/arduino/ArduinoCore-sam) for SAM DUE ARM Cortex-M3 boards.
 5. [`Arduino SAMD core 1.8.13+`](https://github.com/arduino/ArduinoCore-samd) for SAMD ARM Cortex-M0+ boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-samd.svg)](https://github.com/arduino/ArduinoCore-samd/releases/latest)
 6. [`Adafruit SAMD core 1.7.11+`](https://github.com/adafruit/ArduinoCore-samd) for SAMD ARM Cortex-M0+ and M4 boards (Nano 33 IoT, etc.). [![GitHub release](https://img.shields.io/github/release/adafruit/ArduinoCore-samd.svg)](https://github.com/adafruit/ArduinoCore-samd/releases/latest)
 7. [`Seeeduino SAMD core 1.8.3+`](https://github.com/Seeed-Studio/ArduinoCore-samd) for SAMD21/SAMD51 boards (XIAO M0, Wio Terminal, etc.). [![Latest release](https://img.shields.io/github/release/Seeed-Studio/ArduinoCore-samd.svg)](https://github.com/Seeed-Studio/ArduinoCore-samd/releases/latest/)
 8. [`Adafruit nRF52 v1.3.0+`](https://github.com/adafruit/Adafruit_nRF52_Arduino) for nRF52 boards such as Adafruit NRF52840_FEATHER, NRF52832_FEATHER, NRF52840_FEATHER_SENSE, NRF52840_ITSYBITSY, NRF52840_CIRCUITPLAY, NRF52840_CLUE, NRF52840_METRO, NRF52840_PCA10056, PARTICLE_XENON, **NINA_B302_ublox**, etc. [![GitHub release](https://img.shields.io/github/release/adafruit/Adafruit_nRF52_Arduino.svg)](https://github.com/adafruit/Adafruit_nRF52_Arduino/releases/latest)
 9. [`ESP32 Core 2.0.5+`](https://github.com/espressif/arduino-esp32) for ESP32-based boards. [![Latest release](https://img.shields.io/github/release/espressif/arduino-esp32.svg)](https://github.com/espressif/arduino-esp32/releases/latest/)
10. [`ESP8266 Core 3.0.2+`](https://github.com/esp8266/Arduino) for ESP8266-based boards. [![Latest release](https://img.shields.io/github/release/esp8266/Arduino.svg)](https://github.com/esp8266/Arduino/releases/latest/). To use ESP8266 core 2.7.1+ for LittleFS.
11. [`ArduinoCore-mbed mbed_rp2040, mbed_nano, mbed_portenta core 3.4.1+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino (Use Arduino Board Manager) **Portenta_H7, RP2040-based boards, such as Nano_RP2040_Connect, RASPBERRY_PI_PICO**. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)
12. [`Earle Philhower's arduino-pico core v2.6.4+`](https://github.com/earlephilhower/arduino-pico) for RP2040-based boards such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, etc. [![GitHub release](https://img.shields.io/github/release/earlephilhower/arduino-pico.svg)](https://github.com/earlephilhower/arduino-pico/releases/latest)
13. [`Arduino Core for STM32 v2.3.0+`](https://github.com/stm32duino/Arduino_Core_STM32) for STM32F/L/H/G/WB/MP1 boards. [![GitHub release](https://img.shields.io/github/release/stm32duino/Arduino_Core_STM32.svg)](https://github.com/stm32duino/Arduino_Core_STM32/releases/latest). Use STM32 core `v2.2.0` for LAN8720 or compile error.
14. [`Arduino AmebaD core 3.1.4+`](https://github.com/ambiot/ambd_arduino) for Realtek RTL8720DN, RTL8722DM and RTL8722CSM. [![GitHub release](https://img.shields.io/github/release/ambiot/ambd_arduino.svg)](https://github.com/ambiot/ambd_arduino/releases/latest)


15. [`WiFiNINA_Generic library v1.8.15-1+`](https://github.com/khoih-prog/WiFiNINA_Generic) if for WiFiNINA. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiNINA_Generic.svg?)](https://www.ardu-badge.com/WiFiNINA_Generic).
16. [`EthernetWebServer library v2.3.0+`](https://github.com/khoih-prog/EthernetWebServer) if necessary to use Ethernet modules/shields. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer.svg?)](https://www.ardu-badge.com/EthernetWebServer)
17. [`EthernetWebServer_STM32 library v1.5.0+`](https://github.com/khoih-prog/EthernetWebServer_STM32) if necessary to use Ethernet modules/shields. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer_STM32.svg?)](https://www.ardu-badge.com/EthernetWebServer_STM32)
18. [`WebServer_WT32_ETH01 library v1.5.1+`](https://github.com/khoih-prog/WebServer_WT32_ETH01) if necessary to use WT32_ETH01 boards. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WebServer_WT32_ETH01.svg?)](https://www.ardu-badge.com/WebServer_WT32_ETH01)
19. Depending on which Ethernet card you're using:
   - [`Ethernet_Generic library v2.7.1+`](https://github.com/khoih-prog/Ethernet_Generic) for W5100, W5200 and W5500/WIZ550io/WIZ850io/USR-ES1 with Wiznet W5500 chip.  [![GitHub release](https://img.shields.io/github/release/khoih-prog/Ethernet_Generic.svg)](https://github.com/khoih-prog/Ethernet_Generic/releases/latest)
   - [`EthernetENC library v2.0.3+`](https://github.com/jandrassy/EthernetENC) for ENC28J60. [![GitHub release](https://img.shields.io/github/release/jandrassy/EthernetENC.svg)](https://github.com/jandrassy/EthernetENC/releases/latest). **New and Better**
   - [`UIPEthernet library v2.0.12+`](https://github.com/UIPEthernet/UIPEthernet) for ENC28J60. [![GitHub release](https://img.shields.io/github/release/UIPEthernet/UIPEthernet.svg)](https://github.com/UIPEthernet/UIPEthernet/releases/latest)
   - [`STM32Ethernet library v1.3.0+`](https://github.com/stm32duino/STM32Ethernet) for built-in LAN8742A Ethernet on (Nucleo-144, Discovery). [![GitHub release](https://img.shields.io/github/release/stm32duino/STM32Ethernet.svg)](https://github.com/stm32duino/STM32Ethernet/releases/latest). To be used with [`LwIP library v2.1.2+`](https://github.com/stm32duino/LwIP). [![GitHub release](https://img.shields.io/github/release/stm32duino/LwIP.svg)](https://github.com/stm32duino/LwIP/releases/latest).
   - [`NativeEthernet Library version stable111+`](https://github.com/vjmuzik/NativeEthernet) for Teensy 4.1 built-in Ethernet.
   - [`QNEthernet Library version v0.17.0+`](https://github.com/ssilverman/QNEthernet) Teensy 4.1 built-in Ethernet. **New**
   
20. [`WiFiWebServer library v1.10.1+`](https://github.com/khoih-prog/WiFiWebServer) if necessary to use certain WiFi/WiFiNINA features. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiWebServer.svg?)](https://www.ardu-badge.com/WiFiWebServer)
21. [`FlashStorage_SAMD library v1.3.2+`](https://github.com/khoih-prog/FlashStorage_SAMD) for SAMD21 and SAMD51 boards (ZERO, MKR, NANO_33_IOT, M0, M0 Pro, AdaFruit Itsy-Bitsy M4, etc.) if necessary to use certain features. [![GitHub release](https://img.shields.io/github/release/khoih-prog/FlashStorage_SAMD.svg)](https://github.com/khoih-prog/FlashStorage_SAMD/releases/latest)
22. [`FlashStorage_STM32 library v1.2.0+`](https://github.com/khoih-prog/FlashStorage_STM32) for STM32F/L/H/G/WB/MP1 boards. [![GitHub release](https://img.shields.io/github/release/khoih-prog/FlashStorage_STM32.svg)](https://github.com/khoih-prog/FlashStorage_STM32/releases/latest) if necessary to use certain features.
23. [`DueFlashStorage library v1.0.0+`](https://github.com/sebnil/DueFlashStorage) for SAM DUE if necessary to use certain features. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/DueFlashStorage.svg?)](https://www.ardu-badge.com/DueFlashStorage).
24. [`Adafruit's LittleFS/InternalFS`](https://www.adafruit.com) for nRF52. Already included if you already installed Adafruit **nRF52 board package** from Boards Manager.
25. [`DoubleResetDetector_Generic v1.8.1+`](https://github.com/khoih-prog/DoubleResetDetector_Generic) if necessary to use some examples. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/DoubleResetDetector_Generic.svg?)](https://www.ardu-badge.com/DoubleResetDetector_Generic) if necessary to use certain features.
26. [`WiFi101_Generic Library v1.0.0+`](https://github.com/khoih-prog/WiFi101_Generic) to use SAMD MKR1000, etc. boards with WiFi101 to send large data. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFi101_Generic.svg?)](https://www.ardu-badge.com/WiFi101_Generic).
27. [`SinricPro_Generic v2.8.5+`](https://github.com/khoih-prog/SinricPro_Generic) if necessary to use some examples. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/SinricPro_Generic.svg?)](https://www.ardu-badge.com/SinricPro_Generic) if necessary to use certain features.

---
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

### VS Code & PlatformIO

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**WebSockets2_Generic** library](https://registry.platformio.org/libraries/khoih-prog/WebSockets2_Generic) by using [Library Manager](https://registry.platformio.org/libraries/khoih-prog/WebSockets2_Generic/installation). Search for **WebSockets2_Generic** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---
---

### Packages' Patches

#### 1. For Adafruit nRF52840 and nRF52832 boards

**To be able to compile, run and automatically detect and display BOARD_NAME on nRF52840/nRF52832 boards**, you have to copy the whole [nRF52 Packages_Patches](Packages_Patches/adafruit/hardware/nrf52/1.3.0) directory into Adafruit nRF52 directory (~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0). 

Supposing the Adafruit nRF52 version is 1.3.0. These files must be copied into the directory:
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Udp.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Print.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Print.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Udp.h`**

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z
These files must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Print.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Print.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`**

#### 2. For Teensy boards
 
 **To be able to compile and run on Teensy boards**, you have to copy the files in [**Packages_Patches for Teensy directory**](Packages_Patches/hardware/teensy/avr) into Teensy hardware directory (./arduino-1.8.19/hardware/teensy/avr/boards.txt). 

Supposing the Arduino version is 1.8.19. These files must be copied into the directory:

- `./arduino-1.8.19/hardware/teensy/avr/boards.txt`
- `./arduino-1.8.19/hardware/teensy/avr/cores/teensy/Stream.h`
- `./arduino-1.8.19/hardware/teensy/avr/cores/teensy3/Stream.h`
- `./arduino-1.8.19/hardware/teensy/avr/cores/teensy4/Stream.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
These files must be copied into the directory:

- `./arduino-x.yy.zz/hardware/teensy/avr/boards.txt`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy/Stream.h`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy3/Stream.h`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy4/Stream.h`

#### 3. For Arduino SAM DUE boards
 
 **To be able to compile and run on SAM DUE boards**, you have to copy the whole [SAM DUE](Packages_Patches/arduino/hardware/sam/1.6.12) directory into Arduino sam directory (~/.arduino15/packages/arduino/hardware/sam/1.6.12). 

Supposing the Arduino SAM core version is 1.6.12. This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/1.6.12/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/x.yy.zz/platform.txt`

#### 4. For Arduino SAMD boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Arduino SAMD (Nano-33-IoT, etc) boards***, you have to copy the whole [Arduino SAMD Packages_Patches](Packages_Patches/arduino/hardware/samd/1.8.13) directory into Arduino SAMD directory (~/.arduino15/packages/arduino/hardware/samd/1.8.13).
 
#### For core version v1.8.10+

Supposing the Arduino SAMD version is 1.8.13. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.13/platform.txt`

Whenever a new version is installed, remember to copy this files into the new version directory. For example, new version is x.yy.zz

This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/x.yy.zz/platform.txt`
 
#### For core version v1.8.9-

Supposing the Arduino SAMD version is 1.8.9. These files must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.9/platform.txt`
- ***`~/.arduino15/packages/arduino/hardware/samd/1.8.9/cores/arduino/Arduino.h`***

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z

These files must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/x.yy.z/platform.txt`
- ***`~/.arduino15/packages/arduino/hardware/samd/x.yy.z/cores/arduino/Arduino.h`***
 
 This is mandatory to fix the ***notorious Arduino SAMD compiler error***. See [Improve Arduino compatibility with the STL (min and max macro)](https://github.com/arduino/ArduinoCore-samd/pull/399)
 
```
 ...\arm-none-eabi\include\c++\7.2.1\bits\stl_algobase.h:243:56: error: macro "min" passed 3 arguments, but takes just 2
     min(const _Tp& __a, const _Tp& __b, _Compare __comp)
```

Whenever the above-mentioned compiler error issue is fixed with the new Arduino SAMD release, you don't need to copy the `Arduino.h` file anymore.

#### 5. For Adafruit SAMD boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Adafruit SAMD (Itsy-Bitsy M4, etc) boards***, you have to copy the whole [Adafruit SAMD Packages_Patches](Packages_Patches/adafruit/hardware/samd/1.7.11) directory into Adafruit samd directory (~/.arduino15/packages/adafruit/hardware/samd/1.7.11). 

Supposing the Adafruit SAMD core version is 1.7.11. These files must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/1.7.11/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/samd/1.7.11/cores/arduino/Print.h`
- `~/.arduino15/packages/adafruit/hardware/samd/1.7.11/cores/arduino/Print.cpp`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
These files must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/cores/arduino/Print.h`
- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/cores/arduino/Print.cpp`

#### 6. For Seeeduino SAMD boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Seeeduino SAMD (XIAO M0, Wio Terminal, etc) boards***, you have to copy the whole [Seeeduino SAMD Packages_Patches](Packages_Patches/Seeeduino/hardware/samd/1.8.3) directory into Seeeduino samd directory (~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3). 

Supposing the Seeeduino SAMD core version is 1.8.3. These files must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3/platform.txt`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3/cores/arduino/Arduino.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3/cores/arduino/Print.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3/cores/arduino/Print.cpp`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
These files must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/platform.txt`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Arduino.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Print.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Print.cpp`

#### 7. For STM32 boards

#### 7.1 For STM32 boards to use LAN8720

For `Generic STM32F4 series` boards, such as `STM32F407VE`, using `LAN8720`, please use STM32 core `v2.2.0` as breaking core `v2.3.0` creates the compile error.

---

To use LAN8720 on some STM32 boards 

- **Nucleo-144 (F429ZI, NUCLEO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG)**
- **Discovery (DISCO_F746NG)**
- **STM32F4 boards (BLACK_F407VE, BLACK_F407VG, BLACK_F407ZE, BLACK_F407ZG, BLACK_F407VE_Mini, DIYMORE_F407VGT, FK407M1)**

you have to copy the files [stm32f4xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/2.2.0/system/STM32F4xx) and [stm32f7xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/2.2.0/system/STM32F7xx) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/2.2.0/system) to overwrite the old files.

Supposing the STM32 stm32 core version is 2.2.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/2.2.0/system/STM32F4xx/stm32f4xx_hal_conf_default.h` for STM32F4.
- `~/.arduino15/packages/STM32/hardware/stm32/2.2.0/system/STM32F7xx/stm32f7xx_hal_conf_default.h` for Nucleo-144 STM32F7.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
these files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F4xx/stm32f4xx_hal_conf_default.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F7xx/stm32f7xx_hal_conf_default.h`


#### 7.2 For STM32 boards to use Serial1

**To use Serial1 on some STM32 boards without Serial1 definition (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8, etc.) boards**, you have to copy the files [STM32 variant.h](Packages_Patches/STM32/hardware/stm32/2.3.0) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/2.3.0). You have to modify the files corresponding to your boards, this is just an illustration how to do.

Supposing the STM32 stm32 core version is 2.3.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/2.3.0/variants/STM32F7xx/F765Z(G-I)T_F767Z(G-I)T_F777ZIT/NUCLEO_F767ZI/variant.h` for Nucleo-144 NUCLEO_F767ZI.
- `~/.arduino15/packages/STM32/hardware/stm32/2.3.0/variants/STM32L0xx/L052R(6-8)T_L053R(6-8)T_L063R8T/NUCLEO_L053R8/variant.h` for Nucleo-64 NUCLEO_L053R8.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
these files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/STM32F7xx/F765Z(G-I)T_F767Z(G-I)T_F777ZIT/NUCLEO_F767ZI/variant.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/STM32L0xx/L052R(6-8)T_L053R(6-8)T_L063R8T/NUCLEO_L053R8/variant.h`

#### 8. For RP2040-based boards using [Earle Philhower arduino-pico core](https://github.com/earlephilhower/arduino-pico)

#### 8.1 To use BOARD_NAME

 **To be able to automatically detect and display BOARD_NAME on RP2040-based boards (RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040, GENERIC_RP2040, etc) boards**, you have to copy the file [RP2040 platform.txt](Packages_Patches/rp2040/hardware/rp2040/1.4.0) into rp2040 directory (~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0). 

Supposing the rp2040 core version is 1.4.0. This file must be copied into the directory:

- `~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/rp2040/hardware/rp2040/x.yy.zz/platform.txt`

With core after v1.5.0, this step is not necessary anymore thanks to the PR [Add -DBOARD_NAME="{build.board}" #136](https://github.com/earlephilhower/arduino-pico/pull/136).

#### 8.2 To avoid compile error relating to microsecondsToClockCycles

Some libraries, such as [Adafruit DHT-sensor-library](https://github.com/adafruit/DHT-sensor-library), require the definition of microsecondsToClockCycles(). **To be able to compile and run on RP2040-based boards**, you have to copy the files in [**RP2040 Arduino.h**](Packages_Patches/rp2040/hardware/rp2040/1.4.0/cores/rp2040/Arduino.h) into rp2040 directory (~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0).

Supposing the rp2040 core version is 1.4.0. This file must be copied to replace:

- `~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0/cores/rp2040/Arduino.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied to replace:

- `~/.arduino15/packages/rp2040/hardware/rp2040/x.yy.zz/cores/rp2040/Arduino.h`

With core after v1.5.0, this step is not necessary anymore thanks to the PR [Add defs for compatibility #142](https://github.com/earlephilhower/arduino-pico/pull/142).


#### 9. For Portenta_H7 boards using Arduino IDE in Linux

  **To be able to upload firmware to Portenta_H7 using Arduino IDE in Linux (Ubuntu, etc.)**, you have to copy the file [portenta_post_install.sh](Packages_Patches/arduino/hardware/mbed_portenta/3.4.1/portenta_post_install.sh) into mbed_portenta directory (~/.arduino15/packages/arduino/hardware/mbed_portenta/3.4.1/portenta_post_install.sh). 
  
  Then run the following command using `sudo`
  
```
$ cd ~/.arduino15/packages/arduino/hardware/mbed_portenta/3.4.1
$ chmod 755 portenta_post_install.sh
$ sudo ./portenta_post_install.sh
```

This will create the file `/etc/udev/rules.d/49-portenta_h7.rules` as follows:

```
# Portenta H7 bootloader mode UDEV rules

SUBSYSTEMS=="usb", ATTRS{idVendor}=="2341", ATTRS{idProduct}=="035b", GROUP="plugdev", MODE="0666"
```

Supposing the ArduinoCore-mbed core version is 3.4.1. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/3.4.1/portenta_post_install.sh`

Whenever a new version is installed, remember to copy this files into the new version directory. For example, new version is x.yy.zz

This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/x.yy.zz/portenta_post_install.sh`


#### 10. For RTL8720DN boards using AmebaD core
 
 To avoid compile error relating to PROGMEM, you have to copy the file [Realtek AmebaD core pgmspace.h](Packages_Patches/realtek/hardware/AmebaD/3.1.4/cores/ambd/avr/pgmspace.h) into Realtek AmebaD directory (~/.arduino15/packages/realtek/hardware/AmebaD/3.1.4/cores/ambd/avr/pgmspace.h). 

Supposing the Realtek AmebaD core version is 3.1.4. This file must be copied into the directory:

- `~/.arduino15/packages/realtek/hardware/AmebaD/3.1.4/cores/ambd/avr/pgmspace.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/realtek/hardware/AmebaD/x.yy.zz/cores/ambd/avr/pgmspace.h`


#### 11. For SAMD21 and SAMD51 boards using ArduinoCore-fab-sam core
 
 To avoid compile error relating to SAMD21/SAMD51, you have to copy the file [ArduinoCore-fab-sam core pgmspace.h](Packages_Patches/Fab_SAM_Arduino/hardware/samd/1.9.0/boards.txt) into `ArduinoCore-fab-sam` samd directory (~/.arduino15/packages/Fab_SAM_Arduino/hardware/samd/1.9.0/boards.txt). 

Supposing the `ArduinoCore-fab-sam` samd core version is 1.9.0. This file must be copied into the directory:

- `~/.arduino15/packages/Fab_SAM_Arduino/hardware/samd/1.9.0/boards.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/Fab_SAM_Arduino/hardware/samd/x.yy.zz/boards.txt`


#### 12. For Seeeduino RP2040 boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Seeeduino RP2040 (XIAO RP2040, Wio RP2040 Mini) boards***, you have to copy the whole [Seeeduino RP2040 Packages_Patches](Packages_Patches/Seeeduino/hardware/rp2040/2.7.2) directory into Seeeduino samd directory (~/.arduino15/packages/Seeeduino/hardware/rp2040/2.7.2). 

Supposing the Seeeduino RP2040 core version is 2.7.2. These files must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/rp2040/2.7.2/boards.txt`
- `~/.arduino15/packages/Seeeduino/hardware/rp2040/2.7.2/variants/Seeed_XIAO_RP2040/pins_arduino.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
These files must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/boards.txt`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/variants/Seeed_XIAO_RP2040/pins_arduino.h`


---

#### 13. For Seeeduino nRF52840 boards

**To be able to compile and run on Xiao nRF52840 boards**, you have to copy the whole [nRF52 1.0.0](Packages_Patches/Seeeduino/hardware/nrf52/1.0.0) directory into Seeeduino nRF52 directory (~/.arduino15/packages/Seeeduino/hardware/nrf52/1.0.0). 

Supposing the Seeeduino nRF52 version is 1.0.0. These files must be copied into the directory:

- **`~/.arduino15/packages/Seeeduino/hardware/nrf52/1.0.0/platform.txt`**
- **`~/.arduino15/packages/Seeeduino/hardware/nrf52/1.0.0/cores/nRF5/Print.h`**
- **`~/.arduino15/packages/Seeeduino/hardware/nrf52/1.0.0/cores/nRF5/Print.cpp`**
- **`~/.arduino15/packages/Seeeduino/hardware/nrf52/1.0.0/cores/nRF5/Udp.h`**

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z
These files must be copied into the directory:

- **`~/.arduino15/packages/Seeeduino/hardware/nrf52/x.yy.z/platform.txt`**
- **`~/.arduino15/packages/Seeeduino/hardware/nrf52/x.yy.z/cores/nRF5/Print.h`**
- **`~/.arduino15/packages/Seeeduino/hardware/nrf52/x.yy.z/cores/nRF5/Print.cpp`**
- **`~/.arduino15/packages/Seeeduino/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`**



---
---

### Libraries' Patches

#### 1. For application requiring 2K+ HTML page

If your application requires 2K+ HTML page, the current [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) must be modified if you are using W5200/W5500 Ethernet shields. W5100 is not supported for 2K+ buffer. If you use boards requiring different CS/SS pin for W5x00 Ethernet shield, for example ESP32, ESP8266, nRF52, etc., you also have to modify the following libraries to be able to specify the CS/SS pin correctly.

#### 2. For Ethernet library

To fix [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet), just copy these following files into the [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) directory to overwrite the old files:
- [Ethernet.h](LibraryPatches/Ethernet/src/Ethernet.h)
- [Ethernet.cpp](LibraryPatches/Ethernet/src/Ethernet.cpp)
- [EthernetServer.cpp](LibraryPatches/Ethernet/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/Ethernet/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/Ethernet/src/utility/w5100.cpp)

You can also use the forked and modified library at [Patched Ethernet](https://github.com/khoih-prog/Ethernet)

#### 3. For EthernetLarge library

To fix [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge), just copy these following files into the [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge) directory to overwrite the old files:
- [EthernetLarge.h](LibraryPatches/EthernetLarge/src/EthernetLarge.h)
- [EthernetLarge.cpp](LibraryPatches/EthernetLarge/src/EthernetLarge.cpp)
- [EthernetServer.cpp](LibraryPatches/EthernetLarge/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/EthernetLarge/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/EthernetLarge/src/utility/w5100.cpp)

You can also use the forked and modified library at [Patched EthernetLarge](https://github.com/khoih-prog/EthernetLarge)

#### 4. For Ethernet2 library

To fix [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2), just copy these following files into the [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2) directory to overwrite the old files:

- [Ethernet2.h](LibraryPatches/Ethernet2/src/Ethernet2.h)
- [Ethernet2.cpp](LibraryPatches/Ethernet2/src/Ethernet2.cpp)

To add UDP Multicast support, necessary for the [**UPnP_Generic library**](https://github.com/khoih-prog/UPnP_Generic):

- [EthernetUdp2.h](LibraryPatches/Ethernet2/src/EthernetUdp2.h)
- [EthernetUdp2.cpp](LibraryPatches/Ethernet2/src/EthernetUdp2.cpp)

You can also use the forked and modified library at [Patched Ethernet2](https://github.com/khoih-prog/Ethernet2)

#### 5. For Ethernet3 library

5. To fix [`Ethernet3 library`](https://github.com/sstaub/Ethernet3), just copy these following files into the [`Ethernet3 library`](https://github.com/sstaub/Ethernet3) directory to overwrite the old files:
- [Ethernet3.h](LibraryPatches/Ethernet3/src/Ethernet3.h)
- [Ethernet3.cpp](LibraryPatches/Ethernet3/src/Ethernet3.cpp)

You can also use the forked and modified library at [Patched Ethernet3](https://github.com/khoih-prog/Ethernet3)

#### 6. For UIPEthernet library

***To be able to compile and run on nRF52 boards with ENC28J60 using UIPEthernet library***, you have to copy these following files into the UIPEthernet `utility` directory to overwrite the old files:

- [UIPEthernet.h](LibraryPatches/UIPEthernet/UIPEthernet.h)
- [UIPEthernet.cpp](LibraryPatches/UIPEthernet/UIPEthernet.cpp)
- [Enc28J60Network.h](LibraryPatches/UIPEthernet/utility/Enc28J60Network.h)
- [Enc28J60Network.cpp](LibraryPatches/UIPEthernet/utility/Enc28J60Network.cpp)

#### 7. For fixing ESP32 compile error

To fix [`ESP32 compile error`](https://github.com/espressif/arduino-esp32), just copy the following file into the [`ESP32`](https://github.com/espressif/arduino-esp32) cores/esp32 directory (e.g. ./arduino-1.8.13/hardware/espressif/cores/esp32) to overwrite the old file:
- [Server.h](LibraryPatches/esp32/cores/esp32/Server.h)

#### 8. For fixing ESP8266 compile error

To fix `ESP8266 compile error` such as

```cpp
error: 'class EthernetClass' has no member named 'init'
Ethernet.init (USE_THIS_SS_PIN);
```

just rename the following file in ./arduino-1.8.13/hardware/esp8266com/esp8266/libraries/Ethernet directory

- From `Ethernet.h` to `Ethernet_ESP8266.h`

---
---

### Note for Platform IO using ESP32 LittleFS

#### Necessary only for esp32 core v1.0.6-

From esp32 core v1.0.6+, [`LittleFS_esp32 v1.0.6`](https://github.com/lorol/LITTLEFS) has been included and this step is not necessary anymore.

In Platform IO, to fix the error when using [`LittleFS_esp32 v1.0`](https://github.com/lorol/LITTLEFS) for ESP32-based boards with ESP32 core v1.0.4- (ESP-IDF v3.2-), uncomment the following line

from

```cpp
//#define CONFIG_LITTLEFS_FOR_IDF_3_2   /* For old IDF - like in release 1.0.4 */
```

to

```cpp
#define CONFIG_LITTLEFS_FOR_IDF_3_2   /* For old IDF - like in release 1.0.4 */
```

It's advisable to use the latest [`LittleFS_esp32 v1.0.5+`](https://github.com/lorol/LITTLEFS) to avoid the issue.

Thanks to [Roshan](https://github.com/solroshan) to report the issue in [Error esp_littlefs.c 'utime_p'](https://github.com/khoih-prog/ESPAsync_WiFiManager/issues/28) 

---
---

### HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)

Please have a look at [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to have more detailed description and solution of the issue.

#### 1.  ESP32 has 2 ADCs, named ADC1 and ADC2

#### 2. ESP32 ADCs functions

- `ADC1` controls ADC function for pins **GPIO32-GPIO39**
- `ADC2` controls ADC function for pins **GPIO0, 2, 4, 12-15, 25-27**

#### 3.. ESP32 WiFi uses ADC2 for WiFi functions

Look in file [**adc_common.c**](https://github.com/espressif/esp-idf/blob/master/components/driver/adc_common.c#L61)

> In `ADC2`, there're two locks used for different cases:
> 1. lock shared with app and Wi-Fi:
>    ESP32:
>         When Wi-Fi using the `ADC2`, we assume it will never stop, so app checks the lock and returns immediately if failed.
>    ESP32S2:
>         The controller's control over the `ADC` is determined by the arbiter. There is no need to control by lock.
> 
> 2. lock shared between tasks:
>    when several tasks sharing the `ADC2`, we want to guarantee
>    all the requests will be handled.
>    Since conversions are short (about 31us), app returns the lock very soon,
>    we use a spinlock to stand there waiting to do conversions one by one.
> 
> adc2_spinlock should be acquired first, then adc2_wifi_lock or rtc_spinlock.


- In order to use `ADC2` for other functions, we have to **acquire complicated firmware locks and very difficult to do**
- So, it's not advisable to use `ADC2` with WiFi/BlueTooth (BT/BLE).
- Use `ADC1`, and pins GPIO32-GPIO39
- If somehow it's a must to use those pins serviced by `ADC2` (**GPIO0, 2, 4, 12, 13, 14, 15, 25, 26 and 27**), use the **fix mentioned at the end** of [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to work with ESP32 WiFi/BlueTooth (BT/BLE).

---
---

### HOWTO use STM32F4 with LAN8720

#### 1. Wiring

This is the Wiring for STM32F4 (BLACK_F407VE, etc.) using LAN8720


|LAN8720 PHY|<--->|STM32F4|
|:-:|:-:|:-:|
|TX1|<--->|PB_13|
|TX_EN|<--->|PB_11|
|TX0|<--->|PB_12|
|RX0|<--->|PC_4|
|RX1|<--->|PC_5|
|nINT/RETCLK|<--->|PA_1|
|CRS|<--->|PA_7|
|MDIO|<--->|PA_2|
|MDC|<--->|PC_1|
|GND|<--->|GND|
|VCC|<--->|+3.3V|

---

#### 2. HOWTO program using STLink V-2 or V-3

Connect as follows. To program, use **STM32CubeProgrammer** or Arduino IDE with 

- **U(S)ART Support: "Enabled (generic Serial)"**
- **Upload Method : "STM32CubeProgrammer (SWD)"**


|STLink|<--->|STM32F4|
|:-:|:-:|:-:|
|SWCLK|<--->|SWCLK|
|SWDIO|<--->|SWDIO|
|RST|<--->|NRST|
|GND|<--->|GND|
|5v|<--->|5V|


<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/raw/master/pics/STM32F407VET6.png">
</p>

---

#### 3. HOWTO use Serial Port for Debugging

Connect FDTI (USB to Serial) as follows:

|FDTI|<--->|STM32F4|
|:-:|:-:|:-:|
|RX|<--->|TX=PA_9|
|TX|<--->|RX=PA_10|
|GND|<--->|GND|

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
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/raw/master/pics/ICSP_connector.jpg">
</p>

5. For **RP2040** using [`Arduino mbed_rp2040 core`](https://github.com/arduino/ArduinoCore-mbed), use the SPI's  pin as follows:

  - SS/CS     = 5
  - SPI_MOSI  = 3
  - SPI_MISO  = 4
  - SPI_SCK   = 2
  
6. For **RP2040** using [`Earle Philhower's arduino-pico core`](https://github.com/earlephilhower/arduino-pico), use the SPI's  pin as follows:

  - SS/CS     = 17
  - SPI_MOSI  = 19
  - SPI_MISO  = 16
  - SPI_SCK   = 18
  
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

2. Using normal callback function

```cpp
// run callback when events are occurring
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


#### HOWTO keep receiving messages:

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

Using this new feature to enable doing other tasks in the loop(), such as `WebServer`, control tasks, etc.
Server, using library version before `v1.0.6`, can only read Client messages in blocking mode. Therefore, the WebSocket Server can't hang, waiting for Client, and block all other tasks from running.

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

Please test using one of these following new examples with `v1.0.6` and `v1.0.5-` to see the blocking effects. Please remember to change in loop() from

```cpp
WebsocketsMessage msg = client.readNonBlocking();
```

to

```cpp
WebsocketsMessage msg = client.readBlocking();
```

as **client.readNonBlocking() is a new function in v1.0.6+.**

##### For ESP32/ESP8266

1. [Esp32-AdvancedWebServer](examples/ESP32/Esp32-AdvancedWebServer) using ESP32
2. [Esp8266-AdvancedWebServer](examples/ESP8266/Esp8266-AdvancedWebServer) using ESP8266

##### For WT32_ETH01

1. [WT32_ETH01_AdvancedWebServer](examples/WT32_ETH01/WT32_ETH01_AdvancedWebServer) using WT32_ETH01

##### For WiFiNINA

3. [SAMD-AdvancedWebServer](examples/Generic/WiFiNINA/SAMD/SAMD-AdvancedWebServer) using Nano-33-IoT
4. [nRF52-AdvancedWebServer](examples/Generic/WiFiNINA/nRF52/nRF52-AdvancedWebServer) using Adafruit nRF52 NRF52840_FEATHER_EXPRESS, NINA_B302_ublox and WiFiNINA W102 module.
5. [STM32-AdvancedWebServer](examples/Generic/WiFiNINA/STM32/STM32-AdvancedWebServer) using STM32 Nucleo-64 L053R8, STM32F4 and WiFiNINA W102 module.


##### For W5x00, ENC28J60 or LAN8742A Ethernet

 6. [SAMDUE-Ethernet_AdvancedWebServer](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet_AdvancedWebServer) using SAM DUE and W5100 Ethernet
 7. [STM32-Ethernet_AdvancedWebServer](examples/Generic/Ethernet/STM32/STM32-Ethernet_AdvancedWebServer) using STM32F7 Nucleo-144 F676ZI and built-in LAN8742A Ethernet.
 8. [SAMD-Ethernet_AdvancedWebServer](examples/Generic/Ethernet/SAMD/SAMD-Ethernet_AdvancedWebServer) using Adafruit SAMD51 Itsy_Bitsy_M4, Seeeduino SAMD21 XIAO_M0 and W5500 Ethernet.
 9. [nRF52-Ethernet_AdvancedWebServer](examples/Generic/Ethernet/nRF52/nRF52-Ethernet_AdvancedWebServer) using Adafruit nRF52 NRF52840_FEATHER_EXPRESS, NINA_B302_ublox and W5500 Ethernet.
10. [Teensy-Ethernet_AdvancedWebServer](examples/Generic/Ethernet/Teensy/Teensy-Ethernet_AdvancedWebServer) using Teensy and W5500 Ethernet.

---
---

### HOWTO use WiFiNINA module/shield with WiFiNINA_Generic library

```cpp
#define WEBSOCKETS_USE_WIFININA           true
```

---

###  For SAMD21/SAMD51, nRF52, SAM DUE, ESP32 using Ethernet W5x0 or ENC28J60

#### To use Ethernet W5x00 module/shield with Ethernetx library

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/raw/master/pics/W5500.jpg">
</p>

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/raw/master/pics/W5500_1.jpg">
</p>

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/raw/master/pics/W5100.jpg">
</p>

#### 1. To use Ethernet `W5x00` module/shield with one of the Ethernet libraries

```cpp
#define WEBSOCKETS_USE_ETHERNET           true
```

 - To use `W5x00` module/shield with `Ethernet` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET_GENERIC              true
#define USE_ETHERNET_ENC                  false
#define USE_UIP_ETHERNET                  false
```


#### 2. To use Ethernet `ENC28J60` module/shield with `UIPEthernet` library

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/raw/master/pics/ENC28J60.jpg">
</p>

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET_GENERIC              false
#define USE_ETHERNET_ENC                  false
#define USE_UIP_ETHERNET                  true
```

#### 3. To use Ethernet `ENC28J60` module/shield with new `EthernetENC` library

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/raw/master/pics/ENC28J60.jpg">
</p>

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET_GENERIC              false
#define USE_ETHERNET_ENC                  true
#define USE_UIP_ETHERNET                  false
```

#### 3. It's much easier just add to the sketch

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

// Just select one to be true. If all is false, default is Ethernet. 
// If more than one are true, the priority is USE_ETHERNET_GENERIC, USE_ETHERNET2, USE_ETHERNET_ENC, USE_UIP_ETHERNET
#define USE_ETHERNET_GENERIC          true
#define USE_ETHERNET_ENC              false
#define USE_UIP_ETHERNET              false

#if USE_ETHERNET_GENERIC
  // Also default to Ethernet_Generic library
  #include <Ethernet_Generic.h>
  #define ETHERNET_TYPE               "W5x00 and Ethernet_Generic Library"
#elif USE_ETHERNET_ENC
  #include <EthernetENC.h>
  #define ETHERNET_TYPE               "ENC28J60 and EthernetENC Library"  
#elif USE_UIP_ETHERNET
  #include <UIPEthernet.h>
  #include <utility/logging.h> 
  #define ETHERNET_TYPE               "ENC28J60 and UIPEthernet Library"
#else
  // Default to Ethernet_Generic library
  #include <Ethernet_Generic.h>
  #define ETHERNET_TYPE               "W5x00 and Ethernet_Generic Library"
#endif

#ifndef USE_THIS_SS_PIN
  #define USE_THIS_SS_PIN   10    // For other boards
#endif
```

---

###  For STM32F/L/H/G/WB/MP1  using Ethernet W5x0, ENC28J60 or LAN8742A

#### To use Ethernet W5x00 module/shield with Ethernetx library

#### 1. To use Ethernet `W5x00` module/shield with Ethernet_Generic libraries


```cpp
#define WEBSOCKETS_USE_ETHERNET           true
```

 - To use `W5x00` module/shield with `Ethernet_Generic` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_LAN8742A_ETHERNET             false
#define USING_LAN8720                     false
#define USE_ETHERNET_GENERIC              true
#define USE_ETHERNET_ENC                  false
#define USE_UIP_ETHERNET                  false
```

#### 2. To use Ethernet `ENC28J60` module/shield with `UIPEthernet` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_LAN8742A_ETHERNET             false
#define USING_LAN8720                     false
#define USE_ETHERNET_GENERIC              false
#define USE_ETHERNET_ENC                  false
#define USE_UIP_ETHERNET                  true
```

#### 3. To use Ethernet `ENC28J60` module/shield with new `EthernetENC` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_LAN8742A_ETHERNET             false
#define USING_LAN8720                     false
#define USE_ETHERNET_GENERIC              false
#define USE_ETHERNET_ENC                  true
#define USE_UIP_ETHERNET                  false
```

#### 4. To use Ethernet `LAN8742A` built-in module/shield with `STM32Ethernet` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_LAN8742A_ETHERNET             true
#define USING_LAN8720                     false
#define USE_ETHERNET_GENERIC              false
#define USE_ETHERNET_ENC                  false
#define USE_UIP_ETHERNET                  false
```

#### 5. To use Ethernet `LAN8720` module/shield with `STM32Ethernet` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_LAN8742A_ETHERNET             false
#define USING_LAN8720                     true
#define USE_ETHERNET_GENERIC              false
#define USE_ETHERNET_ENC                  false
#define USE_UIP_ETHERNET                  false
```

#### 6. It's much easier just add to the sketch

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

// Just select one to be true. If all is false, default is Ethernet. 
// If more than one are true, the priority is USE_LAN8742A_ETHERNET, USE_ETHERNET_GENERIC, USE_ETHERNET_ENC, USE_UIP_ETHERNET
#define USING_LAN8720                 true
#define USE_LAN8742A_ETHERNET         false
#define USE_ETHERNET_GENERIC          false
#define USE_ETHERNET_ENC              false
#define USE_UIP_ETHERNET              false

#if ( USE_LAN8742A_ETHERNET  || USING_LAN8720 )
  #define USE_BUILTIN_ETHERNET        true
  #include <LwIP.h>
  #include <STM32Ethernet.h>
  #if USING_LAN8720
    #define ETHERNET_TYPE             "LAN8720 and STM32Ethernet Library"
  #else
    #define ETHERNET_TYPE             "LAN8742A and STM32Ethernet Library"
  #endif
#elif USE_ETHERNET_GENERIC
  // Also default to Ethernet_Generic library
  #include <Ethernet_Generic.h>
  #define ETHERNET_TYPE               "W5x00 and Ethernet_Generic Library"
#elif USE_ETHERNET_ENC
  #include <EthernetENC.h>
  #define ETHERNET_TYPE               "ENC28J60 and EthernetENC Library"  
#elif USE_UIP_ETHERNET
  #include <UIPEthernet.h>
  #include <utility/logging.h> 
  #define ETHERNET_TYPE               "ENC28J60 and UIPEthernet Library" 
#else
  // Default to Ethernet_Generic library
  #include <Ethernet_Generic.h>
  #define ETHERNET_TYPE               "W5x00 and Ethernet_Generic Library"
#endif

#ifndef USE_THIS_SS_PIN
  #define USE_THIS_SS_PIN   10    // For other boards
#endif
```

---

###  For Teensy 4.1, 4.0, 3.x using Ethernet W5x0, ENC28J60 or LAN8742A

#### To use Ethernet W5x00 module/shield with Ethernet_Generic library

#### 1. To use Ethernet `W5x00` module/shield with one of the Ethernet libraries

```cpp
#define WEBSOCKETS_USE_ETHERNET           true
```

 - To use `W5x00` module/shield with `Ethernet_Generic` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET_GENERIC              true
#define USE_ETHERNET_ENC                  false
#define USE_UIP_ETHERNET                  false
#define USE_NATIVE_ETHERNET               false
```

#### 2. To use Ethernet `ENC28J60` module/shield with `UIPEthernet` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET_GENERIC              false
#define USE_ETHERNET_ENC                  false
#define USE_UIP_ETHERNET                  true
#define USE_NATIVE_ETHERNET               false
```

#### 3. To use Ethernet `ENC28J60` module/shield with new `EthernetENC` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET_GENERIC              false
#define USE_ETHERNET_ENC                  true
#define USE_UIP_ETHERNET                  false
#define USE_NATIVE_ETHERNET               false
```

#### 4. To use Teensy 4.1 NativeEthernet built-in module/shield with `NativeEthernet` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET_GENERIC              false
#define USE_ETHERNET_ENC                  false
#define USE_UIP_ETHERNET                  false
#define USE_NATIVE_ETHERNET               true
```

#### 5. It's much easier just add to the sketch

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

// Just select one to be true. If all is false, default is Ethernet. 
// If more than one are true, the priority is USE_NATIVE_ETHERNET, USE_ETHERNET_GENERIC, USE_ETHERNET_ENC, USE_UIP_ETHERNET
#define USE_ETHERNET_GENERIC          true
#define USE_ETHERNET_ENC              false
#define USE_UIP_ETHERNET              false
#define USE_NATIVE_ETHERNET           false

#if ( defined(__IMXRT1062__) && defined(ARDUINO_TEENSY41) && USE_NATIVE_ETHERNET )
  // Also default to Ethernet library
  #include <NativeEthernet.h>
  #define ETHERNET_TYPE               "Teensy 4.1 NativeEthernet Library"
#elif USE_ETHERNET_GENERIC
  // Also default to Ethernet_Generic library
  #include <Ethernet_Generic.h>
  #define ETHERNET_TYPE               "W5x00 and Ethernet_Generic Library"
#elif USE_ETHERNET_ENC
  #include <EthernetENC.h>
  #define ETHERNET_TYPE               "ENC28J60 and EthernetENC Library"  
#elif USE_UIP_ETHERNET
  #include <UIPEthernet.h>
  #include <utility/logging.h> 
  #define ETHERNET_TYPE               "ENC28J60 and UIPEthernet Library" 
#else
  // Default to Ethernet_Generic library
  #include <Ethernet_Generic.h>
  #define ETHERNET_TYPE               "W5x00 and Ethernet_Generic Library"
#endif

#ifndef USE_THIS_SS_PIN
  #define USE_THIS_SS_PIN   10    // For other boards
#endif
```

---
---

###  For Teensy 4.1 using NativeEthernet

Just as simple as:


```cpp
#define WEBSOCKETS_USE_ETHERNET     true

#define USE_NATIVE_ETHERNET         true
#define USE_QN_ETHERNET             false
```

---
---

###  For Teensy 4.1 using QNEthernet

Just as simple as:


```cpp
#define WEBSOCKETS_USE_ETHERNET     true

#define USE_NATIVE_ETHERNET         false
#define USE_QN_ETHERNET             true
```

---

### To use ESP8266/ESP32 native WiFi

Default is using `ESP8266/ESP32 native WiFi`. You don't need to do anything special.

---

### To use RP2040W built-in WiFi

```cpp
#define WEBSOCKETS_USE_RP2040W            true
#define USE_RP2040W_WIFI                  true
#define USE_WIFI_NINA                     false
```

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
7. [Esp32-AdvancedWebServer](examples/ESP32/Esp32-AdvancedWebServer)
8. [InSecured-Esp32-Client](examples/ESP32/InSecured-Esp32-Client). **New**

#### For ESP8266 boards

1. [Esp8266-Client](examples/ESP8266/Esp8266-Client)
2. [Minimal-Esp8266-Client](examples/ESP8266/Minimal-Esp8266-Client)
3. [Secured-Esp8266-Client](examples/ESP8266/Secured-Esp8266-Client)
4. [SecuredTwoWay-Esp8266-Client](examples/ESP8266/SecuredTwoWay-Esp8266-Client)
5. [ESP8266-Client_SINRIC](examples/ESP8266/ESP8266-Client_SINRIC)
6. [Esp8266-Server](examples/ESP8266/Esp8266-Server)
7. [Esp8266-RepeatingClient](examples/ESP8266/Esp8266-RepeatingClient)
8. [Esp8266-AdvancedWebServer](examples/ESP8266/Esp8266-AdvancedWebServer)
9. [InSecured-Esp8266-Client](examples/ESP8266/InSecured-Esp8266-Client). **New**

#### For nRF52 boards using WiFiNINA

1. [nRF52-Client](examples/Generic/WiFiNINA/nRF52/nRF52-Client)
2. [nRF52-Minimal-Client](examples/Generic/WiFiNINA/nRF52/nRF52-Minimal-Client)
3. [nRF52-Client_SINRIC](examples/Generic/WiFiNINA/nRF52/nRF52-Client_SINRIC)
4. [nRF52-Server](examples/Generic/WiFiNINA/nRF52/nRF52-Server)
5. [nRF52-RepeatingClient](examples/Generic/WiFiNINA/nRF52/nRF52-RepeatingClient)
6. [nRF52_ServerAllFunctionsDemo](examples/Generic/WiFiNINA/nRF52/nRF52_ServerAllFunctionsDemo)
7. [nRF52-AdvancedWebServer](examples/Generic/WiFiNINA/nRF52/nRF52-AdvancedWebServer).

#### For SAMD21/SAMD51 boards using WiFiNINA

1. [SAMD-Client](examples/Generic/WiFiNINA/SAMD/SAMD-Client)
2. [SAMD-Minimal-Client](examples/Generic/WiFiNINA/SAMD/SAMD-Minimal-Client)
3. [SAMD-Client_SINRIC](examples/Generic/WiFiNINA/SAMD/SAMD-Client_SINRIC)
4. [SAMD-Server](examples/Generic/WiFiNINA/SAMD/SAMD-Server)
5. [SAMD-RepeatingClient](examples/Generic/WiFiNINA/SAMD/SAMD-RepeatingClient)
6. [SAMD_ServerAllFunctionsDemo](examples/Generic/WiFiNINA/SAMD/SAMD_ServerAllFunctionsDemo)
7. [SAMD-AdvancedWebServer](examples/Generic/WiFiNINA/SAMD/SAMD-AdvancedWebServer).

#### For SAMD21/SAMD51 boards using WiFi101

1. [SAMD_WiFi101-Client](examples/Generic/WiFi101/SAMD/SAMD_WiFi101-Client)
2. [SAMD_WiFi101-Minimal-Client](examples/Generic/WiFi101/SAMD/SAMD_WiFi101-Minimal-Client)
3. [SAMD_WiFi101-Client_SINRIC](examples/Generic/WiFi101/SAMD/SAMD_WiFi101-Client_SINRIC)
4. [SAMD_WiFi101-Server](examples/Generic/WiFi101/SAMD/SAMD_WiFi101-Server)
5. [SAMD_WiFi101-RepeatingClient](examples/Generic/WiFi101/SAMD/SAMD_WiFi101-RepeatingClient)
6. [SAMD_WiFi101_ServerAllFunctionsDemo](examples/Generic/WiFi101/SAMD/SAMD_WiFi101_ServerAllFunctionsDemo)
7. [SAMD_WiFi101-AdvancedWebServer](examples/Generic/WiFi101/SAMD/SAMD_WiFi101-AdvancedWebServer).

#### For STM32F/L/H/G/WB/MP1 boards using WiFiNINA

1. [STM32-Client](examples/Generic/WiFiNINA/STM32/STM32-Client)
2. [STM32-Minimal-Client](examples/Generic/WiFiNINA/STM32/STM32-Minimal-Client)
3. [STM32-Client_SINRIC](examples/Generic/WiFiNINA/STM32/STM32-Client_SINRIC)
5. [STM32-RepeatingClient](examples/Generic/WiFiNINA/STM32/STM32-RepeatingClient)
6. [STM32_ServerAllFunctionsDemo](examples/Generic/WiFiNINA/STM32/STM32_ServerAllFunctionsDemo)
7. [STM32-AdvancedWebServer](examples/Generic/WiFiNINA/STM32/STM32-AdvancedWebServer).

#### For nRF52 boards using Ethernet (W5x00 or ENC28J60)

1. [nRF52-Ethernet-Client](examples/Generic/Ethernet/nRF52/nRF52-Ethernet-Client)
2. [nRF52-Ethernet-Minimal-Client](examples/Generic/Ethernet/nRF52/nRF52-Ethernet-Minimal-Client)
3. [nRF52-Ethernet-Client_SINRIC](examples/Generic/Ethernet/nRF52/nRF52-Ethernet-Client_SINRIC)
4. [nRF52-Ethernet-Server](examples/Generic/Ethernet/nRF52/nRF52-Ethernet-Server)
5. [nRF52-Ethernet-RepeatingClient](examples/Generic/Ethernet/nRF52/nRF52-Ethernet-RepeatingClient)
6. [nRF52-Ethernet_ServerAllFunctionsDemo](examples/Generic/Ethernet/nRF52/nRF52-Ethernet_ServerAllFunctionsDemo)
7. [nRF52-Ethernet_AdvancedWebServer](examples/Generic/Ethernet/nRF52/nRF52-Ethernet_AdvancedWebServer).

#### For SAMD21/SAMD51 boards using Ethernet (W5x00 or ENC28J60)

1. [SAMD-Ethernet-Client](examples/Generic/Ethernet/SAMD/SAMD-Ethernet-Client)
2. [SAMD-Ethernet-Minimal-Client](examples/Generic/Ethernet/SAMD/SAMD-Ethernet-Minimal-Client)
3. [SAMD-Ethernet-Client_SINRIC](examples/Generic/Ethernet/SAMD/SAMD-Ethernet-Client_SINRIC)
4. [SAMD-Ethernet-Server](examples/Generic/Ethernet/SAMD/SAMD-Ethernet-Server)
5. [SAMD-Ethernet-RepeatingClient](examples/Generic/Ethernet/SAMD/SAMD-Ethernet-RepeatingClient)
6. [SAMD-Ethernet_ServerAllFunctionsDemo](examples/Generic/Ethernet/SAMD/SAMD-Ethernet_ServerAllFunctionsDemo)
7. [SAMD-Ethernet_AdvancedWebServer](examples/Generic/Ethernet/SAMD/SAMD-Ethernet_AdvancedWebServer).

#### For SAM-DUE boards using Ethernet (W5x00 or ENC28J60)

1. [SAMDUE-Ethernet-Client](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet-Client)
2. [SAMDUE-Ethernet-Minimal-Client](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet-Minimal-Client)
3. [SAMDUE-Ethernet-Client_SINRIC](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet-Client_SINRIC)
4. [SAMDUE-Ethernet-Server](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet-Server)
5. [SAMDUE-Ethernet-RepeatingClient](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet-RepeatingClient)
6. [SAMDUE-Ethernet_ServerAllFunctionsDemo](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet_ServerAllFunctionsDemo)
7. [SAMDUE-Ethernet_AdvancedWebServer](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet_AdvancedWebServer).

#### For STM32F/L/H/G/WB/MP1 boards using Ethernet (W5x00, ENC28J60 or LAN8742A)

1. [STM32-Ethernet-Client](examples/Generic/Ethernet/STM32/STM32-Ethernet-Client)
2. [STM32-Ethernet-Minimal-Client](examples/Generic/Ethernet/STM32/STM32-Ethernet-Minimal-Client)
3. [STM32-Ethernet-Client_SINRIC](examples/Generic/Ethernet/STM32/STM32-Ethernet-Client_SINRIC)
4. [STM32-Ethernet-Server](examples/Generic/Ethernet/STM32/STM32-Ethernet-Server)
5. [STM32-Ethernet-RepeatingClient](examples/Generic/Ethernet/STM32/STM32-Ethernet-RepeatingClient)
6. [STM32-Ethernet_ServerAllFunctionsDemo](examples/Generic/Ethernet/STM32/STM32-Ethernet_ServerAllFunctionsDemo)
7. [STM32-Ethernet_AdvancedWebServer](examples/Generic/Ethernet/STM32/STM32-Ethernet_AdvancedWebServer).

#### For STM32F/L/H/G/WB/MP1 boards using Ethernet (LAN8720)

1. [STM32-Ethernet-Client_LAN8720](examples/Generic/Ethernet/STM32/LAN8720/STM32-Ethernet-Client_LAN8720)
2. [STM32-Ethernet-Minimal-Client_LAN8720](examples/Generic/Ethernet/STM32/LAN8720/STM32-Ethernet-Minimal-Client_LAN8720)
3. [STM32-Ethernet-Client_SINRIC_LAN8720](examples/Generic/Ethernet/STM32/LAN8720/STM32-Ethernet-Client_SINRIC_LAN8720)
4. [STM32-Ethernet-RepeatingClient_LAN8720](examples/Generic/Ethernet/STM32/LAN8720/STM32-Ethernet-RepeatingClient_LAN8720)


#### For Teensy boards using Ethernet (W5x00, ENC28J60 or LAN8742A). New in v1.1.0

1. [Teensy-Ethernet-Client](examples/Generic/Ethernet/Teensy/Teensy-Ethernet-Client)
2. [Teensy-Ethernet-Minimal-Client](examples/Generic/Ethernet/Teensy/Teensy-Ethernet-Minimal-Client)
3. [Teensy-Ethernet-Client_SINRIC](examples/Generic/Ethernet/Teensy/Teensy-Ethernet-Client_SINRIC)
4. [Teensy-Ethernet-Server](examples/Generic/Ethernet/Teensy/Teensy-Ethernet-Server)
5. [Teensy-Ethernet-RepeatingClient](examples/Generic/Ethernet/Teensy/Teensy-Ethernet-RepeatingClient)
6. [Teensy-Ethernet_ServerAllFunctionsDemo](examples/Generic/Ethernet/Teensy/Teensy-Ethernet_ServerAllFunctionsDemo)
7. [Teensy-Ethernet_AdvancedWebServer](examples/Generic/Ethernet/Teensy/Teensy-Ethernet_AdvancedWebServer).

#### For Teensy 4.1 boards using NativeEthernet (KSZ8081MNX/KSZ8081RNB). New in v1.1.0

1. [MultipleClients_Teensy41_Server](examples/Generic/Teensy41_NativeEthernet/MultipleClients_Teensy41_Server)
2. [SocketAndHttp_Teensy41_Server](examples/Generic/Teensy41_NativeEthernet/SocketAndHttp_Teensy41_Server)
3. [Teensy41_Client](examples/Generic/Teensy41_NativeEthernet/Teensy41_Client)
4. [Teensy41_Server](examples/Generic/Teensy41_NativeEthernet/Teensy41_Server)

#### For RP2040 boards using Ethernet (W5x00 or ENC28J60)

1. [RP2040-Ethernet-Client](examples/Generic/Ethernet/RP2040/RP2040-Ethernet-Client)
2. [RP2040-Ethernet-Minimal-Client](examples/Generic/Ethernet/RP2040/RP2040-Ethernet-Minimal-Client)
3. [RP2040-Ethernet-Client_SINRIC](examples/Generic/Ethernet/RP2040/RP2040-Ethernet-Client_SINRIC)
4. [RP2040-Ethernet-Server](examples/Generic/Ethernet/RP2040/RP2040-Ethernet-Server)
5. [RP2040-Ethernet-RepeatingClient](examples/Generic/Ethernet/RP2040/RP2040-Ethernet-RepeatingClient)
6. [RP2040-Ethernet_ServerAllFunctionsDemo](examples/Generic/Ethernet/RP2040/RP2040-Ethernet_ServerAllFunctionsDemo)
7. [RP2040-Ethernet_AdvancedWebServer](examples/Generic/Ethernet/RP2040/RP2040-Ethernet_AdvancedWebServer).


#### For WT32_ETH01 boards

1. [WT32_ETH01_AdvancedWebServer](examples/WT32_ETH01/WT32_ETH01_AdvancedWebServer)
2. [WT32_ETH01_Client](examples/WT32_ETH01/WT32_ETH01_Client)
3. [WT32_ETH01_Client_SINRIC](examples/WT32_ETH01/WT32_ETH01_Client_SINRIC)
4. [WT32_ETH01_InSecuredClient](examples/WT32_ETH01/WT32_ETH01_InSecuredClient)
5. [WT32_ETH01_MinimalClient](examples/WT32_ETH01/WT32_ETH01_MinimalClient)
6. [WT32_ETH01_RepeatingClient](examples/WT32_ETH01/WT32_ETH01_RepeatingClient)
7. [WT32_ETH01_SecuredClient](examples/WT32_ETH01/WT32_ETH01_SecuredClient)
8. [WT32_ETH01_Server](examples/WT32_ETH01/WT32_ETH01_Server).


#### For Teensy 4.1 boards using QNEthernet (KSZ8081MNX/KSZ8081RNB). New in v1.6.0

1. [MultipleClients_Teensy41_Server](examples/Generic/Teensy41_QNEthernet/MultipleClients_Teensy41_Server)
2. [SocketAndHttp_Teensy41_Server](examples/Generic/Teensy41_QNEthernet/SocketAndHttp_Teensy41_Server)
3. [Teensy41_Client](examples/Generic/Teensy41_QNEthernet/Teensy41_Client)
4. [Teensy41_Server](examples/Generic/Teensy41_QNEthernet/Teensy41_Server)


#### For Portenta_H7 boards using Vision-shield Ethernet. New in v1.7.0

1. [Portenta_H7_Ethernet_Client](examples/Generic/Portenta_H7/Ethernet/Portenta_H7_Ethernet_Client)
2. [Portenta_H7_Ethernet_Server](examples/Generic/Portenta_H7/Ethernet/Portenta_H7_Ethernet_Server)

#### For Portenta_H7 boards using Murata WiFi. New in v1.7.0

1. [Portenta_H7-AdvancedWebServer](examples/Generic/Portenta_H7/WiFi/Portenta_H7-AdvancedWebServer)
2. [Portenta_H7-Client](examples/Generic/Portenta_H7/WiFi/Portenta_H7-Client)
3. [Portenta_H7-Client_SINRIC](examples/Generic/Portenta_H7/WiFi/Portenta_H7-Client_SINRIC)
4. [Portenta_H7-Minimal-Client](examples/Generic/Portenta_H7/WiFi/Portenta_H7-Minimal-Client)
5. [Portenta_H7-RepeatingClient](examples/Generic/Portenta_H7/WiFi/Portenta_H7-RepeatingClient)
6. [Portenta_H7-Server](examples/Generic/Portenta_H7/WiFi/Portenta_H7-Server)
7. [Portenta_H7_ServerAllFunctionsDemo](examples/Generic/Portenta_H7/WiFi/Portenta_H7_ServerAllFunctionsDemo)


#### For RP2040 boards using WiFiNINA. New in v1.8.0

1. [RP2040-AdvancedWebServer](examples/Generic/WiFiNINA/RP2040/RP2040-AdvancedWebServer)
2. [RP2040-Client](examples/Generic/WiFiNINA/RP2040/RP2040-Client)
3. [RP2040-Client_SINRIC](examples/Generic/WiFiNINA/RP2040/RP2040-Client_SINRIC)
4. [RP2040-Minimal-Client](examples/Generic/WiFiNINA/RP2040/RP2040-Minimal-Client)
5. [RP2040-RepeatingClient](examples/Generic/WiFiNINA/RP2040/RP2040-RepeatingClient)
6. [RP2040-Server](examples/Generic/Generic/WiFiNINA/RP2040/RP2040-Server)
7. [RP2040_ServerAllFunctionsDemo](examples/Generic/WiFiNINA/RP2040/RP2040_ServerAllFunctionsDemo)


#### For ESP32 boards using Ethernet. New in v1.11.0

1. [ESP32_Ethernet-Client](examples/Generic/Ethernet/ESP32/ESP32_Ethernet-Client)
2. [ESP32_Ethernet-Minimal-Client](examples/Generic/Ethernet/ESP32/ESP32_Ethernet-Minimal-Client)
3. [ESP32_Ethernet-Client_SINRIC](examples/Generic/Ethernet/ESP32/ESP32_Ethernet-Client_SINRIC)
4. [ESP32_Ethernet-Server](examples/Generic/Ethernet/ESP32/ESP32_Ethernet-Server)
5. [ESP32_Ethernet-RepeatingClient](examples/Generic/Ethernet/ESP32/ESP32_Ethernet-RepeatingClient)
6. [ESP32_Ethernet_ServerAllFunctionsDemo](examples/Generic/Ethernet/ESP32/ESP32_Ethernet_ServerAllFunctionsDemo)
7. [ESP32_Ethernet_AdvancedWebServer](examples/Generic/Ethernet/ESP32/ESP32_Ethernet_AdvancedWebServer).

#### For RP2040W boards using built-in WiFi. New in v1.13.0

1. [RP2040W-AdvancedWebServer](examples/Generic/RP2040W/RP2040W-AdvancedWebServer)
2. [RP2040W-Client](examples/Generic/RP2040W/RP2040W-Client)
3. [RP2040W-Client_SINRIC](examples/Generic/RP2040W/RP2040W-Client_SINRIC)
4. [RP2040W-Minimal-Client](examples/Generic/RP2040W/RP2040W-Minimal-Client)
5. [RP2040W-RepeatingClient](examples/Generic/RP2040W/RP2040W-RepeatingClient)
6. [RP2040W-Server](examples/Generic/Generic/RP2040W/RP2040W-Server)
7. [RP2040W_ServerAllFunctionsDemo](examples/Generic/RP2040W/RP2040W_ServerAllFunctionsDemo)

---
---

### Example [SAMD-Client_SINRIC](examples/Generic/WiFiNINA/SAMD/SAMD-Client_SINRIC)

Please take a look at other examples, as well.

#### 1. File [SAMD-Client_SINRIC.ino](examples/Generic/WiFiNINA/SAMD/SAMD-Client_SINRIC/SAMD-Client_SINRIC.ino)

https://github.com/khoih-prog/WebSockets2_Generic/blob/d1139159d520fa9b8b7b812dde7f893d23d0e789/examples/Generic/WiFiNINA/SAMD/SAMD-Client_SINRIC/SAMD-Client_SINRIC.ino#L29-L263


#### 2. File [defines.h](examples/Generic/WiFiNINA/SAMD/SAMD-Client_SINRIC/defines.h)

https://github.com/khoih-prog/WebSockets2_Generic/blob/d1139159d520fa9b8b7b812dde7f893d23d0e789/examples/Generic/WiFiNINA/SAMD/SAMD-Client_SINRIC/defines.h#L17-L164


---

### Using SINRIC Service

This is the terminal output when running [SAMD-Client_SINRIC](examples/Generic/WiFiNINA/SAMD/SAMD-Client_SINRIC) example on **Nano-33 IoT**:

```cpp
Starting WebSockets2_Generic SAMD-Client_SINRIC with WiFiNINA on SAMD NANO_33_IOT
WebSockets2_Generic v1.13.2
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
// To update SHA1 fingerprint, use Google Chrome to connect to https://www.websocket.org/echo.html 
// Then "View Site Information" => "Certificate Viewer" => Copy SHA1 fingerprint
// KH, This SHA1 fingerprint was updated 15.04.2021, 
// Issued on Mar 15th 2021, expired on June 13th 2021
const char echo_org_ssl_fingerprint[] PROGMEM   = "34 A2 66 08 A1 4D 1E 83 1A 0E 49 3C 4A 84 45 9E 4A 0D 08 FE";

client.setFingerprint(echo_org_ssl_fingerprint);
```

or you could use the `setKnownKey()` method to specify the public key of a certificate in order to validate the server you are connecting to.

```cpp
PublicKey *publicKey = new PublicKey(public_key);
client.setKnownKey(publicKey);
```
or you can specify the Certificate Authority (CA) using `setTrustAnchors` method, as follows:

```cpp
X509List *serverTrustedCA = new X509List(ca_cert);
client.setTrustAnchors(serverTrustedCA);
```

For client-side certificate validation, you can use RSA or EC certificates, using the method `setClientRSACert` or `setClientECCert` .


### ESP32

With the ESP32 you could either provide the full certificate, or provide no certificate. An example for setting CA Certificate:

```c++
// KH, This certificate was updated 15.04.2021, 
// Issued on Mar 15th 2021, expired on June 13th 2021
const char echo_org_ssl_ca_cert[] PROGMEM = \
"-----BEGIN CERTIFICATE-----\n" \
"MIIEZTCCA02gAwIBAgIQQAF1BIMUpMghjISpDBbN3zANBgkqhkiG9w0BAQsFADA/\n" \
"MSQwIgYDVQQKExtEaWdpdGFsIFNpZ25hdHVyZSBUcnVzdCBDby4xFzAVBgNVBAMT\n" \
"DkRTVCBSb290IENBIFgzMB4XDTIwMTAwNzE5MjE0MFoXDTIxMDkyOTE5MjE0MFow\n" \
"MjELMAkGA1UEBhMCVVMxFjAUBgNVBAoTDUxldCdzIEVuY3J5cHQxCzAJBgNVBAMT\n" \
"AlIzMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAuwIVKMz2oJTTDxLs\n" \
"jVWSw/iC8ZmmekKIp10mqrUrucVMsa+Oa/l1yKPXD0eUFFU1V4yeqKI5GfWCPEKp\n" \
"Tm71O8Mu243AsFzzWTjn7c9p8FoLG77AlCQlh/o3cbMT5xys4Zvv2+Q7RVJFlqnB\n" \
"U840yFLuta7tj95gcOKlVKu2bQ6XpUA0ayvTvGbrZjR8+muLj1cpmfgwF126cm/7\n" \
"gcWt0oZYPRfH5wm78Sv3htzB2nFd1EbjzK0lwYi8YGd1ZrPxGPeiXOZT/zqItkel\n" \
"/xMY6pgJdz+dU/nPAeX1pnAXFK9jpP+Zs5Od3FOnBv5IhR2haa4ldbsTzFID9e1R\n" \
"oYvbFQIDAQABo4IBaDCCAWQwEgYDVR0TAQH/BAgwBgEB/wIBADAOBgNVHQ8BAf8E\n" \
"BAMCAYYwSwYIKwYBBQUHAQEEPzA9MDsGCCsGAQUFBzAChi9odHRwOi8vYXBwcy5p\n" \
"ZGVudHJ1c3QuY29tL3Jvb3RzL2RzdHJvb3RjYXgzLnA3YzAfBgNVHSMEGDAWgBTE\n" \
"p7Gkeyxx+tvhS5B1/8QVYIWJEDBUBgNVHSAETTBLMAgGBmeBDAECATA/BgsrBgEE\n" \
"AYLfEwEBATAwMC4GCCsGAQUFBwIBFiJodHRwOi8vY3BzLnJvb3QteDEubGV0c2Vu\n" \
"Y3J5cHQub3JnMDwGA1UdHwQ1MDMwMaAvoC2GK2h0dHA6Ly9jcmwuaWRlbnRydXN0\n" \
"LmNvbS9EU1RST09UQ0FYM0NSTC5jcmwwHQYDVR0OBBYEFBQusxe3WFbLrlAJQOYf\n" \
"r52LFMLGMB0GA1UdJQQWMBQGCCsGAQUFBwMBBggrBgEFBQcDAjANBgkqhkiG9w0B\n" \
"AQsFAAOCAQEA2UzgyfWEiDcx27sT4rP8i2tiEmxYt0l+PAK3qB8oYevO4C5z70kH\n" \
"ejWEHx2taPDY/laBL21/WKZuNTYQHHPD5b1tXgHXbnL7KqC401dk5VvCadTQsvd8\n" \
"S8MXjohyc9z9/G2948kLjmE6Flh9dDYrVYA9x2O+hEPGOaEOa1eePynBgPayvUfL\n" \
"qjBstzLhWVQLGAkXXmNs+5ZnPBxzDJOLxhF2JIbeQAcH5H0tZrUlo5ZYyOqA7s9p\n" \
"O5b85o3AM/OJ+CktFBQtfvBhcJVd9wvlwPsk+uyOy2HI7mNxKKgsBTt375teA2Tw\n" \
"UdHkhVNcsAKX1H7GNNLOEADksd86wuoXvg==\n" \
"-----END CERTIFICATE-----\n";

client.setCACert(echo_org_ssl_ca_cert);
```

From v1.2.4, you can use InSecured mode which does not validate the certificate chain. This can be set explicitly using:

```c++
client.setInsecure();
```
---
---

### Debug Terminal Output Samples

#### 1. [SAMD-Ethernet-Client_SINRIC](examples/Generic/Ethernet/SAMD/SAMD-Ethernet-Client_SINRIC) on SAMD51 ADAFRUIT_ITSYBITSY_M4_EXPRESS using ENC28J60

This is terminal debug output when running [SAMD-Ethernet-Client_SINRIC](examples/Generic/Ethernet/SAMD/SAMD-Ethernet-Client_SINRIC) on SAMD51 **ADAFRUIT_ITSYBITSY_M4_EXPRESS using ENC28J60 Ethernet module.**

```cpp
Starting WebSockets2_Generic SAMD-Ethernet-Client_SINRIC on SAMD ADAFRUIT_ITSYBITSY_M4_EXPRESS
Ethernet using ENC28J60 and UIPEthernet Library
WebSockets2_Generic v1.13.2
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

#### 2. [SAMDUE-Ethernet-Server](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet-Server) on SAM-DUE with W5100 using Ethernet_Generic library

This is terminal debug output when running [SAMDUE-Ethernet-Server](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet-Server) on **SAM DUE board with Ethernet W5100 shield using Ethernet_Generic library**, and receiving WebSockets connection from an ESP8266 board.

```cpp
Starting WebSockets2_Generic SAMDUE-Ethernet-Server on SAM DUE
Ethernet using W5x00 and Ethernet_Generic Library
WebSockets2_Generic v1.13.2
[WS] =========== USE_ETHERNET_GENERIC ===========
[WS] Default SPI pinout:
[WS] MOSI: 75
[WS] MISO: 74
[WS] SCK: 76
[WS] SS: 10
[WS] =========================
[WS] SAM DUE  setCsPin: 10
[WS] =========================
[WS] Currently Used SPI pinout:
[WS] MOSI: 75
[WS] MISO: 74
[WS] SCK: 76
[WS] SS: 10
[WS] =========================
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

#### 3. [nRF52-Ethernet-Server](examples/Generic/Ethernet/nRF52/nRF52-Ethernet-Server) on Adafruit NRF52840_ITSYBITSY_EXPRESS with ENC28J60 using UIPEthernet library

This is terminal debug output when running [nRF52-Ethernet-Server](examples/Generic/Ethernet/nRF52/nRF52-Ethernet-Server) on **Adafruit NRF52840_ITSYBITSY_EXPRESS board with Ethernet ENC28J60 shield using UIPEthernet library**, and receiving WebSockets connection from an ESP8266 board.

```cpp
Starting WebSockets2_Generic nRF52-Ethernet-Server on NRF52840_ITSYBITSY_EXPRESS
Ethernet using ENC28J60 and UIPEthernet Library
WebSockets2_Generic v1.13.2
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

#### 4. [STM32-Ethernet-Client_SINRIC](examples/Generic/Ethernet/STM32/STM32-Ethernet-Client_SINRIC) on STM32F7 Nucleo-144 NUCLEO_F767ZI with built-in Ethernet LAN8742A using STMEthernet library

This is terminal debug output when running [STM32-Ethernet-Client_SINRIC](examples/Generic/Ethernet/STM32/STM32-Ethernet-Client_SINRIC) on **STM32F7 Nucleo-144 NUCLEO_F767ZI board with built-in Ethernet LAN8742A using STMEthernet library**.

```cpp
Starting WebSockets2_Generic STM32-Ethernet-Client_SINRIC on NUCLEO_F767ZI
Ethernet using LAN8742A and STM32Ethernet Library
WebSockets2_Generic v1.13.2
[WS] =========== USE_LAN8742A_ETHERNET ===========
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

#### 5. [SAMDUE-Ethernet_ServerAllFunctionsDemo](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet_ServerAllFunctionsDemo) example on SAM-DUE and W5100 Ethernet

This is the terminal debug output when running [SAMDUE-Ethernet_ServerAllFunctionsDemo](examples/Generic/Ethernet/SAMDUE/SAMDUE-Ethernet_ServerAllFunctionsDemo) example on **SAM DUE and W5100 Ethernet**. There are 3 WebSockets Clients connecting to the WebSockets Server:

  - ESP32 running [Esp32-RepeatingClient](examples/ESP32/Esp32-RepeatingClient)
  - ESP8266 running [Esp8266-RepeatingClient](examples/ESP8266/Esp8266-RepeatingClient)
  - STM32 Nucleo-144 NUCLEO_F767ZI running [STM32-Ethernet-RepeatingClient](examples/Generic/Ethernet/STM32/STM32-Ethernet-RepeatingClient)

```cpp
Start Generic_WebSocketServerAllFunctionsDemo_W5500
WebSockets2_Generic v1.13.2
[WS] =========== USE_ETHERNET_GENERIC ===========
[WS] Default SPI pinout:
[WS] MOSI: 75
[WS] MISO: 74
[WS] SCK: 76
[WS] SS: 10
[WS] =========================
[WS] SAM DUE  setCsPin: 10
[WS] =========================
[WS] Currently Used SPI pinout:
[WS] MOSI: 75
[WS] MISO: 74
[WS] SCK: 76
[WS] SS: 10
[WS] =========================
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

#### 6. [STM32-Ethernet-Client_SINRIC_LAN8720](examples/Generic/Ethernet/STM32/LAN8720/STM32-Ethernet-Client_SINRIC_LAN8720) on BLACK_F407VE using LAN8720 and STM32Ethernet Library

This is terminal debug output when running [STM32-Ethernet-Client_SINRIC_LAN8720](examples/Generic/Ethernet/STM32/LAN8720/STM32-Ethernet-Client_SINRIC_LAN8720) on **BLACK_F407VE using LAN8720 and STM32Ethernet Library**.

```cpp
Starting STM32-Ethernet-Client_SINRIC_LAN8720 on BLACK_F407VE
Ethernet using LAN8720 and STM32Ethernet Library
WebSockets2_Generic v1.13.2
[WS] =========== USE_LAN8720_ETHERNET ===========
WebSockets Client IP address: 192.168.2.160
Connecting to WebSockets Server @iot.sinric.com
[WS] WebsocketsClient::generateHandshake: base64Authorization = YXBpa2V5OjkxMjdkNDc4LTExNjAtNDE4OC04MDQ4LTQ3OWJhNWM2OTExNA==
[WS] WebsocketsClient::generateHandshake: handshake = GET / HTTP/1.1
Host: iot.sinric.com
Sec-WebSocket-Key: MDEyMzQ1Njc4OWFiY2RlZg==
apikey: "11111111-2222-3333-4444-555555555555"
Upgrade: websocket
Connection: Upgrade
Sec-WebSocket-Version: 13
User-Agent: TinyWebsockets Client
Authorization: Basic YXBpa2V5OjkxMjdkNDc4LTExNjAtNDE4OC04MDQ4LTQ3OWJhNWM2OTExNA==
Origin: https://github.com/khoih-prog/Websockets2_Generic
[WS] WebsocketsClient::connect: base64Authorization = YXBpa2V5OjkxMjdkNDc4LTExNjAtNDE4OC04MDQ4LTQ3OWJhNWM2OTExNA==
[WS] WebsocketsClient::doestStartsWith: str = HTTP/1.1 101 Switching Protocols
[WS] WebsocketsClient::doestStartsWith: prefix = HTTP/1.1 101
[WS] WebsocketsClient::generateHandshake: key = Server
[WS] WebsocketsClient::generateHandshake: value = nginx/1.10.3 (Ubuntu)
[WS] WebsocketsClient::generateHandshake: key = Date
[WS] WebsocketsClient::generateHandshake: value = Fri, 16 Apr 2021 03:03:10 GMT
[WS] WebsocketsClient::generateHandshake: key = Connection
[WS] WebsocketsClient::generateHandshake: value = upgrade
[WS] WebsocketsClient::generateHandshake: key = Upgrade
[WS] WebsocketsClient::generateHandshake: value = websocket
[WS] WebsocketsClient::generateHandshake: key = Sec-WebSocket-Accept
[WS] WebsocketsClient::generateHandshake: value = BACScCJPNqyz+UBoqMH89VmURoA=
Connected!
Got Message: {"deviceId":"012345678901234567890123","action":"setPowerState","value":"ON"}
Turn on device id: 012345678901234567890123
Got Message: {"deviceId":"012345678901234567890123","action":"setPowerState","value":"OFF"}
Turn off Device ID: 012345678901234567890123
```

---

#### 7. [ESP32-Client_SINRIC](examples/ESP32/ESP32-Client_SINRIC) on ESP32S2_DEV

This is terminal debug output when running [ESP32-Client_SINRIC](examples/ESP32/ESP32-Client_SINRIC) on **ESP32S2_DEV**

```cpp
Starting ESP32-Client_SINRIC on ESP32S2_DEV
WebSockets2_Generic v1.13.2
....Connected to Wifi, Connecting to WebSockets Server @iot.sinric.com
[WS] WebsocketsClient::generateHandshake: base64Authorization = YXBpa2V5OjkxMjdkNDc4LTExNjAtNDE4OC04MDQ4LTQ3OWJhNWM2OTExNA==
[WS] WebsocketsClient::generateHandshake: handshake = GET / HTTP/1.1
Host: iot.sinric.com
Sec-WebSocket-Key: MDEyMzQ1Njc4OWFiY2RlZg==
apikey: "11111111-2222-3333-4444-555555555555"
Upgrade: websocket
Connection: Upgrade
Sec-WebSocket-Version: 13
User-Agent: TinyWebsockets Client
Authorization: Basic YXBpa2V5OjkxMjdkNDc4LTExNjAtNDE4OC04MDQ4LTQ3OWJhNWM2OTExNA==
Origin: https://github.com/khoih-prog/Websockets2_Generic
[WS] WebsocketsClient::connect: base64Authorization = YXBpa2V5OjkxMjdkNDc4LTExNjAtNDE4OC04MDQ4LTQ3OWJhNWM2OTExNA==
[WS] WebsocketsClient::doestStartsWith: str = HTTP/1.1 101 Switching Protocols
[WS] WebsocketsClient::doestStartsWith: prefix = HTTP/1.1 101
[WS] WebsocketsClient::generateHandshake: key = Server
[WS] WebsocketsClient::generateHandshake: value = nginx/1.10.3 (Ubuntu)
[WS] WebsocketsClient::generateHandshake: key = Date
[WS] WebsocketsClient::generateHandshake: value = Thu, 15 Apr 2021 22:44:28 GMT
[WS] WebsocketsClient::generateHandshake: key = Connection
[WS] WebsocketsClient::generateHandshake: value = upgrade
[WS] WebsocketsClient::generateHandshake: key = Upgrade
[WS] WebsocketsClient::generateHandshake: value = websocket
[WS] WebsocketsClient::generateHandshake: key = Sec-WebSocket-Accept
[WS] WebsocketsClient::generateHandshake: value = BACScCJPNqyz+UBoqMH89VmURoA=
Connected!
Got Message: {"deviceId":"012345678901234567890123","action":"setPowerState","value":"ON"}
Turn on device id: 012345678901234567890123
Got Message: {"deviceId":"012345678901234567890123","action":"setPowerState","value":"OFF"}
Turn off Device ID: 012345678901234567890123
```

---

#### 8. [Secured-ESP32-Client](examples/ESP32/Secured-Esp32-Client) on ESP32S2_DEV

This is terminal debug output when running [Secured-ESP32-Client](examples/ESP32/Secured-Esp32-Client) on **ESP32S2_DEV**

```cpp
Starting WebSockets Secured-ESP32-Client on ESP32S2_DEV
WebSockets2_Generic v1.13.2
....
Connected to Wifi, Connecting to WebSockets Server @wss://echo.websocket.org/
[WS] WebsocketsClient::doestStartsWith: str = wss://echo.websocket.org/
[WS] WebsocketsClient::doestStartsWith: prefix = wss://
[WS] WebsocketsClient::generateHandshake: base64Authorization = 
[WS] WebsocketsClient::generateHandshake: handshake = GET / HTTP/1.1
Host: echo.websocket.org
Sec-WebSocket-Key: MDEyMzQ1Njc4OWFiY2RlZg==
Upgrade: websocket
Connection: Upgrade
Sec-WebSocket-Version: 13
User-Agent: TinyWebsockets Client
Authorization: Basic 
Origin: https://github.com/khoih-prog/Websockets2_Generic
[WS] WebsocketsClient::connect: base64Authorization = 
[WS] WebsocketsClient::doestStartsWith: str = HTTP/1.1 101 Web Socket Protocol Handshake
[WS] WebsocketsClient::doestStartsWith: prefix = HTTP/1.1 101
[WS] WebsocketsClient::generateHandshake: key = Access-Control-Allow-Credentials
[WS] WebsocketsClient::generateHandshake: value = true
[WS] WebsocketsClient::generateHandshake: key = Access-Control-Allow-Headers
[WS] WebsocketsClient::generateHandshake: value = content-type
[WS] WebsocketsClient::generateHandshake: key = Access-Control-Allow-Headers
[WS] WebsocketsClient::generateHandshake: value = authorization
[WS] WebsocketsClient::generateHandshake: key = Access-Control-Allow-Headers
[WS] WebsocketsClient::generateHandshake: value = x-websocket-extensions
[WS] WebsocketsClient::generateHandshake: key = Access-Control-Allow-Headers
[WS] WebsocketsClient::generateHandshake: value = x-websocket-version
[WS] WebsocketsClient::generateHandshake: key = Access-Control-Allow-Headers
[WS] WebsocketsClient::generateHandshake: value = x-websocket-protocol
[WS] WebsocketsClient::generateHandshake: key = Access-Control-Allow-Origin
[WS] WebsocketsClient::generateHandshake: value = https://github.com/khoih-prog/Websockets2_Generic
[WS] WebsocketsClient::generateHandshake: key = Connection
[WS] WebsocketsClient::generateHandshake: value = Upgrade
[WS] WebsocketsClient::generateHandshake: key = Date
[WS] WebsocketsClient::generateHandshake: value = Fri, 16 Apr 2021 19:34:42 GMT
[WS] WebsocketsClient::generateHandshake: key = Sec-WebSocket-Accept
[WS] WebsocketsClient::generateHandshake: value = BACScCJPNqyz+UBoqMH89VmURoA=
[WS] WebsocketsClient::generateHandshake: key = Server
[WS] WebsocketsClient::generateHandshake: value = Kaazing Gateway
[WS] WebsocketsClient::generateHandshake: key = Upgrade
[WS] WebsocketsClient::generateHandshake: value = websocket
Connection Opened
Connected!
Got Message: Hello to Server from ESP32S2_DEV
Got a Pong!
```

---

#### 9. [InSecured-ESP32-Client](examples/ESP32/InSecured-Esp32-Client) on ESP32_DEV

This is terminal debug output when running [InSecured-ESP32-Client](examples/ESP32/InSecured-Esp32-Client) on **ESP32_DEV**


```cpp
Starting WebSockets InSecured-ESP32-Client on ESP32_DEV
WebSockets2_Generic v1.13.2
...
Connected to Wifi, Connecting to WebSockets Server @wss://echo.websocket.org/
[WS] WebsocketsClient::doestStartsWith: str = wss://echo.websocket.org/
[WS] WebsocketsClient::doestStartsWith: prefix = wss://
[WS] WebsocketsClient::generateHandshake: base64Authorization = 
[WS] WebsocketsClient::generateHandshake: handshake = GET / HTTP/1.1
Host: echo.websocket.org
Sec-WebSocket-Key: MDEyMzQ1Njc4OWFiY2RlZg==
Upgrade: websocket
Connection: Upgrade
Sec-WebSocket-Version: 13
User-Agent: TinyWebsockets Client
Authorization: Basic 
Origin: https://github.com/khoih-prog/Websockets2_Generic
[WS] WebsocketsClient::connect: base64Authorization = 
[WS] WebsocketsClient::doestStartsWith: str = HTTP/1.1 101 Web Socket Protocol Handshake
[WS] WebsocketsClient::doestStartsWith: prefix = HTTP/1.1 101
[WS] WebsocketsClient::generateHandshake: key = Access-Control-Allow-Credentials
[WS] WebsocketsClient::generateHandshake: value = true
[WS] WebsocketsClient::generateHandshake: key = Access-Control-Allow-Headers
[WS] WebsocketsClient::generateHandshake: value = content-type
[WS] WebsocketsClient::generateHandshake: key = Access-Control-Allow-Headers
[WS] WebsocketsClient::generateHandshake: value = authorization
[WS] WebsocketsClient::generateHandshake: key = Access-Control-Allow-Headers
[WS] WebsocketsClient::generateHandshake: value = x-websocket-extensions
[WS] WebsocketsClient::generateHandshake: key = Access-Control-Allow-Headers
[WS] WebsocketsClient::generateHandshake: value = x-websocket-version
[WS] WebsocketsClient::generateHandshake: key = Access-Control-Allow-Headers
[WS] WebsocketsClient::generateHandshake: value = x-websocket-protocol
[WS] WebsocketsClient::generateHandshake: key = Access-Control-Allow-Origin
[WS] WebsocketsClient::generateHandshake: value = https://github.com/khoih-prog/Websockets2_Generic
[WS] WebsocketsClient::generateHandshake: key = Connection
[WS] WebsocketsClient::generateHandshake: value = Upgrade
[WS] WebsocketsClient::generateHandshake: key = Date
[WS] WebsocketsClient::generateHandshake: value = Wed, 05 May 2021 17:09:23 GMT
[WS] WebsocketsClient::generateHandshake: key = Sec-WebSocket-Accept
[WS] WebsocketsClient::generateHandshake: value = BACScCJPNqyz+UBoqMH89VmURoA=
[WS] WebsocketsClient::generateHandshake: key = Server
[WS] WebsocketsClient::generateHandshake: value = Kaazing Gateway
[WS] WebsocketsClient::generateHandshake: key = Upgrade
[WS] WebsocketsClient::generateHandshake: value = websocket
Connection Opened
Connected!
Got Message: Hello to Server from ESP32_DEV
Got a Pong!
```

---

#### 10. [ESP8266-Client_SINRIC](examples/ESP32/ESP8266-Client_SINRIC) on ESP8266_NODEMCU_ESP12E

This is terminal debug output when running [ESP8266-Client_SINRIC](examples/ESP32/ESP8266-Client_SINRIC) on **ESP8266_NODEMCU_ESP12E**


```cpp
Starting ESP8266-Client_SINRIC on ESP8266_NODEMCU_ESP12E
WebSockets2_Generic v1.13.2
......Connected to Wifi, Connecting to WebSockets Server @iot.sinric.com
[WS] WebsocketsClient::generateHandshake: base64Authorization = YXBpa2V5OjkxMjdkNDc4LTExNjAtNDE4OC04MDQ4LTQ3OWJhNWM2OTExNA==
[WS] WebsocketsClient::generateHandshake: handshake = GET / HTTP/1.1
Host: iot.sinric.com
Sec-WebSocket-Key: MDEyMzQ1Njc4OWFiY2RlZg==
apikey: api_key
Upgrade: websocket
Connection: Upgrade
Sec-WebSocket-Version: 13
User-Agent: TinyWebsockets Client
Authorization: Basic YXBpa2V5OjkxMjdkNDc4LTExNjAtNDE4OC04MDQ4LTQ3OWJhNWM2OTExNA==
Origin: https://github.com/khoih-prog/Websockets2_Generic
[WS] WebsocketsClient::connect: base64Authorization = YXBpa2V5OjkxMjdkNDc4LTExNjAtNDE4OC04MDQ4LTQ3OWJhNWM2OTExNA==
[WS] WebsocketsClient::doestStartsWith: str = HTTP/1.1 101 Switching Protocols
[WS] WebsocketsClient::doestStartsWith: prefix = HTTP/1.1 101
[WS] WebsocketsClient::generateHandshake: key = Server
[WS] WebsocketsClient::generateHandshake: value = nginx/1.10.3 (Ubuntu)
[WS] WebsocketsClient::generateHandshake: key = Date
[WS] WebsocketsClient::generateHandshake: value = Fri, 21 May 2021 04:06:49 GMT
[WS] WebsocketsClient::generateHandshake: key = Connection
[WS] WebsocketsClient::generateHandshake: value = upgrade
[WS] WebsocketsClient::generateHandshake: key = Upgrade
[WS] WebsocketsClient::generateHandshake: value = websocket
[WS] WebsocketsClient::generateHandshake: key = Sec-WebSocket-Accept
[WS] WebsocketsClient::generateHandshake: value = BACScCJPNqyz+UBoqMH89VmURoA=
Connected!
```

---

#### 11. [RP2040-Ethernet-Client_SINRIC](examples/Generic/Ethernet/RP2040/RP2040-Ethernet-Client_SINRIC) on RASPBERRY_PI_PICO

This is terminal debug output when running [RP2040-Ethernet-Client_SINRIC](examples/Generic/Ethernet/RP2040/RP2040-Ethernet-Client_SINRIC) on **RASPBERRY_PI_PICO** using [**Earle Philhower's arduino-pico** core](https://github.com/earlephilhower/arduino-pico)


```cpp
Starting RP2040-Ethernet-Client_SINRIC on RASPBERRY_PI_PICO
Ethernet using W5x00 and Ethernet_Generic Library
WebSockets2_Generic v1.13.2
[WS] =========== USE_ETHERNET_GENERIC ===========
[WS] Default SPI pinout:
[WS] MOSI: 19
[WS] MISO: 16
[WS] SCK: 18
[WS] SS: 17
[WS] =========================
[WS] RASPBERRY_PI_PICO setCsPin: 17
[WS] =========================
[WS] Currently Used SPI pinout:
[WS] MOSI: 19
[WS] MISO: 16
[WS] SCK: 18
[WS] SS: 17
[WS] =========================
WebSockets Client IP address: 192.168.2.152
Connecting to WebSockets Server @iot.sinric.com
[WS] WebsocketsClient::connect: step 1
[WS] WebsocketsClient::generateHandshake: base64Authorization = YXBpa2V5OjkxMjdkNDc4LTExNjAtNDE4OC04MDQ4LTQ3OWJhNWM2OTExNA==
[WS] WebsocketsClient::generateHandshake: handshake = GET / HTTP/1.1
Host: iot.sinric.com
Sec-WebSocket-Key: MDEyMzQ1Njc4OWFiY2RlZg==
apikey: 11111111-2222-3333-4444-555555555555
Upgrade: websocket
Connection: Upgrade
Sec-WebSocket-Version: 13
User-Agent: TinyWebsockets Client
Authorization: Basic YXBpa2V5OjkxMjdkNDc4LTExNjAtNDE4OC04MDQ4LTQ3OWJhNWM2OTExNA==
Origin: https://github.com/khoih-prog/Websockets2_Generic
[WS] WebsocketsClient::connect: base64Authorization = YXBpa2V5OjkxMjdkNDc4LTExNjAtNDE4OC04MDQ4LTQ3OWJhNWM2OTExNA==
[WS] WebsocketsClient::connect: step 2
[WS] WebsocketsClient::connect: step 3
[WS] WebsocketsClient::connect: step 4
[WS] WebsocketsClient::doestStartsWith: str = HTTP/1.1 101 Switching Protocols
[WS] WebsocketsClient::doestStartsWith: prefix = HTTP/1.1 101
[WS] WebsocketsClient::connect: step 5
[WS] WebsocketsClient::connect: step 6
[WS] WebsocketsClient::generateHandshake: key = Server
[WS] WebsocketsClient::generateHandshake: value = nginx/1.10.3 (Ubuntu)
[WS] WebsocketsClient::generateHandshake: key = Date
[WS] WebsocketsClient::generateHandshake: value = Tue, 25 May 2021 04:51:41 GMT
[WS] WebsocketsClient::generateHandshake: key = Connection
[WS] WebsocketsClient::generateHandshake: value = upgrade
[WS] WebsocketsClient::generateHandshake: key = Upgrade
[WS] WebsocketsClient::generateHandshake: value = websocket
[WS] WebsocketsClient::generateHandshake: key = Sec-WebSocket-Accept
[WS] WebsocketsClient::generateHandshake: value = BACScCJPNqyz+UBoqMH89VmURoA=
[WS] WebsocketsClient::connect: step 7
Connected!
Got Message: {"deviceId":"012345678901234567890123","action":"setPowerState","value":"ON"}
Turn on for unknown device id: 012345678901234567890123
Got Message: {"deviceId":"012345678901234567890123","action":"setPowerState","value":"OFF"}
Turn off for unknown device id: 012345678901234567890123
```

---

#### 12. [RP2040-Ethernet-Client_SINRIC](examples/Generic/Ethernet/RP2040/RP2040-Ethernet-Client_SINRIC) on MBED RaspberryPi Pico

This is terminal debug output when running [RP2040-Ethernet-Client_SINRIC](examples/Generic/Ethernet/RP2040/RP2040-Ethernet-Client_SINRIC) on **MBED RaspberryPi Pico** using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed).


```cpp
Starting RP2040-Ethernet-Client_SINRIC on RaspberryPi Pico
Ethernet using W5x00 and Ethernet_Generic Library
WebSockets2_Generic v1.13.2
[WS] =========== USE_ETHERNET_GENERIC ===========
[WS] Default SPI pinout:
[WS] MOSI: 19
[WS] MISO: 16
[WS] SCK: 18
[WS] SS: 17
[WS] =========================
[WS] MBED RASPBERRY_PI_PICO setCsPin: 17
[WS] =========================
[WS] Currently Used SPI pinout:
[WS] MOSI: 19
[WS] MISO: 16
[WS] SCK: 18
[WS] SS: 17
[WS] =========================
WebSockets Client IP address: 192.168.2.152
Connecting to WebSockets Server @iot.sinric.com
[WS] WebsocketsClient::connect: step 1
[WS] WebsocketsClient::generateHandshake: base64Authorization = YXBpa2V5OjkxMjdkNDc4LTExNjAtNDE4OC04MDQ4LTQ3OWJhNWM2OTExNA==
[WS] WebsocketsClient::generateHandshake: handshake = GET / HTTP/1.1
Host: iot.sinric.com
Sec-WebSocket-Key: MDEyMzQ1Njc4OWFiY2RlZg==
apikey: 11111111-2222-3333-4444-555555555555
Upgrade: websocket
Connection: Upgrade
Sec-WebSocket-Version: 13
User-Agent: TinyWebsockets Client
Authorization: Basic YXBpa2V5OjkxMjdkNDc4LTExNjAtNDE4OC04MDQ4LTQ3OWJhNWM2OTExNA==
Origin: https://github.com/khoih-prog/Websockets2_Generic
[WS] WebsocketsClient::connect: base64Authorization = YXBpa2V5OjkxMjdkNDc4LTExNjAtNDE4OC04MDQ4LTQ3OWJhNWM2OTExNA==
[WS] WebsocketsClient::connect: step 2
[WS] WebsocketsClient::connect: step 3
[WS] WebsocketsClient::connect: step 4
[WS] WebsocketsClient::doestStartsWith: str = HTTP/1.1 101 Switching Protocols
[WS] WebsocketsClient::doestStartsWith: prefix = HTTP/1.1 101
[WS] WebsocketsClient::connect: step 5
[WS] WebsocketsClient::connect: step 6
[WS] WebsocketsClient::generateHandshake: key = Server
[WS] WebsocketsClient::generateHandshake: value = nginx/1.10.3 (Ubuntu)
[WS] WebsocketsClient::generateHandshake: key = Date
[WS] WebsocketsClient::generateHandshake: value = Tue, 25 May 2021 04:57:32 GMT
[WS] WebsocketsClient::generateHandshake: key = Connection
[WS] WebsocketsClient::generateHandshake: value = upgrade
[WS] WebsocketsClient::generateHandshake: key = Upgrade
[WS] WebsocketsClient::generateHandshake: value = websocket
[WS] WebsocketsClient::generateHandshake: key = Sec-WebSocket-Accept
[WS] WebsocketsClient::generateHandshake: value = BACScCJPNqyz+UBoqMH89VmURoA=
[WS] WebsocketsClient::connect: step 7
Connected!
Got Message: {"deviceId":"012345678901234567890123","action":"setPowerState","value":"ON"}
Turn on device id: 012345678901234567890123
Got Message: {"deviceId":"012345678901234567890123","action":"setPowerState","value":"OFF"}
Turn off Device ID: 012345678901234567890123
```

---

#### 13. [WT32_ETH01_Client_SINRIC](examples/WT32_ETH01/WT32_ETH01_Client_SINRIC) on WT32_ETH01 (ESP32 + LAN8720)

This is terminal debug output when running [WT32_ETH01_Client_SINRIC](examples/WT32_ETH01/WT32_ETH01_Client_SINRIC) on **WT32_ETH01 (ESP32 + LAN8720)** board.


```cpp
Starting WT32_ETH01_Client_SINRIC on ESP32_DEV with ETH_PHY_LAN8720
WebServer_WT32_ETH01 v1.5.1
WebSockets2_Generic v1.13.2
ETH MAC: A8:03:2A:A1:61:73, IPv4: 192.168.2.232, FULL_DUPLEX, 100Mbps
Connected. Connecting to WebSockets Server @iot.sinric.com
[WS] WebsocketsClient::generateHandshake: base64Authorization = YXBpa2V5OjkxMjdkNDc4LTExNjAtNDE4OC04MDQ4LTQ3OWJhNWM2OTExNA==
[WS] WebsocketsClient::generateHandshake: handshake = GET / HTTP/1.1
Host: iot.sinric.com
Sec-WebSocket-Key: MDEyMzQ1Njc4OWFiY2RlZg==
apikey: 11111111-2222-3333-4444-555555555555
Upgrade: websocket
Connection: Upgrade
Sec-WebSocket-Version: 13
User-Agent: TinyWebsockets Client
Authorization: Basic YXBpa2V5OjkxMjdkNDc4LTExNjAtNDE4OC04MDQ4LTQ3OWJhNWM2OTExNA==
Origin: https://github.com/khoih-prog/Websockets2_Generic
[WS] WebsocketsClient::connect: base64Authorization = YXBpa2V5OjkxMjdkNDc4LTExNjAtNDE4OC04MDQ4LTQ3OWJhNWM2OTExNA==
[WS] WebsocketsClient::doestStartsWith: str = HTTP/1.1 101 Switching Protocols
[WS] WebsocketsClient::doestStartsWith: prefix = HTTP/1.1 101
[WS] WebsocketsClient::generateHandshake: key = Server
[WS] WebsocketsClient::generateHandshake: value = nginx/1.10.3 (Ubuntu)
[WS] WebsocketsClient::generateHandshake: key = Date
[WS] WebsocketsClient::generateHandshake: value = Thu, 08 Jul 2021 18:13:14 GMT
[WS] WebsocketsClient::generateHandshake: key = Connection
[WS] WebsocketsClient::generateHandshake: value = upgrade
[WS] WebsocketsClient::generateHandshake: key = Upgrade
[WS] WebsocketsClient::generateHandshake: value = websocket
[WS] WebsocketsClient::generateHandshake: key = Sec-WebSocket-Accept
[WS] WebsocketsClient::generateHandshake: value = BACScCJPNqyz+UBoqMH89VmURoA=
Connected!
Got Message: {"deviceId":"012345678901234567890123","action":"setPowerState","value":"ON"}
Turn on device id: 012345678901234567890123
Got Message: {"deviceId":"012345678901234567890123","action":"setPowerState","value":"OFF"}
Turn off Device ID: 012345678901234567890123
```

---

#### 14. [WT32_ETH01_SecuredClient](examples/WT32_ETH01/WT32_ETH01_SecuredClient) on WT32_ETH01 (ESP32 + LAN8720)

This is terminal debug output when running [WT32_ETH01_SecuredClient](examples/WT32_ETH01/WT32_ETH01_SecuredClient) on **WT32_ETH01 (ESP32 + LAN8720)** board.


```cpp
Starting WT32_ETH01_SecuredClient on ESP32_DEV with ETH_PHY_LAN8720
WebServer_WT32_ETH01 v1.5.1
WebSockets2_Generic v1.13.2
ETH MAC: A8:03:2A:A1:61:73, IPv4: 192.168.2.232, FULL_DUPLEX, 100Mbps
Connected. Connecting to WebSockets Server @wss://echo.websocket.org/
[WS] WebsocketsClient::doestStartsWith: str = wss://echo.websocket.org/
[WS] WebsocketsClient::doestStartsWith: prefix = wss://
[WS] WebsocketsClient::generateHandshake: base64Authorization = 
[WS] WebsocketsClient::generateHandshake: handshake = GET / HTTP/1.1
Host: echo.websocket.org
Sec-WebSocket-Key: MDEyMzQ1Njc4OWFiY2RlZg==
Upgrade: websocket
Connection: Upgrade
Sec-WebSocket-Version: 13
User-Agent: TinyWebsockets Client
Authorization: Basic 
Origin: https://github.com/khoih-prog/Websockets2_Generic
[WS] WebsocketsClient::connect: base64Authorization = 
[WS] WebsocketsClient::doestStartsWith: str = HTTP/1.1 101 Web Socket Protocol Handshake
[WS] WebsocketsClient::doestStartsWith: prefix = HTTP/1.1 101
[WS] WebsocketsClient::generateHandshake: key = Access-Control-Allow-Credentials
[WS] WebsocketsClient::generateHandshake: value = true
[WS] WebsocketsClient::generateHandshake: key = Access-Control-Allow-Headers
[WS] WebsocketsClient::generateHandshake: value = content-type
[WS] WebsocketsClient::generateHandshake: key = Access-Control-Allow-Headers
[WS] WebsocketsClient::generateHandshake: value = authorization
[WS] WebsocketsClient::generateHandshake: key = Access-Control-Allow-Headers
[WS] WebsocketsClient::generateHandshake: value = x-websocket-extensions
[WS] WebsocketsClient::generateHandshake: key = Access-Control-Allow-Headers
[WS] WebsocketsClient::generateHandshake: value = x-websocket-version
[WS] WebsocketsClient::generateHandshake: key = Access-Control-Allow-Headers
[WS] WebsocketsClient::generateHandshake: value = x-websocket-protocol
[WS] WebsocketsClient::generateHandshake: key = Access-Control-Allow-Origin
[WS] WebsocketsClient::generateHandshake: value = https://github.com/khoih-prog/Websockets2_Generic
[WS] WebsocketsClient::generateHandshake: key = Connection
[WS] WebsocketsClient::generateHandshake: value = Upgrade
[WS] WebsocketsClient::generateHandshake: key = Date
[WS] WebsocketsClient::generateHandshake: value = Thu, 08 Jul 2021 18:31:34 GMT
[WS] WebsocketsClient::generateHandshake: key = Sec-WebSocket-Accept
[WS] WebsocketsClient::generateHandshake: value = BACScCJPNqyz+UBoqMH89VmURoA=
[WS] WebsocketsClient::generateHandshake: key = Server
[WS] WebsocketsClient::generateHandshake: value = Kaazing Gateway
[WS] WebsocketsClient::generateHandshake: key = Upgrade
[WS] WebsocketsClient::generateHandshake: value = websocket
Connection Opened
Connected!
Got Message: Hello to Server from ESP32_DEV
Got a Pong!
```

---

#### 15. [WT32_ETH01_AdvancedWebServer](examples/WT32_ETH01/WT32_ETH01_AdvancedWebServer) on WT32_ETH01 (ESP32 + LAN8720)

This is terminal debug output when running [WT32_ETH01_AdvancedWebServer](examples/WT32_ETH01/WT32_ETH01_AdvancedWebServer) on **WT32_ETH01 (ESP32 + LAN8720)** board.

```cpp
Starting WT32_ETH01_AdvancedWebServer on ESP32_DEV with ETH_PHY_LAN8720
WebServer_WT32_ETH01 v1.5.1
WebSockets2_Generic v1.13.2
ETH MAC: A8:03:2A:A1:61:73, IPv4: 192.168.2.95, FULL_DUPLEX, 100Mbps
MDNS responder started
WebSockets Server Running and Ready on WT32-ETH01
IP address: 192.168.2.95, Port: 8080
HTTP server started
[WS] WebsocketsServer::recvHandshakeRequest: value = 192.168.2.95
[WS] WebsocketsServer::recvHandshakeRequest: value = MDEyMzQ1Njc4OWFiY2RlZg==
[WS] WebsocketsServer::recvHandshakeRequest: value = websocket
[WS] WebsocketsServer::recvHandshakeRequest: value = Upgrade
[WS] WebsocketsServer::recvHandshakeRequest: value = 13
[WS] WebsocketsServer::recvHandshakeRequest: value = TinyWebsockets Client
[WS] WebsocketsServer::recvHandshakeRequest: value = Basic 
[WS] WebsocketsServer::recvHandshakeRequest: value = https://github.com/khoih-prog/Websockets2_Generic
Got Message: 
[WS] WebsocketsServer::recvHandshakeRequest: value = 192.168.2.95
[WS] WebsocketsServer::recvHandshakeRequest: value = MDEyMzQ1Njc4OWFiY2RlZg==
[WS] WebsocketsServer::recvHandshakeRequest: value = websocket
[WS] WebsocketsServer::recvHandshakeRequest: value = Upgrade
[WS] WebsocketsServer::recvHandshakeRequest: value = 13
[WS] WebsocketsServer::recvHandshakeRequest: value = TinyWebsockets Client
[WS] WebsocketsServer::recvHandshakeRequest: value = Basic 
[WS] WebsocketsServer::recvHandshakeRequest: value = https://github.com/khoih-prog/Websockets2_Generic
Got Message: 
```

---

#### 16. [SocketAndHttp_Teensy41_Server](examples/Generic/Teensy41_QNEthernet/SocketAndHttp_Teensy41_Server) on TEENSY 4.1 using QNEthernet

This is terminal debug output and screenshot when running [SocketAndHttp_Teensy41_Server](examples/Generic/Teensy41_QNEthernet/SocketAndHttp_Teensy41_Server) on **TEENSY 4.1 using QNEthernet**.


<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/raw/master/pics/SocketAndHttp_Teensy41_Server_QNEthernet.png">
</p>

```cpp
Start SocketAndHttp_Teensy41_Server on TEENSY 4.1 using QNEthernet
WebSockets2_Generic v1.13.2
=========== USE_QN_ETHERNET ===========
Initialize Ethernet using DHCP => Connected! IP address:192.168.2.119
Visit http://192.168.2.119 in the browser to connect.
[WS] WebsocketsServer::recvHandshakeRequest: value = 192.168.2.119
[WS] WebsocketsServer::recvHandshakeRequest: value = MDEyMzQ1Njc4OWFiY2RlZg==
[WS] WebsocketsServer::recvHandshakeRequest: value = websocket
[WS] WebsocketsServer::recvHandshakeRequest: value = Upgrade
[WS] WebsocketsServer::recvHandshakeRequest: value = 13
[WS] WebsocketsServer::recvHandshakeRequest: value = TinyWebsockets Client
[WS] WebsocketsServer::recvHandshakeRequest: value = Basic 
[WS] WebsocketsServer::recvHandshakeRequest: value = https://github.com/khoih-prog/Websockets2_Generic
Accepted new websockets client at index 0
Got Message: Hello to Server from ESP32
Http client connected!
Http client connected!
Connection closed
[WS] WebsocketsServer::recvHandshakeRequest: value = 192.168.2.119
[WS] WebsocketsServer::recvHandshakeRequest: value = MDEyMzQ1Njc4OWFiY2RlZg==
[WS] WebsocketsServer::recvHandshakeRequest: value = websocket
[WS] WebsocketsServer::recvHandshakeRequest: value = Upgrade
[WS] WebsocketsServer::recvHandshakeRequest: value = 13
[WS] WebsocketsServer::recvHandshakeRequest: value = TinyWebsockets Client
[WS] WebsocketsServer::recvHandshakeRequest: value = Basic 
[WS] WebsocketsServer::recvHandshakeRequest: value = https://github.com/khoih-prog/Websockets2_Generic
Accepted new websockets client at index 0
Got Message: Hello to Server from ESP32
```

---


#### 17. [MultiClients_Teensy41_Server](examples/Generic/Teensy41_QNEthernet/MultiClients_Teensy41_Server) on TEENSY 4.1 using QNEthernet

This is terminal debug output when running [MultiClients_Teensy41_Server](examples/Generic/Teensy41_QNEthernet/MultiClients_Teensy41_Server) on **TEENSY 4.1 using QNEthernet**.


##### 17.1 Server 

```cpp
Starting MultiClients_Teensy41_Server on TEENSY 4.1 using QNEthernet
WebSockets2_Generic v1.13.2
=========== USE_QN_ETHERNET ===========
Initialize Ethernet using DHCP => Connected! IP address:192.168.2.119
Server available at ws://192.168.2.119:81
[WS] WebsocketsServer::recvHandshakeRequest: value = 192.168.2.119
[WS] WebsocketsServer::recvHandshakeRequest: value = MDEyMzQ1Njc4OWFiY2RlZg==
[WS] WebsocketsServer::recvHandshakeRequest: value = websocket
[WS] WebsocketsServer::recvHandshakeRequest: value = Upgrade
[WS] WebsocketsServer::recvHandshakeRequest: value = 13
[WS] WebsocketsServer::recvHandshakeRequest: value = TinyWebsockets Client
[WS] WebsocketsServer::recvHandshakeRequest: value = Basic 
[WS] WebsocketsServer::recvHandshakeRequest: value = https://github.com/khoih-prog/Websockets2_Generic
Accepted new websockets client at index 0
Got Message: Hello to Server from ESP32
Connection closed
[WS] WebsocketsServer::recvHandshakeRequest: value = 192.168.2.119
[WS] WebsocketsServer::recvHandshakeRequest: value = MDEyMzQ1Njc4OWFiY2RlZg==
[WS] WebsocketsServer::recvHandshakeRequest: value = websocket
[WS] WebsocketsServer::recvHandshakeRequest: value = Upgrade
[WS] WebsocketsServer::recvHandshakeRequest: value = 13
[WS] WebsocketsServer::recvHandshakeRequest: value = TinyWebsockets Client
[WS] WebsocketsServer::recvHandshakeRequest: value = Basic 
[WS] WebsocketsServer::recvHandshakeRequest: value = https://github.com/khoih-prog/Websockets2_Generic
Accepted new websockets client at index 0
Got Message: Hello to Server from ESP32
```

##### 17.2 Client


```cpp
Starting ESP32-RepeatingClient on ESP32_DEV
WebSockets2_Generic v1.13.2
....Connected to Wifi, Connecting to WebSockets Server @192.168.2.119
[WS] WebsocketsClient::generateHandshake: base64Authorization = 
[WS] WebsocketsClient::generateHandshake: handshake = GET / HTTP/1.1
Host: 192.168.2.119
Sec-WebSocket-Key: MDEyMzQ1Njc4OWFiY2RlZg==
Upgrade: websocket
Connection: Upgrade
Sec-WebSocket-Version: 13
User-Agent: TinyWebsockets Client
Authorization: Basic 
Origin: https://github.com/khoih-prog/Websockets2_Generic
[WS] WebsocketsClient::connect: base64Authorization = 
[WS] WebsocketsClient::doestStartsWith: str = HTTP/1.1 101 Switching Protocols
[WS] WebsocketsClient::doestStartsWith: prefix = HTTP/1.1 101
[WS] WebsocketsClient::generateHandshake: key = Connection
[WS] WebsocketsClient::generateHandshake: value = Upgrade
[WS] WebsocketsClient::generateHandshake: key = Upgrade
[WS] WebsocketsClient::generateHandshake: value = websocket
[WS] WebsocketsClient::generateHandshake: key = Sec-WebSocket-Version
[WS] WebsocketsClient::generateHandshake: value = 13
[WS] WebsocketsClient::generateHandshake: key = Sec-WebSocket-Accept
[WS] WebsocketsClient::generateHandshake: value = BACScCJPNqyz+UBoqMH89VmURoA=
Connection Opened
Connected!
Got Message: Hello from Teensy
Got Message: Echo: Hello to Server from ESP32
```

---


#### 18. [Portenta_H7_Ethernet_Server](examples/Generic/Portenta_H7/Ethernet/Portenta_H7_Ethernet_Server) on PORTENTA_H7_M7 Ethernet

This is terminal debug output when running [Portenta_H7_Ethernet_Server](examples/Generic/Portenta_H7/Ethernet/Portenta_H7_Ethernet_Server) on **PORTENTA_H7_M7 Ethernet** using Portenta_Ethernet Library



```cpp
Starting Portenta_H7_Ethernet_Server on PORTENTA_H7_M7 Ethernet using Portenta_Ethernet Library
WebSockets2_Generic v1.13.2
WebSockets Client @ IP address: 192.168.2.132
Server available at ws://192.168.2.132:8080
[WS] WebsocketsServer::recvHandshakeRequest: value = 192.168.2.132
[WS] WebsocketsServer::recvHandshakeRequest: value = MDEyMzQ1Njc4OWFiY2RlZg==
[WS] WebsocketsServer::recvHandshakeRequest: value = websocket
[WS] WebsocketsServer::recvHandshakeRequest: value = Upgrade
[WS] WebsocketsServer::recvHandshakeRequest: value = 13
[WS] WebsocketsServer::recvHandshakeRequest: value = TinyWebsockets Client
[WS] WebsocketsServer::recvHandshakeRequest: value = Basic 
[WS] WebsocketsServer::recvHandshakeRequest: value = https://github.com/khoih-prog/Websockets2_Generic
Client connected
Got Message: Hello to Server from ESP8266
Client closed
[WS] WebsocketsServer::recvHandshakeRequest: value = 192.168.2.132
[WS] WebsocketsServer::recvHandshakeRequest: value = MDEyMzQ1Njc4OWFiY2RlZg==
[WS] WebsocketsServer::recvHandshakeRequest: value = websocket
[WS] WebsocketsServer::recvHandshakeRequest: value = Upgrade
[WS] WebsocketsServer::recvHandshakeRequest: value = 13
[WS] WebsocketsServer::recvHandshakeRequest: value = TinyWebsockets Client
[WS] WebsocketsServer::recvHandshakeRequest: value = Basic 
[WS] WebsocketsServer::recvHandshakeRequest: value = https://github.com/khoih-prog/Websockets2_Generic
Client connected
Got Message: Hello to Server from ESP8266
```

---

#### 19. [Portenta_H7-Client_SINRIC](examples/Generic/Portenta_H7/WiFi/Portenta_H7-Client_SINRIC) using WiFi on PORTENTA_H7_M7

This is terminal debug output when running [Portenta_H7-Client_SINRIC](examples/Generic/Portenta_H7/WiFi/Portenta_H7-Client_SINRIC) on **PORTENTA_H7_M7** using `Murata` WiFi


```cpp
Starting Portenta_H7-Client_SINRIC using WiFi on PORTENTA_H7_M7
WebSockets2_Generic v1.13.2
Connecting to SSID: HueNet1
Connected to Wifi, IP address: 192.168.2.130
Connecting to WebSockets Server @iot.sinric.com
[WS] WebsocketsClient::generateHandshake: base64Authorization = YXBpa2V5OjkxMjdkNDc4LTExNjAtNDE4OC04MDQ4LTQ3OWJhNWM2OTExNA==
[WS] WebsocketsClient::generateHandshake: handshake = GET / HTTP/1.1
Host: iot.sinric.com
Sec-WebSocket-Key: MDEyMzQ1Njc4OWFiY2RlZg==
apikey: 11111111-2222-3333-4444-555555555555
Upgrade: websocket
Connection: Upgrade
Sec-WebSocket-Version: 13
User-Agent: TinyWebsockets Client
Authorization: Basic YXBpa2V5OjkxMjdkNDc4LTExNjAtNDE4OC04MDQ4LTQ3OWJhNWM2OTExNA==
Origin: https://github.com/khoih-prog/Websockets2_Generic
[WS] WebsocketsClient::connect: base64Authorization = YXBpa2V5OjkxMjdkNDc4LTExNjAtNDE4OC04MDQ4LTQ3OWJhNWM2OTExNA==
[WS] WebsocketsClient::doestStartsWith: str = HTTP/1.1 101 Switching Protocols
[WS] WebsocketsClient::doestStartsWith: prefix = HTTP/1.1 101
[WS] WebsocketsClient::generateHandshake: key = Server
[WS] WebsocketsClient::generateHandshake: value = nginx/1.10.3 (Ubuntu)
[WS] WebsocketsClient::generateHandshake: key = Date
[WS] WebsocketsClient::generateHandshake: value = Sun, 19 Sep 2021 03:17:49 GMT
[WS] WebsocketsClient::generateHandshake: key = Connection
[WS] WebsocketsClient::generateHandshake: value = upgrade
[WS] WebsocketsClient::generateHandshake: key = Upgrade
[WS] WebsocketsClient::generateHandshake: value = websocket
[WS] WebsocketsClient::generateHandshake: key = Sec-WebSocket-Accept
[WS] WebsocketsClient::generateHandshake: value = BACScCJPNqyz+UBoqMH89VmURoA=
Connected!
Got Message: {"action":"test","sender":"web"}
Got Message: {"action":"test","sender":"web"}
Got Message: {"deviceId":"012345678901234567890123","action":"setPowerState","value":"ON"}
Turn on device id: 012345678901234567890123
Got Message: {"deviceId":"012345678901234567890123","action":"setPowerState","value":"OFF"}
Turn off Device ID: 012345678901234567890123
```

---

#### 20. [RP2040-AdvancedWebServer](examples/Generic/WiFiNINA/RP2040/RP2040-AdvancedWebServer) using WiFiNINA on MBED NANO_RP2040_CONNECT

This is terminal debug output when running [Portenta_H7-Client_SINRIC](examples/Generic/WiFiNINA/RP2040/RP2040-AdvancedWebServer) on **MBED NANO_RP2040_CONNECT** using WiFiNINA


```cpp
Starting RP2040-AdvancedWebServer with WiFiNINA on MBED NANO_RP2040_CONNECT
WebSockets2_Generic v1.13.2
Attempting to connect to SSID: HueNet1
Connected to Wifi, IP address: 192.168.2.96
WebSockets Server Running and Ready on MBED NANO_RP2040_CONNECT
IP address: 192.168.2.96, Port: 8080
[WS] WebsocketsServer::recvHandshakeRequest: value = 192.168.2.96
[WS] WebsocketsServer::recvHandshakeRequest: value = MDEyMzQ1Njc4OWFiY2RlZg==
[WS] WebsocketsServer::recvHandshakeRequest: value = websocket
[WS] WebsocketsServer::recvHandshakeRequest: value = Upgrade
[WS] WebsocketsServer::recvHandshakeRequest: value = 13
[WS] WebsocketsServer::recvHandshakeRequest: value = TinyWebsockets Client
[WS] WebsocketsServer::recvHandshakeRequest: value = Basic 
[WS] WebsocketsServer::recvHandshakeRequest: value = https://github.com/khoih-prog/Websockets2_Generic
Got Message: 
[WS] WebsocketsServer::recvHandshakeRequest: value = 192.168.2.96
[WS] WebsocketsServer::recvHandshakeRequest: value = MDEyMzQ1Njc4OWFiY2RlZg==
[WS] WebsocketsServer::recvHandshakeRequest: value = websocket
[WS] WebsocketsServer::recvHandshakeRequest: value = Upgrade
[WS] WebsocketsServer::recvHandshakeRequest: value = 13
[WS] WebsocketsServer::recvHandshakeRequest: value = TinyWebsockets Client
[WS] WebsocketsServer::recvHandshakeRequest: value = Basic 
[WS] WebsocketsServer::recvHandshakeRequest: value = https://github.com/khoih-prog/Websockets2_Generic
Got Message: 
[WS] WebsocketsServer::recvHandshakeRequest: value = 192.168.2.96
[WS] WebsocketsServer::recvHandshakeRequest: value = MDEyMzQ1Njc4OWFiY2RlZg==
[WS] WebsocketsServer::recvHandshakeRequest: value = websocket
[WS] WebsocketsServer::recvHandshakeRequest: value = Upgrade
[WS] WebsocketsServer::recvHandshakeRequest: value = 13
[WS] WebsocketsServer::recvHandshakeRequest: value = TinyWebsockets Client
[WS] WebsocketsServer::recvHandshakeRequest: value = Basic 
[WS] WebsocketsServer::recvHandshakeRequest: value = https://github.com/khoih-prog/Websockets2_Generic
Got Message: 
```

---

#### 21. [Teensy41_Client](examples/Generic/Teensy41_QNEthernet/Teensy41_Client) using QNEthernet on Teensy 4.1

This is terminal debug output when running [Teensy41_Client](examples/Generic/Teensy41_QNEthernet/Teensy41_Client) on **Teensy 4.1** using QNEthernet

```cpp
Starting Teensy41_Client on TEENSY 4.1 using QNEthernet
WebSockets2_Generic v1.13.2
=========== USE_QN_ETHERNET ===========
Initialize Ethernet using static IP => Connected! IP address:192.168.2.222
[WS] WebsocketsClient::doestStartsWith: str = ws://192.168.2.30:8080
[WS] WebsocketsClient::doestStartsWith: prefix = ws://
[WS] WebsocketsClient::connect: step 1
[WS] QNEthernet::connect: ip = 192.168.2.30 , port =  8080
[WS] WebsocketsClient::generateHandshake: base64Authorization = 
[WS] WebsocketsClient::generateHandshake: handshake = GET / HTTP/1.1
Host: 192.168.2.30
Sec-WebSocket-Key: MDEyMzQ1Njc4OWFiY2RlZg==
Upgrade: websocket
Connection: Upgrade
Sec-WebSocket-Version: 13
User-Agent: TinyWebsockets Client
Authorization: Basic 
Origin: https://github.com/khoih-prog/Websockets2_Generic
[WS] WebsocketsClient::connect: base64Authorization = 
[WS] WebsocketsClient::connect: step 2
[WS] WebsocketsClient::connect: step 3
[WS] WebsocketsClient::connect: step 4
[WS] WebsocketsClient::doestStartsWith: str = HTTP/1.1 101 Switching Protocols
[WS] WebsocketsClient::doestStartsWith: prefix = HTTP/1.1 101
[WS] WebsocketsClient::connect: step 5
[WS] WebsocketsClient::connect: step 6
[WS] WebsocketsClient::generateHandshake: key = Upgrade
[WS] WebsocketsClient::generateHandshake: value = websocket
[WS] WebsocketsClient::generateHandshake: key = Connection
[WS] WebsocketsClient::generateHandshake: value = Upgrade
[WS] WebsocketsClient::generateHandshake: key = Sec-WebSocket-Accept
[WS] WebsocketsClient::generateHandshake: value = BACScCJPNqyz+UBoqMH89VmURoA=
[WS] WebsocketsClient::generateHandshake: key = Origin
[WS] WebsocketsClient::generateHandshake: value = https://github.com/khoih-prog/Websockets2_Generic
[WS] WebsocketsClient::connect: step 7
Connected to server : ws://192.168.2.30:8080
Got Message: Hello Server
```

---

#### 22. [ESP32_Ethernet-Client](examples/Generic/Ethernet/ESP32/ESP32_Ethernet-Client) using W5x00 Ethernet on ESP32_DEV

This is terminal debug output when running [ESP32_Ethernet-Client](examples/Generic/Ethernet/ESP32/ESP32_Ethernet-Client) on **ESP32_DEV** using `W5x00 Ethernet` with `Ethernet_Generic` Library

```cpp
Starting ESP32_Ethernet-Client on ESP32_DEV
Ethernet using W5x00 and Ethernet_Generic Library
WebSockets2_Generic v1.13.2
[WS] Default SPI pinout:
[WS] MOSI: 23
[WS] MISO: 19
[WS] SCK: 18
[WS] SS: 5
[WS] =========================
[WS] ESP32 setCsPin: 5
[WS] =========================
[WS] Currently Used SPI pinout:
[WS] MOSI: 23
[WS] MISO: 19
[WS] SCK: 18
[WS] SS: 5
[WS] =========================
Using mac index = 1
Connected! IP address: 192.168.2.81
WebSockets Client IP address: 192.168.2.84
Connecting to WebSockets Server @192.168.2.30
[WS] WebsocketsClient::connect: step 1
[WS] WebsocketsClient::generateHandshake: base64Authorization = 
[WS] WebsocketsClient::generateHandshake: handshake = GET / HTTP/1.1
Host: 192.168.2.30
Sec-WebSocket-Key: MDEyMzQ1Njc4OWFiY2RlZg==
Upgrade: websocket
Connection: Upgrade
Sec-WebSocket-Version: 13
User-Agent: TinyWebsockets Client
Authorization: Basic 
Origin: https://github.com/khoih-prog/Websockets2_Generic
[WS] WebsocketsClient::connect: base64Authorization = 
[WS] WebsocketsClient::connect: step 2
[WS] WebsocketsClient::connect: step 3
[WS] WebsocketsClient::connect: step 4
[WS] WebsocketsClient::doestStartsWith: str = HTTP/1.1 101 Switching Protocols
[WS] WebsocketsClient::doestStartsWith: prefix = HTTP/1.1 101
[WS] WebsocketsClient::connect: step 5
[WS] WebsocketsClient::connect: step 6
[WS] WebsocketsClient::generateHandshake: key = Upgrade
[WS] WebsocketsClient::generateHandshake: value = websocket
[WS] WebsocketsClient::generateHandshake: key = Connection
[WS] WebsocketsClient::generateHandshake: value = Upgrade
[WS] WebsocketsClient::generateHandshake: key = Sec-WebSocket-Accept
[WS] WebsocketsClient::generateHandshake: value = BACScCJPNqyz+UBoqMH89VmURoA=
[WS] WebsocketsClient::generateHandshake: key = Origin
[WS] WebsocketsClient::generateHandshake: value = https://github.com/khoih-prog/Websockets2_Generic
[WS] WebsocketsClient::connect: step 7
Connection Opened
Connected!
Got Message: Hello to Server from ESP32_DEV
```


---

#### 23. [ESP32_Ethernet-Client](examples/Generic/Ethernet/ESP32/ESP32_Ethernet-Client) using ENC28J60 and EthernetENC Library on ESP32_DEV

This is terminal debug output when running [ESP32_Ethernet-Client](examples/Generic/Ethernet/ESP32/ESP32_Ethernet-Client) on **ESP32_DEV** using `ENC28J60 Ethernet` with `EthernetENC` Library

```cpp
Starting ESP32_Ethernet-Client on ESP32_DEV
Ethernet using ENC28J60 and EthernetENC Library
WebSockets2_Generic v1.13.2
[WS] Default SPI pinout:
[WS] MOSI: 23
[WS] MISO: 19
[WS] SCK: 18
[WS] SS: 5
[WS] =========================
[WS] ESP32 setCsPin: 5
Using mac index = 7
Connected! IP address: 192.168.2.85
WebSockets Client IP address: 192.168.2.85
Connecting to WebSockets Server @192.168.2.30
[WS] WebsocketsClient::connect: step 1
[WS] WebsocketsClient::generateHandshake: base64Authorization = 
[WS] WebsocketsClient::generateHandshake: handshake = GET / HTTP/1.1
Host: 192.168.2.30
Sec-WebSocket-Key: MDEyMzQ1Njc4OWFiY2RlZg==
Upgrade: websocket
Connection: Upgrade
Sec-WebSocket-Version: 13
User-Agent: TinyWebsockets Client
Authorization: Basic 
Origin: https://github.com/khoih-prog/Websockets2_Generic
[WS] WebsocketsClient::connect: base64Authorization = 
[WS] WebsocketsClient::connect: step 2
[WS] WebsocketsClient::connect: step 3
[WS] WebsocketsClient::connect: step 4
[WS] WebsocketsClient::doestStartsWith: str = HTTP/1.1 101 Switching Protocols
[WS] WebsocketsClient::doestStartsWith: prefix = HTTP/1.1 101
[WS] WebsocketsClient::connect: step 5
[WS] WebsocketsClient::connect: step 6
[WS] WebsocketsClient::generateHandshake: key = Upgrade
[WS] WebsocketsClient::generateHandshake: value = websocket
[WS] WebsocketsClient::generateHandshake: key = Connection
[WS] WebsocketsClient::generateHandshake: value = Upgrade
[WS] WebsocketsClient::generateHandshake: key = Sec-WebSocket-Accept
[WS] WebsocketsClient::generateHandshake: value = BACScCJPNqyz+UBoqMH89VmURoA=
[WS] WebsocketsClient::generateHandshake: key = Origin
[WS] WebsocketsClient::generateHandshake: value = https://github.com/khoih-prog/Websockets2_Generic
[WS] WebsocketsClient::connect: step 7
Connection Opened
Connected!
Got Message: Hello to Server from ESP32_DEV
Got a Ping!
Got a Ping!
Got a Ping!
```


---

#### 24. [ESP32_Ethernet-Client](examples/Generic/Ethernet/ESP32/ESP32_Ethernet-Client) using ENC28J60 and UIPEthernet Library on ESP32_DEV

This is terminal debug output when running [ESP32_Ethernet-Client](examples/Generic/Ethernet/ESP32/ESP32_Ethernet-Client) on **ESP32_DEV** using `ENC28J60 Ethernet` with `UIPEthernet` Library


```cpp
Starting ESP32_Ethernet-Client on ESP32_DEV
Ethernet using ENC28J60 and UIPEthernet Library
WebSockets2_Generic v1.13.2
[WS] Default SPI pinout:
[WS] MOSI: 23
[WS] MISO: 19
[WS] SCK: 18
[WS] SS: 5
[WS] =========================
[WS] ESP32 setCsPin: 5
Using mac index = 7
Connected! IP address: 192.168.2.85
WebSockets Client IP address: 192.168.2.88
Connecting to WebSockets Server @192.168.2.30
[WS] WebsocketsClient::connect: step 1
[WS] WebsocketsClient::generateHandshake: base64Authorization = 
[WS] WebsocketsClient::generateHandshake: handshake = GET / HTTP/1.1
Host: 192.168.2.30
Sec-WebSocket-Key: MDEyMzQ1Njc4OWFiY2RlZg==
Upgrade: websocket
Connection: Upgrade
Sec-WebSocket-Version: 13
User-Agent: TinyWebsockets Client
Authorization: Basic 
Origin: https://github.com/khoih-prog/Websockets2_Generic
[WS] WebsocketsClient::connect: base64Authorization = 
[WS] WebsocketsClient::connect: step 2
[WS] WebsocketsClient::connect: step 3
[WS] WebsocketsClient::connect: step 4
[WS] WebsocketsClient::doestStartsWith: str = HTTP/1.1 101 Switching Protocols
[WS] WebsocketsClient::doestStartsWith: prefix = HTTP/1.1 101
[WS] WebsocketsClient::connect: step 5
[WS] WebsocketsClient::connect: step 6
[WS] WebsocketsClient::generateHandshake: key = Upgrade
[WS] WebsocketsClient::generateHandshake: value = websocket
[WS] WebsocketsClient::generateHandshake: key = Connection
[WS] WebsocketsClient::generateHandshake: value = Upgrade
[WS] WebsocketsClient::generateHandshake: key = Sec-WebSocket-Accept
[WS] WebsocketsClient::generateHandshake: value = BACScCJPNqyz+UBoqMH89VmURoA=
[WS] WebsocketsClient::generateHandshake: key = Origin
[WS] WebsocketsClient::generateHandshake: value = https://github.com/khoih-prog/Websockets2_Generic
[WS] WebsocketsClient::connect: step 7
Connection Opened
Connected!
Got Message: Hello to Server from ESP32_DEV
Got a Ping!
Got a Ping!
Got a Ping!
```


---

#### 25. [RP2040W-Client](examples/Generic/RP2040W/RP2040W-Client) using built-in WiFi on RASPBERRY_PI_PICO_W

This is terminal debug output when running [RP2040W-Client](examples/Generic/RP2040W/RP2040W-Client) on **RASPBERRY_PI_PICO_W** using built-in `CYW43439 WiFi`


```cpp
Starting RP2040W-Client on RASPBERRY_PI_PICO_W
WebSockets2_Generic v1.13.2
Connecting to SSID: HueNet1
SSID: HueNet1
Local IP Address: 192.168.2.77
Connecting to WebSockets Server @192.168.2.30
[WS] WebsocketsClient::generateHandshake: base64Authorization = 
[WS] WebsocketsClient::generateHandshake: handshake = GET / HTTP/1.1
Host: 192.168.2.30
Sec-WebSocket-Key: MDEyMzQ1Njc4OWFiY2RlZg==
Upgrade: websocket
Connection: Upgrade
Sec-WebSocket-Version: 13
User-Agent: TinyWebsockets Client
Authorization: Basic 
Origin: https://github.com/khoih-prog/Websockets2_Generic
[WS] WebsocketsClient::connect: base64Authorization = 
[WS] WebsocketsClient::generateHandshake: key = Upgrade
[WS] WebsocketsClient::generateHandshake: value = websocket
[WS] WebsocketsClient::generateHandshake: key = Connection
[WS] WebsocketsClient::generateHandshake: value = Upgrade
[WS] WebsocketsClient::generateHandshake: key = Sec-WebSocket-Accept
[WS] WebsocketsClient::generateHandshake: value = BACScCJPNqyz+UBoqMH89VmURoA=
[WS] WebsocketsClient::generateHandshake: key = Origin
[WS] WebsocketsClient::generateHandshake: value = https://github.com/khoih-prog/Websockets2_Generic
Connection Opened
Connected!
Got Message: Hello to Server from RASPBERRY_PI_PICO_W
Got a Ping!
Got a Ping!
```

---
---

### Screenshots

1. This is the screenshot when running [STM32-Ethernet_AdvancedWebServer](examples/Generic/Ethernet/STM32/STM32-Ethernet_AdvancedWebServer) example on **STM32F7 Nucleo-144 F767ZI and built-in LAN8742A Ethernet** to demonstrate the new non-blocking feature of WebSockets Server enabling WebServer and WebSockets Server to run concurrently.

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/raw/master/pics/Web_WS_Server_STM32.png">
</p>

2. This is the screenshot when running [SAMD-AdvancedWebServer](examples/Generic/WiFiNINA/SAMD/SAMD-AdvancedWebServer) example on **Arduino SAMD21 Nano-33-IoT and built-in WiFiNINA** to demonstrate the new non-blocking feature of WebSockets Server enabling WebServer and WebSockets Server to run concurrently.

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/raw/master/pics/Web_WS_Server_Nano_33_IoT.png">
</p>

3. This is the screenshot when running [Esp32-AdvancedWebServer](examples/ESP32/Esp32-AdvancedWebServer) example on **ESP32-S2** to demonstrate the new non-blocking feature of WebSockets Server enabling WebServer and WebSockets Server to run concurrently.

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/raw/master/pics/Web_WS_Server_ESP32-S2.png">
</p>

4. This is the screenshot when running [WT32_ETH01_AdvancedWebServer](examples/WT32_ETH01/WT32_ETH01_AdvancedWebServer) on **WT32_ETH01 (ESP32 + LAN8720)** board to demonstrate the new non-blocking feature of WebSockets Server enabling WebServer and WebSockets Server to run concurrently.

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/raw/master/pics/Web_WS_Server_WT32_ETH01.png">
</p>

5. This is the screenshot when running [Portenta_H7-AdvancedWebServer](examples/Generic/Portenta_H7/WiFi/Portenta_H7-AdvancedWebServer) on **Portenta_H7** board, using WiFi, to demonstrate the new non-blocking feature of WebSockets Server enabling WebServer and WebSockets Server to run concurrently.

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/raw/master/pics/Web_WS_Server_Portenta_H7.png">
</p>

6. This is the screenshot when running [RP2040-AdvancedWebServer](examples/Generic/WiFiNINA/RP2040/RP2040-AdvancedWebServer) on **MBED NANO_RP2040_CONNECT** using WiFiNINA, to demonstrate the new non-blocking feature of WebSockets Server enabling WebServer and WebSockets Server to run concurrently.

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/raw/master/pics/Web_WS_Server_RP2040.png">
</p>

7. This is the screenshot when running [RP2040W-AdvancedWebServer](examples/Generic/RP2040W/RP2040W-AdvancedWebServer) on **RASPBERRY_PI_PICO_W** using built-in WiFi, to demonstrate the new non-blocking feature of WebSockets Server enabling WebServer and WebSockets Server to run concurrently.

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/raw/master/pics/Web_WS_Server_RP2040W.png">
</p>

---
---

### Debug

Debug is enabled by default on `Serial`. Debug Level from 0 to 4. To disable, change the `_WEBSOCKETS_LOGLEVEL_` to 0

```cpp
// Use this to output debug msgs to Serial
#define DEBUG_WEBSOCKETS_PORT     Serial
// Use this to disable all output debug msgs
//#define DEBUG_WEBSOCKETS_PORT
// Debug Level from 0 to 4
#define _WEBSOCKETS_LOGLEVEL_     3
```

---

## Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the board's core, applying `Libraries' Patches`, `Packages' Patches` or this library latest version.

---
---


### Issues

Submit issues to: [WebSockets2_Generic issues](https://github.com/khoih-prog/WebSockets2_Generic/issues)

---
---

### TO DO

 1. Support more boards
 2. Support ESP8266/ESP32-AT shields.
 3. Add SSL client support to Teensy, SAMD21/SAMD51 and nRF52 using WiFiNINA.
 4. Support more non-compatible Ethernet Libraries such as Ethernet_Shield_W5200, EtherCard, EtherSia
 5. Add mDNS features
 6. Support `ESP8266` using new `lwIP_w5500`, `lwIP_w5100` and `lwIP_enc28j60` Ethernet libraries
 7. Add SSL server / client support to Ethernet (W5x00, ENC28J60, QNEthernet, etc.)

---

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
16. Add support to Teensy using Ethernet libraries such as **Ethernet, Ethernet2, Ethernet3, EthernetLarge, EthernetENC, UIPEthernet**.
17. Add support to Teensy 4.1 using NativeEthernet libraries.
18. Add support to **Ethernet LAN8720** using [STM32Ethernet library](https://github.com/stm32duino/STM32Ethernet), for boards such as **Nucleo-144 (F429ZI, NUCLEO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG), Discovery (DISCO_F746NG)** and **STM32F4 boards (BLACK_F407VE, BLACK_F407VG, BLACK_F407ZE, BLACK_F407ZG, BLACK_F407VE_Mini, DIYMORE_F407VGT, FK407M1)**
19. Add support to **ESP32-S2**
20. Update to use [Latest esp32 core v1.0.6](https://github.com/espressif/arduino-esp32/releases/tag/1.0.6).
21. Add support to **ESP32-C3**
21. Add InSecure mode for **ESP32**
22. Add support to MKR1000 / MKR1010WiFi boards using [**Forked WiFi101** library](https://github.com/khoih-prog/WiFi101)
23. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Earle Philhower's arduino-pico core** v1.3.1+](https://github.com/earlephilhower/arduino-pico).
24. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed).
25. Add support to **WT32_ETH01 boards** using ESP32-based boards and LAN8720 Ethernet
26. Add support to Teensy 4.1 built-in Ethernet using [`QNEthernet`](https://github.com/ssilverman/QNEthernet) library
27. Add support to **Portenta_H7**, using either `Murata WiFi` or `Vision-shield Ethernet`
28. Add support to **RP2040-based boards, such as Nano_RP2040_Connect, RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040**, using WiFiNINA
29. Auto detect ESP32 core to use for WT32_ETH01
30. Fix bug in WT32_ETH01 examples to reduce connection time
31. Reduce QNEthernet latency
32. Fix bug when using `QNEthernet` staticIP. 
32. Add staticIP option to `NativeEthernet` examples
33. Use new [**Ethernet_Generic** library](https://github.com/khoih-prog/Ethernet_Generic) as default for W5x00.
34. Support **SPI2 for ESP32**
35. Add support to SPI1 for RP2040 using [arduino-pico core](https://github.com/earlephilhower/arduino-pico)
36. Use new `waitForLink()` function of QNEthernet
37. Add support to `ESP32` using either `W5x00` or `ENC28J60` Ethernet
38. Add support to ENC28J60 using `EthernetENC` or `UIPEthernet` Library for these supported boards: **ESP32, nRF52, RP2040, SAM DUE, SAMD, STM32, Teensy**
39. Add support to `RP2040W` using `CYW43439 WiFi` or `Ethernet` with `arduino-pico` core
40. Add astyle using `allman` style. Restyle the library 
41. Using new [`WiFi101_Generic library`](https://github.com/khoih-prog/WiFi101_Generic) for sending larger data

---
---

### Contributions and Thanks

1. Based on and modified from [Gil Maimon's ArduinoWebsockets](https://github.com/gilmaimon/ArduinoWebsockets)
2. Thanks to good work of [Miguel Alexandre Wisintainer](https://github.com/tcpipchip) for initiating, inspriring, working with, developing, debugging and testing. Without that, support to nRF52, especially **NINA_B302_ublox running as nRF52840 and NINA_B112_ublox running as nRF52832**, has never been started and finished. See [u-blox nina b](https://github.com/khoih-prog/WiFiNINA_Generic/issues/1)
3. Thanks to bug report and persistence of [Jake](https://github.com/jakespeed1311) to help identify and add **non-blocking WebSockets Server** feature to v1.0.6 to enable WS Server and WebServer running **concurrently**. See [**Support as Http server and the Websockets server on Arduino DUE**](https://github.com/khoih-prog/WebSockets_Generic/issues/1) and [**Running Http and Websocket Servers concurrently**](https://github.com/khoih-prog/WebSockets2_Generic/issues/1). 
4. Thanks to [arnoson](https://github.com/arnoson) code posted in [ArduinoWebsockets release 0.5.0](https://github.com/gilmaimon/ArduinoWebsockets/releases/tag/0.5.0) to provide support to Teensy 4.1 using NativeEthernet.
5. Thanks [Lionel REICHERT](https://github.com/LioRei) for PR [**Add setInsecure for esp32** #18](https://github.com/khoih-prog/WebSockets2_Generic/pull/18) leading to v1.2.4.
6. Thanks to [Jose A.Molina](https://github.com/Josua2012) for the enhancement request [**MKR1000 and WIFI problem and another problem** #20](https://github.com/khoih-prog/WebSockets2_Generic/issues/20), and help testing, leading to new version v1.3.0 to support WiFi101 and MKD1000 / MKR1010WiFi boards.
7. Thanks to [Robert Viens](https://github.com/Sirpercal) for posting the issue [**Compile error with Arduino Nano RP2040** #32](https://github.com/khoih-prog/WebSockets2_Generic/issues/32), leading to v1.8.0.
8. Thanks [Shawn Silverman](https://github.com/ssilverman), [QNEthernet library](https://github.com/ssilverman/QNEthernet) author, for 

	- PR [**Fix QNEthernet TCP interface** #35](https://github.com/khoih-prog/WebSockets2_Generic/pull/35) leading to v1.9.1
	- suggestion to fix [**QNEthernet and NativeEthernet staticIP not working with WS Server** #39](https://github.com/khoih-prog/WebSockets2_Generic/issues/39) leading to v1.10.2
	
9. Thanks [5b4wn](https://github.com/5b4wn) for issue report and proposed fix in [**QNEthernet higher latency** #38](https://github.com/khoih-prog/WebSockets2_Generic/issues/38) leading to v1.10.1


<table>
  <tr>
    <td align="center"><a href="https://github.com/gilmaimon"><img src="https://github.com/gilmaimon.png" width="100px;" alt="gilmaimon"/><br /><sub><b>⭐️⭐️ Gil Maimon</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/tcpipchip"><img src="https://github.com/tcpipchip.png" width="100px;" alt="tcpipchip"/><br /><sub><b>⭐️ Miguel Wisintainer</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/jakespeed1311"><img src="https://github.com/jakespeed1311.png" width="100px;" alt="jakespeed1311"/><br /><sub><b>Jake</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/arnoson"><img src="https://github.com/arnoson.png" width="100px;" alt="arnoson"/><br /><sub><b>arnoson</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/LioRei"><img src="https://github.com/LioRei.png" width="100px;" alt="LioRei"/><br /><sub><b>Lionel REICHERT</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/Josua2012"><img src="https://github.com/Josua2012.png" width="100px;" alt="Josua2012"/><br /><sub><b>Jose A. Molina</b></sub></a><br /></td>
  </tr> 
  <tr>
    <td align="center"><a href="https://github.com/Sirpercal"><img src="https://github.com/Sirpercal.png" width="100px;" alt="Sirpercal"/><br /><sub><b>Robert Viens</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/ssilverman"><img src="https://github.com/ssilverman.png" width="100px;" alt="ssilverman"/><br /><sub><b>Shawn Silverman</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/5b4wn"><img src="https://github.com/5b4wn.png" width="100px;" alt="5b4wn"/><br /><sub><b>5b4wn</b></sub></a><br /></td>
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

- Many of the credits go to original author [**Gil Maimon**](https://github.com/gilmaimon) as well as contributors in original library [ArduinoWebsockets Contributors](https://github.com/gilmaimon/ArduinoWebsockets#contributors)

- The library is licensed under [GPLv3.0](https://github.com/khoih-prog/WebSockets2_Generic/blob/master/LICENSE)

- `base64` written by René Nyffenegger.

---

## Copyright

1. Copyright (c) 2019- Gil Maimon
2. Copyright (c) 2020- Khoi Hoang


