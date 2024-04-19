#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startDeviceDiscovery();
    void stopDeviceDiscovery();
    void selectMusicFile();
    void playMusic();
    void pauseMusic();
    void stopMusic();
    void deviceDiscovered(const QBluetoothDeviceInfo &info);
    void deviceDiscoveryFinished();

    //void on_btnStartScan_clicked();

   // void on_btnStopScan_clicked();

   // void on_btnSelectFile_clicked();

    //void on_btnPlay_clicked();

   // void on_btnPause_clicked();

    //void on_btnStop_clicked();

private:
    Ui::MainWindow *ui;
    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
    QMediaPlayer *player;
};

#endif // MAINWINDOW_H
