/********************************************************************************
** Form generated from reading UI file 'Info.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_H
#define UI_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Info
{
public:
    QPushButton *Home;
    QLabel *label;

    void setupUi(QDialog *Info)
    {
        if (Info->objectName().isEmpty())
            Info->setObjectName(QString::fromUtf8("Info"));
        Info->resize(709, 492);
        Home = new QPushButton(Info);
        Home->setObjectName(QString::fromUtf8("Home"));
        Home->setGeometry(QRect(-40, 0, 141, 491));
        Home->setFocusPolicy(Qt::NoFocus);
        Home->setContextMenuPolicy(Qt::NoContextMenu);
        Home->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/home.png);"));
        Home->setAutoDefault(false);
        Home->setFlat(true);
        label = new QLabel(Info);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 80, 261, 91));

        retranslateUi(Info);

        QMetaObject::connectSlotsByName(Info);
    } // setupUi

    void retranslateUi(QDialog *Info)
    {
        Info->setWindowTitle(QCoreApplication::translate("Info", "Dialog", nullptr));
        Home->setText(QString());
        label->setText(QCoreApplication::translate("Info", "our QT Version : Qt 5.15.8", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Info: public Ui_Info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_H
