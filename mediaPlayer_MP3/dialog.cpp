#include "dialog.h"
#include "ui_dialog.h"

dialog::dialog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::dialog)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this); // Initialize QAudioOutput

    connect(player ,&QMediaPlayer::positionChanged,this,&dialog::on_positionChanged); //dialog is name of class i created like Mainwindow
    connect(player ,&QMediaPlayer::durationChanged,this,&dialog::on_durationChanged);
}

dialog::~dialog()
{
    delete ui;
}

void dialog::on_sliderProgrss_sliderMoved(int position)
{
  player->setPosition(position);
}

//1st implemntation
/*void dialog::on_sliderVolum_sliderMoved(int position)
{
    player->setVolume(position);
   // audioOutput->setVolume(200);
}*/

//2nd implementation
void dialog::on_sliderVolum_sliderMoved(int position)
{
    // Calculate the volume based on the position of the slider
    qreal volume = qreal(position) / 100.0;

    // Set the volume level on the audio output
    audioOutput->setVolume(volume);
}

void dialog::on_pushButton_clicked()
{
//load file to play
    player->setSource(QUrl::fromLocalFile("/home/mariaaam/Downloads/hi.mp4"));
    player->play();
    qDebug() <<player->errorString();
}


void dialog::on_pushButton_2_clicked()
{
    player->stop();

}

void dialog::on_durationChanged(qint64 position)
{
    ui->sliderProgrss->setMaximum(position);

}

void dialog::on_positionChanged(qint64 position)
{
    ui->sliderProgrss->setValue(position);
}

