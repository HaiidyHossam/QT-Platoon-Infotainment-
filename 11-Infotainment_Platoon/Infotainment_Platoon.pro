QT       += core gui network  widgets multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bluetooth.cpp \
    Camera.cpp \
    Info.cpp \
    Prayer.cpp \
    Settings.cpp \
    Weather.cpp \
    flash.cpp \
    main.cpp \
    mainwindow.cpp \
    mp3.cpp \
    mp4.cpp \
    popNotify.cpp

HEADERS += \
    Bluetooth.h \
    Camera.h \
    Info.h \
    Prayer.h \
    Settings.h \
    Weather.h \
    flash.h \
    mainwindow.h \
    mp3.h \
    mp4.h \
    popNotify.h

FORMS += \
    Bluetooth.ui \
    Camera.ui \
    Info.ui \
    Prayer.ui \
    Settings.ui \
    Weather.ui \
    mainwindow.ui \
    mp3.ui \
    mp4.ui \
    popNotify.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
