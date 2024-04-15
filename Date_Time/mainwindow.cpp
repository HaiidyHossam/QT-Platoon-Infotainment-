#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //showTime();
    /*For Time*/
     QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
     timer->start();

      /*For Date*/
   /*  QDateTime dateTime =  QDateTime::currentDateTime();
     QString datetimetext = dateTime.toString();
     ui->DateTime->setText(datetimetext);*/

     // For Date
     QDateTime dateTime = QDateTime::currentDateTime();
     QString datetimetext = "<font color='blue'>" + dateTime.toString("dddd, MMMM d, yyyy") + "</font>"; // Customize the date format and color
     ui->DateTime->setText(datetimetext);

}

void MainWindow::showTime(){
 /*   QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss ");
    ui->Digital_Clock->setText(time_text);*/

    QDateTime currentTime = QDateTime::currentDateTime();
    QString timeText = "<font color='blue'>" + currentTime.toString("h:mm:ss AP") + "</font>"; // Customize the time format and color
    ui->Digital_Clock->setText(timeText);
}


MainWindow::~MainWindow()
{
    delete ui;
}
