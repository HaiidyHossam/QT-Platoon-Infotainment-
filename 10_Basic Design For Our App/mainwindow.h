#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
#include "popNotify.h"
#include <QObject>
#include <QMediaPlayer>
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
};
#endif // MAINWINDOW_H
