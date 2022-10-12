## WebSockets2_Generic

[![arduino-library-badge](https://www.ardu-badge.com/badge/WebSockets2_Generic.svg?)](https://www.ardu-badge.com/WebSockets2_Generic)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/WebSockets2_Generic.svg)](https://github.com/khoih-prog/WebSockets2_Generic/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/WebSockets2_Generic/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/WebSockets2_Generic.svg)](http://github.com/khoih-prog/WebSockets2_Generic/issues)

---
---

## Table of Contents

* [Changelog](#changelog)
  * [Release v1.13.0](#release-v1130)
  * [Release v1.12.1](#release-v1121)
  * [Release v1.12.0](#release-v1120)
  * [Release v1.11.0](#release-v1110)
  * [Release v1.10.3](#release-v1103)
  * [Release v1.10.2](#release-v1102)
  * [Release v1.10.1](#release-v1101)
  * [Major Release v1.10.0](#major-release-v1100)
  * [Release v1.9.1](#release-v191)
  * [Major Release v1.9.0](#major-release-v190)
  * [Release v1.8.1](#release-v181)
  * [Major Release v1.8.0](#major-release-v180)
  * [Major Release v1.7.0](#major-release-v170)
  * [Major Release v1.6.0](#major-release-v160)
  * [Major Release v1.5.0](#major-release-v150)
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

---
---

## Changelog

### Release v1.13.0

1. Add support to `RP2040W` using `CYW43439 WiFi` or `Ethernet` with `arduino-pico` core

### Release v1.12.1

1. Improve and fix bug in examples

### Release v1.12.0

1. Add support to ENC28J60 using `EthernetENC` or `UIPEthernet` Library for these supported boards

- ESP32
- nRF52
- RP2040
- SAM DUE
- SAMD
- STM32
- Teensy


### Release v1.11.0

1. Add support to `ESP32` using `W5x00` Ethernet
2. Update `Packages' Patches`

### Release v1.10.3

1. Use new [Ethernet_Generic library](https://github.com/khoih-prog/Ethernet_Generic) as default for W5x00.
2. Add support to SPI2 for ESP32
3. Add support to SPI1 for RP2040 using [arduino-pico core](https://github.com/earlephilhower/arduino-pico)
4. Rewrite all the examples to support new features
5. Use new `waitForLink()` function of QNEthernet
6. Update `Packages' Patches`

### Release v1.10.2

1. Fix bug when using `QNEthernet` staticIP. Check [QNEthernet and NativeEthernet staticIP not working with WS Server #39](https://github.com/khoih-prog/WebSockets2_Generic/issues/39)
2. Add staticIP option to `NativeEthernet` examples
2. Update `Packages' Patches`

### Release v1.10.1

1. Reduce QNEthernet latency. Check [QNEthernet higher latency #38](https://github.com/khoih-prog/WebSockets2_Generic/issues/38)
2. Update `Packages' Patches`

### Major Release v1.10.0

1. Supporting case-insensitive headers, according to RFC2616
2. Sync with [ArduinoWebsockets releases v0.5.3](https://github.com/gilmaimon/ArduinoWebsockets/releases/tag/0.5.3)
  - Add `connectSecure` method to support WSS connection with the classic interface (host, port, path)
  - Add 1 second `connection timeout` for ESP32/ESP8266, Teensy 4.1 NativeEthernet and QNEthernet
3. Improve debug
  

### Release v1.9.1

1. Fix compile error for `Teensy 4.1` using new [QNEthernet library version](https://github.com/ssilverman/QNEthernet). Check [Fix QNEthernet TCP interface #35](https://github.com/khoih-prog/WebSockets2_Generic/pull/35)
2. Update `Packages' Patches`
3. Verify working with new Arduino IDE `v1.8.18`
4. Update `library.json` and `platform.ini` newly published [QNEthernet library](https://github.com/ssilverman/QNEthernet)

### Major Release v1.9.0

1. Auto detect ESP32 core to use for WT32_ETH01
2. Fix bug in WT32_ETH01 examples to reduce connection time
3. Replace deprecated `echo.websocket.org` in examples.

### Release v1.8.1

1. Update `platform.ini` and `library.json` to use original `khoih-prog` instead of `khoih.prog` after PIO fix
2. Update `Packages' Patches`

### Major Release v1.8.0

1. Add support to **RP2040-based boards, such as Nano_RP2040_Connect, RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040**, using WiFiNINA
2. Add examples with new features
3. Update many Packages' Patches

### Major Release v1.7.0

1. Add support to **Portenta_H7**, using either WiFi or Vision-shield Ethernet
2. Add examples with new features

### Major Release v1.6.0

1. Add support to [QNEthernet Library](https://github.com/ssilverman/QNEthernet) for Teensy 4.1 built-in Ethernet
2. Update examples with new features

### Major Release v1.5.0

1. Add support to WT32_ETH01 (ESP32 + LAN8720) boards
2. Add examples with new features

### Major Release v1.4.0

1. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Earle Philhower's arduino-pico** v1.5.1+ core](https://github.com/earlephilhower/arduino-pico).
2. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** v2.1.0+ core](https://github.com/arduino/ArduinoCore-mbed).
3. Add examples with new features

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


