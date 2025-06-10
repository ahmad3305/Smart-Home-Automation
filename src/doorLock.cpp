#include "DoorLock.h"

DoorLock::DoorLock() : Device(), isLocked(true) {}
DoorLock::DoorLock(const Mystr& deviceId, const Mystr& deviceName, bool isLocked)
    : Device(deviceId, deviceName), isLocked(isLocked) {
}

void DoorLock::adjustFeature(int value) {
    isLocked = (value != 0);
}
bool DoorLock::getLockState() const { return isLocked; }
Mystr DoorLock::getDeviceType() const { return Mystr("DoorLock"); }