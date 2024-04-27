/********************************************************************************
** Form generated from reading UI file 'Camera.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERA_H
#define UI_CAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Camera
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *centralWidget;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Camera)
    {
        if (Camera->objectName().isEmpty())
            Camera->setObjectName(QString::fromUtf8("Camera"));
        Camera->resize(646, 487);
        pushButton = new QPushButton(Camera);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 20, 131, 81));
        pushButton_2 = new QPushButton(Camera);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 20, 151, 91));
        centralWidget = new QWidget(Camera);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setGeometry(QRect(80, 170, 381, 181));
        pushButton_3 = new QPushButton(Camera);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(200, 380, 161, 71));

        retranslateUi(Camera);

        QMetaObject::connectSlotsByName(Camera);
    } // setupUi

    void retranslateUi(QDialog *Camera)
    {
        Camera->setWindowTitle(QCoreApplication::translate("Camera", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Camera", "Start Camera", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Camera", "Stop Camera", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Camera", "Home", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Camera: public Ui_Camera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_H
