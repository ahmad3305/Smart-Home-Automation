#ifndef HOME_H
#define HOME_H

#include "mystr.h"
#include "User.h"

using namespace std;

class Room; // Forward declaration

class Home {
    Mystr homeId;
    Mystr homeName;
    User* owner;      // Pointer to owner User
    Room** rooms;     // Dynamic array of pointers to Rooms
    int roomCount;
    int roomCapacity;
public:
    Home();
    Home(const Mystr& homeId, const Mystr& homeName, User* owner);
    ~Home();

    Mystr getHomeId() const;
    Mystr getHomeName() const;
    User* getOwner() const;

    void setHomeName(const Mystr& newName);
    void setOwner(User* newOwner);

    void addRoom(Room* room);
    void removeRoom(const Mystr& roomId);
    Room* getRoom(const Mystr& roomId) const;
    int getRoomCount() const;
    Room** getRooms() const;
};

#endif