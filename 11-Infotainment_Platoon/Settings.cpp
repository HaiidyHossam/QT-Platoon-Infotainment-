#include "Settings.h"
#include "ui_Settings.h"
#include "mainwindow.h"
Settings::Settings(MainWindow *parent)
    : QDialog(parent)
    , ui(new Ui::Settings),
    mainWindowPtr(parent)

{
    ui->setupUi(this);

    /*settings page */
    //change time
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit->setDisplayFormat("yyyy-MM-dd HH:mm");
    // Allow user to edit date and time
    ui->dateTimeEdit->setReadOnly(false);


    // Connect the dateTimeChanged signal to the onDateTimeChanged slot
    connect(ui->dateTimeEdit, &QDateTimeEdit::dateTimeChanged, this, &Settings::on_dateTimeEdit_dateTimeChanged);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    this->dateTime=dateTime;
}


void Settings::on_Save_Changes_clicked()
{
    // Format the selected date and time
    QString timeText = dateTime.toString("yyyy-MM-dd hh:mm:ss");

    QString disableNTPCmd = "sudo timedatectl set-ntp false";
    QString setTimeCmd = "sudo  timedatectl set-time \"" + timeText + "\"";

    // Convert QString to QByteArray and then to const char*
    const char *ntpCmd = disableNTPCmd.toUtf8().constData();
    const char *setTimeCmdStr = setTimeCmd.toUtf8().constData();

    // Execute the commands
    qDebug() << "Time text: " << timeText;
    qDebug() << "Disable NTP command: " << disableNTPCmd;
    qDebug() << "Set time command: " << setTimeCmd;

    // Disable NTP
    int ntpResult = system(ntpCmd);
    if (ntpResult != 0) {
        qDebug() << "Error disabling NTP";
    } else {
        qDebug() << "NTP disabled successfully";
    }

    // Set time
    int setTimeResult = system(setTimeCmdStr);
    if (setTimeResult != 0) {
        qDebug() << "Error setting time";
    } else {
        qDebug() << "Time set successfully";
    }
    mainWindowPtr->scheduleNextPrayer();

}


void Settings::on_Back_Home_clicked()
{
    mainWindowPtr->Back_Home();
}
