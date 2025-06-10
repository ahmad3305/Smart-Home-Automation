#include "Admin.h"

Admin::Admin() : Account() {}

Admin::Admin(const Mystr& id, const Mystr& username, const Mystr& password, const Mystr& name)
    : Account(id, username, password, name) {
}

Mystr Admin::getRole() const {
    return Mystr("admin");
}