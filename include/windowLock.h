#ifndef WINDOWLOCK_H
#define WINDOWLOCK_H

#include "Device.h"
using namespace std;

class WindowLock : public Device {
    bool isLocked;
public:
    WindowLock();
    WindowLock(const Mystr& deviceId, const Mystr& deviceName, bool isLocked = true);

    void adjustFeature(int value) override; // 0 = unlock, 1 = lock
    bool getLockState() const;
    Mystr getDeviceType() const override;
};

#endif