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
    getAndDisplayPrayerTimes( "Cairo","Egypt");
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::checkCurrentTime);
    timer->start(60000); // Check every 1minute

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::getAndDisplayPrayerTimes(const QString &city, const QString &country) {
    // Construct the URL for the API request
    QString apiUrl = "http://api.aladhan.com/v1/timingsByCity?city=" + city + "&country=" + country;

    // Create a QNetworkAccessManager instance to make the request
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url(apiUrl);
    QNetworkRequest request(url);

    QNetworkReply *reply = manager->get(request);

    // Connect the reply's finished signal to a lambda function to handle the response
    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Read response data
            QByteArray responseData = reply->readAll();
            qDebug() << "Response Data:" << responseData;

            // Parse the JSON response
            QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
            //obtaining the root object of the JSON document enables you to access and work with its contents in a more structured manner.
            QJsonObject jsonObject = jsonResponse.object();

            qDebug() << "Parsed JSON:" << jsonObject;

            // Extract prayer times object from the response
            QJsonObject dataObject = jsonObject.value("data").toObject();
            QJsonObject timingsObject = dataObject.value("timings").toObject();

            // Output prayer times
            qDebug() << "Prayer Times:";
            qDebug() << "Fajr:" << timingsObject.value("Fajr").toString();
            qDebug() << "Dhuhr:" << timingsObject.value("Dhuhr").toString();
            qDebug() << "Asr:" << timingsObject.value("Asr").toString();

            qDebug() << "Maghrib:" << timingsObject.value("Maghrib").toString();
            qDebug() << "Isha:" << timingsObject.value("Isha").toString();

            ui->label->setText("Fajr: " + timingsObject.value("Fajr").toString());
            ui->label_2->setText("Dhuhr: " + timingsObject.value("Dhuhr").toString());
            ui->label_3->setText("Asr: " + timingsObject.value("Asr").toString());
            ui->label_4->setText("Maghrib: " + timingsObject.value("Maghrib").toString());
            ui->label_5->setText("Isha: " + timingsObject.value("Isha").toString());

            // Iterate over the keys and values of timingsObject



            for (auto it = timingsObject.constBegin(); it != timingsObject.constEnd(); ++it) {
                QString prayerName = it.key();
                QString prayerTimeString = it.value().toString();

                QTime prayerTime = QTime::fromString(prayerTimeString, "hh:mm");

                m_prayerTimes.insert(prayerTime, prayerName); // Insert QTime into m_prayerTimes map
            }

            // Print keys in m_prayerTimes map
            /* qDebug() << "Keys in m_prayerTimes map:";
            for (auto it = m_prayerTimes.constBegin(); it != m_prayerTimes.constEnd(); ++it) {
                qDebug() << it.key();
            }*/

        } else {
            qDebug() << "Network Error:" << reply->errorString();
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

    // Check if m_prayerTimes map contains current time
    if (m_prayerTimes.contains(currentTime)) {
        qDebug() << "m_prayerTimes contains current time:" << currentTime;
        qDebug() << "It's time for adhan!";
        //  adhan sound playback
        player = new QMediaPlayer(this);


        // Set the media content
        QString filePath = ":/res/ResSound/file.mp3"; // Update the file path as needed
        player->setMedia(QUrl::fromLocalFile(filePath));

        // Start playback
        player->setVolume(50);
        player->play();


    } else {
        qDebug() << "m_prayerTimes does not contain current time:" << currentTime;
    }
}






void MainWindow::on_pushButton_clicked()
{
    player->stop();
    qDebug() << "Adhan sound stopped.";
}

