#include "User.h"

User::User() : Account() {}

User::User(const Mystr& id, const Mystr& username, const Mystr& password, const Mystr& name)
    : Account(id, username, password, name) {
}

Mystr User::getRole() const {
    return Mystr("user");
}