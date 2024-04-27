/********************************************************************************
** Form generated from reading UI file 'popNotify.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPNOTIFY_H
#define UI_POPNOTIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_popNotify
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *popNotify)
    {
        if (popNotify->objectName().isEmpty())
            popNotify->setObjectName(QString::fromUtf8("popNotify"));
        popNotify->resize(539, 384);
        label = new QLabel(popNotify);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 10, 221, 111));
        pushButton = new QPushButton(popNotify);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 170, 251, 81));

        retranslateUi(popNotify);

        QMetaObject::connectSlotsByName(popNotify);
    } // setupUi

    void retranslateUi(QDialog *popNotify)
    {
        popNotify->setWindowTitle(QCoreApplication::translate("popNotify", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("popNotify", "It is time for pray", nullptr));
        pushButton->setText(QCoreApplication::translate("popNotify", "Stop Sound", nullptr));
    } // retranslateUi

};

namespace Ui {
    class popNotify: public Ui_popNotify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPNOTIFY_H
