#include "AC.h"

AC::AC() : Device(), temperature(24) {}
AC::AC(const Mystr& deviceId, const Mystr& deviceName, int temperature)
    : Device(deviceId, deviceName), temperature(temperature) {
}

void AC::adjustFeature(int value) {
    if (value < 16) value = 16;
    if (value > 30) value = 30;
    temperature = value;
}
int AC::getTemperature() const { return temperature; }
Mystr AC::getDeviceType() const { return Mystr("AC"); }