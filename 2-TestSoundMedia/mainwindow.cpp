#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create a QMediaPlayer instance
    player = new QMediaPlayer(this);


    // Set the media content
    QString filePath = "/home/haiidy/file.mp3"; // Update the file path as needed
    player->setMedia(QUrl::fromLocalFile(filePath));

    // Start playback
    player->setVolume(50);
    player->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}


