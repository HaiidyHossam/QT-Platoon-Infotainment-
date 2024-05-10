/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *FirstStack;
    QWidget *MainButtons;
    QPushButton *Prayer_Button;
    QPushButton *Camera_Button;
    QLabel *DateTime;
    QLabel *Digital_Clock;
    QPushButton *Weather_Button;
    QPushButton *Bluetooth_Button;
    QPushButton *Info_Button;
    QPushButton *Settings_Button;
    QPushButton *Music_Button;
    QPushButton *Video_Button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1069, 713);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        FirstStack = new QStackedWidget(centralwidget);
        FirstStack->setObjectName(QString::fromUtf8("FirstStack"));
        FirstStack->setGeometry(QRect(10, 0, 1031, 651));
        FirstStack->setMinimumSize(QSize(291, 211));
        FirstStack->setMaximumSize(QSize(2000, 2000));
        QFont font;
        font.setPointSize(32);
        FirstStack->setFont(font);
        FirstStack->setTabletTracking(true);
        FirstStack->setAutoFillBackground(false);
        FirstStack->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        MainButtons = new QWidget();
        MainButtons->setObjectName(QString::fromUtf8("MainButtons"));
        Prayer_Button = new QPushButton(MainButtons);
        Prayer_Button->setObjectName(QString::fromUtf8("Prayer_Button"));
        Prayer_Button->setGeometry(QRect(590, 510, 91, 91));
        Prayer_Button->setFocusPolicy(Qt::NoFocus);
        Prayer_Button->setContextMenuPolicy(Qt::NoContextMenu);
        Prayer_Button->setAcceptDrops(false);
#if QT_CONFIG(tooltip)
        Prayer_Button->setToolTip(QString::fromUtf8(""));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        Prayer_Button->setStatusTip(QString::fromUtf8(""));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        Prayer_Button->setWhatsThis(QString::fromUtf8(""));
#endif // QT_CONFIG(whatsthis)
        Prayer_Button->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/prayer.png);"));
        Prayer_Button->setFlat(true);
        Camera_Button = new QPushButton(MainButtons);
        Camera_Button->setObjectName(QString::fromUtf8("Camera_Button"));
        Camera_Button->setGeometry(QRect(480, 510, 91, 91));
        Camera_Button->setFocusPolicy(Qt::NoFocus);
        Camera_Button->setContextMenuPolicy(Qt::NoContextMenu);
        Camera_Button->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/camera.png);"));
        Camera_Button->setFlat(true);
        DateTime = new QLabel(MainButtons);
        DateTime->setObjectName(QString::fromUtf8("DateTime"));
        DateTime->setGeometry(QRect(340, 300, 241, 61));
        DateTime->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        Digital_Clock = new QLabel(MainButtons);
        Digital_Clock->setObjectName(QString::fromUtf8("Digital_Clock"));
        Digital_Clock->setGeometry(QRect(130, 110, 661, 171));
        QFont font1;
        font1.setPointSize(96);
        Digital_Clock->setFont(font1);
        Digital_Clock->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        Weather_Button = new QPushButton(MainButtons);
        Weather_Button->setObjectName(QString::fromUtf8("Weather_Button"));
        Weather_Button->setGeometry(QRect(660, 350, 161, 101));
        Weather_Button->setFocusPolicy(Qt::NoFocus);
        Weather_Button->setContextMenuPolicy(Qt::NoContextMenu);
        Weather_Button->setFlat(true);
        Bluetooth_Button = new QPushButton(MainButtons);
        Bluetooth_Button->setObjectName(QString::fromUtf8("Bluetooth_Button"));
        Bluetooth_Button->setEnabled(true);
        Bluetooth_Button->setGeometry(QRect(710, 510, 91, 91));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Bluetooth_Button->sizePolicy().hasHeightForWidth());
        Bluetooth_Button->setSizePolicy(sizePolicy);
        Bluetooth_Button->setMinimumSize(QSize(91, 81));
        Bluetooth_Button->setFocusPolicy(Qt::NoFocus);
        Bluetooth_Button->setContextMenuPolicy(Qt::NoContextMenu);
        Bluetooth_Button->setAutoFillBackground(false);
        Bluetooth_Button->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/bluetooth.png);"));
        Bluetooth_Button->setFlat(true);
        Info_Button = new QPushButton(MainButtons);
        Info_Button->setObjectName(QString::fromUtf8("Info_Button"));
        Info_Button->setGeometry(QRect(930, 510, 91, 91));
        Info_Button->setFocusPolicy(Qt::NoFocus);
        Info_Button->setContextMenuPolicy(Qt::NoContextMenu);
        Info_Button->setAutoFillBackground(false);
        Info_Button->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/info.png);"));
        Info_Button->setFlat(true);
        Settings_Button = new QPushButton(MainButtons);
        Settings_Button->setObjectName(QString::fromUtf8("Settings_Button"));
        Settings_Button->setGeometry(QRect(820, 510, 91, 91));
        Settings_Button->setFocusPolicy(Qt::NoFocus);
        Settings_Button->setContextMenuPolicy(Qt::NoContextMenu);
        Settings_Button->setAutoFillBackground(false);
        Settings_Button->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/settings.png);"));
        Settings_Button->setAutoDefault(false);
        Settings_Button->setFlat(true);
        Music_Button = new QPushButton(MainButtons);
        Music_Button->setObjectName(QString::fromUtf8("Music_Button"));
        Music_Button->setGeometry(QRect(370, 510, 101, 91));
        Music_Button->setFocusPolicy(Qt::NoFocus);
        Music_Button->setContextMenuPolicy(Qt::NoContextMenu);
        Music_Button->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/music.png);"));
        Music_Button->setFlat(true);
        Video_Button = new QPushButton(MainButtons);
        Video_Button->setObjectName(QString::fromUtf8("Video_Button"));
        Video_Button->setGeometry(QRect(240, 500, 111, 101));
        Video_Button->setFocusPolicy(Qt::NoFocus);
        Video_Button->setContextMenuPolicy(Qt::NoContextMenu);
        Video_Button->setFlat(true);
        FirstStack->addWidget(MainButtons);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1069, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        FirstStack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Prayer_Button->setText(QString());
        Camera_Button->setText(QString());
        DateTime->setText(QCoreApplication::translate("MainWindow", "Mov-12-20320123", nullptr));
        Digital_Clock->setText(QString());
        Weather_Button->setText(QCoreApplication::translate("MainWindow", "Weather", nullptr));
#if QT_CONFIG(tooltip)
        Bluetooth_Button->setToolTip(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Bluetooth_Button->setText(QString());
        Info_Button->setText(QString());
        Settings_Button->setText(QString());
        Music_Button->setText(QString());
        Video_Button->setText(QCoreApplication::translate("MainWindow", "Videos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
