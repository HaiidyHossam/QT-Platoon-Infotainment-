QT += quick multimedia

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        PlayerController.cpp \
        main.cpp

RESOURCES += qml.qrc assets/images/Warda.jpg  assets/images/AbdelHaliem.jpg  assets/images/Carioky.jpg assets/images/UmmKulthom.jpg  assets/icons/8201371_menu_list_order_ui_checklist_icon.png assets/icons/8201381_square_stop_multimedia_ui_icon.png  assets/icons/8207890_back_direction_previous_multimedia_arrows_icon.png assets/icons/8207891_next_arrows_multimedia_skip_ui_icon.png assets/icons/8207892_pause_multimedia_stop_ui_icon.png


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    PlayerController.h
