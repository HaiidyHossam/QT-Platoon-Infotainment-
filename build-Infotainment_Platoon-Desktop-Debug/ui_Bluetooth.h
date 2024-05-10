/********************************************************************************
** Form generated from reading UI file 'Bluetooth.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLUETOOTH_H
#define UI_BLUETOOTH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_BBluetooth
{
public:
    QCheckBox *toggle_bluetooth;
    QLabel *bluetooth_icon;
    QLabel *bluetooth_state;
    QPushButton *Back_Home;

    void setupUi(QDialog *BBluetooth)
    {
        if (BBluetooth->objectName().isEmpty())
            BBluetooth->setObjectName(QString::fromUtf8("BBluetooth"));
        BBluetooth->setEnabled(true);
        BBluetooth->resize(1024, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BBluetooth->sizePolicy().hasHeightForWidth());
        BBluetooth->setSizePolicy(sizePolicy);
        BBluetooth->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        toggle_bluetooth = new QCheckBox(BBluetooth);
        toggle_bluetooth->setObjectName(QString::fromUtf8("toggle_bluetooth"));
        toggle_bluetooth->setGeometry(QRect(200, 50, 161, 71));
        toggle_bluetooth->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        bluetooth_icon = new QLabel(BBluetooth);
        bluetooth_icon->setObjectName(QString::fromUtf8("bluetooth_icon"));
        bluetooth_icon->setGeometry(QRect(230, 150, 251, 18));
        bluetooth_icon->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        bluetooth_state = new QLabel(BBluetooth);
        bluetooth_state->setObjectName(QString::fromUtf8("bluetooth_state"));
        bluetooth_state->setGeometry(QRect(170, 210, 291, 111));
        bluetooth_state->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        Back_Home = new QPushButton(BBluetooth);
        Back_Home->setObjectName(QString::fromUtf8("Back_Home"));
        Back_Home->setGeometry(QRect(0, -10, 101, 661));
        Back_Home->setFocusPolicy(Qt::NoFocus);
        Back_Home->setContextMenuPolicy(Qt::NoContextMenu);
        Back_Home->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/home.png);"));
        Back_Home->setAutoDefault(true);
        Back_Home->setFlat(true);

        retranslateUi(BBluetooth);

        QMetaObject::connectSlotsByName(BBluetooth);
    } // setupUi

    void retranslateUi(QDialog *BBluetooth)
    {
        BBluetooth->setWindowTitle(QCoreApplication::translate("BBluetooth", "Dialog", nullptr));
        toggle_bluetooth->setText(QCoreApplication::translate("BBluetooth", "CheckBox", nullptr));
        bluetooth_icon->setText(QCoreApplication::translate("BBluetooth", "TextLabel", nullptr));
        bluetooth_state->setText(QCoreApplication::translate("BBluetooth", "TextLabel", nullptr));
        Back_Home->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BBluetooth: public Ui_BBluetooth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLUETOOTH_H
