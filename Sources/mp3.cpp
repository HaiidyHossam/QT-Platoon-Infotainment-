#include "Headers/mp3.h"
#include "ui_mp3.h"
#include <iostream>
#include "Headers/flash.h"
#include "QDir"
#include <QListWidget>
#include "QDebug"
#include <QFileDialog>
#include <QtMultimedia>
#include <QRandomGenerator>

Mp3::Mp3(MainWindow *parent)
    : QDialog(parent)
    , ui(new Ui::Mp3)
    , mainWindowPtr(parent) {
    ui->setupUi(this);
    player = new QMediaPlayer();
    timer = new QTimer(this);
    connect(player, &QMediaPlayer::positionChanged, this, &Mp3::updateProgressBar);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateList()));
     connect(player, &QMediaPlayer::mediaStatusChanged, this, &Mp3::handleMediaStatusChanged);
    player->setVolume(ui->verticalSlider->value());
    ui->label_2->hide();
    timer->start(1000);
}

Mp3::~Mp3() {
    delete ui;
    delete player;
    delete timer;
}


void Mp3::updateList() {
    ui->listWidget->clear();
    if (flashObj.updateFlashStatus() == false) {
        ui->label->setText("Insert a USB!");
        ui->label->show();
        ui->label_2->hide();
    }
    else {
        ui->label->clear();
        ui->label->hide();
    }
    QString directoryPath = "/media/"+QString::fromStdString(flashObj.usbName);

    // Create a QDir object to access the directory
    QDir directory(directoryPath);

    // Filter files by ".mp3" and sort them alphabetically
    QStringList mp3Files = directory.entryList(QStringList() << "*.mp3", QDir::Files, QDir::Name);

    if(mp3Files.isEmpty()&&(!flashObj.usbName.empty())){
        ui->label_2->show();
    }
    else{
        ui->label_2->hide();
    }
    // Add sorted mp3 files to the QListWidget
    foreach (const QString &mp3File, mp3Files) {
        QListWidgetItem *item = new QListWidgetItem(mp3File);
        item->setForeground(QColor("white"));
        ui->listWidget->addItem(item);
    }

}

void Mp3::on_listWidget_itemClicked(QListWidgetItem *item) {
    indx = ui->listWidget->currentRow();
    std::cout << "Selected item: " << item->text().toStdString() << std::endl;
    QString filePath = "/media/"+QString::fromStdString(flashObj.usbName)+"/"+item->text();
    QUrl fileUrl = QUrl::fromLocalFile(filePath);
    player->setMedia(fileUrl);
    ui->horizontalSlider->setValue(0);
    player->play();
    ui->start_stop_button->setChecked(true);
}

void Mp3::updateProgressBar() {

    int progress=0;
    if(player->duration() > 0) {
        progress = (player->position()*100)/player->duration();
        ui->horizontalSlider->setValue(progress);
    }
    if(progress==100)
    {
        on_next_button_clicked();
    }
}

void Mp3::on_horizontalSlider_sliderMoved(int position) {
    int newPos = ((position*player->duration())/100) ;
    player->setPosition(newPos);
}

void Mp3::on_horizontalSlider_sliderReleased() {
    int position = ui->horizontalSlider->value();
    int newPos = ((position*player->duration())/100) ;
    player->setPosition(newPos);
}

void Mp3::on_verticalSlider_valueChanged(int value) {
    player->setVolume(value);
}

void Mp3::on_start_stop_button_clicked() {
    if(ui->start_stop_button->isChecked()) {
        player->play();
    }
    else {
        player->pause();
    }
}

void Mp3::on_next_button_clicked() {
    QListWidgetItem *nextItem ;
    if (ui->listWidget->count() == 0) {
        return;
    }
    int currentIndex = indx; //ui->listWidget->currentRow();
    if(rand==false)
    {
         nextItem = ui->listWidget->item(currentIndex+1);
    }
    else
    {
        int randomIndex = QRandomGenerator::global()->bounded(ui->listWidget->count());
         nextItem = ui->listWidget->item(randomIndex);
    }

    if (nextItem == nullptr) {
        nextItem = ui->listWidget->item(0);
    }
    ui->listWidget->setCurrentItem(nextItem);
    on_listWidget_itemClicked(nextItem);
}

void Mp3::on_previous_button_clicked() {
    if (ui->listWidget->count() == 0) {
        return;
    }
    int currentIndex = indx; //ui->listWidget->currentRow();
    QListWidgetItem *nextItem = ui->listWidget->item(currentIndex-1);
    if (nextItem == nullptr) {
        nextItem = ui->listWidget->item(ui->listWidget->count()-1);
    }
    ui->listWidget->setCurrentItem(nextItem);
    on_listWidget_itemClicked(nextItem);
}

void Mp3::on_repeat_button_clicked() {
    player->setPosition(0);
}


void Mp3::on_home_button_clicked() {
    mainWindowPtr->Back_Home();
}

void Mp3::handleMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if(status == QMediaPlayer::EndOfMedia)
    {
        on_next_button_clicked();
        player->play();
        player->pause();

    }


}




void Mp3::on_shuffle_clicked()
{
    if(ui->shuffle->isChecked()) {
        rand=true;
    }
    else {
        rand=false;
    }

}

