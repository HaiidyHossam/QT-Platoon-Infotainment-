// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    // Create a QNetworkAccessManager instance
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);


    QString latitude = "30.0444";   // Cairo latitude
    QString longitude = "31.2357";  // Cairo longitude

    // Construct the URL for the weather API request with the updated latitude and longitude
    QString apiUrl = "https://api.open-meteo.com/v1/forecast?latitude=" + latitude + "&longitude=" + longitude + "&current=temperature_2m,wind_speed_10m&hourly=temperature_2m,relative_humidity_2m,wind_speed_10m";


    // Send a GET request to the weather API
    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(apiUrl)));

    // Connect the finished() signal to a lambda function to handle the response
    connect(reply, &QNetworkReply::finished, [=]() {
        // Check for errors
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "Error:" << reply->errorString();
            return;
        }

        // Read the response data
        QByteArray responseData = reply->readAll();

        // Parse the JSON response
        QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObject =jsonResponse.object();

        // Extract and display current weather data
        if (jsonObject.contains("current")) {
            QJsonObject currentObject = jsonObject["current"].toObject();
            QString currentTemperature = QString::number(currentObject["temperature_2m"].toDouble()) + "°C";
            QString currentWindSpeed = QString::number(currentObject["wind_speed_10m"].toDouble()) + "m/s";
            ui->currentTemperatureLabel->setText("Current Temperature: " + currentTemperature);
            ui->currentWindSpeedLabel->setText("Current Wind Speed: " + currentWindSpeed);

        }

        // Cleanup
        reply->deleteLater();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
