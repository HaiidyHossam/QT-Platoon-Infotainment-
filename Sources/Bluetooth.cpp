
#include "Headers/Bluetooth.h"
#include "ui_Bluetooth.h"
#include "Headers/mainwindow.h"
#include <sstream>

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
    ui->bluetooth_state->setText("Bluetooth is disabled.");
}

Bluetooth::~Bluetooth()
{
    closeBluetooth();
    pclose(Bscript);
    delete ui;
}

std::string Bluetooth::execute(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

bool Bluetooth::isDeviceConnected(const std::string& macAddress) {
    std::string command = "bluetoothctl info " + macAddress;
    std::string result = execute(command.c_str());
    return result.find("Connected: yes") != std::string::npos;
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
    sendCommand("discoverable on");
}

std::string Bluetooth::getConnectedDeviceName() {
    std::string command = "bluetoothctl devices";
    std::string result = execute(command.c_str());

    // Parse the output to extract device MAC addresses and names
    std::istringstream stream(result);
    std::string line;
    while (std::getline(stream, line)) {
        std::size_t pos = line.find(' ');
        if (pos != std::string::npos) {
            std::string macAddress = line.substr(pos + 1, 17); // Extract MAC address
            std::string deviceName = line.substr(pos + 19);    // Extract device name

            // Check if the device is currently connected
            if (isDeviceConnected(macAddress)) {
                //std::cout << "Device MAC: " << macAddress << ", Name: " << deviceName << std::endl;
                //ui->bluetooth_state->setText(QString::fromStdString(deviceName));
                return deviceName;
            }
        }
    }
    return "";
}

void Bluetooth::disableBluetooth() {
    sendCommand("power off");    
}

void Bluetooth::closeBluetooth() {
    sendCommand("quit");
    pclose(btctlProcess);
}

void Bluetooth::on_Back_Home_clicked() {
     mainWindowPtr->Back_Home();
}

void Bluetooth::update_connected_device() {
    if (getConnectedDeviceName().empty())
        ui->bluetooth_state->setText("Bluetooth is enabled.\nConnect your device!");
    else
        ui->bluetooth_state->setText(QString::fromStdString(getConnectedDeviceName()));
}

void Bluetooth::on_toggle_bluetooth_clicked() {
    if (ui->toggle_bluetooth->isChecked()) {
        initializeBluetooth();
        ui->bluetooth_state->setText("Bluetooth is enabled.\nConnect your device!");
        popen("bluetooth-script.py","r");
        timer_bluetooth->start(1000);
    }
    else {
        disableBluetooth();
        system("killall bluetooth-script.py");
        timer_bluetooth->stop();
        ui->bluetooth_state->setText("Bluetooth is disabled.");
    }
}
