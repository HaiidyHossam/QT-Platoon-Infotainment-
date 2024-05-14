#include "Headers/Info.h"
#include "ui_Info.h"
#include "Headers/mainwindow.h"

Info::Info(MainWindow *parent)
    : QDialog(parent)
    , ui(new Ui::Info),
   mainWindowPtr(parent)
{
    ui->setupUi(this);
}

Info::~Info()
{
    delete ui;
}


void Info::on_Home_clicked()
{
    mainWindowPtr->Back_Home();
}

