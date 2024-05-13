#include "flash.h"
#include <string>
#include <cstdio>
//#include <iostream>

std::string GetStdoutFromCommand(std::string cmd) {
    std::string data;
    FILE* stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    cmd.append(" 2>&1");

    stream = popen(cmd.c_str(), "r");
    if (stream) {
        while (!feof(stream))
            if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
        pclose(stream);
    }
    return data;
}

Flash::Flash() {

}

int Flash::mountUSB() {

    const char *cmd;
    std::string mountCMD;

    std::string mkdir = "mkdir -p /media/" + usbName;
    system(mkdir.c_str());

    mountCMD = "mount /dev/" + usbName + " /media/" + usbName;

    cmd = mountCMD.c_str();
    return system(cmd);
}

int Flash::unmountUSB() {
    const char *cmd;
    std::string unmountCMD;

    unmountCMD = "umount /media/" + mountedDevice;

    cmd = unmountCMD.c_str();
    return system(cmd);
}

std::string Flash::extractUsb(std::string devices) {
    std::string dev,devType;
    std::string checkDevTypeCMD;
    int start, devNameLen;

    devNameLen = 4;
    start = 0;

    while (start<devices.length())
    {
        dev = devices.substr(start,devNameLen);

        checkDevTypeCMD = "udevadm info --query=all --name=" +dev + " | grep usb";
        devType = GetStdoutFromCommand(checkDevTypeCMD);
        if (devType.length()!=0)
        {
            return dev;
        }

        start = start + devNameLen;
    }
    return devType;
}

bool Flash::updateFlashStatus() {
    std::string devicesList = "ls /dev/ | grep sd[a-z][0-9]";

    std::string devices = GetStdoutFromCommand(devicesList);
    std::string modData;
    for (char c : devices) {
        if (c != '\n') {
            modData += c;
        }
    }
    usbName = extractUsb(devices);
    if (usbName == "") {
        //std::cerr << "Failed to extract USB device name!" << std::endl;
        if (isMounted == true) {
          unmountUSB();
          system ("rm -rf /media/*");
          isMounted = false;
        }
        return false;
    }

    if (isMounted == false) {
      int mount = mountUSB();
      if (mount != 0) {
          //std::cerr << "Failed to mount USB device!" << std::endl;
          return false;
      }
      isMounted = true;
      mountedDevice = usbName;
    }
    return true;
}
