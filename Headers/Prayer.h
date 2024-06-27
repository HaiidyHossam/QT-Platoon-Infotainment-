#ifndef PRAYER_H
#define PRAYER_H
#include "popNotify.h"
#include <QDialog>
class MainWindow; // Forward declaration
namespace Ui {
class Prayer;
}

class Prayer : public QDialog
{
    Q_OBJECT

public:
    explicit Prayer(MainWindow *parent = nullptr);
    ~Prayer();
    void scheduleNextPrayer();
    void on_checkBox_Notify_stateChanged(int arg1);
    void loadPrayerTimes();
    QDateTime findNextPrayerTimeFromStoredData(const QDateTime &currentDateTime);
    void updatePrayerTimesFromLabels();
    void updateUIWithPrayerTimes(const QString &fajrTime, const QString &dhuhrTime,
                                         const QString &asrTime, const QString &maghribTime,
                                        const QString &ishaTime);
 
    QString formatTime(const QString &timeStr);

    void getAndDisplayPrayerTimes();
    void displayLastPrayerTimes();
    void savePrayerTimes();
private slots:
    void on_Back_clicked();
    void loadSettings();
    void saveSettings();




private:
    Ui::Prayer *ui;
    MainWindow *mainWindowPtr;
    popNotify *popup  ;
     bool m_dataFromApi;
    QMap<QTime, QString> m_prayerTimes;


};

#endif // PRAYER_H

