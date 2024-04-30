#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
#include "popNotify.h"
#include <QObject>
#include <QMediaPlayer>
#include "bluetooth.h"
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


private:
         // Ui::MainWindow *ui;
    //Adhan *prayerWidget;
    MainWindow *mainWindow;
    QMediaPlayer *player;
    popNotify *popup  ;
    QDateTime dateTime;
   bluetooth bbluetooth;
    QTimer *timer_bluetooth;

    QMap<QTime, QString> m_prayerTimes;

    void getAndDisplayPrayerTimes(const QString &city);
    void scheduleNextPrayer();
    void displayLastPrayerTimes();
    void savePrayerTimes();
    void loadPrayerTimes();

private slots:
    void showTime();
    void AdhanPage();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    //hi
    void on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime);
    void on_pushButton_12_clicked();
    //for bluetooth
    void on_toggle_bluetooth_clicked();
    void update_connected_device();
    void on_pushButton_8_clicked();

    void on_pushButton_13_clicked();
};
#endif // MAINWINDOW_H
