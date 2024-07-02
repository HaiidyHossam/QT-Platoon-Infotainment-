
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
    m_timer = new QTimer(this);
    m_popupShown=false;
     m_isFetchingPrayerTimes=false;

    loadPrayerTimes(); // Load prayer times from local storage
    m_dataFromApi = false; // Initial assumption is data is not from API
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
    if (m_isFetchingPrayerTimes) {
        return; // Exit if a request is already in progress
    }

    m_isFetchingPrayerTimes = true; // Set the flag to indicate fetching

    QString dateString = QDate::currentDate().toString("dd-MM-yyyy");
    QString apiUrl = "https://api.aladhan.com/v1/timingsByCity/" + dateString + "?city=Cairo&country=Egypt&method=8";

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url(apiUrl);
    QNetworkRequest request(url);

    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, [=]() {
        m_isFetchingPrayerTimes = false; // Reset the flag

        if (reply->error() == QNetworkReply::NoError) {
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

                qDebug() << "Prayer Times (from Aladhan API):";
                qDebug() << "Fajr:" << fajrTime;
                qDebug() << "Dhuhr:" << dhuhrTime;
                qDebug() << "Asr:" << asrTime;
                qDebug() << "Maghrib:" << maghribTime;
                qDebug() << "Isha:" << ishaTime;

                updateUIWithPrayerTimes(fajrTime, dhuhrTime, asrTime, maghribTime, ishaTime);

                m_prayerTimes.clear();
                m_prayerTimes.insert(QTime::fromString(fajrTime, "hh:mm"), "Fajr");
                m_prayerTimes.insert(QTime::fromString(dhuhrTime, "hh:mm"), "Dhuhr");
                m_prayerTimes.insert(QTime::fromString(asrTime, "hh:mm"), "Asr");
                m_prayerTimes.insert(QTime::fromString(maghribTime, "hh:mm"), "Maghrib");
                m_prayerTimes.insert(QTime::fromString(ishaTime, "hh:mm"), "Isha");

                savePrayerTimes();

                m_dataFromApi = true;
                if (!m_timer->isActive() ) {
                    scheduleNextPrayer();
                }
            } else {
                qDebug() << "Invalid response code:" << responseCode;
            }
        } else {
            qDebug() << "Network Error:" << reply->errorString();

            displayLastPrayerTimes();
            m_dataFromApi = false;
            if (!m_timer->isActive()) {
                scheduleNextPrayer();
            }
        }

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
    if (m_timer->isActive()) {
        m_timer->stop();
    }

    QDateTime currentDateTime = QDateTime::currentDateTime();
    currentDateTime = currentDateTime.addSecs(-currentDateTime.time().second());

    QDateTime nextPrayerDateTime;
    bool found = false;

    if (m_dataFromApi) {
        for (auto it = m_prayerTimes.constBegin(); it != m_prayerTimes.constEnd(); ++it) {
            QDateTime prayerDateTime(currentDateTime.date(), it.key());
            if (prayerDateTime > currentDateTime) {
                nextPrayerDateTime = prayerDateTime;
                found = true;
                break;
            }
        }

        if (!found) {
            QDate tomorrow = currentDateTime.date().addDays(1);
            nextPrayerDateTime.setDate(tomorrow);
            nextPrayerDateTime.setTime(m_prayerTimes.firstKey());
        }
    } else {
        nextPrayerDateTime = findNextPrayerTimeFromStoredData(currentDateTime);
    }

    if (nextPrayerDateTime <= currentDateTime) {
        QDate tomorrow = currentDateTime.date().addDays(1);
        nextPrayerDateTime.setDate(tomorrow);
        nextPrayerDateTime.setTime(m_prayerTimes.firstKey());
    }

    int msecToNextPrayer = currentDateTime.msecsTo(nextPrayerDateTime);

    qDebug() << "Current Date and Time:" << currentDateTime.toString("yyyy-MM-dd hh:mm:ss");



   m_timer->singleShot(msecToNextPrayer, [=]() {
        qDebug() << "It's time for" << m_prayerTimes[nextPrayerDateTime.time()] << "Adhan!";
        if (!m_popupShown) {
            popNotify *popup = new popNotify(this);
            popup->exec();
            m_popupShown = true;
        }
        if (!m_timer->isActive()) {
            scheduleNextPrayer();
        }
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



