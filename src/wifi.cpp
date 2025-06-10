#include "Wifi.h"

Wifi::Wifi() : Device(), bandwidth(50) {}
Wifi::Wifi(const Mystr& deviceId, const Mystr& deviceName, int bandwidth)
    : Device(deviceId, deviceName), bandwidth(bandwidth) {
}

void Wifi::adjustFeature(int value) {
    if (value < 0) value = 0;
    if (value > 100) value = 100;
    bandwidth = value;
}
int Wifi::getBandwidth() const { return bandwidth; }
Mystr Wifi::getDeviceType() const { return Mystr("Wifi"); }