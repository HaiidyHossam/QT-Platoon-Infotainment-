/********************************************************************************
** Form generated from reading UI file 'Prayer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRAYER_H
#define UI_PRAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Prayer
{
public:
    QPushButton *Back;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *Prayer)
    {
        if (Prayer->objectName().isEmpty())
            Prayer->setObjectName(QString::fromUtf8("Prayer"));
        Prayer->resize(515, 404);
        Prayer->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(0, 0, 0);"));
        Back = new QPushButton(Prayer);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(0, 0, 61, 401));
        Back->setFocusPolicy(Qt::NoFocus);
        Back->setContextMenuPolicy(Qt::NoContextMenu);
        Back->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/home.png);"));
        Back->setAutoDefault(false);
        Back->setFlat(true);
        layoutWidget = new QWidget(Prayer);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 40, 381, 201));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(label_5);


        retranslateUi(Prayer);

        QMetaObject::connectSlotsByName(Prayer);
    } // setupUi

    void retranslateUi(QDialog *Prayer)
    {
        Prayer->setWindowTitle(QCoreApplication::translate("Prayer", "Dialog", nullptr));
        Back->setText(QString());
        label->setText(QCoreApplication::translate("Prayer", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("Prayer", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("Prayer", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("Prayer", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("Prayer", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Prayer: public Ui_Prayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRAYER_H
