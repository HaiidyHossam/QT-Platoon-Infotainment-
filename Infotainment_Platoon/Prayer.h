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
  void loadPrayerTimes();

  void getAndDisplayPrayerTimes(const QString &city);
  void displayLastPrayerTimes();
  void savePrayerTimes();
private slots:
    void on_Back_clicked();

private:
    Ui::Prayer *ui;
    MainWindow *mainWindowPtr;
    popNotify *popup  ;

    QMap<QTime, QString> m_prayerTimes;


};

#endif // PRAYER_H
