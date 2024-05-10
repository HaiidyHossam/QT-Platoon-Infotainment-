/********************************************************************************
** Form generated from reading UI file 'Weather.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHER_H
#define UI_WEATHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Weather
{
public:
    QLabel *currentTemperatureLabel;
    QLabel *currentWindSpeedLabel;
    QPushButton *Back_Home;

    void setupUi(QDialog *Weather)
    {
        if (Weather->objectName().isEmpty())
            Weather->setObjectName(QString::fromUtf8("Weather"));
        Weather->resize(400, 300);
        currentTemperatureLabel = new QLabel(Weather);
        currentTemperatureLabel->setObjectName(QString::fromUtf8("currentTemperatureLabel"));
        currentTemperatureLabel->setGeometry(QRect(20, 20, 361, 31));
        currentWindSpeedLabel = new QLabel(Weather);
        currentWindSpeedLabel->setObjectName(QString::fromUtf8("currentWindSpeedLabel"));
        currentWindSpeedLabel->setGeometry(QRect(20, 90, 351, 51));
        Back_Home = new QPushButton(Weather);
        Back_Home->setObjectName(QString::fromUtf8("Back_Home"));
        Back_Home->setGeometry(QRect(150, 150, 131, 61));

        retranslateUi(Weather);

        QMetaObject::connectSlotsByName(Weather);
    } // setupUi

    void retranslateUi(QDialog *Weather)
    {
        Weather->setWindowTitle(QCoreApplication::translate("Weather", "Dialog", nullptr));
        currentTemperatureLabel->setText(QString());
        currentWindSpeedLabel->setText(QString());
        Back_Home->setText(QCoreApplication::translate("Weather", "Home", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Weather: public Ui_Weather {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHER_H
