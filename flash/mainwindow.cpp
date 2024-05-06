#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mp3.h"
#include "mp4.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    //set as default page
    ui->FirstStack->setCurrentIndex(0);

    /* set widget as stacked widget*/
    Mp3 *mp3 = new Mp3(this);
    ui->FirstStack->insertWidget(1, mp3);
    Mp4 *mp4 = new Mp4(this);
    ui->FirstStack->insertWidget(2, mp4);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_mp3_button_clicked() {
    ui->FirstStack->setCurrentIndex(1);
}


void MainWindow::on_mp4_button_clicked() {
    ui->FirstStack->setCurrentIndex(2);
}

void MainWindow::Back_Home(void) {
    ui->FirstStack->setCurrentIndex(0);
}

