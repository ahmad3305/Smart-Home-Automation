#ifndef WIFI_H
#define WIFI_H

#include "Device.h"
using namespace std;

class Wifi : public Device {
    int bandwidth; // e.g., 0-100 Mbps
public:
    Wifi();
    Wifi(const Mystr& deviceId, const Mystr& deviceName, int bandwidth = 50);

    void adjustFeature(int value) override; // Adjust bandwidth
    int getBandwidth() const;
    Mystr getDeviceType() const override;
};

#endif