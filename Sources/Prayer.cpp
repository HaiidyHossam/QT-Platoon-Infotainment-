
#include "Headers/Prayer.h"
#include "ui_Prayer.h"
#include "Headers/mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDate>
#include <QDebug>
#include <QTimer>
#include <QSettings>
#include <QCheckBox>

Prayer::Prayer(MainWindow *parent)
    : QDialog(parent)
    , ui(new Ui::Prayer)
    , mainWindowPtr(parent)
{
    ui->setupUi(this);

    // Load saved settings
    loadSettings();

    // Connect the checkbox state change to a slot
    connect(ui->checkBox_Notify, &QCheckBox::stateChanged, this, &Prayer::on_checkBox_Notify_stateChanged);

    loadPrayerTimes(); // Load prayer times from local storage
    m_dataFromApi = false; // Initial assumption is data is not from API
    scheduleNextPrayer(); // Schedule the next prayer based on stored times
    getAndDisplayPrayerTimes();
}

Prayer::~Prayer()
{
    delete ui;
}

void Prayer::on_Back_clicked()
{
    mainWindowPtr->Back_Home();
}

void Prayer::getAndDisplayPrayerTimes()
{
    QString dateString = QDate::currentDate().toString("dd-MM-yyyy");
    QString apiUrl = "https://api.aladhan.com/v1/timingsByCity/" + dateString + "?city=Cairo&country=Egypt&method=8";

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
            QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
            QJsonObject jsonObj = jsonDoc.object();

            int responseCode = jsonObj.value("code").toInt();
            QString status = jsonObj.value("status").toString();
            qDebug() << "Response code:" << responseCode;
            qDebug() << "Status:" << status;

            if (responseCode == 200) {
                QJsonObject dataObj = jsonObj.value("data").toObject();
                QJsonObject timingsObj = dataObj.value("timings").toObject();

                QString fajrTime = timingsObj.value("Fajr").toString();
                QString dhuhrTime = timingsObj.value("Dhuhr").toString();
                QString asrTime = timingsObj.value("Asr").toString();
                QString maghribTime = timingsObj.value("Maghrib").toString();
                QString ishaTime = timingsObj.value("Isha").toString();

                // Output prayer times (for debugging)
                qDebug() << "Prayer Times (from Aladhan API):";
                qDebug() << "Fajr:" << fajrTime;
                qDebug() << "Dhuhr:" << dhuhrTime;
                qDebug() << "Asr:" << asrTime;
                qDebug() << "Maghrib:" << maghribTime;
                qDebug() << "Isha:" << ishaTime;

                // Update UI with fetched prayer times
                updateUIWithPrayerTimes(fajrTime, dhuhrTime, asrTime, maghribTime, ishaTime);

                // Update m_prayerTimes with the fetched times
                m_prayerTimes.clear();
                m_prayerTimes.insert(QTime::fromString(fajrTime, "hh:mm"), "Fajr");
                m_prayerTimes.insert(QTime::fromString(dhuhrTime, "hh:mm"), "Dhuhr");
                m_prayerTimes.insert(QTime::fromString(asrTime, "hh:mm"), "Asr");
                m_prayerTimes.insert(QTime::fromString(maghribTime, "hh:mm"), "Maghrib");
                m_prayerTimes.insert(QTime::fromString(ishaTime, "hh:mm"), "Isha");

                // Save fetched prayer times (for future reference)
                savePrayerTimes();

                m_dataFromApi = true; // Data is from API

                // Schedule the next prayer
                scheduleNextPrayer();
            } else {

                qDebug() << "Invalid response code:" << responseCode;
            }
        } else {
            qDebug() << "Network Error:" << reply->errorString();

            // If there's no network, display the last fetched prayer times
            displayLastPrayerTimes();
            m_dataFromApi = false; // Data is not from API
        }

        // Clean up
        reply->deleteLater();
    });
}



void Prayer::updateUIWithPrayerTimes(const QString &fajrTime, const QString &dhuhrTime,
                                     const QString &asrTime, const QString &maghribTime,
                                     const QString &ishaTime)
{
    // Update UI labels with 24-hour format times
    ui->label->setText("Fajr: " + fajrTime);
    ui->label_2->setText("Dhuhr: " + dhuhrTime);
    ui->label_3->setText("Asr: " + asrTime);
    ui->label_4->setText("Maghrib: " + maghribTime);
    ui->label_5->setText("Isha: " + ishaTime);
}

void Prayer::updatePrayerTimesFromLabels()
{
    QString fajr = ui->label->text();
    QString dhuhr = ui->label_2->text();
    QString asr = ui->label_3->text();
    QString maghrib = ui->label_4->text();
    QString isha = ui->label_5->text();

    // Convert labels to 24-hour format times and update m_prayerTimes
    m_prayerTimes.clear();
    m_prayerTimes.insert(QTime::fromString(fajr.mid(fajr.indexOf(":") + 2), "hh:mm"), "Fajr");
    m_prayerTimes.insert(QTime::fromString(dhuhr.mid(dhuhr.indexOf(":") + 2), "hh:mm"), "Dhuhr");
    m_prayerTimes.insert(QTime::fromString(asr.mid(asr.indexOf(":") + 2), "hh:mm"), "Asr");
    m_prayerTimes.insert(QTime::fromString(maghrib.mid(maghrib.indexOf(":") + 2), "hh:mm"), "Maghrib");
    m_prayerTimes.insert(QTime::fromString(isha.mid(isha.indexOf(":") + 2), "hh:mm"), "Isha");
}

void Prayer::scheduleNextPrayer()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    currentDateTime = currentDateTime.addSecs(-currentDateTime.time().second());

    QDateTime nextPrayerDateTime;
    bool found = false;

    if (m_dataFromApi) {
        // Use m_prayerTimes from API if available
        for (auto it = m_prayerTimes.constBegin(); it != m_prayerTimes.constEnd(); ++it) {
            QDateTime prayerDateTime(currentDateTime.date(), it.key());
            if (prayerDateTime > currentDateTime) {
                nextPrayerDateTime = prayerDateTime;
                found = true;
                break;
            }
        }

        if (!found) {
            // If no future prayer time found, schedule for the first prayer time of the next day
            QDate tomorrow = currentDateTime.date().addDays(1);
            nextPrayerDateTime.setDate(tomorrow);
            nextPrayerDateTime.setTime(m_prayerTimes.firstKey());
        }

    } else {
        // Use stored prayer times if not from API
        nextPrayerDateTime = findNextPrayerTimeFromStoredData(currentDateTime);
    }

    // Ensure that the next prayer is indeed after the current time
    if (nextPrayerDateTime <= currentDateTime) {
        QDate tomorrow = currentDateTime.date().addDays(1);
        nextPrayerDateTime.setDate(tomorrow);
        nextPrayerDateTime.setTime(m_prayerTimes.firstKey());
    }

    int msecToNextPrayer = currentDateTime.msecsTo(nextPrayerDateTime);

    qDebug() << "Current Date and Time:" << currentDateTime.toString("yyyy-MM-dd hh:mm:ss");

    // Schedule single-shot timer for the next prayer time
    QTimer::singleShot(msecToNextPrayer, [=]() {

        // Check if notifications are enabled
        if (ui->checkBox_Notify->isChecked()) {
            qDebug() << "It's time for" << m_prayerTimes[nextPrayerDateTime.time()] << "Adhan!";
            popNotify *popup = new popNotify(this);
            popup->exec(); // Show the widget as a modal dialog
        }

        // Schedule the next prayer
        scheduleNextPrayer();
    });

    qDebug() << "Next prayer scheduled at:" << nextPrayerDateTime.toString("yyyy-MM-dd hh:mm:ss");
}


QDateTime Prayer::findNextPrayerTimeFromStoredData(const QDateTime &currentDateTime)
{
    QDateTime nextPrayerDateTime;

    for (auto it = m_prayerTimes.constBegin(); it != m_prayerTimes.constEnd(); ++it) {
        QDateTime prayerDateTime(currentDateTime.date(), it.key());
        if (prayerDateTime > currentDateTime) {
            nextPrayerDateTime = prayerDateTime;
            break;
        }
    }

    if (nextPrayerDateTime.isNull()) {
        QDate tomorrow = currentDateTime.date().addDays(1);
        nextPrayerDateTime.setDate(tomorrow);
        nextPrayerDateTime.setTime(m_prayerTimes.firstKey());
    }

    return nextPrayerDateTime;
}

void Prayer::loadPrayerTimes()
{
    QSettings settings("PrayerTimes", "MyApp");

    // Load stored prayer times
    QString fajr = settings.value("FajrTime", "").toString();
    QString dhuhr = settings.value("DhuhrTime", "").toString();
    QString asr = settings.value("AsrTime", "").toString();
    QString maghrib = settings.value("MaghribTime", "").toString();
    QString isha = settings.value("IshaTime", "").toString();

    // Update m_prayerTimes with loaded times
    m_prayerTimes.clear();
    m_prayerTimes.insert(QTime::fromString(fajr, "h:mm"), "Fajr");
    m_prayerTimes.insert(QTime::fromString(dhuhr, "h:mm"), "Dhuhr");
    m_prayerTimes.insert(QTime::fromString(asr, "h:mm"), "Asr");
    m_prayerTimes.insert(QTime::fromString(maghrib, "h:mm"), "Maghrib");
    m_prayerTimes.insert(QTime::fromString(isha, "h:mm"), "Isha");

    // Update the UI with loaded times
    updateUIWithPrayerTimes(fajr, dhuhr, asr, maghrib, isha);
}

void Prayer::savePrayerTimes()
{
    QSettings settings("PrayerTimes", "MyApp");

    // Save current prayer times
    settings.setValue("FajrTime", ui->label->text().mid(ui->label->text().indexOf(":") + 2));
    settings.setValue("DhuhrTime", ui->label_2->text().mid(ui->label_2->text().indexOf(":") + 2));
    settings.setValue("AsrTime", ui->label_3->text().mid(ui->label_3->text().indexOf(":") + 2));
    settings.setValue("MaghribTime", ui->label_4->text().mid(ui->label_4->text().indexOf(":") + 2));
    settings.setValue("IshaTime", ui->label_5->text().mid(ui->label_5->text().indexOf(":") + 2));
}

void Prayer::displayLastPrayerTimes()
{
    loadPrayerTimes(); // Load and display last prayer times from storage
}

void Prayer::loadSettings()
{
    QSettings settings("PrayerApp", "MyApp");

    // Load the state of the checkbox
    bool notifyEnabled = settings.value("NotifyEnabled", true).toBool();
    ui->checkBox_Notify->setChecked(notifyEnabled);
}

void Prayer::saveSettings()
{
    QSettings settings("PrayerApp", "MyApp");

    // Save the state of the checkbox
    settings.setValue("NotifyEnabled", ui->checkBox_Notify->isChecked());
}

void Prayer::on_checkBox_Notify_stateChanged(int state)
{
    saveSettings(); // Save the state of the checkbox immediately

    // Check if notifications are enabled
    if (state == Qt::Checked) {
        // If checked, schedule next prayer with notification
        scheduleNextPrayer();
    } else {
        // If unchecked, do nothing (notifications are disabled)
    }
}
