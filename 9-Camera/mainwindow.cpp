#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    camera = new QCamera(this);
    viewfinder = new QCameraViewfinder(this);
    QVBoxLayout *centralLayout = new QVBoxLayout(ui->centralWidget);
    centralLayout->addWidget(viewfinder);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startCamera()
{
    camera->setViewfinder(viewfinder);
    camera->start();
}

void MainWindow::stopCamera()
{
    camera->stop();
}

void MainWindow::on_pushButton_clicked()
{
    startCamera();
}


void MainWindow::on_pushButton_2_clicked()
{
    stopCamera();
}

