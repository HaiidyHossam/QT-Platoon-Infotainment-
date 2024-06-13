QT       += core gui network  widgets multimedia multimediawidgets mqtt quickwidgets qml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Sources/Bluetooth.cpp \
    Sources/Camera.cpp \
    Sources/Info.cpp \
    Sources/Prayer.cpp \
    Sources/Settings.cpp \
    Sources/Weather.cpp \
    Sources/flash.cpp \
    Sources/main.cpp \
    Sources/mainwindow.cpp \
    Sources/mp3.cpp \
    Sources/mp4.cpp \
    Sources/mqtt_connection.cpp \
    Sources/popNotify.cpp \
    Sources/updatedialog.cpp

HEADERS += \
    Headers/Bluetooth.h \
    Headers/Camera.h \
    Headers/Info.h \
    Headers/Prayer.h \
    Headers/Settings.h \
    Headers/Weather.h \
    Headers/flash.h \
    Headers/mainwindow.h \
    Headers/mp3.h \
    Headers/mp4.h \
    Headers/mqtt_connection.h \
    Headers/popNotify.h \
    Headers/updatedialog.h

FORMS += \
    Forms/Bluetooth.ui \
    Forms/Camera.ui \
    Forms/Info.ui \
    Forms/Prayer.ui \
    Forms/Settings.ui \
    Forms/Weather.ui \
    Forms/mainwindow.ui \
    Forms/mp3.ui \
    Forms/mp4.ui \
    Forms/popNotify.ui \
    Forms/updatedialog.ui

RESOURCES += \
    Resources.qrc

DISTFILES += \
    icons/CameraDefault.png
