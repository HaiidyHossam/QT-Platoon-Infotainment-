/********************************************************************************
** Form generated from reading UI file 'popNotify.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
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
    QPushButton *Stop_Sound;

    void setupUi(QDialog *popNotify)
    {
        if (popNotify->objectName().isEmpty())
            popNotify->setObjectName(QString::fromUtf8("popNotify"));
        popNotify->resize(539, 384);
        label = new QLabel(popNotify);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 10, 221, 111));
        Stop_Sound = new QPushButton(popNotify);
        Stop_Sound->setObjectName(QString::fromUtf8("Stop_Sound"));
        Stop_Sound->setGeometry(QRect(200, 240, 91, 91));
        Stop_Sound->setFocusPolicy(Qt::NoFocus);
        Stop_Sound->setContextMenuPolicy(Qt::NoContextMenu);
        Stop_Sound->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/Mute.png);"));
        Stop_Sound->setAutoDefault(false);
        Stop_Sound->setFlat(true);

        retranslateUi(popNotify);

        QMetaObject::connectSlotsByName(popNotify);
    } // setupUi

    void retranslateUi(QDialog *popNotify)
    {
        popNotify->setWindowTitle(QCoreApplication::translate("popNotify", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("popNotify", "It is time for pray", nullptr));
        Stop_Sound->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class popNotify: public Ui_popNotify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPNOTIFY_H
