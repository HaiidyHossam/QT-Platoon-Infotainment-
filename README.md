# Infotainment Platoon

Qt-based infotainment application for vehicle dashboard-style modules.

## Overview

### Video

https://github.com/user-attachments/assets/4fc50242-8a2d-40b3-b74c-40798d62f9e9

This project is a Qt 5 application that combines multiple modules in a stacked UI, including:
- Camera module
- Weather module
- Bluetooth module
- Settings module
- Info module
- Prayer times module
- MP3 music player
- MP4 video player
- QML map view
- QML gauge cluster view
- MQTT-based data input

## Project structure

- `Infotainment_Platoon.pro` - Qt project file
- `Sources/` - C++ source files
- `Headers/` - C++ header files
- `Forms/` - Qt Designer UI forms
- `qml/` - QML views and components
- `Resources.qrc` - Qt resource file
- `build/` - generated build output directory

## Dependencies

The project uses the following Qt modules:
- Qt Core
- Qt GUI
- Qt Widgets
- Qt Network
- Qt Multimedia
- Qt MultimediaWidgets
- Qt MQTT
- Qt Quick
- Qt Quick Widgets
- Qt QML

## Build instructions

Recommended workflow on Linux:

```bash
git clone https://github.com/HarmWare/QT-Platoon-Infotainment-.git
cd ./QT-Platoon-Infotainment-
mkdir ./build
cd ./build
qmake -o Makefile ../Infotainment_Platoon.pro
make -j4
```

If you prefer Qt Creator, open `Infotainment_Platoon.pro` and configure the kit.

## Run

After successful build, run the executable from the build directory:

```bash
./Infotainment_Platoon
```
