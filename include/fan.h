#ifndef FAN_H
#define FAN_H

#include "Device.h"
using namespace std;

class Fan : public Device {
    int speed; // 0-5
public:
    Fan();
    Fan(const Mystr& deviceId, const Mystr& deviceName, int speed = 0);

    void adjustFeature(int value) override; // Adjust speed
    int getSpeed() const;
    Mystr getDeviceType() const override;
};

#endif