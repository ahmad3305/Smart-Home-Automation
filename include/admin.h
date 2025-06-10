#ifndef ADMIN_H
#define
#include "Account.h"
using namespace std;

class Admin : public Account {
public:
    Admin();
    Admin(const Mystr& id, const Mystr& username, const Mystr& password, const Mystr& name);
    Mystr getRole() const override;
};

#endif
