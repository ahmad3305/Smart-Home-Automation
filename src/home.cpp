#include "Home.h"
#include "Room.h"

Home::Home() : homeId(""), homeName(""), owner(nullptr), rooms(nullptr), roomCount(0), roomCapacity(0) {}

Home::Home(const Mystr& homeId, const Mystr& homeName, User* owner)
    : homeId(homeId), homeName(homeName), owner(owner), rooms(nullptr), roomCount(0), roomCapacity(0) {
}

Home::~Home() {
    if (rooms) {
        for (int i = 0; i < roomCount; ++i)
            delete rooms[i];
        delete[] rooms;
    }
}

Mystr Home::getHomeId() const { return homeId; }
Mystr Home::getHomeName() const { return homeName; }
User* Home::getOwner() const { return owner; }

void Home::setHomeName(const Mystr& newName) { homeName = newName; }
void Home::setOwner(User* newOwner) { owner = newOwner; }

void Home::addRoom(Room* room) {
    if (roomCount == roomCapacity) {
        int newCapacity = roomCapacity == 0 ? 2 : roomCapacity * 2;
        Room** newRooms = new Room * [newCapacity];
        for (int i = 0; i < roomCount; ++i)
            newRooms[i] = rooms[i];
        delete[] rooms;
        rooms = newRooms;
        roomCapacity = newCapacity;
    }
    rooms[roomCount++] = room;
}

void Home::removeRoom(const Mystr& roomId) {
    for (int i = 0; i < roomCount; ++i) {
        if (rooms[i]->getRoomId().is_equal(roomId)) {
            delete rooms[i];
            for (int j = i; j < roomCount - 1; ++j)
                rooms[j] = rooms[j + 1];
            --roomCount;
            return;
        }
    }
}

Room* Home::getRoom(const Mystr& roomId) const {
    for (int i = 0; i < roomCount; ++i) {
        if (rooms[i]->getRoomId().is_equal(roomId))
            return rooms[i];
    }
    return nullptr;
}

int Home::getRoomCount() const { return roomCount; }
Room** Home::getRooms() const { return rooms; }