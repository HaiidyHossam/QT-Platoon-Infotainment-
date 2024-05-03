#include "Prayer.h"
#include "ui_Prayer.h"
#include "mainwindow.h"
#include "QSettings"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTimer>
#include <QDebug>
#include <QUrl>

Prayer::Prayer(MainWindow *parent)
    : QDialog(parent)
    , ui(new Ui::Prayer),
    mainWindowPtr(parent)
{
    ui->setupUi(this);
    loadPrayerTimes();
    getAndDisplayPrayerTimes("Cairo");
}

Prayer::~Prayer()
{
    delete ui;
}




void Prayer::on_Back_clicked()
{

    mainWindowPtr->Back_Home();
}



//***************************************************

void Prayer::getAndDisplayPrayerTimes(const QString &city)
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

void Prayer::scheduleNextPrayer()
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
    popNotify *popup = new popNotify(this);
    popup->exec(); // Show the widget as a modal dialog

    // Schedule the next prayer
    scheduleNextPrayer();
});


qDebug() << "Next prayer scheduled at:" << nextPrayerDateTime.toString("yyyy-MM-dd hh:mm:ss");
}

void Prayer::displayLastPrayerTimes()
{
    QSettings settings("MyCompany", "MyApp");
    settings.beginGroup("PrayerTimes");
    QString fajr = settings.value("Fajr", "").toString();
    QString dhuhr = settings.value("Dhuhr", "").toString();
    QString asr = settings.value("Asr", "").toString();
    QString maghrib = settings.value("Maghrib", "").toString();
    QString isha = settings.value("Isha", "").toString();

    ui->label->setText(fajr);
    ui->label_2->setText(dhuhr);
    ui->label_3->setText(asr);
    ui->label_4->setText(maghrib);
    ui->label_5->setText(isha);

    settings.endGroup();
}

void Prayer::savePrayerTimes()
{
    QSettings settings("MyCompany", "MyApp");
    settings.beginGroup("PrayerTimes");
    settings.setValue("Fajr", ui->label->text());
    settings.setValue("Dhuhr", ui->label_2->text());
    settings.setValue("Asr", ui->label_3->text());
    settings.setValue("Maghrib", ui->label_4->text());
    settings.setValue("Isha", ui->label_5->text());

    settings.endGroup();
}

void Prayer::loadPrayerTimes()
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
