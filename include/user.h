#ifndef USER_H
#define USER_H
#include "Account.h"
using namespace std;

class User : public Account {
public:
    User();
    User(const Mystr& id, const Mystr& username, const Mystr& password, const Mystr& name);
    Mystr getRole() const override;
};
#endif
