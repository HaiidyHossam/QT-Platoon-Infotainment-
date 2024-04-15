/* DONEEEEEEE */

#include "mainwindow.h"

#include <QApplication>


//without pause button
/*int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QVideoWidget *videoWidget = new QVideoWidget;

    // Create a QMediaPlayer instance
    QMediaPlayer *player = new QMediaPlayer;



    // Set the media content for the player
    //player->setSource(QUrl::fromLocalFile("/home/mariaaam/Downloads/hi.mp4"));
    player->setSource(QUrl::fromLocalFile("/path/paths/hello.mp4"));

    // Set the video output format
    videoWidget->setFixedSize(100, 200); // Set the size of the video widget
    player->setVideoOutput(videoWidget);

    // Create a QVideoWidget instance to display video
   // QVideoWidget *videoWidget = new QVideoWidget;
    player->setVideoOutput(videoWidget);

    // Show the video widget
    videoWidget->show();

    // Play the media
    player->play();

    return app.exec();
}*/
///////////////////////

//with pause button
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create a QMediaPlayer instance
    QMediaPlayer *player = new QMediaPlayer;

    // Create a QVideoWidget instance to display video
    QVideoWidget *videoWidget = new QVideoWidget;
      videoWidget->setFixedSize(100, 200);
    player->setVideoOutput(videoWidget);

    // Set the media content for the player
    //player->setSource(QUrl::fromLocalFile("/path/paths/hello.mp4"));
    player->setSource(QUrl::fromLocalFile("/home/mariaaam/Downloads/hi.mp4"));
    // Create a button to pause the video
    QPushButton *pauseButton = new QPushButton("Pause");
    QObject::connect(pauseButton, &QPushButton::clicked, player, &QMediaPlayer::pause);

    // Create a layout to organize the video widget and button
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(videoWidget);
    layout->addWidget(pauseButton);

    // Create a widget to hold the layout
    QWidget *widget = new QWidget;
    widget->setLayout(layout);
    widget->show();

    // Play the media
    player->play();

    return app.exec();
}
