#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTimer>
#include <QDebug>
#include <QUrl>
#include <QSettings>
#include "popNotify.h"
//#include "ui_popNotify.h"
#include "Camera.h"
#include "Weather.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //set as default page
    ui->FirstStack->setCurrentIndex(0);

/*Adhan things*/
     loadPrayerTimes();
   getAndDisplayPrayerTimes("Cairo");



    /*For Time*/

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start(1000);

    // For Date
    QDateTime dateTime = QDateTime::currentDateTime();
    QString datetimetext = "<font color='blue'>" + dateTime.toString("dddd, MMMM d, yyyy") + "</font>"; // Customize the date format and color
    ui->DateTime->setText(datetimetext);

    /*set icons for button */
    ui->pushButton_8->setIcon(QIcon(":/new/prefix1/Media/bluetooth_icon.png"));
    ui->pushButton_8->setIconSize(QSize(150,150));

    /* info*/
    ui->pushButton_9->setIcon(QIcon(" :/new/prefix1/Media/chris.jpeg"));
    ui->pushButton_9->setIconSize(QSize(150,150));

    /*bacground */
   // MainWindow::setStyleSheet("background:url(:/new/prefix1/Media/chris.jpeg)");

}

void MainWindow::showTime(){


    QDateTime currentTime = QDateTime::currentDateTime();
    QString timeText = "<font color='blue'>" + currentTime.toString("h:mm:ss AP") + "</font>"; // Customize the time format and color
    ui->Digital_Clock->setText(timeText);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::AdhanPage() {
    //int nextIndex = ui->PrayerStacked->currentIndex() + 1; // Assuming 0-based indexing
    ui->FirstStack->setCurrentIndex(4);
}
void MainWindow::on_pushButton_clicked()
{
    AdhanPage();

}

//***************************************************




void MainWindow::getAndDisplayPrayerTimes(const QString &city)
{
    // Construct the URL for the API request
    QString apiUrl = "https://muslimsalat.com/" + city + ".json?key=38562ca872msh5d45bd8ce413582p1bfd2ajsn9b1005826d68";

    // Create a QNetworkAccessManager instance to make the request
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url(apiUrl);
    QNetworkRequest request(url);

    // Make the GET request
    QNetworkReply *reply = manager->get(request);

    // Connect the reply's finished signal to a lambda function to handle the response
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Read response data
            QByteArray responseData = reply->readAll();

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

            // Output prayer times
            qDebug() << "Prayer Times:";
            for (auto it = m_prayerTimes.constBegin(); it != m_prayerTimes.constEnd(); ++it) {
                qDebug() << it.key().toString("h:mm AP") << ":" << it.value();
            }

            //Ui::MainWindow *ui = mainWindow->ui;
           // ui->PrayerStacked->setCurrentIndex(1);

            ui->label->setText("Fajr: " + fajrTime);
            ui->label_2->setText("Dhuhr: " + dhuhrTime);
            ui->label_3->setText("Asr: " + asrTime);
            ui->label_4->setText("Maghrib: " + maghribTime);
            ui->label_5->setText("Isha: " + ishaTime);

            // Schedule single-shot timer for the next prayer time
            scheduleNextPrayer();

            // Save fetched prayer times
            savePrayerTimes();

        } else {
            qDebug() << "Network Error:" << reply->errorString();

            // If there's no network, display the last fetched prayer times
            displayLastPrayerTimes();
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
        popNotify *popup =new  popNotify(this);
        popup->exec(); // Show the widget as a modal dialog
        // Set the media content and start playback
        /* QString filePath = "/home/haiidy/file.mp3"; // Update the file path as needed
        player->setMedia(QUrl::fromLocalFile(filePath));
        player->setVolume(50);
        player->play();*/

        // Schedule the next prayer
        scheduleNextPrayer();
    });

    // Print debug information
    qDebug() << "Next prayer scheduled at:" << nextPrayerDateTime.toString("yyyy-MM-dd hh:mm:ss");
}

void MainWindow::displayLastPrayerTimes()
{
    QSettings settings("MyCompany", "MyApp");
    settings.beginGroup("PrayerTimes");

    QString fajr = settings.value("Fajr", "").toString();
    QString dhuhr = settings.value("Dhuhr", "").toString();
    QString asr = settings.value("Asr", "").toString();
    QString maghrib = settings.value("Maghrib", "").toString();
    QString isha = settings.value("Isha", "").toString();
    //ui->PrayerStacked->setCurrentIndex(1);
    ui->label->setText( fajr);
    ui->label_2->setText( dhuhr);
    ui->label_3->setText(asr);
    ui->label_4->setText( maghrib);
    ui->label_5->setText( isha);

    settings.endGroup();
}

void MainWindow::savePrayerTimes()
{
    QSettings settings("MyCompany", "MyApp");
    settings.beginGroup("PrayerTimes");
   // ui->PrayerStacked->setCurrentIndex(1);
    settings.setValue("Fajr", ui->label->text());
    settings.setValue("Dhuhr", ui->label_2->text());
    settings.setValue("Asr", ui->label_3->text());
    settings.setValue("Maghrib", ui->label_4->text());
    settings.setValue("Isha", ui->label_5->text());

    settings.endGroup();
}

void MainWindow::loadPrayerTimes()
{
    QSettings settings("MyCompany", "MyApp");
    settings.beginGroup("PrayerTimes");

    QString fajr = settings.value("Fajr", "").toString();
    QString dhuhr = settings.value("Dhuhr", "").toString();
    QString asr = settings.value("Asr", "").toString();
    QString maghrib = settings.value("Maghrib", "").toString();
    QString isha = settings.value("Isha", "").toString();

    if (!fajr.isEmpty() && !dhuhr.isEmpty() && !asr.isEmpty() && !maghrib.isEmpty() && !isha.isEmpty()) {
        qDebug() << "Loaded last fetched prayer times.";
        displayLastPrayerTimes();
    }

    settings.endGroup();
}

void MainWindow::Back_Home()
{
    ui->FirstStack->setCurrentIndex(0);
}


void MainWindow::on_pushButton_2_clicked()
{
    Back_Home();
}


void MainWindow::on_pushButton_3_clicked()
{

    Camera *cameraWidget = new Camera(this);
    ui->FirstStack->insertWidget(1, cameraWidget);

     ui->FirstStack->setCurrentIndex(1);
}


void MainWindow::on_pushButton_6_clicked()
{
     ui->FirstStack->setCurrentIndex(0);
}




void MainWindow::on_pushButton_7_clicked()
{

     Weather *WeatherWidget = new Weather(this);
     ui->FirstStack->insertWidget(3, WeatherWidget);


     ui->FirstStack->setCurrentIndex(3);
}

