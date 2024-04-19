#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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


private slots:

    void getAndDisplayPrayerTimes(const QString &city, const QString &country);

    void checkCurrentTime();



    void on_pushButton_clicked();

private:

private:
    Ui::MainWindow *ui;
    //   QMap<QString, QTime> m_prayerTimes; // Define m_prayerTimes here
    QMap<QTime, QString> m_prayerTimes;


    QMediaPlayer *player;

};
#endif // MAINWINDOW_H
