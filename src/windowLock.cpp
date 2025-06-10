#include "WindowLock.h"

WindowLock::WindowLock() : Device(), isLocked(true) {}
WindowLock::WindowLock(const Mystr& deviceId, const Mystr& deviceName, bool isLocked)
    : Device(deviceId, deviceName), isLocked(isLocked) {
}

void WindowLock::adjustFeature(int value) {
    isLocked = (value != 0);
}
bool WindowLock::getLockState() const { return isLocked; }
Mystr WindowLock::getDeviceType() const { return Mystr("WindowLock"); }