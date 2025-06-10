#include "Device.h"

Device::Device() : deviceId(""), deviceName(""), isOn(false) {}
Device::Device(const Mystr& deviceId, const Mystr& deviceName) : deviceId(deviceId), deviceName(deviceName), isOn(false) {}
Device::~Device() {}

void Device::turnOn() { isOn = true; }
void Device::turnOff() { isOn = false; }
bool Device::getState() const { return isOn; }

Mystr Device::getDeviceId() const { return deviceId; }
Mystr Device::getDeviceName() const { return deviceName; }
void Device::setDeviceName(const Mystr& newName) { deviceName = newName; }