# phiUi
Lightweight and customizable ui framework for embedded devices

## Supported platforms
* Monochrome displays via U8G2 library
* Desktop (Linux, Windows, Macos) via SDL2

## Features
* Low memory and cpu usage
* Fully customizable rendering, the user may write their own rendering functions
* Flexible grid system, similar to row/col system in web
* Compile-time widget types and names handling, widget are handled with no cost
* Cross-platform: debug the app on desktop, deploy on PlatformIO
* The code is fully configurable

## Requirements
* C++ 20 (widget name handler requires constexpr constructors, perhaps could try to rewrite it in C++ 17)
* Desktop: CMake, SDL2
* Microcontroller: PlatformIO, U8G2 (Arduino IDE and ESP-IDF are not tested)

*This project is in early WIP*

## TODO
* [X] Desktop and U8G2 rendering plugins
* [ ] Port bitmap font system from U8G2
* [ ] Add animations support with deltaTime and animation class
* [ ] Add signals
* [ ] Add dummy renderer, compile to webassembly