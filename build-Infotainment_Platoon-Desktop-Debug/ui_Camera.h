/********************************************************************************
** Form generated from reading UI file 'Camera.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
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
    QPushButton *Start_Camera;
    QPushButton *Stop_Camera;
    QWidget *centralWidget;
    QPushButton *Back_Home;

    void setupUi(QDialog *Camera)
    {
        if (Camera->objectName().isEmpty())
            Camera->setObjectName(QString::fromUtf8("Camera"));
        Camera->resize(1024, 600);
        Camera->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        Start_Camera = new QPushButton(Camera);
        Start_Camera->setObjectName(QString::fromUtf8("Start_Camera"));
        Start_Camera->setGeometry(QRect(120, 340, 131, 111));
        Start_Camera->setFocusPolicy(Qt::NoFocus);
        Start_Camera->setContextMenuPolicy(Qt::NoContextMenu);
        Start_Camera->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/cameraon.png);"));
        Start_Camera->setAutoDefault(false);
        Start_Camera->setFlat(true);
        Stop_Camera = new QPushButton(Camera);
        Stop_Camera->setObjectName(QString::fromUtf8("Stop_Camera"));
        Stop_Camera->setGeometry(QRect(370, 340, 131, 111));
        Stop_Camera->setFocusPolicy(Qt::NoFocus);
        Stop_Camera->setContextMenuPolicy(Qt::NoContextMenu);
        Stop_Camera->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/cameraoff.png);"));
        Stop_Camera->setAutoDefault(false);
        Stop_Camera->setFlat(true);
        centralWidget = new QWidget(Camera);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setGeometry(QRect(110, 70, 451, 221));
        Back_Home = new QPushButton(Camera);
        Back_Home->setObjectName(QString::fromUtf8("Back_Home"));
        Back_Home->setGeometry(QRect(-20, 0, 121, 601));
        Back_Home->setFocusPolicy(Qt::NoFocus);
        Back_Home->setContextMenuPolicy(Qt::NoContextMenu);
        Back_Home->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/home.png);"));
        Back_Home->setAutoDefault(false);
        Back_Home->setFlat(true);

        retranslateUi(Camera);

        QMetaObject::connectSlotsByName(Camera);
    } // setupUi

    void retranslateUi(QDialog *Camera)
    {
        Camera->setWindowTitle(QCoreApplication::translate("Camera", "Dialog", nullptr));
        Start_Camera->setText(QString());
        Stop_Camera->setText(QString());
        Back_Home->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Camera: public Ui_Camera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_H
