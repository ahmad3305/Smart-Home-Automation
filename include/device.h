#ifndef DEVICE_H
#define DEVICE_H

#include "mystr.h"
using namespace std;

class Device {
protected:
    Mystr deviceId;
    Mystr deviceName;
    bool isOn;
public:
    Device();
    Device(const Mystr& deviceId, const Mystr& deviceName);
    virtual ~Device();

    virtual void turnOn();
    virtual void turnOff();
    bool getState() const;

    Mystr getDeviceId() const;
    Mystr getDeviceName() const;
    void setDeviceName(const Mystr& newName);

    virtual void adjustFeature(int value) = 0;
    virtual void adjustFeature(int value) = 0;

    virtual Mystr getDeviceType() const = 0;

};

#endif