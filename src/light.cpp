#include "Light.h"

Light::Light() : Device(), intensity(100) {}
Light::Light(const Mystr& deviceId, const Mystr& deviceName, int intensity)
    : Device(deviceId, deviceName), intensity(intensity) {
}

void Light::adjustFeature(int value) {
    if (value < 0) value = 0;
    if (value > 100) value = 100;
    intensity = value;
}
int Light::getIntensity() const { return intensity; }
Mystr Light::getDeviceType() const { return Mystr("Light"); }