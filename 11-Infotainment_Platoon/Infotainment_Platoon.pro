QT       += core gui network  widgets multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BBluetooth.cpp \
    Camera.cpp \
    Info.cpp \
    Settings.cpp \
    Weather.cpp \
    main.cpp \
    mainwindow.cpp \
    popNotify.cpp

HEADERS += \
    BBluetooth.h \
    Camera.h \
    Info.h \
    Settings.h \
    Weather.h \
    mainwindow.h \
    popNotify.h

FORMS += \
    BBluetooth.ui \
    Camera.ui \
    Info.ui \
    Settings.ui \
    Weather.ui \
    mainwindow.ui \
    popNotify.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
