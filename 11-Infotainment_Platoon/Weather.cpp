// Camera.cpp
#include "Weather.h"
#include "ui_Weather.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSettings>
#include "mainwindow.h"

Weather::Weather(MainWindow *parent)
    : QDialog(parent)
    , ui(new Ui::Weather),
    mainWindowPtr(parent)
{
    ui->setupUi(this);
    // Create a QNetworkAccessManager instance
    manager = new QNetworkAccessManager(this);

    // Load weather data from local storage
    loadWeatherData();

    // Request weather data
    requestWeatherData();
}

Weather::~Weather()
{
    delete ui;
}



void Weather::requestWeatherData()
{
    // Construct the URL for the weather API request
    QString latitude = "30.0444";   // Cairo latitude
    QString longitude = "31.2357";  // Cairo longitude
    QString apiUrl = "https://api.open-meteo.com/v1/forecast?latitude=" + latitude + "&longitude=" + longitude + "&current=temperature_2m,wind_speed_10m&hourly=temperature_2m,relative_humidity_2m,wind_speed_10m";

    // Send a GET request to the weather API
    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(apiUrl)));

    // Connect the finished() signal to a lambda function to handle the response
    connect(reply, &QNetworkReply::finished, [=]() {
        // Check for errors
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "Error:" << reply->errorString();
            // Display the last received weather data
            displayWeatherData(lastWeatherData);
            reply->deleteLater();
            return;
        }
        // Read the response data
        QByteArray responseData = reply->readAll();

        // Parse the JSON response
        QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObject = jsonResponse.object();

        // Extract and display current weather data
        if (jsonObject.contains("current")) {
            QJsonObject currentObject = jsonObject["current"].toObject();
            QString currentTemperature = QString::number(currentObject["temperature_2m"].toDouble()) + "°C";
            QString currentWindSpeed = QString::number(currentObject["wind_speed_10m"].toDouble()) + "m/s";

            // Update the last received weather data
            lastWeatherData["currentTemperature"] = currentTemperature;
            lastWeatherData["currentWindSpeed"] = currentWindSpeed;

            // Save the latest weather data to local storage
            saveWeatherData();

            // Display current weather data
            displayWeatherData(lastWeatherData);
        }

        // Cleanup
        reply->deleteLater();
    });
}

void Weather::displayWeatherData(const QMap<QString, QString> &weatherData)
{
    // Display current weather data
    ui->currentTemperatureLabel->setText("Current Temperature: " + weatherData["currentTemperature"]);
    ui->currentWindSpeedLabel->setText("Current Wind Speed: " + weatherData["currentWindSpeed"]);
}

void Weather::saveWeatherData()
{

    QSettings settings("MyCompany", "MyApp");
    settings.beginGroup("WeatherData");
    settings.setValue("currentTemperature", lastWeatherData["currentTemperature"]);
    settings.setValue("currentWindSpeed", lastWeatherData["currentWindSpeed"]);
    settings.endGroup();
}

void Weather::loadWeatherData()
{

    QSettings settings("MyCompany", "MyApp");
    settings.beginGroup("WeatherData");
    lastWeatherData["currentTemperature"] = settings.value("currentTemperature", "- °C").toString();
    lastWeatherData["currentWindSpeed"] = settings.value("currentWindSpeed", "- m/s").toString();
    settings.endGroup();
}




void Weather::on_Back_Home_clicked()
{
      mainWindowPtr->Back_Home();
}

