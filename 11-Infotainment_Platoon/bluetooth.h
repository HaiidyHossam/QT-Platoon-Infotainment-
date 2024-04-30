#ifndef BLUETOOTH_H
#define BLUETOOTH_H
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <QDialog>

namespace Ui {
class bluetooth;
}

class bluetooth : public QDialog
{
    Q_OBJECT

public:
    explicit bluetooth(QWidget *parent = nullptr);
    ~bluetooth();
    void sendCommand(const char* command);
    void initializeBluetooth();
    void disableBluetooth();
    std::string getConnectedDeviceName();
    void closeBluetooth();



private:
    Ui::bluetooth *ui;
    FILE* btctlProcess;
};

#endif // BLUETOOTH_H
