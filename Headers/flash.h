#ifndef FLASH_H
#define FLASH_H

#include <string>

class Flash
{
public:
    std::string usbName;
    Flash();
    bool updateFlashStatus(void);
private:
    bool isMounted = false;
    int mountUSB ();
    int unmountUSB ();
    std::string extractUsb (std::string devices);
    std::string mountedDevice;
};

#endif // FLASH_H
