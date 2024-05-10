/********************************************************************************
** Form generated from reading UI file 'Settings.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QPushButton *Save_Changes;
    QPushButton *Back_Home;
    QLabel *label;
    QDateTimeEdit *dateTimeEdit;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(735, 491);
        Save_Changes = new QPushButton(Settings);
        Save_Changes->setObjectName(QString::fromUtf8("Save_Changes"));
        Save_Changes->setGeometry(QRect(200, 180, 161, 51));
        Save_Changes->setFocusPolicy(Qt::NoFocus);
        Save_Changes->setContextMenuPolicy(Qt::NoContextMenu);
        Save_Changes->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/save.png);"));
        Save_Changes->setAutoDefault(false);
        Save_Changes->setFlat(true);
        Back_Home = new QPushButton(Settings);
        Back_Home->setObjectName(QString::fromUtf8("Back_Home"));
        Back_Home->setGeometry(QRect(100, 330, 80, 26));
        Back_Home->setFocusPolicy(Qt::NoFocus);
        Back_Home->setContextMenuPolicy(Qt::NoContextMenu);
        Back_Home->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/home.png);"));
        Back_Home->setAutoDefault(false);
        Back_Home->setFlat(true);
        label = new QLabel(Settings);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 40, 141, 41));
        dateTimeEdit = new QDateTimeEdit(Settings);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(150, 90, 221, 51));

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QCoreApplication::translate("Settings", "Dialog", nullptr));
        Save_Changes->setText(QString());
        Back_Home->setText(QString());
        label->setText(QCoreApplication::translate("Settings", "Change Time :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
