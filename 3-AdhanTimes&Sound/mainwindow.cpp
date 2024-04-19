#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>
#include <QTimer>
#include <QTime>
#include <QMap>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Fetch and display prayer times
    getAndDisplayPrayerTimes( "Cairo");
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::checkCurrentTime);
    timer->start(60000); // Check every 1minute

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::getAndDisplayPrayerTimes(const QString &city) {
    // Construct the URL for the API request
    QString apiUrl = "https://muslimsalat.com/" + city + ".json?key=38562ca872msh5d45bd8ce413582p1bfd2ajsn9b1005826d68";

    // Create a QNetworkAccessManager instance to make the request
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url(apiUrl);
    QNetworkRequest request(url);

    // Make the GET request
    QNetworkReply *reply = manager->get(request);

    // Connect the reply's finished signal to a lambda function to handle the response
    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Read response data
            QByteArray responseData = reply->readAll();
            qDebug() << "Response Data:" << responseData;

            // Parse the JSON response
            QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
            QJsonObject jsonObject = jsonResponse.object();

            // Extract prayer times object from the response
            QJsonArray itemsArray = jsonObject.value("items").toArray();
            if (itemsArray.isEmpty()) {
                qDebug() << "Error: Empty items array.";
                return;
            }
              QJsonObject prayerTimesObject = itemsArray.at(0).toObject();
            QString fajrTime = prayerTimesObject.value("fajr").toString();
            QString dhuhrTime = prayerTimesObject.value("dhuhr").toString();
            QString asrTime = prayerTimesObject.value("asr").toString();
            QString maghribTime = prayerTimesObject.value("maghrib").toString();
            QString ishaTime = prayerTimesObject.value("isha").toString();

            // Parse prayer times and insert into the map
            m_prayerTimes.clear(); // Clear existing data
            m_prayerTimes.insert(QTime::fromString(fajrTime, "h:mm AP"), "Fajr");
            m_prayerTimes.insert(QTime::fromString(dhuhrTime, "h:mm AP"), "Dhuhr");
            m_prayerTimes.insert(QTime::fromString(asrTime, "h:mm AP"), "Asr");
            m_prayerTimes.insert(QTime::fromString(maghribTime, "h:mm AP"), "Maghrib");
           m_prayerTimes.insert(QTime::fromString(ishaTime, "h:mm AP"), "Isha");
          //  m_prayerTimes.insert(QTime::fromString("11:33:00 PM", "hh:mm:ss AP"), "Isha"); for test




            // Output prayer times
            qDebug() << "Prayer Times:";
            qDebug() << "Fajr:" << fajrTime;
            qDebug() << "Dhuhr:" << dhuhrTime;
            qDebug() << "Asr:" << asrTime;
            qDebug() << "Maghrib:" << maghribTime;
            qDebug() << "Isha:" << ishaTime;

            // Update UI with prayer times
            ui->label->setText("Fajr: " + fajrTime);
            ui->label_2->setText("Dhuhr: " + dhuhrTime);
            ui->label_3->setText("Asr: " + asrTime);
            ui->label_4->setText("Maghrib: " + maghribTime);
            ui->label_5->setText("Isha: " + ishaTime);

        } else {
            qDebug() << "Network Error be carefull :" << reply->errorString();
            ui->label->setText("Fajr: 3:49 am");
            ui->label_2->setText("Dhuhr: 11:54 am");
            ui->label_3->setText("Asr: 3:29 pm");
            ui->label_4->setText("Maghrib: 6:29 pm");
            ui->label_5->setText("Isha: 7:48 pm");
        }

        // Clean up
        reply->deleteLater();
    });
}





void MainWindow::checkCurrentTime()
{
    // Get current time
    QTime currentTime = QTime::currentTime();
    // Round current time to nearest minute and remove milliseconds
    currentTime = currentTime.addSecs(-currentTime.second()).addMSecs(-currentTime.msec());
   // QTime currentTime = QTime::fromString("18:29:00", "h:mm:ss");


    // Check if m_prayerTimes map contains current time
    if (m_prayerTimes.contains(currentTime)) {
        qDebug() << "m_prayerTimes contains current time:" << currentTime;
        qDebug() << "It's time for adhan!";
        //  adhan sound playback
        player = new QMediaPlayer(this);


        // Set the media content:/res/ResSound/file.mp3
        QString filePath = "/home/haiidy/file.mp3"; // Update the file path as needed
        player->setMedia(QUrl::fromLocalFile(filePath));

        // Start playback
        player->setVolume(50);
        player->play();
    } else {
        qDebug() << "m_prayerTimes does not contain current time:" << currentTime;
        qDebug() << "Prayer times in m_prayerTimes map:";
        for (auto it = m_prayerTimes.constBegin(); it != m_prayerTimes.constEnd(); ++it) {
            qDebug() << it.key() << ":" << it.value();
        }
    }

}
void MainWindow::on_pushButton_clicked()
{
    player->stop();
    qDebug() << "Adhan sound stopped.";
}
