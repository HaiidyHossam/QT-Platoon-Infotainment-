#include "mp4.h"
#include "ui_mp4.h"

#include "mainwindow.h"
#include "QDir"
#include "iostream"

Mp4::Mp4(MainWindow *parent)
    : QDialog(parent)
    , ui(new Ui::Mp4)
    , mainWindowPtr(parent) {
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateList()));
    timer->start(1000);
    player = new QMediaPlayer();
    player->setVolume(ui->verticalSlider_sound->value());
    connect(player, &QMediaPlayer::positionChanged, this, &Mp4::updateProgressBar);
    back();
}

Mp4::~Mp4() {
    delete ui;
    delete player;
    delete timer;
}

void Mp4::on_home_button_clicked() {
    mainWindowPtr->Back_Home();
}

void Mp4::back() {
    ui->back_button->hide();
    ui->groupBox->hide();
    ui->seek_backward_button->hide();
    ui->seek_forward_button->hide();
    ui->start_pause_button->hide();
    ui->horizontalSlider_duration->hide();
    ui->verticalSlider_sound->hide();
    ui->repeat_button->hide();
    ui->current_time_label->hide();
    ui->total_time_label->hide();
    ui->home_button->show();
    ui->listWidget->show();
    ui->label->show();
}

void Mp4::play() {
    ui->listWidget->hide();
    ui->home_button->hide();
    ui->label->hide();
    ui->back_button->show();
    ui->groupBox->show();
    ui->seek_backward_button->show();
    ui->seek_forward_button->show();
    ui->start_pause_button->show();
    ui->horizontalSlider_duration->show();
    ui->verticalSlider_sound->show();
    ui->repeat_button->show();
    ui->current_time_label->show();
    ui->total_time_label->show();
}


void Mp4::on_listWidget_itemClicked(QListWidgetItem *item) {
    play();
    std::cout << "Selected item: " << item->text().toStdString() << std::endl;
    QString filePath = "/media/"+QString::fromStdString(flashObj.usbName)+"/"+item->text();
    QUrl fileUrl = QUrl::fromLocalFile(filePath);
    video = new QVideoWidget();
    video->setGeometry(5,5,ui->groupBox->width()-10,ui->groupBox->height()-10);
    video->setParent(ui->groupBox);
    player->setVideoOutput(video);
    player->setMedia(QUrl(fileUrl));
    video->setVisible(true);
    video->show();
    player->play();
    ui->start_pause_button->setChecked(true);
}

void Mp4::updateList() {
    ui->listWidget->clear();
    if (flashObj.updateFlashStatus() == false) {
        ui->label->setText("Inser your USB!");
    }
    else {
        ui->label->clear();
    }
    QString directoryPath = "/media/"+QString::fromStdString(flashObj.usbName);

    // Create a QDir object to access the directory
    QDir directory(directoryPath);

    // Filter files by ".mp4" and ".mkv" and sort them alphabetically
    QStringList mp4Files = directory.entryList(QStringList() << "*.mp4", QDir::Files, QDir::Name);
    QStringList mkvFiles = directory.entryList(QStringList() << "*.mkv", QDir::Files, QDir::Name);

    // Add sorted mp4 files to the QListWidget 
    foreach (const QString &mp4File, mp4Files) {
        QListWidgetItem *item = new QListWidgetItem(mp4File);
        ui->listWidget->addItem(item);
    }
    // Add sorted mkv files to the QListWidget 
    foreach (const QString &mkvFile, mkvFiles) {
        QListWidgetItem *item = new QListWidgetItem(mkvFile);
        ui->listWidget->addItem(item);
    }
}


void Mp4::on_back_button_clicked() {
    back();
    player->stop();
    delete video;
}

void Mp4::on_repeat_button_clicked() {
    player->setPosition(0);
}


void Mp4::on_start_pause_button_clicked() {
    if(ui->start_pause_button->isChecked()) {
        player->play();
    }
    else {
        player->pause();
    }
}


void Mp4::on_seek_forward_button_clicked() {
    player->setPosition(player->position()+10000);
}


void Mp4::updateProgressBar() {
    if(player->duration() > 0) {
        int progress = (player->position()*100)/player->duration();
        ui->horizontalSlider_duration->setValue(progress);
    }
    // show current time and total time in form HH:MM:SS format
    int currentTime = player->position()/1000;
    int totalTime = player->duration()/1000;
    QTime currentTimeQTime((currentTime/3600)%60, (currentTime/60)%60, currentTime%60);
    QTime totalTimeQTime((totalTime/3600)%60, (totalTime/60)%60, totalTime%60);
    QString currentTimeString = currentTimeQTime.toString("HH:mm:ss");
    QString totalTimeString = totalTimeQTime.toString("HH:mm:ss");
    ui->current_time_label->setText(currentTimeString);
    ui->total_time_label->setText(totalTimeString);
}

void Mp4::on_seek_backward_button_clicked() {
    player->setPosition(player->position()-10000);
}


void Mp4::on_verticalSlider_sound_valueChanged(int value) {
    player->setVolume(value);
}


void Mp4::on_horizontalSlider_duration_sliderMoved(int position) {
    int newPos = ((position*player->duration())/100) ;
    player->setPosition(newPos);
}


void Mp4::on_horizontalSlider_duration_sliderReleased() {
    int position = ui->horizontalSlider_duration->value();
    int newPos = ((position*player->duration())/100) ;
    player->setPosition(newPos);
}

