#include "Room.h"
#include "Device.h"

Room::Room() : roomId(""), roomName(""), devices(nullptr), deviceCount(0), deviceCapacity(0) {}

Room::Room(const Mystr& roomId, const Mystr& roomName)
    : roomId(roomId), roomName(roomName), devices(nullptr), deviceCount(0), deviceCapacity(0) {
}

Room::~Room() {
    if (devices) {
        for (int i = 0; i < deviceCount; ++i)
            delete devices[i];
        delete[] devices;
    }
}

Mystr Room::getRoomId() const { return roomId; }
Mystr Room::getRoomName() const { return roomName; }
void Room::setRoomName(const Mystr& newName) { roomName = newName; }

void Room::addDevice(Device* device) {
    if (deviceCount == deviceCapacity) {
        int newCapacity = deviceCapacity == 0 ? 2 : deviceCapacity * 2;
        Device** newDevices = new Device * [newCapacity];
        for (int i = 0; i < deviceCount; ++i)
            newDevices[i] = devices[i];
        delete[] devices;
        devices = newDevices;
        deviceCapacity = newCapacity;
    }
    devices[deviceCount++] = device;
}

void Room::removeDevice(const Mystr& deviceId) {
    for (int i = 0; i < deviceCount; ++i) {
        if (devices[i]->getDeviceId().is_equal(deviceId)) {
            delete devices[i];
            for (int j = i; j < deviceCount - 1; ++j)
                devices[j] = devices[j + 1];
            --deviceCount;
            return;
        }
    }
}

Device* Room::getDevice(const Mystr& deviceId) const {
    for (int i = 0; i < deviceCount; ++i) {
        if (devices[i]->getDeviceId().is_equal(deviceId))
            return devices[i];
    }
    return nullptr;
}

int Room::getDeviceCount() const { return deviceCount; }
Device** Room::getDevices() const { return devices; }