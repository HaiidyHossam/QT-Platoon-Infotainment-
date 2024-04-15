
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


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open MP3 File"), "", tr("MP3 Files (.mp3)"));

    // Set the media source of the player to the selected file
     player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile(fileName));
     //player->setSource(QUrl::fromLocalFile("/home/username/Downloads/name.mp3"));
     audioOutput->setVolume(200);
    // Play the media
    player->play();

}

