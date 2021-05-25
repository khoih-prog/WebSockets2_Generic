## WebSockets2_Generic

[![arduino-library-badge](https://www.ardu-badge.com/badge/WebSockets2_Generic.svg?)](https://www.ardu-badge.com/WebSockets2_Generic)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/WebSockets2_Generic.svg)](https://github.com/khoih-prog/WebSockets2_Generic/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/WebSockets2_Generic/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/WebSockets2_Generic.svg)](http://github.com/khoih-prog/WebSockets2_Generic/issues)

---
---

## Table of Contents

* [Why do we need this WebSockets2_Generic library](#why-do-we-need-this-websockets2_generic-library)
  * [Features](#features)
  * [Supported features of RFC6455](#supported-features-of-rfc6455)
  * [Currently supported Boards](#currently-supported-boards)
  * [Currently supported WiFi shields/modules](#currently-supported-wifi-shieldsmodules)
  * [Currently supported Ethernet shields/modules](#currently-supported-ethernet-shieldsmodules)
* [Changelog](#changelog)
  * [Major Release v1.4.0](#major-release-v140)
  * [Release v1.3.0](#release-v130)
  * [Release v1.2.4](#release-v124)
  * [Release v1.2.3](#release-v123)
  * [Release v1.2.2](#release-v122)
  * [Release v1.2.1](#release-v121)
  * [Major Release v1.2.0](#major-release-v120)
  * [Major Release v1.1.0](#major-release-v110)
  * [Release v1.0.7](#release-v107)
  * [Release v1.0.6](#release-v106)
  * [Release v1.0.5](#release-v105)
  * [Release v1.0.4](#release-v104)
  * [Release v1.0.3](#release-v103)
  * [Release v1.0.2](#release-v102)
  * [Release v1.0.1](#release-v101)
  * [Release v1.0.0](#release-v100)
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
* [Libraries' Patches](#libraries-patches)
  * [1. For application requiring 2K+ HTML page](#1-for-application-requiring-2k-html-page)
  * [2. For Ethernet library](#2-for-ethernet-library)
  * [3. For EthernetLarge library](#3-for-ethernetlarge-library)
  * [4. For Etherne2 library](#4-for-ethernet2-library)
  * [5. For Ethernet3 library](#5-for-ethernet3-library)
  * [6. For UIPEthernet library](#6-for-uipethernet-library)
    * [Optional UIPEthernet patch](#optional-uipethernet-patch)
  * [7. For fixing ESP32 compile error](#7-for-fixing-esp32-compile-error)
  * [8. For fixing ESP8266 compile error](#8-for-fixing-esp8266-compile-error)
* [HOWTO Install esp32 core for ESP32-S2 (Saola, AI-Thinker ESP-12K) and ESP32-C3 boards into Arduino IDE](#howto-install-esp32-core-for-esp32-s2-saola-ai-thinker-esp-12k-and-esp32-c3-boards-into-arduino-ide)
  * [1. Save the original esp32 core](#1-save-the-original-esp32-core)
  * [2. Install esp32 core v1.0.6](#2-install-esp32-core-v106)
    * [2.1 Install esp32 core](#21-install-esp32-core)
    * [2.2 Download latest zip with esp32-s2 support](#22-download-latest-zip-with-esp32-s2-support)
    * [2.3 Unzip](#23-unzip)
    * [2.3 Update esp32 core directories](#24-update-esp32-core-directories)
  * [3. Download tools for ESP32-S2](#3-download-tools-for-esp32-s2) 
    * [3.1 Download Toolchain for Xtensa (ESP32-S2) based on GCC](#31-download-toolchain-for-xtensa-esp32-s2-based-on-gcc)
    * [3.2 Download esptool](#32-download-esptool)
    * [3.3 Unzip](#33-unzip)
  * [4. Update tools](#4-update-tools)
    * [4.1 Update Toolchain](#41-update-toolchain)
    * [4.2 Update esptool](#42-update-esptool)
  * [5. Download tools for ESP32-C3](#5-download-tools-for-esp32-c3)
  * [6. esp32-s2 WebServer Library Patch](#6-esp32-s2-webserver-library-patch)
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
* [For STM32F/L/H/G/WB/MP1 using Ethernet W5x0, ENC28J60, LAN8720 or LAN8742A](#for-stm32flhgwbmp1--using-ethernet-w5x0-enc28j60-lan8720-or-lan8742a)
* [For Teensy 4.1, 4.0, 3.x using Ethernet W5x0, ENC28J60 or LAN8742A](#for-teensy-41-40-3x-using-ethernet-w5x0-enc28j60-or-lan8742a)
* [For Teensy 4.1 using NativeEthernet](#for-teensy-41-using-nativeethernet)
* [To use ESP8266/ESP32 native WiFi](#to-use-esp8266esp32-native-wifi)
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
  * [For RP2040 boards using Ethernet (W5x00 or ENC28J60)](#for-rp2040-boards-using-ethernet-w5x00-or-enc28j60). **New**
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
* [Releases](#releases)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License and credits](#license-and-credits)
* [Copyright](#copyright)


### Why do we need this [WebSockets2_Generic library](https://github.com/khoih-prog/WebSockets2_Generic)

#### Features

Many Web services require WebSockets library, which is so far written only for ESP8266/ESP32 boards. The ESP boards so far rely on the [**Markus Sattler's WebSockets Library**](https://github.com/Links2004/arduinoWebSockets) to connect to Alexa via Sinric or SinricPro skills.

This [**WebSockets2_Generic library**](https://github.com/khoih-prog/WebSockets2_Generic) is based on and modified from [**Gil Maimon's ArduinoWebSockets Library**](https://github.com/gilmaimon/ArduinoWebsockets) to provide support to many more boards, such as **Arduino SAMD21, Adafruit SAMD21/SAMD51, Seeeduino SAMD21/SAMD51, nRF52, STM32F/L/H/G/WB/MP1, Teensy, SAM DUE, etc.** and enable those boards to use WebSockets services, including voice-controlled Alexa along with Blynk. Those supported boards can also run **WebSockets Server.** The WebSockets can be used with **ESP’s WiFi, WiFiNINA, WiFi101, W5x00/ENC28J60/LAN8742A Ethernet, ESP8266/ESP32-AT modules/shields.**

Please see [the TinyWebsockets wiki](https://github.com/gilmaimon/TinyWebsockets/wiki) for roughly-accurate information about the API not covered here.

#### Supported features of RFC6455

 - text frame
 - binary frame
 - connection close
 - ping
 - pong
 - continuation frame
 
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

 7. **ESP32**
 8. **ESP8266**
 
 9. RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** v2.1.0+ core](https://github.com/arduino/ArduinoCore-mbed) or [**Earle Philhower's arduino-pico** core v1.5.1+](https://github.com/earlephilhower/arduino-pico).


#### Currently supported WiFi shields/modules

1. WiFiNINA using [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic)
2. WiFi101 using [`WiFi101 library v0.16.1+`](https://github.com/arduino-libraries/WiFi101)
3. U-Blox W101, W102 using [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic)
4. ESP32 and ESP8266 WiFi

#### Currently supported Ethernet shields/modules

1. W5x00 using [`Ethernet`](https://www.arduino.cc/en/Reference/Ethernet), [`EthernetLarge`](https://github.com/OPEnSLab-OSU/EthernetLarge), [`Ethernet2`](https://github.com/adafruit/Ethernet2) or [`Ethernet3`](https://github.com/sstaub/Ethernet3) library
2. ENC28J60 using [`EthernetENC`](https://github.com/jandrassy/EthernetENC) or [`UIPEthernet`](https://github.com/UIPEthernet/UIPEthernet) library
3. Teensy 4.1 built-in NativeEthernet using [NativeEthernet Library](https://github.com/vjmuzik/NativeEthernet)


---
---

## Changelog

### Major Release v1.4.0

1. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Earle Philhower's arduino-pico** v1.5.1+ core](https://github.com/earlephilhower/arduino-pico).
2. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** v2.1.0+ core](https://github.com/arduino/ArduinoCore-mbed).
4. Add examples with new features

### Release v1.3.0

1. Add support to WiFi101. To be used with [**Forked WiFi101** library](https://github.com/khoih-prog/WiFi101)
2. Check compatibility with new ESP8266 core v3.0.0
3. Suppress warnings

### Release v1.2.4

1. Add InSecure mode for ESP32. For more info, check [**Add setInsecure for esp32** #18](https://github.com/khoih-prog/WebSockets2_Generic/pull/18)
2. Add InSecude-mode examples for ESP32/ESP8266

### Release v1.2.3

1. Update `websocket.org` `letsenrypt.org` CA Certs and Fingerprint for EP32 and ESP8266 secured exampled.

### Release v1.2.2

1. Add support to new **ESP32-C3** boards (**Arduino ESP32C3_DEV**). Check [HOWTO Install esp32 core for ESP32-S2 (Saola, AI-Thinker ESP-12K) and ESP32-C3 boards into Arduino IDE](#howto-install-esp32-core-for-esp32-s2-saola-ai-thinker-esp-12k-and-esp32-c3-boards-into-arduino-ide).


### Release v1.2.1

1. Add support to new ESP32-S2 boards (**SparkFun ESP32-S2 Thing Plus; Adafruit Metro ESP32-S2, MagTag 2.9, FunHouse, Feather ESP32-S2 (no PSRAM)**). Drop support to **UM ProS2**
2. Add HTTP and WebSockets Server support to **ESP32-S2** (ESP32-S2 Saola, AI-Thinker ESP-12K, etc.)

### Major Release v1.2.0

1. Add limited (client-only) support to **LAN8720** Ethernet for **STM32F4 (F407xx, NUCLEO_F429ZI) and STM32F7** (DISCO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG) boards.
2. Add LAN8720 examples
3. Add Packages' Patches for STM32 to use LAN8720 with STM32Ethernet and LwIP libraries
4. Update `echo.websocket.org` **fingerprint add CA Certificate** for ESP8266 and ESP32. Check [Secured-Esp32-Client Example not works on NodeMcu32s (Esp32s) #16](https://github.com/khoih-prog/WebSockets2_Generic/issues/16)
5. Add limited (client-only) support to **ESP32-S2** (ESP32-S2 Saola, AI-Thinker ESP-12K, etc.)
6. Update [HOWTO Install esp32-s2 core for ESP32-S2](https://github.com/khoih-prog/WebSockets2_Generic#howto-install-esp32-s2-core-for-esp32-s2-saola-ai-thinker-esp-12k-boards-into-arduino-ide) to accomodate [Latest esp32 core v1.0.6](https://github.com/espressif/arduino-esp32/releases/tag/1.0.6)
7. Update README to reflect [`LittleFS_esp32 library`](https://github.com/lorol/LITTLEFS) has been included in [Latest esp32 core v1.0.6](https://github.com/espressif/arduino-esp32/releases/tag/1.0.6) and many steps are not necessary anymore

### Major Release v1.1.0

1. Add support to **Teensy using Ethernet libraries** such as **Ethernet, Ethernet2, Ethernet3, EthernetLarge, EthernetENC, UIPEthernet**.
2. Add support to **Teensy 4.1 using NativeEthernet library**. Thanks to [**arnoson**](https://github.com/arnoson) code posted in [ArduinoWebsockets release 0.5.0](https://github.com/gilmaimon/ArduinoWebsockets/releases/tag/0.5.0)
3. Add Version String

### Release v1.0.7

1. Add support to ENC28J60 Ethernet using **EthernetENC**.
2. Add Ethernet Library Patches for **UIPEthernet v2.0.9 and Ethernet2**
3. Update Platform.ini to support **PlatformIO 5.x owner-based dependency declaration**.

#### Release v1.0.6

1. Add **non-blocking WebSockets Server** feature to enable WS Server and WebServer running **concurrently**. See [**Support as Http server and the Websockets server on Arduino DUE**](https://github.com/khoih-prog/WebSockets_Generic/issues/1) and [**Running Http and Websocket Servers concurrently**](https://github.com/khoih-prog/WebSockets2_Generic/issues/1). Thanks to bug report and persistence of [Jake](https://github.com/jakespeed1311).
2. Add non-blocking WebSockets Server and WebServer examples. 
3. Add Ethernet Library Patches
4. Add Arduino SAMD Packages_Patches to fix compiler errors when using [Standard Template Library STL](https://en.wikipedia.org/wiki/Standard_Template_Library)

#### Release v1.0.5

1. Sync with [ArduinoWebsockets v0.4.18](https://github.com/gilmaimon/ArduinoWebsockets/releases/tag/0.4.18) to fix ESP8266 SSL bug. See [Secured-Two-Way: Client certificate is not sent if used along with setTrustAnchors](https://github.com/gilmaimon/ArduinoWebsockets/issues/84)

#### Release v1.0.4

1. Add support to all **STM32F/L/H/G/WB/MP1 (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8, etc.)**
2. Add support to **Seeeduino SAMD21/SAMD51 boards (SEEED_WIO_TERMINAL, SEEED_FEMTO_M0, SEEED_XIAO_M0, Wio_Lite_MG126, WIO_GPS_BOARD, SEEEDUINO_ZERO, SEEEDUINO_LORAWAN, SEEED_GROVE_UI_WIRELESS, etc.)**
3. Add sample Packages_Patches for **STM32 stm32** (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8)
4. Add Packages' Patches for **Seeeduino SAMD** to enable displaying **BOARD_NAME**
5. Add many examples
                                  
#### Release v1.0.3

1. Add support to STM32F boards with built-in Ethernet such as :
  - **Nucleo-144 (F429ZI, F767ZI)**
  - **Discovery (STM32F746G-DISCOVERY)**
  - **All STM32F Boards with Built-in Ethernet LAN8742A**

2. Add support to **STM32F1,2,3,4,7 boards (with 64+K Flash)** using **Ethernet W5x00, ENC28J60 or LAN8742A**
3. Add Packages' Patches to **Adafruit nRF52, SAMD, Arduino SAMD** to enable displaying **BOARD_NAME**
4. Enhance examples and update README.md

#### Release v1.0.2

1. Add support to **Ethernet ENC28J60, using UIPEthernet library**, for nRF52, SAMD21/SAMD51 and SAM DUE boards.

#### Release v1.0.1

1. Add support to **SAM DUE** boards.
2. Add support to **Ethernet W5x00, using either Ethernet, EthernetLarge or Ethernet2 library.**
3. Restructure code to provide flexibility to support many more WiFi/Ethernet modules/shields in the future. Please delete the *.cpp files, replaced with coresponding *.hpp files, in the library src directory, if the *.cpp files still exist after installing new version.

#### Release v1.0.0

1. Add support to **nRF52** boards, such as **AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc.**,  using WiFiNINA with [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic)
2. Add support to **SAMD51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)** , using WiFiNINA with [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic).
3. Add support to **SAMD21 (ZERO, MKR, NANO_33_IOT, M0, M0 Pro, AdaFruit CIRCUITPLAYGROUND_EXPRESS, etc.)**, using WiFiNINA with [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic).
4. Add Alexa/[`SINRIC`](https://sinric.com) examples and supports to those boards as well as ESP8266/ESP32

---
---
 
## Prerequisites

 1. [`Arduino IDE v1.8.13+`](https://www.arduino.cc/en/Main/Software)
 2. [`ESP32 Core 1.0.6+`](https://github.com/espressif/arduino-esp32) for ESP32-based boards. [![Latest release](https://img.shields.io/github/release/espressif/arduino-esp32.svg)](https://github.com/espressif/arduino-esp32/releases/latest/)
 3. [`ESP32-S2/C3 Core 1.0.6+`](https://github.com/espressif/arduino-esp32) for ESP32-S2/C3-based boards. Must follow [HOWTO Install esp32 core for ESP32-S2 (Saola, AI-Thinker ESP-12K) and ESP32-C3 boards into Arduino IDE](#howto-install-esp32-core-for-esp32-s2-saola-ai-thinker-esp-12k-and-esp32-c3-boards-into-arduino-ide).
 4. [`ESP8266 Core 3.0.0+`](https://github.com/esp8266/Arduino) for ESP8266-based boards. [![Latest release](https://img.shields.io/github/release/esp8266/Arduino.svg)](https://github.com/esp8266/Arduino/releases/latest/). To use ESP8266 core 2.7.1+ for LittleFS. 
 5. [`Arduino AVR core 1.8.3+`](https://github.com/arduino/ArduinoCore-avr) for Arduino (Use Arduino Board Manager) for AVR boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-avr.svg)](https://github.com/arduino/ArduinoCore-avr/releases/latest)
 6. [`Teensy core v1.53+`](https://www.pjrc.com/teensy/td_download.html) for Teensy (4.1, 4.0, 3.6, 3.5, 3,2, 3.1, 3.0) boards. **Ready** from v1.0.0.
 7. [`Arduino SAM DUE core v1.6.12+`](https://github.com/arduino/ArduinoCore-sam) for SAM DUE ARM Cortex-M3 boards.
 8. [`Arduino SAMD core 1.8.11+`](https://github.com/arduino/ArduinoCore-samd) for SAMD ARM Cortex-M0+ boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-samd.svg)](https://github.com/arduino/ArduinoCore-samd/releases/latest)
 9. [`Adafruit SAMD core 1.7.1+`](https://github.com/adafruit/ArduinoCore-samd) for SAMD ARM Cortex-M0+ and M4 boards (Nano 33 IoT, etc.). [![GitHub release](https://img.shields.io/github/release/adafruit/ArduinoCore-samd.svg)](https://github.com/adafruit/ArduinoCore-samd/releases/latest)
10. [`Seeeduino SAMD core 1.8.1+`](https://github.com/Seeed-Studio/ArduinoCore-samd) for SAMD21/SAMD51 boards (XIAO M0, Wio Terminal, etc.). [![Latest release](https://img.shields.io/github/release/Seeed-Studio/ArduinoCore-samd.svg)](https://github.com/Seeed-Studio/ArduinoCore-samd/releases/latest/)
11. [`Adafruit nRF52 v0.22.0+`](https://github.com/adafruit/Adafruit_nRF52_Arduino) for nRF52 boards such as Adafruit NRF52840_FEATHER, NRF52832_FEATHER, NRF52840_FEATHER_SENSE, NRF52840_ITSYBITSY, NRF52840_CIRCUITPLAY, NRF52840_CLUE, NRF52840_METRO, NRF52840_PCA10056, PARTICLE_XENON, **NINA_B302_ublox**, etc. [![GitHub release](https://img.shields.io/github/release/adafruit/Adafruit_nRF52_Arduino.svg)](https://github.com/adafruit/Adafruit_nRF52_Arduino/releases/latest)
12. [`Arduino Core for STM32 v2.0.0+`](https://github.com/stm32duino/Arduino_Core_STM32) for STM32F/L/H/G/WB/MP1 boards. [![GitHub release](https://img.shields.io/github/release/stm32duino/Arduino_Core_STM32.svg)](https://github.com/stm32duino/Arduino_Core_STM32/releases/latest)
13. [`Arduino mbed_rp2040 core 2.1.0+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino (Use Arduino Board Manager) RP2040-based boards, such as RASPBERRY_PI_PICO. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)
14. [`Earle Philhower's arduino-pico core v1.5.1+`](https://github.com/earlephilhower/arduino-pico) for RP2040-based boards such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, etc. [![GitHub release](https://img.shields.io/github/release/earlephilhower/arduino-pico.svg)](https://github.com/earlephilhower/arduino-pico/releases/latest)
15. [`WiFiNINA_Generic library v1.8.5+`](https://github.com/khoih-prog/WiFiNINA_Generic) if for WiFiNINA. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiNINA_Generic.svg?)](https://www.ardu-badge.com/WiFiNINA_Generic).
16. [`EthernetWebServer library v1.5.0+`](https://github.com/khoih-prog/EthernetWebServer) if necessary to use Ethernet modules/shields. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer.svg?)](https://www.ardu-badge.com/EthernetWebServer)
17. Depending on which Ethernet module/shield you're using :
   - [`Ethernet library v2.0.0+`](https://github.com/arduino-libraries/Ethernet) for W5100, W5200 and W5500.  [![GitHub release](https://img.shields.io/github/release/arduino-libraries/Ethernet.svg)](https://github.com/arduino-libraries/Ethernet/releases/latest)
   - [`EthernetLarge library v2.0.0+`](https://github.com/OPEnSLab-OSU/EthernetLarge) for W5100, W5200 and W5500.
   - [`Ethernet2 library v1.0.4+`](https://github.com/khoih-prog/Ethernet2) for W5500. [![GitHub release](https://img.shields.io/github/release/adafruit/Ethernet2.svg)](https://github.com/adafruit/Ethernet2/releases/latest)
   - [`Ethernet3 library v1.5.5+`](https://github.com/sstaub/Ethernet3) for W5500/WIZ550io/WIZ850io/USR-ES1 with Wiznet W5500 chip. [![GitHub release](https://img.shields.io/github/release/sstaub/Ethernet3.svg)](https://github.com/sstaub/Ethernet3/releases/latest)
   - [`EthernetENC library v2.0.1+`](https://github.com/jandrassy/EthernetENC) for ENC28J60. [![GitHub release](https://img.shields.io/github/release/jandrassy/EthernetENC.svg)](https://github.com/jandrassy/EthernetENC/releases/latest). **New and Better**
   - [`UIPEthernet library v2.0.10+`](https://github.com/UIPEthernet/UIPEthernet) for ENC28J60. [![GitHub release](https://img.shields.io/github/release/UIPEthernet/UIPEthernet.svg)](https://github.com/UIPEthernet/UIPEthernet/releases/latest)
   - [`STM32Ethernet library v1.2.0+`](https://github.com/stm32duino/STM32Ethernet) for LAN8720 or built-in LAN8742A Ethernet on STM32. [![GitHub release](https://img.shields.io/github/release/stm32duino/STM32Ethernet.svg)](https://github.com/stm32duino/STM32Ethernet/releases/latest). To be used with [`LwIP library v2.1.2+`](https://github.com/stm32duino/LwIP). [![GitHub release](https://img.shields.io/github/release/stm32duino/LwIP.svg)](https://github.com/stm32duino/LwIP/releases/latest). 
   - [`NativeEthernet Library version stable111+`](https://github.com/vjmuzik/NativeEthernet) for Teensy 4.1 built-in NativeEthernet
18. [`ESP_AT_Lib library v1.2.0+`](https://github.com/khoih-prog/ESP_AT_Lib) if necessary to use ESP8288/ESP32-AT shields. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/ESP_AT_Lib.svg?)](https://www.ardu-badge.com/ESP_AT_Lib). **Not yet ready**.
19. [`WiFiWebServer library v1.1.1+`](https://github.com/khoih-prog/WiFiWebServer) if necessary to use certain WiFi/WiFiNINA features. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiWebServer.svg?)](https://www.ardu-badge.com/WiFiWebServer)
20. [`FlashStorage_SAMD library v1.1.0+`](https://github.com/khoih-prog/FlashStorage_SAMD) for SAMD21 and SAMD51 boards (ZERO, MKR, NANO_33_IOT, M0, M0 Pro, AdaFruit Itsy-Bitsy M4, etc.). [![GitHub release](https://img.shields.io/github/release/khoih-prog/FlashStorage_SAMD.svg)](https://github.com/khoih-prog/FlashStorage_SAMD/releases/latest) if necessary to use certain features.
21. [`FlashStorage_STM32 library v1.1.0+`](https://github.com/khoih-prog/FlashStorage_STM32) for STM32F/L/H/G/WB/MP1 boards. [![GitHub release](https://img.shields.io/github/release/khoih-prog/FlashStorage_STM32.svg)](https://github.com/khoih-prog/FlashStorage_STM32/releases/latest) if necessary to use certain features.
22. [`DueFlashStorage library v1.0.0+`](https://github.com/sebnil/DueFlashStorage) for SAM DUE. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/DueFlashStorage.svg?)](https://www.ardu-badge.com/DueFlashStorage) if necessary to use certain features.
23. [`Adafruit's LittleFS/InternalFS`](https://www.adafruit.com) for nRF52. Already included if you already installed Adafruit **nRF52 board package** from Boards Manager.
24. [`DoubleResetDetector_Generic v1.2.0+`](https://github.com/khoih-prog/DoubleResetDetector_Generic) if necessary to use some examples. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/DoubleResetDetector_Generic.svg?)](https://www.ardu-badge.com/DoubleResetDetector_Generic) if necessary to use certain features.
25. [`Modified WiFi101 Library v0.16.1+`](https://github.com/khoih-prog/WiFi101) to use SAMD MKR1000, etc. boards with WiFi101.

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
3. Install [**WebSockets2_Generic** library](https://platformio.org/lib/show/11239/WebSockets2_Generic) by using [Library Manager](https://platformio.org/lib/show/11239/WebSockets2_Generic/installation). Search for **WebSockets2_Generic** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---
---

### Packages' Patches

#### 1. For Adafruit nRF52840 and nRF52832 boards

**To be able to compile, run and automatically detect and display BOARD_NAME on nRF52840/nRF52832 boards**, you have to copy the whole [nRF52 0.22.0](Packages_Patches/adafruit/hardware/nrf52/0.22.0) directory into Adafruit nRF52 directory (~/.arduino15/packages/adafruit/hardware/nrf52/0.22.0). 

Supposing the Adafruit nRF52 version is 0.22.0. These files must be copied into the directory:
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.22.0/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.22.0/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.22.0/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.22.0/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.22.0/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.22.0/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/0.22.0/cores/nRF5/Udp.h`**

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z
These files must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`**

#### 2. For Teensy boards
 
 **To be able to compile and run on Teensy boards**, you have to copy the files in [**Packages_Patches for Teensy directory**](Packages_Patches/hardware/teensy/avr) into Teensy hardware directory (./arduino-1.8.13/hardware/teensy/avr/boards.txt). 

Supposing the Arduino version is 1.8.13. These files must be copied into the directory:

- `./arduino-1.8.13/hardware/teensy/avr/boards.txt`
- `./arduino-1.8.13/hardware/teensy/avr/cores/teensy/Stream.h`
- `./arduino-1.8.13/hardware/teensy/avr/cores/teensy3/Stream.h`
- `./arduino-1.8.13/hardware/teensy/avr/cores/teensy4/Stream.h`

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
 
 ***To be able to compile without error and automatically detect and display BOARD_NAME on Arduino SAMD (Nano-33-IoT, etc) boards***, you have to copy the whole [Arduino SAMD cores 1.8.11](Packages_Patches/arduino/hardware/samd/1.8.11) directory into Arduino SAMD directory (~/.arduino15/packages/arduino/hardware/samd/1.8.11).
 
#### For core version v1.8.10+

Supposing the Arduino SAMD version is 1.8.11. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.11/platform.txt`

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
 
 ***To be able to automatically detect and display BOARD_NAME on Adafruit SAMD (Itsy-Bitsy M4, etc) boards***, you have to copy the file [Adafruit SAMD platform.txt](Packages_Patches/adafruit/hardware/samd/1.7.1) into Adafruit samd directory (~/.arduino15/packages/adafruit/hardware/samd/1.7.1). 

Supposing the Adafruit SAMD core version is 1.7.1. This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/1.7.1/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/platform.txt`

#### 6. For Seeeduino SAMD boards
 
 ***To be able to automatically detect and display BOARD_NAME on Seeeduino SAMD (XIAO M0, Wio Terminal, etc) boards***, you have to copy the file [Seeeduino SAMD platform.txt](Packages_Patches/Seeeduino/hardware/samd/1.8.1) into Adafruit samd directory (~/.arduino15/packages/Seeeduino/hardware/samd/1.8.1). 

Supposing the Seeeduino SAMD core version is 1.8.1. This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.1/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/platform.txt`

#### 7. For STM32 boards

#### 7.1 For STM32 boards to use LAN8720

To use LAN8720 on some STM32 boards 

- **Nucleo-144 (F429ZI, NUCLEO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG)**
- **Discovery (DISCO_F746NG)**
- **STM32F4 boards (BLACK_F407VE, BLACK_F407VG, BLACK_F407ZE, BLACK_F407ZG, BLACK_F407VE_Mini, DIYMORE_F407VGT, FK407M1)**

you have to copy the files [stm32f4xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/1.9.0/system/STM32F4xx) and [stm32f7xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/1.9.0/system/STM32F7xx) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/1.9.0/system) to overwrite the old files.

Supposing the STM32 stm32 core version is 1.9.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/system/STM32F4xx/stm32f4xx_hal_conf_default.h` for STM32F4.
- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/system/STM32F7xx/stm32f7xx_hal_conf_default.h` for Nucleo-144 STM32F7.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
theses files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F4xx/stm32f4xx_hal_conf_default.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F7xx/stm32f7xx_hal_conf_default.h


#### 7.2 For STM32 boards to use Serial1

**To use Serial1 on some STM32 boards without Serial1 definition (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8, etc.) boards**, you have to copy the files [STM32 variant.h](Packages_Patches/STM32/hardware/stm32/1.9.0) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/1.9.0). You have to modify the files corresponding to your boards, this is just an illustration how to do.

Supposing the STM32 stm32 core version is 1.9.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/variants/NUCLEO_F767ZI/variant.h` for Nucleo-144 NUCLEO_F767ZI.
- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/variants/NUCLEO_L053R8/variant.h` for Nucleo-64 NUCLEO_L053R8.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
theses files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/NUCLEO_F767ZI/variant.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/NUCLEO_L053R8/variant.h`

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

#### 3. For EthernetLarge library

To fix [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge), just copy these following files into the [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge) directory to overwrite the old files:
- [EthernetLarge.h](LibraryPatches/EthernetLarge/src/EthernetLarge.h)
- [EthernetLarge.cpp](LibraryPatches/EthernetLarge/src/EthernetLarge.cpp)
- [EthernetServer.cpp](LibraryPatches/EthernetLarge/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/EthernetLarge/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/EthernetLarge/src/utility/w5100.cpp)


#### 4. For Ethernet2 library

To fix [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2), just copy these following files into the [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2) directory to overwrite the old files:

- [Ethernet2.h](LibraryPatches/Ethernet2/src/Ethernet2.h)
- [Ethernet2.cpp](LibraryPatches/Ethernet2/src/Ethernet2.cpp)

To add UDP Multicast support, necessary for the [**UPnP_Generic library**](https://github.com/khoih-prog/UPnP_Generic):

- [EthernetUdp2.h](LibraryPatches/Ethernet2/src/EthernetUdp2.h)
- [EthernetUdp2.cpp](LibraryPatches/Ethernet2/src/EthernetUdp2.cpp)

#### 5. For Ethernet3 library

To fix [`Ethernet3 library`](https://github.com/sstaub/Ethernet3), just copy these following files into the [`Ethernet3 library`](https://github.com/sstaub/Ethernet3) directory to overwrite the old files:
- [Ethernet3.h](LibraryPatches/Ethernet3/src/Ethernet3.h)
- [Ethernet3.cpp](LibraryPatches/Ethernet3/src/Ethernet3.cpp)

#### 6. For UIPEthernet library

***To be able to compile and run on nRF52 boards with ENC28J60 using UIPEthernet library***, you have to copy these following files into the UIPEthernet `utility` directory to overwrite the old files:

- [UIPEthernet.h](LibraryPatches/UIPEthernet/UIPEthernet.h)
- [UIPEthernet.cpp](LibraryPatches/UIPEthernet/UIPEthernet.cpp)
- [Enc28J60Network.h](LibraryPatches/UIPEthernet/utility/Enc28J60Network.h)
- [Enc28J60Network.cpp](LibraryPatches/UIPEthernet/utility/Enc28J60Network.cpp)

##### Optional UIPEthernet patch

Check if you need to install the UIPthernet patch [new STM32 core F3/F4 compatibility](https://github.com/UIPEthernet/UIPEthernet/commit/c6d6519a260166b722b9cee5dd1f0fb2682e6782) to avoid errors `#include HardwareSPI.h` on some STM32 boards (Nucleo-32 F303K8, etc.)


#### 7. For fixing ESP32 compile error

To fix [`ESP32 compile error`](https://github.com/espressif/arduino-esp32), just copy the following file into the [`ESP32`](https://github.com/espressif/arduino-esp32) cores/esp32 directory (e.g. ./arduino-1.8.13/hardware/espressif/cores/esp32) to overwrite the old file:
- [Server.h](LibraryPatches/esp32/cores/esp32/Server.h)

#### 8. For fixing ESP8266 compile error

To fix `ESP8266 compile error` such as

```
error: 'class EthernetClass' has no member named 'init'
Ethernet.init (USE_THIS_SS_PIN);
```

just rename the following file in ./arduino-1.8.13/hardware/esp8266com/esp8266/libraries/Ethernet directory

- From `Ethernet.h` to `Ethernet_ESP8266.h`

---
---

## HOWTO Install esp32 core for ESP32-S2 (Saola, AI-Thinker ESP-12K) and ESP32-C3 boards into Arduino IDE


These are instructions demonstrating the steps to install esp32-s2 core on Ubuntu machines. For Windows or other OS'es, just follow the the similar principles and steps.

Assuming you already installed Arduino IDE ESP32 core and the installed directory is

`/home/your_account/.arduino15/packages/esp32`


### 1. Save the original esp32 core

First, copy the whole original esp32 core to another safe place. Then delete all the sub-directories of

`/home/your_account/.arduino15/packages/esp32/hardware/esp32/1.0.4`

---


### 2. Install esp32 core v1.0.6

#### 2.1 Install esp32 core

Just use Arduino IDE Board Manager to install [ESP32 Arduino Release 1.0.6 based on ESP-IDF v3.3.5](https://github.com/espressif/arduino-esp32/releases/tag/1.0.6). This official v1.06 core doesn't have esp32-s2/s3 support. You have to download and use the latest master branch.


#### 2.2 Download latest zip with esp32-s2 support

As of **April 16th 2021**, the **esp32-s2/c3** board support has been included in master branch of esp32 core. Download [**esp32 core, master branch**](https://github.com/espressif/arduino-esp32) in the zip format.

#### 2.3 Unzip

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/blob/master/pics/esp32_s2_Core_Unzipped.png">
</p>

#### 2.4 Update esp32 core directories

Copy all subdirectories of esp32 core into `/home/your_account/.arduino15/packages/esp32/hardware/esp32/1.0.6`


---

### 3 Download tools for ESP32-S2


#### 3.1 Download Toolchain for Xtensa (ESP32-S2) based on GCC

Download [**esp32-s2 Toolchain**](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s2/api-guides/tools/idf-tools.html#xtensa-esp32s2-elf) corresponding to your environment (linux-amd64, win64, etc.).

For example `xtensa-esp32s2-elf-gcc8_4_0-esp-2020r3-linux-amd64.tar.gz`, then un-archive.


<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/blob/master/pics/esp32_s2_Toolchain.png">
</p>

#### 3.2 Download esptool


Download [esptool](https://github.com/espressif/esptool/releases) int the `zip` format:

`esptool-3.0.zip`

#### 3.3 Unzip

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/blob/master/pics/esp32_s2_esptool.png">
</p>

---

### 4. Update tools

#### 4.1 Update Toolchain

Copy whole `xtensa-esp32s2-elf` directory into `/home/your_account/.arduino15/packages/esp32/hardware/esp32/1.0.6/tools`


#### 4.2 Update esptool

Rename `esptool-3.0` directory to `esptool`


Copy whole `esptool` directory into `/home/your_account/.arduino15/packages/esp32/hardware/esp32/1.0.6/tools`


<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/blob/master/pics/esp32_s2_tools.png">
</p>


### 5 Download tools for ESP32-C3

Download [**esp32-c3 Toolchain**](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s2/api-guides/tools/idf-tools.html#riscv32-esp-elf) corresponding to your environment (linux-amd64, win64, etc.).

For example`riscv32-esp-elf-gcc8_4_0-crosstool-ng-1.24.0-123-g64eb9ff-linux-amd64.tar.gz`, then un-archive.

Then using the similar steps as in

* [3. Download tools for ESP32-S2](#3-download-tools-for-esp32-s2) 
  * [3.1 Download Toolchain for Xtensa (ESP32-S2) based on GCC](#31-download-toolchain-for-xtensa-esp32-s2-based-on-gcc)
  * [3.2 Download esptool](#32-download-esptool)
  * [3.3 Unzip](#33-unzip)
* [4. Update tools](#4-update-tools)
  * [4.1 Update Toolchain](#41-update-toolchain)
  * [4.2 Update esptool](#42-update-esptool)

then copy whole `riscv32-esp-elf` directory into `/home/your_account/.arduino15/packages/esp32/hardware/esp32/1.0.6/tools`

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/blob/master/pics/ESP32_C3_Support.png">
</p>


### 6. esp32-s2 WebServer Library Patch

#### Necessary only for esp32 core v1.0.6-

If you haven't installed a new version with [WebServer.handleClient delay PR #4350](https://github.com/espressif/arduino-esp32/pull/4350) or haven't applied the above mentioned PR, you have to use the following patch.


**To be able to run Config Portal on ESP32-S2 boards**, you have to copy the files in [esp32-s2 WebServer Patch](esp32s2_WebServer_Patch/) directory into esp32-s2 WebServer library directory (~/.arduino15/packages/esp32/hardware/esp32/1.0.4/libraries/WebServer).

Supposing the esp32-s2 version is 1.0.4, these files `WebServer.h/cpp` must be copied into the directory to replace:

- `~/.arduino15/packages/esp32/hardware/esp32/1.0.4/libraries/WebServer/src/WebServer.h`
- `~/.arduino15/packages/esp32/hardware/esp32/1.0.4/libraries/WebServer/src/WebServer.cpp`


---

That's it. You're now ready to compile and test for ESP32-S2 now

---
---

### Note for Platform IO using ESP32 LittleFS

#### Necessary only for esp32 core v1.0.6-

From esp32 core v1.0.6+, [`LittleFS_esp32 v1.0.6`](https://github.com/lorol/LITTLEFS) has been included and this step is not necessary anymore.

In Platform IO, to fix the error when using [`LittleFS_esp32 v1.0`](https://github.com/lorol/LITTLEFS) for ESP32-based boards with ESP32 core v1.0.4- (ESP-IDF v3.2-), uncomment the following line

from

```
//#define CONFIG_LITTLEFS_FOR_IDF_3_2   /* For old IDF - like in release 1.0.4 */
```

to

```
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

- ADC1 controls ADC function for pins **GPIO32-GPIO39**
- ADC2 controls ADC function for pins **GPIO0, 2, 4, 12-15, 25-27**

#### 3.. ESP32 WiFi uses ADC2 for WiFi functions

Look in file [**adc_common.c**](https://github.com/espressif/esp-idf/blob/master/components/driver/adc_common.c#L61)

> In ADC2, there're two locks used for different cases:
> 1. lock shared with app and Wi-Fi:
>    ESP32:
>         When Wi-Fi using the ADC2, we assume it will never stop, so app checks the lock and returns immediately if failed.
>    ESP32S2:
>         The controller's control over the ADC is determined by the arbiter. There is no need to control by lock.
> 
> 2. lock shared between tasks:
>    when several tasks sharing the ADC2, we want to guarantee
>    all the requests will be handled.
>    Since conversions are short (about 31us), app returns the lock very soon,
>    we use a spinlock to stand there waiting to do conversions one by one.
> 
> adc2_spinlock should be acquired first, then adc2_wifi_lock or rtc_spinlock.


- In order to use ADC2 for other functions, we have to **acquire complicated firmware locks and very difficult to do**
- So, it's not advisable to use ADC2 with WiFi/BlueTooth (BT/BLE).
- Use ADC1, and pins GPIO32-GPIO39
- If somehow it's a must to use those pins serviced by ADC2 (**GPIO0, 2, 4, 12, 13, 14, 15, 25, 26 and 27**), use the **fix mentioned at the end** of [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to work with ESP32 WiFi/BlueTooth (BT/BLE).

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
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/blob/master/pics/STM32F407VET6.png">
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
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/blob/master/pics/ICSP_connector.jpg">
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
10. [Teensy-Ethernet_AdvancedWebServer](examples/Generic/Ethernet/Teensy/Teensy-Ethernet_AdvancedWebServer) using Teensy and W5500 Ethernet.

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
#define USING_LAN8720                     false
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
#define USING_LAN8720                     false
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
#define USING_LAN8720                     false
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
#define USING_LAN8720                     false
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
#define USING_LAN8720                     false
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
#define USING_LAN8720                     false
#define USE_LAN8742A_ETHERNET             true
```

#### 5. To use Ethernet `LAN8720` module/shield with `STM32Ethernet` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET                      false
#define USE_ETHERNET2                     false
#define USE_ETHERNET_LARGE                false
#define USE_ETHERNET_ENC                  false

#define USE_UIP_ETHERNET                  false
#define USING_LAN8720                     true
#define USE_LAN8742A_ETHERNET             true
```

#### 6. It's much easier just add to the sketch

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

###  For Teensy 4.1, 4.0, 3.x using Ethernet W5x0, ENC28J60 or LAN8742A

#### To use Ethernet W5x00 module/shield with Ethernetx library

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
#define USE_NATIVE_ETHERNET               false

#define USE_UIP_ETHERNET                  false
```

 - To use `W5x00` module/shield with `Ethernet2` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET                      false
#define USE_ETHERNET2                     true
#define USE_ETHERNET_LARGE                false
#define USE_ETHERNET_ENC                  false
#define USE_NATIVE_ETHERNET               false

#define USE_UIP_ETHERNET                  false
```
 - To use` W5x00` module/shield with `EthernetLarge` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET                      false
#define USE_ETHERNET2                     false
#define USE_ETHERNET_LARGE                true
#define USE_ETHERNET_ENC                  false
#define USE_NATIVE_ETHERNET               false

#define USE_UIP_ETHERNET                  false
```

#### 2. To use Ethernet `ENC28J60` module/shield with `UIPEthernet` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET                      false
#define USE_ETHERNET2                     false
#define USE_ETHERNET_LARGE                false
#define USE_ETHERNET_ENC                  false
#define USE_NATIVE_ETHERNET               false

#define USE_UIP_ETHERNET                  true
```

#### 3. To use Ethernet `ENC28J60` module/shield with new `EthernetENC` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET                      false
#define USE_ETHERNET2                     false
#define USE_ETHERNET_LARGE                false
#define USE_ETHERNET_ENC                  true
#define USE_NATIVE_ETHERNET               false

#define USE_UIP_ETHERNET                  false
```

#### 4. To use Teensy 4.1 NativeEthernet built-in module/shield with `NativeEthernet` library

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

#define USE_ETHERNET                      false
#define USE_ETHERNET2                     false
#define USE_ETHERNET_LARGE                false
#define USE_ETHERNET_ENC                  true

#define USE_UIP_ETHERNET                  false
```

#### 5. It's much easier just add to the sketch

```cpp
#define WEBSOCKETS_USE_ETHERNET           true

// Just select one to be true. If all is false, default is Ethernet. 
// If more than one are true, the priority is USE_ETHERNET, USE_ETHERNET2, USE_ETHERNET_LARGE, USE_UIP_ETHERNET
#define USE_ETHERNET                  false
#define USE_ETHERNET2                 true
#define USE_ETHERNET_LARGE            false
#define USE_ETHERNET_ENC              false
#define USE_NATIVE_ETHERNET           false

#define USE_UIP_ETHERNET              false

#if ( defined(__IMXRT1062__) && defined(ARDUINO_TEENSY41) && USE_NATIVE_ETHERNET )
  // Also default to Ethernet library
  #include <NativeEthernet.h>
  #define ETHERNET_TYPE               "Teensy 4.1 NativeEthernet Library"
#elif USE_ETHERNET
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

---

###  For Teensy 4.1 using NativeEthernet

Just as simple as:


```cpp
#define WEBSOCKETS_USE_ETHERNET     true
#define USE_NATIVE_ETHERNET         true
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

  Serial.println("\nStarting SAMD-Client_SINRIC with WiFiNINA on " + String(BOARD_NAME));
  Serial.println(WEBSOCKETS2_GENERIC_VERSION);

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
WebSockets2_Generic v1.2.4
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

1. This is terminal debug output when running [SAMD-Ethernet-Client_SINRIC](examples/Generic/Ethernet/SAMD/SAMD-Ethernet-Client_SINRIC) on SAMD51 **ADAFRUIT_ITSYBITSY_M4_EXPRESS using ENC28J60 Ethernet module.**

```
Starting WebSockets2_Generic SAMD-Ethernet-Client_SINRIC on SAMD ADAFRUIT_ITSYBITSY_M4_EXPRESS
Ethernet using ENC28J60 and UIPEthernet Library
WebSockets2_Generic v1.2.4
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
WebSockets2_Generic v1.2.4
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
WebSockets2_Generic v1.2.4
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
WebSockets2_Generic v1.2.4
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
WebSockets2_Generic v1.2.4
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

6. This is terminal debug output when running [STM32-Ethernet-Client_SINRIC_LAN8720](examples/Generic/Ethernet/STM32/LAN8720/STM32-Ethernet-Client_SINRIC_LAN8720) on **BLACK_F407VE using LAN8720 and STM32Ethernet Library**.

```
Starting STM32-Ethernet-Client_SINRIC_LAN8720 on BLACK_F407VE
Ethernet using LAN8720 and STM32Ethernet Library
WebSockets2_Generic v1.2.4
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

7. This is terminal debug output when running [ESP32-Client_SINRIC](examples/ESP32/ESP32-Client_SINRIC) on **ESP32S2_DEV** using modified [Latest esp32 core v1.0.6](https://github.com/espressif/arduino-esp32/releases/tag/1.0.6) . Check [HOWTO Install esp32-s2 core for ESP32-S2](https://github.com/khoih-prog/WebSockets2_Generic#howto-install-esp32-s2-core-for-esp32-s2-saola-ai-thinker-esp-12k-boards-into-arduino-ide)

```
Starting ESP32-Client_SINRIC on ESP32S2_DEV
WebSockets2_Generic v1.2.4
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

8. This is terminal debug output when running [Secured-ESP32-Client](examples/ESP32/Secured-Esp32-Client) on **ESP32S2_DEV** using modified [Latest esp32 core v1.0.6](https://github.com/espressif/arduino-esp32/releases/tag/1.0.6) . Check [HOWTO Install esp32-s2 core for ESP32-S2](https://github.com/khoih-prog/WebSockets2_Generic#howto-install-esp32-s2-core-for-esp32-s2-saola-ai-thinker-esp-12k-boards-into-arduino-ide)

```
Starting WebSockets Secured-ESP32-Client on ESP32S2_DEV
WebSockets2_Generic v1.2.4
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
Connnection Opened
Connected!
Got Message: Hello to Server from ESP32S2_DEV
Got a Pong!
```

---

9. This is terminal debug output when running [InSecured-ESP32-Client](examples/ESP32/InSecured-Esp32-Client) on **ESP32_DEV** using [Latest esp32 core v1.0.6](https://github.com/espressif/arduino-esp32/releases/tag/1.0.6).


```
Starting WebSockets InSecured-ESP32-Client on ESP32_DEV
WebSockets2_Generic v1.2.4
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
Connnection Opened
Connected!
Got Message: Hello to Server from ESP32_DEV
Got a Pong!

```

---

10. This is terminal debug output when running [ESP8266-Client_SINRIC](examples/ESP32/ESP8266-Client_SINRIC) on **ESP8266_NODEMCU_ESP12E** using [Latest esp8266 core v3.0.0](https://github.com/esp8266/Arduino/releases/tag/3.0.0)


```
Starting ESP8266-Client_SINRIC on ESP8266_NODEMCU_ESP12E
WebSockets2_Generic v1.3.0
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

11. This is terminal debug output when running [RP2040-Ethernet-Client_SINRIC](examples/Generic/Ethernet/RP2040/RP2040-Ethernet-Client_SINRIC) on **RASPBERRY_PI_PICO** using [**Earle Philhower's arduino-pico** core](https://github.com/earlephilhower/arduino-pico)


```
Starting RP2040-Ethernet-Client_SINRIC on RASPBERRY_PI_PICO
Ethernet using W5x00 and EthernetLarge Library
WebSockets2_Generic v1.4.0
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 17
W5100::init: W5500, SSIZE =8192
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


12. This is terminal debug output when running [RP2040-Ethernet-Client_SINRIC](examples/Generic/Ethernet/RP2040/RP2040-Ethernet-Client_SINRIC) on **MBED RaspberryPi Pico** using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed).


```
Starting RP2040-Ethernet-Client_SINRIC on RaspberryPi Pico
Ethernet using W5x00 and EthernetLarge Library
WebSockets2_Generic v1.4.0
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 5, new ss_pin = 10, W5100Class::ss_pin = 5
W5100::init: W5500, SSIZE =8192
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

3. This is the screenshot when running [Esp32-AdvancedWebServer](examples/ESP32/Esp32-AdvancedWebServer) example on **ESP32-S2** to demonstrate the new non-blocking feature of WebSockets Server enabling WebServer and WebSockets Server to run concurrently.

<p align="center">
    <img src="https://github.com/khoih-prog/WebSockets2_Generic/blob/master/pics/Web_WS_Server_ESP32-S2.png">
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

## Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the board's core, applying Libraries' Patches, Packages' Patches or this library latest version.

---
---

## Releases

### Major Release v1.4.0

1. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Earle Philhower's arduino-pico** v1.5.1+ core](https://github.com/earlephilhower/arduino-pico).
2. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** v2.1.0+ core](https://github.com/arduino/ArduinoCore-mbed).
4. Add examples with new features

### Release v1.3.0

1. Add support to WiFi101. To be used with [**Forked WiFi101** library](https://github.com/khoih-prog/WiFi101)
2. Check compatibility with new ESP8266 core v3.0.0
3. Suppress warnings

### Release v1.2.4

1. Add InSecure mode for ESP32. For more info, check [**Add setInsecure for esp32** #18](https://github.com/khoih-prog/WebSockets2_Generic/pull/18)
2. Add InSecude-mode examples for ESP32/ESP8266

### Release v1.2.3

1. Update `websocket.org` `letsenrypt.org` CA Certs and Fingerprint for EP32 and ESP8266 secured exampled.

### Release v1.2.2

1. Add support to new **ESP32-C3** boards (**Arduino ESP32C3_DEV**). Check [HOWTO Install esp32 core for ESP32-S2 (Saola, AI-Thinker ESP-12K) and ESP32-C3 boards into Arduino IDE](#howto-install-esp32-core-for-esp32-s2-saola-ai-thinker-esp-12k-and-esp32-c3-boards-into-arduino-ide).

### Release v1.2.1

1. Add support to new ESP32-S2 boards (**SparkFun ESP32-S2 Thing Plus; Adafruit Metro ESP32-S2, MagTag 2.9, FunHouse, Feather ESP32-S2 (no PSRAM)**). Drop support to **UM ProS2**
2. Add HTTP and WebSockets Server support to **ESP32-S2** (ESP32-S2 Saola, AI-Thinker ESP-12K, etc.)

### Major Release v1.2.0

1. Add limited (client-only) support to **LAN8720** Ethernet for **STM32F4 (F407xx, NUCLEO_F429ZI) and STM32F7** (DISCO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG) boards.
2. Add LAN8720 examples
3. Add Packages' Patches for STM32 to use LAN8720 with STM32Ethernet and LwIP libraries
4. Update `echo.websocket.org` **fingerprint add CA Certificate** for ESP8266 and ESP32. Check [Secured-Esp32-Client Example not works on NodeMcu32s (Esp32s) #16](https://github.com/khoih-prog/WebSockets2_Generic/issues/16)
5. Add limited (client-only) support to **ESP32-S2** (ESP32-S2 Saola, AI-Thinker ESP-12K, etc.)
6. Update [HOWTO Install esp32-s2 core for ESP32-S2](https://github.com/khoih-prog/WebSockets2_Generic#howto-install-esp32-s2-core-for-esp32-s2-saola-ai-thinker-esp-12k-boards-into-arduino-ide) to accomodate [Latest esp32 core v1.0.6](https://github.com/espressif/arduino-esp32/releases/tag/1.0.6)
7. Update README to reflect [`LittleFS_esp32 library`](https://github.com/lorol/LITTLEFS) has been included in [Latest esp32 core v1.0.6](https://github.com/espressif/arduino-esp32/releases/tag/1.0.6) and many steps are not necessary anymore

### Major Release v1.1.0

1. Add support to **Teensy using Ethernet libraries** such as **Ethernet, Ethernet2, Ethernet3, EthernetLarge, EthernetENC, UIPEthernet**.
2. Add support to **Teensy 4.1 using NativeEthernet library**. Thanks to [**arnoson**](https://github.com/arnoson) code posted in [ArduinoWebsockets release 0.5.0](https://github.com/gilmaimon/ArduinoWebsockets/releases/tag/0.5.0)
3. Add Version String

### Release v1.0.7

1. Add support to ENC28J60 Ethernet using **EthernetENC**.
2. Add Ethernet Library Patches for **UIPEthernet v2.0.9 and Ethernet2**
3. Update Platform.ini to support **PlatformIO 5.x owner-based dependency declaration**.

#### Release v1.0.6

1. Add **non-blocking WebSockets Server** feature to enable WS Server and WebServer running **concurrently**. See [**Support as Http server and the Websockets server on Arduino DUE**](https://github.com/khoih-prog/WebSockets_Generic/issues/1) and [**Running Http and Websocket Servers concurrently**](https://github.com/khoih-prog/WebSockets2_Generic/issues/1). Thanks to bug report and persistence of [Jake](https://github.com/jakespeed1311).
2. Add non-blocking WebSockets Server and WebServer examples. 
3. Add Ethernet Library Patches
4. Add Arduino SAMD Packages_Patches to fix compiler errors when using [Standard Template Library STL](https://en.wikipedia.org/wiki/Standard_Template_Library)

#### Release v1.0.5

1. Sync with [ArduinoWebsockets v0.4.18](https://github.com/gilmaimon/ArduinoWebsockets/releases/tag/0.4.18) to fix ESP8266 SSL bug. See [Secured-Two-Way: Client certificate is not sent if used along with setTrustAnchors](https://github.com/gilmaimon/ArduinoWebsockets/issues/84)

#### Release v1.0.4

1. Add support to all **STM32F/L/H/G/WB/MP1 (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8, etc.)**
2. Add support to **Seeeduino SAMD21/SAMD51 boards (SEEED_WIO_TERMINAL, SEEED_FEMTO_M0, SEEED_XIAO_M0, Wio_Lite_MG126, WIO_GPS_BOARD, SEEEDUINO_ZERO, SEEEDUINO_LORAWAN, SEEED_GROVE_UI_WIRELESS, etc.)**
3. Add sample Packages_Patches for **STM32 stm32** (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8)
4. Add Packages' Patches for **Seeeduino SAMD** to enable displaying **BOARD_NAME**
5. Add many examples
                                  
#### Release v1.0.3

1. Add support to STM32F boards with built-in Ethernet such as :
  - **Nucleo-144 (F429ZI, F767ZI)**
  - **Discovery (STM32F746G-DISCOVERY)**
  - **All STM32F Boards with Built-in Ethernet LAN8742A**

2. Add support to **STM32F1,2,3,4,7 boards (with 64+K Flash)** using **Ethernet W5x00, ENC28J60 or LAN8742A**
3. Add Packages' Patches to **Adafruit nRF52, SAMD, Arduino SAMD** to enable displaying **BOARD_NAME**
4. Enhance examples and update README.md

#### Release v1.0.2

1. Add support to **Ethernet ENC28J60, using UIPEthernet library**, for nRF52, SAMD21/SAMD51 and SAM DUE boards.

#### Release v1.0.1

1. Add support to **SAM DUE** boards.
2. Add support to **Ethernet W5x00, using either Ethernet, EthernetLarge or Ethernet2 library.**
3. Restructure code to provide flexibility to support many more WiFi/Ethernet modules/shields in the future. Please delete the *.cpp files, replaced with coresponding *.hpp files, in the library src directory, if the *.cpp files still exist after installing new version.

#### Release v1.0.0

1. Add support to **nRF52** boards, such as **AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc.**,  using WiFiNINA with [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic)
2. Add support to **SAMD51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)** , using WiFiNINA with [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic).
3. Add support to **SAMD21 (ZERO, MKR, NANO_33_IOT, M0, M0 Pro, AdaFruit CIRCUITPLAYGROUND_EXPRESS, etc.)**, using WiFiNINA with [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic).
4. Add Alexa/[`SINRIC`](https://sinric.com) examples and supports to those boards as well as ESP8266/ESP32

---
---

### Issues

Submit issues to: [WebSockets2_Generic issues](https://github.com/khoih-prog/WebSockets2_Generic/issues)

---
---

### TO DO

 1. Support more boards (Teensy, etc.)
 2. Support ESP8266/ESP32-AT shields.
 3. Add SSL support to SAMD21/SAMD51 and nRF52 using WiFiNINA.
 4. Support more non-compatible Ethernet Libraries such as Ethernet_Shield_W5200, EtherCard, EtherSia
 5. Add mDNS features.
 6. Add WiFiNINA support to new RP2040-basd boards, such as **Nano RP2040 Connect**

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

---
---

### Contributions and Thanks

1. Based on and modified from [Gil Maimon's ArduinoWebsockets](https://github.com/gilmaimon/ArduinoWebsockets)
2. Thanks to good work of [Miguel Alexandre Wisintainer](https://github.com/tcpipchip) for initiating, inspriring, working with, developing, debugging and testing. Without that, support to nRF52, especially **NINA_B302_ublox running as nRF52840 and NINA_B112_ublox running as nRF52832**, has never been started and finished. See [u-blox nina b](https://github.com/khoih-prog/WiFiNINA_Generic/issues/1)
3. Thanks to bug report and persistence of [Jake](https://github.com/jakespeed1311) to help identify and add **non-blocking WebSockets Server** feature to v1.0.6 to enable WS Server and WebServer running **concurrently**. See [**Support as Http server and the Websockets server on Arduino DUE**](https://github.com/khoih-prog/WebSockets_Generic/issues/1) and [**Running Http and Websocket Servers concurrently**](https://github.com/khoih-prog/WebSockets2_Generic/issues/1). 
4. Thanks to [arnoson](https://github.com/arnoson) code posted in [ArduinoWebsockets release 0.5.0](https://github.com/gilmaimon/ArduinoWebsockets/releases/tag/0.5.0) to provide support to Teensy 4.1 using NativeEthernet.
5. Thanks [Lionel REICHERT](https://github.com/apwwn) for PR [**Add setInsecure for esp32** #18](https://github.com/khoih-prog/WebSockets2_Generic/pull/18) leading to v1.2.4.
6. Thanks to [Jose A.Molina](https://github.com/Josua2012) for the enhanement request [**MKR1000 and WIFI problem and another problem** #20](https://github.com/khoih-prog/WebSockets2_Generic/issues/20), and help testing, leading to new version v1.3.0 to support WiFi101 and MKD1000 / MKR1010WiFi boards.


<table>
  <tr>
    <td align="center"><a href="https://github.com/gilmaimon"><img src="https://github.com/gilmaimon.png" width="100px;" alt="gilmaimon"/><br /><sub><b>⭐️⭐️ Gil Maimon</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/tcpipchip"><img src="https://github.com/tcpipchip.png" width="100px;" alt="tcpipchip"/><br /><sub><b>⭐️ Miguel Wisintainer</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/jakespeed1311"><img src="https://github.com/jakespeed1311.png" width="100px;" alt="jakespeed1311"/><br /><sub><b>Jake</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/arnoson"><img src="https://github.com/arnoson.png" width="100px;" alt="arnoson"/><br /><sub><b>arnoson</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/apwwn"><img src="https://github.com/apwwn.png" width="100px;" alt="apwwn"/><br /><sub><b>Lionel REICHERT</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/Josua2012"><img src="https://github.com/Josua2012.png" width="100px;" alt="Josua2012"/><br /><sub><b>Jose A. Molina</b></sub></a><br /></td>
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

- The library is licensed under [GPLv3.0](https://github.com/khoih-prog/WebSockets2_Generic/blob/master/LICENSE)

- `base64` written by René Nyffenegger.

---

## Copyright

1. Copyright (c) 2019- Gil Maimon
2. Copyright (c) 2020- Khoi Hoang


