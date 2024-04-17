#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize Bluetooth device discovery agent
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &MainWindow::deviceDiscovered);
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished,
            this, &MainWindow::deviceDiscoveryFinished);

    // Initialize media player
    player = new QMediaPlayer(this);

    // Connect signals and slots
    connect(ui->btnStartScan, &QPushButton::clicked, this, &MainWindow::startDeviceDiscovery);
    connect(ui->btnStopScan, &QPushButton::clicked, this, &MainWindow::stopDeviceDiscovery);
    connect(ui->btnSelectFile, &QPushButton::clicked, this, &MainWindow::selectMusicFile);
    connect(ui->btnPlay, &QPushButton::clicked, this, &MainWindow::playMusic);
    connect(ui->btnPause, &QPushButton::clicked, this, &MainWindow::pauseMusic);
    connect(ui->btnStop, &QPushButton::clicked, this, &MainWindow::stopMusic);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete discoveryAgent;
    delete player;
}



void MainWindow::deviceDiscovered(const QBluetoothDeviceInfo &info)
{
    ui->listDevices->addItem(info.name());
}

void MainWindow::deviceDiscoveryFinished()
{
  //  ui->statusBar->showMessage("Device discovery finished.");
    ui->btnStartScan->setEnabled(true);
    ui->btnStopScan->setEnabled(false);
}
//***********************************
void MainWindow::startDeviceDiscovery()
{    ui->listDevices->clear();
   // ui->statusBar->showMessage("Scanning for devices...");
    discoveryAgent->start();
    ui->btnStartScan->setEnabled(false);
    ui->btnStopScan->setEnabled(true);

}


void MainWindow::stopDeviceDiscovery()
{
    discoveryAgent->stop();
    //ui->statusBar->showMessage("Scan stopped.");
    ui->btnStartScan->setEnabled(true);
    ui->btnStopScan->setEnabled(false);
}


void MainWindow::selectMusicFile()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Select Music File");
    if (!filePath.isEmpty()) {
        ui->txtFilePath->setText(filePath);
        ui->btnPlay->setEnabled(true);
        ui->btnPause->setEnabled(true);
        ui->btnStop->setEnabled(true);
    }
}


void MainWindow::playMusic()
{
    player->setSource(QUrl::fromLocalFile(ui->txtFilePath->text()));
    //player->setVolume(50);
    player->play();
}


void MainWindow::pauseMusic()
{
    player->pause();
}


void MainWindow::stopMusic()
{
    player->stop();
}

