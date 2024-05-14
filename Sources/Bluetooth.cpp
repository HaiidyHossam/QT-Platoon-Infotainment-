
#include "Headers/Bluetooth.h"
#include "ui_Bluetooth.h"
#include "Headers/mainwindow.h"

Bluetooth::Bluetooth(MainWindow *parent)
    : QDialog(parent)
    , ui(new Ui::Bluetooth),
   mainWindowPtr(parent)
{
    ui->setupUi(this);
    /* Bluetooth */
    timer_bluetooth = new QTimer(this);
    connect(timer_bluetooth, SIGNAL(timeout()), this, SLOT(update_connected_device()));
    btctlProcess = popen("bluetoothctl", "w");
    if (!btctlProcess) {
        std::cerr << "Failed to open bluetoothctl process!" << std::endl;
        exit(EXIT_FAILURE);
    }
}

Bluetooth::~Bluetooth()
{
    closeBluetooth();
    delete ui;
}


void Bluetooth::sendCommand(const char* command) {
    fprintf(btctlProcess, "%s\n", command);
    fflush(btctlProcess);
    std::cout << "Sent command: " << command << std::endl;
}

void Bluetooth::initializeBluetooth() {
    sendCommand("power on");
    sendCommand("agent on");
    sendCommand("default-agent");
    sendCommand("discovrable on");
}

std::string Bluetooth::getConnectedDeviceName() {
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

void Bluetooth::disableBluetooth() {
    sendCommand("power off");
}

void Bluetooth::closeBluetooth() {
    sendCommand("quit");
    pclose(btctlProcess);
}

void Bluetooth::on_Back_Home_clicked()
{
     mainWindowPtr->Back_Home();
}

void Bluetooth::update_connected_device() {
    ui->bluetooth_state->setText(QString::fromStdString(getConnectedDeviceName()));
}

void Bluetooth::on_toggle_bluetooth_clicked()
{
    if (ui->toggle_bluetooth->isChecked()) {
        initializeBluetooth();
        ui->bluetooth_state->setText("Bluetooth is enabled.\nConnect your device!");
        //timer->start(5000);

    }
    else {
        disableBluetooth();
        ui->bluetooth_state->setText("Bluetooth is disabled.");
        ui->bluetooth_state->setText(QString::fromStdString(getConnectedDeviceName()));

    }
}

