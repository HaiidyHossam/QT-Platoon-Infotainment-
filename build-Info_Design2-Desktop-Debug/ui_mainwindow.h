/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
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
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QLabel *DateTime;
    QLabel *Digital_Clock;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QWidget *Camera;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QWidget *widget;
    QPushButton *pushButton_6;
    QWidget *PrayerTimes;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_2;
    QWidget *Weather;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(927, 731);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        FirstStack = new QStackedWidget(centralwidget);
        FirstStack->setObjectName(QString::fromUtf8("FirstStack"));
        FirstStack->setGeometry(QRect(10, 10, 891, 621));
        FirstStack->setMinimumSize(QSize(291, 211));
        FirstStack->setMaximumSize(QSize(891, 621));
        MainButtons = new QWidget();
        MainButtons->setObjectName(QString::fromUtf8("MainButtons"));
        pushButton = new QPushButton(MainButtons);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 130, 171, 81));
        pushButton_3 = new QPushButton(MainButtons);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(300, 130, 191, 81));
        DateTime = new QLabel(MainButtons);
        DateTime->setObjectName(QString::fromUtf8("DateTime"));
        DateTime->setGeometry(QRect(50, 20, 201, 71));
        Digital_Clock = new QLabel(MainButtons);
        Digital_Clock->setObjectName(QString::fromUtf8("Digital_Clock"));
        Digital_Clock->setGeometry(QRect(390, 10, 201, 81));
        pushButton_7 = new QPushButton(MainButtons);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(70, 280, 161, 101));
        pushButton_8 = new QPushButton(MainButtons);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(300, 270, 201, 141));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        pushButton_8->setMinimumSize(QSize(91, 81));
        pushButton_8->setAutoFillBackground(true);
        pushButton_9 = new QPushButton(MainButtons);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(540, 130, 201, 111));
        pushButton_10 = new QPushButton(MainButtons);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(560, 280, 171, 91));
        FirstStack->addWidget(MainButtons);
        Camera = new QWidget();
        Camera->setObjectName(QString::fromUtf8("Camera"));
        pushButton_4 = new QPushButton(Camera);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(60, 20, 201, 131));
        pushButton_5 = new QPushButton(Camera);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(400, 20, 201, 131));
        widget = new QWidget(Camera);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 190, 531, 231));
        pushButton_6 = new QPushButton(Camera);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(330, 440, 111, 71));
        FirstStack->addWidget(Camera);
        pushButton_4->raise();
        widget->raise();
        pushButton_6->raise();
        pushButton_5->raise();
        PrayerTimes = new QWidget();
        PrayerTimes->setObjectName(QString::fromUtf8("PrayerTimes"));
        label = new QLabel(PrayerTimes);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 121, 18));
        label_2 = new QLabel(PrayerTimes);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 161, 18));
        label_2->setMaximumSize(QSize(161, 18));
        label_3 = new QLabel(PrayerTimes);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 80, 141, 18));
        label_4 = new QLabel(PrayerTimes);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 110, 191, 18));
        label_5 = new QLabel(PrayerTimes);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 140, 151, 41));
        pushButton_2 = new QPushButton(PrayerTimes);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(530, 340, 251, 171));
        FirstStack->addWidget(PrayerTimes);
        Weather = new QWidget();
        Weather->setObjectName(QString::fromUtf8("Weather"));
        FirstStack->addWidget(Weather);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 927, 22));
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
        pushButton->setText(QCoreApplication::translate("MainWindow", "prayer", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Camera", nullptr));
        DateTime->setText(QString());
        Digital_Clock->setText(QString());
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Weather", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_8->setToolTip(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_8->setText(QString());
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "info", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Start Camera", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Stop Camera", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
