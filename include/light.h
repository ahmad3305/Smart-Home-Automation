#ifndef LIGHT_H
#define LIGHT_H

#include "Device.h"
using namespace std;

class Light : public Device {
    int intensity; // 0-100
public:
    Light();
    Light(const Mystr& deviceId, const Mystr& deviceName, int intensity = 100);

    void adjustFeature(int value) override; // Adjust intensity
    int getIntensity() const;
    Mystr getDeviceType() const override;
};

#endif