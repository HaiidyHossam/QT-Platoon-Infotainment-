QT += core gui bluetooth multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = BluetoothMusicPlayer
TEMPLATE = app

# You may need to adjust the paths if your project structure is different
INCLUDEPATH += $$PWD

# Source files
SOURCES += \
    main.cpp \
    mainwindow.cpp

# Header files
HEADERS += \
    mainwindow.h

# User interface file
FORMS += \
    mainwindow.ui
