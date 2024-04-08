
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create a QMediaPlayer instance

    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    // ..
    //
    player->setSource(QUrl::fromLocalFile("C:/Users/Dell/Desktop/song/file.mp3"));
    audioOutput->setVolume(50);
    player->play();


}

MainWindow::~MainWindow()
{
    delete ui;
}


