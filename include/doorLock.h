#ifndef DOORLOCK_H
#define DOORLOCK_H

#include "Device.h"
using namespace std;

class DoorLock : public Device {
    bool isLocked;
public:
    DoorLock();
    DoorLock(const Mystr& deviceId, const Mystr& deviceName, bool isLocked = true);

    void adjustFeature(int value) override; // 0 = unlock, 1 = lock
    bool getLockState() const;
    Mystr getDeviceType() const override;
};

#endif