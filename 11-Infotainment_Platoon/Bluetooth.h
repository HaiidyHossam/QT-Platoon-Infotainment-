#ifndef BLUETOOTH_H
#define BLUETOOTH_H
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <QDialog>
#include <QTimer>

class MainWindow; // Forward declaration

namespace Ui {
class BBluetooth;
}

class BBluetooth : public QDialog
{
    Q_OBJECT

public:
    explicit BBluetooth(MainWindow *parent = nullptr);
    ~BBluetooth();
    void sendCommand(const char* command);
    void initializeBluetooth();
    void disableBluetooth();
    std::string getConnectedDeviceName();
    void closeBluetooth();
    void update_connected_device();


private slots:
    void on_Back_Home_clicked();

    void on_toggle_bluetooth_clicked();

private:
    QTimer *timer_bluetooth;
    Ui::BBluetooth *ui;
    FILE* btctlProcess;
    MainWindow *mainWindowPtr;
};

#endif // BLUETOOTH_H








