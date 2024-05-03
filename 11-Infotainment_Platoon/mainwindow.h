#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
#include "popNotify.h"
#include <QObject>
#include <QMediaPlayer>
#include "BBluetooth.h"
#include "Weather.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;
    void Back_Home();
    void scheduleNextPrayer();



private:
         // Ui::MainWindow *ui;
    //Adhan *prayerWidget;
    MainWindow *mainWindow;
    QMediaPlayer *player;
    popNotify *popup  ;

    QMap<QTime, QString> m_prayerTimes;

    void getAndDisplayPrayerTimes(const QString &city);
    //void scheduleNextPrayer();
    void displayLastPrayerTimes();
    void savePrayerTimes();
    void loadPrayerTimes();

private slots:
    void showTime();

    void on_Prayer_Button_clicked();

    void on_Camera_Button_clicked();


    void on_Weather_Button_clicked();

    void on_Settings_Button_clicked();

    void on_Bluetooth_Button_clicked();

    void on_Back_Home_from_prayer_clicked();


    void on_Info_Button_clicked();
};
#endif // MAINWINDOW_H
