/********************************************************************************
** Form generated from reading UI file 'mp3.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MP3_H
#define UI_MP3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mp3
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget;
    QPushButton *previous_button;
    QPushButton *next_button;
    QSlider *horizontalSlider;
    QSlider *verticalSlider;
    QCheckBox *start_stop_button;
    QPushButton *repeat_button;
    QPushButton *home_button;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QDialog *Mp3)
    {
        if (Mp3->objectName().isEmpty())
            Mp3->setObjectName(QString::fromUtf8("Mp3"));
        Mp3->resize(1024, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Mp3->sizePolicy().hasHeightForWidth());
        Mp3->setSizePolicy(sizePolicy);
        Mp3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(Mp3);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setGeometry(QRect(-10, 30, 1011, 571));
        centralwidget->setFocusPolicy(Qt::NoFocus);
        centralwidget->setContextMenuPolicy(Qt::NoContextMenu);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(110, 50, 711, 381));
        listWidget->setFocusPolicy(Qt::NoFocus);
        listWidget->setContextMenuPolicy(Qt::NoContextMenu);
        previous_button = new QPushButton(centralwidget);
        previous_button->setObjectName(QString::fromUtf8("previous_button"));
        previous_button->setGeometry(QRect(160, 480, 80, 25));
        previous_button->setFocusPolicy(Qt::NoFocus);
        previous_button->setContextMenuPolicy(Qt::NoContextMenu);
        previous_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        previous_button->setAutoDefault(false);
        previous_button->setFlat(true);
        next_button = new QPushButton(centralwidget);
        next_button->setObjectName(QString::fromUtf8("next_button"));
        next_button->setGeometry(QRect(510, 480, 80, 25));
        next_button->setFocusPolicy(Qt::NoFocus);
        next_button->setContextMenuPolicy(Qt::NoContextMenu);
        next_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        next_button->setAutoDefault(false);
        next_button->setFlat(true);
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(130, 530, 491, 20));
        horizontalSlider->setFocusPolicy(Qt::NoFocus);
        horizontalSlider->setContextMenuPolicy(Qt::NoContextMenu);
        horizontalSlider->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        horizontalSlider->setOrientation(Qt::Horizontal);
        verticalSlider = new QSlider(centralwidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(740, 450, 21, 101));
        verticalSlider->setFocusPolicy(Qt::NoFocus);
        verticalSlider->setContextMenuPolicy(Qt::NoContextMenu);
        verticalSlider->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        verticalSlider->setMinimum(1);
        verticalSlider->setPageStep(1);
        verticalSlider->setValue(50);
        verticalSlider->setSliderPosition(50);
        verticalSlider->setOrientation(Qt::Vertical);
        start_stop_button = new QCheckBox(centralwidget);
        start_stop_button->setObjectName(QString::fromUtf8("start_stop_button"));
        start_stop_button->setGeometry(QRect(330, 480, 82, 23));
        start_stop_button->setFocusPolicy(Qt::NoFocus);
        start_stop_button->setContextMenuPolicy(Qt::NoContextMenu);
        start_stop_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        start_stop_button->setChecked(false);
        repeat_button = new QPushButton(centralwidget);
        repeat_button->setObjectName(QString::fromUtf8("repeat_button"));
        repeat_button->setGeometry(QRect(620, 480, 80, 25));
        repeat_button->setFocusPolicy(Qt::NoFocus);
        repeat_button->setContextMenuPolicy(Qt::NoContextMenu);
        repeat_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        repeat_button->setAutoDefault(false);
        repeat_button->setFlat(true);
        home_button = new QPushButton(centralwidget);
        home_button->setObjectName(QString::fromUtf8("home_button"));
        home_button->setGeometry(QRect(0, 10, 111, 561));
        home_button->setFocusPolicy(Qt::NoFocus);
        home_button->setContextMenuPolicy(Qt::NoContextMenu);
        home_button->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/home.png);"));
        home_button->setAutoDefault(false);
        home_button->setFlat(true);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 20, 431, 20));
        menubar = new QMenuBar(Mp3);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1024, 20));
        statusbar = new QStatusBar(Mp3);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setGeometry(QRect(0, 0, 3, 22));

        retranslateUi(Mp3);

        QMetaObject::connectSlotsByName(Mp3);
    } // setupUi

    void retranslateUi(QDialog *Mp3)
    {
        Mp3->setWindowTitle(QCoreApplication::translate("Mp3", "Dialog", nullptr));
        previous_button->setText(QCoreApplication::translate("Mp3", "previous", nullptr));
        next_button->setText(QCoreApplication::translate("Mp3", "next", nullptr));
        start_stop_button->setText(QCoreApplication::translate("Mp3", "CheckBox", nullptr));
        repeat_button->setText(QCoreApplication::translate("Mp3", "repeat", nullptr));
        home_button->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Mp3: public Ui_Mp3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MP3_H
