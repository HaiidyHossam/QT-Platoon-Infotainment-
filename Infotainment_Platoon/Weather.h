#ifndef WEATHER_H
#define WEATHER_H
#include <QNetworkAccessManager>

#include <QDialog>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class Weather; }
QT_END_NAMESPACE

class MainWindow;

class Weather : public QDialog
{
    Q_OBJECT

public:
    explicit Weather(MainWindow *parent = nullptr);
    ~Weather();

private slots:
    void requestWeatherData();
    void displayWeatherData(const QMap<QString, QString> &weatherData);
    void saveWeatherData();
    void loadWeatherData();


    void on_Back_Home_clicked();

private:
    Ui::Weather *ui;
    QNetworkAccessManager *manager;
    QMap<QString, QString> lastWeatherData;
    MainWindow *mainWindowPtr;
};

#endif // WEATHER_H




