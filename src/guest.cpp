#include "Guest.h"

Guest::Guest() : Account() {}

Guest::Guest(const Mystr& id, const Mystr& username, const Mystr& password, const Mystr& name)
    : Account(id, username, password, name) {
}

Mystr Guest::getRole() const {
    return Mystr("guest");
}