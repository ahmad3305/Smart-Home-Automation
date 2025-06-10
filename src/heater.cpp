#include "Heater.h"

Heater::Heater() : Device(), temperature(30) {}
Heater::Heater(const Mystr& deviceId, const Mystr& deviceName, int temperature)
    : Device(deviceId, deviceName), temperature(temperature) {
}

void Heater::adjustFeature(int value) {
    if (value < 20) value = 20;
    if (value > 40) value = 40;
    temperature = value;
}
int Heater::getTemperature() const { return temperature; }
Mystr Heater::getDeviceType() const { return Mystr("Heater"); }