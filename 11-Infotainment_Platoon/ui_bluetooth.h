/********************************************************************************
** Form generated from reading UI file 'bluetooth.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
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

QT_BEGIN_NAMESPACE

class Ui_bluetooth
{
public:
    QCheckBox *toggle_bluetooth;
    QLabel *bluetooth_icon;
    QLabel *bluetooth_state;

    void setupUi(QDialog *bluetooth)
    {
        if (bluetooth->objectName().isEmpty())
            bluetooth->setObjectName(QString::fromUtf8("bluetooth"));
        bluetooth->resize(738, 468);
        toggle_bluetooth = new QCheckBox(bluetooth);
        toggle_bluetooth->setObjectName(QString::fromUtf8("toggle_bluetooth"));
        toggle_bluetooth->setGeometry(QRect(460, 30, 85, 24));
        bluetooth_icon = new QLabel(bluetooth);
        bluetooth_icon->setObjectName(QString::fromUtf8("bluetooth_icon"));
        bluetooth_icon->setGeometry(QRect(230, 120, 251, 41));
        bluetooth_state = new QLabel(bluetooth);
        bluetooth_state->setObjectName(QString::fromUtf8("bluetooth_state"));
        bluetooth_state->setGeometry(QRect(270, 230, 58, 18));

        retranslateUi(bluetooth);

        QMetaObject::connectSlotsByName(bluetooth);
    } // setupUi

    void retranslateUi(QDialog *bluetooth)
    {
        bluetooth->setWindowTitle(QCoreApplication::translate("bluetooth", "Dialog", nullptr));
        toggle_bluetooth->setText(QCoreApplication::translate("bluetooth", "CheckBox", nullptr));
        bluetooth_icon->setText(QCoreApplication::translate("bluetooth", "bluetooth_icon", nullptr));
        bluetooth_state->setText(QCoreApplication::translate("bluetooth", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bluetooth: public Ui_bluetooth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLUETOOTH_H
