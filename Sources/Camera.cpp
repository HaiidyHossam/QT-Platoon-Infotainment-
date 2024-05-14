// Camera.cpp
#include "Headers/Camera.h"
#include "ui_Camera.h"
#include "Headers/mainwindow.h"

Camera::Camera(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::Camera),
    mainWindowPtr(parent) // Store the pointer to MainWindow
{
    ui->setupUi(this);
    camera = new QCamera(this);
    viewfinder = new QCameraViewfinder(this);
    QVBoxLayout *centralLayout = new QVBoxLayout(ui->centralWidget);
    centralLayout->addWidget(viewfinder);
}

Camera::~Camera()
{
    delete ui;
}

void Camera::startCamera()
{
    camera->setViewfinder(viewfinder);
    camera->start();
}

void Camera::stopCamera()
{
    camera->stop();
}

void Camera::on_Start_Camera_clicked()
{
    startCamera();
}

void Camera::on_Stop_Camera_clicked()
{
    stopCamera();
}

void Camera::on_Back_Home_clicked()
{
    mainWindowPtr->Back_Home();
}
