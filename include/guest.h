#ifndef GUEST_H
#define GUEST_H
#include "Account.h"
using namespace std;

class Guest : public Account {
public:
    Guest();
    Guest(const Mystr& id, const Mystr& username, const Mystr& password, const Mystr& name);
    Mystr getRole() const override;
};

#endif