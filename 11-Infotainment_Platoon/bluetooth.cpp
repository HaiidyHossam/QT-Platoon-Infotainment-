#include "bluetooth.h"
#include "ui_bluetooth.h"
#include "mainwindow.h"
bluetooth::bluetooth(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::bluetooth)
{
    ui->setupUi(this);
    btctlProcess = popen("bluetoothctl", "w");
    if (!btctlProcess) {
        std::cerr << "Failed to open bluetoothctl process!" << std::endl;
        exit(EXIT_FAILURE);
    }
}

bluetooth::~bluetooth()
{
    closeBluetooth();
    delete ui;
}


void bluetooth::sendCommand(const char* command) {
    fprintf(btctlProcess, "%s\n", command);
    fflush(btctlProcess);
    std::cout << "Sent command: " << command << std::endl;
}

void bluetooth::initializeBluetooth() {
    sendCommand("power on");
    sendCommand("agent on");
    sendCommand("default-agent");
    sendCommand("discovrable on");
}

std::string bluetooth::getConnectedDeviceName() {
    // Run hcitool to get connected devices
    FILE* hcitoolProcess = popen("hcitool con", "r");
    if (!hcitoolProcess) {
        std::cerr << "Failed to run hcitool!" << std::endl;
        return "";
    }

    // Read output to find connected device MAC addresses
    std::string connectedDeviceName;
    char buffer[128];
    if (fgets(buffer, sizeof(buffer), hcitoolProcess) != NULL) {
        std::string line(buffer);
        size_t pos = line.find("ACL");
        if (pos != std::string::npos) {
            // Extract device MAC address from the line
            size_t start = line.find_first_of(" ", pos + 4);
            if (start != std::string::npos) {
                size_t end = line.find_last_of(" ");
                if (end != std::string::npos) {
                    std::string macAddress = line.substr(start + 1, end - start);
                    // Get the name of the connected device using the MAC address
                    std::string command = "hcitool name " + macAddress;
                    FILE* hcitoolNameProcess = popen(command.c_str(), "r");
                    if (!hcitoolNameProcess) {
                        std::cerr << "Failed to run hcitool name!" << std::endl;
                        return "";
                    }

                    // Read output to get device name
                    if (fgets(buffer, sizeof(buffer), hcitoolNameProcess) != NULL) {
                        connectedDeviceName = buffer;
                        // Remove newline character if present
                        connectedDeviceName.erase(connectedDeviceName.find_last_not_of("\n") + 1);
                    }
                    pclose(hcitoolNameProcess);
                }
            }
        }
    }

    pclose(hcitoolProcess);
    return connectedDeviceName;
}

void bluetooth::disableBluetooth() {
    sendCommand("power off");
}

void bluetooth::closeBluetooth() {
    sendCommand("quit");
    pclose(btctlProcess);
}



