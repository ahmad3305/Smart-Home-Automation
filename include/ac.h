#ifndef AC_H
#define AC_H

#include "Device.h"
using namespace std;

class AC : public Device {
    int temperature; // e.g., 16-30
public:
    AC();
    AC(const Mystr& deviceId, const Mystr& deviceName, int temperature = 24);

    void adjustFeature(int value) override; // Adjust temperature
    int getTemperature() const;
    Mystr getDeviceType() const override;
};

#endif