#ifndef HEATER_H
#define HEATER_H

#include "Device.h"
using namespace std;

class Heater : public Device {
    int temperature; // e.g., 20-40
public:
    Heater();
    Heater(const Mystr& deviceId, const Mystr& deviceName, int temperature = 30);

    void adjustFeature(int value) override; // Adjust temperature
    int getTemperature() const;
    Mystr getDeviceType() const override;
};

#endif