/********************************************************************************
** Form generated from reading UI file 'mp4.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MP4_H
#define UI_MP4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mp4
{
public:
    QWidget *centralwidget;
    QPushButton *home_button;
    QListWidget *listWidget;
    QLabel *label;
    QPushButton *back_button;
    QGroupBox *groupBox;
    QCheckBox *start_pause_button;
    QPushButton *repeat_button;
    QPushButton *seek_forward_button;
    QPushButton *seek_backward_button;
    QSlider *verticalSlider_sound;
    QSlider *horizontalSlider_duration;
    QLabel *current_time_label;
    QLabel *total_time_label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QDialog *Mp4)
    {
        if (Mp4->objectName().isEmpty())
            Mp4->setObjectName(QString::fromUtf8("Mp4"));
        Mp4->resize(1075, 796);
        centralwidget = new QWidget(Mp4);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setGeometry(QRect(30, 30, 1021, 731));
        centralwidget->setContextMenuPolicy(Qt::NoContextMenu);
        home_button = new QPushButton(centralwidget);
        home_button->setObjectName(QString::fromUtf8("home_button"));
        home_button->setGeometry(QRect(0, 0, 80, 731));
        home_button->setFocusPolicy(Qt::NoFocus);
        home_button->setContextMenuPolicy(Qt::NoContextMenu);
        home_button->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/home.png);"));
        home_button->setAutoDefault(false);
        home_button->setFlat(true);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(80, 40, 921, 611));
        listWidget->setContextMenuPolicy(Qt::NoContextMenu);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 0, 591, 20));
        label->setContextMenuPolicy(Qt::NoContextMenu);
        back_button = new QPushButton(centralwidget);
        back_button->setObjectName(QString::fromUtf8("back_button"));
        back_button->setGeometry(QRect(0, 0, 80, 731));
        back_button->setContextMenuPolicy(Qt::NoContextMenu);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(50, 30, 921, 551));
        groupBox->setContextMenuPolicy(Qt::NoContextMenu);
        start_pause_button = new QCheckBox(centralwidget);
        start_pause_button->setObjectName(QString::fromUtf8("start_pause_button"));
        start_pause_button->setGeometry(QRect(460, 620, 82, 23));
        start_pause_button->setFocusPolicy(Qt::NoFocus);
        start_pause_button->setContextMenuPolicy(Qt::NoContextMenu);
        repeat_button = new QPushButton(centralwidget);
        repeat_button->setObjectName(QString::fromUtf8("repeat_button"));
        repeat_button->setGeometry(QRect(150, 620, 81, 21));
        repeat_button->setFocusPolicy(Qt::NoFocus);
        repeat_button->setContextMenuPolicy(Qt::NoContextMenu);
        repeat_button->setAutoDefault(false);
        repeat_button->setFlat(true);
        seek_forward_button = new QPushButton(centralwidget);
        seek_forward_button->setObjectName(QString::fromUtf8("seek_forward_button"));
        seek_forward_button->setGeometry(QRect(660, 620, 80, 25));
        seek_forward_button->setFocusPolicy(Qt::NoFocus);
        seek_forward_button->setContextMenuPolicy(Qt::NoContextMenu);
        seek_forward_button->setAutoDefault(false);
        seek_forward_button->setFlat(true);
        seek_backward_button = new QPushButton(centralwidget);
        seek_backward_button->setObjectName(QString::fromUtf8("seek_backward_button"));
        seek_backward_button->setGeometry(QRect(310, 620, 80, 25));
        seek_backward_button->setFocusPolicy(Qt::NoFocus);
        seek_backward_button->setContextMenuPolicy(Qt::NoContextMenu);
        seek_backward_button->setAutoDefault(false);
        seek_backward_button->setFlat(true);
        verticalSlider_sound = new QSlider(centralwidget);
        verticalSlider_sound->setObjectName(QString::fromUtf8("verticalSlider_sound"));
        verticalSlider_sound->setGeometry(QRect(950, 590, 20, 131));
        verticalSlider_sound->setContextMenuPolicy(Qt::NoContextMenu);
        verticalSlider_sound->setMinimum(1);
        verticalSlider_sound->setSliderPosition(50);
        verticalSlider_sound->setOrientation(Qt::Vertical);
        horizontalSlider_duration = new QSlider(centralwidget);
        horizontalSlider_duration->setObjectName(QString::fromUtf8("horizontalSlider_duration"));
        horizontalSlider_duration->setGeometry(QRect(180, 670, 691, 20));
        horizontalSlider_duration->setContextMenuPolicy(Qt::NoContextMenu);
        horizontalSlider_duration->setPageStep(1);
        horizontalSlider_duration->setOrientation(Qt::Horizontal);
        current_time_label = new QLabel(centralwidget);
        current_time_label->setObjectName(QString::fromUtf8("current_time_label"));
        current_time_label->setGeometry(QRect(100, 670, 71, 17));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        current_time_label->setFont(font);
        current_time_label->setFocusPolicy(Qt::NoFocus);
        current_time_label->setContextMenuPolicy(Qt::NoContextMenu);
        total_time_label = new QLabel(centralwidget);
        total_time_label->setObjectName(QString::fromUtf8("total_time_label"));
        total_time_label->setGeometry(QRect(880, 670, 71, 17));
        total_time_label->setFont(font);
        total_time_label->setContextMenuPolicy(Qt::NoContextMenu);
        menubar = new QMenuBar(Mp4);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menubar->setContextMenuPolicy(Qt::NoContextMenu);
        statusbar = new QStatusBar(Mp4);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setGeometry(QRect(0, 0, 3, 22));
        statusbar->setContextMenuPolicy(Qt::NoContextMenu);

        retranslateUi(Mp4);

        QMetaObject::connectSlotsByName(Mp4);
    } // setupUi

    void retranslateUi(QDialog *Mp4)
    {
        Mp4->setWindowTitle(QCoreApplication::translate("Mp4", "Dialog", nullptr));
        home_button->setText(QString());
        label->setText(QString());
        back_button->setText(QCoreApplication::translate("Mp4", "back", nullptr));
        groupBox->setTitle(QString());
        start_pause_button->setText(QCoreApplication::translate("Mp4", "CheckBox", nullptr));
        repeat_button->setText(QCoreApplication::translate("Mp4", "repeat", nullptr));
        seek_forward_button->setText(QCoreApplication::translate("Mp4", "+10", nullptr));
        seek_backward_button->setText(QCoreApplication::translate("Mp4", "-10", nullptr));
        current_time_label->setText(QCoreApplication::translate("Mp4", "00:00:00", nullptr));
        total_time_label->setText(QCoreApplication::translate("Mp4", "00:00:00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mp4: public Ui_Mp4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MP4_H
