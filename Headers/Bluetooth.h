#ifndef BLUETOOTH_H
#define BLUETOOTH_H
#include <cstdio>
#include <iostream>
#include <QDialog>
#include <QTimer>

class MainWindow; // Forward declaration

namespace Ui {
class Bluetooth;
}

class Bluetooth : public QDialog
{
    Q_OBJECT

public:
    explicit Bluetooth(MainWindow *parent = nullptr);
    ~Bluetooth();
    void sendCommand(const char* command);
    void initializeBluetooth();
    void disableBluetooth();
    std::string getConnectedDeviceName();
    void closeBluetooth();

private slots:
    void on_Back_Home_clicked();
    void update_connected_device();
    void on_toggle_bluetooth_clicked();

private:
    QTimer *timer_bluetooth;
    Ui::Bluetooth *ui;
    FILE* btctlProcess;
    FILE* Bscript;
    MainWindow *mainWindowPtr;
    std::string execute(const char* cmd);
    bool isDeviceConnected(const std::string& macAddress);
};

#endif // BLUETOOTH_H








