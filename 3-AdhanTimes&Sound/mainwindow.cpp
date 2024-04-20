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
    getAndDisplayPrayerTimes("Cairo");
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
            // Parse the JSON response and insert prayer times into the map

            m_prayerTimes.clear(); // Clear existing data
            m_prayerTimes.insert(QTime::fromString(fajrTime, "h:mm AP"), "Fajr");
            m_prayerTimes.insert(QTime::fromString(dhuhrTime, "h:mm AP"), "Dhuhr");
            m_prayerTimes.insert(QTime::fromString(asrTime, "h:mm AP"), "Asr");
            m_prayerTimes.insert(QTime::fromString(maghribTime, "h:mm AP"), "Maghrib");
            m_prayerTimes.insert(QTime::fromString(ishaTime, "h:mm AP"), "Isha");

            // Update UI with prayer times
            ui->label->setText("Fajr: " + fajrTime);
            ui->label_2->setText("Dhuhr: " + dhuhrTime);
            ui->label_3->setText("Asr: " + asrTime);
            ui->label_4->setText("Maghrib: " + maghribTime);
            ui->label_5->setText("Isha: " + ishaTime);


            // Output prayer times
            // Print prayer times
            qDebug() << "Prayer Times:";
            for (auto it = m_prayerTimes.constBegin(); it != m_prayerTimes.constEnd(); ++it) {
                qDebug() << it.key().toString("h:mm AP") << ":" << it.value();
            }


            // Schedule single-shot timer for the next prayer time
            scheduleNextPrayer();

        } else {
            qDebug() << "Network Error:" << reply->errorString();
            // Handle network error
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


void MainWindow::scheduleNextPrayer()
{
    // Get current date and time
   QDateTime currentDateTime = QDateTime::currentDateTime();
   currentDateTime = currentDateTime.addSecs(-currentDateTime.time().second());

   // QDateTime currentDateTime = QDateTime::fromString("2024-04-20 3:28:00", "yyyy-MM-dd H:mm:ss"); //for test

    // Find the next prayer time
    QDateTime nextPrayerDateTime;

    for (auto it = m_prayerTimes.constBegin(); it != m_prayerTimes.constEnd(); ++it) {
        QDateTime prayerDateTime(currentDateTime.date(), it.key());
        if (prayerDateTime > currentDateTime) {
            nextPrayerDateTime = prayerDateTime;
            break;
        }
    }
    // If there's no next prayer time for today, schedule for tomorrow's Fajr
    if (nextPrayerDateTime.isNull()) {
        QDate tomorrow = currentDateTime.date().addDays(1);
        nextPrayerDateTime.setDate(tomorrow);
        nextPrayerDateTime.setTime(m_prayerTimes.firstKey());
    }

    // Calculate the time until the next prayer (in milliseconds)
    int msecToNextPrayer = currentDateTime.msecsTo(nextPrayerDateTime);


    // Print debug information
    qDebug() << "Current Date and Time:" << currentDateTime.toString("yyyy-MM-dd hh:mm:ss");

    // Schedule single-shot timer for the next prayer time
    QTimer::singleShot(msecToNextPrayer, [=]() {
        qDebug() << "It's time for" << m_prayerTimes[nextPrayerDateTime.time()] << "Adhan!";

        // Create a new player instance
        QMediaPlayer *player = new QMediaPlayer(this);

        // Set the media content
        QString filePath = "/home/haiidy/file.mp3"; // Update the file path as needed
        QUrl mediaUrl = QUrl::fromLocalFile(filePath);
        player->setMedia(mediaUrl);

        // Start playback
        player->setVolume(50);
        player->play();

        // Schedule the next prayer
        scheduleNextPrayer();
    });

    // Print debug information
    qDebug() << "Next prayer scheduled at:" << nextPrayerDateTime.toString("yyyy-MM-dd hh:mm:ss");
}


void MainWindow::on_pushButton_clicked()
{

    qDebug() << "Adhan sound stopped.";
    player->stop();
}

