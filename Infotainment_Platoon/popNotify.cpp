#include "popNotify.h"
#include "ui_popNotify.h"


popNotify::popNotify(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::popNotify)
{
    ui->setupUi(this);
    player = new QMediaPlayer();
    QString filePath = "/home/haiidy/file.mp3"; // Update the file path as needed
    player->setMedia(QUrl::fromLocalFile(filePath));
    player->setVolume(50);
    player->play();

}

popNotify::~popNotify()
{
    delete ui;
}

void popNotify::on_Stop_Sound_clicked()
{
    player->stop();
    close(); // Close the pop-up window

}

