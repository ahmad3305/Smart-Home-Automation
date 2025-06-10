#include "Account.h"
#include "mystr.h"
Account::Account() {}

Account::Account(const Mystr& id, const Mystr& username, const Mystr& password, const Mystr& name)
    : id(id), username(username), password(password), name(name) {
}

Account::~Account() {}

Mystr Account::getId() const {
    return id;
}

Mystr Account::getUsername() const {
    return username;
}

Mystr Account::getName() const {
    return name;
}

void Account::setPassword(const Mystr& newPassword) {
    password = newPassword;
}

bool Account::checkPassword(const Mystr& pass) const {
    return password.is_equal(pass);
}

Mystr Account::getRole() const {
    return Mystr("account");
}