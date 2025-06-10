#ifndef ROOM_H
#define ROOM_H

#include "mystr.h"
using namespace std;

class Device; // Forward declaration

class Room {
    Mystr roomId;
    Mystr roomName;
    Device** devices;
    int deviceCount;
    int deviceCapacity;
public:
    Room();
    Room(const Mystr& roomId, const Mystr& roomName);
    ~Room();

    Mystr getRoomId() const;
    Mystr getRoomName() const;

    void setRoomName(const Mystr& newName);

    void addDevice(Device* device);
    void removeDevice(const Mystr& deviceId);
    Device* getDevice(const Mystr& deviceId) const;
    int getDeviceCount() const;
    Device** getDevices() const;
};

#endif