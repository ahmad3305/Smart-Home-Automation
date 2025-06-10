#include "Fan.h"

Fan::Fan() : Device(), speed(0) {}
Fan::Fan(const Mystr& deviceId, const Mystr& deviceName, int speed)
    : Device(deviceId, deviceName), speed(speed) {
}

void Fan::adjustFeature(int value) {
    if (value < 0) value = 0;
    if (value > 5) value = 5;
    speed = value;
}
int Fan::getSpeed() const { return speed; }
Mystr Fan::getDeviceType() const { return Mystr("Fan"); }